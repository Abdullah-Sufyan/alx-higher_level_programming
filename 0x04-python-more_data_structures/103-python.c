#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_list - Prints some basic info about Python lists
 * @p: PyObject pointer
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	printf("[*] Python list info\n");
	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}
	size = ((PyVarObject *)p)->ob_size;

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; ++i)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}

/**
 * print_python_bytes - Prints some basic info about Python bytes objects
 * @p: PyObject pointer
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	unsigned char *str;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)p)->ob_size;
	printf("  [.] Size: %ld\n", size);
	printf("  [.] trying string: %s\n", ((PyBytesObject *)p)->ob_sval);

	if (size > 10)
		size = 10;

	str = ((PyBytesObject *)p)->ob_sval;
	printf("  [.] first %ld bytes: ", size);
	for (i = 0; i < size; ++i)
	{
		printf("%02x", str[i]);
		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}
