#include"car.h"


void draw()
{
	cout << "***********************************\n";
	cout << "**         ͣ��������ϵͳ        **\n";
	cout << "***********************************\n";
	cout << "**       ��ѡ������Ҫ�Ĳ���      **\n";
	cout << "*        1.�鿴ͣ�����������     *\n";
	cout << "*        2.����ͣ����            *\n";
	cout << "*        3.�뿪ͣ����            *\n";
	cout << "*        0.�˳�ͣ����ϵͳ         *\n";
	cout << "***********************************\n";
}

void DisplayCar(parkinglot s, sideway p)
{
	if (s.length != 0)
	{
		for (int i = 0; i < s.length; i++)
		{
			cout << "��"<< i+1 <<"����:"  << endl;
			cout << "���ƺ�:" << s.parkinglot[i]->getNumber()<<endl;
			cout << "����ʱ��:" << s.parkinglot[i]->getAtime() << ":" << s.parkinglot[i]->getAtime1()<<endl;
			if (s.parkinglot[i]->getDtime() != 24)
			{
				cout << "�뿪ʱ��:" << s.parkinglot[i]->getDtime() << ":" << s.parkinglot[i]->getDtime1();
				cout << "����:" << s.parkinglot[i]->getAmount() << endl;
			}
		 }
	}
	
}
