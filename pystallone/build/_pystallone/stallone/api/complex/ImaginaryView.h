#ifndef stallone_api_complex_ImaginaryView_H
#define stallone_api_complex_ImaginaryView_H

#include "stallone/doubles/AbstractDoubleArray.h"

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
    namespace complex {
      class IComplexArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class ImaginaryView : public ::stallone::doubles::AbstractDoubleArray {
      public:
        enum {
          mid_init$_ce2e75ca,
          mid_columns_54c6a179,
          mid_copy_1d53e353,
          mid_create_e3ead0f5,
          mid_create_3cbb604f,
          mid_get_39c7bd2e,
          mid_get_d8d154b4,
          mid_getArray_dab10e78,
          mid_getColumn_b4292e9e,
          mid_getRow_b4292e9e,
          mid_getTable_b9d949a8,
          mid_isSparse_54c6a16a,
          mid_order_54c6a179,
          mid_rows_54c6a179,
          mid_set_5aa51c57,
          mid_set_514fa3b5,
          mid_size_54c6a179,
          mid_zero_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ImaginaryView(jobject obj) : ::stallone::doubles::AbstractDoubleArray(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ImaginaryView(const ImaginaryView& obj) : ::stallone::doubles::AbstractDoubleArray(obj) {}

        ImaginaryView(const ::stallone::api::complex::IComplexArray &);

        jint columns() const;
        ::stallone::api::doubles::IDoubleArray copy() const;
        ::stallone::api::doubles::IDoubleArray create(jint) const;
        ::stallone::api::doubles::IDoubleArray create(jint, jint) const;
        jdouble get(jint) const;
        jdouble get(jint, jint) const;
        JArray< jdouble > getArray() const;
        JArray< jdouble > getColumn(jint) const;
        JArray< jdouble > getRow(jint) const;
        JArray< JArray< jdouble > > getTable() const;
        jboolean isSparse() const;
        jint order() const;
        jint rows() const;
        void set(jint, jdouble) const;
        void set(jint, jint, jdouble) const;
        jint size() const;
        void zero() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace complex {
      extern PyTypeObject PY_TYPE(ImaginaryView);

      class t_ImaginaryView {
      public:
        PyObject_HEAD
        ImaginaryView object;
        static PyObject *wrap_Object(const ImaginaryView&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
