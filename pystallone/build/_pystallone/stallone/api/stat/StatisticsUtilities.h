#ifndef stallone_api_stat_StatisticsUtilities_H
#define stallone_api_stat_StatisticsUtilities_H

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
      class IDoubleList;
    }
    namespace ints {
      class IIntArray;
      class IIntList;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace stat {

      class StatisticsUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_covariance_608d4898,
          mid_gaussianDensity_c5d3f3bd,
          mid_histogram_a01ac655,
          mid_mean_02530858,
          mid_meanColumn_32638cb7,
          mid_meanRow_32638cb7,
          mid_splitNonexponentialLifetimes_7d9b9db3,
          mid_splitNonexponentialLifetimes_488ea26a,
          mid_stdDev_02530858,
          mid_variance_02530858,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit StatisticsUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        StatisticsUtilities(const StatisticsUtilities& obj) : ::java::lang::Object(obj) {}

        StatisticsUtilities();

        jdouble covariance(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble gaussianDensity(jdouble, jdouble, jdouble) const;
        ::stallone::api::ints::IIntArray histogram(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble mean(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray meanColumn(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray meanRow(const ::stallone::api::doubles::IDoubleArray &) const;
        JArray< jint > splitNonexponentialLifetimes(const ::stallone::api::ints::IIntList &, const ::stallone::api::doubles::IDoubleList &) const;
        JArray< jint > splitNonexponentialLifetimes(const JArray< jint > &, const JArray< jdouble > &) const;
        jdouble stdDev(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble variance(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace stat {
      extern PyTypeObject PY_TYPE(StatisticsUtilities);

      class t_StatisticsUtilities {
      public:
        PyObject_HEAD
        StatisticsUtilities object;
        static PyObject *wrap_Object(const StatisticsUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
