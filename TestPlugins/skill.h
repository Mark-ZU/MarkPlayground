#ifndef __SKILL_H__
#define __SKILL_H__
struct TaskT{
    double tx;
    double ty;
};
class Skill{
public:
    virtual void plan(const TaskT&) = 0;
    virtual void execute(const TaskT&) = 0;
};
#endif // __SKILL_H__