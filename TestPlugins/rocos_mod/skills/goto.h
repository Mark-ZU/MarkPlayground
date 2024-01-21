#pragma once
#include <fmt/core.h>
#include "skill.h"
#include "registry.h"
class Goto: public Skill{
public:
    bool execute(const TaskT& task) override{
        fmt::print("Skill Goto execute-({},{})\n",task.tx,task.ty);
        return true;
    }
    bool plan(const TaskT& task) override{
        fmt::print("Skill Goto plan-({},{})\n",task.tx,task.ty);
        return true;
    }
    static Skill* create(){
        return new Goto();
    }
};
REGISTER_SKILL(Goto,Goto::create);
