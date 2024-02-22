#include <iostream>

using namespace std;

void foo(int* x)//int* is a pointer type - value: 0x7ffee8ea46a8 from plugged in - address: new address
{
    *x += 1; // * dereferences x - back to the value of i which is 3 + 1 = 4
    cout << "Value of x is " << x << endl; // 0x7ffee8ea46a8
    cout << "Address of x is " << &x << endl; // different address storing above address 
    cout << "Value of where x is pointing " << *x << endl; // * points back to the origin of the address
}

int main()
{
    int i = 3;
    cout << "value of i is " << i << endl; // i:3 | Address: 0x7ffee8ea46a8
    cout << "address of i is " << &i << endl; //& = address so pointing to 0x7ffee8ea46a8
    foo(&i); // memory address of i - 0x7ffee8ea46a8 being plugged into foo
    cout << "Value of i is " << i << endl; 
    return 0;
}