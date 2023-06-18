#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook{
  private:
    SpellBook(SpellBook const &other);
    SpellBook& operator=(SpellBook const &other);
    std::map<std::string, ASpell*> book;

  public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell *aspell);
    void forgetSpell(std::string const &spell_name);
    ASpell* createSpell(std::string const &spell_name);
};