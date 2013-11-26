#ifndef stallone_api_cluster_ClusterFactory_H
#define stallone_api_cluster_ClusterFactory_H

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
    namespace datasequence {
      class IDataSequence;
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

      class ClusterFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_createDensityBased_dcea8e74,
          mid_createDensityBased_544bdf51,
          mid_createDensityBased_66646433,
          mid_createDensityBased_810dc3c0,
          mid_createFixed_dca311aa,
          mid_createFixed_4e346fc0,
          mid_createKcenter_a743e72e,
          mid_createKcenter_dcea8e74,
          mid_createKcenter_9a5b1f9b,
          mid_createKcenter_544bdf51,
          mid_createKcenter_591b59c5,
          mid_createKcenter_d426b214,
          mid_createKmeans_a743e72e,
          mid_createKmeans_dcea8e74,
          mid_createKmeans_b5b0c110,
          mid_createKmeans_591b59c5,
          mid_createKmeans_7777b89b,
          mid_createKmeans_c5cf10c2,
          mid_createKmeans_504866f1,
          mid_createKmeans_a5d60e49,
          mid_createKmeans_f2ad93a2,
          mid_createRandom_a743e72e,
          mid_createRandom_dcea8e74,
          mid_createRandomCompact_b5b0c110,
          mid_createRandomCompact_c5cf10c2,
          mid_createRegularSpatial_22ddb313,
          mid_createRegularSpatial_a59e2bf6,
          mid_createRegularSpatial_532aac9e,
          mid_createRegularSpatial_1f660d8f,
          mid_metric_419347da,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ClusterFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ClusterFactory(const ClusterFactory& obj) : ::java::lang::Object(obj) {}

        static jint METRIC_EUCLIDEAN;
        static jint METRIC_MINRMSD;

        ClusterFactory();

        ::stallone::api::cluster::IClustering createDensityBased(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::cluster::IClustering createDensityBased(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::cluster::IClustering createDensityBased(const ::stallone::api::datasequence::IDataSequence &, jdouble, jint) const;
        ::stallone::api::cluster::IClustering createDensityBased(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jdouble, jint) const;
        ::stallone::api::cluster::IClustering createFixed(const ::stallone::api::datasequence::IDataSequence &) const;
        ::stallone::api::cluster::IClustering createFixed(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::datasequence::IDataSequence &) const;
        ::stallone::api::cluster::IClustering createKcenter(jint) const;
        ::stallone::api::cluster::IClustering createKcenter(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::cluster::IClustering createKcenter(const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::cluster::IClustering createKcenter(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::cluster::IClustering createKcenter(const ::java::lang::Iterable &, jint, jint) const;
        ::stallone::api::cluster::IClustering createKcenter(const ::java::lang::Iterable &, jint, const ::stallone::api::doubles::IMetric &, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(jint, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::java::lang::Iterable &, jint, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::stallone::api::doubles::IMetric &, jint, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::stallone::api::datasequence::IDataSequence &, jint, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jint, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::java::lang::Iterable &, jint, jint, jint) const;
        ::stallone::api::cluster::IClustering createKmeans(const ::java::lang::Iterable &, jint, const ::stallone::api::doubles::IMetric &, jint, jint) const;
        ::stallone::api::cluster::IClustering createRandom(jint) const;
        ::stallone::api::cluster::IClustering createRandom(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::cluster::IClustering createRandomCompact(jint, jint) const;
        ::stallone::api::cluster::IClustering createRandomCompact(const ::stallone::api::datasequence::IDataSequence &, jint, jint) const;
        ::stallone::api::cluster::IClustering createRegularSpatial(const ::stallone::api::datasequence::IDataSequence &, jdouble) const;
        ::stallone::api::cluster::IClustering createRegularSpatial(const ::stallone::api::datasequence::IDataSequence &, const ::stallone::api::doubles::IMetric &, jdouble) const;
        ::stallone::api::cluster::IClustering createRegularSpatial(const ::java::lang::Iterable &, jint, jdouble) const;
        ::stallone::api::cluster::IClustering createRegularSpatial(const ::java::lang::Iterable &, jint, const ::stallone::api::doubles::IMetric &, jdouble) const;
        ::stallone::api::doubles::IMetric metric(jint, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace cluster {
      extern PyTypeObject PY_TYPE(ClusterFactory);

      class t_ClusterFactory {
      public:
        PyObject_HEAD
        ClusterFactory object;
        static PyObject *wrap_Object(const ClusterFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
