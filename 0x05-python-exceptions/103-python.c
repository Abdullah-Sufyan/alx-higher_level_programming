#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Prints basic info about Python lists
 * @p: PyObject pointer
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	if (!PyList_Check(p))
	{
		fprintf(stderr, "[ERROR] Invalid List Object\n");
		return;
	}

	size = PyList_Size(p);
	printf("[*] Size of the Python List = %ld\n", size);

	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; ++i)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}

/**
 * print_python_bytes - Prints basic info about Python bytes
 * @p: PyObject pointer
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *str;

	if (!PyBytes_Check(p))
	{
		fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	printf("[.] Size of the Python Bytes = %ld\n", size);

	printf("[.] First 10 bytes: ");
	str = PyBytes_AsString(p);
	if (size > 10)
		size = 10;
	for (i = 0; i < size; ++i)
	{
		printf("%02x", str[i] & 0xff);
		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_python_float - Prints basic info about Python floats
 * @p: PyObject pointer
 */
void print_python_float(PyObject *p)
{
	double val;

	if (!PyFloat_Check(p))
	{
		fprintf(stderr, "[ERROR] Invalid Float Object\n");
		return;
	}

	val = ((PyFloatObject *)p)->ob_fval;
	printf("[.] %s\n", Py_TYPE(p)->tp_name);
	printf("Float: %lf\n", val);
}
