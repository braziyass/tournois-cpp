#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

std::vector<Team> teams;

class Team {
public:
    Team(const std::string& name = "");
    Team();
    
    std::string getName() const;
    void setName(const std::string& name);

    int getGamesPlayed() const;
    void incrementGamesPlayed();

    int getWins() const;
    void incrementWins();

    int getDraws() const;
    void incrementDraws();

    int getLosses() const;
    void incrementLosses();

    void inputTeam();
    void displayTeam() const;
    int calculatePoints() const;
    
private:
    std::string name;
    int gamesPlayed = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;
};

#endif // TEAM_H