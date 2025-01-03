#ifndef MATCH_H
#define MATCH_H

#include <string>
#include <vector>
#include "../teams/Team.h"
#include "../referees/Referee.h"
#include "../fields/Field.h"



enum class MatchPhase {
    GroupStage,
    QuarterFinal,
    SemiFinal,
    Final
};


class Match {
public:
    Match(Team* team1, Team* team2, const std::string& scheduledTime);
    
    
    
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

    MatchPhase getPhase() const;
    void setPhase(MatchPhase phase);

    bool isPlayed() const;
    void setPlayed(bool played);

    void inputMatch();
    std::string displayMatch() const;
    
private:
    Team* team1;
    Team* team2;
    Field* field;
    MatchPhase phase;
    std::string scheduledTime;
    Referee* referee;
    bool played = true;
};

extern std::vector<Match> matches;
extern std::vector<Referee> referees;
extern std::vector<Team> teams;
extern std::vector<Field> fields;


#endif // MATCH_H