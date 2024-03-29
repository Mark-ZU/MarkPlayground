#pragma once
#include <fmt/core.h>
#include "skill.h"
#include "registry.h"
class SmartGoto: public Skill{
public:
    bool execute(const TaskT& task) override{
        fmt::print("Skill SmartGoto execute-({},{})\n",task.tx,task.ty);
        return true;
    }
    bool plan(const TaskT& task) override{
        fmt::print("Skill SmartGoto plan-({},{})\n",task.tx,task.ty);
        setSubTask(SkillRegistry<Skill>::create("Goto"));
        Skill::plan(task);
        return true;
    }
    static Skill* create(){
        return new SmartGoto();
    }
};
REGISTER_SKILL(SmartGoto,SmartGoto::create);
