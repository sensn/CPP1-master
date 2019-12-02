#include <windows.h>
#include <stdio.h>

//***
#define WIDTH 70
#define HEIGHT 35

HANDLE wHnd; /* write (output) handle */
HANDLE rHnd; /* read (input handle */

			 
			 //***
int test1(const int mwidth, const int mheight);
int test();

HANDLE hStdin;
DWORD fdwSaveOldMode;


VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
int input_Buffer_Events_main(VOID)
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		printf("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		printf("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		printf("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 

	while (1)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			printf("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				printf("Unknown event type");
				break;
			}
		}
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	return 0;
}

VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	printf("Key event: ");

	if (ker.bKeyDown)
		printf("key pressed\n");
	else printf("key released\n");
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	printf("Mouse event: ");

	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			printf("left button press \n");
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			printf("right button press \n");
		}
		else
		{
			printf("button press\n");
		}
		break;
	case DOUBLE_CLICK:
		
		

		printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		printf("mouse moved\n");
		break;
	case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);

	//test();
	int muh = wbsr.dwSize.X;
	//test1(wbsr.dwSize.X, wbsr.dwSize.Y);
	HANDLE output_handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	if (output_handle == INVALID_HANDLE_VALUE)
		printf("FALSE");
	CONSOLE_SCREEN_BUFFER_INFO info = {};
	if (::GetConsoleScreenBufferInfo(output_handle, &info) == FALSE)
		printf("FALSE");
	size_t width = info.srWindow.Right - info.srWindow.Left;
	size_t height = info.srWindow.Bottom - info.srWindow.Top;
	
	printf("Xs %d Y %d rows.\n", width, height);
	//bool suc = SetWindowSize(width + 1, height + 1);
	test1(width, height);


}

int test() {
	int r, g, b;
	char s[10] = "HOHOHO";
	const int max = 255;
	for (int colnum = 0; colnum < max; colnum++) {
		r = 255 - (colnum * 255 / max - 1);
		g = (colnum * 510 / max - 1);
		b = (colnum * 255 / max - 1);
		if (r > 255) r = 510 - r;
		if (g > 255) g = 510 - g;
		if (b > 255) b = 510 - b;
		//printf("\x1b[38;2;%d;%d;%dmTRUECOLOR\x1b[0m\n",r,g,b);
		//printf("\x1b[48;2;%d;%d;%dmTRUECOLOR\x1b[0m\n",r,g,b);
		//printf("\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dmTRUECOLOR\x1b[0m\n",r,g,b,b,r,g);
		printf("\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dmTRUECOLOR\x1b[0m\n", r, g, b, r, g, b);

		//printf ("\033[48;2;%d;%d;%dmYUHUU\n"), r, g, b;
		//printf ("\033[38;2;%d;%d;%dmHOHO\n"), 255 - r, 255 - g, 255 - b;
	//	printf ("%s\033[0m", s);
	}

	return 444;
}

int test1(const int mwidth, const int mheight) {
	int x, y;

	//srand(time(0));

	/* Window size coordinates, be sure to start index at zero! */
	SMALL_RECT windowSize = { 0, 0, mwidth - 1, mheight - 1 };

	/* A COORD struct for specificying the console's screen buffer dimensions */
	COORD bufferSize = { mwidth, mheight };

	/* Setting up different variables for passing to WriteConsoleOutput */
	COORD characterBufferSize = { mwidth, mheight };
	COORD characterPosition = { 0, 0 };
	SMALL_RECT consoleWriteArea = { 0, 0, mwidth - 1, mheight - 1 };

	/* A CHAR_INFO structure containing data about a single character */
	//const int mewidth = mwidth;
	//const int mewidth = 5;
	
	
	//CHAR_INFO *muh= new CHAR_INFO[mwidth];
	
	//CHAR_INFO consoleBuffer[WIDTH * HEIGHT];
	CHAR_INFO *consoleBuffer=new CHAR_INFO[mwidth * mheight];

	/* initialize handles */
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);

	/* Set the console's title */
	SetConsoleTitle("Our shiny new title!");

	/* Set the window size */
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	/* Set the screen's buffer size */
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	for (y = 0; y < mheight; ++y)
	{
		for (x = 0; x < mwidth; ++x)
		{
			//consoleBuffer[x + mwidth * y].Char.AsciiChar = (unsigned char)219;
			consoleBuffer[x + mwidth * y].Char.AsciiChar = (unsigned char)97;
			consoleBuffer[x + mwidth * y].Attributes = rand() % 256;
		}
	}

	/* Write our character buffer (a single character currently) to the console buffer */
	WriteConsoleOutputA(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);

	getchar();

	return 5;
}
