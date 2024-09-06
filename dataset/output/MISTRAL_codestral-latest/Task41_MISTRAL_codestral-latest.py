# Python
def process_string(input_string):
    # Process the string here
    print(f'Processed string: {input_string}')

# Safe from buffer overflow as Python handles memory management automatically
input_string = input('Enter a string: ')
process_string(input_string)