#ifndef RESULT_H
#define RESULT_H

#include <string>
#include "../matches/Match.h"

class Result {
public:
    Result(Match* match, int scoreTeam1, int scoreTeam2);
    
    Match* getMatch() const;
    void setMatch(Match* match);
    
    int getScoreTeam1() const;
    void setScoreTeam1(int score);
    
    int getScoreTeam2() const;
    void setScoreTeam2(int score);
    
    std::string getRecordedAt() const;
    void setRecordedAt(const std::string& time);
    
private:
    Match* match;
    int scoreTeam1;
    int scoreTeam2;
    std::string recordedAt;
};

#endif // RESULT_H