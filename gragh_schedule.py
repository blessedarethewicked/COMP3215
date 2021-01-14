"""
==============
Eventplot Demo
==============

An eventplot showing sequences of events with various line properties.
The plot is shown in both horizontal and vertical orientations.
"""

import matplotlib.pyplot as plt
import numpy as np
import matplotlib
matplotlib.rcParams['font.size'] = 8.0

# Fixing random state for reproducibility
np.random.seed(19680801)


# create random data
data1 = np.random.random([6, 50])
# print(data1.shape)
# print(data1)



# set different colors for each set of positions
colors1 = ['C{}'.format(i) for i in range(6)]

# set different line properties for each set of positions
# note that some overlap
lineoffsets1 = np.array([-15, -10, -5, 5, 10, 15]) # this changes the offsets of the line
linelengths1 = [3, 3, 3, 3, 3, 3] #this changes the sizes of the lines

# fig, axs = plt.subplots(2, 2) #this tells it to make four plots in a 2 by 2 grid

# create a horizontal plot
plt.eventplot(data1, colors=colors1, lineoffsets=lineoffsets1,
                    linelengths=linelengths1)


plt.savefig('test.png')
plt.show()