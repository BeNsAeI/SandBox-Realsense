/*******************************************************************************

INTEL CORPORATION PROPRIETARY INFORMATION
This software is supplied under the terms of a license agreement or nondisclosure
agreement with Intel Corporation and may not be copied or disclosed except in
accordance with the terms of that agreement
Copyright(c) 2014-2015 Intel Corporation. All Rights Reserved.

*******************************************************************************/
/** @file PXCEnhancedPhotography.h
    Defines the PXCEnhancedPhotography interface, which programs may use to process snapshots of captured frames
	to measure distance and refocus the image
 */
#pragma once
#include "pxcphoto.h"

/**
This class defines a standard interface for enhanced photography algorithms.
*/
class PXCEnhancedPhotography:public PXCBase {
public:

	PXC_CUID_OVERWRITE(PXC_UID('E','P','I','N'));

	/* 
	MeasureDistance: measure the distance between 2 points in mm
	photo: is the photo instance
	startPoint, endPoint: are the start pont and end point of the distance that need to be measured.
	Note: depth data must be availible and accurate at the start and end point selected. 
	*/
	virtual pxcF32 PXCAPI MeasureDistance(const PXCPhoto *photo, PXCPointI32 startPoint, PXCPointI32 endPoint) = 0;
	
	/* 
	DepthRefocus: refocus the image at input focusPoint by using depth data refocus
	photo: is the color and depth photo instance
	focusPoint: is the selected point foir refocussing.
	aperture: Range of the blur area [1-100]  
	Note: The application must release the returned refocussed image
	*/
	virtual PXCPhoto* PXCAPI DepthRefocus(const PXCPhoto *photo, PXCPointI32 focusPoint, pxcF32 aperture) = 0;

	/*
	DepthRefocus: refocus the image at input focusPoint by using depth data refocus
	photo: is the color and depth photo
	focusPoint: is the selected point foir refocussing.
	Note: The application must release the returned refocussed image
	*/
	__inline PXCPhoto* DepthRefocus(const PXCPhoto *photo, PXCPointI32 focusPoint) { 
		return DepthRefocus(photo, focusPoint, 50.0);
	}

	/* 
	Input param for Depth fill Quality: 
	High: better quality, slow execution for post processing (image)
	Low : lower quality, fast execution for realtime processing (live video sequence)
	*/
	enum DepthFillQuality {
		HIGH = 0, 
		LOW, 
	};

	/* 
	EnhanceDepth: enhance the depth image quality by filling holes and denoising
	outputs the enhanced depth image
	photo: input color, depth photo, and calibration data
	depthQuality: Depth fill Quality: HIGH or LOW for post or realtime processing respectively
	Note: The application must release the returned enhanced depth image
	*/
	virtual PXCPhoto* PXCAPI EnhanceDepth(const PXCPhoto *photo, DepthFillQuality depthQuality)= 0;
	
	/* 
	ComputeMaskFromThreshold: calculates a mask from the threshold computed 
	photo: input color and depth photo, only used the depth map.
	depthThreshold: depth threshold.  
	Returns a mask in the form of PXCImage for blending with the current photo frame.
	*/
	virtual PXCImage* PXCAPI ComputeMaskFromThreshold(const PXCPhoto *photo, pxcF32 depthThreshold) = 0;
	    
	/* 
	ComputeMaskFromCoordinate: convenience function that creates a mask directly from a depth coordinate.
	photo: input color and depth photo, only used the depth map.
	coord: input (x,y) coordinates on the depth map.  
	Returns a mask in the form of PXCImage for blending with the current photo frame.
	Note: this function simply calls ComputeMaskFromThreshold underneath.
	*/
	virtual PXCImage* PXCAPI ComputeMaskFromCoordinate(const PXCPhoto *photo, PXCPointI32 coord) = 0;

	/* 
	UpScaleDepth: Resize the depth map of a given photo according to its color image size. 
	High quality upscaling of depth image based on color image.
	photo: input image color+depth
	Returns a Depth map that has the same aspect ratio as the color image resolution.
	Note: Returns a nullptr if the aspect ratio btw color and depth is not preserved
	*/
	virtual PXCPhoto* PXCAPI DepthResize(const PXCPhoto *photo, PXCSizeI32 size) = 0;
    
