import re

def read_file_and_sort(file_path):
    """Reads a file containing key-value pairs and sorts them by key.

    Args:
        file_path (str): The path to the input file.

    Returns:
        list: A list of sorted key-value pairs as tuples.
    """

    data = []
    with open(file_path, 'r') as file:
        for line in file:
            match = re.match(r'(.+)=(.+)', line.strip())
            if match:
                key, value = match.groups()
                data.append((key, value))

    sorted_data = sorted(data, key=lambda item: item[0])
    return sorted_data

if __name__ == '__main__':
    sorted_records = read_file_and_sort('input.txt')
    for key, value in sorted_records:
        print(f"{key}={value}")