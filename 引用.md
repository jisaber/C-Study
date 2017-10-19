/*
引用于指针类似，但是引用不能凭空产生，必须依附与某个已经存在的 变量，
而且这个时候引用和原变量基本相同，但是引用是一个指针，可以直接操作 ，
而且通过引用改变变量值，原变量也会改变 

*/

#include <iostream>
#include <cmath>

using namespace std;
int main(){

/*C++ 引用 vs 指针

引用很容易与指针混淆，它们之间有三个主要的不同：

    不存在空引用。引用必须连接到一块合法的内存。
    一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
    引用必须在创建时被初始化。指针可以在任何时间被初始化。
    */
	int i;
	double d; 
	
	int& r = i;//必须在初始化的时候声明否则会报错 
	double& s = d;
	
	i = 5;
	cout<<"Value of i :"<<i<<endl;
	cout<<"Value of i reference :"<<r<<endl;
	
	d =  11.7;
	cout<<"Value of d: "<<d<<endl;
	cout<<"Value of d reference :"<<s<<endl;
	
	s++;
	cout<<"Value of d: "<<d<<endl;
	
}

 
