#ifndef stallone_api_mc_tpt_ICommittor_H
#define stallone_api_mc_tpt_ICommittor_H

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

        class ICommittor : public ::java::lang::Object {
        public:
          enum {
            mid_backwardCommittor_1d53e353,
            mid_forwardCommittor_1d53e353,
            mid_setRateMatrix_0253084a,
            mid_setStationaryDistribution_0253084a,
            mid_setTransitionMatrix_0253084a,
            max_mid
          };

          static ::java::lang::Class *class$;
          static jmethodID *mids$;
          static bool live$;
          static jclass initializeClass(bool);

          explicit ICommittor(jobject obj) : ::java::lang::Object(obj) {
            if (obj != NULL)
              env->getClass(initializeClass);
          }
          ICommittor(const ICommittor& obj) : ::java::lang::Object(obj) {}

          ::stallone::api::doubles::IDoubleArray backwardCommittor() const;
          ::stallone::api::doubles::IDoubleArray forwardCommittor() const;
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
        extern PyTypeObject PY_TYPE(ICommittor);

        class t_ICommittor {
        public:
          PyObject_HEAD
          ICommittor object;
          static PyObject *wrap_Object(const ICommittor&);
          static PyObject *wrap_jobject(const jobject&);
          static void install(PyObject *module);
          static void initialize(PyObject *module);
        };
      }
    }
  }
}

#endif
