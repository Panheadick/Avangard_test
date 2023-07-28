#include "Cabin.h"

Cabin::Cabin() {
    floor = 1;
    status = STANDING_WITH_CLOSED_DOORS;
}

// Нажать кнопку этажа 
void Cabin::pressFloorButton(int floor) {

    // Двери закрываются после нажатия на кнопку этажа
    this->pressDoorCloseButton();

    //Если выбранный этаж выше текущего, то лифт двигает вверх
    if (floor > this->floor) {
        status = MOVING_UP;
    }
    //Если выбранный этаж ниже текущего, то лифт двигает вниз
    else if (floor < this->floor) {
        status = MOVING_DOWN;
    }


    std::cout << "Кабинка двигается " << (status == MOVING_UP ? "вверх " : "вниз ") << std::endl;
    // Пока кабина не достигнет нужного этажа, увеличиваем или уменьшаем текущий этаж
    while (this->floor != floor) {
        if (status == MOVING_UP) {
            this->floor++;
            Sleep(TIME_ONE_FLOOR);
        }
        else if (status == MOVING_DOWN) {
            this->floor--;
            Sleep(TIME_ONE_FLOOR);
        }
        std::cout << "Кабина находится на этаже " << this->floor << std::endl;
    }
    this->status = STANDING_WITH_CLOSED_DOORS;
    std::cout << "Кабина прибыла на этаж "  << this->floor << std::endl;

    // Двери открываются после прибытия
    this->pressDoorOpenButton();

    // И снова закрываются
    this->pressDoorCloseButton();
}
 
// Нажать кнопку закрытия дверей 
void Cabin::pressDoorCloseButton() {
    if (status == STANDING_WITH_OPEN_DOORS) {
        std::cout << "Двери закрываются" << std::endl;
        status = DOOR_CLOSING;
        Sleep(TIME_OPEN_CLOSE_DOOR);
        status = STANDING_WITH_CLOSED_DOORS;
        std::cout << "Двери закрыты." << std::endl;
    }
    else if (status == STANDING_WITH_CLOSED_DOORS){
        std::cout << "Двери уже закрыты." << std::endl;
    }
    else if (status == DOOR_CLOSING or status == DOOR_OPENING) {
        std::cout << "Двери открываются или закрываются в данный момент." << std::endl;
    }
}

// Нажать кнопку открытия дверей 
void Cabin::pressDoorOpenButton() {
    if (status == STANDING_WITH_CLOSED_DOORS) {
        std::cout << "Двери открываются" << std::endl;
        status = DOOR_CLOSING;
        Sleep(TIME_OPEN_CLOSE_DOOR);
        status = STANDING_WITH_OPEN_DOORS;
        std::cout << "Двери открыты." << std::endl;
    }
    else if (status == DOOR_OPENING or status == DOOR_CLOSING){
        std::cout << "Двери открываются или закрываются в данный момент." << std::endl;
    }
    else if (status == MOVING_UP or status == MOVING_DOWN) {
        std::cout << "Нельзя открывать двери во время движения." << std::endl;
    }

}

void Cabin::pressDispatcherButton() {
    std::cout << "Был вызвван диспетчер.";
}

void Cabin::setFloor(int floor) {
    this->floor = floor;
}

void Cabin::setStatus(Status status) {
    this->status = status;
}

int Cabin::getFloor() {
    return this->floor;
}

Status Cabin::getStatus() {
    return this->status;
}