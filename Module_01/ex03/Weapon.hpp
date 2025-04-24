#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);

        void    setType(const std::string& type);
        const std::string& getType() const;

};

#endif