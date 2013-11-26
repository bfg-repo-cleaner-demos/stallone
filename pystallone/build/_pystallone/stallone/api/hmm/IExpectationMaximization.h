#ifndef stallone_api_hmm_IExpectationMaximization_H
#define stallone_api_hmm_IExpectationMaximization_H

#include "stallone/api/hmm/IHMMOptimizer.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace hmm {
      class IHMMParameters;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class IExpectationMaximization : public ::stallone::api::hmm::IHMMOptimizer {
      public:
        enum {
          mid_getLogLikelihoodHistory_dab10e78,
          mid_setInitialParameters_ba9323e8,
          mid_setLikelihoodDecreaseTolerance_5d1c7645,
          mid_setMaximumNumberOfStep_39c7bd3c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IExpectationMaximization(jobject obj) : ::stallone::api::hmm::IHMMOptimizer(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IExpectationMaximization(const IExpectationMaximization& obj) : ::stallone::api::hmm::IHMMOptimizer(obj) {}

        JArray< jdouble > getLogLikelihoodHistory() const;
        void setInitialParameters(const ::stallone::api::hmm::IHMMParameters &) const;
        void setLikelihoodDecreaseTolerance(jdouble) const;
        void setMaximumNumberOfStep(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(IExpectationMaximization);

      class t_IExpectationMaximization {
      public:
        PyObject_HEAD
        IExpectationMaximization object;
        static PyObject *wrap_Object(const IExpectationMaximization&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
