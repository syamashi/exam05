#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(std::string const &type){
  this->type = type;
}
ATarget::ATarget(ATarget const &a){
  *this = a;
}
ATarget &ATarget::operator=(ATarget const &a){
  if (this != &a){
    this->type = a.type;
  }
  return *this;
}
ATarget::~ATarget(){}
std::string const &ATarget::getType() const{ return this->type; }

void ATarget::getHitBySpell(ASpell const &aspell) const{
  std::cout << this->type << " has been " << aspell.getEffects() << "!" << std::endl;
}
