import ctypes

# Allocate memory for an integer 
my_var = ctypes.c_int(42)
print(f"Python: Value = {my_var.value}")

# Deallocate memory
del my_var