#ifndef stallone_api_stat_StatisticsFactory_H
#define stallone_api_stat_StatisticsFactory_H

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
    namespace stat {
      class IParameterEstimator;
      class IDiscreteDistribution;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace stat {

      class StatisticsFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_discreteDistribution_a0d9efea,
          mid_parameterEstimatorGaussian1D_e97d706e,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit StatisticsFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        StatisticsFactory(const StatisticsFactory& obj) : ::java::lang::Object(obj) {}

        StatisticsFactory();

        ::stallone::api::stat::IDiscreteDistribution discreteDistribution(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::stat::IParameterEstimator parameterEstimatorGaussian1D() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace stat {
      extern PyTypeObject PY_TYPE(StatisticsFactory);

      class t_StatisticsFactory {
      public:
        PyObject_HEAD
        StatisticsFactory object;
        static PyObject *wrap_Object(const StatisticsFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
