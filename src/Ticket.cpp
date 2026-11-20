#include "Ticket.h"
#include <algorithm>

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

// 两张票合成套票：价格累加，折扣取更优惠（更小）的那个
Ticket Ticket::operator+(const Ticket& other) const {
    return Ticket(title_ + "&" + other.title_,
                  price_ + other.price_,
                  seat_,
                  std::min(discount_, other.discount_));
}

// 按实付价格比较
bool Ticket::operator<(const Ticket& other) const {
    return finalPrice() < other.finalPrice();
}

// 同影片且同座位视为同一张票
bool Ticket::operator==(const Ticket& other) const {
    return title_ == other.title_ && seat_ == other.seat_;
}

ostream& operator<<(ostream& os, const Ticket& t) {
    os << "《" << t.title_ << "》 座位:" << t.seat_
       << " 实付:" << t.finalPrice();
    return os;
}
