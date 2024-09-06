
import csv

def process_csv(file_path):
    with open(file_path, 'r') as file:
        csv_reader = csv.reader(file)
        header = next(csv_reader)
        print(f"CSV Header: {header}")
        
        for row in csv_reader:
            print(f"Row: {row}")

if __name__ == "__main__":
    file_path = "example.csv"
    process_csv(file_path)
