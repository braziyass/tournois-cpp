#ifndef MATCH_H
#define MATCH_H

#include <string>
#include <vector>
#include "../teams/Team.h"
#include "../referees/Referee.h"
#include "../fields/Field.h"


std::vector<Match> matches;
extern std::vector<Referee> referees;
extern std::vector<Team> teams;
extern std::vector<Field> fields;

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
    
    std::string getScheduledTime() const;
    void setScheduledTime(const std::string& time);
    
    Referee* getReferee() const;
    void setReferee(Referee* referee);

    bool isPlayed() const;
    void setPlayed(bool played);

    void inputMatch();
    void displayNonPlayedMatch() const;
    
private:
    Team* team1;
    Team* team2;
    Field* field;
    
    std::string scheduledTime;
    Referee* referee;
    bool played = false;
};

#endif // MATCH_H