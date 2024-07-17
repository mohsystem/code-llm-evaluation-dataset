import csv

def process_csv(filename):
    with open(filename, newline='') as csvfile:
        csvreader = csv.reader(csvfile, delimiter=',')
        for row in csvreader:
            print(' '.join(row))

if __name__ == "__main__":
    process_csv('data.csv')