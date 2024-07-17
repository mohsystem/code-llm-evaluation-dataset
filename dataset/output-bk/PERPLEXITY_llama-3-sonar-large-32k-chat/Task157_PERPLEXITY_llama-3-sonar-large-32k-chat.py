code here:
import ctypes

ptr = ctypes.pointer(ctypes.c_int(10))
print(ptr.contents.value)  # prints 10

ctypes.pointer(ctypes.c_int(20)).contents.value = 20
print(ptr.contents.value)  # prints 20