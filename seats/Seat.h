#ifndef SEAT_H
#define SEAT_H

enum class SeatType {
    VIP,
    Regular
};



class Seat {

public:
    Seat(int n);
    int getNum() const;
    void setNum(int n);

    bool isEmpty() const;
    void setEmpty(bool e);

    SeatType getType() const;
    void setType(SeatType t);

    void displaySeat() const;
    void inputSeat();

private:
    int num;
    bool empty = true;
    SeatType type;
};

#endif // SEAT_H