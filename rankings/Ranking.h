#ifndef RANKING_H
#define RANKING_H

#include <string>
#include "../teams/Team.h"

class Ranking {
public:
    Ranking(Team* team, int points, int gamesPlayed, int wins, int draws, int losses);
    
    Team* getTeam() const;
    void setTeam(Team* team);
    
    int getPoints() const;
    void setPoints(int points);
    
    int getGamesPlayed() const;
    void setGamesPlayed(int gamesPlayed);
    
    int getWins() const;
    void setWins(int wins);
    
    int getDraws() const;
    void setDraws(int draws);
    
    int getLosses() const;
    void setLosses(int losses);
    
private:
    Team* team;
    int points;
    int gamesPlayed;
    int wins;
    int draws;
    int losses;
};

#endif // RANKING_H