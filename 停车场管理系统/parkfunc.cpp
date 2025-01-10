#include"car.h"

void Manager::arrive()
{
	string carnumber, atime;
	cout << "�����������ĳ��ƺ�";
	cin >> carnumber;

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(tem);
		return;
	}

	p->parkinglot[p->length] = new car(carnumber);
	p->length++;
	cout << "����:" << carnumber << "�ѽ���ͣ������\n";

	savecarinfo(append);
}

void Manager::depart()
{
	int pos;
	parkinginfo();
	cout << "��������뿪�����ĳ�λ�ţ�";
	cin >> pos;

	if (pos < 1 || pos > p->length) 
	{
		cout << pos << "�ų�λ��û�г�����";
		return;
	}
	p->parkinglot[pos - 1]->departtime();
	p->parkinglot[pos - 1]->calculateAmount();
	cout << "�뿪ʱ��Ϊ" << p->parkinglot[pos-1]->getDepartHour() << ":" << p->parkinglot[pos-1]->getDepartMin();
	cout << "����Ϊ" << p->parkinglot[pos-1]->getAmount();
	savecarlog(pos);
	car* q = p->parkinglot[pos - 1];
	cout << q->getNumber() << "���뿪ͣ����\n";
	delete q;

	for (int i = pos - 1; i < p->length - 1; i++) {
		p->parkinglot[i] = p->parkinglot[i + 1];
	}
	p->parkinglot[p->length - 1] = nullptr;
	p->length--;
	if (!issidewayempty())
	{
		car* temcar = desideway();
		p->parkinglot[p->length] = temcar;
		p->length++;

		cout << "ͣ�����п�λ������е�" << temcar->getNumber()
			<< "�ѽ���ͣ������" << endl;
	}
}

void Manager::sqfindcar(parkinglot* p, string carname)
{
	for (int i = 0; i < p->length; i++) {
		if (carname == p->parkinglot[i]->getNumber())
			cout << carname << "��λ��λ��" << i << "��\n";
	}
}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv");

	if (file.is_open()) {
		file << "���ƺ�,����ʱ��\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;
			file << p->parkinglot[i]->getNumber() << "," << p->parkinglot[i]->getArrivehour()
				<< ":" << p->parkinglot[i]->getArriveMin() << "\n";
		}
		file.close();
	}
	else {
		cerr << "�޷����ļ�!" << endl;
	}
}

void Manager::loadfile()
{
	ifstream file("parkinglot.csv");
	string line;
	getline(file, line);
	while (getline(file, line))
	{
		stringstream ss(line);
		string carnumber;
		int arrivehour, arriveminute;
		char delimiter;
		int i;

		if (getline(ss, carnumber, ',') && ss >> arrivehour >> delimiter >> arriveminute)
		{
			car* tem = new car(carnumber, arrivehour, arriveminute);
			
			p->parkinglot[p->length] = tem;
			p->length++;
		}
	}
	file.close();
}

void Manager::savecarlog(int i)
{
	ofstream file("parkinglog.csv", std::ios::app);

	if (file.is_open()) {
		file << "���ƺ�,����ʱ��,�뿪ʱ��,��֧�����\n";
		
			file << p->parkinglot[i-1]->getNumber() << "," << p->parkinglot[i-1]->getArrivehour() << ":" << p->parkinglot[i-1]->getArriveMin()
				<< "," << p->parkinglot[i-1]->getDepartHour() << ":" << p->parkinglot[i-1]->getDepartMin() << "," << p->parkinglot[i-1]->getAmount() << "\n";
		
		file.close();
	}
	else {
		cerr << "�޷����ļ�!" << endl;
	}
}