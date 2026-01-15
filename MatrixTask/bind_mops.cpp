#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "matrix.hpp"

namespace py = pybind11;

void bind_mops(py::module_& m) {    
    py::class_<Matrix> matrix_class(m, "Matrix", py::module_local());
    matrix_class
        .def("__add__", &Matrix::operator+,
            py::arg("other"),
            "Add two matrices")
        
        .def("__mul__", &Matrix::operator*,
            py::arg("other"),
            "Multiply two matrices")
        
        .def("swapRow", &Matrix::swapRow,
            py::arg("r1"), py::arg("r2"),
            "Swap two rows (1-indexed)")
        
        .def("swapCol", &Matrix::swapCol,
            py::arg("c1"), py::arg("c2"),
            "Swap two columns (1-indexed)")
        
        .def("transpose", &Matrix::Transpose,
            "Transpose the matrix in-place")
        
        .def("luDecomp", &Matrix::LUdecomp,
            py::arg("A"), py::arg("B"),
            "Solve AX = B with LU decomposition")
        
        .def("gradientDescent", &Matrix::gradientDescent,
            py::arg("X"), py::arg("Y"), 
            py::arg("alpha") = 0.01, 
            py::arg("iters") = 1000,
            "find slope");
}
