# Simple script that converts a space delimited dataset to a comma separated one

import numpy as np
import sys.argv as argv
import sys.exit as exit

def convertToCSV(filename):
  data = np.genfromtxt(filename, delimiter=' ')
  np.savetxt(filename, data, delimiter=",")

if __name__ == "__main__":
  if len(argv)!=2:
    print("Usage: ./augment inputFileName")
    exit()
  convertToCSV(argv[1])
