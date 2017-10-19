#include<iostream>
#include<cstring>
using namespace std;


//定义 ，且不能再调用之后定义，必须在主函数之前定义

struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

int access_struct(){
	Books Book1;
	Books Book2;
	
	strcpy(Book1.title,"C++教程");
	strcpy(Book1.author,"zhuxaing");
	strcpy(Book1.subject,"Programme");
	Book1.book_id=123450;
	
	strcpy(Book2.title,"CSS教程");
	strcpy(Book2.author,"zhuxaing");
	strcpy(Book2.subject,"Javascript");
	Book1.book_id=123456;
	
	cout<<Book1.title<<endl;
	cout<<Book1.author<<endl;
	cout<<Book1.subject<<endl;
	cout<<Book1.book_id<<endl;
	
	cout<<Book2.title<<endl;
	cout<<Book2.author<<endl;
	cout<<Book2.subject<<endl;
	cout<<Book2.book_id<<endl;
	
	return 0;	
}
//结构体作为函数参数 ，普通的参数 

void printBook(struct Books book );

int struct_as_parameter(){
	Books Book1;
	Books Book2;
	
	strcpy(Book1.title,"C++教程");
	strcpy(Book1.author,"zhuxaing");
	strcpy(Book1.subject,"Programme");
	Book1.book_id=123450;
	
	strcpy(Book2.title,"CSS教程");
	strcpy(Book2.author,"zhuxaing");
	strcpy(Book2.subject,"Javascript");
	Book1.book_id=123456;
	
	printBook(Book1);
	
	printBook(Book2);
	
}
void printBook(struct Books book1 ){
	cout<<book1.title<<endl;
	cout<<book1.author<<endl;
	cout<<book1.subject<<endl;
	cout<<book1.book_id<<endl; 
} 
//结构体作为函数的参数，且为指针形式 ，与其它类型的指针参数类似，准确地生活就是一模一样 
void printBook1(struct Books *book1);

int struct_as_indicator(){
	Books Book1;
	Books Book2;
	
	strcpy(Book1.title,"C++教程");
	strcpy(Book1.author,"zhuxaing");
	strcpy(Book1.subject,"Programme");
	Book1.book_id=123450;
	
	strcpy(Book2.title,"CSS教程");
	strcpy(Book2.author,"zhuxaing");
	strcpy(Book2.subject,"Javascript");
	Book1.book_id=123456;
	
	printBook1(&Book1);
	
	printBook1(&Book2); 
	
}
//这个时候访问不能是 *Book.title这样是非法的。
//必须用结构体自身的访问成员运算符 -> 
void printBook1(struct Books *book1){
	cout<<book1->title<<endl;
	cout<<book1->author<<endl;
	cout<<book1->subject<<endl;
	cout<<book1->book_id<<endl;	
}

int main(){
	access_struct();
	struct_as_parameter();
	struct_as_indicator();
}
