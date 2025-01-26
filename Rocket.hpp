#pragma once
#include <limits>
#include <vector>
#include <fstream>

class Rocket
{
public:
    Rocket();  // Constructor: Initializes rocket with default values
    virtual ~Rocket();  // Destructor: Cleans up when rocket is destroyed

    void SetTriggerAge(int i);  // Set the age at which the rocket triggers
    void SetAgeLimit(int i);    // Set the rocket's age limit
    void SetPosition(Rocket &other);  // Set position from another rocket
    void SetPosition(float x, float y);  // Set rocket position using coordinates
    void SetForce(float x, float y);  // Set rocket force (speed in x and y directions)

    virtual void Draw();  // Draw the rocket (to be overridden)
    virtual void Step();  // Update rocket state (empty here, to be overridden)

    int GetAge();  // Get the current age of the rocket
    bool IsAlive();  // Check if rocket is alive (not exceeding age limit)
    bool IsTriggered();  // Check if rocket has triggered based on age

    static void SetGravity(float g);  // Set gravity for all rockets
    static void SetLogFile(std::ofstream *log_file);  // Set log file for output
    static void SetVector(std::vector<Rocket *> *rockets);  // Set the rocket vector

    virtual void Trigger();  // Trigger action for the rocket (to be overridden)

protected:
    int age;  // Age of the rocket
    int age_limit;  // Maximum age the rocket can reach
    int trigger_age;  // Age at which the rocket will trigger an action

    struct { float x, y; } position;  // Position of the rocket (x, y coordinates)
    struct { float x, y; } force;  // Force applied on the rocket (x, y speed)

    static float gravity;  // Gravity affecting all rockets
    static std::ofstream *log_file;  // File to log information
    static std::vector<Rocket *> *rockets;  // Vector holding all rocket objects
};
