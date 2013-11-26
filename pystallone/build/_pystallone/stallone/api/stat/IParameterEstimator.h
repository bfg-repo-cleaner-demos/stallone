#ifndef stallone_api_stat_IParameterEstimator_H
#define stallone_api_stat_IParameterEstimator_H

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
    namespace datasequence {
      class IDataSequence;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace stat {

      class IParameterEstimator : public ::java::lang::Object {
      public:
        enum {
          mid_addToEstimate_d7ef70c8,
          mid_addToEstimate_86440024,
          mid_copy_e97d706e,
          mid_estimate_2f8669d9,
          mid_estimate_9e4ae5c1,
          mid_getEstimate_1d53e353,
          mid_initialize_54c6a166,
          mid_initialize_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IParameterEstimator(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IParameterEstimator(const IParameterEstimator& obj) : ::java::lang::Object(obj) {}

        void addToEstimate(const ::stallone::api::datasequence::IDataSequence &) const;
        void addToEstimate(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IDoubleArray &) const;
        IParameterEstimator copy() const;
        ::stallone::api::doubles::IDoubleArray estimate(const ::stallone::api::datasequence::IDataSequence &) const;
        ::stallone::api::doubles::IDoubleArray estimate(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray getEstimate() const;
        void initialize() const;
        void initialize(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace stat {
      extern PyTypeObject PY_TYPE(IParameterEstimator);

      class t_IParameterEstimator {
      public:
        PyObject_HEAD
        IParameterEstimator object;
        static PyObject *wrap_Object(const IParameterEstimator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
