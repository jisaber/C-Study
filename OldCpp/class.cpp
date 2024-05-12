class Box
{
   public:
      double length;   // 盒子的长度
      double breadth;  // 盒子的宽度
      double height;   // 盒子的高度
};
//之后再补充吧。在宾馆完全看不下去
#include<iostream>
using namespace std;
//类有点类似于结构体，相当于在函数外部定义了一种全新的变量
//相当于int的初始定义
class Box{
   public:
      double length;
      double breadth;
      double height;

};//这里的分号不能忘记都则回报错



int main(){
   Box Box1;
   Box Box2;
   double volume = 0.0;


   // box 1 详述,box1成员的赋值直接用‘.’来操作
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;
 
   // box 2 详述
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;
 
   // box 1 的体积，可以直接对类的成员进行操作
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Box1 的体积：" << volume <<endl;
 
   // box 2 的体积
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Box2 的体积：" << volume <<endl;
   return 0;
}
//下面是输出
/*
×××××××××××:~$ bash gcc.sh
Box1 的体积：210
Box2 的体积：1560
*/
/*
而且今天遇到一个傻逼问题，我一开始竟然用gcc来编译.cpp文件，后来发现使用g++来编译的。
然后自己写个.sh分分钟解决问题。恩！
*/
