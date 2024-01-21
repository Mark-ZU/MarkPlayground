#pragma once

struct TaskT{
    double tx;
    double ty;
};
class Skill{
public:
    virtual bool plan(const TaskT& t) { return subTask() ? subTask()->plan(t) : false;}
    virtual bool execute(const TaskT& t) { return subTask() ? subTask()->execute(t) : false;}
    void setSubTask(Skill* sub_task){ m_sub_task = sub_task;}
    Skill* subTask() const { return m_sub_task;}
private:
    Skill* m_sub_task = nullptr;
};