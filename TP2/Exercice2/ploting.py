#!/usr/bin/python3

import csv
import matplotlib.pyplot as plt

def plot(fileName):
    with open(fileName, 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_NONNUMERIC)
        x = next(reader)
        y = next(reader)
        z = next(reader)

    fig = plt.figure()
    ax = fig.add_axes([0.1,0.1,0.8,0.8])
    ax.scatter(x,y, c="#D22B14")
    ax.scatter(x,z, c="#4682b4")
    ax.set_xlabel('iteration counter')
    ax.set_ylabel('mesured access time')
    ax.set_title('Time access of the pointer')
    ax.legend(labels = ['without flush', 'with flush'], loc = 'upper right')
    plt.show()

plot('output.csv')