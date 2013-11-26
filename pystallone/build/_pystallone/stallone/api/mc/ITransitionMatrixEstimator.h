#ifndef stallone_api_mc_ITransitionMatrixEstimator_H
#define stallone_api_mc_ITransitionMatrixEstimator_H

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
    namespace mc {

      class ITransitionMatrixEstimator : public ::java::lang::Object {
      public:
        enum {
          mid_estimate_54c6a166,
          mid_getTransitionMatrix_1d53e353,
          mid_setCounts_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ITransitionMatrixEstimator(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ITransitionMatrixEstimator(const ITransitionMatrixEstimator& obj) : ::java::lang::Object(obj) {}

        void estimate() const;
        ::stallone::api::doubles::IDoubleArray getTransitionMatrix() const;
        void setCounts(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(ITransitionMatrixEstimator);

      class t_ITransitionMatrixEstimator {
      public:
        PyObject_HEAD
        ITransitionMatrixEstimator object;
        static PyObject *wrap_Object(const ITransitionMatrixEstimator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
