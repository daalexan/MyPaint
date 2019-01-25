#include "stdafx.h"
#include "MainWindow.h"
#include <crtdbg.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
	MSG msg;
	MainWindow *main = new MainWindow(hInstance, MAKEINTRESOURCE(IDD_MAINDIALOG), NULL);
	main->Show(1);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	delete main;
	_CrtDumpMemoryLeaks();
	return 0;
}