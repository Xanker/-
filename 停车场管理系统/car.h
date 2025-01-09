#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<time.h>
using namespace std;


#define Max_Size 3

class car
{
public:
	car() {};
	car(string carnumber1):carnumber(carnumber1)
	{
		parktime();
	}
	string getNumber() { return carnumber; }
	int getAtime()	{ return arrivehour; }
	int getAtime1() { return arrivemin; }
	
	int getDtime() { return departhour; }
	int getDtime1() { return departmin; }
	double getAmount() { return amount; }
	
	void parktime()   //提取字符串中的小时分钟计算金额
	{
		//int arrivehour, departhour, arrivemin, departmin;
		//version 1
		
		//stringstream dtimestream(departtime);

		
		//dtimestream >> departhour >> ch >> departmin;
		//version 2
		time_t atime;
		struct tm p;
		

		time(&atime);
		localtime_s(&p, &atime);
		//atimestream >> p->tm_hour >> ch >> p->tm_min;
		arrivehour = p.tm_hour;
		arrivemin = p.tm_min;
		arrive_min_sum = p.tm_hour * 60 + p.tm_min;
		//double depart_min_sum = departhour * 60 + departmin;
		//parkingtime = (depart_min_sum - arrive_min_sum) / 60.0;
		//amount = parkingtime * 10.0;
	}
	void Getdeparttime()
	{
        
		
		time_t dime;
		struct tm q;
		time(&dime);
		localtime_s(&q, &dime);
		
		departhour = q.tm_hour;
		departmin = q.tm_min;

		depart_min_sum = q.tm_hour * 60 + q.tm_min;
	}
	void sumAmout()
		//计算总金额
	{
		
		parkingtime = (depart_min_sum - arrive_min_sum) / 60.0;
		amount = parkingtime * 10.0;
	}
	

private:
	string carnumber; //车牌号
	int arrivehour; //便于输出到达时间
	int arrivemin; 
	int departhour = 24; //便于输出离开时间
	int departmin;
	double arrive_min_sum;//便于计算的到达时间
	double depart_min_sum;//便于计算的离开时间visu
	double parkingtime; //停车时间
	double amount; //总金额
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


//停车场相关函数
void initparkinglot(parkinglot*& p);
void arrive(parkinglot* p, sideway* s, const char* carnumber);
void depart(parkinglot* p, int pos);
void sqfindcar(parkinglot* p, string carname);
void savecarinfo(parkinglot* p);

//便道相关函数
void initsideway(sideway*& s);
void ensideway(sideway* s, car* c);
car* desideway(sideway* s);

void draw();
void DisplayCar(parkinglot s, sideway p);