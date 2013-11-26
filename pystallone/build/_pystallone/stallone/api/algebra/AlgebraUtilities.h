#ifndef stallone_api_algebra_AlgebraUtilities_H
#define stallone_api_algebra_AlgebraUtilities_H

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
    }
    namespace complex {
      class IComplexArray;
    }
    namespace algebra {
      class IComplexNumber;
      class IEigenvalueDecomposition;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class AlgebraUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_add_7db6c263,
          mid_add_76419023,
          mid_add_c44f5837,
          mid_add_3313c4fb,
          mid_addTo_f5db6ac1,
          mid_addTo_608d488a,
          mid_addTo_a856213d,
          mid_addTo_1ee5623e,
          mid_addWeightedToNew_7b466925,
          mid_addWeightedToNew_2b0fc113,
          mid_columnSums_32638cb7,
          mid_createNormalized_32638cb7,
          mid_createNormalized_e79ba665,
          mid_det_02530858,
          mid_distance_608d4898,
          mid_divideElementsToNew_76419023,
          mid_dot_608d4898,
          mid_dot_0f08b618,
          mid_dotComplex_33e89a6c,
          mid_dotComplex_57553453,
          mid_dotComplexWeighted_240132e0,
          mid_dotComplexWeighted_e2044387,
          mid_evd_4642b6a7,
          mid_evd_303a3579,
          mid_evd_18dc44e5,
          mid_evd_01c65c05,
          mid_inverse_32638cb7,
          mid_invertElements_0253084a,
          mid_isSquare_02530846,
          mid_isSymmetric_02530846,
          mid_multiplyElementsToNew_76419023,
          mid_multiplyElementsToNew_7db6c263,
          mid_negate_ce2e75ca,
          mid_negate_0253084a,
          mid_norm_02530858,
          mid_norm_20d144ba,
          mid_normalize_0253084a,
          mid_normalize_20d144a8,
          mid_normalizeRows_20d144a8,
          mid_numericallyEquals_bce6070b,
          mid_numericallyEquals_cf067855,
          mid_power_e79ba665,
          mid_product_951a6d0b,
          mid_product_76419023,
          mid_product_3313c4fb,
          mid_product_c44f5837,
          mid_rowSums_32638cb7,
          mid_saveMatrixDense_e14c9e64,
          mid_saveMatrixSparse_e14c9e64,
          mid_scale_f69a7b77,
          mid_scale_b8c978f1,
          mid_scale_575d19fd,
          mid_scaleToNew_6acbffe2,
          mid_scaleToNew_cc0b12f6,
          mid_scaleToNew_280fd27a,
          mid_scaleToNew_07c71ba4,
          mid_solve_76419023,
          mid_solve_a80d54d9,
          mid_square_0253084a,
          mid_subtract_76419023,
          mid_subtract_3313c4fb,
          mid_sum_68404830,
          mid_sum_02530858,
          mid_trace_02530858,
          mid_transpose_0253084a,
          mid_transpose_ce2e75ca,
          mid_transposeToNew_2e81309f,
          mid_transposeToNew_32638cb7,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit AlgebraUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        AlgebraUtilities(const AlgebraUtilities& obj) : ::java::lang::Object(obj) {}

        AlgebraUtilities();

        ::stallone::api::complex::IComplexArray add(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray add(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::complex::IComplexArray add(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray add(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        void addTo(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        void addTo(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        void addTo(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::algebra::IComplexNumber &) const;
        void addTo(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::complex::IComplexArray addWeightedToNew(jdouble, const ::stallone::api::complex::IComplexArray &, jdouble, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray addWeightedToNew(jdouble, const ::stallone::api::doubles::IDoubleArray &, jdouble, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray columnSums(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray createNormalized(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray createNormalized(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jdouble det(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble distance(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray divideElementsToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble dot(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble dot(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IComplexNumber dotComplex(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::algebra::IComplexNumber dotComplex(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &, const ::stallone::api::algebra::IComplexNumber &) const;
        ::stallone::api::algebra::IComplexNumber dotComplexWeighted(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IComplexNumber dotComplexWeighted(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::algebra::IComplexNumber &) const;
        ::stallone::api::algebra::IEigenvalueDecomposition evd(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IEigenvalueDecomposition evd(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::algebra::IEigenvalueDecomposition evd(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        ::stallone::api::algebra::IEigenvalueDecomposition evd(const ::stallone::api::doubles::IDoubleArray &, jboolean, jboolean) const;
        ::stallone::api::doubles::IDoubleArray inverse(const ::stallone::api::doubles::IDoubleArray &) const;
        void invertElements(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isSquare(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isSymmetric(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray multiplyElementsToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::complex::IComplexArray multiplyElementsToNew(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        void negate(const ::stallone::api::complex::IComplexArray &) const;
        void negate(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble norm(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble norm(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        void normalize(const ::stallone::api::doubles::IDoubleArray &) const;
        void normalize(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        void normalizeRows(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jboolean numericallyEquals(const ::stallone::api::algebra::IComplexNumber &, const ::stallone::api::algebra::IComplexNumber &, jdouble) const;
        jboolean numericallyEquals(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray power(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray product(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray product(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray product(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::complex::IComplexArray product(const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray rowSums(const ::stallone::api::doubles::IDoubleArray &) const;
        void saveMatrixDense(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        void saveMatrixSparse(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        void scale(jdouble, const ::stallone::api::doubles::IDoubleArray &) const;
        void scale(jdouble, const ::stallone::api::complex::IComplexArray &) const;
        void scale(const ::stallone::api::algebra::IComplexNumber &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray scaleToNew(jdouble, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::complex::IComplexArray scaleToNew(const ::stallone::api::algebra::IComplexNumber &, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::complex::IComplexArray scaleToNew(jdouble, const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::complex::IComplexArray scaleToNew(const ::stallone::api::algebra::IComplexNumber &, const ::stallone::api::complex::IComplexArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray solve(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray solve(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        void square(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray subtract(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray subtract(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IComplexNumber sum(const ::stallone::api::complex::IComplexArray &) const;
        jdouble sum(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble trace(const ::stallone::api::doubles::IDoubleArray &) const;
        void transpose(const ::stallone::api::doubles::IDoubleArray &) const;
        void transpose(const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::complex::IComplexArray transposeToNew(const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::doubles::IDoubleArray transposeToNew(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(AlgebraUtilities);

      class t_AlgebraUtilities {
      public:
        PyObject_HEAD
        AlgebraUtilities object;
        static PyObject *wrap_Object(const AlgebraUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
