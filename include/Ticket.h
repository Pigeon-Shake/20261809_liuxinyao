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

    // 两张票合并成"套票"：价格相加，折扣取更优惠（更小）的
    Ticket operator+(const Ticket& other) const;
    // 按实付价格比较，方便排序
    bool operator<(const Ticket& other) const;
    // 同影片且同座位视为同一张票
    bool operator==(const Ticket& other) const;

    // 流输出：左操作数是 ostream，只能写成友元函数
    friend ostream& operator<<(ostream& os, const Ticket& t);

private:
    string title_;
    double price_;
    int    seat_;
    double discount_;
    static int total_;   // 已售票数统计
};
