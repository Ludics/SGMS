
//main.cpp		主函数
#include"class.h"
#include"stuInfo.h"
#include<iostream>
#include<iomanip>
using namespace std;

void Dis_Index();
void Dis_Menu();
void Dis_StuInfoMng();
void Dis_StuInfoHandle();
void Dis_CourseInfoMng();
int main()
{
	int order;
	bool quit = false;
	Dis_Index();
	course myCourse;
	stuInfo myStu;
	base *ptrBase[] = { &myCourse, &myStu };
	cout << "\t<按任意键进入>\n\t";  
	cin.get();  
	//	system( "cls" );    //清屏
	while ( !quit )
	{
	  //	system( "cls" );  
		Dis_Menu();
		cin >> order;
		switch ( order )
		{
		case 0: quit = true; break;
		case 1: 
			{
			  //	system( "cls" );  
				Dis_StuInfoMng(); 
				cin >> order;
				switch ( order )
				{
				case 0: continue;
				case 1: myStu.addStu(); break;
				case 2: myStu.deleteStu(); break;
				case 3: myStu.modifyStu(); break;
				case 4: myStu.deleteAll(); break;
				}
			}break;
		case 2:			
			{
			  //	system( "cls" );  
				Dis_StuInfoHandle(); 
				cin >> order;
				switch ( order )
				{
				case 0: continue;
				case 1: myStu.seekStu(); break;
				case 2: myStu.sortList(); break;
				case 3: {
				  //		system( "cls");
					ptrBase[1]->Display();
					}break;
				case 4: myStu.Unpass(); break;
				case 5: myStu.Average(); break;
				}
			}break;
		case 3: 			
			{
			  //	system( "cls" );  
				Dis_CourseInfoMng(); 
				cin >> order;
				switch ( order )
				{
				case 0: continue;
				case 1: myCourse.setCourse(); break;
				case 2: ptrBase[0]->Display(); break;
				}
			}break;
		default: continue;
		}
	}
	return 0;
}

void Dis_Index()
{
	cout << "\n\n\n\t\t\t*******************************\n";  
	cout << "\t\t           欢迎使用学生成绩管理系统\n";  
	cout << "\t\t\t*******************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\n\t\t\t书山有路勤为径\n";  
	cout << "\t\t\t\t       学海无涯苦作舟\n\n";  
	cout << "\t_______________________________"
		 << "_______________________________\n";  
	cout << "\t版权所有\tversion: 1.0\n\t\t\t\t\t\t\t\tLudics\n\n\n";   
}
void Dis_Menu()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      学生成绩管理系统\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;  
	cout << "\t\t#主菜单#\n";
	cout << "\t\t\t       1.成绩信息管理"<<endl;
	cout << "\t\t\t       2.成绩信息处理"<<endl;
	cout << "\t\t\t       3.课程信息管理"<<endl;
	cout << "\t\t\t       0.安全退出系统"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t请选择：";
}

void Dis_StuInfoMng()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      学生成绩管理系统\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\t\t#成绩信息管理#\n";
	cout << "\t\t\t       1.添加学生信息"<<endl;
	cout << "\t\t\t       2.删除学生信息"<<endl;
	cout << "\t\t\t       3.修改学生信息"<<endl;
	cout << "\t\t\t       4.删除所有信息"<<endl;
	cout << "\t\t\t       0.返回主菜单"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t请选择：";
}

void Dis_StuInfoHandle()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      学生成绩管理系统\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\t\t#成绩信息处理#\n";
	cout << "\t\t\t       1.查找学生信息"<<endl;
	cout << "\t\t\t       2.排序统计信息"<<endl;
	cout << "\t\t\t       3.显示全部信息"<<endl;
	cout << "\t\t\t       4.查询挂科信息"<<endl;
	cout << "\t\t\t       5.查询平均分"<<endl;
	cout << "\t\t\t       0.返回主菜单"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t请选择：";
}

void Dis_CourseInfoMng()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      学生成绩管理系统\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\t\t#课程信息管理#\n";
	cout << "\t\t\t       1.重设课程信息"<<endl;
	cout << "\t\t\t       2.显示课程信息"<<endl;
	cout << "\t\t\t       0.返回主菜单"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t请选择：";
}
