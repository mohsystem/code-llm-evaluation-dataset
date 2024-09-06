# Python
def redirect_user(user_input):
    if user_input == 'home':
        print('Redirecting to home page...')
    elif user_input == 'about':
        print('Redirecting to about page...')
    elif user_input == 'contact':
        print('Redirecting to contact page...')
    else:
        print('Invalid input. Redirecting to default page...')

# Test the function
redirect_user('about')