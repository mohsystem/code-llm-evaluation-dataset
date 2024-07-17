def main():
    n = int(input("Enter number of strings to concatenate:
"))
    result = ""
    
    for i in range(n):
        str = input(f"Enter string {i + 1}:
")
        result += str
    
    print(f"Concatenated string: {result}")

if __name__ == "__main__":
    main()