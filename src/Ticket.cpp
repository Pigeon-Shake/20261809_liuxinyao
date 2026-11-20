#include "Ticket.h"

int Ticket::total_ = 0;

// 构造函数：初始化列表依次初始化影片名、原价、座位号、折扣率
Ticket::Ticket(const string& title, double price, int seat, double discount)
    : title_(title), price_(price), seat_(seat), discount_(discount) {
    ++total_;
    cout << "[出票] 《" << title_ << "》 " << seat_ << "号座，原价 " << price_ << endl;
}

// 析构函数：退票时票数减一，并打印剩余票数
Ticket::~Ticket() {
    --total_;
    cout << "[退票] 《" << title_ << "》 " << seat_ << "号座，剩余票数：" << total_ << endl;
}

void Ticket::print() const {
    cout << "《" << title_ << "》 座位:" << seat_
         << " 原价:" << price_
         << " 折扣:" << discount_
         << " 实付:" << finalPrice() << endl;
}

// 实付价格 = 原价 * 折扣率
double Ticket::finalPrice() const {
    return price_ * discount_;
}

void Ticket::changeSeat(int newSeat) {
    cout << "换座：" << seat_ << " -> " << newSeat << endl;
    seat_ = newSeat;
}
