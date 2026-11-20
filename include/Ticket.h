#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ticket {
public:
    Ticket(const string& title = "未命名", double price = 0.0,
           int seat = 0, double discount = 1.0);
    ~Ticket();

    void print() const;
    double finalPrice() const;
    void changeSeat(int newSeat);

private:
    string title_;
    double price_;
    int    seat_;
    double discount_;
    static int total_;   // 已售票数统计
};
