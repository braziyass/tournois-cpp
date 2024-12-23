#include "Match.h"

Match::Match(const std::string& phase, Team* team1, Team* team2, Field* field, const std::string& scheduledTime)
    : phase(phase), team1(team1), team2(team2), field(field), scheduledTime(scheduledTime), referee(nullptr) {}

std::string Match::getPhase() const {
    return phase;
}

void Match::setPhase(const std::string& phase) {
    this->phase = phase;
}

Team* Match::getTeam1() const {
    return team1;
}

void Match::setTeam1(Team* team) {
    this->team1 = team;
}

Team* Match::getTeam2() const {
    return team2;
}

void Match::setTeam2(Team* team) {
    this->team2 = team;
}

Field* Match::getField() const {
    return field;
}

void Match::setField(Field* field) {
    this->field = field;
}

std::string Match::getScheduledTime() const {
    return scheduledTime;
}

void Match::setScheduledTime(const std::string& time) {
    this->scheduledTime = time;
}

Referee* Match::getReferee() const {
    return referee;
}

void Match::setReferee(Referee* referee) {
    this->referee = referee;
}