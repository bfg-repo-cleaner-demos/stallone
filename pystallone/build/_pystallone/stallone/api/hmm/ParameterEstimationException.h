#ifndef stallone_api_hmm_ParameterEstimationException_H
#define stallone_api_hmm_ParameterEstimationException_H

#include "java/lang/Exception.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class ParameterEstimationException : public ::java::lang::Exception {
      public:
        enum {
          mid_init$_5fdc3f48,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ParameterEstimationException(jobject obj) : ::java::lang::Exception(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ParameterEstimationException(const ParameterEstimationException& obj) : ::java::lang::Exception(obj) {}

        ParameterEstimationException(const ::java::lang::String &);
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(ParameterEstimationException);

      class t_ParameterEstimationException {
      public:
        PyObject_HEAD
        ParameterEstimationException object;
        static PyObject *wrap_Object(const ParameterEstimationException&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
