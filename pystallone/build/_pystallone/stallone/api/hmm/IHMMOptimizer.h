#ifndef stallone_api_hmm_IHMMOptimizer_H
#define stallone_api_hmm_IHMMOptimizer_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace hmm {
      class ParameterEstimationException;
      class IHMM;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class IHMMOptimizer : public ::java::lang::Object {
      public:
        enum {
          mid_getHMM_612e48e3,
          mid_run_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IHMMOptimizer(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IHMMOptimizer(const IHMMOptimizer& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::hmm::IHMM getHMM() const;
        void run() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(IHMMOptimizer);

      class t_IHMMOptimizer {
      public:
        PyObject_HEAD
        IHMMOptimizer object;
        static PyObject *wrap_Object(const IHMMOptimizer&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
