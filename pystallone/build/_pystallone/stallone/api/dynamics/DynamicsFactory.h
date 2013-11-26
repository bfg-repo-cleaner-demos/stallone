#ifndef stallone_api_dynamics_DynamicsFactory_H
#define stallone_api_dynamics_DynamicsFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace dynamics {
    class IIntegratorThermostatted;
    class IIntegrator;
  }
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
    namespace potential {
      class IEnergyModel;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace dynamics {

      class DynamicsFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_brownianDynamicsEuler_8f27988a,
          mid_langevinLeapFrog_8f27988a,
          mid_velocityVerlet_1d40a0c7,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DynamicsFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DynamicsFactory(const DynamicsFactory& obj) : ::java::lang::Object(obj) {}

        DynamicsFactory();

        ::stallone::dynamics::IIntegratorThermostatted brownianDynamicsEuler(const ::stallone::api::potential::IEnergyModel &, const ::stallone::api::doubles::IDoubleArray &, jdouble, jdouble, jdouble) const;
        ::stallone::dynamics::IIntegratorThermostatted langevinLeapFrog(const ::stallone::api::potential::IEnergyModel &, const ::stallone::api::doubles::IDoubleArray &, jdouble, jdouble, jdouble) const;
        ::stallone::dynamics::IIntegrator velocityVerlet(const ::stallone::api::potential::IEnergyModel &, const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace dynamics {
      extern PyTypeObject PY_TYPE(DynamicsFactory);

      class t_DynamicsFactory {
      public:
        PyObject_HEAD
        DynamicsFactory object;
        static PyObject *wrap_Object(const DynamicsFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
