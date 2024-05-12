/*
本章小结
1.#define 预处理 
#define macro-name replacement-text  遇到macro-name，编译器就用replacement-text替换掉，这个是后面几个变种的基础和前提

2.带参数的预处理
#define MIN（a，b） （a<b?a:b） //括号不能省略

3.条件编译
有点类似于if ... else 结构 
 
#ifndef NULL
    #define NULL 0 
    //执行的代码 
#endif 
如果之前没有定义了NULL符号常量，那么就会执行二者之间的代码 
 
#ifdef DEBUG  
     //执行的代码 
#endif
如果之前定义了DEBUG那么就会执行二者之间的代码

4.#与##
#会把内容变成字符串返回
MKSTR（x） #x
相当于带参数的预处理，遇到MKSTR（X） 就会执行 #x 把其中的X变成一个字符串然后替换MKSTR（X） 
 
## 会把二者拼接返回，而且这种拼接是直接的字符替换 
CONCAT（a，b）  a##b
遇到CONCAT（a，b）就换替换成ab，

int xy=100；不能定义int x=1，y=00；因为经过CONCAT（x，y）之后整个表达式会被替换成xy
 
5.预定义的宏 
__LINE__ 	这会在程序编译时包含当前行号。
__FILE__ 	这会在程序编译时包含当前文件名。
__DATE__ 	这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
__TIME__ 	这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。



*/ 

#include<iostream>
#include<cstring>
#include<ctime> 
 
/*
预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理。

所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾。

我们已经看到，之前所有的实例中都有 #include 指令。这个宏用于把头文件包含到源文件中。

C++ 还支持很多预处理指令，比如 #include、#define、#if、#else、#line 等，让我们一起看看这些重要指令。

*/ 

//#define 预处理  #define 预处理指令用于创建符号常量。该符号常量通常称为 宏 ，指令的一般形式是：
//#define macro-name replacement-text 
//#define 宏指令     替换文本
using namespace std;

#define PI 3.1415926//正常的宏定义 

#define MIN(a,b) (a<b?a:b)//带参数的宏不加括号会报错 

//如果之前定义了符号常量DEBUG ，那么程序就会把这段编译  

/*
#ifdef
#endif

#if 0
#endif 

只能在程序中使用不能在最开始的部分定义

*/
#if 0 
	//不进行编译的代码，他与注释不同，
	//这段代码可能只是暂时用不到，但是之后会用到 
	//而注释是为了更好阅读代码的，有可能错过一些游泳的代码
#endif
	 
int sharpdefine(){
 	cout << "Value of PI : "<< PI << endl;
	return 0;
	// 如果是仅仅进行编译的话，会发现最后会被改成 
	//cout << "Value of PI : "<< 3.1415926 << endl;
}

int parameterdefine(){
	int i,j;
	i=100;
	j=30;
	cout << " small value is :"	<<MIN(i,j) << endl;
	return MIN(i,j);
}

int conditional_compilataion(){
	int i,j;
	i=100;
	j=30;
#ifndef NULL
	#define NULL 0 
#endif 
	
#ifdef DEBUG 
	cerr<<"Trace: Inside main function"<<endl;
#endif

#if 0
	/*这是注释部分*/
	cout<<MKSTR(HELLO C++) << endl;
#endif

	cout<<"The minimum is :"<<MIN(i,j)<<endl;
#ifdef DEBUG 
	cerr<<"Trace: Coming out of function"<<endl;
#endif	
	return 0;

}
#define MKSTR(x) #x

//相当于带参数的宏定义 ，遇到MKSTR就用#x替代 
//这句会把X变成一个字符串，数字也会转换成字符串 
//# 和 ## 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的。
//# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
int sharp(){
	cout<< MKSTR(12345)<<endl;
	return 0;	
}

#define CONCAT(x,y) x##y

//相当于遇到CONCAT（x，y）就用后面的x##y来替代 
//## 运算符用于连接两个令牌。

int sharpsharp(){
	int xy=100;
	//这个定义的就是xy这个变量经过CONCAT处理之后
	//已经不存在x与y了而是一个全新的变量xy 
	cout<<CONCAT(x,y)<<endl;
	return 0;
} 

//预定义的宏 系统自带的用两个下划线括起来__initdefine__

/*
__LINE__ 	这会在程序编译时包含当前行号。
__FILE__ 	这会在程序编译时包含当前文件名。
__DATE__ 	这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
__TIME__ 	这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。

*/ 
int initdefine(){
	cout<<"Vlaue of __LINE__ :"<<__LINE__<<endl;
	//这会在程序编译时包含当前行号
	cout<<"Vlaue of __FILE__ :"<<__FILE__<<endl;
	//显示文件的全部名称地址+文件名+后缀名 
	cout<<"Vlaue of __DATE__ :"<<__DATE__<<endl;
	//显示把源文件转换为目标代码的日期
	cout<<"Vlaue of __TIME__ :"<<__TIME__<<endl;
	//显示它表示程序被编译的时间 
	return 0;
	
}

int main(){
	sharpdefine();
	parameterdefine();
	conditional_compilataion(); 
	sharp();
	sharpsharp();
	initdefine();
	
	
} 
