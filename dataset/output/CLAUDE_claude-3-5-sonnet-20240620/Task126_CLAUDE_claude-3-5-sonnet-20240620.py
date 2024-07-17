
import webbrowser

def redirect_user():
    print("Select a destination:")
    print("1. Google")
    print("2. YouTube")
    print("3. Wikipedia")
    print("4. GitHub")

    choice = input("Enter your choice (1-4): ")

    if choice == \'1\':
        webbrowser.open(\'https://www.google.com\')
    elif choice == \'2\':
        webbrowser.open(\'https://www.youtube.com\')
    elif choice == \'3\':
        webbrowser.open(\'https://www.wikipedia.org\')
    elif choice == \'4\':
        webbrowser.open(\'https://www.github.com\')
    else:
        print("Invalid choice. Please try again.")

if __name__ == "__main__":
    redirect_user()
