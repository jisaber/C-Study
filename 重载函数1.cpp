/*
在同一个作用域内，可以声明几个功能类似的同名函数，.
但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。
就是在一个类里面定义同一个函数名称但是参数不一样，这样可以做到实现同一个函数的复杂操作。
您不能仅通过返回类型的不同来重载函数。
*/
#include <iostream>
using namespace std;
class PrintData{
	public:
		void print(int i){
			cout<<"integer:"<<i<<endl;
		}
		void print(double d){
			cout<<"float:"<<d<<endl;
		}
		void print(string c){
			cout<<"string :"<<c<<endl;
		}
};
int main(void){
	PrintData p;
	p.print(5);
	p.print("womenhao");
	p.print(2.30);
	return 0;
}
/*
integer:5
string :womenhao
float:2.3
请按任意键继续. . .
*/
