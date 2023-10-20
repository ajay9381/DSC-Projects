#!/bin/bash

# Remove any existing data file
rm -f trapezoidal_data.txt

for ((i=1; i<=30; i++))
do
    N=$((2**i))
    echo "Running N = $N"

    # Replace 'your_program_name' with the actual name of your compiled C program
    if [ -f trap2.c ]; then
        ./trap2.c $N >> trapezoidal_data.txt
    else
        echo "Error: The program 'your_program_name' does not exist. Please replace it with the actual program name."
        exit 1
    fi
done

if [ -s trapezoidal_data.txt ]; then
    # Python script for log-log plot
    python << END
    import matplotlib.pyplot as plt
    import numpy as np

    data = np.loadtxt('trapezoidal_data.txt')
    N = data[:, 0]
    error = data[:, 1]

    # Calculate log-log values
    log_N = np.log(N)
    log_error = np.log(error)

    # Fit a line to the data using a linear regression
    coefficients = np.polyfit(log_N, log_error, 1)
    slope = -coefficients[0]

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
    END
else
    echo "Error: The 'trapezoidal_data.txt' file is empty. Please ensure that your C program is providing output."
fi

