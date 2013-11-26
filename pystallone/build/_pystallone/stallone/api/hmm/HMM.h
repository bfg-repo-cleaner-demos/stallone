#ifndef stallone_api_hmm_HMM_H
#define stallone_api_hmm_HMM_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace hmm {
      class HMMFactory;
      class HMMUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class HMM : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit HMM(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        HMM(const HMM& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::hmm::HMMFactory *create;
        static ::stallone::api::hmm::HMMUtilities *util;

        HMM();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(HMM);

      class t_HMM {
      public:
        PyObject_HEAD
        HMM object;
        static PyObject *wrap_Object(const HMM&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
