#ifndef stallone_api_discretization_DiscretizationFactory_H
#define stallone_api_discretization_DiscretizationFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class IGriddedFunction;
      class IFunction;
    }
    namespace doubles {
      class IDoubleArray;
      class IMetric;
    }
    namespace discretization {
      class IDiscretization;
    }
    namespace datasequence {
      class IDataSequence;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace discretization {

      class DiscretizationFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_coreDiscretization_d4adc0e8,
          mid_coreDiscretization_420bbdd1,
          mid_createGridDiscretization_520f5e61,
          mid_createGridDiscretization_036175b0,
          mid_randomSelectionDiscretization_b095688d,
          mid_randomSelectionDiscretization_cdbbabe6,
          mid_regularSelectionDiscretization_b095688d,
          mid_regularSelectionDiscretization_cdbbabe6,
          mid_voronoiDiscretization_f8e8794f,
          mid_voronoiDiscretization_e9a384f2,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DiscretizationFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DiscretizationFactory(const DiscretizationFactory& obj) : ::java::lang::Object(obj) {}

        DiscretizationFactory();

        ::stallone::api::discretization::IDiscretization coreDiscretization(const ::stallone::api::datasequence::IDataSequence &, jdouble) const;
        ::stallone::api::discretization::IDiscretization coreDiscretization(const ::stallone::api::datasequence::IDataSequence &, jdouble, const ::stallone::api::doubles::IMetric &) const;
        ::stallone::api::function::IGriddedFunction createGridDiscretization(const ::stallone::api::function::IFunction &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::function::IGriddedFunction createGridDiscretization(const ::stallone::api::function::IFunction &, const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::discretization::IDiscretization randomSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::discretization::IDiscretization randomSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::discretization::IDiscretization regularSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::discretization::IDiscretization regularSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::discretization::IDiscretization voronoiDiscretization(const ::stallone::api::datasequence::IDataSequence &) const;
        ::stallone::api::discretization::IDiscretization voronoiDiscretization(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace discretization {
      extern PyTypeObject PY_TYPE(DiscretizationFactory);

      class t_DiscretizationFactory {
      public:
        PyObject_HEAD
        DiscretizationFactory object;
        static PyObject *wrap_Object(const DiscretizationFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
