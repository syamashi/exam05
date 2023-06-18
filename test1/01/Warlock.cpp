#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title){
  this->name = name;
  this->title = title;
  std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock(){
  std::cout << this->name << ": My job here is done!" << std::endl;
  std::map<std::string, ASpell*>::iterator it = book.begin();
  std::map<std::string, ASpell*>::iterator end = book.end();
  while(it != end){
    delete it->second;
    ++it;
  }
  book.clear();
}
std::string const &Warlock::getName() const{return this->name;}
std::string const &Warlock::getTitle() const{return this->title;}
void Warlock::setTitle(std::string const &title){this->title = title;}
void Warlock::introduce() const{
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *aspell){
  if (book.count(aspell->getName()) == 0){
    book[aspell->getName()] = aspell->clone();
  }
}
void Warlock::forgetSpell(std::string spell_name){
  if (book.count(spell_name) == 0) return;
  delete book[spell_name];
  book.erase(spell_name);
}
void Warlock::launchSpell(std::string spell_name, ATarget const &atarget){
  if (book.count(spell_name) == 0) return;
  (*book[spell_name]).launch(atarget);
}
