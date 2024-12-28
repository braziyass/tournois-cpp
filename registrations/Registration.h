#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>
#include <vector>
#include "../teams/Team.h"



class Registration {
public:
    Registration(Team* team);
    
    Team* getTeam() const;
    void setTeam(Team* team);
    
    std::string getDateRegistered() const;
    void setDateRegistered(const std::string& date);
    
    bool isValidated() const;
    void Validate();
    void inValidate();

    void inputRegistration();
    void displayRegistration() const;
    
private:
    Team* team;
    std::string dateRegistered;
    bool validated;
};

extern std::vector<Registration> registrations;
extern std::vector<Team> teams;

#endif // REGISTRATION_H