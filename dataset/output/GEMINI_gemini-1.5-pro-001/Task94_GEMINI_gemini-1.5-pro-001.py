import sys

def read_file_and_sort(file_path):
    """Reads a file containing key-value pairs and sorts them.

    Args:
        file_path (str): The path to the input file.

    Returns:
        list: A list of sorted key-value pairs.
    """
    key_value_pairs = []
    with open(file_path, 'r') as file:
        for line in file:
            key, value = line.strip().split(' ', 1)
            key_value_pairs.append((key, value))
    return sorted(key_value_pairs)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python your_script.py <file_path>")
        sys.exit(1)

    file_path = sys.argv[1]
    sorted_pairs = read_file_and_sort(file_path)
    for key, value in sorted_pairs:
        print(f"{key} {value}")