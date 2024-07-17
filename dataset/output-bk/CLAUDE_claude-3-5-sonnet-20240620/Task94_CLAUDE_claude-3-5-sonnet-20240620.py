
import sys

def sort_key_value_file(filename):
    sorted_dict = {}
    
    try:
        with open(filename, \'r\') as file:
            for line in file:
                line = line.strip()
                if \':\' in line:
                    key, value = line.split(\':\', 1)
                    sorted_dict[key.strip()] = value.strip()
    except IOError:
        print(f"Error: Unable to read file \'{filename}\'")
        return

    for key in sorted(sorted_dict.keys()):
        print(f"{key}: {sorted_dict[key]}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
    else:
        sort_key_value_file(sys.argv[1])
