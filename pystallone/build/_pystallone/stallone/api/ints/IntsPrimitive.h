#ifndef stallone_api_ints_IntsPrimitive_H
#define stallone_api_ints_IntsPrimitive_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class IntsPrimitive : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IntsPrimitive(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IntsPrimitive(const IntsPrimitive& obj) : ::java::lang::Object(obj) {}

        IntsPrimitive();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IntsPrimitive);

      class t_IntsPrimitive {
      public:
        PyObject_HEAD
        IntsPrimitive object;
        static PyObject *wrap_Object(const IntsPrimitive&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
