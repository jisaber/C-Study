/*
在同一个作用域内，可以声明几个功能类似的同名函数，.
但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。
您不能仅通过返回类型的不同来重载函数。
*/
#include <iostream>
#include <math.h>
using namespace std;
class PrintData{
	public:
		void f(int i){
			cout<<i*i<<endl;
		}
		void f(int i,int j){
			cout<<pow(i,j)<<endl;
		}
};
int main(void){
	PrintData p;
	p.f(5);
	p.f(2,3);
	return 0;
}
/*
25
8
请按任意键继续. . .
*/
