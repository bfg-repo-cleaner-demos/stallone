#ifndef stallone_api_potential_IMassEnergyModel_H
#define stallone_api_potential_IMassEnergyModel_H

#include "stallone/api/potential/IEnergyModel.h"

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
    namespace potential {

      class IMassEnergyModel : public ::stallone::api::potential::IEnergyModel {
      public:
        enum {
          mid_getMasses_1d53e353,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IMassEnergyModel(jobject obj) : ::stallone::api::potential::IEnergyModel(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IMassEnergyModel(const IMassEnergyModel& obj) : ::stallone::api::potential::IEnergyModel(obj) {}

        ::stallone::api::doubles::IDoubleArray getMasses() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace potential {
      extern PyTypeObject PY_TYPE(IMassEnergyModel);

      class t_IMassEnergyModel {
      public:
        PyObject_HEAD
        IMassEnergyModel object;
        static PyObject *wrap_Object(const IMassEnergyModel&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
