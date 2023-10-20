import matplotlib.pyplot as plt
import numpy as np

# Load data from the file
data = np.loadtxt('output.txt')
N = data[:, 0]
integral = data[:, 1]

# Calculate the error
exact_integral = 2.0 / 3.0  # Exact integral of f(x) = x^2 from -1 to 1
error = np.abs(exact_integral - integral)

# Calculate log-log values
log_N = np.log(N)
log_error = np.log(error)

# Fit a line to the data using a linear regression
coefficients = np.polyfit(log_N, log_error, 1)
slope = -coefficients[0]  # The slope of the line

# Plot the log-log graph
plt.figure(figsize=(8, 6))
plt.loglog(N, error, marker='o', linestyle='-')
plt.xlabel('N (log scale)')
plt.ylabel('Error (log scale)')
plt.title('Log-Log Plot of N vs. Error')
plt.grid(True)

# Display the plot
plt.show()

print(f"Slope (C) of the line: {slope}")

