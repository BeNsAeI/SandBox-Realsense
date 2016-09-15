/*******************************************************************************
INTEL CORPORATION PROPRIETARY INFORMATION
This software is supplied under the terms of a license agreement or nondisclosure
agreement with Intel Corporation and may not be copied or disclosed except in
accordance with the terms of that agreement
Copyright(c) 2015 Intel Corporation. All Rights Reserved.
*******************************************************************************/
/// @file pxc3dscan.h
/// 3D Capture video module interface
#pragma once
#include "pxccapture.h"

class PXC3DScan : public PXCBase
{
public:
    PXC_CUID_OVERWRITE(PXC_UID('S', 'C', 'I', '1'));

    /// Scanning modes
    enum ScanningMode {
        VARIABLE = 0,                        // Fixed (in this release) to the largest scanning area per camera
        OBJECT_ON_PLANAR_SURFACE_DETECTION,  // Scanning area is auto-fit to detected object, surface is removed automaticaly
        FACE,                                // Fixed scanning size for scanning human faces.
        HEAD,                                // Fixed scanning size for scanning human head (and shoulders, or hat)
        BODY                                 // Fixed scanning size for scanning human body (with arms at sides)
    };

    /// Reconstruction options
    enum ReconstructionOption {             /// Bit field
        NONE           = 0,
        SOLIDIFICATION = (1<<0),             // Fill holes and close mesh (manifold)
        TEXTURE        = (1<<1)              // Generate texture map (instead of vertex color)
    };

    /// Configuration structure
    struct Configuration {
        pxcI32               minFramesBeforeScanStart; // Must be at least 3 in this release
        ScanningMode         mode;
        ReconstructionOption options;
        pxcI32               reserved[256];
    };

    /// Get a copy of the current configuration
    virtual Configuration PXCAPI QueryConfiguration(void) = 0;

    /// Configure the scanning system according to the provided configuration and restart the scanning process
    virtual pxcStatus PXCAPI SetConfiguration(Configuration config) = 0;

    /// Render an image of the scanned data from the perspective of the last frame processed.
    virtual PXCImage* PXCAPI AcquirePreviewImage(void) = 0;

    /// Determine if the scan has started.
    virtual pxcBool PXCAPI IsScanning(void) = 0;

    /// Supported output file formats.
    enum FileFormat { OBJ, PLY, STL };

    /// Generate a mesh on disk from the scanned data.
    virtual pxcStatus PXCAPI Reconstruct(FileFormat format, const pxcCHAR* fileName) = 0;

    /// PXC3DScan reconstruction file format extension helper
    __inline static const pxcCHAR * FileFormatToString(FileFormat format) {
        switch (format) {
        case OBJ: return (const pxcCHAR*)L"obj";
        case PLY: return (const pxcCHAR*)L"ply";
        case STL: return (const pxcCHAR*)L"stl";
        }
        return (const pxcCHAR*)L"Unknown";
    }
};

/// ReconstructionOption helper function
__inline static PXC3DScan::ReconstructionOption operator|(PXC3DScan::ReconstructionOption a, PXC3DScan::ReconstructionOption b)
{
    return (PXC3DScan::ReconstructionOption)((int)a | (int)b);
}

/// ReconstructionOption helper function
__inline static PXC3DScan::ReconstructionOption operator^(PXC3DScan::ReconstructionOption a, PXC3DScan::ReconstructionOption b)
{
    return (PXC3DScan::ReconstructionOption)((int)a ^ (int)b);
}
