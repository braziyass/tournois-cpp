#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "../teams/Team.h"
#include <vector>
#include "../seats/Seat.h"

std::vector<Field> fields;

class Field {
public:
    Field(const std::string& name, int capacity);
    
    std::string getName() const;
    void setName(const std::string& name);
    
    int getCapacity() const;
    void setCapacity(int capacity);

    void displayField() const;
    void inputField();
    
private:
    std::string name;
    int capacity;
    std::vector<Seat> seats;
};

#endif // FIELD_H