#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
class SpellBook{
  private:
    SpellBook(SpellBook const &);
    SpellBook &operator=(SpellBook const &);
    std::map<std::string, ASpell*> book;

  public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *aspell);
    void forgetSpell(std::string const &name);
    ASpell* createSpell(std::string const &name);
};