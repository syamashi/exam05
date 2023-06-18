#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator{
  private:
    TargetGenerator(TargetGenerator const &other);
    TargetGenerator& operator=(TargetGenerator const &);
    std::map<std::string, ATarget *> targets;
  
  public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget *atarget);
    void forgetTargetType(std::string const &type);
    ATarget* createTarget(std::string const &type);
};