	/* 
	PasteOnPlane: This function is provided for texturing a smaller 2D image (foreground)
	onto a bigger color + depth image (background). The smaller foreground image, is rendered according to a
	user-specified position and an auto-detected plane orientation onto the background image.
	The auto-oriented foreground image and the color data of the background image are composited together
	according to the alpha channal of the foreground image.

	imbedIm: the image to imbed in the photo (foreground image)
	topLeftCoord, bottomLeftCoord: are the top left corner and the bottom left corner of where the user wants to embed the image.
	Returns the imbeded foreground with background image.
	*/
	virtual PXCPhoto* PXCAPI PasteOnPlane(const PXCPhoto *photo, PXCImage* imbedIm, PXCPointI32 topLeftCoord, PXCPointI32 bottomLeftCoord) = 0;

	/*
	DepthBlend: blend the a foreground 2D image into the background color+depth image. the function rotates and 
	scales the foreground 2D image before inserting it at a user specified coordinate and depth value. 

	sampleBackground: 2D+depth background image. The depth data should be hole-filled
	imgForeground: RGBA 2D foreground image 
	insertCoord: (x,y) user-specified location of the 2D image center onto the background image
	insertDepth: user-specified depth value of the 2D image inside the background image. 
	rotation[3]: is the Pitch, Yaw, Roll rotations in degrees in the Range: 0-360. 
		rotaion[0]: pitch 
		rotaion[1]: yaw
		rotaion[2]: roll
	scaleFG: scaling factor. E.g. 2.0 means 2x bigger.
	PXCPhoto: the returned blended 2D image foreground + background.
	*/
	virtual PXCPhoto* PXCAPI DepthBlend(const PXCPhoto *sampleBackground, PXCImage* imgForeground, 
		PXCPointI32 insertCoord, pxcI32 insertDepth, pxcI32 rotation[3], pxcF32 scaleFG) = 0;



	/* 
	ObjectSegment: generates an initial mask for any object selected by the bounding box. 
	The mask can then be refined by hints supplied by the user in RefineMask() function. 
	photo: input color and depth photo.
	topLeftCoord    : top left corner of the object to segment.  
	bottomRightCoord: Bottom right corner of the object to segment.
	Returns a mask in the form of PXCImage with detected pixels set to 255 and undetected pixels set to 0.
	*/
	virtual PXCImage* PXCAPI ObjectSegment(const PXCPhoto *photo, PXCPointI32 topLeftCoord, PXCPointI32 bottomRightCoord) = 0;
	    
	/* 
	RefineMask: refines the mask generated by the ObjectSegment() function by using hints.
    hints: input mask with hints. hint values.
     0 = no hint
     1 = foreground
     2 = background
	Returns a mask in the form of PXCImage with detected pixels set to 255 and undetected pixels set to 0.
	*/
	virtual PXCImage* PXCAPI RefineMask(const PXCImage *hints) = 0;

	/* 
	Input param for Tracking Method: 
	LAYER: track the depth layer in each frame
	OBJECT: track the slected object in each frame
	*/
	enum TrackMethod {
		LAYER = 0, 
		OBJECT, 
	};

	/* 
	InitTracker: creates an object tracker with a specific tracking method and an initial bounding mask 
	as a hint for the object to detect. 
	firstFrame: first frame input color and depth photo.
	boundingMask: a hint on what object to detect setting the target pixels to 255 and background to 0.  
	method: Tracking method for depth layer tracking or object tracking.
	*/
	virtual pxcStatus PXCAPI InitTracker(const PXCPhoto *firstFrame, const PXCImage *boundingMask, TrackMethod method) = 0;
	__inline pxcStatus InitTracker(const PXCPhoto *firstFrame, const PXCImage *boundingMask) { 
		return InitTracker(firstFrame, boundingMask, TrackMethod::LAYER);
	}
	
	/* 
	TrackObject: tracks the object selected in InitTracker() in every nextFrame.
	Returns a mask in the form of PXCImage with detected pixels set to 255 and undetected pixels set to 0.
	*/
	virtual PXCImage* PXCAPI TrackObject(const PXCPhoto *nextFrame) = 0;

};