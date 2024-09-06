import ctypes

lib = ctypes.CDLL('./buffer_program.so')
buffer_size = 10

def main():
    print("Enter characters to fill the buffer:")
    for _ in range(buffer_size):
        char = input("Enter a character: ")
        lib.add_char(ctypes.c_char(char.encode('utf-8')))
    
    print("Buffer contents:")
    lib.print_buffer()

if __name__ == "__main__":
    main()