#include "Cabin.h"

Cabin::Cabin() {
    floor = 1;
    status = STANDING_WITH_CLOSED_DOORS;
}

// ������ ������ ����� 
void Cabin::pressFloorButton(int floor) {

    // ����� ����������� ����� ������� �� ������ �����
    this->pressDoorCloseButton();

    //���� ��������� ���� ���� ��������, �� ���� ������� �����
    if (floor > this->floor) {
        status = MOVING_UP;
    }
    //���� ��������� ���� ���� ��������, �� ���� ������� ����
    else if (floor < this->floor) {
        status = MOVING_DOWN;
    }


    std::cout << "������� ��������� " << (status == MOVING_UP ? "����� " : "���� ") << std::endl;
    // ���� ������ �� ��������� ������� �����, ����������� ��� ��������� ������� ����
    while (this->floor != floor) {
        if (status == MOVING_UP) {
            this->floor++;
            Sleep(TIME_ONE_FLOOR);
        }
        else if (status == MOVING_DOWN) {
            this->floor--;
            Sleep(TIME_ONE_FLOOR);
        }
        std::cout << "������ ��������� �� ����� " << this->floor << std::endl;
    }
    this->status = STANDING_WITH_CLOSED_DOORS;
    std::cout << "������ ������� �� ���� "  << this->floor << std::endl;

    // ����� ����������� ����� ��������
    this->pressDoorOpenButton();

    // � ����� �����������
    this->pressDoorCloseButton();
}
 
// ������ ������ �������� ������ 
void Cabin::pressDoorCloseButton() {
    if (status == STANDING_WITH_OPEN_DOORS) {
        std::cout << "����� �����������" << std::endl;
        status = DOOR_CLOSING;
        Sleep(TIME_OPEN_CLOSE_DOOR);
        status = STANDING_WITH_CLOSED_DOORS;
        std::cout << "����� �������." << std::endl;
    }
    else if (status == STANDING_WITH_CLOSED_DOORS){
        std::cout << "����� ��� �������." << std::endl;
    }
    else if (status == DOOR_CLOSING or status == DOOR_OPENING) {
        std::cout << "����� ����������� ��� ����������� � ������ ������." << std::endl;
    }
}

// ������ ������ �������� ������ 
void Cabin::pressDoorOpenButton() {
    if (status == STANDING_WITH_CLOSED_DOORS) {
        std::cout << "����� �����������" << std::endl;
        status = DOOR_CLOSING;
        Sleep(TIME_OPEN_CLOSE_DOOR);
        status = STANDING_WITH_OPEN_DOORS;
        std::cout << "����� �������." << std::endl;
    }
    else if (status == DOOR_OPENING or status == DOOR_CLOSING){
        std::cout << "����� ����������� ��� ����������� � ������ ������." << std::endl;
    }
    else if (status == MOVING_UP or status == MOVING_DOWN) {
        std::cout << "������ ��������� ����� �� ����� ��������." << std::endl;
    }

}

void Cabin::pressDispatcherButton() {
    std::cout << "��� ������� ���������.";
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