def main():
    with open("data.txt", "r") as file:
        records = file.readlines()

    records.sort()

    with open("sorted_data.txt", "w") as file:
        for record in records:
            file.write(record)

if __name__ == "__main__":
    main()