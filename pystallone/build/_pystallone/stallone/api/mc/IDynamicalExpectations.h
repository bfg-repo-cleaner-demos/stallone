#ifndef stallone_api_mc_IDynamicalExpectations_H
#define stallone_api_mc_IDynamicalExpectations_H

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

      class IDynamicalExpectations : public ::java::lang::Object {
      public:
        enum {
          mid_calculateAutocorrelation_f5db6ad3,
          mid_calculateCorrelation_cf06784b,
          mid_calculatePerturbationExpectation_cf06784b,
          mid_setK_0253084a,
          mid_setStationaryDistribution_0253084a,
          mid_setT_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDynamicalExpectations(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDynamicalExpectations(const IDynamicalExpectations& obj) : ::java::lang::Object(obj) {}

        jdouble calculateAutocorrelation(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jdouble calculateCorrelation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jdouble calculatePerturbationExpectation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        void setK(const ::stallone::api::doubles::IDoubleArray &) const;
        void setStationaryDistribution(const ::stallone::api::doubles::IDoubleArray &) const;
        void setT(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(IDynamicalExpectations);

      class t_IDynamicalExpectations {
      public:
        PyObject_HEAD
        IDynamicalExpectations object;
        static PyObject *wrap_Object(const IDynamicalExpectations&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
