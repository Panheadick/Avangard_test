#include "Floor.h"

Floor::Floor(int floor) {
    this->floor = floor;
    this->cabin1Floor = 1;
    this->cabin1Status = STANDING_WITH_CLOSED_DOORS;
    this->cabin2Floor = 1;
    this->cabin2Status = STANDING_WITH_CLOSED_DOORS;
    this->callButtonPressed = false;
}

Cabin* Floor::pressLiftButton(Cabin *c1, Cabin *c2) {
    // ���� ������ �� ������
    if (!callButtonPressed) {
        this->callButtonPressed = true;

        // �������� ���������� � ������� �����
        this->cabin1Floor = c1->getFloor();
        this->cabin1Status = c1->getStatus();
        this->cabin2Floor = c2->getFloor();
        this->cabin2Status = c2->getStatus();


        // ���� ��� ������ �������� ���������� ��������� 
        if (this->cabin1Status == STANDING_WITH_CLOSED_DOORS and this->cabin2Status == STANDING_WITH_CLOSED_DOORS)
        {
            if ( abs(this->cabin1Floor - this->floor) < abs(this->cabin2Floor - this->floor) ) {
                c1->pressFloorButton(this->floor);
                this->callButtonPressed = false;
                return c1;
            }
            else {
                c2->pressFloorButton(this->floor);
                this->callButtonPressed = false;
                return c2;
            }
        }
        // ���� �������� ������ ����, �������� ���
        else if (this->cabin2Status == STANDING_WITH_CLOSED_DOORS) {
            c2->pressFloorButton(this->floor);
            this->callButtonPressed = false;
            return c2;
        }
        else if (this->cabin1Status == STANDING_WITH_CLOSED_DOORS) {
            c1->pressFloorButton(this->floor);
            this->callButtonPressed = false;
            return c1;
        }
        // ���� ��� ��������� ����� ��������� ��������� �� ������
        else {
            std::cout << "��������� ���� ���� �� ������ ����������� � ����� ������� �� ������." << std::endl;
        }
    }
}
