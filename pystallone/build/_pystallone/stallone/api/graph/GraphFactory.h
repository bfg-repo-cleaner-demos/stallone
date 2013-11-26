#ifndef stallone_api_graph_GraphFactory_H
#define stallone_api_graph_GraphFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
    namespace graph {
      class IIntGraph;
      class IIntConnectivity;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class GraphFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_connectivityChecker_f03ea51b,
          mid_intGraph_3333943b,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit GraphFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        GraphFactory(const GraphFactory& obj) : ::java::lang::Object(obj) {}

        GraphFactory();

        ::stallone::api::graph::IIntConnectivity connectivityChecker(const ::stallone::api::graph::IIntGraph &) const;
        ::stallone::api::graph::IIntGraph intGraph(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(GraphFactory);

      class t_GraphFactory {
      public:
        PyObject_HEAD
        GraphFactory object;
        static PyObject *wrap_Object(const GraphFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
