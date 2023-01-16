#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "QuadTree.hpp"

namespace py = pybind11;

template <typename Sequence >
inline py::array_t<typename Sequence::value_type> as_pyarray(Sequence& seq) {

  auto size = seq.size();
  auto data = seq.data();
  std::unique_ptr<Sequence> seq_ptr = std::make_unique<Sequence>(std::move(seq));
  auto capsule = py::capsule(seq_ptr.get(), [](void *p) { std::unique_ptr<Sequence>(reinterpret_cast<Sequence*>(p)); });
  seq_ptr.release();
  return py::array(size, data, capsule);
}

PYBIND11_MODULE(libquadtree, m)
{
  m.doc() = R"pbdoc(
        C++ utility methods for the quadtree.
    )pbdoc";

  py::class_<Quadtree>(m, "Quadtree")
        .def(py::init<int,int,int>())
        .def("insert", &Quadtree::insert)
        .def("remove", &Quadtree::remove)
        .def("query",
             [](Quadtree &a,float x1,float y1,float x2,float y2, int omit_element) {
                auto l = a.query(x1,y1,x2,y2,omit_element);
                std::vector<int> v;
                v.reserve(l.size());
                for (int i = 0; i < l.size(); ++i) {
                 v.push_back(l[i]);
                }
                return as_pyarray(v);
             }
        )
        .def("cleanup",&Quadtree::cleanup);

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}
