#include<pybind11/pybind11.h>
#include"matrix.hpp"
namespace py = pybind11;
using namespace std;

void bind_matrix(py::module_& m) {
    py::class_<Matrix>(m, "Matrix")
        .def(py::init<vector<vector<float>>&>(),
            py::arg("data"))
        
        .def("print", &Matrix::print)
        
        .def("__getitem__", [](Matrix& A, size_t i) -> vector<float>& {
            return A[i];
        }, py::return_value_policy::reference_internal)
        
        .def("__repr__", [](const Matrix& A) {
            return "<Matrix object>";
        });
}