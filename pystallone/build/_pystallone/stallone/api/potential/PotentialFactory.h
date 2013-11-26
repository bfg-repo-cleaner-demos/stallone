#ifndef stallone_api_potential_PotentialFactory_H
#define stallone_api_potential_PotentialFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
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
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace potential {

      class PotentialFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_createBistablePotential_39cb644b,
          mid_createBistablePotential_caf283f6,
          mid_createCoulombPotential_1de4cd01,
          mid_createCoulombPotential_389e8ec3,
          mid_createFoldingModel_ac319d50,
          mid_createHarmonicNetwork_373667c4,
          mid_createHarmonicOscillator_49727f51,
          mid_createLennardJonesModel_9c427ad8,
          mid_createLennardJonesModel_3d9f564e,
          mid_createPotential_44f9853a,
          mid_createPotential_f9bdb1a8,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit PotentialFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        PotentialFactory(const PotentialFactory& obj) : ::java::lang::Object(obj) {}

        PotentialFactory();

        ::stallone::api::potential::IEnergyModel createBistablePotential(jdouble, jdouble, jdouble) const;
        ::stallone::api::potential::IEnergyModel createBistablePotential(jdouble, jdouble, jdouble, jdouble) const;
        ::stallone::api::potential::IEnergyModel createCoulombPotential(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::potential::IEnergyModel createCoulombPotential(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, jdouble) const;
        ::stallone::api::potential::IEnergyModel createFoldingModel(jdouble, jdouble, jdouble, jdouble, jint) const;
        ::stallone::api::potential::IEnergyModel createHarmonicNetwork(jint) const;
        ::stallone::api::potential::IEnergyModel createHarmonicOscillator(jdouble) const;
        ::stallone::api::potential::IEnergyModel createLennardJonesModel(jint, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::potential::IEnergyModel createLennardJonesModel(jint, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::potential::IEnergyModel createPotential(const ::java::lang::String &, const JArray< ::java::lang::String > &) const;
        ::stallone::api::potential::IEnergyModel createPotential(const JArray< ::java::lang::String > &, const ::java::lang::String &, const JArray< ::java::lang::String > &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace potential {
      extern PyTypeObject PY_TYPE(PotentialFactory);

      class t_PotentialFactory {
      public:
        PyObject_HEAD
        PotentialFactory object;
        static PyObject *wrap_Object(const PotentialFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
