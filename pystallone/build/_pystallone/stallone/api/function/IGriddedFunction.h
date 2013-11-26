#ifndef stallone_api_function_IGriddedFunction_H
#define stallone_api_function_IGriddedFunction_H

#include "stallone/api/function/IGrid.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class IDiscretizedFunction;
    }
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class IGriddedFunction : public ::stallone::api::function::IGrid {
      public:
        enum {
          mid_f_059aa486,
          mid_f_1efc201a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IGriddedFunction(jobject obj) : ::stallone::api::function::IGrid(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IGriddedFunction(const IGriddedFunction& obj) : ::stallone::api::function::IGrid(obj) {}

        jdouble f(const ::stallone::api::ints::IIntArray &) const;
        jdouble f(const JArray< jint > &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(IGriddedFunction);

      class t_IGriddedFunction {
      public:
        PyObject_HEAD
        IGriddedFunction object;
        static PyObject *wrap_Object(const IGriddedFunction&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
