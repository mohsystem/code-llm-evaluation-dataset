
import sys

def read_and_sort_records(filename):
    records = {}
    try:
        with open(filename, 'r') as file:
            for line in file:
                key, value = line.strip().split(':', 1)
                records[key.strip()] = value.strip()
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return
    except ValueError:
        print("Error: Invalid file format. Each line should be 'key: value'.")
        return

    sorted_records = dict(sorted(records.items()))
    
    for key, value in sorted_records.items():
        print(f"{key}: {value}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
    else:
        read_and_sort_records(sys.argv[1])
