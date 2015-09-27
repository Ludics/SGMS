
//main.cpp		������
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
	cout << "\t<�����������>\n\t";  
	cin.get();  
	//	system( "cls" );    //����
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
	cout << "\t\t           ��ӭʹ��ѧ���ɼ�����ϵͳ\n";  
	cout << "\t\t\t*******************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\n\t\t\t��ɽ��·��Ϊ��\n";  
	cout << "\t\t\t\t       ѧ�����Ŀ�����\n\n";  
	cout << "\t_______________________________"
		 << "_______________________________\n";  
	cout << "\t��Ȩ����\tversion: 1.0\n\t\t\t\t\t\t\t\tLudics\n\n\n";   
}
void Dis_Menu()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      ѧ���ɼ�����ϵͳ\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;  
	cout << "\t\t#���˵�#\n";
	cout << "\t\t\t       1.�ɼ���Ϣ����"<<endl;
	cout << "\t\t\t       2.�ɼ���Ϣ����"<<endl;
	cout << "\t\t\t       3.�γ���Ϣ����"<<endl;
	cout << "\t\t\t       0.��ȫ�˳�ϵͳ"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t��ѡ��";
}

void Dis_StuInfoMng()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      ѧ���ɼ�����ϵͳ\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\t\t#�ɼ���Ϣ����#\n";
	cout << "\t\t\t       1.���ѧ����Ϣ"<<endl;
	cout << "\t\t\t       2.ɾ��ѧ����Ϣ"<<endl;
	cout << "\t\t\t       3.�޸�ѧ����Ϣ"<<endl;
	cout << "\t\t\t       4.ɾ��������Ϣ"<<endl;
	cout << "\t\t\t       0.�������˵�"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t��ѡ��";
}

void Dis_StuInfoHandle()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      ѧ���ɼ�����ϵͳ\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\t\t#�ɼ���Ϣ����#\n";
	cout << "\t\t\t       1.����ѧ����Ϣ"<<endl;
	cout << "\t\t\t       2.����ͳ����Ϣ"<<endl;
	cout << "\t\t\t       3.��ʾȫ����Ϣ"<<endl;
	cout << "\t\t\t       4.��ѯ�ҿ���Ϣ"<<endl;
	cout << "\t\t\t       5.��ѯƽ����"<<endl;
	cout << "\t\t\t       0.�������˵�"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t��ѡ��";
}

void Dis_CourseInfoMng()
{
	cout << "\n\n\n\t\t\t*****************************\n";  
	cout << "\t\t\t      ѧ���ɼ�����ϵͳ\n";  
	cout << "\t\t\t*****************************\n\n\n";  
	for ( int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;   
	cout << "\t\t#�γ���Ϣ����#\n";
	cout << "\t\t\t       1.����γ���Ϣ"<<endl;
	cout << "\t\t\t       2.��ʾ�γ���Ϣ"<<endl;
	cout << "\t\t\t       0.�������˵�"<<endl;
	cout << "\t_______________________________"
		 << "_______________________________\n"; 
	cout << "\n\t\t\n\t\t��ѡ��";
}
