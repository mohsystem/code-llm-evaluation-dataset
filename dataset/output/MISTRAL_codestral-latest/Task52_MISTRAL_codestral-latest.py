# Python
def caesar_cipher(shift, input_file, output_file):
    with open(input_file, 'r') as file:
        data = file.read()
    result = ''
    for character in data:
        if character.isalpha():
            ascii_offset = ord('a') if character.islower() else ord('A')
            character = chr((ord(character) - ascii_offset + shift) % 26 + ascii_offset)
        result += character
    with open(output_file, 'w') as file:
        file.write(result)

if __name__ == "__main__":
    shift = int(input("Enter the shift value: "))
    input_file = input("Enter the input file path: ")
    output_file = input("Enter the output file path: ")
    caesar_cipher(shift, input_file, output_file)