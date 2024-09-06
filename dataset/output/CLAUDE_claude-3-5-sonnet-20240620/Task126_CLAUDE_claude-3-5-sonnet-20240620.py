
import webbrowser

def redirect_user():
    print("Select a destination:")
    print("1. Google")
    print("2. YouTube")
    print("3. Wikipedia")
    
    choice = input("Enter your choice (1-3): ")
    
    if choice == '1':
        webbrowser.open('https://www.google.com')
    elif choice == '2':
        webbrowser.open('https://www.youtube.com')
    elif choice == '3':
        webbrowser.open('https://www.wikipedia.org')
    else:
        print("Invalid choice. Please try again.")

if __name__ == "__main__":
    redirect_user()
