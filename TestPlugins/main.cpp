#include <memory>
#include <iostream>
#include "__a_skills.h"
int main(){
    auto s = std::unique_ptr<Skill>(SkillRegistry<Skill>::create("Goto"));
    s->execute();
    return 0;
}
