#include "SpellBook.hpp"
SpellBook::SpellBook(){}
SpellBook::~SpellBook(){
  std::map<std::string, ASpell *>::iterator it = this->arr_spell.begin();
  std::map<std::string, ASpell *>::iterator it_end = this->arr_spell.end();
  while (it != it_end){
    delete it->second;
    ++it;
  }
  this->arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *aspell_ptr){
  arr_spell[aspell_ptr->getName()] = aspell_ptr->clone();
}
void SpellBook::forgetSpell(std::string const &name){
  if (arr_spell.count(name)){
    delete arr_spell[name];
  }
  arr_spell.erase(name);
}
ASpell* SpellBook::createSpell(std::string const &name){
  if (!arr_spell.count(name)) return NULL;
  return arr_spell[name];
}