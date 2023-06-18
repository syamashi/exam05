#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {
  std::map<std::string, ATarget*>::iterator it = targets.begin();
  std::map<std::string, ATarget*>::iterator end = targets.end();
  while (it != end) {
    delete it->second;
    ++it;
  }
  targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* atarget) {
  if (targets.count(atarget->getType())) return;
  targets[atarget->getType()] = atarget->clone();
}
void TargetGenerator::forgetTargetType(std::string const& type) {
  if (targets.count(type) == 0) return;
  delete targets[type];
  targets.erase(type);
}
ATarget* TargetGenerator::createTarget(std::string const& type) {
  if (targets.count(type) == 0) return NULL;
  return targets[type];
}