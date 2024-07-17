choice = input("Enter your destination (A/B/C): ")

if choice.upper() == 'A':
    print("https://www.exampleA.com")
elif choice.upper() == 'B':
    print("https://www.exampleB.com")
elif choice.upper() == 'C':
    print("https://www.exampleC.com")
else:
    print("Invalid choice.")