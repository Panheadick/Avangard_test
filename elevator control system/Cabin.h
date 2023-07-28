#pragma once
#include "Status.h"
#include <iostream>
#include "windows.h"


class Cabin
{
private:
	// ����, �� ������� ��������� ������ � ������ ������.
	int floor;
	// ������ ������  (���� �����/���� ����/��������� �����/��������� �����/����� � ��������� �������)
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

	// ����� �� ������� ������� ��������� ���� ���� � ��
	static const int TIME_ONE_FLOOR = 30;
	// ����� �������� � �������� ������ � ��
	static const int TIME_OPEN_CLOSE_DOOR = 100;
};

