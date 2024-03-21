#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define bt2_id 2
#define bt3_id 3
#define bt4_id 4
#define bt5_id 5

HWND bt_quit;

LRESULT wndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (message == WM_DESTROY)
        PostQuitMessage(0);
    else if (message == WM_COMMAND)
    {
        if (bt_quit == lparam)
            PostQuitMessage(0);

        if (LOWORD(wparam) == bt2_id)
        {
            if (IsIconic(hWnd)) {
                ShowWindow(hWnd, SW_RESTORE);
            }
            else {
                ShowWindow(hWnd, SW_MINIMIZE);
            }
        }


        if (LOWORD(wparam) == bt3_id)
            MessageBoxA(hWnd, "Modal", "Put 5 pls", MB_OK);

        if (LOWORD(wparam) == bt4_id)
            MessageBoxA(NULL, " Not Modal", "Put 5 pls", MB_OK);

        if (LOWORD(wparam) == bt5_id)
        {
            MessageBoxA(NULL, "Not Modal, and i have a brother", "Put 5 pls", MB_OK);
            MessageBoxA(NULL, "Not Modal, and i have a sister", "Put 5 pls", MB_OK);
        }        
    }

    return DefWindowProcA(hWnd, message, wparam, lparam);
}

int main()
{
    WNDCLASSA wcl;
    memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.lpszClassName = "my Window";
    wcl.lpfnWndProc = wndProc;
    RegisterClassA(&wcl);

    HWND hwnd = CreateWindowA("my Window", "Window Name", WS_OVERLAPPEDWINDOW,
        10, 10, 640, 480, NULL, NULL, NULL, NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);

    bt_quit = CreateWindowA("button", "Quit",
        WS_VISIBLE | WS_CHILD,
        10, 10, 100, 50,
        hwnd, NULL, NULL, NULL);

    HWND bt2 = CreateWindowA("button", "Roll up",
        WS_VISIBLE | WS_CHILD,
        110, 10, 100, 50,
        hwnd, bt2_id, NULL, NULL);

    HWND bt3 = CreateWindowA("button", "Modal",
        WS_VISIBLE | WS_CHILD,
        210, 10, 100, 50,
        hwnd, bt3_id, NULL, NULL);

    HWND bt4 = CreateWindowA("button", "Not Modal",
        WS_VISIBLE | WS_CHILD,
        310, 10, 100, 50,
        hwnd, bt4_id, NULL, NULL);

    HWND bt5 = CreateWindowA("button", "Multiply Window",
        WS_VISIBLE | WS_CHILD,
        410, 10, 150, 50,
        hwnd, bt5_id, NULL, NULL);


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
