#include "Registration.h"
#include <iostream>

Registration::Registration(Team* team) : team(team), dateRegistered(""), validated(false) {}

Team* Registration::getTeam() const {
    return team;
}

void Registration::setTeam(Team* team) {
    this->team = team;
}

std::string Registration::getDateRegistered() const {
    return dateRegistered;
}

void Registration::setDateRegistered(const std::string& date) {
    this->dateRegistered = date;
}

bool Registration::isValidated() const {
    return validated;
}

void Registration::Validate() {
    this->validated = true;
    this->team->setInscris(true);
}

void Registration::inValidate() {
    this->validated = false;
    this->team->setInscris(false);
}

void Registration::inputRegistration() {
    std::cout << "Entrez la date d'inscription: ";
    std::getline(std::cin, dateRegistered);
}

void Registration::displayRegistration() const {
    std::cout << "Équipe: " << team->getName()
              << ", Date Inscription: " << dateRegistered
              << ", Validée: " << (validated ? "Oui" : "Non") << std::endl;
}