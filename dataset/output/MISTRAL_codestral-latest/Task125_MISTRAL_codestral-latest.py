# Python

resources = {
    'A': 'Resource A',
    'B': 'Resource B',
    'C': 'Resource C'
}

user_input = input('Enter a key to access a resource: ')

if user_input in resources:
    print('Access granted to:', resources[user_input])
else:
    print('Access denied.')