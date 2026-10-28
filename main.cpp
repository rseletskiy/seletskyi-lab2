#include "car.hpp"

#include <iostream>

int main() {
    const Car car("Vehicle");
    const CombustionCar combustion("Toyota Corolla", 50);
    const ElectricCar electric("Tesla Model 3", 60);
    const HybridCar hybrid("Toyota Prius", 43, 8.8);
    const Car* cars[] = {&car, &combustion, &electric, &hybrid};

    for (const Car* vehicle : cars) {
        vehicle->print(std::cout);
        std::cout << '\n';
    }
}
