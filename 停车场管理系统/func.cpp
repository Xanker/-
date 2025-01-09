#include"car.h"


void draw()
{
	cout << "***********************************\n";
	cout << "**         停车场管理系统        **\n";
	cout << "***********************************\n";
	cout << "**       请选择您需要的操作      **\n";
	cout << "*        1.查看停车场车辆情况     *\n";
	cout << "*        2.进入停车场            *\n";
	cout << "*        3.离开停车场            *\n";
	cout << "*        0.退出停车场系统         *\n";
	cout << "***********************************\n";
}

void DisplayCar(parkinglot s, sideway p)
{
	if (s.length != 0)
	{
		for (int i = 0; i < s.length; i++)
		{
			cout << "第"<< i+1 <<"辆车:"  << endl;
			cout << "车牌号:" << s.parkinglot[i]->getNumber()<<endl;
			cout << "进入时间:" << s.parkinglot[i]->getAtime() << ":" << s.parkinglot[i]->getAtime1()<<endl;
			if (s.parkinglot[i]->getDtime() != 24)
			{
				cout << "离开时间:" << s.parkinglot[i]->getDtime() << ":" << s.parkinglot[i]->getDtime1();
				cout << "费用:" << s.parkinglot[i]->getAmount() << endl;
			}
		 }
	}
	
}
