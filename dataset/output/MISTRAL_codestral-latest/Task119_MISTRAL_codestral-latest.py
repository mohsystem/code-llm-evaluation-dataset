# Python
import csv

with open('file.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    for row in reader:
        # Process row here
        pass