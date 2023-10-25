import numpy as np
from matplotlib import pyplot as plt
x=np.loadtxt("rand_numbers.dat" )
plt.hist(x,bins=30)
plt.savefig("histogram_10000.png")
