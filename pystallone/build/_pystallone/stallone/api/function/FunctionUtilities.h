#ifndef stallone_api_function_FunctionUtilities_H
#define stallone_api_function_FunctionUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class FunctionUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit FunctionUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        FunctionUtilities(const FunctionUtilities& obj) : ::java::lang::Object(obj) {}

        FunctionUtilities();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(FunctionUtilities);

      class t_FunctionUtilities {
      public:
        PyObject_HEAD
        FunctionUtilities object;
        static PyObject *wrap_Object(const FunctionUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
