#!/usr/bin/python3 -u

import ctypes

lib = ctypes.CDLL('./libPython.so')
lib.print_python_list.argtypes = [ctypes.py_object]
lib.print_python_bytes.argtypes = [ctypes.py_object]
lib.print_python_float.argtypes = [ctypes.py_object]
s = b"Hello"
lib.print_python_bytes(s)
b = b'\xff\xf8\x00\x00\x00\x00\x00\x00'
lib.print_python_bytes(b)
b = b'What does the \'b\' character do in front of a string literal?'
lib.print_python_bytes(b)
L = [b'Hello', b'World']
lib.print_python_list(L)
del L[1]
lib.print_python_list(L)
L = L + [4, 5, 6.0, (9, 8), [9, 8, 1024], b"School", "Betty"]
lib.print_python_list(L)
L = []
lib.print_python_list(L)
L.append(0)
lib.print_python_list(L)
L.append(1)
L.append(2)
L.append(3)
L.append(4)
lib.print_python_list(L)
L.pop()
lib.print_python_list(L)
L = ["School"]
lib.print_python_list(L)
lib.print_python_bytes(L)
f = 3.14
lib.print_python_float(f)
L = [-1.0, -0.1, 0.0, 1.0, 3.14, 3.14159, 3.14159265, 3.142]
print(L)
lib.print_python_list(L)
lib.print_python_float(L)
lib.print_python_list(f)
