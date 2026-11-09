#include "iostream"
#include "iomanip"
#include "string"

using namespace std;

class Demand {
private:
    string district;       // Желаемый район
    string propertyType;   // Тип жилья

    double minArea;        // Минимальная площадь
    double maxArea;        // Максимальная площадь

    double minCost;        // Минимальная цена
    double maxCost;        // Максимальная цена

    int minRooms;          // Минимальное количество комнат
    int maxRooms;          // Максимальное количество комнат

    double coordinateX;    // Координата X заявителя
    double coordinateY;    // Координата Y заявителя
public:
    Demand() {
        district = "";
        propertyType = "";
        minArea = 0;
        maxArea = 0;
        maxCost = 0;
        minCost = 0;
        minRooms = 0;
        maxRooms = 0;
        coordinateX = 0;
        coordinateY = 0;
    }

    Demand(string district, string propertyType,
           double minArea, double maxArea,
           double minCost, double maxCost,
           int minRooms, int maxRooms,
           double coordinateX, double coordinateY) {
        this->district = district;
        this->propertyType = propertyType;
        this->minArea = minArea;
        this->maxArea = maxArea;
        this->minCost = minCost;
        this->maxCost = maxCost;
        this->minRooms = minRooms;
        this->maxRooms = maxRooms;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
    }

    void showInfo() const {
        cout << "\n===== ТРЕБОВАНИЯ ПОКУПАТЕЛЯ =====\n";

        cout << "Район: " << district << endl;
        cout << "Тип жилья: " << propertyType << endl;

        cout << "Площадь: от " << minArea
             << " до " << maxArea << " м2" << endl;

        cout << "Стоимость: от " << minCost
             << " до " << maxCost << endl;

        cout << "Количество комнат: от " << minRooms
             << " до " << maxRooms << endl;

        cout << "Координаты заявителя: X = "
             << coordinateX << ", Y = "
             << coordinateY << endl;
    }
};

class DemandDatabase {
private:
    Demand *demands; //Массив требований
    int count; // Кол-во записей
    int capacity; // Размер массива
public:
    DemandDatabase() {
        count = 0;
        capacity = 2;
        demands = new Demand[capacity];
    }

    void resize() {
        int newCapacity = capacity * 2;
        Demand *newDemands = new Demand[newCapacity];
        for (int i = 0; i < count; i++) {
            newDemands[i] = demands[i];
        }
        delete[] demands;
        demands = newDemands;
        capacity = newCapacity;
    }

    void addDemand(const Demand &demand) {
        if (count == capacity) {
            resize();
        }
        demands[count] = demand;
        count++;
        cout << "Требование добавлено\n";
    }

    void showAll() const {
        if (count == 0) {
            cout << "База спроса пуста.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "\nЗапись №" << i + 1 << endl;
            demands[i].showInfo();
        }
    }

    int getCount() const {
        return count;
    }

    ~DemandDatabase() {
        delete[] demands;
    }
};

