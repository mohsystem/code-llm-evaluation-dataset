
import os

KEY = 0x42

def encrypt_decrypt(input_file, output_file):
    with open(input_file, \'rb\') as fin, open(output_file, \'wb\') as fout:
        while True:
            chunk = fin.read(1024)
            if not chunk:
                break
            encrypted_chunk = bytes([b ^ KEY for b in chunk])
            fout.write(encrypted_chunk)

def main():
    choice = input("Enter \'e\' to encrypt or \'d\' to decrypt: ")
    input_file = input("Enter input file name: ")
    output_file = input("Enter output file name: ")

    try:
        encrypt_decrypt(input_file, output_file)
        print("Operation completed successfully.")
    except IOError as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
