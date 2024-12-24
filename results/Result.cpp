#include "Result.h"
#include <iostream>

Result::Result(Match* match, int scoreTeam1, int scoreTeam2)
    : match(match), scoreTeam1(scoreTeam1), scoreTeam2(scoreTeam2) {}

Match* Result::getMatch() const {
    return match;
}

void Result::setMatch(Match* match) {
    this->match = match;
}

int Result::getScoreTeam1() const {
    return scoreTeam1;
}

void Result::setScoreTeam1(int score) {
    this->scoreTeam1 = score;
}

int Result::getScoreTeam2() const {
    return scoreTeam2;
}

void Result::setScoreTeam2(int score) {
    this->scoreTeam2 = score;
}

void Result::inputResult() {
    std::cout << "Enter team 1 score: ";
    std::cin >> scoreTeam1;
    std::cout << "Enter team 2 score: ";
    std::cin >> scoreTeam2;
}

void Result::displayResult() const {
    std::cout << "Team 1 score: " << scoreTeam1 << std::endl;
    std::cout << "Team 2 score: " << scoreTeam2 << std::endl;
}

void Result::AfterMatchCalculations() {
    if (scoreTeam1 > scoreTeam2) {
        match->getTeam1()->incrementWins();
        match->getTeam2()->incrementLosses();
    } else if (scoreTeam1 < scoreTeam2) {
        match->getTeam1()->incrementLosses();
        match->getTeam2()->incrementWins();
    } else {
        match->getTeam1()->incrementDraws();
        match->getTeam2()->incrementDraws();
    }
    match->getTeam1()->incrementGamesPlayed();
    match->getTeam2()->incrementGamesPlayed();
    match->setPlayed(true);
}
