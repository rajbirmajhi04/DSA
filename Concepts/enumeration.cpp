#include <iostream>
using namespace std;

/*
    ? by default spring is 0. we can change the default value of an enum element during declaration
*/
enum season {
    spring = 0,
    summer = 4,
    autmn = 8,
    winter = 12
};

// here index of each value starts from (0)
// values default idnex can be changed
enum week {
    sunday = 34, monday, tuesday, wednesday, thursday, friday, saturday
};

// enum variable takes only one value out of many possible values.
enum suit {
    club = 0,
    diamond = 10,
    hearts = 20,
    spades = 3
} card;

// all the integral constants are power of 2
enum designFlags {
    ITALICS = 1,
    BOLD = 2,
    UNDERLINE = 4
};

int main()
{
    week today;
    today = sunday;
    cout << "Day " << today + 1 << endl;

    season month;
    month = summer;
    cout << "Season: " << month << endl;

    suit cards;
    cards = hearts;
    cout << "Point: " << (cards) << endl;

    card = diamond;
    cout << "Size of enum variable " << sizeof(card) << " bytes." << endl;

    // When the output is (6) -> Bold and Underline are used
    int myDesign = BOLD | UNDERLINE;
    // when the output is (5) -> Italics and Underline are used
    int myDesign1  = ITALICS | UNDERLINE;

    cout << myDesign << endl;
    cout << myDesign1 << endl;
   
    return 0;
}