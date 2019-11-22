#include <Python.h>
#include "recoil.h"

#if PY_MAJOR_VERSION >= 3
    #define PyInt_FromLong PyLong_FromLong
    #define PyString_FromString PyUnicode_FromString
#endif

static void
ri_delete(PyObject *py_recoil)
{
    RECOIL_Delete((RECOIL *)PyCapsule_GetPointer(py_recoil, NULL));
}

static PyObject *
ri_new(PyObject *self, PyObject *args)
{
    RECOIL *recoil;

    if (!PyArg_ParseTuple(args, ""))
        return NULL;

    recoil = RECOIL_New();
    if (!recoil)
        return NULL;

    return PyCapsule_New((void *)recoil, NULL, ri_delete);
}

static PyObject *
ri_isourfile(PyObject *self, PyObject *args)
{
    const char *filename;
    bool result;

    if (!PyArg_ParseTuple(args, "s", &filename))
        return NULL;
    result = RECOIL_IsOurFile(filename);
    if (result) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}

static PyObject *
ri_decode(PyObject *self, PyObject *args)
{
    PyObject *py_recoil;
    const char *filename;
    PyObject *content;
    bool result;

    if (!PyArg_ParseTuple(args, "OsO", &py_recoil, &filename, &content))
        return NULL;

    result = RECOIL_Decode(
        (RECOIL *)PyCapsule_GetPointer(py_recoil, NULL),
        filename,
        (const uint8_t *)PyByteArray_AsString(content),
        PyByteArray_Size(content)
    );
    if (result) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}

static PyObject *
ri_getcolors(PyObject *self, PyObject *args)
{
    PyObject *py_recoil;
    int result;

    if (!PyArg_ParseTuple(args, "O", &py_recoil))
        return NULL;

    result = RECOIL_GetColors((RECOIL *)PyCapsule_GetPointer(py_recoil, NULL));

    return PyInt_FromLong(result);
}

static PyObject *
ri_getframes(PyObject *self, PyObject *args)
{
    PyObject *py_recoil;
    int result;

    if (!PyArg_ParseTuple(args, "O", &py_recoil))
        return NULL;

    result = RECOIL_GetFrames((RECOIL *)PyCapsule_GetPointer(py_recoil, NULL));

    return PyInt_FromLong(result);
}

static PyObject *
ri_getsize(PyObject *self, PyObject *args)
{
    PyObject *py_recoil;
    RECOIL *recoil;
    PyObject *width, *height;

    if (!PyArg_ParseTuple(args, "O", &py_recoil))
        return NULL;

    recoil = (RECOIL *)PyCapsule_GetPointer(py_recoil, NULL);

    width = PyInt_FromLong(RECOIL_GetWidth(recoil));
    height = PyInt_FromLong(RECOIL_GetHeight(recoil));

    return PyTuple_Pack(2, width, height);
}

static PyObject *
ri_getoriginalsize(PyObject *self, PyObject *args)
{
    PyObject *py_recoil;
    RECOIL *recoil;
    PyObject *width, *height;

    if (!PyArg_ParseTuple(args, "O", &py_recoil))
        return NULL;

    recoil = (RECOIL *)PyCapsule_GetPointer(py_recoil, NULL);

    width = PyInt_FromLong(RECOIL_GetOriginalWidth(recoil));
    height = PyInt_FromLong(RECOIL_GetOriginalHeight(recoil));

    return PyTuple_Pack(2, width, height);
}

static PyObject *
ri_getplatform(PyObject *self, PyObject *args)
{
    PyObject *py_recoil;
    const char *result;

    if (!PyArg_ParseTuple(args, "O", &py_recoil))
        return NULL;

    result = RECOIL_GetPlatform((RECOIL *)PyCapsule_GetPointer(py_recoil, NULL));

    return PyString_FromString(result);
}


static PyObject *
ri_getpixels(PyObject *self, PyObject *args)
{
    PyObject *py_recoil, *buffer;
    RECOIL *recoil;
    int pixel_count;

    const int *in_buf, *in_buf_end, *ptr;
    char *out_buf;

    if (!PyArg_ParseTuple(args, "O", &py_recoil))
        return NULL;

    recoil = (RECOIL *)PyCapsule_GetPointer(py_recoil, NULL);

    pixel_count = RECOIL_GetWidth(recoil) * RECOIL_GetHeight(recoil);
    buffer = PyByteArray_FromObject(PyInt_FromLong(pixel_count * 3));

    in_buf = RECOIL_GetPixels(recoil);
    in_buf_end = in_buf + pixel_count;

    out_buf = PyByteArray_AsString(buffer);
    for (ptr = in_buf; ptr < in_buf_end; ptr++) {
        *out_buf = (*ptr) >> 16; out_buf++;
        *out_buf = ((*ptr) & 0xff00) >> 8; out_buf++;
        *out_buf = (*ptr) & 0xff; out_buf++;
    }

    return buffer;
}
static PyMethodDef RecoilMethods[] = {
    {"new", ri_new, METH_VARARGS, "Create a new empty RECOIL structure."},
    {"is_our_file", ri_isourfile, METH_VARARGS, "Checks whether the filename extension is supported by RECOIL."},
    {"decode", ri_decode, METH_VARARGS, "Decodes picture file to an RGB bitmap."},
    {"get_colors", ri_getcolors, METH_VARARGS, "Returns number of unique colors in the decoded picture."},
    {"get_frames", ri_getframes, METH_VARARGS, "Returns the number of alternating frames the pictures is composed of."},
    {"get_size", ri_getsize, METH_VARARGS, "Returns the decoded width and height as a tuple."},
    {"get_original_size", ri_getoriginalsize, METH_VARARGS, "Returns the original width and height as a tuple (informational)."},
    {"get_platform", ri_getplatform, METH_VARARGS, "Returns the computer family of the decoded file format."},
    {"get_pixels", ri_getpixels, METH_VARARGS, "Returns pixels of the decoded image, top-down, left-to-right, as a bytebuffer of R, G, B for each pixel"},
    {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
    static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "_recoil",                                   /* m_name */
        "Internal interface to the RECOIL library",  /* m_doc */
        -1,                                          /* m_size */
        RecoilMethods,                               /* m_methods */
        NULL,                                        /* m_slots */
        NULL,                                        /* m_traverse */
        NULL,                                        /* m_clear */
        NULL,                                        /* m_free */
    };

    PyMODINIT_FUNC
    PyInit__recoil(void)
    {
        return PyModule_Create(&moduledef);
    }
#else
    PyMODINIT_FUNC
    init_recoil(void)
    {
        (void) Py_InitModule("_recoil", RecoilMethods);
    }
#endif
