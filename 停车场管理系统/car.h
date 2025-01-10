#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<time.h>
using namespace std;
#define Max_Size 5
#define refresh true
#define append false

//����
class car
{
public:
	car() {};
	car(const string carn)
		:carnumber(carn)
	{
		parktime();
	}
	car(const string carn, int Arrivehour, int Arrivemin )
		:carnumber(carn), arrivehour(Arrivehour), arrivemin(Arrivemin)
	{
		arrive_min_sum = arrivehour * 60 + arrivemin;
	};

	string getNumber() { return carnumber; }
	int getArrivehour()	{ return arrivehour; }
	int getArriveMin() { return arrivemin; }
	int getDepartHour() { return departhour; }
	int getDepartMin() { return departmin; }
	double getAmount() { return amount; }
	
	void parktime()   //��ȡ�ַ����е�Сʱ���Ӽ�����
	{
		time_t atime;
		struct tm p;


		time(&atime);
		localtime_s(&p, &atime);

		arrivehour = p.tm_hour;
		arrivemin = p.tm_min;
		arrive_min_sum = arrivehour * 60 + arrivemin;

	}

	//�����뿪ʱ��
	void departtime()
	{
		time_t dtime;
		struct tm p;

		time(&dtime);
		localtime_s(&p, &dtime);

		departhour = p.tm_hour;
		departmin = p.tm_min;
		depart_min_sum = departhour * 60 + departmin;
		//depart_min_sum = p.tm_hour * 60 + p.tm_min;
	}
	void calculateAmount()   //��ȡ�ַ����е�Сʱ���Ӽ�����
	{
		
		
		parkingtime = (depart_min_sum - arrive_min_sum) / 60.0;
		amount = parkingtime * 10.0;
	}
	
	
private:
	string carnumber; //���ƺ�
	int arrivehour=0; //����ʱ��
	int arrivemin=0;
	int departhour=0; //�뿪ʱ��
	int departmin=0;
	double arrive_min_sum=0;
	double depart_min_sum=0;
	double parkingtime=0; //ͣ��ʱ��
	double amount=0; //�ܽ��
};

//ͣ�����ṹ
typedef struct
{
	car* parkinglot[Max_Size];
	int length;
}parkinglot;

//����ṹ
typedef struct
{
	car* sideway[Max_Size];
	int front, rear;
}sideway;

typedef struct
{
	car* stack[Max_Size];
	int top;
}temstack;

//����Ա��
class Manager
{
private:
	
	parkinglot* p;
	sideway* s;
	temstack* t;

public:
	Manager()
	{
		initparkinglot();
		initsideway();
		loadfile();
	}

	//��ʼ��˳���ͣ����
	void initparkinglot()
	{
		p = new parkinglot;
		p->length = 0;

		for (int i = 0; i < Max_Size; i++)
			p->parkinglot[i] = nullptr;
	}

	//��ʼ�����б��
	void initsideway()
	{
		s = new sideway;
		for (int i = 0; i < Max_Size; i++)
			s->sideway[i] = nullptr;
		s->front = s->rear = 0;
	}

	//��ʼ��ջ���ڴ�ű������
	void initstack()
	{
		t = new temstack;
		for (int i = 0; i < Max_Size; i++)
			t->stack[i] = nullptr;
		t->top = -1;
	}

	//ͣ������غ���
	void arrive();
	void depart();
	void sqfindcar(parkinglot* p, string carname);
	void parkinginfo();

	//�����غ���
	bool issidewayempty();
	void ensideway(car* c);
	car* desideway();
	void showsidewayinfo();
	bool isstackempty();
	void push(car* c);
	bool pop(car*& c);
	void departsideway();

	//�ļ���غ���
    void savecarinfo(bool mode);
	void savecarlog(int i);
	void loadfile();
 };

void drawmenu();