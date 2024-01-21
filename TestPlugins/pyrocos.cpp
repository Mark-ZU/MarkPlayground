#include <string>
#include <iostream>
#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "__a_skills.h"
void test_skill(const std::string& name){
    std::cout << "in test_skill function : " << name << std::endl;
}
bool execute_skill(const std::string& name, const double tx, const double ty){
    auto pSkill = SkillRegistry<Skill>::create(name);
    if(pSkill == nullptr){
        std::cout << "Skill " << name << " not exist, please check again" << std::endl;
        return false;
    }
    auto s = std::unique_ptr<Skill>(pSkill);
    return s->plan(TaskT{tx,ty});
}
// a function return list of string for python
std::vector<std::string> get_skill_list(){
    std::vector<std::string> skill_list;
    return SkillRegistry<Skill>::getSkillList();
}

PYBIND11_MODULE(pyrocos,m){
    m.doc() = "pyrocos";
    m.def("test_skill",&test_skill,"test_skill function",
          pybind11::arg("name")="default name");
    m.def("execute_skill",&execute_skill,"execute_skill",
          pybind11::arg("name")="default name",
          pybind11::arg("tx")=0.0,
          pybind11::arg("ty")=0.0);
    m.def("get_skill_list",&get_skill_list,"get_skill_list");
    m.attr("__VERSION__") = "v0.0.1-alpha";
}
