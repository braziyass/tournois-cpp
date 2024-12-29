#include "Team.h"
#include <iostream>


Team::Team(const std::string& name)
    : name(name) {}



std::string Team::getName() const {
    return name;
}

void Team::setName(const std::string& name) {
    this->name = name;
}


bool Team::isInscris() const {
    return inscris;
}

void Team::setInscris(bool inscris) {
    this->inscris = inscris;
}

int Team::getGamesPlayed() const {
    return gamesPlayed;
}

void Team::incrementGamesPlayed() {
    gamesPlayed++;
}

int Team::getWins() const {
    return wins;
}

void Team::incrementWins() {
    wins++;
}


int Team::getDraws() const {
    return draws;
}

void Team::incrementDraws() {
    draws++;
}

int Team::getLosses() const {
    return losses;
}

void Team::incrementLosses() {
    losses++;
}

void Team::inputTeam() {
    std::cout << "Enter team name: ";
    std::getline(std::cin, name);
}

void Team::displayTeam() const {
    std::cout << "Team name: " << name << std::endl;
    std::cout << "Games played: " << gamesPlayed << std::endl;
    std::cout << "Wins: " << wins << std::endl;
    std::cout << "Draws: " << draws << std::endl;
    std::cout << "Losses: " << losses << std::endl;
    std::cout << "Points: " << calculatePoints() << std::endl;
}

int Team::calculatePoints() const {
    return wins * 3 + draws;
}