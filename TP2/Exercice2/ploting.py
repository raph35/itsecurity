#!/usr/bin/python

import csv
import matplotlib.pyplot as plt
steelBlue = [0.2,0.5,1]
yellow = [1,0.8,0.2]

with open('output.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile, delimiter=',', quotechar='|')
    iter = reader.next()
    timeaccess = reader.next()
    timeaccessWithflush = reader.next()

plt.scatter(iter,timeaccess,c=yellow)
plt.scatter(iter,timeaccessWithflush,c=steelBlue)
plt.show()