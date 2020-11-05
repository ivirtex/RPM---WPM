#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    DWORD pid = 0;
    SIZE_T bytesRead = 0;
    int intRead = 0;
    int ptrRead = 0;

    cout << "PID: ";
    cin >> pid;

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) { // Failed to get a handle
        cout << endl << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
        system("pause");

        return EXIT_FAILURE;
    }

    uintptr_t memoryAddress = 0x0;
    cout << endl << "Memory address to read: 0x";
    cin >> hex >> memoryAddress;
    
    cout << "Reading 0x" << hex << memoryAddress << "..." << endl << endl;

    BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)memoryAddress, &intRead, sizeof(int), &bytesRead);
    if (rpmReturn == FALSE) {
        cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
        system("pause");

        return EXIT_FAILURE;
    }

    cout << "intRead = " << dec << intRead << endl;
    cout << "Bytes read: " << bytesRead << endl << endl;
    cout << "Press ENTER to quit." << endl;
    system("pause > nul");

    return EXIT_SUCCESS;

    // BOOL WINAPI ReadProcessMemory(
    // _In_  HANDLE  hProcess,
    // _In_  LPCVOID lpBaseAddress,
    // _Out_ LPVOID  lpBuffer,
    // _In_  SIZE_T  nSize,
    // _Out_ SIZE_T  *lpNumberOfBytesRead
    // );
}