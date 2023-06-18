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
  while (it != end){
    delete it->second;
    ++it;
  }
  book.clear();
}
std::string const &Warlock::getName() const{ return this->name; }
std::string const &Warlock::getTitle() const{ return this->title; }
void Warlock::setTitle(std::string const &title){
  this->title = title;
}

void Warlock::introduce() const{
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell* aspell){
  if (book.count(aspell->getName())) return;
  book[aspell->getName()] = aspell->clone();
}
void Warlock::forgetSpell(std::string name){
  if (book.count(name) == 0) return;
  delete book[name];
  book.erase(name);
}
void Warlock::launchSpell(std::string name, ATarget &atarget){
  if (book.count(name) == 0) return;
  book[name]->launch(atarget);
}
