#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "matrix.hpp"

namespace py = pybind11;

void bind_gauss(py::module_& m) {
    py::class_<Matrix> matrix_class(m, "Matrix", py::module_local());
    matrix_class.def("gauss_jordan", &Matrix::gaussJordan,
        "Compute minv using G-J elimination");
}