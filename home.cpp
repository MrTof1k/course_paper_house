#include <iostream>
#include <string>
#include "iomanip"

using namespace std;


struct ExchangeFactors {
    string positive_factors;
    string negative_factors;
};


class Home {
protected:
    string district;          // Район
    string address;           // Адрес
    string characteristic;    // Характеристика жилья
    double cost;              // Запрашиваемая стоимость
    double area;              // Площадь
    string layout;             // Планировка
    ExchangeFactors factors;  // Факторы обмена

public:
    Home(string district, string address,
         string characteristic, double cost,
         double area, string layout,
         ExchangeFactors factors) {
        this->district = district;
        this->address = address;
        this->characteristic = characteristic;
        this->cost = cost;
        this->area = area;
        this->layout = layout;
        this->factors = factors;
    }


    void setCost(double newCost) {
        if (newCost > 0) cost = newCost;
    }

    void setArea(double newArea) {
        if (newArea > 0) area = newArea;
    }

    void setDistrict(string newDistrict) {
        district = newDistrict;
    }

    void setAddress(string newAddress) {
        address = newAddress;
    }

    void setCharacteristic(string newCharacteristic) {
        characteristic = newCharacteristic;
    }

    void setLayout(string newLayout) {
        layout = newLayout;
    }


    virtual void showInfo() const {
        cout << "Район: " << district << endl;
        cout << "Адрес: " << address << endl;
        cout << "Характеристика: " << characteristic << endl;
        cout << fixed << setprecision(2);
        cout << "Стоимость: " << cost << endl;
        cout << "Площадь: " << area << " м2" << endl;
        cout << "Планировка: " << layout << endl;

        cout << "Положительные факторы: "
             << factors.positive_factors << endl;

        cout << "Отрицательные факторы: "
             << factors.negative_factors << endl;
    }


    double getCost() const {
        return cost;
    }


    double getArea() const {
        return area;
    }

    string getDistrict() const {
        return district;
    }

    virtual ~Home() {}
};


class House : public Home {
private:
    int floors;             // Количество этажей
    double land_area;       // Площадь участка

public:


    House(string district, string address,
          string characteristic, double cost,
          double area, string layout,
          ExchangeFactors factors,
          int floors, double land_area)
            : Home(district, address, characteristic,
                   cost, area, layout, factors) {
        this->floors = floors;
        this->land_area = land_area;
    }

    void showInfo() const override {
        cout << "\n===== ЧАСТНЫЙ ДОМ =====\n";

        Home::showInfo();

        cout << "Количество этажей: "
             << floors << endl;

        cout << "Площадь участка: "
             << land_area << " м2" << endl;
    }
};


class Apartment : public Home {
private:
    int floor;              // Этаж квартиры
    int total_floors;       // Количество этажей здания

public:

    Apartment(string district, string address,
              string characteristic, double cost,
              double area, string layout,
              ExchangeFactors factors,
              int floor, int total_floors)
            : Home(district, address, characteristic,
                   cost, area, layout, factors) {
        this->floor = floor;
        this->total_floors = total_floors;
    }

    void showInfo() const override {
        cout << "\n===== КВАРТИРА =====\n";

        Home::showInfo();

        cout << "Этаж квартиры: "
             << floor << endl;

        cout << "Всего этажей в здании: "
             << total_floors << endl;
    }
};
