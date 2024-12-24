#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <vector>
#include "../matches/Match.h"

std::vector<Ticket> tickets;
extern std::vector<Match> matches;

const int VIP_PRICE = 100;
const int REGULAR_PRICE = 50;

class Ticket {
public:
    Ticket(int id, Match* match, Seat* seat, double price);

    int getId() const;
    void setId(int id);
    
    Match* getMatch() const;
    void setMatch(Match* match);

    Seat* getSeat() const;
    void setSeat(Seat* seat);

    double getPrice() const;
    void setPrice(double price);

    void displayTicket() const;
    void inputTicket();
    
    
private:
    int id;
    Match* match;
    Seat* seat;
    double price;

};

#endif // TICKET_H