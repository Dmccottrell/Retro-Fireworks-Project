/*	Project:    NAME OF PROJECT GOES HERE
	Name:       YOUR NAME GOES HERE
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 1
*/

#include <vector>
#include <iostream>
#include "Rocket.hpp"
#include "Streamer.hpp"
#include "Palmtree.hpp"
#include "Sparkler.hpp"

int main() {
    std::vector<Rocket *> rockets;

    // Create a new Streamer rocket and set its properties
    Rocket *r = new Streamer();
    r->SetPosition(10, 10);
    r->SetForce(1, -2);
    r->SetAgeLimit(100);

    rockets.push_back(r);  // Add the rocket to the list

    // Trigger action for the rocket
    r->Trigger(rockets);

    // Create a new Palmtree rocket and set its properties
    Rocket *p = new Palmtree();
    p->SetPosition(20, 20);
    p->SetForce(0, -3);
    p->SetAgeLimit(80);

    rockets.push_back(p);  // Add the Palmtree rocket to the list

    // Trigger action for the Palmtree rocket
    p->Trigger(rockets);

    // Main loop for updating the rockets and drawing them on the screen
    for (int age = 0; age < 100; age++) {
        for (Rocket *rocket : rockets) {
            rocket->Step();
            rocket->Draw();
        }
        // Add any other updates, like checking if rockets are still alive
    }

    // Clean up rockets when done
    for (Rocket *rocket : rockets) {
        delete rocket;
    }

    return 0;
}
