#ifndef stallone_api_function_IFunction_H
#define stallone_api_function_IFunction_H

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
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class IFunction : public ::java::lang::Object {
      public:
        enum {
          mid_f_f3b62ccb,
          mid_f_02530858,
          mid_getNumberOfVariables_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IFunction(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IFunction(const IFunction& obj) : ::java::lang::Object(obj) {}

        jdouble f(const JArray< jdouble > &) const;
        jdouble f(const ::stallone::api::doubles::IDoubleArray &) const;
        jint getNumberOfVariables() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(IFunction);

      class t_IFunction {
      public:
        PyObject_HEAD
        IFunction object;
        static PyObject *wrap_Object(const IFunction&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
