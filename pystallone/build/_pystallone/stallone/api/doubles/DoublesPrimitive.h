#ifndef stallone_api_doubles_DoublesPrimitive_H
#define stallone_api_doubles_DoublesPrimitive_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class DoublesPrimitive : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DoublesPrimitive(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DoublesPrimitive(const DoublesPrimitive& obj) : ::java::lang::Object(obj) {}

        DoublesPrimitive();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(DoublesPrimitive);

      class t_DoublesPrimitive {
      public:
        PyObject_HEAD
        DoublesPrimitive object;
        static PyObject *wrap_Object(const DoublesPrimitive&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
