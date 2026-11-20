#include "Ticket.h"

int main() {
    Ticket a("流浪地球3", 60, 12, 0.9);
    Ticket b("流浪地球3", 60, 13, 0.8);

    a.print();
    b.print();

    Ticket couple = a + b;          // 情侣套票
    cout << "套票：" << couple << endl;

    cout << (a < b ? "a 更便宜" : "b 更便宜") << endl;
    cout << (a == b ? "是同一张票" : "不是同一张票") << endl;

    a.changeSeat(20);
    a.print();
    return 0;
}
