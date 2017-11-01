/*
>> and << 这两个标识可以看做数据流的方向，A >> B，代表A流向B
所以 COUT << X 因为cout可以看做linux下的一个输出设备，
所以信息流从X流向了输出设备 

C++的逻辑貌似是所有的标准都是以内存为核心，如
outfile这个输出指的是从内存输出到文件而infile指的是从文件输出到内存 

这里的fstream ifstream ofstream都是类，使用时要先实例一个对象，然后这个对象继承了类的所有数据和方法。
然后再在对象上进行操作。 
*/

#include<iostream> 
#include<fstream>
using namespace std;
int main(){
	char data[100];
	
	// open file with write model
	ofstream outfile;
	outfile.open("afile.dat");
	
	cout<<"writing to the file"<<endl;
	cout<<"Enter your name"<<endl;
	cin.getline(data,100);
	
	
	//开始向文件写入用户输入的数据
	
	outfile<<data<<endl;
	
	cout<<"enter your age"<<endl;
	cin>>data;
	cin.ignore();//ignore会忽略之前的读语句留下的多余字符 
	
	outfile<<data<<endl ;
	
	outfile.close();
	
	// open file with read model
	
	ifstream infile;
	infile.open("afile.dat");
	
	infile>>data;//信息流从infile流向data
	
	cout<<data<<endl;
	
	infile>>data;
	cout<<data<<endl;
	
	infile.close();
	
	return 0; 
		 
}
/*
writing to the file
Enter your name
zhuxiang
enter your age
22
zhuxiang
22
请按任意键继续. . .
*/
