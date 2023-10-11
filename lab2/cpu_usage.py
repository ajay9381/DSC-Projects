from matplotlib import pyplot as plt
import numpy as np
# storing data
data = np.loadtxt('CPUData.dat')
x = data[:,0]
y = data[:,1]

#Creating  plot
plt.plot(x,y,'r--',label=".dat file Data")
plt.legend(loc='upper left')

#Adding labels
plt.xlabel("Unix Coordinate Time")
plt.ylabel("CPU Usage")
plt.title('CPU Usage vs Time')
plt.legend()

#saving the plot as an image
plt.savefig('cpuTime.png')
