#include"car.h"

void add(parkinglot *p, sideway *s)
{
	
	char carnum[10];
	cout << "�����복�ƺ�:" << endl;
	cin >> carnum;
	arrive(p, s, carnum);
}
void leave(parkinglot* p, sideway* s)
{
	int n = 0;
	int j = 0;
	string num;
	cout << "��ͣ���ģ�" << endl;
	cout << "1��ͣ���� 2����� 0,����" << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "��������ĳ��ƺ�:" << endl;
		cin >> num;
		for (int i = 0; i < p->length; i++) {
			if (num == p->parkinglot[i]->getNumber())
			{
				p->parkinglot[i]->Getdeparttime();
				p->parkinglot[i]->sumAmout();
				cout << num << "��λ��λ��" << i << "��\n";
				cout << "�뿪ʱ��Ϊ" << p->parkinglot[i]->getDtime() << ":" << p->parkinglot[i]->getDtime1();
				cout << "����Ϊ" << p->parkinglot[i]->getAmount();
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
		cout << "��������ţ�";
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
		default:cout << "����������������룡\n";
		}
	} while (input!='0');
	//cin.get();
	

    //savecarinfo(p);
}