#ifndef stallone_api_graph_IIntConnectivity_H
#define stallone_api_graph_IIntConnectivity_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace graph {
      class IIntGraph;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class IIntConnectivity : public ::java::lang::Object {
      public:
        enum {
          mid_perform_54c6a166,
          mid_setGraph_7599d3ca,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntConnectivity(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntConnectivity(const IIntConnectivity& obj) : ::java::lang::Object(obj) {}

        void perform() const;
        void setGraph(const ::stallone::api::graph::IIntGraph &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(IIntConnectivity);

      class t_IIntConnectivity {
      public:
        PyObject_HEAD
        IIntConnectivity object;
        static PyObject *wrap_Object(const IIntConnectivity&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
