#ifndef stallone_dynamics_IIntegrator_H
#define stallone_dynamics_IIntegrator_H

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
    namespace potential {
      class IEnergyModel;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace dynamics {

    class IIntegrator : public ::java::lang::Object {
    public:
      enum {
        mid_copy_dc93dc5d,
        mid_getA_1d53e353,
        mid_getStepLength_54c6a174,
        mid_getV_1d53e353,
        mid_getX_1d53e353,
        mid_kineticEnergy_54c6a174,
        mid_potentialEnergy_54c6a174,
        mid_setEnergyModel_07a15343,
        mid_setMasses_0253084a,
        mid_setStepLength_5d1c7645,
        mid_setV_0253084a,
        mid_setX_0253084a,
        mid_step_54c6a16a,
        mid_totalEnergy_54c6a174,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit IIntegrator(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      IIntegrator(const IIntegrator& obj) : ::java::lang::Object(obj) {}

      IIntegrator copy() const;
      ::stallone::api::doubles::IDoubleArray getA() const;
      jdouble getStepLength() const;
      ::stallone::api::doubles::IDoubleArray getV() const;
      ::stallone::api::doubles::IDoubleArray getX() const;
      jdouble kineticEnergy() const;
      jdouble potentialEnergy() const;
      void setEnergyModel(const ::stallone::api::potential::IEnergyModel &) const;
      void setMasses(const ::stallone::api::doubles::IDoubleArray &) const;
      void setStepLength(jdouble) const;
      void setV(const ::stallone::api::doubles::IDoubleArray &) const;
      void setX(const ::stallone::api::doubles::IDoubleArray &) const;
      jboolean step() const;
      jdouble totalEnergy() const;
    };
  }
}

#include <Python.h>

namespace stallone {
  namespace dynamics {
    extern PyTypeObject PY_TYPE(IIntegrator);

    class t_IIntegrator {
    public:
      PyObject_HEAD
      IIntegrator object;
      static PyObject *wrap_Object(const IIntegrator&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
