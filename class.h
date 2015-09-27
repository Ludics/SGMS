//class.h		base�࣬course�࣬student��Ķ�����ʵ��
#ifndef _CLASS_H
#define _CLASS_H
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
const int NUM = 100;

//����base�࣬������
class base
{
public:
	virtual void Display() = 0;		//���麯��
	virtual ~base() {}				//����������
};
//course��
class course:
	public base
{
private:
	int credit[NUM];				//ѧ��
	string courseName[NUM];			//�γ���
	int total;						//�ܿγ���
	ifstream  courseIn;
	ofstream courseOut;
public:
	course();	
	virtual ~course() {}
	void setCourse();							//���ÿγ���Ϣ
	virtual void Display();				//��ʾ�γ���Ϣ
	int getCredit(int i) const			{ return credit[i];		}
	string getCourseName(int i) const	{ return courseName[i];	}
	int getTotal()	const				{ return total;			}
};

//���캯�������û��γ���Ϣ���������������Ĭ�Ͽγ���Ϣ
course::course()						
{	
	for ( int i = 0; i < NUM; i++)
		courseName[i] = '\0', credit[i] = 0;
	courseIn.open( "UsrCourse.txt" ); 
	if ( !courseIn ){
		total = 8;
		courseName[0] = "΢����";
		credit[0] = 5;
		courseName[1] = "���Դ���";
		credit[1] = 4;
		courseName[2] = "��ѧ����";
		credit[2] = 4;
		courseName[3] = "��ɢ��ѧ";
		credit[3] = 3;
		courseName[4] = "�������";
		credit[4] = 2;
		courseName[5] = "���ӵ�·";
		credit[5] = 2;
		courseName[6] = "Ӣ��";
		credit[6] = 2;
		courseName[7] = "����";
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
//�����û��γ���Ϣ���ڴ���
	cout << "\n��ǰ�γ���ϢΪ��\n";
	cout << setiosflags(ios_base::left)
		 << "\n\t\t�γ�����Ϊ��\t" << total << endl;
	cout << "\t\t#���#\t" << setw(15) << "#�γ�#"
		<< setiosflags(ios_base::left) << "#ѧ��#" <<endl;
	for (int i = 0; i < total; i++)
		cout << "\t\t" << i+1 << "\t" << setw(15)<< courseName[i] 
			 << setiosflags(ios_base::left)<< credit[i] << endl;
	cout << "\n�޸Ŀγ���Ϣ��ɾ��ȫ��ѧ���ɼ���Ϣ��������ļ�stuInfo.txt���б��ݡ�\n";
	cout << "ȷ���޸���(y\\n)";
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
		cout << "�������ܿγ�����\t";
		cin >> total;
		cout << "����������γ�������Ӧѧ��:\n";
		for ( int i = 0; i < total; i++)
		{	
			cout << "�� " << i+1 << " �ſεĿγ���Ϊ��";
			cin >> courseName[i];
			cout << "\t     ѧ��Ϊ��";
			cin >> credit[i];
		}
	
	//�����õĿγ���Ϣ���浽�ļ�UsrCourse.txt��
		courseOut.open( "UsrCourse.txt");
		courseOut << total << endl;
		for ( int i = 0; i < total; i++)
		{
			courseOut << courseName[i] << "\t" << credit[i] <<endl;
		}
		cout << "\n\n�γ���������ϣ������������...\n";
		cin.get();cin.get();
	}
	else 
	{
		cout << "�����������...";
		cin.get();cin.get();
	}
}

//��ʾ�γ���Ϣ
void course::Display()
{
	cout << setiosflags(ios_base::left)
		 << "\n\t\t�γ�����Ϊ��\t" << total << endl;
	cout << "\t\t#���#\t" << setw(15) << "#�γ�#" 
		<< setiosflags(ios_base::left) << "#ѧ��#" <<endl;
	for (int i = 0; i < total; i++)
		cout << "\t\t" << i+1 << "\t" << setw(15)<< courseName[i] 
			 << setiosflags(ios_base::left)<< credit[i] << endl;
	cout << "\n\n�����������...";
	cin.get();cin.get();
}

//student��
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
	double Score[NUM];				//����
	double GPA;						//ѧ�ּ�
	double totalScore;				//�ܷ�
};

student::student()
{
	Next = NULL;
	Name = stuNumber = gender = '\0';
	for ( int i = 0; i < NUM; i++) Score[i] = 0;
	GPA = totalScore = 0;
}

//ѧ����Ϣ���뺯����ͨ�����̽�ѧ����Ϣ���뵽�ڴ�
void student::stuInfoInput()
{
	cout << "\t\tѧ��������";
	cin >> Name;
	cout << "\t\tѧ�ţ�";
	cin >> stuNumber;
	cout << "\t\t�Ա�";
	cin >> gender;
	cout << "\t\t��������Ƴɼ���\n";
	totalScore = 0;
	double sumScore = 0,sumCredit = 0;
	for ( int i = 0; i < getTotal(); i++)
	{
		cout << "\t\t" << getCourseName(i) << "��";
		cin >> Score[i];
		totalScore += Score[i];
		sumScore += Score[i] * getCredit(i);
		sumCredit += getCredit(i);
	}
	GPA = sumScore / sumCredit;
	for ( int i = getTotal(); i < NUM; i++) Score[i] = 0;
}

//�ļ���ȡ��������stuIn����Ϣ��ȡ���ڴ�
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
		 << setw(20) << "\t\t  ����" << Name << "\n"
		 << setw(20) << "\t\t  ѧ��" << stuNumber << "\n"
		 << setw(20) << "\t\t  �Ա�" << gender << "\n"
		 << setw(20) << "\t\t  GPA" << GPA << "\n"
		 << setw(20) << "\t\t  �ܷ�" << totalScore << "\n";
	cout << "\t\t--------------------------" << endl;
	for ( int i = 0; i < getTotal(); i++ )
		cout << "\t\t" << i+1 << "\t" << setw(10) << getCourseName(i)
			 << "\t" << setiosflags(ios_base::left)
			 << Score[i] << endl;
	cout << endl;
} 
#endif  //_CLASS_H
