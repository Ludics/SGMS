//stuInfo.h		stuInfo类的定义及实现
#ifndef _STUINFO_H
#define _STUINFO_H
#include"class.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

//链表类stuInfo
class stuInfo:
	public base
{
private:
	student *Head, *End;	//表头、表尾指针
	ifstream stuInfoIn;
	ofstream stuInfoOut;
	student* match(string str);
	void swap(student *,student *);
public:
	stuInfo();
	virtual ~stuInfo();
	void addStu();
	void seekStu();
	void modifyStu();
	void deleteStu();
	int countList();
	void swapStu(student *,student *);
	void sortList();
	void saveList();
	virtual void Display();
	void deleteAll();
	void Unpass();
	void Average();
};

//构造函数，读取文件stuInfo.txt中的信息
stuInfo::stuInfo()
{
	Head = new student;
	Head->Next = new student;
	End = Head->Next;
	stuInfoIn.open("stuInfo.txt");
	if ( !stuInfoIn )
		cout << "未发现学生信息，请先输入..." << endl;
	else
	{
		while ( !stuInfoIn.eof() )
		{
			End->readFile(stuInfoIn);
			if ( End->Name[0] == '\0' )	break;
			End->Next = new student;
			End = End->Next;
		}
		stuInfoIn.close();
		cout << "\t\t读取学生信息成功!" << endl;
	}
}

stuInfo::~stuInfo()		//析构函数
{
	saveList();
	for ( student *temp; Head->Next != End; )
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

void stuInfo::addStu()		//向链表尾添加信息
{
	int total;
	cout << "请输入添加人数：\t";
	cin >> total;
	for ( int i = 0; i < total; i++)
	{	
		cout << "请输入第 " << i+1 << " 名同学的信息：\n";
		End->stuInfoInput();
		End->Next = new student;
		End = End->Next;
	}
	saveList();
	cout << "\t\t学生信息添加完毕，按任意键继续...";
	cin.get();cin.get();
}

student* stuInfo::match(string str)
{
//匹配成功则返回上个结点的指针，不成功就返回空
	for ( student *p = Head; p->Next != End; p = p->Next )
		if ( p->Next->Name == str || p->Next->stuNumber == str ) 
			return p;
	return NULL;
}

void stuInfo::seekStu()		//查询信息
{
	string str;
	student* p = NULL;
	cout << "\t\t请输入要查找的学生的姓名或学号：";
	cin >> str;
	if ( p = match( str ) )	
	{
		cout << "查询到学生信息为：\n";
		p->Next->stuDisplay();
		cout << "查询完毕，按任意键继续...";
	}
	else cout << "未查询到信息，按任意键继续...";
	cin.get();cin.get();
}

void stuInfo::modifyStu()		//修改信息
{
	string str;
	student* p = NULL;
	cout << "\t\t请输入要修改信息的学生的姓名或学号：";
	cin >> str;
	if ( p = match( str ) )
	{
		cout << "查询到学生信息为：\n";
		p->Next->stuDisplay();
		cout << "确认修改吗？(y\\n)\n";
		char ch;
		cin >> ch;
		if ( ch == 'y' || ch == 'Y')
		{
			p->Next->stuInfoInput();
			saveList();
			cout << "信息修改成功！按任意键继续...";
		}
		else cout << "信息未修改，按任意键继续...";
	}
	else cout << "未查询到信息，按任意键继续...";
	cin.get();cin.get();
}

void stuInfo::deleteStu()		//删除信息
{
	string str;
	student *p = NULL, *temp = NULL;
	cout << "\t\t请输入要删除信息的学生的姓名或学号：";
	cin >> str;
	if ( p = match( str ) )
	{
		cout << "查询到学生信息为：\n";
		p->Next->stuDisplay();
		cout << "确认删除吗？(y\\n)\n";
		char ch;
		cin >> ch;
		if ( ch == 'y' || ch == 'Y')
		{
			temp = p->Next;
			p->Next = p->Next->Next;
			delete temp;
			saveList();
			cout << "信息删除成功！按任意键继续...";
		}
		else cout << "信息未删除，按任意键继续...";
	}
	else cout << "未查询到信息，按任意键继续...";
	cin.get();cin.get();
}

int stuInfo::countList()
{
//统计当前链表记录总数，返回一个整数
	if ( !Head ) return 0;
	int n=0;
	for ( student *p = Head->Next; p != End; p = p->Next ) 
		n++;
	return n;
}

void stuInfo::swap(student *p1, student *p2) //swapStu()的子函数
	{
		p1->Name = p2->Name;
		p1->stuNumber = p2->stuNumber;
		p1->GPA = p2->GPA;
		p1->gender = p2->gender;
		p1->totalScore = p2->totalScore;
		for ( int i = 0; i < NUM; i++ )
			p1->Score[i] = p2->Score[i];
	}
void stuInfo::swapStu(student *p_1,student *p_2)	//sortList()的子函数
{
//交换两个student对象的数据域
	student *temp = new student;
	swap( temp, p_1 );
	swap( p_1, p_2 );
	swap( p_2, temp );
	delete temp;
}

//排序
void stuInfo::sortList()
{
	student *p = NULL,*p1 = NULL,*k = NULL;
	int n = countList();
	if ( n < 2 ) 
	{
		cout << "只有一项数据！按任意键继续...";
		cin.get();cin.get();
		return;
	}
	else
	{
		cout << "\t\t1. 按学分绩排序\n\t\t2. 按总分排序\n\t\t3. 选择课程分数排序\n";
		cout << "\t\t输入序号选择排序方式：";
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			{
				for ( p = Head->Next; p != End; p = p->Next )
				for ( k = p->Next; k != End; k = k->Next )
					if ( p->GPA < k->GPA ) swapStu(p,k);
				saveList();
				cout << "按学分绩排序完成！"<<endl;
			}break;
		case 2:
			{
				for ( p = Head->Next; p != End; p = p->Next )
				for ( k = p->Next; k != End; k = k->Next )
					if ( p->totalScore < k->totalScore ) swapStu(p,k);
				saveList();
				cout << "按总分排序完成！"<<endl;
			}break;
		case 3:
			{
				int x = 0;
				cout << "\t\t#序号#\t" << setw(15) << "#课程#"
					 << setiosflags(ios_base::left) << "#学分#" <<endl;
				for (int i = 0; i < Head->getTotal(); i++)
					cout << "\t\t" << i+1 << "\t" << setw(15)<< Head->getCourseName(i) 
						 << setiosflags(ios_base::left)<< Head->getCredit(i) << endl;
				cout << "请输入排序课程名前序号：";
				cin >> x;
				x--;
				for ( p = Head->Next; p != End; p = p->Next )
				for ( k = p->Next; k != End; k = k->Next )
					if ( p->Score[x] < k->Score[x] ) swapStu( p, k );
				saveList();
				cout << "按总分排序完成！"<<endl;
			}break;
		default: return;
		}
		cout << "显示排序后全部成绩信息？(y\\n)"<<endl;
		char c;
		cin >> c;
		if ( c == 'y' || c == 'Y' ) Display();
		else return;
	}
}

