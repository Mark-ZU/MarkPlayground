#include <string>
#include <iostream>
#include <memory>
#include <pybind11/pybind11.h>
#include "__a_skills.h"
void test_skill(const std::string& name){
    std::cout << "in test_skill function : " << name << std::endl;
}
void execute_skill(const std::string& name){
    auto pSkill = SkillRegistry<Skill>::create(name);
    if(pSkill == nullptr){
        std::cout << "Skill " << name << " not exist, please check again" << std::endl;
        return;
    }
    auto s = std::unique_ptr<Skill>(pSkill);
    s->execute();
}
PYBIND11_MODULE(pyrocos,m){
    m.doc() = "pyrocos";
    m.def("test_skill",&test_skill,"test_skill function",
          pybind11::arg("name")="default name");
    m.def("execute_skill",&execute_skill,"execute_skill",
          pybind11::arg("name")="default name");
    m.attr("__VERSION__") = "v0.0.1-alpha";
}
