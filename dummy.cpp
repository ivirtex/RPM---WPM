#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    int varInt = 123456;
    string varString = "DefaultString";
    char arrChar[128] =  "Long char array right there ->";
    int* ptr2int = &varInt;
    int** ptr2ptr = &ptr2int;
    int*** ptr2ptr2 = &ptr2ptr;

    do {
        cout << "Procces ID: " << GetCurrentProcessId() << endl << endl;
        cout << "varInt         (" << &varInt << ") = " << varInt << endl;
        cout << "varString      (" << &varString << ") = " << varString << endl;
        cout << "arrChar[128]   (" << &arrChar << ") = " << arrChar << endl << endl;
        
        cout << "ptr2int        (" << &ptr2int << ") = " << ptr2int << endl;
        cout << "ptr2ptr        (" << &ptr2ptr << ") = " << ptr2ptr << endl;
        cout << "ptr2ptr2       (" << &ptr2ptr2 << ") = " << ptr2ptr2 << endl << endl;

        cout << "Press ENTER to print again." << endl;
        getchar();
        cout << endl << "---------------------------------------------------" << endl << endl;
    } while(true);
}