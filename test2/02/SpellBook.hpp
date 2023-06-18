#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook{
  private:
    std::map<std::string, ASpell*> book;
    SpellBook(SpellBook const &);
    SpellBook &operator=(SpellBook const &);

  public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell* aspell);
    void forgetSpell(std::string const &name);
    ASpell* createSpell(std::string const &name);
};