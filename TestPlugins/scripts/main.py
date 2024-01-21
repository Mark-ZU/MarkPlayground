import pyrocos as rocos
skills = rocos.get_skill_list()
print("all Skills : ",skills)
rocos.execute_skill("goto") # not exist, should got warning
rocos.execute_skill("Goto")
rocos.execute_skill("SmartGoto",2.0,-2.0)