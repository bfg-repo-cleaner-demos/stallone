#ifndef stallone_api_function_IFunctionC1_H
#define stallone_api_function_IFunctionC1_H

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
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class IFunctionC1 : public ::stallone::api::function::IFunction {
      public:
        enum {
          mid_grad_381b58a8,
          mid_grad_32638cb7,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IFunctionC1(jobject obj) : ::stallone::api::function::IFunction(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IFunctionC1(const IFunctionC1& obj) : ::stallone::api::function::IFunction(obj) {}

        ::stallone::api::doubles::IDoubleArray grad(const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleArray grad(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(IFunctionC1);

      class t_IFunctionC1 {
      public:
        PyObject_HEAD
        IFunctionC1 object;
        static PyObject *wrap_Object(const IFunctionC1&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
