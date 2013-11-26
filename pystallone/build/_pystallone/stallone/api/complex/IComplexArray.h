#ifndef stallone_api_complex_IComplexArray_H
#define stallone_api_complex_IComplexArray_H

#include "stallone/api/doubles/IDoubleArray.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace complex {
      class IComplexIterator;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class IComplexArray : public ::stallone::api::doubles::IDoubleArray {
      public:
        enum {
          mid_complexIterator_bbde838d,
          mid_copy_d54418bb,
          mid_copyFrom_ce2e75ca,
          mid_copyInto_ce2e75ca,
          mid_create_f6210079,
          mid_create_74a6154f,
          mid_getIm_39c7bd2e,
          mid_getIm_d8d154b4,
          mid_getImaginaryArray_dab10e78,
          mid_getImaginaryColumn_b4292e9e,
          mid_getImaginaryRow_b4292e9e,
          mid_getImaginaryTable_b9d949a8,
          mid_getRe_39c7bd2e,
          mid_getRe_d8d154b4,
          mid_getRealArray_dab10e78,
          mid_getRealColumn_b4292e9e,
          mid_getRealRow_b4292e9e,
          mid_getRealTable_b9d949a8,
          mid_isReal_54c6a16a,
          mid_nonzeroComplexIterator_bbde838d,
          mid_set_6a0b612e,
          mid_set_8b16f164,
          mid_setIm_5aa51c57,
          mid_setIm_514fa3b5,
          mid_setRe_5aa51c57,
          mid_setRe_514fa3b5,
          mid_view_eb1c1787,
          mid_viewBlock_9d679403,
          mid_viewColumn_f6210079,
          mid_viewImaginary_1d53e353,
          mid_viewReal_1d53e353,
          mid_viewRow_f6210079,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IComplexArray(jobject obj) : ::stallone::api::doubles::IDoubleArray(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IComplexArray(const IComplexArray& obj) : ::stallone::api::doubles::IDoubleArray(obj) {}

        ::stallone::api::complex::IComplexIterator complexIterator() const;
        IComplexArray copy() const;
        void copyFrom(const IComplexArray &) const;
        void copyInto(const IComplexArray &) const;
        IComplexArray create(jint) const;
        IComplexArray create(jint, jint) const;
        jdouble getIm(jint) const;
        jdouble getIm(jint, jint) const;
        JArray< jdouble > getImaginaryArray() const;
        JArray< jdouble > getImaginaryColumn(jint) const;
        JArray< jdouble > getImaginaryRow(jint) const;
        JArray< JArray< jdouble > > getImaginaryTable() const;
        jdouble getRe(jint) const;
        jdouble getRe(jint, jint) const;
        JArray< jdouble > getRealArray() const;
        JArray< jdouble > getRealColumn(jint) const;
        JArray< jdouble > getRealRow(jint) const;
        JArray< JArray< jdouble > > getRealTable() const;
        jboolean isReal() const;
        ::stallone::api::complex::IComplexIterator nonzeroComplexIterator() const;
        void set(jint, jdouble, jdouble) const;
        void set(jint, jint, jdouble, jdouble) const;
        void setIm(jint, jdouble) const;
        void setIm(jint, jint, jdouble) const;
        void setRe(jint, jdouble) const;
        void setRe(jint, jint, jdouble) const;
        IComplexArray view(const JArray< jint > &, const JArray< jint > &) const;
        IComplexArray viewBlock(jint, jint, jint, jint) const;
        IComplexArray viewColumn(jint) const;
        ::stallone::api::doubles::IDoubleArray viewImaginary() const;
        ::stallone::api::doubles::IDoubleArray viewReal() const;
        IComplexArray viewRow(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace complex {
      extern PyTypeObject PY_TYPE(IComplexArray);

      class t_IComplexArray {
      public:
        PyObject_HEAD
        IComplexArray object;
        static PyObject *wrap_Object(const IComplexArray&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
