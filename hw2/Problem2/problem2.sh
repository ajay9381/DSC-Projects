#!/bin/bash
#----------------------------------------------------
#SBATCH -J myjob # Job name
#SBATCH -o myjob.out # Name of stdout output file
#SBATCH -e myjob.err # Name of stderr error file
#SBATCH -p shared # Queue (partition) name
#SBATCH -N 1 # Total # of nodes (must be 1 for serial)
#SBATCH -n 1 # Total # of cores to use
#SBATCH -t 00:05:00 # Run time (hh:mm:ss)
#SBATCH -A SEE230009 # Name of class allocation
#SBATCH --mail-user=apadala@umassd.edu
#SBATCH --mail-type=all # Send email at begin and end of job

./P2
