#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook(){
  std::map<std::string, ASpell*>::iterator it = book.begin();
  std::map<std::string, ASpell*>::iterator end = book.end();
  while(it != end){
    delete it->second;
    ++it;
  }
  book.clear();
}
void SpellBook::learnSpell(ASpell *aspell){
  if (book.count(aspell->getName())) return;
  book[aspell->getName()] = aspell->clone();
}
void SpellBook::forgetSpell(std::string const &spell_name){
  if (book.count(spell_name) == 0) return;
  delete book[spell_name];
  book.erase(spell_name);
}
ASpell* SpellBook::createSpell(std::string const &spell_name){
  if (book.count(spell_name) == 0) return NULL;
  return book[spell_name];
}
