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

//车类
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
	
	void parktime()   //提取字符串中的小时分钟计算金额
	{
		time_t atime;
		struct tm p;


		time(&atime);
		localtime_s(&p, &atime);

		arrivehour = p.tm_hour;
		arrivemin = p.tm_min;
		arrive_min_sum = arrivehour * 60 + arrivemin;

	}

	//计算离开时间
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
	void calculateAmount()   //提取字符串中的小时分钟计算金额
	{
		
		
		parkingtime = (depart_min_sum - arrive_min_sum) / 60.0;
		amount = parkingtime * 10.0;
	}
	
	
private:
	string carnumber; //车牌号
	int arrivehour=0; //到达时间
	int arrivemin=0;
	int departhour=0; //离开时间
	int departmin=0;
	double arrive_min_sum=0;
	double depart_min_sum=0;
	double parkingtime=0; //停车时间
	double amount=0; //总金额
};

//停车场结构
typedef struct
{
	car* parkinglot[Max_Size];
	int length;
}parkinglot;

//便道结构
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

//管理员类
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

	//初始化顺序表停车场
	void initparkinglot()
	{
		p = new parkinglot;
		p->length = 0;

		for (int i = 0; i < Max_Size; i++)
			p->parkinglot[i] = nullptr;
	}

	//初始化队列便道
	void initsideway()
	{
		s = new sideway;
		for (int i = 0; i < Max_Size; i++)
			s->sideway[i] = nullptr;
		s->front = s->rear = 0;
	}

	//初始化栈用于存放便道车辆
	void initstack()
	{
		t = new temstack;
		for (int i = 0; i < Max_Size; i++)
			t->stack[i] = nullptr;
		t->top = -1;
	}

	//停车场相关函数
	void arrive();
	void depart();
	void sqfindcar(parkinglot* p, string carname);
	void parkinginfo();

	//便道相关函数
	bool issidewayempty();
	void ensideway(car* c);
	car* desideway();
	void showsidewayinfo();
	bool isstackempty();
	void push(car* c);
	bool pop(car*& c);
	void departsideway();

	//文件相关函数
    void savecarinfo(bool mode);
	void savecarlog(int i);
	void loadfile();
 };

void drawmenu();