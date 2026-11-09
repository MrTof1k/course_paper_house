#include <iostream>
#include "home.cpp"
#include "database.cpp"

using namespace std;


int main() {
    system("chcp 65001");
    ExchangeFactors factors;
    factors.positive_factors = "Рядом парк, хороший ремонт";
    factors.negative_factors = "Далеко от метро";
    House house("Центральный",
                "ул. Лесная, 10",
                "Кирпичный дом",
                5000000,
                150,
                "Два этажа, три комнаты",
                factors,
                2,
                600);
    house.showInfo();
    DemandDatabase database;
    Demand demand1(
            "Центральный",
            "Квартира",
            50, 70,
            3000000, 5000000,
            2, 3,
            55.75, 37.61
    );
    Demand demand2(
            "Северный",
            "Частный дом",
            90, 150,
            4000000, 7000000,
            3, 5,
            55.82, 37.50
    );
    database.addDemand(demand1);
    database.addDemand(demand2);
    database.showAll();
    return 0;
}