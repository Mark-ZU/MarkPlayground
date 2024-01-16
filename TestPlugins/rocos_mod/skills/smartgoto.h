#pragma once
#include <fmt/core.h>
#include "skill.h"
#include "registry.h"
class SmartGoto: public Skill{
public:
    void execute(const TaskT& task) override{
        fmt::print("Skill SmartGoto execute-({},{})\n",task.tx,task.ty);
    }
    void plan(const TaskT& task) override{
        fmt::print("Skill SmartGoto plan-({},{})\n",task.tx,task.ty);
    }
    static Skill* create(){
        return new SmartGoto();
    }
};
REGISTER_SKILL(SmartGoto,SmartGoto::create);
