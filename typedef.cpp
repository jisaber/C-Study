#include<iostream>
#include<cstring>
#include<typeinfo>
using namespace std; 
typedef long int *pint32;
/*以下是个人理解 
相当于给long int重新取个名字叫pint32，但是因为这个类型多定义为指针类型，直接加一个型号变成指针类型，
之后定义直接用pint32 x,y,z;相当于志强的long int *x ，*y，*z；主要目的是为了简化操作 
*/
pint32 x,y,z;

int main(){
	cout<<&x<<endl;
	cout<<sizeof(z);	
}
