# Python
import ctypes

# Allocate memory
size = 100
libc = ctypes.CDLL(None)
c_malloc = libc.malloc
c_malloc.argtypes = [ctypes.c_size_t]
c_malloc.restype = ctypes.c_void_p

memory = c_malloc(size)

# Deallocate memory
c_free = libc.free
c_free.argtypes = [ctypes.c_void_p]
c_free(memory)