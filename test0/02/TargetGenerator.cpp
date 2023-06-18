#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){
  std::map<std::string, ATarget *>::iterator it = arr_target.begin();
  std::map<std::string, ATarget *>::iterator it_end = arr_target.end();
  while (it != it_end){
    delete it->second;
    ++it;
  }
  arr_target.clear();
}

void TargetGenerator::learnTargetType(ATarget *atarget){
  arr_target[atarget->getType()] = atarget->clone();
}
void TargetGenerator::forgetTargetType(std::string const &type){
  if (arr_target.count(type)){
    delete arr_target[type];
    arr_target.erase(type);
  }
}
ATarget* TargetGenerator::createTarget(std::string const &type){
  if (arr_target.count(type)){
    return arr_target[type];
  }
  return NULL;
}
