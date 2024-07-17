import ctypes

libc = ctypes.CDLL(None)
libc.printf.argtypes = [ctypes.c_char_p]

def process_string_python(input_str):
    safe_str = input_str[:255]  # Limit the length of the input string
    libc.printf(b"You entered (Python): %s
", safe_str.encode('utf-8'))

# Hooking up with JNI
def processStringPython(env, obj, input):
    input_str = env.GetStringUTFChars(input, 0)
    process_string_python(input_str)
    env.ReleaseStringUTFChars(input, input_str)