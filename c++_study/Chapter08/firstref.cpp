/* copyright C++ Primer Plus */
#include <iostream>

int main()
{
    using namespace std;

    int rats = 101;
    int & rodent = rats;

    cout << "rats:" << rats << " rodent:" << rodent << endl;

    rodent++;
    cout << "rats:" << rats << " rodent:" << rodent << endl;

    cout << "rats addr:" << &rats << " rodent addr:" << &rodent << endl;


    return 0;
}