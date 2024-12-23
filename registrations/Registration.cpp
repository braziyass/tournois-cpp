#include "Registration.h"

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

void Registration::setValidated(bool validated) {
    this->validated = validated;
}