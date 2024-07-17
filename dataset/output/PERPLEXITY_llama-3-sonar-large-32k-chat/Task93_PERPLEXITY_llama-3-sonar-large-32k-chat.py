with open("input.txt", "r") as file:
    records = [line.strip().split("-", 1) for line in file]
records.sort(key=lambda x: x[0])
for record in records:
    print(f"{record[0]}-{record[1]}")