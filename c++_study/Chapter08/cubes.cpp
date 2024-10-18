/* copyright C++ Primer Plus */
#include <iostream>
double cube(double a);
double cuberef(const double &ra);

int main()
{
    using namespace std;
    double x = 3.0;
    cout << cube(x);
    cout << " =cube of " << x << endl;
    cout << cuberef(x);
    cout << " =cube of " << x << endl;

    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

// 如果加了const会报编译错误, 当尝试修改引用的时候 
//  error: assignment of read-only reference 'ra'
double cuberef(const double &ra)
{
    ra *= ra * ra;
    return ra;
}
