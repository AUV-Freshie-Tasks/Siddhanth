#include<pybind11/pybind11.h>
#include<pybind11/operators.h>
#include"matrix.hpp"

namespace py = pybind11;
PYBIND11_MODULE(Matrix, m){
    py::class_<Matrix<float>>(m, "Matrix")
        .def(py::init<vector<vector<float>>&>())
        .def("__getitem__",[]
            (Matrix<float> &self, int i) -> std::vector<float>& {
                if (i < 0 || i >= self.m1.size())
                    throw py::index_error();
                return self[i];
            },
            py::return_value_policy::reference_internal
        )
        .def("__setitem__",
            [](Matrix<float> &self, int i, const std::vector<float>& value) {
                if (i < 0 || i >= self.m1.size())
                    throw py::index_error();
                self.m1[i] = value;
            }
        )
        .def(py::self + py::self)
        .def(py::self * py::self)
        .def("print", &Matrix<float>::print)
        .def("gaussJordan", &Matrix<float>::gaussJordan)
        .def("swapRow", &Matrix<float>::swapRow)
        .def("swapCol", &Matrix<float>::swapCol)
        .def("multInt", &Matrix<float>::multInt)
        .def("Transpose", &Matrix<float>::Transpose)
        .def("LUdecomp", &Matrix<float>::LUdecomp)
        .def("gradientDescent", &Matrix<float>::gradientDescent);
}