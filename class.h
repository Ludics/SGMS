//class.h		base类，course类，student类的定义与实现
#ifndef _CLASS_H
#define _CLASS_H
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
const int NUM = 100;

//基类base类，抽象类
class base
{
public:
	virtual void Display() = 0;		//纯虚函数
	virtual ~base() {}				//虚析构函数
};
//course类
class course:
	public base
{
private:
	int credit[NUM];				//学分
	string courseName[NUM];			//课程名
	int total;						//总课程数
	ifstream  courseIn;
	ofstream courseOut;
public:
	course();	
	virtual ~course() {}
	void setCourse();							//设置课程信息
	virtual void Display();				//显示课程信息
	int getCredit(int i) const			{ return credit[i];		}
	string getCourseName(int i) const	{ return courseName[i];	}
	int getTotal()	const				{ return total;			}
};

//构造函数，打开用户课程信息，若不存在则加载默认课程信息
course::course()						
{	
	for ( int i = 0; i < NUM; i++)
		courseName[i] = '\0', credit[i] = 0;
	courseIn.open( "UsrCourse.txt" ); 
	if ( !courseIn ){
		total = 8;
		courseName[0] = "微积分";
		credit[0] = 5;
		courseName[1] = "线性代数";
		credit[1] = 4;
		courseName[2] = "大学物理";
		credit[2] = 4;
		courseName[3] = "离散数学";
		credit[3] = 3;
		courseName[4] = "程序设计";
		credit[4] = 2;
		courseName[5] = "电子电路";
		credit[5] = 2;
		courseName[6] = "英语";
		credit[6] = 2;
		courseName[7] = "体育";
		credit[7] = 1;
	}
	else {
		courseIn >> total; 
		for ( int i = 0; i < total; i++)
			courseIn >> courseName[i] >> credit[i];	
		courseIn.close();
	}
}

void course::setCourse()
{
//输入用户课程信息到内存中
	cout << "\n当前课程信息为：\n";
	cout << setiosflags(ios_base::left)
		 << "\n\t\t课程数量为：\t" << total << endl;
	cout << "\t\t#序号#\t" << setw(15) << "#课程#"
		<< setiosflags(ios_base::left) << "#学分#" <<endl;
	for (int i = 0; i < total; i++)
		cout << "\t\t" << i+1 << "\t" << setw(15)<< courseName[i] 
			 << setiosflags(ios_base::left)<< credit[i] << endl;
	cout << "\n修改课程信息将删除全部学生成绩信息！！请对文件stuInfo.txt进行备份。\n";
	cout << "确认修改吗？(y\\n)";
	cin.get();
	char x;
	x = getchar();
	if ( x == 'y' || x == 'Y' )
	{
		ofstream out;
		out.open("stuInfo.txt");
		out << '\0';
		out.close();
		for ( int i = 0; i < total; i++)
			courseName[i] = '\0', credit[i] = 0;
		cout << "请输入总课程数：\t";
		cin >> total;
		cout << "请依次输入课程名及对应学分:\n";
		for ( int i = 0; i < total; i++)
		{	
			cout << "第 " << i+1 << " 门课的课程名为：";
			cin >> courseName[i];
			cout << "\t     学分为：";
			cin >> credit[i];
		}
	
	//将设置的课程信息保存到文件UsrCourse.txt中
		courseOut.open( "UsrCourse.txt");
		courseOut << total << endl;
		for ( int i = 0; i < total; i++)
		{
			courseOut << courseName[i] << "\t" << credit[i] <<endl;
		}
		cout << "\n\n课程名设置完毕，按任意键继续...\n";
		cin.get();cin.get();
	}
	else 
	{
		cout << "按任意键返回...";
		cin.get();cin.get();
	}
}

//显示课程信息
void course::Display()
{
	cout << setiosflags(ios_base::left)
		 << "\n\t\t课程数量为：\t" << total << endl;
	cout << "\t\t#序号#\t" << setw(15) << "#课程#" 
		<< setiosflags(ios_base::left) << "#学分#" <<endl;
	for (int i = 0; i < total; i++)
		cout << "\t\t" << i+1 << "\t" << setw(15)<< courseName[i] 
			 << setiosflags(ios_base::left)<< credit[i] << endl;
	cout << "\n\n按任意键继续...";
	cin.get();cin.get();
}

//student类
class student
	:public course
{
	friend class stuInfo;
public:
	student();
	void stuInfoInput();
	void readFile(ifstream &stuIn);
	void stuDisplay() const;
private:
	student* Next;
	string Name;
	string stuNumber;
	string gender;
	double Score[NUM];				//分数
	double GPA;						//学分绩
	double totalScore;				//总分
};

student::student()
{
	Next = NULL;
	Name = stuNumber = gender = '\0';
	for ( int i = 0; i < NUM; i++) Score[i] = 0;
	GPA = totalScore = 0;
}

//学生信息输入函数，通过键盘将学生信息输入到内存
void student::stuInfoInput()
{
	cout << "\t\t学生姓名：";
	cin >> Name;
	cout << "\t\t学号：";
	cin >> stuNumber;
	cout << "\t\t性别：";
	cin >> gender;
	cout << "\t\t请输入各科成绩：\n";
	totalScore = 0;
	double sumScore = 0,sumCredit = 0;
	for ( int i = 0; i < getTotal(); i++)
	{
		cout << "\t\t" << getCourseName(i) << "：";
		cin >> Score[i];
		totalScore += Score[i];
		sumScore += Score[i] * getCredit(i);
		sumCredit += getCredit(i);
	}
	GPA = sumScore / sumCredit;
	for ( int i = getTotal(); i < NUM; i++) Score[i] = 0;
}

//文件读取函数，将stuIn中信息读取到内存
void student::readFile(ifstream &stuIn)
{
	stuIn >> Name >> stuNumber >> gender >> GPA;
	for ( int i = 0; i < getTotal(); i++)
		stuIn >> Score[i];
	stuIn >> totalScore;
}

void student::stuDisplay() const
{
	cout << setiosflags(ios_base::left)
		 << setw(20) << "\t\t  姓名" << Name << "\n"
		 << setw(20) << "\t\t  学号" << stuNumber << "\n"
		 << setw(20) << "\t\t  性别" << gender << "\n"
		 << setw(20) << "\t\t  GPA" << GPA << "\n"
		 << setw(20) << "\t\t  总分" << totalScore << "\n";
	cout << "\t\t--------------------------" << endl;
	for ( int i = 0; i < getTotal(); i++ )
		cout << "\t\t" << i+1 << "\t" << setw(10) << getCourseName(i)
			 << "\t" << setiosflags(ios_base::left)
			 << Score[i] << endl;
	cout << endl;
} 
#endif  //_CLASS_H
