#ifndef stallone_api_cluster_INeighborSearch_H
#define stallone_api_cluster_INeighborSearch_H

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
      class IMetric;
    }
    namespace datasequence {
      class IDataSequence;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace cluster {

      class INeighborSearch : public ::java::lang::Object {
      public:
        enum {
          mid_nearestNeighbor_02530855,
          mid_nearestNeighbor_39c7bd23,
          mid_nearestNeighbors_acd005c5,
          mid_nearestNeighbors_8e0c7267,
          mid_neighbors_2dc291e0,
          mid_neighbors_f417ea92,
          mid_setData_d7ef70c8,
          mid_setMetric_9f46b3d3,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit INeighborSearch(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        INeighborSearch(const INeighborSearch& obj) : ::java::lang::Object(obj) {}

        jint nearestNeighbor(const ::stallone::api::doubles::IDoubleArray &) const;
        jint nearestNeighbor(jint) const;
        JArray< jint > nearestNeighbors(jint, jint) const;
        JArray< jint > nearestNeighbors(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        JArray< jint > neighbors(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        JArray< jint > neighbors(jint, jdouble) const;
        void setData(const ::stallone::api::datasequence::IDataSequence &) const;
        void setMetric(const ::stallone::api::doubles::IMetric &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace cluster {
      extern PyTypeObject PY_TYPE(INeighborSearch);

      class t_INeighborSearch {
      public:
        PyObject_HEAD
        INeighborSearch object;
        static PyObject *wrap_Object(const INeighborSearch&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
