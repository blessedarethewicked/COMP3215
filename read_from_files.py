import numpy as np


f = open("testcase2/testcase2edf.txt", "r")
line_id = 0
executes = []
completes = []
misses = []
executing = []

print("test")
end_of_file = '------------------------'
for line in f:
    task_action =''
    try:
        tick,word_task,task_id,task_action =line.split()
        # print(tick+" "+ task_action)
    except:
        print('not a valid line')
    if task_action=="executes":
        executes = np.append(executes,tick)
    elif task_action=="completes":
        completes = np.append(completes,tick)
                
    elif task_action=="misses":
        misses = np.append(misses,tick)
        
    elif task_action=="executing":
        executing = np.append(executing,tick)

    if line_id<tick:
        link_id=tick   
    line_id +=1

data = np.array[executes,completes,misses,executing]
print(data.shape)
print(data)

