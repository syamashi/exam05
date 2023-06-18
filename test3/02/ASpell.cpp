#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(std::string const &name, std::string const &effects){
  this->name = name;
  this->effects = effects;
}
ASpell::ASpell(ASpell const &a){
  *this = a;
}
ASpell &ASpell::operator=(ASpell const &a){
  if (this != &a){
    this->name = a.name;
    this->effects = a.effects;
  }
  return *this;
}
ASpell::~ASpell(){}
std::string const &ASpell::getName() const{ return this->name; }
std::string const &ASpell::getEffects() const{ return this->effects; }

void ASpell::launch(ATarget const &atarget) const{
  atarget.getHitBySpell(*this);
}
