#include "Cabin.h"
#include <iostream>
#include "Floor.h"
#include <vector>

void testLift (Cabin* c1, Cabin* c2, std::vector<Floor> vec) {
	std::cout << "Пассажир 1 вызвал лифт с 1-ого этажа " << std::endl;
	Cabin *c = vec[0].pressLiftButton(c1, c2);
	std::cout << "Пассажир нажал на кнопку 15 этажа";
	c->pressFloorButton(15);

	std::cout << "Пассажир вызвал лифт с 15-ого этажа" << std::endl;
	c = vec[14].pressLiftButton(c1, c2);
	std::cout << "Пассажир нажал на кнопку 1 этажа";
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

