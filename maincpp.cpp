#include <iostream>
#include "Player.h"
using namespace std;

int main() {
    try {
        // Test 1 — normal player
        Player p1(1, "Bukayo Saka", 23, "English", "RW", 7, 1, 34);
        p1.displayInfo();

        // Test 2 — free agent
        Player p2(2, "Kylian Mbappe", 25, "French", "ST", 9, -1, 30);
        p2.displayInfo();

        // Test 3 — polymorphism
        Person* p3 = new Player(3, "Declan Rice", 25, "English", "CM", 41, 1, 35);
        p3->displayInfo();
        delete p3;

        // Test 4 — add goals and assists
        Player p4(4, "Erling Haaland", 24, "Norwegian", "ST", 9, 2, 35);
        p4.addGoal();
        p4.addGoal();
        p4.addGoal();
        p4.addAssist();
        p4.displayInfo();

        // Test 5 — bad data, should throw
        Player p5(5, "", 23, "English", "ST", 9, 1, 20);

    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}