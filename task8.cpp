#include <iostream>

enum Week{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sanday
};

struct Date{
    int day;
    int month;
    int year;
};

void show_week(enum Week ob) {
    std::cout << ob << std::endl;
}

void show_day(struct Date ob) {
    std::cout << ob.day << std::endl;
}

int main() {
    Date ob = {13, 04, 2002};
    show_day(ob);

    Week ob1 = Monday;
    show_week(ob1);
    return 0;
}