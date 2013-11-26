#ifndef stallone_api_hmm_IHMM_H
#define stallone_api_hmm_IHMM_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace hmm {
      class IHMMParameters;
      class IHMMHiddenVariables;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class IHMM : public ::java::lang::Object {
      public:
        enum {
          mid_getHidden_bb1898f3,
          mid_getLogLikelihood_54c6a174,
          mid_getLogLikelihoodHistory_dab10e78,
          mid_getParameters_6a5b587d,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IHMM(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IHMM(const IHMM& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::hmm::IHMMHiddenVariables getHidden(jint) const;
        jdouble getLogLikelihood() const;
        JArray< jdouble > getLogLikelihoodHistory() const;
        ::stallone::api::hmm::IHMMParameters getParameters() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(IHMM);

      class t_IHMM {
      public:
        PyObject_HEAD
        IHMM object;
        static PyObject *wrap_Object(const IHMM&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
