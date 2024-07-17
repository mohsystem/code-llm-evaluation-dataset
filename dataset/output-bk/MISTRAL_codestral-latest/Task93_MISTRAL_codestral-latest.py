with open('file.txt', 'r') as file:
    lines = file.readlines()

records = {}
for line in lines:
    key, value = line.strip().split('=')
    records[key] = value

sorted_records = sorted(records.items())
for key, value in sorted_records:
    print(f'{key}={value}')