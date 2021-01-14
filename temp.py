import numpy as np
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
matplotlib.rcParams['font.size'] = 8.0

def task_to_data(dic,task_num):
    task = str(task_num)
    executes = []
    completes = []
    misses = []
    data=[]
    data=np.array(data)
    executes = np.array(executes)
    completes = np.array(completes)
    misses = np.array(misses)

    for k in range(0,len(dic)+1):
        # print(k)
        # try:
        #     print(dic[k][task]['action'])
        # except:
        #     pass
        try:
            if((dic[k][task]['action'] == 'executes')):
                executes=np.hstack((executes,k))
                
            elif((dic[k][task]['action'] == 'completes')):
                completes=np.hstack((completes,k))
                
            elif((dic[k][task]['action'] == 'misses')):
                misses=np.hstack((misses,k))
                # print('misses')
            elif((dic[k][task]['action'] == 'none')):
                pass
                # print('none')
        except:
            pass

        try:
            if((dic[k][task]['actions2'] == 'executes')):
                executes=np.hstack((executes,k))
            elif((dic[k][task]['actions2'] == 'completes')):
                completes=np.hstack((completes,k))
        except:
            pass

            # print('key not found')
    
    # make them the same shape
    try:
        completes=np.hstack((completes,np.zeros(executes.shape[0]-completes.shape[0])))
    except:
        pass
    
    try:
        misses=np.hstack((misses,np.zeros(executes.shape[0]-misses.shape[0])))
    except:
       pass
    
    # change them into data
    try:
        data1 = np.vstack((executes,completes))
    except:
        pass
    try:
        data = np.vstack((data1,misses))
    except:
        pass

    print(data)

    return data

print('enter the name of the file')
file_name = input()
print('enter the type of scheduling ')
file_type = input()
open_f = file_name + "/" + file_name + file_type+".txt"
print(open_f)
f = open(open_f, "r")
#[tick][task id][action]
time_line={}
number_of_tasks = 0
lcm = 0

# time_line[0][1]['action'] = 'comp'
# time_line[0][1]['action2'] = 'comp'
# time_line[0][2] = {'action': 'exs'}


# print(time_line[0])
end_of_file = '------------------------'
for line in f:
    # get the number of tasks
    try:
        task_num,word_is,word_the,word_number,word_of,word_task =line.split()
        if word_number=='number':
            number_of_tasks = task_num
            # print(number_of_tasks)
        if word_number=='lowest':
            lcm = task_num
            # print(lcm)

    except:
        pass

    task_action =''
    tick = ''
    # split the words so we can test them individual
    try:
        tick,word_task,task_id,task_action =line.split()
        
    except:
        pass

 
    # check how we need to affect the time
    if task_action=="misses":

        time_line[int(tick)] = {task_id:{'action': 'misses'}}
        
    elif task_action=="executes":

        try:
            if time_line[int(tick)][task_id]['action'] == 'misses':

                time_line[int(tick)][task_id]['actions2'] = 'executes'
        except:
            pass
        time_line[int(tick)] = {task_id:{'action': 'executes'}}
    elif task_action=="completes":

        try:
            if time_line[int(tick)][task_id]['action'] == 'executes':

                time_line[int(tick)][task_id]['actions2'] = 'completes'
        except:
            
            time_line[int(tick)] = {task_id:{'action': 'completes'}}
                
    elif task_action=="executing":

        time_line[int(tick)] = {task_id:{'action': 'none'}}
    
# for x in time_line:
#     print(x)
#     print(time_line[x])
task_id=[]

for i in range(1,int(number_of_tasks)+1):
    # this is sizes of the lines
    linelengths1 = [3]*(i*3)
    linewidths = [1,0.5,0.1]
    

    data = task_to_data(time_line,i)

    # the colours 
    colors1 = ['C{}'.format(k) for k in range(data.shape[0])]

    # the ofsets are dirrent for each task but the same within the task
    lineoffsets1 = np.ones(data.shape[0])*i*4

    linelengths1 = np.resize(linelengths1,(data.shape[0],))

    linewidths = np.resize(linewidths,(data.shape[0],))
    task_id= np.append(task_id,['task'+str(i)])

    # the last thing
    plt.eventplot(data, colors=colors1, lineoffsets=lineoffsets1,linewidths=linewidths,linelengths=linelengths1)

    
    plt.xticks(np.arange(0, np.amax(int(lcm))+1, step=1))

plt.title('task 1 is at the bottom and the take number inceases as you go up')
safe_f = file_name + "/" + file_name + file_type+".png"
plt.savefig(safe_f)
plt.show()