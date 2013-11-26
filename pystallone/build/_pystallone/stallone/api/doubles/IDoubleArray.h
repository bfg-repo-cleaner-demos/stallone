#ifndef stallone_api_doubles_IDoubleArray_H
#define stallone_api_doubles_IDoubleArray_H

#include "java/lang/Iterable.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleIterator;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class IDoubleArray : public ::java::lang::Iterable {
      public:
        enum {
          mid_columns_54c6a179,
          mid_copy_1d53e353,
          mid_copyFrom_0253084a,
          mid_copyInto_0253084a,
          mid_create_e3ead0f5,
          mid_create_3cbb604f,
          mid_get_39c7bd2e,
          mid_get_d8d154b4,
          mid_getArray_dab10e78,
          mid_getColumn_b4292e9e,
          mid_getRow_b4292e9e,
          mid_getTable_b9d949a8,
          mid_isSparse_54c6a16a,
          mid_iterator_c2219c49,
          mid_nonzeroIterator_c2219c49,
          mid_order_54c6a179,
          mid_rows_54c6a179,
          mid_set_5aa51c57,
          mid_set_514fa3b5,
          mid_size_54c6a179,
          mid_view_1259a6af,
          mid_viewBlock_6662d773,
          mid_viewColumn_e3ead0f5,
          mid_viewRow_e3ead0f5,
          mid_zero_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDoubleArray(jobject obj) : ::java::lang::Iterable(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDoubleArray(const IDoubleArray& obj) : ::java::lang::Iterable(obj) {}

        jint columns() const;
        IDoubleArray copy() const;
        void copyFrom(const IDoubleArray &) const;
        void copyInto(const IDoubleArray &) const;
        IDoubleArray create(jint) const;
        IDoubleArray create(jint, jint) const;
        jdouble get(jint) const;
        jdouble get(jint, jint) const;
        JArray< jdouble > getArray() const;
        JArray< jdouble > getColumn(jint) const;
        JArray< jdouble > getRow(jint) const;
        JArray< JArray< jdouble > > getTable() const;
        jboolean isSparse() const;
        ::stallone::api::doubles::IDoubleIterator iterator() const;
        ::stallone::api::doubles::IDoubleIterator nonzeroIterator() const;
        jint order() const;
        jint rows() const;
        void set(jint, jdouble) const;
        void set(jint, jint, jdouble) const;
        jint size() const;
        IDoubleArray view(const JArray< jint > &, const JArray< jint > &) const;
        IDoubleArray viewBlock(jint, jint, jint, jint) const;
        IDoubleArray viewColumn(jint) const;
        IDoubleArray viewRow(jint) const;
        void zero() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(IDoubleArray);

      class t_IDoubleArray {
      public:
        PyObject_HEAD
        IDoubleArray object;
        static PyObject *wrap_Object(const IDoubleArray&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
