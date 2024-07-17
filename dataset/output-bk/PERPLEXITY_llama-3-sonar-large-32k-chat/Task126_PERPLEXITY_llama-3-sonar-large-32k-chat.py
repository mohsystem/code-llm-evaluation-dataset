def redirect_user():
    user_input = input("Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'exit' to exit: ")
    if user_input == 'google':
        print("Redirecting to Google...")
    elif user_input == 'facebook':
        print("Redirecting to Facebook...")
    elif user_input == 'exit':
        print("Exiting...")
    else:
        print("Invalid input. Please try again.")
        redirect_user()

redirect_user()