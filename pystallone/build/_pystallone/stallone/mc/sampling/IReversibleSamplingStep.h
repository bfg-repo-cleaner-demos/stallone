#ifndef stallone_mc_sampling_IReversibleSamplingStep_H
#define stallone_mc_sampling_IReversibleSamplingStep_H

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

      class IReversibleSamplingStep : public ::java::lang::Object {
      public:
        enum {
          mid_init_0f08b60a,
          mid_step_54c6a16a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IReversibleSamplingStep(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IReversibleSamplingStep(const IReversibleSamplingStep& obj) : ::java::lang::Object(obj) {}

        void init(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean step() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace mc {
    namespace sampling {
      extern PyTypeObject PY_TYPE(IReversibleSamplingStep);

      class t_IReversibleSamplingStep {
      public:
        PyObject_HEAD
        IReversibleSamplingStep object;
        static PyObject *wrap_Object(const IReversibleSamplingStep&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
