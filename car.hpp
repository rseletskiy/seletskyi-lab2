#pragma once

#include <ostream>
#include <string>
#include <utility>

class Car {
    std::string model;

public:
    explicit Car(std::string model) : model(std::move(model)) {}

    virtual ~Car() = default;

    virtual void print(std::ostream& output) const {
        output << "Model: " << model;
    }
};

class CombustionCar : virtual public Car {
protected:
    double fuelTankCapacity;

public:
    CombustionCar(std::string model, double fuelTankCapacity)
        : Car(std::move(model)), fuelTankCapacity(fuelTankCapacity) {}

    void print(std::ostream& output) const override {
        Car::print(output);
        output << " | Fuel tank: " << fuelTankCapacity << " L";
    }
};

class ElectricCar : virtual public Car {
protected:
    double batteryCapacity;

public:
    ElectricCar(std::string model, double batteryCapacity)
        : Car(std::move(model)), batteryCapacity(batteryCapacity) {}

    void print(std::ostream& output) const override {
        Car::print(output);
        output << " | Battery: " << batteryCapacity << " kWh";
    }
};

class HybridCar : public CombustionCar, public ElectricCar {
public:
    HybridCar(std::string model, double fuelTankCapacity, double batteryCapacity)
        : Car(model), CombustionCar(model, fuelTankCapacity),
          ElectricCar(std::move(model), batteryCapacity) {}

    void print(std::ostream& output) const override {
        CombustionCar::print(output);
        output << " | Battery: " << batteryCapacity << " kWh";
    }
};
