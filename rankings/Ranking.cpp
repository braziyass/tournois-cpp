#include "Ranking.h"

Ranking::Ranking(Team* team, int points, int gamesPlayed, int wins, int draws, int losses)
    : team(team), points(points), gamesPlayed(gamesPlayed), wins(wins), draws(draws), losses(losses) {}

Team* Ranking::getTeam() const {
    return team;
}

void Ranking::setTeam(Team* team) {
    this->team = team;
}

int Ranking::getPoints() const {
    return points;
}

void Ranking::setPoints(int points) {
    this->points = points;
}

int Ranking::getGamesPlayed() const {
    return gamesPlayed;
}

void Ranking::setGamesPlayed(int gamesPlayed) {
    this->gamesPlayed = gamesPlayed;
}

int Ranking::getWins() const {
    return wins;
}

void Ranking::setWins(int wins) {
    this->wins = wins;
}

int Ranking::getDraws() const {
    return draws;
}

void Ranking::setDraws(int draws) {
    this->draws = draws;
}

int Ranking::getLosses() const {
    return losses;
}

void Ranking::setLosses(int losses) {
    this->losses = losses;
}