#ifndef stallone_api_mc_ICountMatrixEstimator_H
#define stallone_api_mc_ICountMatrixEstimator_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
    class Iterable;
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

      class ICountMatrixEstimator : public ::java::lang::Object {
      public:
        enum {
          mid_addInput_059aa494,
          mid_addInput_d1cac205,
          mid_estimate_1d53e353,
          mid_getCountMatrix_1d53e353,
          mid_setLag_39c7bd3c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ICountMatrixEstimator(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ICountMatrixEstimator(const ICountMatrixEstimator& obj) : ::java::lang::Object(obj) {}

        void addInput(const ::stallone::api::ints::IIntArray &) const;
        void addInput(const ::java::lang::Iterable &) const;
        ::stallone::api::doubles::IDoubleArray estimate() const;
        ::stallone::api::doubles::IDoubleArray getCountMatrix() const;
        void setLag(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(ICountMatrixEstimator);

      class t_ICountMatrixEstimator {
      public:
        PyObject_HEAD
        ICountMatrixEstimator object;
        static PyObject *wrap_Object(const ICountMatrixEstimator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
