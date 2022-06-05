#ifndef __REGISTRY_H__
#define __REGISTRY_H__
#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include "skill.h"
#define REGISTER_SKILL(name,create_func) \
    bool name##_entry = SkillRegistry<Skill>::add(#name,(create_func))

template <typename T>
class SkillRegistry{
public:
    using FactoryFunction = std::function<T*()>;
    using FactoryMap = std::unordered_map<std::string, FactoryFunction>;
    static bool add(const std::string& name, FactoryFunction fac){
        auto&& map = getFactoryMap();
        if(map.find(name) != map.end()){
            return false;
        }
        map[name] = fac;
        return true;
    }
    static T* create(const std::string& name){
        auto&& map = getFactoryMap();
        if(map.find(name) == map.end()){
            return nullptr;
        }
        return map[name]();
    }
private:
    static FactoryMap& getFactoryMap() {
        static FactoryMap map;
        return map;
    }
};
#endif // __REGISTRY_H__
