try:
    import jpype
    import os
    import jpype.imports
    from jpype.types import *

    jpype.startJVM(classpath=['.'])

    # C/C++ codes are compiled shared libraries
    import ctypes
    from ctypes import c_char_p, c_int, cdll

    # Load C library
    c_lib = ctypes.CDLL('./c_product.so')

    # Load C++ library
    cpp_lib = cdll.LoadLibrary('./cpp_product.so')

    class Product:
        def __init__(self):
            # Initialize Java and C++ objects
            self.java_product = jpype.JClass('Product')()
            self.c_product = c_lib.create_product()
            self.cpp_product = cpp_lib.create_product()

        def set_details(self, name, price):
            # Call setter in Java
            self.java_product.setName(name)
            self.java_product.setPrice(price)
            
            # Call setter in C
            c_lib.set_name(self.c_product, c_char_p(name.encode('utf-8')))
            c_lib.set_price(self.c_product, c_int(price))
            
            # Call setter in C++
            cpp_lib.setName(self.cpp_product, c_char_p(name.encode('utf-8')))
            cpp_lib.setPrice(self.cpp_product, c_int(price))

        def get_details(self):
            # Call getter in Java
            java_name = self.java_product.getName()
            java_price = self.java_product.getPrice()
            
            # Call getter in C
            c_name = c_lib.get_name(self.c_product)
            c_price = c_lib.get_price(self.c_product)
            
            # Call getter in C++
            cpp_name = cpp_lib.getName(self.cpp_product)
            cpp_price = cpp_lib.getPrice(self.cpp_product)

            return {
                'Java': (java_name, java_price),
                'C': (c_name.decode('utf-8'), c_price),
                'C++': (cpp_name.decode('utf-8'), cpp_price)
            }

    product = Product()
    product.set_details('Laptop', 1200)
    details = product.get_details()
    print('Java:', details['Java'])
    print('C:', details['C'])
    print('C++:', details['C++'])
    
    jpype.shutdownJVM()

except Exception as e:
    print("An error occurred:", str(e))