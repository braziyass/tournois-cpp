#include "Field.h"
#include <iostream>

Field::Field(const std::string& name, int capacity) : name(name), capacity(capacity) {}

std::string Field::getName() const {
    return name;
}

void Field::setName(const std::string& name) {
    this->name = name;
}

int Field::getCapacity() const {
    return capacity;
}

void Field::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Field::displayField() const {
    std::cout << "Field Name: " << name << ", Capacity: " << capacity << std::endl;
}

void Field::inputField() {
    std::cout << "Enter field name: ";
    std::getline(std::cin, name);
    std::cout << "Enter field capacity: ";
    std::cin >> capacity;
}