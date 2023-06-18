#include "TargetGenerator.hpp"
TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){
  std::map<std::string, ATarget*>::iterator it = targets.begin();
  std::map<std::string, ATarget*>::iterator end = targets.end();
  while(it != end){
    delete it->second;
    ++it;
  }
  targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *atarget){
  if (this->targets.count(atarget->getType())) return;
  this->targets[atarget->getType()] = atarget->clone();
}
void TargetGenerator::forgetTargetType(std::string const &type){
  if (this->targets.count(type) == 0) return;
  delete this->targets[type];
  this->targets.erase(type);
}
ATarget* TargetGenerator::createTarget(std::string const &type){
  if (this->targets.count(type) == 0) return NULL;
  return this->targets[type];
}
