#pragma once
#include "Status.h"
#include "Cabin.h"
#include  <cmath>

class Floor
{
private:
    // Переменная floor хранит информацию о том, какой этот этаж по счету [1-20]
    int floor;
    int cabin1Floor;
    Status cabin1Status;
    int cabin2Floor;
    Status cabin2Status;
    bool callButtonPressed;
public:
    Floor(int floor);
    // Метод принимает 2 обьекта кабин лифта, возвращается кабинку, которая приехала
    Cabin* pressLiftButton(Cabin*, Cabin*);
};

