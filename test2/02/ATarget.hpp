#pragma once
#include <iostream>

class ASpell;
class ATarget{
  protected:
    std::string type;
    
  public:
    ATarget();
    ATarget(std::string const &type);
    virtual ~ATarget();
    ATarget(ATarget const &);
    ATarget &operator=(ATarget const &);
    
    std::string const &getType() const;

    virtual ATarget *clone() const = 0;

    void getHitBySpell(ASpell const &atarget) const;
};
#include "ASpell.hpp"