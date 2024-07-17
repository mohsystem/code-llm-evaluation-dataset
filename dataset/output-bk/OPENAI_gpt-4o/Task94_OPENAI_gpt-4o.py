def main():
    with open("records.txt") as file:
        lines = file.readlines()
    
    lines.sort()
    
    for line in lines:
        print(line.strip())

if __name__ == "__main__":
    main()