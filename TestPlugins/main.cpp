#include <memory>
#include <iostream>
#include "goto.h"

int main(){
    auto s = std::unique_ptr<Skill>(SkillRegistry<Skill>::create("Goto"));
    s->execute();
    return 0;
}
