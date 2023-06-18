#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title){
  this->name = name;
  this->title = title;
  std::cout << this->name << ": This looks like another boring day.\n";
}
Warlock::~Warlock(){
  std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const{
  return this->name;
}
std::string const &Warlock::getTitle() const{
  return this->title;
}
void Warlock::setTitle(std::string const &title){
  this->title = title;
}
void Warlock::introduce() const{
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *aspell_ptr){
  if (aspell_ptr){
    arr[aspell_ptr->getName()] = aspell_ptr->clone();
  }
}
void Warlock::forgetSpell(std::string name){
  if (arr.count(name)){
    delete arr.find(name)->second;
  }
  arr.erase(name);
}
void Warlock::launchSpell(std::string name, ATarget const &atarget_ref){
  if (arr.count(name)){
    arr[name]->launch(atarget_ref);
  }
}