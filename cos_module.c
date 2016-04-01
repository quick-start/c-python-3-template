/*
 * Example of the Python 3 C API
 */
#include <Python.h>
#include <math.h>

/*  wrapped cosine function */
static PyObject* cos_func(PyObject* self, PyObject* args)
{
    double value, answer;

    /*  parse the input, from python float to c double */
    if (!PyArg_ParseTuple(args, "d", &value))
    {
        return NULL;
    }

    /* if the above function returns -1, an appropriate Python exception will
       have been set, and the function simply returns NULL */

    /* actual call to the cos function from libm */
    answer = cos(value);

    /*  construct the output from cos, from c double to python float */
    return Py_BuildValue("f", answer);
}

/* Define functions in module */
static PyMethodDef CosMethods[] =
{
     {"cos_func", cos_func, METH_VARARGS, "Evaluate the cosine of x"},
     {NULL, NULL, 0, NULL}
};

/* Python module definition */
static struct PyModuleDef module =
{
    PyModuleDef_HEAD_INIT,
    "cos_module", "Example of the Python 3 C API",
    -1, CosMethods
};

/* Name of the module should match the name above */
PyMODINIT_FUNC PyInit_cos_module(void)
{
    return PyModule_Create(&module);
}
