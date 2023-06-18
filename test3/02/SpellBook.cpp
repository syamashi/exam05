#include "SpellBook.hpp"

SpellBook::SpellBook(){
}

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
  if (book.count(aspell->getName()) == 0)
  book[aspell->getName()] = aspell->clone();
}
void SpellBook::forgetSpell(std::string const &name){
  if (book.count(name) == 0) return;
  free(book[name]);
  book.erase(name);
}
ASpell* SpellBook::createSpell(std::string const &name){
  if (book.count(name) == 0) return NULL;
  return book[name];
}
