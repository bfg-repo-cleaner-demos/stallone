#ifndef stallone_api_mc_IMarkovChain_H
#define stallone_api_mc_IMarkovChain_H

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
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace mc {

      class IMarkovChain : public ::java::lang::Object {
      public:
        enum {
          mid_getTransitionMatrix_1d53e353,
          mid_printRandomTrajectory_39c7bd3c,
          mid_randomTrajectory_62213cdb,
          mid_randomTrajectoryToState_e2b10697,
          mid_setStartingDistribution_0253084a,
          mid_setStartingState_39c7bd3c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IMarkovChain(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IMarkovChain(const IMarkovChain& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray getTransitionMatrix() const;
        void printRandomTrajectory(jint) const;
        ::stallone::api::ints::IIntArray randomTrajectory(jint) const;
        ::stallone::api::ints::IIntArray randomTrajectoryToState(const JArray< jint > &) const;
        void setStartingDistribution(const ::stallone::api::doubles::IDoubleArray &) const;
        void setStartingState(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(IMarkovChain);

      class t_IMarkovChain {
      public:
        PyObject_HEAD
        IMarkovChain object;
        static PyObject *wrap_Object(const IMarkovChain&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
