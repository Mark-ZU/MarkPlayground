#ifndef __SKILL_H__
#define __SKILL_H__
class Skill{
public:
    virtual void plan() = 0;
    virtual void execute() = 0;
};
#endif // __SKILL_H__