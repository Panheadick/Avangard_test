#pragma once
#include "Status.h"
#include "Cabin.h"
#include  <cmath>

class Floor
{
private:
    // ���������� floor ������ ���������� � ���, ����� ���� ���� �� ����� [1-20]
    int floor;
    int cabin1Floor;
    Status cabin1Status;
    int cabin2Floor;
    Status cabin2Status;
    bool callButtonPressed;
public:
    Floor(int floor);
    // ����� ��������� 2 ������� ����� �����, ������������ �������, ������� ��������
    Cabin* pressLiftButton(Cabin*, Cabin*);
};

