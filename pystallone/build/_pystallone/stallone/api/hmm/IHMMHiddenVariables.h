#ifndef stallone_api_hmm_IHMMHiddenVariables_H
#define stallone_api_hmm_IHMMHiddenVariables_H

#include "java/lang/Object.h"

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
    namespace hmm {

      class IHMMHiddenVariables : public ::java::lang::Object {
      public:
        enum {
          mid_getAlpha_d8d154b4,
          mid_getBeta_d8d154b4,
          mid_getGamma_d8d154b4,
          mid_getGammaByState_e3ead0f5,
          mid_getMaxPath_dab10e75,
          mid_getPout_d8d154b4,
          mid_logLikelihood_54c6a174,
          mid_mostProbableState_39c7bd23,
          mid_nStates_54c6a179,
          mid_size_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IHMMHiddenVariables(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IHMMHiddenVariables(const IHMMHiddenVariables& obj) : ::java::lang::Object(obj) {}

        jdouble getAlpha(jint, jint) const;
        jdouble getBeta(jint, jint) const;
        jdouble getGamma(jint, jint) const;
        ::stallone::api::doubles::IDoubleArray getGammaByState(jint) const;
        JArray< jint > getMaxPath() const;
        jdouble getPout(jint, jint) const;
        jdouble logLikelihood() const;
        jint mostProbableState(jint) const;
        jint nStates() const;
        jint size() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(IHMMHiddenVariables);

      class t_IHMMHiddenVariables {
      public:
        PyObject_HEAD
        IHMMHiddenVariables object;
        static PyObject *wrap_Object(const IHMMHiddenVariables&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
