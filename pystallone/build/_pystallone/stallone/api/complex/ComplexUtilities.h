#ifndef stallone_api_complex_ComplexUtilities_H
#define stallone_api_complex_ComplexUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class ComplexUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ComplexUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ComplexUtilities(const ComplexUtilities& obj) : ::java::lang::Object(obj) {}

        ComplexUtilities();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace complex {
      extern PyTypeObject PY_TYPE(ComplexUtilities);

      class t_ComplexUtilities {
      public:
        PyObject_HEAD
        ComplexUtilities object;
        static PyObject *wrap_Object(const ComplexUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
