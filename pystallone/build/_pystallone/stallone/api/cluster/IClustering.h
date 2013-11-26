#ifndef stallone_api_cluster_IClustering_H
#define stallone_api_cluster_IClustering_H

#include "stallone/api/discretization/IDiscretization.h"

namespace java {
  namespace lang {
    class Class;
    class Iterable;
  }
  namespace util {
    class Iterator;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
      class IMetric;
    }
    namespace datasequence {
      class IDataSequence;
    }
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace cluster {

      class IClustering : public ::stallone::api::discretization::IDiscretization {
      public:
        enum {
          mid_clusterCenterIterator_40858c90,
          mid_getClusterAssignment_69a9969d,
          mid_getClusterCenters_26787975,
          mid_getClusterIndexes_4ac77731,
          mid_getNumberOfClusters_54c6a179,
          mid_perform_54c6a166,
          mid_setClusterInput_d7ef70c8,
          mid_setClusterInput_ae885829,
          mid_setMetric_9f46b3d3,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IClustering(jobject obj) : ::stallone::api::discretization::IDiscretization(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IClustering(const IClustering& obj) : ::stallone::api::discretization::IDiscretization(obj) {}

        ::java::util::Iterator clusterCenterIterator() const;
        ::stallone::api::discretization::IDiscretization getClusterAssignment() const;
        ::stallone::api::datasequence::IDataSequence getClusterCenters() const;
        ::stallone::api::ints::IIntArray getClusterIndexes() const;
        jint getNumberOfClusters() const;
        void perform() const;
        void setClusterInput(const ::stallone::api::datasequence::IDataSequence &) const;
        void setClusterInput(const ::java::lang::Iterable &, jint) const;
        void setMetric(const ::stallone::api::doubles::IMetric &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace cluster {
      extern PyTypeObject PY_TYPE(IClustering);

      class t_IClustering {
      public:
        PyObject_HEAD
        IClustering object;
        static PyObject *wrap_Object(const IClustering&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
