#ifndef stallone_api_graph_Graph_H
#define stallone_api_graph_Graph_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace graph {
      class GraphFactory;
      class GraphUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class Graph : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Graph(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Graph(const Graph& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::graph::GraphFactory *create;
        static ::stallone::api::graph::GraphUtilities *util;

        Graph();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(Graph);

      class t_Graph {
      public:
        PyObject_HEAD
        Graph object;
        static PyObject *wrap_Object(const Graph&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
