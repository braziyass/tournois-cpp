#include "Match.h"
#include <iostream>

Match::Match(Team* team1, Team* team2, const std::string& scheduledTime)
    : team1(team1), team2(team2), scheduledTime(scheduledTime), referee(nullptr) {}


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


bool Match::isPlayed() const {
    return played;
}

void Match::setPlayed(bool played) {
    this->played = played;
}

void Match::inputMatch() {

    std::cout << "Enter match phase (0 - GroupStage, 1 - QuarterFinal, 2 - SemiFinal, 3 - Final): ";
    int phase;
    std::cin >> phase;
    this->phase = static_cast<MatchPhase>(phase);

    std::cout << "Enter team 1: ";
    std::string team1Name;
    std::cin.ignore();
    std::getline(std::cin, team1Name);
    team1 = nullptr;
    for (Team& team : teams) {
        if (team.getName() == team1Name) {
            if (team.isInscris() == false) {
                std::cout << "Team 1 not registered." << std::endl;
                return;
            }
            team1 = &team;
            break;
        }
    }
    if (!team1) {
        std::cout << "Team not found." << std::endl;
        return;
    }
    
    std::cout << "Enter team 2: ";
    std::string team2Name;
    std::getline(std::cin, team2Name);
    team2 = nullptr;
    for (Team& team : teams) {
        if (team.getName() == team2Name) {
            if (team.isInscris() == false) {
                std::cout << "Team 2 not registered." << std::endl;
                return;
            }
            team2 = &team;
            break;
        }
    }
    if (!team2) {
        std::cout << "Team not found." << std::endl;
        return;
    }
    
    std::cout << "Enter scheduled time: ";
    std::cin.ignore();
    std::getline(std::cin, scheduledTime);
    
    std::cout << "Enter referee name: ";
    std::string refereeName;
    std::getline(std::cin, refereeName);
    referee = nullptr;
    for (Referee& ref : referees) {
        if (ref.getName() == refereeName) {
            referee = &ref;
            break;
        }
    }
    if (!referee) {
        std::cout << "Referee not found." << std::endl;
        return;
    }

    std::cout << "Enter field name: ";
    for (Field& f : fields) {
       std::cout << f.getName() << std::endl;
    }
    std::string fieldName;
    std::getline(std::cin, fieldName);
    field = nullptr;
    for (Field& f : fields) {
        if (f.getName() == fieldName) {
            field = &f;
            break;
        }
    }
    if (!field) {
        std::cout << "Field not found." << std::endl;
        return;
    }

}

void Match::displayMatch() const {

    std::cout << "Match: " << team1->getName() << " vs " << team2->getName() << " on " << scheduledTime << std::endl;

}
