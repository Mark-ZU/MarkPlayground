#ifndef __SKILL_GOTO_H__
#define __SKILL_GOTO_H__
#include <fmt/core.h>
#include "skill.h"
#include "registry.h"
class Goto: public Skill{
public:
    void execute(){
        fmt::print("Skill goto execute\n");
    }
    void plan(){
        fmt::print("Skill goto plan\n");
    }
    static Skill* create(){
        return new Goto();
    }
};
REGISTER_SKILL(Goto,Goto::create);
#endif // __SKILL_GOTO_H__
