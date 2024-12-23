#include "Field.h"

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