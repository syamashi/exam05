#pragma once

#include <iostream>

class ATarget;
class ASpell{
  protected:
    std::string name;
    std::string effects;

  public:
    ASpell();
    ASpell(std::string const &name, std::string const &effects);
    ASpell(ASpell const &);
    ASpell &operator=(ASpell const &);
    virtual ~ASpell();
    std::string const &getName() const;
    std::string const &getEffects() const;
    virtual ASpell *clone() const = 0;

    void launch(ATarget const &atarget) const;
};
#include "ATarget.hpp"