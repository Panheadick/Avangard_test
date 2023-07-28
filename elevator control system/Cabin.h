#pragma once
#include "Status.h"
#include <iostream>
#include "windows.h"


class Cabin
{
private:
	// Этаж, на котором находится кабина в данный момент.
	int floor;
	// Статус кабины  (едет вверх/едет вниз/открывает двери/закрывает двери/стоит с открытыми дверьми)
	Status status;
public:
	Cabin();
	void pressFloorButton(int);
	void pressDoorCloseButton();
	void pressDoorOpenButton();
	void pressDispatcherButton();

	int getFloor();
	Status getStatus();

	void setFloor(int);
	void setStatus(Status);

	// Время за которое кабинка проезжает один этаж в мс
	static const int TIME_ONE_FLOOR = 30;
	// Время закрытия и открытия дверей в мс
	static const int TIME_OPEN_CLOSE_DOOR = 100;
};

