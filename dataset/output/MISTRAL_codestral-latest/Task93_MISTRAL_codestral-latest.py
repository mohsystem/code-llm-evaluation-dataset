# Python

def read_and_sort_file(file_path):
    with open(file_path, 'r') as file:
        records = [line.strip().split('=') for line in file]
        records.sort()
        return records

# Usage
sorted_records = read_and_sort_file('path_to_your_file.txt')
print(sorted_records)