#include"car.h"

void add(parkinglot *p, sideway *s)
{
	
	char carnum[10];
	cout << "请输入车牌号:" << endl;
	cin >> carnum;
	arrive(p, s, carnum);
}
void leave(parkinglot* p, sideway* s)
{
	int n = 0;
	int j = 0;
	string num;
	cout << "车停在哪？" << endl;
	cout << "1，停车场 2，便道 0,返回" << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "请输入你的车牌号:" << endl;
		cin >> num;
		for (int i = 0; i < p->length; i++) {
			if (num == p->parkinglot[i]->getNumber())
			{
				p->parkinglot[i]->Getdeparttime();
				p->parkinglot[i]->sumAmout();
				cout << num << "的位置位于" << i << "号\n";
				cout << "离开时间为" << p->parkinglot[i]->getDtime() << ":" << p->parkinglot[i]->getDtime1();
				cout << "费用为" << p->parkinglot[i]->getAmount();
			}
		}
	}
}
int main()
{
	parkinglot *p;
	sideway* s;
	initparkinglot(p);
	initsideway(s);
	char input = 1;
	do {
		draw();
		cout << "请输入序号：";
		cin >> input;
		switch (input)
		{
		case '1': 
			DisplayCar(*p,*s);
			break;
		case '2': 
			add(p,s);
			break;
		case '3': 
			leave(p, s);
			break;
		case '4': break;
		default:cout << "输入错误，请重新输入！\n";
		}
	} while (input!='0');
	//cin.get();
	

    //savecarinfo(p);
}