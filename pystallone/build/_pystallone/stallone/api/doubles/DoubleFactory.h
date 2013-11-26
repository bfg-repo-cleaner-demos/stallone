#ifndef stallone_api_doubles_DoubleFactory_H
#define stallone_api_doubles_DoubleFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
      class IDoubleList;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class DoubleFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_array_ae6f32f9,
          mid_array_e3ead0f5,
          mid_array_381b58a8,
          mid_array_879be6f8,
          mid_array_3cbb604f,
          mid_array_25e947ee,
          mid_arrayFrom_a5c2d8f9,
          mid_arrayFrom_ccfe2d76,
          mid_arrayFrom_381b58a8,
          mid_arrayFrom_e50533dc,
          mid_arrayFrom_9f1bde93,
          mid_arrayGrid_c0244e63,
          mid_arrayRandom_e3ead0f5,
          mid_arrayRange_2ab9bf4a,
          mid_column_e3ead0f5,
          mid_denseColumn_e3ead0f5,
          mid_denseMatrix_3cbb604f,
          mid_denseRow_e3ead0f5,
          mid_diag_381b58a8,
          mid_diag_32638cb7,
          mid_diag_25e947ee,
          mid_fromFile_ae6f32f9,
          mid_identity_e3ead0f5,
          mid_list_ddaae285,
          mid_list_b2944c93,
          mid_list_0b2722e8,
          mid_listFrom_40d7ca50,
          mid_listFrom_c4eaeedd,
          mid_listFrom_4c109cc2,
          mid_listFrom_8d6e829a,
          mid_listFrom_0659110f,
          mid_listRandom_ddaae285,
          mid_listRange_6c6f4020,
          mid_matrix_ae6f32f9,
          mid_matrix_879be6f8,
          mid_matrix_3cbb604f,
          mid_matrix_f1448bb0,
          mid_matrixFrom_b7906b69,
          mid_matrixFrom_d64998e6,
          mid_matrixReshape_0a1bc13f,
          mid_row_e3ead0f5,
          mid_sparseColumn_e3ead0f5,
          mid_sparseMatrix_3cbb604f,
          mid_sparseRow_e3ead0f5,
          mid_symmetric_32638cb7,
          mid_symmetricReal_e3ead0f5,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DoubleFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DoubleFactory(const DoubleFactory& obj) : ::java::lang::Object(obj) {}

        DoubleFactory();

        ::stallone::api::doubles::IDoubleArray array(const ::java::lang::String &) const;
        ::stallone::api::doubles::IDoubleArray array(jint) const;
        ::stallone::api::doubles::IDoubleArray array(const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleArray array(const JArray< JArray< jdouble > > &) const;
        ::stallone::api::doubles::IDoubleArray array(jint, jint) const;
        ::stallone::api::doubles::IDoubleArray array(jint, jdouble) const;
        ::stallone::api::doubles::IDoubleArray arrayFrom(const JArray< jint > &) const;
        ::stallone::api::doubles::IDoubleArray arrayFrom(const JArray< jfloat > &) const;
        ::stallone::api::doubles::IDoubleArray arrayFrom(const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleArray arrayFrom(jdouble) const;
        ::stallone::api::doubles::IDoubleArray arrayFrom(jdouble, const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleArray arrayGrid(jdouble, jdouble, jint) const;
        ::stallone::api::doubles::IDoubleArray arrayRandom(jint) const;
        ::stallone::api::doubles::IDoubleArray arrayRange(jdouble, jdouble, jdouble) const;
        ::stallone::api::doubles::IDoubleArray column(jint) const;
        ::stallone::api::doubles::IDoubleArray denseColumn(jint) const;
        ::stallone::api::doubles::IDoubleArray denseMatrix(jint, jint) const;
        ::stallone::api::doubles::IDoubleArray denseRow(jint) const;
        ::stallone::api::doubles::IDoubleArray diag(const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleArray diag(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray diag(jint, jdouble) const;
        ::stallone::api::doubles::IDoubleArray fromFile(const ::java::lang::String &) const;
        ::stallone::api::doubles::IDoubleArray identity(jint) const;
        ::stallone::api::doubles::IDoubleList list(jint) const;
        ::stallone::api::doubles::IDoubleList list(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleList list(jint, jdouble) const;
        ::stallone::api::doubles::IDoubleList listFrom(const JArray< jfloat > &) const;
        ::stallone::api::doubles::IDoubleList listFrom(const JArray< jint > &) const;
        ::stallone::api::doubles::IDoubleList listFrom(const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleList listFrom(jdouble) const;
        ::stallone::api::doubles::IDoubleList listFrom(jdouble, const JArray< jdouble > &) const;
        ::stallone::api::doubles::IDoubleList listRandom(jint) const;
        ::stallone::api::doubles::IDoubleList listRange(jdouble, jdouble, jdouble) const;
        ::stallone::api::doubles::IDoubleArray matrix(const ::java::lang::String &) const;
        ::stallone::api::doubles::IDoubleArray matrix(const JArray< JArray< jdouble > > &) const;
        ::stallone::api::doubles::IDoubleArray matrix(jint, jint) const;
        ::stallone::api::doubles::IDoubleArray matrix(jint, jint, jdouble) const;
        ::stallone::api::doubles::IDoubleArray matrixFrom(const JArray< JArray< jint > > &) const;
        ::stallone::api::doubles::IDoubleArray matrixFrom(const JArray< JArray< jfloat > > &) const;
        ::stallone::api::doubles::IDoubleArray matrixReshape(const ::stallone::api::doubles::IDoubleArray &, jint, jint) const;
        ::stallone::api::doubles::IDoubleArray row(jint) const;
        ::stallone::api::doubles::IDoubleArray sparseColumn(jint) const;
        ::stallone::api::doubles::IDoubleArray sparseMatrix(jint, jint) const;
        ::stallone::api::doubles::IDoubleArray sparseRow(jint) const;
        ::stallone::api::doubles::IDoubleArray symmetric(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray symmetricReal(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(DoubleFactory);

      class t_DoubleFactory {
      public:
        PyObject_HEAD
        DoubleFactory object;
        static PyObject *wrap_Object(const DoubleFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
