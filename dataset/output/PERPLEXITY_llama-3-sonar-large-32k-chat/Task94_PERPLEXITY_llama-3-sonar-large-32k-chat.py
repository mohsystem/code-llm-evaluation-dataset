code here:
f = open("input.txt", "r")
records = [line.strip().split("=") for line in f.readlines()]
records.sort()
for record in records:
    print("=".join(record))