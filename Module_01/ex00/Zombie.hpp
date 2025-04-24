#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;
    
public:
    Zombie(std::string name);
    ~Zombie(void);

    void announce(void);
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);



#endif