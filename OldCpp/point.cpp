/*
总结提纲，就是指
1. 针要用就得先定义，int *p 之类的，p是一个地址，可以++ -- + - 操作，但是不能赋值给普普通通的0xffeedd之类，编译可以通过，但执行的时候会出错。
2. & 是取地址操作，基本上普通的变量都需要这个取地址操作，实际上指针变量可以通过他再去一次地址，多级间接寻址的问题
3. *p 就是间接访问地址的内容，其于普通变量一样，可以说*p=var=100
4. 嗯！就这样，有什么问题后续再补

*/
#include <iostream>
using namespace std;
const int MAX = 3;
int main(){
	int var;//这是一个变量 
	int *ptr;//这是一个指针变量（虽然是变量，但是必须赋值给ptr一个地址，*是间接访问操作） 
	int **pptr;//C++允许指向指针的指针（多级间接寻址） 
	
	var = 3000;//对一个普通的变量赋值 
	ptr = &var;//理论上来说ptr可以赋值如0xffeeccdd之类的，但是由于地址指向不明（就算是明确的地址）计算机依然会报错，所以只能通过&取地址操作来赋值 
	pptr = &ptr;//对ptr这个指针变量再进行一次取地址操作 
	
	
	cout<< "Adress of var"<<&var<<"另外一种访问方式"<<ptr<<endl;
	cout<<" Value  of var"<<var<<"另外一种访问方式"<<*ptr<<endl;  
	cout<< "Adress of ptr"<<&ptr<<"另外一种访问方式"<<pptr<<endl;
	cout<<" Value  of ptr"<<*ptr<<"另外一种访问方式"<<**pptr<<endl;
	
	**pptr = 100；
	cout<<" Value  of var"<<var<<endl;
	//这个时候var变成了100
 	 
 	 
	/*地址的不同操作方式 的结果 
	Adress of var0x28ff44另外一种访问方式0x28ff44
	Value  of var3000另外一种访问方式3000
	Adress of ptr0x28ff40另外一种访问方式0x28ff40
	Value  of ptr3000另外一种访问方式3000
	 Value  of var100
	
	请按任意键继续. . .
	*/
 	
	 /*下面是数组的指针访问 */
 	int var_array[MAX] = {10,100,200};
 	int *ptr_array;//不定义成指针会报错，因为一维数组的var_name就是一个地址,类似于普通变量&var之后的内容，下面就可以直接赋值给指针变量 
 	ptr_array = var_array;
 	
 	for(int i = 0;i < MAX;i++){
		cout<< "Adress of var_arry["<<i<<"]="<<ptr_array<<endl;//这里面得到的是数组中每个元素的地址 
		cout<<" Value  of var_arry["<<i<<"]="<<*ptr_array<<endl;//通过访问每个地址得到数据 
		ptr_array++;
		/*地址支持++，--,+,-操作这个不是加一个，而是加4个，因为整数的大小是4个字节
		我电脑的地址是0x28ff20 0x28ff24 0x28ff28 */
		
		//ptr_array+=1;
		/*这样可以 ，但是结果会不正常 
	    Adress of var_arry[2]=0x28ff30
        Value  of var_arry[2]=1986354116*/
	 }
	 /*输出的结果 
	Adress of var_arry[0]=0x28ff20
	Value  of var_arry[0]=10
	Adress of var_arry[1]=0x28ff24
	Value  of var_arry[1]=100
	Adress of var_arry[2]=0x28ff28
	Value  of var_arry[2]=200
	请按任意键继续. . .
	*/
 	
	/*下面是指针的简单介绍*/
 	int *ip_simple;
 	double *dp_simple;
 	float *fp_imple;
	char *ch_simple;
 	/*上面虽然定义了4个不同类型的指针，但都是地址6位的16进制数，区别只是那个地址中数据类型的差别，而不是指针本身的类型差别， 
 	所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，
	 都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。*/
 
 	int var_simple = 20;
 	ip_simple = &var_simple;
 	ip_simple--;

 	//int i_simple;
 	//i_simple = 0x000000;
	/*虽然这个常数和地址长得很像，但只是外表很像，
 	就像我和吴彦祖，虽然外表很像，但是很多人都不认识我一样，虽然常数和地址很像，但很多系统都拒绝他的访问*/ 	
 	
 	cout<<"Value of var is :"<<var_simple<<endl;
 	//普通的输出变量过程 
 	
 	cout<<"Adress stored in ip variable:"<<ip_simple<<endl;
 	//把地址变量输出，这个时候出现的是一串地址 
 	
 	
 	cout<<"Value of *ip variable:"<<*ip_simple<<endl;
 	//通过指针的简介访问操作符*去读取地址ip_simple中的值，也就是var_simple的值，也就是20 
 	
	 //cout<<"Value of *i variable:"<<*i<<endl;
	 //我们上面虽然给i_simple赋值一个地址，上面已经说了，这个系统不认，会直接报错。 
 	
	 /*下面是普通变量与一位数组的小小区别*/ 
 	int var1;
 	char var2[10];
 	cout<< "Var1变量的地址：" ;
 	cout<<&var1<<endl;
 	
 	cout<<"Var2变量的地址：";
 	cout<<var2<<endl;//数组名是一个特殊变量，他本身就是一个地址。
 }
