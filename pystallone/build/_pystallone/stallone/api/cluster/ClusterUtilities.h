#ifndef stallone_api_cluster_ClusterUtilities_H
#define stallone_api_cluster_ClusterUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
    class Iterable;
  }
}
namespace stallone {
  namespace api {
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
    namespace ints {
      class IIntArray;
    }
    namespace cluster {
      class IClustering;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace cluster {

      class ClusterUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_clusterIndexDaviesBouldin_10283cb8,
          mid_clusterIndexSizeImbalance_059aa486,
          mid_clusterNoncompactness_10283cb8,
          mid_clusterSizes_668b97b7,
          mid_densityBased_dcea8e74,
          mid_densityBased_66646433,
          mid_densityBased_810dc3c0,
          mid_discretize_b1063b91,
          mid_kcenter_544bdf51,
          mid_kcenter_d426b214,
          mid_kmeans_dcea8e74,
          mid_kmeans_c5cf10c2,
          mid_kmeans_591b59c5,
          mid_kmeans_a5d60e49,
          mid_kmeans_504866f1,
          mid_kmeans_f2ad93a2,
          mid_membershipToState_b982e684,
          mid_regularSpatial_a59e2bf6,
          mid_regularSpatial_1f660d8f,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ClusterUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ClusterUtilities(const ClusterUtilities& obj) : ::java::lang::Object(obj) {}

        ClusterUtilities();

        jdouble clusterIndexDaviesBouldin(const ::java::lang::Iterable &, const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, const ::stallone::api::ints::IIntArray &) const;
        jdouble clusterIndexSizeImbalance(const ::stallone::api::ints::IIntArray &) const;
        jdouble clusterNoncompactness(const ::java::lang::Iterable &, const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray clusterSizes(const ::java::lang::Iterable &, const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::cluster::IClustering densityBased(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::cluster::IClustering densityBased(const ::stallone::api::datasequence::IDataSequence &, jdouble, jint) const;
        ::stallone::api::cluster::IClustering densityBased(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jdouble, jint) const;
        ::stallone::api::ints::IIntArray discretize(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::discretization::IDiscretization &) const;
        ::stallone::api::cluster::IClustering kcenter(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::cluster::IClustering kcenter(const ::java::lang::Iterable &, jint, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::cluster::IClustering kmeans(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::cluster::IClustering kmeans(const ::stallone::api::datasequence::IDataSequence &, jint, jint) const;
        ::stallone::api::cluster::IClustering kmeans(const ::java::lang::Iterable &, jint, jint) const;
        ::stallone::api::cluster::IClustering kmeans(const ::java::lang::Iterable &, jint, jint, jint) const;
        ::stallone::api::cluster::IClustering kmeans(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint, jint) const;
        ::stallone::api::cluster::IClustering kmeans(const ::java::lang::Iterable &, jint, const ::stallone::api::doubles::IMetric &, jint, jint) const;
        ::stallone::api::doubles::IDoubleArray membershipToState(const ::stallone::api::cluster::IClustering &, jint) const;
        ::stallone::api::cluster::IClustering regularSpatial(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jdouble) const;
        ::stallone::api::cluster::IClustering regularSpatial(const ::java::lang::Iterable &, jint, const ::stallone::api::doubles::IMetric &, jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace cluster {
      extern PyTypeObject PY_TYPE(ClusterUtilities);

      class t_ClusterUtilities {
      public:
        PyObject_HEAD
        ClusterUtilities object;
        static PyObject *wrap_Object(const ClusterUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
