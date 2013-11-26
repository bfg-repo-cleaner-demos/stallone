#ifndef stallone_api_function_IDiscretizedFunction_H
#define stallone_api_function_IDiscretizedFunction_H

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

      class IDiscretizedFunction : public ::stallone::api::function::IFunction {
      public:
        enum {
          mid_f_02530858,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDiscretizedFunction(jobject obj) : ::stallone::api::function::IFunction(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDiscretizedFunction(const IDiscretizedFunction& obj) : ::stallone::api::function::IFunction(obj) {}

        jdouble f(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(IDiscretizedFunction);

      class t_IDiscretizedFunction {
      public:
        PyObject_HEAD
        IDiscretizedFunction object;
        static PyObject *wrap_Object(const IDiscretizedFunction&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
