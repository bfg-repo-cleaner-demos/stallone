#ifndef stallone_api_hmm_HMMUtilities_H
#define stallone_api_hmm_HMMUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class HMMUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit HMMUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        HMMUtilities(const HMMUtilities& obj) : ::java::lang::Object(obj) {}

        HMMUtilities();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(HMMUtilities);

      class t_HMMUtilities {
      public:
        PyObject_HEAD
        HMMUtilities object;
        static PyObject *wrap_Object(const HMMUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
