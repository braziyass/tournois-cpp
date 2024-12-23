#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "../teams/Team.h"

class Field {
public:
    Field(const std::string& name, int capacity);
    
    std::string getName() const;
    void setName(const std::string& name);
    
    int getCapacity() const;
    void setCapacity(int capacity);

    Team* getTeam() const;
    void setTeam(Team* team);
    
private:
    std::string name;
    int capacity;
    Team* team;

};

#endif // FIELD_H