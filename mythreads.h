#include<signal.h>
#include<Windows.h>
#include<stdio.h>

void RemoveHookThread(int code, DWORD tid = 0)
{
    if (PostThreadMessageA(tid, WM_QUIT, (WPARAM)NULL, (LPARAM)NULL) == 0)
    {
        printf("\nCannot send the WM_QUIT message to the hook thread\n");
        exit(EXIT_FAILURE);
    }
}

void CreateHookThread(void(*HookUnhook), DWORD tid = 0)
{
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HookUnhook, (void *)NULL, 0, &tid);
    if (hThread == NULL)
    {
        printf("Cannot create a new hook thread\n");
    }
    else
    {
        signal(SIGINT, (__p_sig_fn_t)RemoveHookThread);
        WaitForSingleObject(hThread, INFINITE);
        signal(SIGINT, SIG_DFL);
        CloseHandle(hThread);
    }
}