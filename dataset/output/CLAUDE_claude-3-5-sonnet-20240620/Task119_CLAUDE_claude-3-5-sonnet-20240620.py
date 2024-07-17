
import csv

def process_csv(filename):
    with open(filename, \'r\') as file:
        csv_reader = csv.reader(file)
        for row in csv_reader:
            print(\'\\t\'.join(row))

if __name__ == "__main__":
    process_csv("data.csv")
