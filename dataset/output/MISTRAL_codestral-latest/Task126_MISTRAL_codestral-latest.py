def redirect_user(input):
    if input == 'home':
        print('Redirecting to home page...')
    elif input == 'about':
        print('Redirecting to about page...')
    elif input == 'contact':
        print('Redirecting to contact page...')
    else:
        print('Invalid input. Staying on current page.')

# Test the function
redirect_user('about')