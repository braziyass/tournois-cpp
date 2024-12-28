#include "Referee.h"
#include <iostream>

Referee::Referee(const std::string& name, const std::string& certifications)
    : name(name), certifications(certifications) {}

std::string Referee::getName() const {
    return name;
}

void Referee::setName(const std::string& name) {
    this->name = name;
}

std::string Referee::getCertifications() const {
    return certifications;
}

void Referee::setCertifications(const std::string& certifications) {
    this->certifications = certifications;
}

void Referee::inputReferee() {
    std::cout << "Enter referee name: ";
    std::getline(std::cin, name);
    std::cout << "Enter referee certifications: ";
    std::getline(std::cin, certifications);
}

void Referee::displayReferee() const {
    std::cout << "Referee name: " << name << std::endl;
    std::cout << "Referee certifications: " << certifications << std::endl;
}