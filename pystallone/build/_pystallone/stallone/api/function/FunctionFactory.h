#ifndef stallone_api_function_FunctionFactory_H
#define stallone_api_function_FunctionFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class IFunction;
      class IFunctionC1;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class FunctionFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_createDifferentiableFunction_27744d9b,
          mid_createDifferentiableFunction_9fa18969,
          mid_createFunction_74899c4f,
          mid_createFunction_9cbc3d09,
          mid_main_4dd4540c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit FunctionFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        FunctionFactory(const FunctionFactory& obj) : ::java::lang::Object(obj) {}

        FunctionFactory();

        ::stallone::api::function::IFunctionC1 createDifferentiableFunction(const ::java::lang::String &, const JArray< ::java::lang::String > &) const;
        ::stallone::api::function::IFunctionC1 createDifferentiableFunction(const JArray< ::java::lang::String > &, const ::java::lang::String &, const JArray< ::java::lang::String > &) const;
        ::stallone::api::function::IFunction createFunction(const ::java::lang::String &) const;
        ::stallone::api::function::IFunction createFunction(const JArray< ::java::lang::String > &, const ::java::lang::String &) const;
        static void main(const JArray< ::java::lang::String > &);
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(FunctionFactory);

      class t_FunctionFactory {
      public:
        PyObject_HEAD
        FunctionFactory object;
        static PyObject *wrap_Object(const FunctionFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
