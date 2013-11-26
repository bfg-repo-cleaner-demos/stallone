#ifndef stallone_mc_sampling_ITransitionMatrixSampler_H
#define stallone_mc_sampling_ITransitionMatrixSampler_H

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
  namespace mc {
    namespace sampling {

      class ITransitionMatrixSampler : public ::java::lang::Object {
      public:
        enum {
          mid_init_0253084a,
          mid_init_608d488a,
          mid_logLikelihood_54c6a174,
          mid_sample_e3ead0f5,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ITransitionMatrixSampler(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ITransitionMatrixSampler(const ITransitionMatrixSampler& obj) : ::java::lang::Object(obj) {}

        void init(const ::stallone::api::doubles::IDoubleArray &) const;
        void init(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble logLikelihood() const;
        ::stallone::api::doubles::IDoubleArray sample(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace mc {
    namespace sampling {
      extern PyTypeObject PY_TYPE(ITransitionMatrixSampler);

      class t_ITransitionMatrixSampler {
      public:
        PyObject_HEAD
        ITransitionMatrixSampler object;
        static PyObject *wrap_Object(const ITransitionMatrixSampler&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
