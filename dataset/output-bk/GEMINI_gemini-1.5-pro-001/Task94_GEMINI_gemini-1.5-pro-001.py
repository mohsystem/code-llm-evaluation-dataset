import sys

def main():
    if len(sys.argv) < 2:
        print("Usage: python sort_key_value.py <filename>")
        sys.exit(1)

    filename = sys.argv[1]
    keyValueMap = {}

    try:
        with open(filename, 'r') as file:
            for line in file:
                # Assuming key and value are separated by a space " "
                parts = line.strip().split(" ", 1)
                if len(parts) == 2:
                    key, value = parts
                    keyValueMap[key] = value
                else:
                    print(f"Invalid format on line: {line.strip()}")

        # Sort and print key-value pairs
        for key in sorted(keyValueMap.keys()):
            print(f"{key} {keyValueMap[key]}")

    except FileNotFoundError:
        print(f"Error: File not found: {filename}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()