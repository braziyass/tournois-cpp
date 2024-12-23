#ifndef MATCH_H
#define MATCH_H

#include <string>
#include "../teams/Team.h"
#include "../fields/Field.h"
#include "../referees/Referee.h"

class Match {
public:
    Match(const std::string& phase, Team* team1, Team* team2, Field* field, const std::string& scheduledTime);
    
    std::string getPhase() const;
    void setPhase(const std::string& phase);
    
    Team* getTeam1() const;
    void setTeam1(Team* team);
    
    Team* getTeam2() const;
    void setTeam2(Team* team);
    
    Field* getField() const;
    void setField(Field* field);
    
    std::string getScheduledTime() const;
    void setScheduledTime(const std::string& time);
    
    Referee* getReferee() const;
    void setReferee(Referee* referee);
    
private:
    std::string phase;
    Team* team1;
    Team* team2;
    Field* field;
    std::string scheduledTime;
    Referee* referee;
};

#endif // MATCH_H