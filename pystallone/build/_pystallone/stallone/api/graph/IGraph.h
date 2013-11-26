#ifndef stallone_api_graph_IGraph_H
#define stallone_api_graph_IGraph_H

#include "java/lang/Object.h"

namespace java {
  namespace util {
    class Iterator;
  }
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace graph {
      class IEdge;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class IGraph : public ::java::lang::Object {
      public:
        enum {
          mid_contains_290588e2,
          mid_contains_ee8d062c,
          mid_edgeIterator_40858c90,
          mid_neighborIterator_a04f5304,
          mid_nodeIterator_40858c90,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IGraph(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IGraph(const IGraph& obj) : ::java::lang::Object(obj) {}

        jboolean contains(const ::java::lang::Object &) const;
        jboolean contains(const ::stallone::api::graph::IEdge &) const;
        ::java::util::Iterator edgeIterator() const;
        ::java::util::Iterator neighborIterator(const ::java::lang::Object &) const;
        ::java::util::Iterator nodeIterator() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(IGraph);

      class t_IGraph {
      public:
        PyObject_HEAD
        IGraph object;
        PyTypeObject *parameters[2];
        static PyTypeObject **parameters_(t_IGraph *self)
        {
          return (PyTypeObject **) &(self->parameters);
        }
        static PyObject *wrap_Object(const IGraph&);
        static PyObject *wrap_jobject(const jobject&);
        static PyObject *wrap_Object(const IGraph&, PyTypeObject *, PyTypeObject *);
        static PyObject *wrap_jobject(const jobject&, PyTypeObject *, PyTypeObject *);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
