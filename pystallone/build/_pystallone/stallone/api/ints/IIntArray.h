#ifndef stallone_api_ints_IIntArray_H
#define stallone_api_ints_IIntArray_H

#include "java/lang/Iterable.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntIterator;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class IIntArray : public ::java::lang::Iterable {
      public:
        enum {
          mid_columns_54c6a179,
          mid_copy_4ac77731,
          mid_copyFrom_059aa494,
          mid_copyInto_059aa494,
          mid_create_62213cdb,
          mid_create_004e62f1,
          mid_get_39c7bd23,
          mid_get_d8d154b9,
          mid_getArray_dab10e75,
          mid_getColumn_b4292e93,
          mid_getRow_b4292e93,
          mid_getTable_b9d949a5,
          mid_isSparse_54c6a16a,
          mid_iterator_6c27215b,
          mid_nonzeroIterator_6c27215b,
          mid_order_54c6a179,
          mid_rows_54c6a179,
          mid_set_d8d154a6,
          mid_set_d3236aa4,
          mid_size_54c6a179,
          mid_viewColumn_62213cdb,
          mid_viewRow_62213cdb,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntArray(jobject obj) : ::java::lang::Iterable(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntArray(const IIntArray& obj) : ::java::lang::Iterable(obj) {}

        jint columns() const;
        IIntArray copy() const;
        void copyFrom(const IIntArray &) const;
        void copyInto(const IIntArray &) const;
        IIntArray create(jint) const;
        IIntArray create(jint, jint) const;
        jint get(jint) const;
        jint get(jint, jint) const;
        JArray< jint > getArray() const;
        JArray< jint > getColumn(jint) const;
        JArray< jint > getRow(jint) const;
        JArray< JArray< jint > > getTable() const;
        jboolean isSparse() const;
        ::stallone::api::ints::IIntIterator iterator() const;
        ::stallone::api::ints::IIntIterator nonzeroIterator() const;
        jint order() const;
        jint rows() const;
        void set(jint, jint) const;
        void set(jint, jint, jint) const;
        jint size() const;
        IIntArray viewColumn(jint) const;
        IIntArray viewRow(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IIntArray);

      class t_IIntArray {
      public:
        PyObject_HEAD
        IIntArray object;
        static PyObject *wrap_Object(const IIntArray&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
