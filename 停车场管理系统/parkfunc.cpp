#include"car.h"

void Manager::arrive()
{
	string carnumber, atime;
	cout << "请输入汽车的车牌号";
	cin >> carnumber;

	if (p->length >= Max_Size) {
		car* tem = new car(carnumber);
		ensideway(tem);
		return;
	}

	p->parkinglot[p->length] = new car(carnumber);
	p->length++;
	cout << "车辆:" << carnumber << "已进入停车场！\n";

	savecarinfo(append);
}

void Manager::depart()
{
	int pos;
	parkinginfo();
	cout << "请输入待离开车辆的车位号：";
	cin >> pos;

	if (pos < 1 || pos > p->length) 
	{
		cout << pos << "号车位上没有车辆！";
		return;
	}
	p->parkinglot[pos - 1]->departtime();
	p->parkinglot[pos - 1]->calculateAmount();
	cout << "离开时间为" << p->parkinglot[pos-1]->getDepartHour() << ":" << p->parkinglot[pos-1]->getDepartMin();
	cout << "费用为" << p->parkinglot[pos-1]->getAmount();
	savecarlog(pos);
	car* q = p->parkinglot[pos - 1];
	cout << q->getNumber() << "已离开停车场\n";
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

		cout << "停车场有空位，便道中的" << temcar->getNumber()
			<< "已进入停车场中" << endl;
	}
}

void Manager::sqfindcar(parkinglot* p, string carname)
{
	for (int i = 0; i < p->length; i++) {
		if (carname == p->parkinglot[i]->getNumber())
			cout << carname << "的位置位于" << i << "号\n";
	}
}

void Manager::savecarinfo(bool mode) {
	ofstream file("parkinglot.csv");

	if (file.is_open()) {
		file << "车牌号,到达时间\n";
		for (int i = 0; i < p->length; i++) {
			if (p->parkinglot[i] == nullptr)
				i++;
			file << p->parkinglot[i]->getNumber() << "," << p->parkinglot[i]->getArrivehour()
				<< ":" << p->parkinglot[i]->getArriveMin() << "\n";
		}
		file.close();
	}
	else {
		cerr << "无法打开文件!" << endl;
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
		file << "车牌号,到达时间,离开时间,待支付金额\n";
		
			file << p->parkinglot[i-1]->getNumber() << "," << p->parkinglot[i-1]->getArrivehour() << ":" << p->parkinglot[i-1]->getArriveMin()
				<< "," << p->parkinglot[i-1]->getDepartHour() << ":" << p->parkinglot[i-1]->getDepartMin() << "," << p->parkinglot[i-1]->getAmount() << "\n";
		
		file.close();
	}
	else {
		cerr << "无法打开文件!" << endl;
	}
}