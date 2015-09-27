//stuInfo.h		stuInfo��Ķ��弰ʵ��
#ifndef _STUINFO_H
#define _STUINFO_H
#include"class.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

//������stuInfo
class stuInfo:
	public base
{
private:
	student *Head, *End;	//��ͷ����βָ��
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

//���캯������ȡ�ļ�stuInfo.txt�е���Ϣ
stuInfo::stuInfo()
{
	Head = new student;
	Head->Next = new student;
	End = Head->Next;
	stuInfoIn.open("stuInfo.txt");
	if ( !stuInfoIn )
		cout << "δ����ѧ����Ϣ����������..." << endl;
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
		cout << "\t\t��ȡѧ����Ϣ�ɹ�!" << endl;
	}
}

stuInfo::~stuInfo()		//��������
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

void stuInfo::addStu()		//������β�����Ϣ
{
	int total;
	cout << "���������������\t";
	cin >> total;
	for ( int i = 0; i < total; i++)
	{	
		cout << "������� " << i+1 << " ��ͬѧ����Ϣ��\n";
		End->stuInfoInput();
		End->Next = new student;
		End = End->Next;
	}
	saveList();
	cout << "\t\tѧ����Ϣ�����ϣ������������...";
	cin.get();cin.get();
}

student* stuInfo::match(string str)
{
//ƥ��ɹ��򷵻��ϸ�����ָ�룬���ɹ��ͷ��ؿ�
	for ( student *p = Head; p->Next != End; p = p->Next )
		if ( p->Next->Name == str || p->Next->stuNumber == str ) 
			return p;
	return NULL;
}

void stuInfo::seekStu()		//��ѯ��Ϣ
{
	string str;
	student* p = NULL;
	cout << "\t\t������Ҫ���ҵ�ѧ����������ѧ�ţ�";
	cin >> str;
	if ( p = match( str ) )	
	{
		cout << "��ѯ��ѧ����ϢΪ��\n";
		p->Next->stuDisplay();
		cout << "��ѯ��ϣ������������...";
	}
	else cout << "δ��ѯ����Ϣ�������������...";
	cin.get();cin.get();
}

void stuInfo::modifyStu()		//�޸���Ϣ
{
	string str;
	student* p = NULL;
	cout << "\t\t������Ҫ�޸���Ϣ��ѧ����������ѧ�ţ�";
	cin >> str;
	if ( p = match( str ) )
	{
		cout << "��ѯ��ѧ����ϢΪ��\n";
		p->Next->stuDisplay();
		cout << "ȷ���޸���(y\\n)\n";
		char ch;
		cin >> ch;
		if ( ch == 'y' || ch == 'Y')
		{
			p->Next->stuInfoInput();
			saveList();
			cout << "��Ϣ�޸ĳɹ��������������...";
		}
		else cout << "��Ϣδ�޸ģ������������...";
	}
	else cout << "δ��ѯ����Ϣ�������������...";
	cin.get();cin.get();
}

void stuInfo::deleteStu()		//ɾ����Ϣ
{
	string str;
	student *p = NULL, *temp = NULL;
	cout << "\t\t������Ҫɾ����Ϣ��ѧ����������ѧ�ţ�";
	cin >> str;
	if ( p = match( str ) )
	{
		cout << "��ѯ��ѧ����ϢΪ��\n";
		p->Next->stuDisplay();
		cout << "ȷ��ɾ����(y\\n)\n";
		char ch;
		cin >> ch;
		if ( ch == 'y' || ch == 'Y')
		{
			temp = p->Next;
			p->Next = p->Next->Next;
			delete temp;
			saveList();
			cout << "��Ϣɾ���ɹ��������������...";
		}
		else cout << "��Ϣδɾ���������������...";
	}
	else cout << "δ��ѯ����Ϣ�������������...";
	cin.get();cin.get();
}

int stuInfo::countList()
{
//ͳ�Ƶ�ǰ�����¼����������һ������
	if ( !Head ) return 0;
	int n=0;
	for ( student *p = Head->Next; p != End; p = p->Next ) 
		n++;
	return n;
}

void stuInfo::swap(student *p1, student *p2) //swapStu()���Ӻ���
	{
		p1->Name = p2->Name;
		p1->stuNumber = p2->stuNumber;
		p1->GPA = p2->GPA;
		p1->gender = p2->gender;
		p1->totalScore = p2->totalScore;
		for ( int i = 0; i < NUM; i++ )
			p1->Score[i] = p2->Score[i];
	}
void stuInfo::swapStu(student *p_1,student *p_2)	//sortList()���Ӻ���
{
//��������student�����������
	student *temp = new student;
	swap( temp, p_1 );
	swap( p_1, p_2 );
	swap( p_2, temp );
	delete temp;
}

