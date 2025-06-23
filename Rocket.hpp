#ifndef ROCKET_HPP
#define ROCKET_HPP

#include <vector>

struct Position {
    float x, y;
};

class Rocket {
public:
    static float gravity;  // Global gravity for all rockets

    // Constructor and Destructor
    Rocket();
    virtual ~Rocket();

    // Setters and Getters
    void SetTriggerAge(int i);
    void SetAgeLimit(int i);
    void SetPosition(float x, float y);
    void SetPosition(Rocket &other);
    void SetForce(float x, float y);

    // Position and Force Getters
    Position GetPosition() const { return position; }  // Getter for position

    // Core functionalities
    virtual void Draw() = 0;  // Draw function, virtual for derived classes
    virtual void Trigger(std::vector<Rocket*>& v);  // Trigger a new rocket

    void Step(std::vector<Rocket*>& v);  // Update rocket position and age
    bool IsAlive();  // Check if rocket is alive based on age limit
    bool IsTriggered();  // Check if rocket is triggered based on its age

    // Set global gravity for all rockets
    static void SetGravity(float g);

protected:
    Position position;
    Position force;
    int age;
    int age_limit;
    int trigger_age;

private:
    // These can be set in constructors and modified using setters
    void SetAgeLimit(int i);
    void SetTriggerAge(int i);
    void SetPosition(float x, float y);
    void SetForce(float x, float y);
};

#endif
