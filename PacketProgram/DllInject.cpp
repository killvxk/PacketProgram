#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
HWND hWnd(0);
using namespace std;
HANDLE hProc;
DWORD teraID;
LPVOID AddressOfAllocatedMem;
DWORD dwAllocatedAddress;
void GetHandle() {
	cout << "Waiting for TERA.exe to launch.." << endl;
	while (!hWnd)
	{
		hWnd = FindWindow(0, ("1 (Hacked by Ulysse) TERA"));
		if (hWnd == NULL)
		{
			hWnd = FindWindow(0, ("TERA"));
			if (hWnd == 0)
				Sleep(1);
			else
				cout << "window found." << endl;
			SetWindowText(hWnd, "1 (Hacked by Ulysse) TERA");
		}
		else
			cout << "window found." << endl;
		Sleep(200);

	}
	GetWindowThreadProcessId(hWnd, &teraID);
	if (teraID == 0)
		cout << "failed to get process ID." << endl;
	else
		cout << "Retrieved process Id." << endl;
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, teraID);
	if (hProc == 0)
		cout << "can't retrieve handle" << endl;
	else
		cout << "handle retrieved" << endl;
}
void InjectDll(char *chDllName) {
	AddressOfAllocatedMem = VirtualAllocEx(hProc, 0, 4000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (AddressOfAllocatedMem == 0)
		cout << "could not allocate memory" << endl;
	else
		cout << "Memory allocated" << endl;
	WriteProcessMemory(hProc, AddressOfAllocatedMem, chDllName, strlen(chDllName), NULL);
	HMODULE hKernel32 = GetModuleHandle("Kernel32");
	HANDLE localHandle = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "LoadLibraryA"), AddressOfAllocatedMem, 0, 0);
	if (localHandle == 0)
		cout << "couldn't create thread" << endl;
	else
		cout << "thread created" << " adress of string is : " << AddressOfAllocatedMem << endl;

}