//����
void stuInfo::sortList()
{
	student *p = NULL,*p1 = NULL,*k = NULL;
	int n = countList();
	if ( n < 2 ) 
	{
		cout << "ֻ��һ�����ݣ������������...";
		cin.get();cin.get();
		return;
	}
	else
	{
		cout << "\t\t1. ��ѧ�ּ�����\n\t\t2. ���ܷ�����\n\t\t3. ѡ��γ̷�������\n";
		cout << "\t\t�������ѡ������ʽ��";
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
				cout << "��ѧ�ּ�������ɣ�"<<endl;
			}break;
		case 2:
			{
				for ( p = Head->Next; p != End; p = p->Next )
				for ( k = p->Next; k != End; k = k->Next )
					if ( p->totalScore < k->totalScore ) swapStu(p,k);
				saveList();
				cout << "���ܷ�������ɣ�"<<endl;
			}break;
		case 3:
			{
				int x = 0;
				cout << "\t\t#���#\t" << setw(15) << "#�γ�#"
					 << setiosflags(ios_base::left) << "#ѧ��#" <<endl;
				for (int i = 0; i < Head->getTotal(); i++)
					cout << "\t\t" << i+1 << "\t" << setw(15)<< Head->getCourseName(i) 
						 << setiosflags(ios_base::left)<< Head->getCredit(i) << endl;
				cout << "����������γ���ǰ��ţ�";
				cin >> x;
				x--;
				for ( p = Head->Next; p != End; p = p->Next )
				for ( k = p->Next; k != End; k = k->Next )
					if ( p->Score[x] < k->Score[x] ) swapStu( p, k );
				saveList();
				cout << "���ܷ�������ɣ�"<<endl;
			}break;
		default: return;
		}
		cout << "��ʾ�����ȫ���ɼ���Ϣ��(y\\n)"<<endl;
		char c;
		cin >> c;
		if ( c == 'y' || c == 'Y' ) Display();
		else return;
	}
}

void stuInfo::saveList()	//����������Ϣ
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

void stuInfo::Display()		//��ʾ������Ϣ
{
	int i = 0;
	cout << "��ǰѧ������Ϊ��" << countList() << endl;
	for ( student *p = Head->Next; p != End; p = p->Next )
	{
		i++;
		cout<< "\t" << i << ".\n";
		p->stuDisplay();
	}
	cout << "ȫ����Ϣ��ʾ��ϣ������������...";
	cin.get();cin.get();
}
void stuInfo::deleteAll()		//ɾ��������Ϣ
{
	cout << "����ɾ�����ɻָ�������ļ�stuInfo.txt���б��ݡ�"
		 << "\nȷ��ɾ��ȫ����Ϣ��(y\\n)\n";
	char c;
	cin >> c;
	if ( c == 'y' || c == 'Y')
	{
		ofstream out;
		out.open("stuInfo.txt");
		out << '\0';
		out.close();
		cout << "��Ϣɾ����ϣ������������...";
		cin.get();cin.get();
	}
	else return;
}

void stuInfo::Unpass()		//��ѯ�ҿ���Ϣ
{
	int unpass[NUM] = { 0 };
	for ( student *p = Head->Next; p != End; p = p->Next )
		for ( int i = 0; i < Head->getTotal(); i ++ )
			if ( p->Score[i] < 60 ) unpass[i] ++;
	cout << "��ǰѧ������Ϊ��" << countList() << endl;
	cout << setiosflags(ios_base::left)
		<< setw(20) << "\t\t#�γ�#" << "#�ҿ�����#" << "\n";
	for ( int i = 0; i < Head->getTotal(); i ++ )
		cout << setiosflags(ios_base::left)
		  << "\t\t" << setw(20)<<  Head->getCourseName(i) << unpass[i] << "\n";
	cout << "�����������...";
	cin.get();cin.get();
}
void stuInfo::Average()		//��ѯƽ������Ϣ
{
	double average[NUM] = { 0 };
	for ( student *p = Head->Next; p != End; p = p->Next )
		for ( int i = 0; i < Head->getTotal(); i ++ )
			average[i] += p->Score[i];
	for ( int i = 0; i < Head->getTotal(); i ++ )
		average[i] /= double( countList() );
	cout << setiosflags(ios_base::left)
		<< setw(20) << "\t\t#�γ�#" << "#ƽ����#" << "\n";
	for ( int i = 0; i < Head->getTotal(); i ++ )
		cout << setiosflags(ios_base::left)
		<< "\t\t" << setw(20)<<  Head->getCourseName(i) << average[i] << "\n";
	cout << "�����������...";
	cin.get();cin.get();
}
#endif	//_STUINFO_H