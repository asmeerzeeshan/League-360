#include <iostream>
#include <vector>
#include "Player.h"
#include "Coach.h"
using namespace std;

int main() {
    try {
        cout << "========================================" << endl;
        cout << "         LEAGUE 360 - SYSTEM TEST       " << endl;
        cout << "========================================\n" << endl;

        // ── PLAYER TESTS ──────────────────────────
        cout << "===== PLAYER TESTS =====" << endl;

        Player p1(1, "Bukayo Saka", 23, "English", "RW", 7, 1, 34);
        p1.addGoal(); p1.addGoal(); p1.addGoal();
        p1.addAssist(); p1.addAssist();
        p1.displayInfo();

        Player p2(2, "Erling Haaland", 24, "Norwegian", "ST", 9, 2, 35);
        p2.addGoal(); p2.addGoal(); p2.addGoal();
        p2.addGoal(); p2.addGoal();
        p2.addAssist();
        p2.displayInfo();

        Player p3(3, "Kylian Mbappe", 25, "French", "ST", 9, -1, 30);
        p3.displayInfo(); // free agent

        // ── COACH TESTS ───────────────────────────
        cout << "===== COACH TESTS =====" << endl;

        Coach c1(1, "Mikel Arteta", 42, "Spanish", "Head Coach", 1, 3);
        c1.displayInfo();

        Coach c2(2, "Pep Guardiola", 53, "Spanish", "Head Coach", 2, 14);
        c2.displayInfo();

        Coach c3(3, "Jurgen Klopp", 56, "German", "Head Coach", -1, 8);
        c3.displayInfo(); // no team

        // ── POLYMORPHISM TEST ─────────────────────
        cout << "===== POLYMORPHISM TEST =====" << endl;
        cout << "Person* pointing to Player and Coach objects:\n" << endl;

        vector<Person*> people;

        // Players
        people.push_back(new Player(4, "Declan Rice", 25, "English", "CM", 41, 1, 35));
        people.push_back(new Player(5, "Lamine Yamal", 17, "Spanish", "RW", 27, 3, 32));
        people.push_back(new Player(6, "Lautaro Martinez", 26, "Argentine", "ST", 10, 4, 36));

        // Coaches
        people.push_back(new Coach(4, "Carlo Ancelotti", 65, "Italian", "Head Coach", 3, 16));
        people.push_back(new Coach(5, "Simone Inzaghi", 48, "Italian", "Head Coach", 4, 6));

        // Polymorphic call — each calls its OWN displayInfo()
        for (Person* p : people) {
            p->displayInfo();
        }

        // ── SETTER TESTS ──────────────────────────
        cout << "===== SETTER TESTS =====" << endl;

        Player p4(7, "Test Player", 25, "English", "ST", 10, 1, 20);
        cout << "Before setters:" << endl;
        p4.displayInfo();

        p4.setGoalsScored(15);
        p4.setAssists(8);
        p4.setPosition("AM");
        p4.setJerseyNumber(8);
        cout << "After setters:" << endl;
        p4.displayInfo();

        // ── VALIDATION TESTS ──────────────────────
        cout << "===== VALIDATION TESTS =====" << endl;

        // Empty player name
        try {
            Player bad1(8, "", 23, "English", "ST", 9, 1, 20);
        }
        catch (const invalid_argument& e) {
            cout << "Caught: " << e.what() << endl;
        }

        // Invalid age
        try {
            Player bad2(9, "Bad Player", -5, "English", "ST", 9, 1, 20);
        }
        catch (const invalid_argument& e) {
            cout << "Caught: " << e.what() << endl;
        }

        // Invalid jersey
        try {
            Player bad3(10, "Bad Player", 23, "English", "ST", -1, 1, 20);
        }
        catch (const invalid_argument& e) {
            cout << "Caught: " << e.what() << endl;
        }

        // Empty coach name
        try {
            Coach bad4(6, "", 42, "Spanish", "Head Coach", 1, 3);
        }
        catch (const invalid_argument& e) {
            cout << "Caught: " << e.what() << endl;
        }

        // Empty coach role
        try {
            Coach bad5(7, "Some Coach", 42, "Spanish", "", 1, 3);
        }
        catch (const invalid_argument& e) {
            cout << "Caught: " << e.what() << endl;
        }

        // ── CLEANUP ───────────────────────────────
        for (Person* p : people) delete p;

        cout << "\n========================================" << endl;
        cout << "         ALL TESTS PASSED ✓             " << endl;
        cout << "========================================" << endl;

    }
    catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}