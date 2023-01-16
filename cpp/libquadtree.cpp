#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "QuadTree.hpp"
namespace py = pybind11;
PYBIND11_MODULE(quadtree, m)
{
  m.doc() = R"pbdoc(
        C++ utility methods for the quadtree.
    )pbdoc";

  py::class_<Quadtree>(m, "Quadtree")
        .def(py::init<int,int,int>())
        .def("insert", &Quadtree::insert)
        .def("remove", &Quadtree::remove)
        .def("query",&Quadtree::query)
        .def("cleanup",&Quadtree::cleanup);
//  m.def("small_list_2_vec",&small_list_2_vec<int>);

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}
