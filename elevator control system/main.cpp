#include "Cabin.h"
#include <iostream>
#include "Floor.h"
#include <vector>

void testLift (Cabin* c1, Cabin* c2, std::vector<Floor> vec) {
	std::cout << "�������� 1 ������ ���� � 1-��� ����� " << std::endl;
	Cabin *c = vec[0].pressLiftButton(c1, c2);
	std::cout << "�������� ����� �� ������ 15 �����";
	c->pressFloorButton(15);

	std::cout << "�������� ������ ���� � 15-��� �����" << std::endl;
	c = vec[14].pressLiftButton(c1, c2);
	std::cout << "�������� ����� �� ������ 1 �����";
	c->pressFloorButton(1);
}

int main() {
	system("chcp 1251");

	Cabin *cabin1 = new Cabin();
	Cabin *cabin2 = new Cabin();
	std::vector<Floor> floors;
	for (int i = 1; i < 21; i++) {
		Floor floor(i);
		floors.push_back(floor);
	}

	testLift(cabin1, cabin2, floors);

	return 0;
}

