#include "Team.h"
#include <iostream>


Team::Team(const std::string& name, int ranking) : name(name), ranking(ranking) {}

Team::Team() : name(""), ranking(0) {}

std::string Team::getName() const {
    return name;
}

void Team::setName(const std::string& name) {
    this->name = name;
}

int Team::getRanking() const {
    return ranking;
}

void Team::setRanking(int ranking) {
    this->ranking = ranking;
}

std::string Team::getField() const {
    return field;
}

void Team::setField(const std::string& field) {
    this->field = field;
}

int Team::getCapacity() const {
    return capacity;
}

void Team::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Team::inputTeam() {
    std::cout << "Enter team name: ";
    std::cin.ignore(); 
    std::getline(std::cin, name);
    std::cout << "Enter team field: ";
    std::cin.ignore();
    std::getline(std::cin, field);
    std::cout << "Enter field capacity: ";
    std::cin.ignore();
    std::cin >> capacity;
}