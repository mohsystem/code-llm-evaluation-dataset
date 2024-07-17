# Python
def main():
    map = {}
    with open('file.txt', 'r') as file:
        for line in file:
            parts = line.strip().split('=')
            if len(parts) == 2:
                map[parts[0]] = parts[1]

    for key in sorted(map.keys()):
        print(f'{key}={map[key]}')

if __name__ == '__main__':
    main()