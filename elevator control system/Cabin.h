#pragma once
#include "Status.h"
#include <iostream>
#include "windows.h"


class Cabin
{
private:
	// Ётаж, на котором находитс€ кабина в данный момент.
	int floor;
	// —татус кабины  (едет вверх/едет вниз/открывает двери/закрывает двери/стоит с открытыми дверьми)
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

	// ¬рем€ за которое кабинка проезжает один этаж в мс
	static const int TIME_ONE_FLOOR = 30;
	// ¬рем€ закрыти€ и открыти€ дверей в мс
	static const int TIME_OPEN_CLOSE_DOOR = 100;
};

