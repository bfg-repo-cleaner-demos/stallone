#ifndef stallone_api_graph_IEdge_H
#define stallone_api_graph_IEdge_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class IEdge : public ::java::lang::Object {
      public:
        enum {
          mid_getNode1_846352c3,
          mid_getNode2_846352c3,
          mid_getWeight_54c6a174,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IEdge(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IEdge(const IEdge& obj) : ::java::lang::Object(obj) {}

        ::java::lang::Object getNode1() const;
        ::java::lang::Object getNode2() const;
        jdouble getWeight() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(IEdge);

      class t_IEdge {
      public:
        PyObject_HEAD
        IEdge object;
        PyTypeObject *parameters[1];
        static PyTypeObject **parameters_(t_IEdge *self)
        {
          return (PyTypeObject **) &(self->parameters);
        }
        static PyObject *wrap_Object(const IEdge&);
        static PyObject *wrap_jobject(const jobject&);
        static PyObject *wrap_Object(const IEdge&, PyTypeObject *);
        static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
