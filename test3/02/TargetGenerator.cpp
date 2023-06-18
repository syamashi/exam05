#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){
}

TargetGenerator::~TargetGenerator(){
  std::map<std::string, ATarget*>::iterator it = book.begin();
  std::map<std::string, ATarget*>::iterator end = book.end();
  while(it != end){
    delete it->second;
    ++it;
  }
  book.clear();
}

void TargetGenerator::learnTargetType(ATarget *aspell){
  if (book.count(aspell->getType()) == 0)
  book[aspell->getType()] = aspell->clone();
}
void TargetGenerator::forgetTargetType(std::string const &name){
  if (book.count(name) == 0) return;
  free(book[name]);
  book.erase(name);
}
ATarget* TargetGenerator::createTarget(std::string const &name){
  if (book.count(name) == 0) return NULL;
  return book[name];
}
