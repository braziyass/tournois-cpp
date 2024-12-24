#include "Ticket.h"
#include <iostream>

Ticket::Ticket(int id, Match* match, Seat* seat, double price)
    : id(id), match(match), seat(seat), price(price) {}


Match* Ticket::getMatch() const {
    return match;
}

void Ticket::setMatch(Match* match) {
    this->match = match;
}

Seat* Ticket::getSeat() const {
    return seat;
}

void Ticket::setSeat(Seat* seat) {
    this->seat = seat;
}

double Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(double price) {
    this->price = price;
}

void Ticket::displayTicket() const {
    std::cout << "Ticket ID: " << id << ", Match: " << match->getTeam1()->getName() << " vs " << match->getTeam2()->getName()
              << ", Seat: " << seat->getNum() << ", Price: $" << price << std::endl;
}

void Ticket::inputTicket() {
    std::cout << "Enter ticket ID: ";
    std::cin >> id;
    std::cout << "Enter match: ";
    int matchIndex=0;
    for (Match& m : matches) {
        std::cout << matchIndex << m.displayMatch() << std::endl;
        matchIndex++;
    }
    std::cin >> matchIndex;
    match = &matches[matchIndex];
    
    seat->inputSeat();
}
