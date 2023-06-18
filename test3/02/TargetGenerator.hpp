#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
class TargetGenerator{
  private:
    TargetGenerator(TargetGenerator const &);
    TargetGenerator &operator=(TargetGenerator const &);
    std::map<std::string, ATarget*> book;

  public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget *atarget);
    void forgetTargetType(std::string const &name);
    ATarget* createTarget(std::string const &name);
};