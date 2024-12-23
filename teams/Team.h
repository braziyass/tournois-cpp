#ifndef TEAM_H
#define TEAM_H

#include <string>

class Team {
public:
    Team(const std::string& name, int ranking);
    Team();
    
    std::string getName() const;
    void setName(const std::string& name);
    
    int getRanking() const;
    void setRanking(int ranking);

    std::string getField() const;
    void setField(const std::string& field);

    int getCapacity() const;
    void setCapacity(int capacity);

    void inputTeam();
    
private:
    std::string name;
    int ranking;
    std::string field;
    int capacity;
};

#endif // TEAM_H