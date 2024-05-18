/* copyright C++ Primer Plus */
#include <iostream>
inline double square(double x) { return x * x; }

int main()
{
    using namespace std;
    double a, b;
    double c = 13.0;
    a = square(5.0);
    b = square(4.5 + 7.5);
    cout << "a=" << a << ",b=" << b << ",c=" << c << endl;

    cout << ", c squared=" << square(c++) << "\n"; // c结果是169，先做传值再计算++
    cout << "Now,c=" << c << endl;
    return 0;
}