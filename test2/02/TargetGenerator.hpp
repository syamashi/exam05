#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator{
  private:
    std::map<std::string, ATarget*> targets;
    TargetGenerator(TargetGenerator const &);
    TargetGenerator &operator=(TargetGenerator const &);

  public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget* atarget);
    void forgetTargetType(std::string const &type);
    ATarget* createTarget(std::string const &type);
};