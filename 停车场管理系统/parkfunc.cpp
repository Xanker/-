#include"car.h"

//��ʼ��ͣ��������ָ����null
void initparkinglot(parkinglot*& p)
{
	p = new parkinglot;
	p->length = 0;

	for (int i = 0; i < Max_Size; i++)
		p->parkinglot[i] = nullptr;
}

void arrive(parkinglot* p, sideway* s, const char* carnumber)
{
	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(s, tem);
		cout << "����:" << carnumber << "�ѽ�������\n";
		return;
	}

	p->parkinglot[p->length] = new car(carnumber);
	p->length++;
	cout << "����:" << carnumber << "�ѽ���ͣ������\n";
}

void depart(parkinglot* p, int pos)
{
	if (pos < 1 || pos > p->length) {
		cout << "��Ч��λ��: " << pos << "�޷��Ƴ�������";
		return;
	}
	
	car* q = p->parkinglot[pos - 1];
	cout << q->getNumber() << "���뿪ͣ����\n";
	for (int i = pos - 1; i < p->length - 1; i++) {
		p->parkinglot[i] = p->parkinglot[i + 1];
	}

	delete q;
	p->length--;
	p->parkinglot[p->length] = nullptr;
}

void sqfindcar(parkinglot* p, string carname)
{
	for (int i = 0; i < p->length; i++) {
		if (carname == p->parkinglot[i]->getNumber())
			cout << carname << "��λ��λ��" << i << "��\n";
	}
}

void savecarinfo(parkinglot* p) {
	ofstream file("parkinglot.csv");

	if (file.is_open()) {
		file << "���ƺ�,����ʱ��,�뿪ʱ��,��֧�����\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;
			file << p->parkinglot[i]->getNumber() << "," << p->parkinglot[i]->getAtime()
				<< "," << p->parkinglot[i]->getDtime() << "," << p->parkinglot[i]->getAmount()<<"\n";
		}
		file.close();
	}
	else {
		cerr << "�޷����ļ�!" << endl;
	}
}

void loadfile()
{

}