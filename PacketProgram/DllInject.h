#ifndef DLLINJECT_H
#define DLLINJECT_H
//prots
void InjectDll(char *chDllName);
void GetHandle();


//Vars :
extern HWND hWnd;
extern HANDLE hProc;
extern DWORD teraID;
extern LPVOID AddressOfAllocatedMem;
extern DWORD dwAllocatedAddress;
#endif