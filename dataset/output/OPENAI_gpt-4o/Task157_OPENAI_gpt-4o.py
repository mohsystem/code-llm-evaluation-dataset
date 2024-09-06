import ctypes

def main():
    # Allocate memory for an integer
    int_ptr = ctypes.pointer(ctypes.c_int(10))
    print(f"Value at allocated memory: {int_ptr.contents.value}")
    
    # Deallocate memory
    del int_ptr

if __name__ == "__main__":
    main()