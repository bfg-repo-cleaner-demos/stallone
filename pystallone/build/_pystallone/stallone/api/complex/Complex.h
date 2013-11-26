#ifndef stallone_api_complex_Complex_H
#define stallone_api_complex_Complex_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace complex {
      class ComplexUtilities;
      class ComplexFactory;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class Complex : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Complex(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Complex(const Complex& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::complex::ComplexFactory *create;
        static ::stallone::api::complex::ComplexUtilities *util;

        Complex();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace complex {
      extern PyTypeObject PY_TYPE(Complex);

      class t_Complex {
      public:
        PyObject_HEAD
        Complex object;
        static PyObject *wrap_Object(const Complex&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
