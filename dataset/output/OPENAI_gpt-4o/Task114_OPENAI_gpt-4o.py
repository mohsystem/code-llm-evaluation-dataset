import ctypes

# Java string operations using Jython
import java.lang.StringBuilder

# C++ string operations using C++ integration in Python
import cppyy

cppyy.cppdef('''
#include <string>
std::string cpp_copy_string(const std::string& s) {
    return s;
}
std::string cpp_concat_strings(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}
''')

# C string operations using ctypes
libc = ctypes.CDLL(None)

def c_copy_string(src):
    dest = ctypes.create_string_buffer(len(src) + 1)
    libc.strcpy(dest, src.encode('utf-8'))
    return dest.value.decode('utf-8')

def main():
    # Python string operations
    python_str = "Hello, Python!"
    python_copied_str = python_str[:]
    python_concatenated_str = python_str + " How are you?"

    # Java string operations
    java_str = java.lang.StringBuilder("Hello, Java!")
    java_copied_str = java_str.toString()[:]
    java_str.append(" How are you?")
    java_concatenated_str = java_str.toString()

    # C++ string operations
    cpp_str = "Hello, C++!"
    cpp_copied_str = cppyy.gbl.cpp_copy_string(cpp_str)
    cpp_concatenated_str = cppyy.gbl.cpp_concat_strings(cpp_str, " How are you?")

    # C string operations
    c_str = "Hello, C!"
    c_copied_str = c_copy_string(c_str)
    c_concatenated_str = c_str + " How are you?"

    print(f"Python copied string: {python_copied_str}")
    print(f"Python concatenated string: {python_concatenated_str}")
    print(f"Java copied string: {java_copied_str}")
    print(f"Java concatenated string: {java_concatenated_str}")
    print(f"C++ copied string: {cpp_copied_str}")
    print(f"C++ concatenated string: {cpp_concatenated_str}")
    print(f"C copied string: {c_copied_str}")
    print(f"C concatenated string: {c_concatenated_str}")

if __name__ == "__main__":
    main()