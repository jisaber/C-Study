/* copyright C++ Primer Plus */
#include <iostream>
#include <cmath>

using namespace std;
int stonetolb(int);

int main()
{
    cout << "Enter the weight in stone ";
    int stone;
    cin >> stone;
    int pounds = stonetolb(stone);

    cout << stone << " stone = ";
    cout << pounds << " pounds." << endl;
    return 0;
}

int stonetolb(int sts)
{

    return 14 * sts;
}