#ifndef stallone_api_hmm_IHMMParameters_H
#define stallone_api_hmm_IHMMParameters_H

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

      class IHMMParameters : public ::java::lang::Object {
      public:
        enum {
          mid_copy_6a5b587d,
          mid_getInitialDistribution_1d53e353,
          mid_getNStates_54c6a179,
          mid_getOutputParameters_e3ead0f5,
          mid_getTransitionMatrix_1d53e353,
          mid_isReversible_54c6a16a,
          mid_isStationary_54c6a16a,
          mid_setInitialDistribution_0253084a,
          mid_setOutputParameters_9665a230,
          mid_setTransitionMatrix_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IHMMParameters(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IHMMParameters(const IHMMParameters& obj) : ::java::lang::Object(obj) {}

        IHMMParameters copy() const;
        ::stallone::api::doubles::IDoubleArray getInitialDistribution() const;
        jint getNStates() const;
        ::stallone::api::doubles::IDoubleArray getOutputParameters(jint) const;
        ::stallone::api::doubles::IDoubleArray getTransitionMatrix() const;
        jboolean isReversible() const;
        jboolean isStationary() const;
        void setInitialDistribution(const ::stallone::api::doubles::IDoubleArray &) const;
        void setOutputParameters(jint, const ::stallone::api::doubles::IDoubleArray &) const;
        void setTransitionMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(IHMMParameters);

      class t_IHMMParameters {
      public:
        PyObject_HEAD
        IHMMParameters object;
        static PyObject *wrap_Object(const IHMMParameters&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
