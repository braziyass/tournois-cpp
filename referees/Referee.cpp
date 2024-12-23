#include "Referee.h"

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