#ifndef stallone_api_function_Functions_H
#define stallone_api_function_Functions_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class FunctionFactory;
      class FunctionUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class Functions : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Functions(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Functions(const Functions& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::function::FunctionFactory *create;
        static ::stallone::api::function::FunctionUtilities *util;

        Functions();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(Functions);

      class t_Functions {
      public:
        PyObject_HEAD
        Functions object;
        static PyObject *wrap_Object(const Functions&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
