/*
类继承的形式如下，derived-class叫做派生类，base-class叫做基类，一个派生类可以来源于多个基类。
其中的acess-specifier访问修饰符是 public、protected 或 private 其中的一个，代表派生类从基类继承的方式，  
public继承之后所有的成员都是public，以此类推。
class derived-class: access-specifier base-class，access-specifier base-class


*/


#include<iostream>
#include<time.h>
using namespace std;

//基类
class Shape{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};


//派生类，这个是公有继承
class Rectangle:public Shape{
   public:
      int getArea(){
         return (width*height);
      }
};
/*
这个继承相当于，把基类的可以继承的数据和方法
class Rectangle:public Shape{
   public:
      int getArea(){
         return (width*height);
      }
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

*/

//在主函数中进行各种调用

int main()
{
   clock_t startTime,endTime,totaltime;
   startTime = clock();  

   Rectangle Rect;
   Rect.setWidth(5);
   Rect.setHeight(7);
   cout<<Rect.getArea()<<endl;

 
   endTime = clock();  
   totaltime = endTime - startTime;
   cout<<"程序运行时间:"<<totaltime<<"ms"<<endl;

}
