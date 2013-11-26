#ifndef stallone_dynamics_IIntegratorThermostatted_H
#define stallone_dynamics_IIntegratorThermostatted_H

#include "stallone/dynamics/IIntegrator.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace dynamics {

    class IIntegratorThermostatted : public ::stallone::dynamics::IIntegrator {
    public:
      enum {
        mid_setkT_5d1c7645,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit IIntegratorThermostatted(jobject obj) : ::stallone::dynamics::IIntegrator(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      IIntegratorThermostatted(const IIntegratorThermostatted& obj) : ::stallone::dynamics::IIntegrator(obj) {}

      void setkT(jdouble) const;
    };
  }
}

#include <Python.h>

namespace stallone {
  namespace dynamics {
    extern PyTypeObject PY_TYPE(IIntegratorThermostatted);

    class t_IIntegratorThermostatted {
    public:
      PyObject_HEAD
      IIntegratorThermostatted object;
      static PyObject *wrap_Object(const IIntegratorThermostatted&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
