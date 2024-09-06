# Python
with open('file.txt', 'r') as file:
    lines = file.readlines()
    records = [line.strip().split('=') for line in lines]
    records.sort()
    for record in records:
        print('='.join(record))