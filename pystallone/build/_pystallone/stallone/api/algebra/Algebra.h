#ifndef stallone_api_algebra_Algebra_H
#define stallone_api_algebra_Algebra_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace algebra {
      class AlgebraFactory;
      class AlgebraUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class Algebra : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Algebra(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Algebra(const Algebra& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::algebra::AlgebraFactory *create;
        static ::stallone::api::algebra::AlgebraUtilities *util;

        Algebra();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(Algebra);

      class t_Algebra {
      public:
        PyObject_HEAD
        Algebra object;
        static PyObject *wrap_Object(const Algebra&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
