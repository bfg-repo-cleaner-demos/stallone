#ifndef stallone_api_function_IGrid_H
#define stallone_api_function_IGrid_H

#include "stallone/api/discretization/IDiscretization.h"

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
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace function {

      class IGrid : public ::stallone::api::discretization::IDiscretization {
      public:
        enum {
          mid_getIndex_1efc2017,
          mid_getIndex_059aa48b,
          mid_getNeighborIndexes_62213cdb,
          mid_getNeighborMultiIndexes_e2b10697,
          mid_getNeighbors_062b33a3,
          mid_getNumberOfGridPoints_54c6a179,
          mid_getNumberOfGridPoints_39c7bd23,
          mid_getPoint_d0740085,
          mid_getPoint_a5c2d8f9,
          mid_nearestMultiIndex_c221c4b5,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IGrid(jobject obj) : ::stallone::api::discretization::IDiscretization(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IGrid(const IGrid& obj) : ::stallone::api::discretization::IDiscretization(obj) {}

        jint getIndex(const JArray< jint > &) const;
        jint getIndex(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray getNeighborIndexes(jint) const;
        ::stallone::api::ints::IIntArray getNeighborMultiIndexes(const JArray< jint > &) const;
        ::stallone::api::datasequence::IDataSequence getNeighbors(jint) const;
        jint getNumberOfGridPoints() const;
        jint getNumberOfGridPoints(jint) const;
        ::stallone::api::doubles::IDoubleArray getPoint(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray getPoint(const JArray< jint > &) const;
        ::stallone::api::ints::IIntArray nearestMultiIndex(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace function {
      extern PyTypeObject PY_TYPE(IGrid);

      class t_IGrid {
      public:
        PyObject_HEAD
        IGrid object;
        static PyObject *wrap_Object(const IGrid&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
