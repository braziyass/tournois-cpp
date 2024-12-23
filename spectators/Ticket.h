#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "../matches/Match.h"

class Ticket {
public:
    Ticket(Match* match, const std::string& seatNumber, double price);
    
    Match* getMatch() const;
    void setMatch(Match* match);
    
    std::string getSeatNumber() const;
    void setSeatNumber(const std::string& seatNumber);
    
    double getPrice() const;
    void setPrice(double price);
    
    bool isAvailable() const;
    void setAvailability(bool available);
    
private:
    Match* match;
    std::string seatNumber;
    double price;
    bool available;
};

#endif // TICKET_H