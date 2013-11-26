#ifndef stallone_api_mc_IDynamicalExpectationsSpectral_H
#define stallone_api_mc_IDynamicalExpectationsSpectral_H

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

      class IDynamicalExpectationsSpectral : public ::java::lang::Object {
      public:
        enum {
          mid_calculateAutocorrelation_0253084a,
          mid_calculateCorrelation_608d488a,
          mid_calculatePerturbationExpectation_608d488a,
          mid_getAmplitudes_1d53e353,
          mid_getTimescales_1d53e353,
          mid_getValue_5d1c7657,
          mid_setK_0253084a,
          mid_setStationaryDistribution_0253084a,
          mid_setT_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDynamicalExpectationsSpectral(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDynamicalExpectationsSpectral(const IDynamicalExpectationsSpectral& obj) : ::java::lang::Object(obj) {}

        void calculateAutocorrelation(const ::stallone::api::doubles::IDoubleArray &) const;
        void calculateCorrelation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        void calculatePerturbationExpectation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray getAmplitudes() const;
        ::stallone::api::doubles::IDoubleArray getTimescales() const;
        jdouble getValue(jdouble) const;
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
      extern PyTypeObject PY_TYPE(IDynamicalExpectationsSpectral);

      class t_IDynamicalExpectationsSpectral {
      public:
        PyObject_HEAD
        IDynamicalExpectationsSpectral object;
        static PyObject *wrap_Object(const IDynamicalExpectationsSpectral&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
