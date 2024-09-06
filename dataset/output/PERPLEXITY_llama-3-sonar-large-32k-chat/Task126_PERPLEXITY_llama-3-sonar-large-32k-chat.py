code here:
import webbrowser

def redirect_user():
    user_input = input("Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'youtube' to go to YouTube: ")
    if user_input == 'google':
        webbrowser.open('https://www.google.com')
    elif user_input == 'facebook':
        webbrowser.open('https://www.facebook.com')
    elif user_input == 'youtube':
        webbrowser.open('https://www.youtube.com')
    else:
        print("Invalid input. Please try again.")

redirect_user()