#pragma once
#include <fmt/core.h>
#include "skill.h"
#include "registry.h"
class Goto: public Skill{
public:
    void execute(const TaskT& task) override{
        fmt::print("Skill Goto execute-({},{})\n",task.tx,task.ty);
    }
    void plan(const TaskT& task) override{
        fmt::print("Skill Goto plan-({},{})\n",task.tx,task.ty);
    }
    static Skill* create(){
        return new Goto();
    }
};
REGISTER_SKILL(Goto,Goto::create);
