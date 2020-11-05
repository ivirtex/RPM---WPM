#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    DWORD pid = 0;
    SIZE_T bytesWritten = 0;
    string valueToWrite = "";

    cout << "PID: ";
    cin >> pid;

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) { // Failed to get a handle
        cout << endl << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
        system("pause");

        return EXIT_FAILURE;
    }

    uintptr_t memoryAddress = 0x0;
    cout << endl << "Memory address to overwrite: 0x";
    cin >> hex >> memoryAddress;

    cout << "Value to write: ";
    cin >> dec >> valueToWrite;
    
    cout << "Writing 0x" << hex << memoryAddress << "..." << endl << endl;

    BOOL wpmReturn = WriteProcessMemory(hProcess, (LPVOID)memoryAddress, &valueToWrite, sizeof(string), &bytesWritten);
    if (wpmReturn == FALSE) {
        cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
        system("pause");

        return EXIT_FAILURE;
    }

    cout << "Overwritten successfully" << endl;
    cout << "Bytes written: " << bytesWritten << endl << endl;
    cout << "Press ENTER to quit." << endl;
    system("pause > nul");

    return EXIT_SUCCESS;
}