#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <vector>
#include "../matches/Match.h"
std::vector<Result> results;
extern std::vector<Match> matches;

class Result {
public:
    Result(Match* match, int scoreTeam1, int scoreTeam2);
    
    Match* getMatch() const;
    void setMatch(Match* match);
    
    int getScoreTeam1() const;
    void setScoreTeam1(int score);
    
    int getScoreTeam2() const;
    void setScoreTeam2(int score);

    void inputResult();
    void displayResult() const;
    void AfterMatchCalculations();
    
    
private:
    Match* match;
    int scoreTeam1;
    int scoreTeam2;
};

#endif // RESULT_H