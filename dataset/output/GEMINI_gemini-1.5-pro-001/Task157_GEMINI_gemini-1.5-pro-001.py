import ctypes

# Allocate memory
memory = ctypes.cast(ctypes.create_string_buffer(1024), ctypes.POINTER(ctypes.c_int))

# Use memory (example)
memory[0] = 10

# Deallocate memory
ctypes.free(memory)