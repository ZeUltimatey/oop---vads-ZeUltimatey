// Made by: Edijs Aizgirevičs

#include <iostream>
#include <vector>
#include <random>


class Soldier {

public:
    int strength;
    int health;

    // Constructor with default values for strength and health
    Soldier(int strength = 0, int health = 0) : strength(strength), health(health) {}

};


class Platoon {

private:
    int surviving_soldiers = 0; // keep track of the number of surviving soldiers

public:
    Platoon() {}

    // Add a new soldier with the given strength, health
    void addSoldier(int strength, int health) {
        this->soldiers.emplace_back(strength, health);
        this->surviving_soldiers++;
    }

    // Add a new soldier with random strength, health
    void addRandomSoldier() {
        int strength = rand();
        int health = rand();
        this->addSoldier(strength, health);
    }

    // Return true if there are surviving soldiers in the platoon
    bool hasSurvivingSoldiers() {
        return this->surviving_soldiers > 0;
    }

    void removeDefeatedSoldier() {
        this->surviving_soldiers--;
    }

    std::vector<Soldier> soldiers;
};


int main() {
    // Create two platoons
    Platoon platoon1, platoon2;

    // Add some soldiers to each platoon
    platoon1.addRandomSoldier();
    platoon1.addRandomSoldier();
    platoon1.addRandomSoldier();
    platoon2.addRandomSoldier();
    platoon2.addRandomSoldier();
    platoon2.addRandomSoldier();

    int num_battles = 100;
    for (int i = 0; i < num_battles; i++) {
        // Create two new platoons
        Platoon platoon1, platoon2;

        // Add some soldiers to each platoon
        platoon1.addRandomSoldier();
        platoon1.addRandomSoldier();
        platoon1.addRandomSoldier();
        platoon2.addRandomSoldier();
        platoon2.addRandomSoldier();
        platoon2.addRandomSoldier();

        // Run the battle
        while (platoon1.hasSurvivingSoldiers() && platoon2.hasSurvivingSoldiers()) {
            // Get a random soldier from each platoon
            Soldier soldier1 = platoon1.soldiers[rand() % platoon1.soldiers.size()];
            Soldier soldier2 = platoon2.soldiers[rand() % platoon2.soldiers.size()];

            // Have the soldiers fight each other
            while (soldier1.health > 0 && soldier2.health > 0) {
                soldier1.health -= soldier2.strength;
                soldier2.health -= soldier1.strength;
            }

            // The soldier with remaining health is the winner
            if (soldier1.health > 0) {
                // Soldier 1 wins, remove soldier 2 from platoon 2
                platoon2.removeDefeatedSoldier();
            } else {
                // Soldier 2 wins, remove soldier 1 from platoon 1
                platoon1.removeDefeatedSoldier();
            }
        }
        // At this point one of the platoons is the winner
        if (platoon1.hasSurvivingSoldiers()) {
            std::cout << "Platoon 1 wins!" << std::endl;
        } else if (platoon2.hasSurvivingSoldiers()) {
            std::cout << "Platoon 2 wins!" << std::endl;
        } else {
            std::cout << "Draw" << std::endl;
        }
        return 0;
    }
}
