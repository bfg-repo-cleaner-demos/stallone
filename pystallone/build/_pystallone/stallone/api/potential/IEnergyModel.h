#ifndef stallone_api_potential_IEnergyModel_H
#define stallone_api_potential_IEnergyModel_H

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
    namespace potential {

      class IEnergyModel : public ::java::lang::Object {
      public:
        enum {
          mid_calculate_54c6a16a,
          mid_getCoordinates_1d53e353,
          mid_getEnergy_54c6a174,
          mid_getGradient_1d53e353,
          mid_getNDimensions_54c6a179,
          mid_setCoordinates_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IEnergyModel(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IEnergyModel(const IEnergyModel& obj) : ::java::lang::Object(obj) {}

        jboolean calculate() const;
        ::stallone::api::doubles::IDoubleArray getCoordinates() const;
        jdouble getEnergy() const;
        ::stallone::api::doubles::IDoubleArray getGradient() const;
        jint getNDimensions() const;
        void setCoordinates(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace potential {
      extern PyTypeObject PY_TYPE(IEnergyModel);

      class t_IEnergyModel {
      public:
        PyObject_HEAD
        IEnergyModel object;
        static PyObject *wrap_Object(const IEnergyModel&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