void stuInfo::saveList()	//保存所有信息
{
	stuInfoOut.open("stuInfo.txt");
	for ( student *p = Head->Next; p != End; p = p-> Next )
	{	
		stuInfoOut << p->Name << "\t" << p->stuNumber << "\t"
				   << p->gender << "\t" << p->GPA << "\t";
		for ( int i = 0; i < p->getTotal(); i++)
			stuInfoOut << p->Score[i] << "\t";
		stuInfoOut << p->totalScore << endl;
	}
	stuInfoOut.close();
}

void stuInfo::Display()		//显示所有信息
{
	int i = 0;
	cout << "当前学生总数为：" << countList() << endl;
	for ( student *p = Head->Next; p != End; p = p->Next )
	{
		i++;
		cout<< "\t" << i << ".\n";
		p->stuDisplay();
	}
	cout << "全部信息显示完毕，按任意键继续...";
	cin.get();cin.get();
}
void stuInfo::deleteAll()		//删除所有信息
{
	cout << "数据删除不可恢复，请对文件stuInfo.txt进行备份。"
		 << "\n确定删除全部信息吗？(y\\n)\n";
	char c;
	cin >> c;
	if ( c == 'y' || c == 'Y')
	{
		ofstream out;
		out.open("stuInfo.txt");
		out << '\0';
		out.close();
		cout << "信息删除完毕！按任意键继续...";
		cin.get();cin.get();
	}
	else return;
}

void stuInfo::Unpass()		//查询挂科信息
{
	int unpass[NUM] = { 0 };
	for ( student *p = Head->Next; p != End; p = p->Next )
		for ( int i = 0; i < Head->getTotal(); i ++ )
			if ( p->Score[i] < 60 ) unpass[i] ++;
	cout << "当前学生总数为：" << countList() << endl;
	cout << setiosflags(ios_base::left)
		<< setw(20) << "\t\t#课程#" << "#挂科人数#" << "\n";
	for ( int i = 0; i < Head->getTotal(); i ++ )
		cout << setiosflags(ios_base::left)
		  << "\t\t" << setw(20)<<  Head->getCourseName(i) << unpass[i] << "\n";
	cout << "按任意键继续...";
	cin.get();cin.get();
}
void stuInfo::Average()		//查询平均分信息
{
	double average[NUM] = { 0 };
	for ( student *p = Head->Next; p != End; p = p->Next )
		for ( int i = 0; i < Head->getTotal(); i ++ )
			average[i] += p->Score[i];
	for ( int i = 0; i < Head->getTotal(); i ++ )
		average[i] /= double( countList() );
	cout << setiosflags(ios_base::left)
		<< setw(20) << "\t\t#课程#" << "#平均分#" << "\n";
	for ( int i = 0; i < Head->getTotal(); i ++ )
		cout << setiosflags(ios_base::left)
		<< "\t\t" << setw(20)<<  Head->getCourseName(i) << average[i] << "\n";
	cout << "按任意键继续...";
	cin.get();cin.get();
}
#endif	//_STUINFO_H