f = open("testcase1/testcase1edf.txt", "r")
line_id = 0
print("test")
for line in f:
    if line_id ==0:
        pass
    else:
        task_id,task_ex,task_period =line.split()
        # print(split(line))
        print(task_id)
    line_id +=1

