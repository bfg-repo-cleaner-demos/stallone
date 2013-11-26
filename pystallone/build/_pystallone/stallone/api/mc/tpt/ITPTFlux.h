#ifndef stallone_api_mc_tpt_ITPTFlux_H
#define stallone_api_mc_tpt_ITPTFlux_H

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
      namespace tpt {

        class ITPTFlux : public ::java::lang::Object {
        public:
          enum {
            mid_calculate_54c6a166,
            mid_getBackwardCommittor_1d53e353,
            mid_getFlux_1d53e353,
            mid_getForwardCommittor_1d53e353,
            mid_getNetFlux_1d53e353,
            mid_getRate_54c6a174,
            mid_getStationaryDistribution_1d53e353,
            mid_getTotalFlux_54c6a174,
            mid_setRateMatrix_0253084a,
            mid_setStationaryDistribution_0253084a,
            mid_setTransitionMatrix_0253084a,
            max_mid
          };

          static ::java::lang::Class *class$;
          static jmethodID *mids$;
          static bool live$;
          static jclass initializeClass(bool);

          explicit ITPTFlux(jobject obj) : ::java::lang::Object(obj) {
            if (obj != NULL)
              env->getClass(initializeClass);
          }
          ITPTFlux(const ITPTFlux& obj) : ::java::lang::Object(obj) {}

          void calculate() const;
          ::stallone::api::doubles::IDoubleArray getBackwardCommittor() const;
          ::stallone::api::doubles::IDoubleArray getFlux() const;
          ::stallone::api::doubles::IDoubleArray getForwardCommittor() const;
          ::stallone::api::doubles::IDoubleArray getNetFlux() const;
          jdouble getRate() const;
          ::stallone::api::doubles::IDoubleArray getStationaryDistribution() const;
          jdouble getTotalFlux() const;
          void setRateMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
          void setStationaryDistribution(const ::stallone::api::doubles::IDoubleArray &) const;
          void setTransitionMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
        };
      }
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      namespace tpt {
        extern PyTypeObject PY_TYPE(ITPTFlux);

        class t_ITPTFlux {
        public:
          PyObject_HEAD
          ITPTFlux object;
          static PyObject *wrap_Object(const ITPTFlux&);
          static PyObject *wrap_jobject(const jobject&);
          static void install(PyObject *module);
          static void initialize(PyObject *module);
        };
      }
    }
  }
}

#endif
