
void MouseSetup(INPUT *buffer)
{
	buffer->type = INPUT_MOUSE;
	buffer->mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
	buffer->mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
	buffer->mi.mouseData = 0;
	buffer->mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
	buffer->mi.time = 0;
	buffer->mi.dwExtraInfo = 0;
}


void MouseMoveAbsolute(INPUT *buffer, int x, int y)
{
	buffer->mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
	buffer->mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);

	SendInput(1, buffer, sizeof(INPUT));
}


void MouseClick(INPUT *buffer)
{
	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
	SendInput(1, buffer, sizeof(INPUT));

	Sleep(10);

	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
	SendInput(1, buffer, sizeof(INPUT));
}
