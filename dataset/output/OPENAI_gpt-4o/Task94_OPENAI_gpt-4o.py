import sys

def read_file(filename):
    with open(filename, 'r') as file:
        records = [line.strip().split('=') for line in file]
    records.sort()
    return records

def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
        return
    
    filename = sys.argv[1]
    records = read_file(filename)
    for key, value in records:
        print(f"{key} = {value}")

if __name__ == "__main__":
    main()