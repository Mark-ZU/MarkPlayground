#include <memory>
#include <iostream>
#include "__a_skills.h"
int main(){
    auto s = std::unique_ptr<Skill>(SkillRegistry<Skill>::create("Goto"));
    TaskT task{1.0,-1.0};
    s->execute(task);
    return 0;
}
