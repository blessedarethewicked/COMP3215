import numpy as np
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
matplotlib.rcParams['font.size'] = 8.0


f = open("testcase2/testcase2edf.txt", "r")
tick_counter = 0
executes = []
completes = []
misses = []
executing = []

print("test")
end_of_file = '------------------------'
for line in f:
    task_action =''
    tick = ''
    try:
        tick,word_task,task_id,task_action =line.split()
        # print(tick+" "+ task_action)
    except:
        pass
    if task_action=="executes":
        executes = np.append(executes,tick)
    elif task_action=="completes":
        completes = np.append(completes,int(tick))
                
    elif task_action=="misses":
        misses = np.append(misses,int(tick))
        
    elif task_action=="executing":
        executing = np.append(executing,int(tick))

    try:

        if tick_counter<int(tick):

            tick_counter=tick
    except:
        pass  

# print(completes.shape[0])
# print(completes)
completes=np.hstack((completes,np.zeros(executes.shape[0]-completes.shape[0])))
misses=np.hstack((misses,np.zeros(executes.shape[0]-misses.shape[0])))
executing=np.hstack((executing,np.zeros(executes.shape[0]-executing.shape[0])))
# misses=np.resize(misses,(executes.shape[0],))
# executing=np.resize(executing,(executes.shape[0],))

# print(completes)
print(executes.shape)
print(completes.shape)
print(misses.shape)
print(executing.shape)



data1 = np.vstack((executes,completes))
data2 = np.vstack((misses,executing))
# the order is executes,completes, misses and executing respectively



data = np.vstack((data1,data2))
data = np.array(data).astype(np.float)
data = np.array(data).astype(np.int)
print(type(data[0][0]))



# set different colors for each set of positions
colors1 = ['C{}'.format(i) for i in range(data.shape[0])]

# set different line properties for each set of positions
# note that some overlap
lineoffsets1 = np.array([-4,-2,2,4]) # this changes the offsets of the line
# lineoffsets1 = np.zeros(data.shape[0]) # this changes the offsets of the line
linelengths1 = [3] #this changes the sizes of the lines
linelengths1 = np.resize(linelengths1,(data.shape[0],))

print(data.shape)

# fig, axs = plt.subplots(2, 2) #this tells it to make four plots in a 2 by 2 grid

# create a horizontal plot
plt.eventplot(data, colors=colors1, lineoffsets=lineoffsets1,
                    linelengths=linelengths1)
plt.xticks(np.arange(0, np.amax(data)+1, step=1))
plt.legend(colors1)


plt.savefig('test.png')
plt.show()
