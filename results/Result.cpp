#include "Result.h"

Result::Result(Match* match, int scoreTeam1, int scoreTeam2)
    : match(match), scoreTeam1(scoreTeam1), scoreTeam2(scoreTeam2), recordedAt("") {}

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

std::string Result::getRecordedAt() const {
    return recordedAt;
}

void Result::setRecordedAt(const std::string& time) {
    this->recordedAt = time;
}