import sys

def read_and_sort(filename):
    records = []
    with open(filename, 'r') as file:
        for line in file:
            key, value = line.strip().split()
            records.append((key, value))
    sorted_records = sorted(records, key=lambda x: x[0])
    for record in sorted_records:
        print(f"{record[0]} {record[1]}")

if __name__ == "__main__":
    filename = sys.argv[1]
    read_and_sort(filename)