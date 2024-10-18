/* copyright C++ Primer Plus */
#include <iostream>
void swapr(int & a, int &b);
void swapp(int* a, int *b);
void swapv(int a, int b);


int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1:" << wallet1 << " wallet2:" << wallet2 << endl;

    cout << "Using references to swap\n";
    swapr(wallet1, wallet2);
    cout << "wallet1:" << wallet1 << " wallet2:" << wallet2 << endl;

    cout << "Using point to swap\n";
    swapp(&wallet1, &wallet2);
    cout << "wallet1:" << wallet1 << " wallet2:" << wallet2 << endl;

    cout << "Using value to swap\n";
    swapv(wallet1, wallet2);
    cout << "wallet1:" << wallet1 << " wallet2:" << wallet2 << endl;


    return 0;
}

void swapr(int & a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapp(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapv(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
