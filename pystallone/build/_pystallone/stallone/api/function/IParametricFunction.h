#ifndef stallone_api_function_IParametricFunction_H
#define stallone_api_function_IParametricFunction_H

#include "stallone/api/function/IFunction.h"

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
    class ICopyable;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class IParametricFunction : public ::stallone::api::function::IFunction {
      public:
        enum {
          mid_getParameters_1d53e353,
          mid_setParameters_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IParametricFunction(jobject obj) : ::stallone::api::function::IFunction(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IParametricFunction(const IParametricFunction& obj) : ::stallone::api::function::IFunction(obj) {}

        ::stallone::api::doubles::IDoubleArray getParameters() const;
        void setParameters(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(IParametricFunction);

      class t_IParametricFunction {
      public:
        PyObject_HEAD
        IParametricFunction object;
        static PyObject *wrap_Object(const IParametricFunction&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
