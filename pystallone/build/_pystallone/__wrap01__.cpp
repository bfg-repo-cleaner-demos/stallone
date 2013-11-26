#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/AlgebraUtilities.h"
#include "java/lang/String.h"
#include "stallone/api/algebra/IEigenvalueDecomposition.h"
#include "stallone/api/complex/IComplexArray.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/algebra/IComplexNumber.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *AlgebraUtilities::class$ = NULL;
      jmethodID *AlgebraUtilities::mids$ = NULL;
      bool AlgebraUtilities::live$ = false;

      jclass AlgebraUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/AlgebraUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_add_7db6c263] = env->getMethodID(cls, "add", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_add_76419023] = env->getMethodID(cls, "add", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_add_c44f5837] = env->getMethodID(cls, "add", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_add_3313c4fb] = env->getMethodID(cls, "add", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_addTo_f5db6ac1] = env->getMethodID(cls, "addTo", "(Lstallone/api/doubles/IDoubleArray;D)V");
          mids$[mid_addTo_608d488a] = env->getMethodID(cls, "addTo", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_addTo_a856213d] = env->getMethodID(cls, "addTo", "(Lstallone/api/complex/IComplexArray;Lstallone/api/algebra/IComplexNumber;)V");
          mids$[mid_addTo_1ee5623e] = env->getMethodID(cls, "addTo", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)V");
          mids$[mid_addWeightedToNew_7b466925] = env->getMethodID(cls, "addWeightedToNew", "(DLstallone/api/complex/IComplexArray;DLstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_addWeightedToNew_2b0fc113] = env->getMethodID(cls, "addWeightedToNew", "(DLstallone/api/doubles/IDoubleArray;DLstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_columnSums_32638cb7] = env->getMethodID(cls, "columnSums", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_createNormalized_32638cb7] = env->getMethodID(cls, "createNormalized", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_createNormalized_e79ba665] = env->getMethodID(cls, "createNormalized", "(Lstallone/api/doubles/IDoubleArray;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_det_02530858] = env->getMethodID(cls, "det", "(Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_distance_608d4898] = env->getMethodID(cls, "distance", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_divideElementsToNew_76419023] = env->getMethodID(cls, "divideElementsToNew", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_dot_608d4898] = env->getMethodID(cls, "dot", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_dot_0f08b618] = env->getMethodID(cls, "dot", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_dotComplex_33e89a6c] = env->getMethodID(cls, "dotComplex", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_dotComplex_57553453] = env->getMethodID(cls, "dotComplex", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;Lstallone/api/algebra/IComplexNumber;)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_dotComplexWeighted_240132e0] = env->getMethodID(cls, "dotComplexWeighted", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_dotComplexWeighted_e2044387] = env->getMethodID(cls, "dotComplexWeighted", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/algebra/IComplexNumber;)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_evd_4642b6a7] = env->getMethodID(cls, "evd", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/algebra/IEigenvalueDecomposition;");
          mids$[mid_evd_303a3579] = env->getMethodID(cls, "evd", "(Lstallone/api/doubles/IDoubleArray;I)Lstallone/api/algebra/IEigenvalueDecomposition;");
          mids$[mid_evd_18dc44e5] = env->getMethodID(cls, "evd", "(Lstallone/api/doubles/IDoubleArray;Ljava/lang/String;)Lstallone/api/algebra/IEigenvalueDecomposition;");
          mids$[mid_evd_01c65c05] = env->getMethodID(cls, "evd", "(Lstallone/api/doubles/IDoubleArray;ZZ)Lstallone/api/algebra/IEigenvalueDecomposition;");
          mids$[mid_inverse_32638cb7] = env->getMethodID(cls, "inverse", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_invertElements_0253084a] = env->getMethodID(cls, "invertElements", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_isSquare_02530846] = env->getMethodID(cls, "isSquare", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_isSymmetric_02530846] = env->getMethodID(cls, "isSymmetric", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_multiplyElementsToNew_76419023] = env->getMethodID(cls, "multiplyElementsToNew", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_multiplyElementsToNew_7db6c263] = env->getMethodID(cls, "multiplyElementsToNew", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_negate_ce2e75ca] = env->getMethodID(cls, "negate", "(Lstallone/api/complex/IComplexArray;)V");
          mids$[mid_negate_0253084a] = env->getMethodID(cls, "negate", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_norm_02530858] = env->getMethodID(cls, "norm", "(Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_norm_20d144ba] = env->getMethodID(cls, "norm", "(Lstallone/api/doubles/IDoubleArray;I)D");
          mids$[mid_normalize_0253084a] = env->getMethodID(cls, "normalize", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_normalize_20d144a8] = env->getMethodID(cls, "normalize", "(Lstallone/api/doubles/IDoubleArray;I)V");
          mids$[mid_normalizeRows_20d144a8] = env->getMethodID(cls, "normalizeRows", "(Lstallone/api/doubles/IDoubleArray;I)V");
          mids$[mid_numericallyEquals_bce6070b] = env->getMethodID(cls, "numericallyEquals", "(Lstallone/api/algebra/IComplexNumber;Lstallone/api/algebra/IComplexNumber;D)Z");
          mids$[mid_numericallyEquals_cf067855] = env->getMethodID(cls, "numericallyEquals", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;D)Z");
          mids$[mid_power_e79ba665] = env->getMethodID(cls, "power", "(Lstallone/api/doubles/IDoubleArray;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_product_951a6d0b] = env->getMethodID(cls, "product", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_product_76419023] = env->getMethodID(cls, "product", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_product_3313c4fb] = env->getMethodID(cls, "product", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_product_c44f5837] = env->getMethodID(cls, "product", "(Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_rowSums_32638cb7] = env->getMethodID(cls, "rowSums", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_saveMatrixDense_e14c9e64] = env->getMethodID(cls, "saveMatrixDense", "(Lstallone/api/doubles/IDoubleArray;Ljava/lang/String;)V");
          mids$[mid_saveMatrixSparse_e14c9e64] = env->getMethodID(cls, "saveMatrixSparse", "(Lstallone/api/doubles/IDoubleArray;Ljava/lang/String;)V");
          mids$[mid_scale_f69a7b77] = env->getMethodID(cls, "scale", "(DLstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_scale_b8c978f1] = env->getMethodID(cls, "scale", "(DLstallone/api/complex/IComplexArray;)V");
          mids$[mid_scale_575d19fd] = env->getMethodID(cls, "scale", "(Lstallone/api/algebra/IComplexNumber;Lstallone/api/complex/IComplexArray;)V");
          mids$[mid_scaleToNew_6acbffe2] = env->getMethodID(cls, "scaleToNew", "(DLstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_scaleToNew_cc0b12f6] = env->getMethodID(cls, "scaleToNew", "(Lstallone/api/algebra/IComplexNumber;Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_scaleToNew_280fd27a] = env->getMethodID(cls, "scaleToNew", "(DLstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_scaleToNew_07c71ba4] = env->getMethodID(cls, "scaleToNew", "(Lstallone/api/algebra/IComplexNumber;Lstallone/api/complex/IComplexArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_solve_76419023] = env->getMethodID(cls, "solve", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_solve_a80d54d9] = env->getMethodID(cls, "solve", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Ljava/lang/String;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_square_0253084a] = env->getMethodID(cls, "square", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_subtract_76419023] = env->getMethodID(cls, "subtract", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_subtract_3313c4fb] = env->getMethodID(cls, "subtract", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_sum_68404830] = env->getMethodID(cls, "sum", "(Lstallone/api/complex/IComplexArray;)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_sum_02530858] = env->getMethodID(cls, "sum", "(Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_trace_02530858] = env->getMethodID(cls, "trace", "(Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_transpose_0253084a] = env->getMethodID(cls, "transpose", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_transpose_ce2e75ca] = env->getMethodID(cls, "transpose", "(Lstallone/api/complex/IComplexArray;)V");
          mids$[mid_transposeToNew_2e81309f] = env->getMethodID(cls, "transposeToNew", "(Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_transposeToNew_32638cb7] = env->getMethodID(cls, "transposeToNew", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      AlgebraUtilities::AlgebraUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::complex::IComplexArray AlgebraUtilities::add(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_add_7db6c263], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::add(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_add_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::add(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1, const ::stallone::api::complex::IComplexArray & a2) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_add_c44f5837], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::add(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_add_3313c4fb], a0.this$, a1.this$, a2.this$));
      }

      void AlgebraUtilities::addTo(const ::stallone::api::doubles::IDoubleArray & a0, jdouble a1) const
      {
        env->callVoidMethod(this$, mids$[mid_addTo_f5db6ac1], a0.this$, a1);
      }

      void AlgebraUtilities::addTo(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_addTo_608d488a], a0.this$, a1.this$);
      }

      void AlgebraUtilities::addTo(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::algebra::IComplexNumber & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_addTo_a856213d], a0.this$, a1.this$);
      }

      void AlgebraUtilities::addTo(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_addTo_1ee5623e], a0.this$, a1.this$);
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::addWeightedToNew(jdouble a0, const ::stallone::api::complex::IComplexArray & a1, jdouble a2, const ::stallone::api::complex::IComplexArray & a3) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_addWeightedToNew_7b466925], a0, a1.this$, a2, a3.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::addWeightedToNew(jdouble a0, const ::stallone::api::doubles::IDoubleArray & a1, jdouble a2, const ::stallone::api::doubles::IDoubleArray & a3) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_addWeightedToNew_2b0fc113], a0, a1.this$, a2, a3.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::columnSums(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_columnSums_32638cb7], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::createNormalized(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_createNormalized_32638cb7], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::createNormalized(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_createNormalized_e79ba665], a0.this$, a1));
      }

      jdouble AlgebraUtilities::det(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_det_02530858], a0.this$);
      }

      jdouble AlgebraUtilities::distance(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_distance_608d4898], a0.this$, a1.this$);
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::divideElementsToNew(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_divideElementsToNew_76419023], a0.this$, a1.this$));
      }

      jdouble AlgebraUtilities::dot(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_dot_608d4898], a0.this$, a1.this$);
      }

      jdouble AlgebraUtilities::dot(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return env->callDoubleMethod(this$, mids$[mid_dot_0f08b618], a0.this$, a1.this$, a2.this$);
      }

      ::stallone::api::algebra::IComplexNumber AlgebraUtilities::dotComplex(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_dotComplex_33e89a6c], a0.this$, a1.this$));
      }

      ::stallone::api::algebra::IComplexNumber AlgebraUtilities::dotComplex(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1, const ::stallone::api::algebra::IComplexNumber & a2) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_dotComplex_57553453], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::algebra::IComplexNumber AlgebraUtilities::dotComplexWeighted(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_dotComplexWeighted_240132e0], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::algebra::IComplexNumber AlgebraUtilities::dotComplexWeighted(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1, const ::stallone::api::doubles::IDoubleArray & a2, const ::stallone::api::algebra::IComplexNumber & a3) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_dotComplexWeighted_e2044387], a0.this$, a1.this$, a2.this$, a3.this$));
      }

      ::stallone::api::algebra::IEigenvalueDecomposition AlgebraUtilities::evd(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::algebra::IEigenvalueDecomposition(env->callObjectMethod(this$, mids$[mid_evd_4642b6a7], a0.this$));
      }

      ::stallone::api::algebra::IEigenvalueDecomposition AlgebraUtilities::evd(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return ::stallone::api::algebra::IEigenvalueDecomposition(env->callObjectMethod(this$, mids$[mid_evd_303a3579], a0.this$, a1));
      }

      ::stallone::api::algebra::IEigenvalueDecomposition AlgebraUtilities::evd(const ::stallone::api::doubles::IDoubleArray & a0, const ::java::lang::String & a1) const
      {
        return ::stallone::api::algebra::IEigenvalueDecomposition(env->callObjectMethod(this$, mids$[mid_evd_18dc44e5], a0.this$, a1.this$));
      }

      ::stallone::api::algebra::IEigenvalueDecomposition AlgebraUtilities::evd(const ::stallone::api::doubles::IDoubleArray & a0, jboolean a1, jboolean a2) const
      {
        return ::stallone::api::algebra::IEigenvalueDecomposition(env->callObjectMethod(this$, mids$[mid_evd_01c65c05], a0.this$, a1, a2));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::inverse(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_inverse_32638cb7], a0.this$));
      }

      void AlgebraUtilities::invertElements(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_invertElements_0253084a], a0.this$);
      }

      jboolean AlgebraUtilities::isSquare(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isSquare_02530846], a0.this$);
      }

      jboolean AlgebraUtilities::isSymmetric(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isSymmetric_02530846], a0.this$);
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::multiplyElementsToNew(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_multiplyElementsToNew_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::multiplyElementsToNew(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_multiplyElementsToNew_7db6c263], a0.this$, a1.this$));
      }

      void AlgebraUtilities::negate(const ::stallone::api::complex::IComplexArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_negate_ce2e75ca], a0.this$);
      }

      void AlgebraUtilities::negate(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_negate_0253084a], a0.this$);
      }

      jdouble AlgebraUtilities::norm(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_norm_02530858], a0.this$);
      }

      jdouble AlgebraUtilities::norm(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_norm_20d144ba], a0.this$, a1);
      }

      void AlgebraUtilities::normalize(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_normalize_0253084a], a0.this$);
      }

      void AlgebraUtilities::normalize(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        env->callVoidMethod(this$, mids$[mid_normalize_20d144a8], a0.this$, a1);
      }

      void AlgebraUtilities::normalizeRows(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        env->callVoidMethod(this$, mids$[mid_normalizeRows_20d144a8], a0.this$, a1);
      }

      jboolean AlgebraUtilities::numericallyEquals(const ::stallone::api::algebra::IComplexNumber & a0, const ::stallone::api::algebra::IComplexNumber & a1, jdouble a2) const
      {
        return env->callBooleanMethod(this$, mids$[mid_numericallyEquals_bce6070b], a0.this$, a1.this$, a2);
      }

      jboolean AlgebraUtilities::numericallyEquals(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, jdouble a2) const
      {
        return env->callBooleanMethod(this$, mids$[mid_numericallyEquals_cf067855], a0.this$, a1.this$, a2);
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::power(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_power_e79ba665], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::product(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_product_951a6d0b], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::product(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_product_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::product(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_product_3313c4fb], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::product(const ::stallone::api::complex::IComplexArray & a0, const ::stallone::api::complex::IComplexArray & a1, const ::stallone::api::complex::IComplexArray & a2) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_product_c44f5837], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::rowSums(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_rowSums_32638cb7], a0.this$));
      }

      void AlgebraUtilities::saveMatrixDense(const ::stallone::api::doubles::IDoubleArray & a0, const ::java::lang::String & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_saveMatrixDense_e14c9e64], a0.this$, a1.this$);
      }

      void AlgebraUtilities::saveMatrixSparse(const ::stallone::api::doubles::IDoubleArray & a0, const ::java::lang::String & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_saveMatrixSparse_e14c9e64], a0.this$, a1.this$);
      }

      void AlgebraUtilities::scale(jdouble a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_scale_f69a7b77], a0, a1.this$);
      }

      void AlgebraUtilities::scale(jdouble a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_scale_b8c978f1], a0, a1.this$);
      }

      void AlgebraUtilities::scale(const ::stallone::api::algebra::IComplexNumber & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_scale_575d19fd], a0.this$, a1.this$);
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::scaleToNew(jdouble a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_scaleToNew_6acbffe2], a0, a1.this$));
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::scaleToNew(const ::stallone::api::algebra::IComplexNumber & a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_scaleToNew_cc0b12f6], a0.this$, a1.this$));
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::scaleToNew(jdouble a0, const ::stallone::api::complex::IComplexArray & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_scaleToNew_280fd27a], a0, a1.this$));
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::scaleToNew(const ::stallone::api::algebra::IComplexNumber & a0, const ::stallone::api::complex::IComplexArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_scaleToNew_07c71ba4], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::solve(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_solve_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::solve(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::java::lang::String & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_solve_a80d54d9], a0.this$, a1.this$, a2.this$));
      }

      void AlgebraUtilities::square(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_square_0253084a], a0.this$);
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::subtract(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_subtract_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::subtract(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_subtract_3313c4fb], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::algebra::IComplexNumber AlgebraUtilities::sum(const ::stallone::api::complex::IComplexArray & a0) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_sum_68404830], a0.this$));
      }

      jdouble AlgebraUtilities::sum(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_sum_02530858], a0.this$);
      }

      jdouble AlgebraUtilities::trace(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_trace_02530858], a0.this$);
      }

      void AlgebraUtilities::transpose(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_transpose_0253084a], a0.this$);
      }

      void AlgebraUtilities::transpose(const ::stallone::api::complex::IComplexArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_transpose_ce2e75ca], a0.this$);
      }

      ::stallone::api::complex::IComplexArray AlgebraUtilities::transposeToNew(const ::stallone::api::complex::IComplexArray & a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_transposeToNew_2e81309f], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray AlgebraUtilities::transposeToNew(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_transposeToNew_32638cb7], a0.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_AlgebraUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_AlgebraUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_AlgebraUtilities_init_(t_AlgebraUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_AlgebraUtilities_add(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_addTo(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_addWeightedToNew(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_columnSums(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_createNormalized(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_det(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_distance(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_divideElementsToNew(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_dot(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_dotComplex(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_dotComplexWeighted(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_evd(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_inverse(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_invertElements(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_isSquare(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_isSymmetric(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_multiplyElementsToNew(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_negate(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_norm(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_normalize(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_normalizeRows(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_numericallyEquals(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_power(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_product(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_rowSums(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_saveMatrixDense(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_saveMatrixSparse(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_scale(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_scaleToNew(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_solve(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_square(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_subtract(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_sum(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_trace(t_AlgebraUtilities *self, PyObject *arg);
      static PyObject *t_AlgebraUtilities_transpose(t_AlgebraUtilities *self, PyObject *args);
      static PyObject *t_AlgebraUtilities_transposeToNew(t_AlgebraUtilities *self, PyObject *args);

      static PyMethodDef t_AlgebraUtilities__methods_[] = {
        DECLARE_METHOD(t_AlgebraUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_AlgebraUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_AlgebraUtilities, add, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, addTo, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, addWeightedToNew, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, columnSums, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, createNormalized, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, det, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, distance, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, divideElementsToNew, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, dot, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, dotComplex, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, dotComplexWeighted, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, evd, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, inverse, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, invertElements, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, isSquare, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, isSymmetric, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, multiplyElementsToNew, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, negate, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, norm, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, normalize, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, normalizeRows, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, numericallyEquals, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, power, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, product, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, rowSums, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, saveMatrixDense, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, saveMatrixSparse, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, scale, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, scaleToNew, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, solve, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, square, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, subtract, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, sum, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, trace, METH_O),
        DECLARE_METHOD(t_AlgebraUtilities, transpose, METH_VARARGS),
        DECLARE_METHOD(t_AlgebraUtilities, transposeToNew, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(AlgebraUtilities, t_AlgebraUtilities, ::java::lang::Object, AlgebraUtilities, t_AlgebraUtilities_init_, 0, 0, 0, 0, 0);

      void t_AlgebraUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(AlgebraUtilities), module, "AlgebraUtilities", 0);
      }

      void t_AlgebraUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(AlgebraUtilities).tp_dict, "class_", make_descriptor(AlgebraUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(AlgebraUtilities).tp_dict, "wrapfn_", make_descriptor(t_AlgebraUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(AlgebraUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_AlgebraUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, AlgebraUtilities::initializeClass, 1)))
          return NULL;
        return t_AlgebraUtilities::wrap_Object(AlgebraUtilities(((t_AlgebraUtilities *) arg)->object.this$));
      }
      static PyObject *t_AlgebraUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, AlgebraUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_AlgebraUtilities_init_(t_AlgebraUtilities *self, PyObject *args, PyObject *kwds)
      {
        AlgebraUtilities object((jobject) NULL);

        INT_CALL(object = AlgebraUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_AlgebraUtilities_add(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.add(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.add(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray a2((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.add(a0, a1, a2));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.add(a0, a1, a2));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "add", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_addTo(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jdouble a1;

            if (!parseArgs(args, "kD", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.addTo(a0, a1));
              Py_RETURN_NONE;
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.addTo(a0, a1));
              Py_RETURN_NONE;
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber a1((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::algebra::IComplexNumber::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.addTo(a0, a1));
              Py_RETURN_NONE;
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.addTo(a0, a1));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "addTo", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_addWeightedToNew(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 4:
          {
            jdouble a0;
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            jdouble a2;
            ::stallone::api::complex::IComplexArray a3((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "DkDk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.addWeightedToNew(a0, a1, a2, a3));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            jdouble a0;
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            jdouble a2;
            ::stallone::api::doubles::IDoubleArray a3((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "DkDk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.addWeightedToNew(a0, a1, a2, a3));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "addWeightedToNew", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_columnSums(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.columnSums(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "columnSums", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_createNormalized(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.createNormalized(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createNormalized(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createNormalized", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_det(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jdouble result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.det(a0));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "det", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_distance(t_AlgebraUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        jdouble result;

        if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.distance(a0, a1));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "distance", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_divideElementsToNew(t_AlgebraUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.divideElementsToNew(a0, a1));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "divideElementsToNew", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_dot(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.dot(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.dot(a0, a1, a2));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "dot", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_dotComplex(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.dotComplex(a0, a1));
              return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber a2((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::algebra::IComplexNumber::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.dotComplex(a0, a1, a2));
              return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "dotComplex", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_dotComplexWeighted(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 3:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.dotComplexWeighted(a0, a1, a2));
              return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber a3((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

            if (!parseArgs(args, "kkkk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::algebra::IComplexNumber::initializeClass, &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.dotComplexWeighted(a0, a1, a2, a3));
              return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "dotComplexWeighted", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_evd(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::algebra::IEigenvalueDecomposition result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.evd(a0));
              return ::stallone::api::algebra::t_IEigenvalueDecomposition::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::algebra::IEigenvalueDecomposition result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.evd(a0, a1));
              return ::stallone::api::algebra::t_IEigenvalueDecomposition::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            ::stallone::api::algebra::IEigenvalueDecomposition result((jobject) NULL);

            if (!parseArgs(args, "ks", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.evd(a0, a1));
              return ::stallone::api::algebra::t_IEigenvalueDecomposition::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jboolean a1;
            jboolean a2;
            ::stallone::api::algebra::IEigenvalueDecomposition result((jobject) NULL);

            if (!parseArgs(args, "kZZ", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.evd(a0, a1, a2));
              return ::stallone::api::algebra::t_IEigenvalueDecomposition::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "evd", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_inverse(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.inverse(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "inverse", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_invertElements(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.invertElements(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "invertElements", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_isSquare(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.isSquare(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isSquare", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_isSymmetric(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.isSymmetric(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isSymmetric", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_multiplyElementsToNew(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.multiplyElementsToNew(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.multiplyElementsToNew(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "multiplyElementsToNew", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_negate(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::complex::IComplexArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.negate(a0));
              Py_RETURN_NONE;
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.negate(a0));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "negate", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_norm(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.norm(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint a1;
            jdouble result;

            if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.norm(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "norm", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_normalize(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.normalize(a0));
              Py_RETURN_NONE;
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint a1;

            if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.normalize(a0, a1));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "normalize", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_normalizeRows(t_AlgebraUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jint a1;

        if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.normalizeRows(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "normalizeRows", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_numericallyEquals(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 3:
          {
            ::stallone::api::algebra::IComplexNumber a0((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber a1((jobject) NULL);
            jdouble a2;
            jboolean result;

            if (!parseArgs(args, "kkD", ::stallone::api::algebra::IComplexNumber::initializeClass, ::stallone::api::algebra::IComplexNumber::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.numericallyEquals(a0, a1, a2));
              Py_RETURN_BOOL(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            jdouble a2;
            jboolean result;

            if (!parseArgs(args, "kkD", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.numericallyEquals(a0, a1, a2));
              Py_RETURN_BOOL(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "numericallyEquals", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_power(t_AlgebraUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jint a1;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.power(a0, a1));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "power", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_product(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.product(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.product(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.product(a0, a1, a2));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray a2((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.product(a0, a1, a2));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "product", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_rowSums(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.rowSums(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "rowSums", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_saveMatrixDense(t_AlgebraUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);

        if (!parseArgs(args, "ks", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.saveMatrixDense(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "saveMatrixDense", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_saveMatrixSparse(t_AlgebraUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);

        if (!parseArgs(args, "ks", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.saveMatrixSparse(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "saveMatrixSparse", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_scale(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jdouble a0;
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);

            if (!parseArgs(args, "Dk", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.scale(a0, a1));
              Py_RETURN_NONE;
            }
          }
          {
            jdouble a0;
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);

            if (!parseArgs(args, "Dk", ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.scale(a0, a1));
              Py_RETURN_NONE;
            }
          }
          {
            ::stallone::api::algebra::IComplexNumber a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::algebra::IComplexNumber::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.scale(a0, a1));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "scale", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_scaleToNew(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jdouble a0;
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "Dk", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.scaleToNew(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::algebra::IComplexNumber a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::algebra::IComplexNumber::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.scaleToNew(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            jdouble a0;
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "Dk", ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.scaleToNew(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::algebra::IComplexNumber a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::algebra::IComplexNumber::initializeClass, ::stallone::api::complex::IComplexArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.scaleToNew(a0, a1, a2));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "scaleToNew", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_solve(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.solve(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::java::lang::String a2((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kks", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.solve(a0, a1, a2));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "solve", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_square(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.square(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "square", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_subtract(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.subtract(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.subtract(a0, a1, a2));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "subtract", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_sum(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::complex::IComplexArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.sum(a0));
              return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.sum(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "sum", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_trace(t_AlgebraUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jdouble result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.trace(a0));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "trace", arg);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_transpose(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.transpose(a0));
              Py_RETURN_NONE;
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::complex::IComplexArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.transpose(a0));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "transpose", args);
        return NULL;
      }

      static PyObject *t_AlgebraUtilities_transposeToNew(t_AlgebraUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::complex::IComplexArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.transposeToNew(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.transposeToNew(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "transposeToNew", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/hmm/IHMM.h"
#include "stallone/api/hmm/IHMMHiddenVariables.h"
#include "stallone/api/hmm/IHMMParameters.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace hmm {

      ::java::lang::Class *IHMM::class$ = NULL;
      jmethodID *IHMM::mids$ = NULL;
      bool IHMM::live$ = false;

      jclass IHMM::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/hmm/IHMM");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getHidden_bb1898f3] = env->getMethodID(cls, "getHidden", "(I)Lstallone/api/hmm/IHMMHiddenVariables;");
          mids$[mid_getLogLikelihood_54c6a174] = env->getMethodID(cls, "getLogLikelihood", "()D");
          mids$[mid_getLogLikelihoodHistory_dab10e78] = env->getMethodID(cls, "getLogLikelihoodHistory", "()[D");
          mids$[mid_getParameters_6a5b587d] = env->getMethodID(cls, "getParameters", "()Lstallone/api/hmm/IHMMParameters;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::hmm::IHMMHiddenVariables IHMM::getHidden(jint a0) const
      {
        return ::stallone::api::hmm::IHMMHiddenVariables(env->callObjectMethod(this$, mids$[mid_getHidden_bb1898f3], a0));
      }

      jdouble IHMM::getLogLikelihood() const
      {
        return env->callDoubleMethod(this$, mids$[mid_getLogLikelihood_54c6a174]);
      }

      JArray< jdouble > IHMM::getLogLikelihoodHistory() const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getLogLikelihoodHistory_dab10e78]));
      }

      ::stallone::api::hmm::IHMMParameters IHMM::getParameters() const
      {
        return ::stallone::api::hmm::IHMMParameters(env->callObjectMethod(this$, mids$[mid_getParameters_6a5b587d]));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace hmm {
      static PyObject *t_IHMM_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IHMM_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IHMM_getHidden(t_IHMM *self, PyObject *arg);
      static PyObject *t_IHMM_getLogLikelihood(t_IHMM *self);
      static PyObject *t_IHMM_getLogLikelihoodHistory(t_IHMM *self);
      static PyObject *t_IHMM_getParameters(t_IHMM *self);
      static PyObject *t_IHMM_get__logLikelihood(t_IHMM *self, void *data);
      static PyObject *t_IHMM_get__logLikelihoodHistory(t_IHMM *self, void *data);
      static PyObject *t_IHMM_get__parameters(t_IHMM *self, void *data);
      static PyGetSetDef t_IHMM__fields_[] = {
        DECLARE_GET_FIELD(t_IHMM, logLikelihood),
        DECLARE_GET_FIELD(t_IHMM, logLikelihoodHistory),
        DECLARE_GET_FIELD(t_IHMM, parameters),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IHMM__methods_[] = {
        DECLARE_METHOD(t_IHMM, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IHMM, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IHMM, getHidden, METH_O),
        DECLARE_METHOD(t_IHMM, getLogLikelihood, METH_NOARGS),
        DECLARE_METHOD(t_IHMM, getLogLikelihoodHistory, METH_NOARGS),
        DECLARE_METHOD(t_IHMM, getParameters, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IHMM, t_IHMM, ::java::lang::Object, IHMM, abstract_init, 0, 0, t_IHMM__fields_, 0, 0);

      void t_IHMM::install(PyObject *module)
      {
        installType(&PY_TYPE(IHMM), module, "IHMM", 0);
      }

      void t_IHMM::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IHMM).tp_dict, "class_", make_descriptor(IHMM::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IHMM).tp_dict, "wrapfn_", make_descriptor(t_IHMM::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IHMM).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IHMM_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IHMM::initializeClass, 1)))
          return NULL;
        return t_IHMM::wrap_Object(IHMM(((t_IHMM *) arg)->object.this$));
      }
      static PyObject *t_IHMM_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IHMM::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IHMM_getHidden(t_IHMM *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::hmm::IHMMHiddenVariables result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getHidden(a0));
          return ::stallone::api::hmm::t_IHMMHiddenVariables::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getHidden", arg);
        return NULL;
      }

      static PyObject *t_IHMM_getLogLikelihood(t_IHMM *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.getLogLikelihood());
        return PyFloat_FromDouble((double) result);
      }

      static PyObject *t_IHMM_getLogLikelihoodHistory(t_IHMM *self)
      {
        JArray< jdouble > result((jobject) NULL);
        OBJ_CALL(result = self->object.getLogLikelihoodHistory());
        return result.wrap();
      }

      static PyObject *t_IHMM_getParameters(t_IHMM *self)
      {
        ::stallone::api::hmm::IHMMParameters result((jobject) NULL);
        OBJ_CALL(result = self->object.getParameters());
        return ::stallone::api::hmm::t_IHMMParameters::wrap_Object(result);
      }

      static PyObject *t_IHMM_get__logLikelihood(t_IHMM *self, void *data)
      {
        jdouble value;
        OBJ_CALL(value = self->object.getLogLikelihood());
        return PyFloat_FromDouble((double) value);
      }

      static PyObject *t_IHMM_get__logLikelihoodHistory(t_IHMM *self, void *data)
      {
        JArray< jdouble > value((jobject) NULL);
        OBJ_CALL(value = self->object.getLogLikelihoodHistory());
        return value.wrap();
      }

      static PyObject *t_IHMM_get__parameters(t_IHMM *self, void *data)
      {
        ::stallone::api::hmm::IHMMParameters value((jobject) NULL);
        OBJ_CALL(value = self->object.getParameters());
        return ::stallone::api::hmm::t_IHMMParameters::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/function/IGriddedFunction.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/function/IDiscretizedFunction.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace function {

      ::java::lang::Class *IGriddedFunction::class$ = NULL;
      jmethodID *IGriddedFunction::mids$ = NULL;
      bool IGriddedFunction::live$ = false;

      jclass IGriddedFunction::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/function/IGriddedFunction");

          mids$ = new jmethodID[max_mid];
          mids$[mid_f_059aa486] = env->getMethodID(cls, "f", "(Lstallone/api/ints/IIntArray;)D");
          mids$[mid_f_1efc201a] = env->getMethodID(cls, "f", "([I)D");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jdouble IGriddedFunction::f(const ::stallone::api::ints::IIntArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_f_059aa486], a0.this$);
      }

      jdouble IGriddedFunction::f(const JArray< jint > & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_f_1efc201a], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace function {
      static PyObject *t_IGriddedFunction_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IGriddedFunction_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IGriddedFunction_f(t_IGriddedFunction *self, PyObject *args);

      static PyMethodDef t_IGriddedFunction__methods_[] = {
        DECLARE_METHOD(t_IGriddedFunction, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IGriddedFunction, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IGriddedFunction, f, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IGriddedFunction, t_IGriddedFunction, ::stallone::api::function::IGrid, IGriddedFunction, abstract_init, 0, 0, 0, 0, 0);

      void t_IGriddedFunction::install(PyObject *module)
      {
        installType(&PY_TYPE(IGriddedFunction), module, "IGriddedFunction", 0);
      }

      void t_IGriddedFunction::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IGriddedFunction).tp_dict, "class_", make_descriptor(IGriddedFunction::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IGriddedFunction).tp_dict, "wrapfn_", make_descriptor(t_IGriddedFunction::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IGriddedFunction).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IGriddedFunction_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IGriddedFunction::initializeClass, 1)))
          return NULL;
        return t_IGriddedFunction::wrap_Object(IGriddedFunction(((t_IGriddedFunction *) arg)->object.this$));
      }
      static PyObject *t_IGriddedFunction_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IGriddedFunction::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IGriddedFunction_f(t_IGriddedFunction *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "k", ::stallone::api::ints::IIntArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.f(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          {
            JArray< jint > a0((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "[I", &a0))
            {
              OBJ_CALL(result = self->object.f(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "f", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/doubles/IDoubleElement.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace doubles {

      ::java::lang::Class *IDoubleElement::class$ = NULL;
      jmethodID *IDoubleElement::mids$ = NULL;
      bool IDoubleElement::live$ = false;

      jclass IDoubleElement::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/doubles/IDoubleElement");

          mids$ = new jmethodID[max_mid];
          mids$[mid_column_54c6a179] = env->getMethodID(cls, "column", "()I");
          mids$[mid_get_54c6a174] = env->getMethodID(cls, "get", "()D");
          mids$[mid_index_54c6a179] = env->getMethodID(cls, "index", "()I");
          mids$[mid_row_54c6a179] = env->getMethodID(cls, "row", "()I");
          mids$[mid_set_5d1c7645] = env->getMethodID(cls, "set", "(D)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jint IDoubleElement::column() const
      {
        return env->callIntMethod(this$, mids$[mid_column_54c6a179]);
      }

      jdouble IDoubleElement::get() const
      {
        return env->callDoubleMethod(this$, mids$[mid_get_54c6a174]);
      }

      jint IDoubleElement::index() const
      {
        return env->callIntMethod(this$, mids$[mid_index_54c6a179]);
      }

      jint IDoubleElement::row() const
      {
        return env->callIntMethod(this$, mids$[mid_row_54c6a179]);
      }

      void IDoubleElement::set(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_set_5d1c7645], a0);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace doubles {
      static PyObject *t_IDoubleElement_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDoubleElement_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDoubleElement_column(t_IDoubleElement *self);
      static PyObject *t_IDoubleElement_get(t_IDoubleElement *self);
      static PyObject *t_IDoubleElement_index(t_IDoubleElement *self);
      static PyObject *t_IDoubleElement_row(t_IDoubleElement *self);
      static PyObject *t_IDoubleElement_set(t_IDoubleElement *self, PyObject *arg);

      static PyMethodDef t_IDoubleElement__methods_[] = {
        DECLARE_METHOD(t_IDoubleElement, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDoubleElement, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDoubleElement, column, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleElement, get, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleElement, index, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleElement, row, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleElement, set, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDoubleElement, t_IDoubleElement, ::java::lang::Object, IDoubleElement, abstract_init, 0, 0, 0, 0, 0);

      void t_IDoubleElement::install(PyObject *module)
      {
        installType(&PY_TYPE(IDoubleElement), module, "IDoubleElement", 0);
      }

      void t_IDoubleElement::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDoubleElement).tp_dict, "class_", make_descriptor(IDoubleElement::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDoubleElement).tp_dict, "wrapfn_", make_descriptor(t_IDoubleElement::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDoubleElement).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDoubleElement_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDoubleElement::initializeClass, 1)))
          return NULL;
        return t_IDoubleElement::wrap_Object(IDoubleElement(((t_IDoubleElement *) arg)->object.this$));
      }
      static PyObject *t_IDoubleElement_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDoubleElement::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDoubleElement_column(t_IDoubleElement *self)
      {
        jint result;
        OBJ_CALL(result = self->object.column());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleElement_get(t_IDoubleElement *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.get());
        return PyFloat_FromDouble((double) result);
      }

      static PyObject *t_IDoubleElement_index(t_IDoubleElement *self)
      {
        jint result;
        OBJ_CALL(result = self->object.index());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleElement_row(t_IDoubleElement *self)
      {
        jint result;
        OBJ_CALL(result = self->object.row());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleElement_set(t_IDoubleElement *self, PyObject *arg)
      {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
          OBJ_CALL(self->object.set(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "set", arg);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/complex/IComplexIterator.h"
#include "stallone/api/complex/IComplexElement.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace complex {

      ::java::lang::Class *IComplexIterator::class$ = NULL;
      jmethodID *IComplexIterator::mids$ = NULL;
      bool IComplexIterator::live$ = false;

      jclass IComplexIterator::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/complex/IComplexIterator");

          mids$ = new jmethodID[max_mid];
          mids$[mid_advance_54c6a166] = env->getMethodID(cls, "advance", "()V");
          mids$[mid_column_54c6a179] = env->getMethodID(cls, "column", "()I");
          mids$[mid_get_54c6a174] = env->getMethodID(cls, "get", "()D");
          mids$[mid_getIm_54c6a174] = env->getMethodID(cls, "getIm", "()D");
          mids$[mid_getIndex_54c6a179] = env->getMethodID(cls, "getIndex", "()I");
          mids$[mid_getRe_54c6a174] = env->getMethodID(cls, "getRe", "()D");
          mids$[mid_hasNext_54c6a16a] = env->getMethodID(cls, "hasNext", "()Z");
          mids$[mid_next_4d8c4a74] = env->getMethodID(cls, "next", "()Lstallone/api/complex/IComplexElement;");
          mids$[mid_reset_54c6a166] = env->getMethodID(cls, "reset", "()V");
          mids$[mid_row_54c6a179] = env->getMethodID(cls, "row", "()I");
          mids$[mid_set_5d1c7645] = env->getMethodID(cls, "set", "(D)V");
          mids$[mid_set_b1e28678] = env->getMethodID(cls, "set", "(DD)V");
          mids$[mid_setIm_5d1c7645] = env->getMethodID(cls, "setIm", "(D)V");
          mids$[mid_setRe_5d1c7645] = env->getMethodID(cls, "setRe", "(D)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void IComplexIterator::advance() const
      {
        env->callVoidMethod(this$, mids$[mid_advance_54c6a166]);
      }

      jint IComplexIterator::column() const
      {
        return env->callIntMethod(this$, mids$[mid_column_54c6a179]);
      }

      jdouble IComplexIterator::get() const
      {
        return env->callDoubleMethod(this$, mids$[mid_get_54c6a174]);
      }

      jdouble IComplexIterator::getIm() const
      {
        return env->callDoubleMethod(this$, mids$[mid_getIm_54c6a174]);
      }

      jint IComplexIterator::getIndex() const
      {
        return env->callIntMethod(this$, mids$[mid_getIndex_54c6a179]);
      }

      jdouble IComplexIterator::getRe() const
      {
        return env->callDoubleMethod(this$, mids$[mid_getRe_54c6a174]);
      }

      jboolean IComplexIterator::hasNext() const
      {
        return env->callBooleanMethod(this$, mids$[mid_hasNext_54c6a16a]);
      }

      ::stallone::api::complex::IComplexElement IComplexIterator::next() const
      {
        return ::stallone::api::complex::IComplexElement(env->callObjectMethod(this$, mids$[mid_next_4d8c4a74]));
      }

      void IComplexIterator::reset() const
      {
        env->callVoidMethod(this$, mids$[mid_reset_54c6a166]);
      }

      jint IComplexIterator::row() const
      {
        return env->callIntMethod(this$, mids$[mid_row_54c6a179]);
      }

      void IComplexIterator::set(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_set_5d1c7645], a0);
      }

      void IComplexIterator::set(jdouble a0, jdouble a1) const
      {
        env->callVoidMethod(this$, mids$[mid_set_b1e28678], a0, a1);
      }

      void IComplexIterator::setIm(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setIm_5d1c7645], a0);
      }

      void IComplexIterator::setRe(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setRe_5d1c7645], a0);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace complex {
      static PyObject *t_IComplexIterator_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IComplexIterator_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IComplexIterator_advance(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_column(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_get(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_getIm(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_getIndex(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_getRe(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_hasNext(t_IComplexIterator *self, PyObject *args);
      static PyObject *t_IComplexIterator_next(t_IComplexIterator *self, PyObject *args);
      static PyObject *t_IComplexIterator_reset(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_row(t_IComplexIterator *self);
      static PyObject *t_IComplexIterator_set(t_IComplexIterator *self, PyObject *args);
      static PyObject *t_IComplexIterator_setIm(t_IComplexIterator *self, PyObject *arg);
      static PyObject *t_IComplexIterator_setRe(t_IComplexIterator *self, PyObject *arg);
      static PyObject *t_IComplexIterator_get__im(t_IComplexIterator *self, void *data);
      static int t_IComplexIterator_set__im(t_IComplexIterator *self, PyObject *arg, void *data);
      static PyObject *t_IComplexIterator_get__index(t_IComplexIterator *self, void *data);
      static PyObject *t_IComplexIterator_get__re(t_IComplexIterator *self, void *data);
      static int t_IComplexIterator_set__re(t_IComplexIterator *self, PyObject *arg, void *data);
      static PyGetSetDef t_IComplexIterator__fields_[] = {
        DECLARE_GETSET_FIELD(t_IComplexIterator, im),
        DECLARE_GET_FIELD(t_IComplexIterator, index),
        DECLARE_GETSET_FIELD(t_IComplexIterator, re),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IComplexIterator__methods_[] = {
        DECLARE_METHOD(t_IComplexIterator, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IComplexIterator, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IComplexIterator, advance, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, column, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, get, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, getIm, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, getIndex, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, getRe, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, hasNext, METH_VARARGS),
        DECLARE_METHOD(t_IComplexIterator, next, METH_VARARGS),
        DECLARE_METHOD(t_IComplexIterator, reset, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, row, METH_NOARGS),
        DECLARE_METHOD(t_IComplexIterator, set, METH_VARARGS),
        DECLARE_METHOD(t_IComplexIterator, setIm, METH_O),
        DECLARE_METHOD(t_IComplexIterator, setRe, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IComplexIterator, t_IComplexIterator, ::java::util::Iterator, IComplexIterator, abstract_init, PyObject_SelfIter, ((PyObject *(*)(::java::util::t_Iterator *)) get_iterator_next< ::java::util::t_Iterator,::stallone::api::complex::t_IComplexElement >), t_IComplexIterator__fields_, 0, 0);

      void t_IComplexIterator::install(PyObject *module)
      {
        installType(&PY_TYPE(IComplexIterator), module, "IComplexIterator", 0);
      }

      void t_IComplexIterator::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IComplexIterator).tp_dict, "class_", make_descriptor(IComplexIterator::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IComplexIterator).tp_dict, "wrapfn_", make_descriptor(t_IComplexIterator::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IComplexIterator).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IComplexIterator_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IComplexIterator::initializeClass, 1)))
          return NULL;
        return t_IComplexIterator::wrap_Object(IComplexIterator(((t_IComplexIterator *) arg)->object.this$));
      }
      static PyObject *t_IComplexIterator_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IComplexIterator::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IComplexIterator_advance(t_IComplexIterator *self)
      {
        OBJ_CALL(self->object.advance());
        Py_RETURN_NONE;
      }

      static PyObject *t_IComplexIterator_column(t_IComplexIterator *self)
      {
        jint result;
        OBJ_CALL(result = self->object.column());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IComplexIterator_get(t_IComplexIterator *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.get());
        return PyFloat_FromDouble((double) result);
      }

      static PyObject *t_IComplexIterator_getIm(t_IComplexIterator *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.getIm());
        return PyFloat_FromDouble((double) result);
      }

      static PyObject *t_IComplexIterator_getIndex(t_IComplexIterator *self)
      {
        jint result;
        OBJ_CALL(result = self->object.getIndex());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IComplexIterator_getRe(t_IComplexIterator *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.getRe());
        return PyFloat_FromDouble((double) result);
      }

      static PyObject *t_IComplexIterator_hasNext(t_IComplexIterator *self, PyObject *args)
      {
        jboolean result;

        if (!parseArgs(args, ""))
        {
          OBJ_CALL(result = self->object.hasNext());
          Py_RETURN_BOOL(result);
        }

        return callSuper(&PY_TYPE(IComplexIterator), (PyObject *) self, "hasNext", args, 2);
      }

      static PyObject *t_IComplexIterator_next(t_IComplexIterator *self, PyObject *args)
      {
        ::stallone::api::complex::IComplexElement result((jobject) NULL);

        if (!parseArgs(args, ""))
        {
          OBJ_CALL(result = self->object.next());
          return ::stallone::api::complex::t_IComplexElement::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IComplexIterator), (PyObject *) self, "next", args, 2);
      }

      static PyObject *t_IComplexIterator_reset(t_IComplexIterator *self)
      {
        OBJ_CALL(self->object.reset());
        Py_RETURN_NONE;
      }

      static PyObject *t_IComplexIterator_row(t_IComplexIterator *self)
      {
        jint result;
        OBJ_CALL(result = self->object.row());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IComplexIterator_set(t_IComplexIterator *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jdouble a0;

            if (!parseArgs(args, "D", &a0))
            {
              OBJ_CALL(self->object.set(a0));
              Py_RETURN_NONE;
            }
          }
          break;
         case 2:
          {
            jdouble a0;
            jdouble a1;

            if (!parseArgs(args, "DD", &a0, &a1))
            {
              OBJ_CALL(self->object.set(a0, a1));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "set", args);
        return NULL;
      }

      static PyObject *t_IComplexIterator_setIm(t_IComplexIterator *self, PyObject *arg)
      {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
          OBJ_CALL(self->object.setIm(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setIm", arg);
        return NULL;
      }

      static PyObject *t_IComplexIterator_setRe(t_IComplexIterator *self, PyObject *arg)
      {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
          OBJ_CALL(self->object.setRe(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setRe", arg);
        return NULL;
      }

      static PyObject *t_IComplexIterator_get__im(t_IComplexIterator *self, void *data)
      {
        jdouble value;
        OBJ_CALL(value = self->object.getIm());
        return PyFloat_FromDouble((double) value);
      }
      static int t_IComplexIterator_set__im(t_IComplexIterator *self, PyObject *arg, void *data)
      {
        {
          jdouble value;
          if (!parseArg(arg, "D", &value))
          {
            INT_CALL(self->object.setIm(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "im", arg);
        return -1;
      }

      static PyObject *t_IComplexIterator_get__index(t_IComplexIterator *self, void *data)
      {
        jint value;
        OBJ_CALL(value = self->object.getIndex());
        return PyInt_FromLong((long) value);
      }

      static PyObject *t_IComplexIterator_get__re(t_IComplexIterator *self, void *data)
      {
        jdouble value;
        OBJ_CALL(value = self->object.getRe());
        return PyFloat_FromDouble((double) value);
      }
      static int t_IComplexIterator_set__re(t_IComplexIterator *self, PyObject *arg, void *data)
      {
        {
          jdouble value;
          if (!parseArg(arg, "D", &value))
          {
            INT_CALL(self->object.setRe(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "re", arg);
        return -1;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/ILUDecomposition.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *ILUDecomposition::class$ = NULL;
      jmethodID *ILUDecomposition::mids$ = NULL;
      bool ILUDecomposition::live$ = false;

      jclass ILUDecomposition::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/ILUDecomposition");

          mids$ = new jmethodID[max_mid];
          mids$[mid_det_54c6a174] = env->getMethodID(cls, "det", "()D");
          mids$[mid_getL_1d53e353] = env->getMethodID(cls, "getL", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_getU_1d53e353] = env->getMethodID(cls, "getU", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_isNonsingular_54c6a16a] = env->getMethodID(cls, "isNonsingular", "()Z");
          mids$[mid_perform_54c6a166] = env->getMethodID(cls, "perform", "()V");
          mids$[mid_setMatrix_0253084a] = env->getMethodID(cls, "setMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jdouble ILUDecomposition::det() const
      {
        return env->callDoubleMethod(this$, mids$[mid_det_54c6a174]);
      }

      ::stallone::api::doubles::IDoubleArray ILUDecomposition::getL() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getL_1d53e353]));
      }

      ::stallone::api::doubles::IDoubleArray ILUDecomposition::getU() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getU_1d53e353]));
      }

      jboolean ILUDecomposition::isNonsingular() const
      {
        return env->callBooleanMethod(this$, mids$[mid_isNonsingular_54c6a16a]);
      }

      void ILUDecomposition::perform() const
      {
        env->callVoidMethod(this$, mids$[mid_perform_54c6a166]);
      }

      void ILUDecomposition::setMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setMatrix_0253084a], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_ILUDecomposition_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ILUDecomposition_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ILUDecomposition_det(t_ILUDecomposition *self);
      static PyObject *t_ILUDecomposition_getL(t_ILUDecomposition *self);
      static PyObject *t_ILUDecomposition_getU(t_ILUDecomposition *self);
      static PyObject *t_ILUDecomposition_isNonsingular(t_ILUDecomposition *self);
      static PyObject *t_ILUDecomposition_perform(t_ILUDecomposition *self);
      static PyObject *t_ILUDecomposition_setMatrix(t_ILUDecomposition *self, PyObject *arg);
      static PyObject *t_ILUDecomposition_get__l(t_ILUDecomposition *self, void *data);
      static int t_ILUDecomposition_set__matrix(t_ILUDecomposition *self, PyObject *arg, void *data);
      static PyObject *t_ILUDecomposition_get__nonsingular(t_ILUDecomposition *self, void *data);
      static PyObject *t_ILUDecomposition_get__u(t_ILUDecomposition *self, void *data);
      static PyGetSetDef t_ILUDecomposition__fields_[] = {
        DECLARE_GET_FIELD(t_ILUDecomposition, l),
        DECLARE_SET_FIELD(t_ILUDecomposition, matrix),
        DECLARE_GET_FIELD(t_ILUDecomposition, nonsingular),
        DECLARE_GET_FIELD(t_ILUDecomposition, u),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_ILUDecomposition__methods_[] = {
        DECLARE_METHOD(t_ILUDecomposition, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ILUDecomposition, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ILUDecomposition, det, METH_NOARGS),
        DECLARE_METHOD(t_ILUDecomposition, getL, METH_NOARGS),
        DECLARE_METHOD(t_ILUDecomposition, getU, METH_NOARGS),
        DECLARE_METHOD(t_ILUDecomposition, isNonsingular, METH_NOARGS),
        DECLARE_METHOD(t_ILUDecomposition, perform, METH_NOARGS),
        DECLARE_METHOD(t_ILUDecomposition, setMatrix, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(ILUDecomposition, t_ILUDecomposition, ::java::lang::Object, ILUDecomposition, abstract_init, 0, 0, t_ILUDecomposition__fields_, 0, 0);

      void t_ILUDecomposition::install(PyObject *module)
      {
        installType(&PY_TYPE(ILUDecomposition), module, "ILUDecomposition", 0);
      }

      void t_ILUDecomposition::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(ILUDecomposition).tp_dict, "class_", make_descriptor(ILUDecomposition::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ILUDecomposition).tp_dict, "wrapfn_", make_descriptor(t_ILUDecomposition::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ILUDecomposition).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_ILUDecomposition_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, ILUDecomposition::initializeClass, 1)))
          return NULL;
        return t_ILUDecomposition::wrap_Object(ILUDecomposition(((t_ILUDecomposition *) arg)->object.this$));
      }
      static PyObject *t_ILUDecomposition_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, ILUDecomposition::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_ILUDecomposition_det(t_ILUDecomposition *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.det());
        return PyFloat_FromDouble((double) result);
      }

      static PyObject *t_ILUDecomposition_getL(t_ILUDecomposition *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getL());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_ILUDecomposition_getU(t_ILUDecomposition *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getU());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_ILUDecomposition_isNonsingular(t_ILUDecomposition *self)
      {
        jboolean result;
        OBJ_CALL(result = self->object.isNonsingular());
        Py_RETURN_BOOL(result);
      }

      static PyObject *t_ILUDecomposition_perform(t_ILUDecomposition *self)
      {
        OBJ_CALL(self->object.perform());
        Py_RETURN_NONE;
      }

      static PyObject *t_ILUDecomposition_setMatrix(t_ILUDecomposition *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setMatrix(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setMatrix", arg);
        return NULL;
      }

      static PyObject *t_ILUDecomposition_get__l(t_ILUDecomposition *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getL());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }

      static int t_ILUDecomposition_set__matrix(t_ILUDecomposition *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setMatrix(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "matrix", arg);
        return -1;
      }

      static PyObject *t_ILUDecomposition_get__nonsingular(t_ILUDecomposition *self, void *data)
      {
        jboolean value;
        OBJ_CALL(value = self->object.isNonsingular());
        Py_RETURN_BOOL(value);
      }

      static PyObject *t_ILUDecomposition_get__u(t_ILUDecomposition *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getU());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/graph/IIntEdge.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace graph {

      ::java::lang::Class *IIntEdge::class$ = NULL;
      jmethodID *IIntEdge::mids$ = NULL;
      bool IIntEdge::live$ = false;

      jclass IIntEdge::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/graph/IIntEdge");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getV1_54c6a179] = env->getMethodID(cls, "getV1", "()I");
          mids$[mid_getV2_54c6a179] = env->getMethodID(cls, "getV2", "()I");
          mids$[mid_setV1_39c7bd3c] = env->getMethodID(cls, "setV1", "(I)V");
          mids$[mid_setV2_39c7bd3c] = env->getMethodID(cls, "setV2", "(I)V");
          mids$[mid_setWeight_5d1c7645] = env->getMethodID(cls, "setWeight", "(D)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jint IIntEdge::getV1() const
      {
        return env->callIntMethod(this$, mids$[mid_getV1_54c6a179]);
      }

      jint IIntEdge::getV2() const
      {
        return env->callIntMethod(this$, mids$[mid_getV2_54c6a179]);
      }

      void IIntEdge::setV1(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setV1_39c7bd3c], a0);
      }

      void IIntEdge::setV2(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setV2_39c7bd3c], a0);
      }

      void IIntEdge::setWeight(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setWeight_5d1c7645], a0);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace graph {
      static PyObject *t_IIntEdge_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntEdge_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntEdge_getV1(t_IIntEdge *self);
      static PyObject *t_IIntEdge_getV2(t_IIntEdge *self);
      static PyObject *t_IIntEdge_setV1(t_IIntEdge *self, PyObject *arg);
      static PyObject *t_IIntEdge_setV2(t_IIntEdge *self, PyObject *arg);
      static PyObject *t_IIntEdge_setWeight(t_IIntEdge *self, PyObject *arg);
      static PyObject *t_IIntEdge_get__v1(t_IIntEdge *self, void *data);
      static int t_IIntEdge_set__v1(t_IIntEdge *self, PyObject *arg, void *data);
      static PyObject *t_IIntEdge_get__v2(t_IIntEdge *self, void *data);
      static int t_IIntEdge_set__v2(t_IIntEdge *self, PyObject *arg, void *data);
      static int t_IIntEdge_set__weight(t_IIntEdge *self, PyObject *arg, void *data);
      static PyGetSetDef t_IIntEdge__fields_[] = {
        DECLARE_GETSET_FIELD(t_IIntEdge, v1),
        DECLARE_GETSET_FIELD(t_IIntEdge, v2),
        DECLARE_SET_FIELD(t_IIntEdge, weight),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IIntEdge__methods_[] = {
        DECLARE_METHOD(t_IIntEdge, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntEdge, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntEdge, getV1, METH_NOARGS),
        DECLARE_METHOD(t_IIntEdge, getV2, METH_NOARGS),
        DECLARE_METHOD(t_IIntEdge, setV1, METH_O),
        DECLARE_METHOD(t_IIntEdge, setV2, METH_O),
        DECLARE_METHOD(t_IIntEdge, setWeight, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IIntEdge, t_IIntEdge, ::stallone::api::graph::IEdge, IIntEdge, abstract_init, 0, 0, t_IIntEdge__fields_, 0, 0);

      void t_IIntEdge::install(PyObject *module)
      {
        installType(&PY_TYPE(IIntEdge), module, "IIntEdge", 0);
      }

      void t_IIntEdge::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IIntEdge).tp_dict, "class_", make_descriptor(IIntEdge::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IIntEdge).tp_dict, "wrapfn_", make_descriptor(t_IIntEdge::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IIntEdge).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IIntEdge_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IIntEdge::initializeClass, 1)))
          return NULL;
        return t_IIntEdge::wrap_Object(IIntEdge(((t_IIntEdge *) arg)->object.this$));
      }
      static PyObject *t_IIntEdge_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IIntEdge::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IIntEdge_getV1(t_IIntEdge *self)
      {
        jint result;
        OBJ_CALL(result = self->object.getV1());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IIntEdge_getV2(t_IIntEdge *self)
      {
        jint result;
        OBJ_CALL(result = self->object.getV2());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IIntEdge_setV1(t_IIntEdge *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.setV1(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setV1", arg);
        return NULL;
      }

      static PyObject *t_IIntEdge_setV2(t_IIntEdge *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.setV2(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setV2", arg);
        return NULL;
      }

      static PyObject *t_IIntEdge_setWeight(t_IIntEdge *self, PyObject *arg)
      {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
          OBJ_CALL(self->object.setWeight(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setWeight", arg);
        return NULL;
      }

      static PyObject *t_IIntEdge_get__v1(t_IIntEdge *self, void *data)
      {
        jint value;
        OBJ_CALL(value = self->object.getV1());
        return PyInt_FromLong((long) value);
      }
      static int t_IIntEdge_set__v1(t_IIntEdge *self, PyObject *arg, void *data)
      {
        {
          jint value;
          if (!parseArg(arg, "I", &value))
          {
            INT_CALL(self->object.setV1(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "v1", arg);
        return -1;
      }

      static PyObject *t_IIntEdge_get__v2(t_IIntEdge *self, void *data)
      {
        jint value;
        OBJ_CALL(value = self->object.getV2());
        return PyInt_FromLong((long) value);
      }
      static int t_IIntEdge_set__v2(t_IIntEdge *self, PyObject *arg, void *data)
      {
        {
          jint value;
          if (!parseArg(arg, "I", &value))
          {
            INT_CALL(self->object.setV2(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "v2", arg);
        return -1;
      }

      static int t_IIntEdge_set__weight(t_IIntEdge *self, PyObject *arg, void *data)
      {
        {
          jdouble value;
          if (!parseArg(arg, "D", &value))
          {
            INT_CALL(self->object.setWeight(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "weight", arg);
        return -1;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Integer.h"
#include "java/lang/String.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Comparable.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Integer::class$ = NULL;
    jmethodID *Integer::mids$ = NULL;
    bool Integer::live$ = false;
    jint Integer::MAX_VALUE = (jint) 0;
    jint Integer::MIN_VALUE = (jint) 0;
    jint Integer::SIZE = (jint) 0;
    ::java::lang::Class *Integer::TYPE = NULL;

    jclass Integer::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Integer");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_bitCount_39c7bd23] = env->getStaticMethodID(cls, "bitCount", "(I)I");
        mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
        mids$[mid_compareTo_af7b73bb] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Integer;)I");
        mids$[mid_decode_da36ea2b] = env->getStaticMethodID(cls, "decode", "(Ljava/lang/String;)Ljava/lang/Integer;");
        mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
        mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
        mids$[mid_getInteger_da36ea2b] = env->getStaticMethodID(cls, "getInteger", "(Ljava/lang/String;)Ljava/lang/Integer;");
        mids$[mid_getInteger_fe9eddb1] = env->getStaticMethodID(cls, "getInteger", "(Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;");
        mids$[mid_getInteger_39b2b79d] = env->getStaticMethodID(cls, "getInteger", "(Ljava/lang/String;I)Ljava/lang/Integer;");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_highestOneBit_39c7bd23] = env->getStaticMethodID(cls, "highestOneBit", "(I)I");
        mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
        mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
        mids$[mid_lowestOneBit_39c7bd23] = env->getStaticMethodID(cls, "lowestOneBit", "(I)I");
        mids$[mid_numberOfLeadingZeros_39c7bd23] = env->getStaticMethodID(cls, "numberOfLeadingZeros", "(I)I");
        mids$[mid_numberOfTrailingZeros_39c7bd23] = env->getStaticMethodID(cls, "numberOfTrailingZeros", "(I)I");
        mids$[mid_parseInt_5fdc3f57] = env->getStaticMethodID(cls, "parseInt", "(Ljava/lang/String;)I");
        mids$[mid_parseInt_6e53ccd9] = env->getStaticMethodID(cls, "parseInt", "(Ljava/lang/String;I)I");
        mids$[mid_reverse_39c7bd23] = env->getStaticMethodID(cls, "reverse", "(I)I");
        mids$[mid_reverseBytes_39c7bd23] = env->getStaticMethodID(cls, "reverseBytes", "(I)I");
        mids$[mid_rotateLeft_d8d154b9] = env->getStaticMethodID(cls, "rotateLeft", "(II)I");
        mids$[mid_rotateRight_d8d154b9] = env->getStaticMethodID(cls, "rotateRight", "(II)I");
        mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
        mids$[mid_signum_39c7bd23] = env->getStaticMethodID(cls, "signum", "(I)I");
        mids$[mid_toBinaryString_141401b3] = env->getStaticMethodID(cls, "toBinaryString", "(I)Ljava/lang/String;");
        mids$[mid_toHexString_141401b3] = env->getStaticMethodID(cls, "toHexString", "(I)Ljava/lang/String;");
        mids$[mid_toOctalString_141401b3] = env->getStaticMethodID(cls, "toOctalString", "(I)Ljava/lang/String;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_toString_141401b3] = env->getStaticMethodID(cls, "toString", "(I)Ljava/lang/String;");
        mids$[mid_toString_f9118fe5] = env->getStaticMethodID(cls, "toString", "(II)Ljava/lang/String;");
        mids$[mid_valueOf_7266dabb] = env->getStaticMethodID(cls, "valueOf", "(I)Ljava/lang/Integer;");
        mids$[mid_valueOf_da36ea2b] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Integer;");
        mids$[mid_valueOf_39b2b79d] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;I)Ljava/lang/Integer;");

        class$ = (::java::lang::Class *) new JObject(cls);
        cls = (jclass) class$->this$;

        MAX_VALUE = env->getStaticIntField(cls, "MAX_VALUE");
        MIN_VALUE = env->getStaticIntField(cls, "MIN_VALUE");
        SIZE = env->getStaticIntField(cls, "SIZE");
        TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Integer::Integer(jint a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

    Integer::Integer(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    jint Integer::bitCount(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_bitCount_39c7bd23], a0);
    }

    jbyte Integer::byteValue() const
    {
      return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
    }

    jint Integer::compareTo(const Integer & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_compareTo_af7b73bb], a0.this$);
    }

    Integer Integer::decode(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_decode_da36ea2b], a0.this$));
    }

    jdouble Integer::doubleValue() const
    {
      return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
    }

    jboolean Integer::equals(const ::java::lang::Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
    }

    jfloat Integer::floatValue() const
    {
      return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
    }

    Integer Integer::getInteger(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_getInteger_da36ea2b], a0.this$));
    }

    Integer Integer::getInteger(const ::java::lang::String & a0, const Integer & a1)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_getInteger_fe9eddb1], a0.this$, a1.this$));
    }

    Integer Integer::getInteger(const ::java::lang::String & a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_getInteger_39b2b79d], a0.this$, a1));
    }

    jint Integer::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    jint Integer::highestOneBit(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_highestOneBit_39c7bd23], a0);
    }

    jint Integer::intValue() const
    {
      return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
    }

    jlong Integer::longValue() const
    {
      return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
    }

    jint Integer::lowestOneBit(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_lowestOneBit_39c7bd23], a0);
    }

    jint Integer::numberOfLeadingZeros(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_numberOfLeadingZeros_39c7bd23], a0);
    }

    jint Integer::numberOfTrailingZeros(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_numberOfTrailingZeros_39c7bd23], a0);
    }

    jint Integer::parseInt(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_parseInt_5fdc3f57], a0.this$);
    }

    jint Integer::parseInt(const ::java::lang::String & a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_parseInt_6e53ccd9], a0.this$, a1);
    }

    jint Integer::reverse(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_reverse_39c7bd23], a0);
    }

    jint Integer::reverseBytes(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_reverseBytes_39c7bd23], a0);
    }

    jint Integer::rotateLeft(jint a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_rotateLeft_d8d154b9], a0, a1);
    }

    jint Integer::rotateRight(jint a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_rotateRight_d8d154b9], a0, a1);
    }

    jshort Integer::shortValue() const
    {
      return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
    }

    jint Integer::signum(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_signum_39c7bd23], a0);
    }

    ::java::lang::String Integer::toBinaryString(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toBinaryString_141401b3], a0));
    }

    ::java::lang::String Integer::toHexString(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_141401b3], a0));
    }

    ::java::lang::String Integer::toOctalString(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toOctalString_141401b3], a0));
    }

    ::java::lang::String Integer::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    ::java::lang::String Integer::toString(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_141401b3], a0));
    }

    ::java::lang::String Integer::toString(jint a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_f9118fe5], a0, a1));
    }

    Integer Integer::valueOf(jint a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_valueOf_7266dabb], a0));
    }

    Integer Integer::valueOf(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_valueOf_da36ea2b], a0.this$));
    }

    Integer Integer::valueOf(const ::java::lang::String & a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return Integer(env->callStaticObjectMethod(cls, mids$[mid_valueOf_39b2b79d], a0.this$, a1));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Integer_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Integer_init_(t_Integer *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Integer_bitCount(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_byteValue(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_compareTo(t_Integer *self, PyObject *arg);
    static PyObject *t_Integer_decode(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_doubleValue(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_equals(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_floatValue(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_getInteger(PyTypeObject *type, PyObject *args);
    static PyObject *t_Integer_hashCode(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_highestOneBit(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_intValue(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_longValue(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_lowestOneBit(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_parseInt(PyTypeObject *type, PyObject *args);
    static PyObject *t_Integer_reverse(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_reverseBytes(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_rotateLeft(PyTypeObject *type, PyObject *args);
    static PyObject *t_Integer_rotateRight(PyTypeObject *type, PyObject *args);
    static PyObject *t_Integer_shortValue(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_signum(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_toBinaryString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_toHexString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_toOctalString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Integer_toString(t_Integer *self, PyObject *args);
    static PyObject *t_Integer_toString_(PyTypeObject *type, PyObject *args);
    static PyObject *t_Integer_valueOf(PyTypeObject *type, PyObject *args);

    static PyMethodDef t_Integer__methods_[] = {
      DECLARE_METHOD(t_Integer, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, bitCount, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, byteValue, METH_VARARGS),
      DECLARE_METHOD(t_Integer, compareTo, METH_O),
      DECLARE_METHOD(t_Integer, decode, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, doubleValue, METH_VARARGS),
      DECLARE_METHOD(t_Integer, equals, METH_VARARGS),
      DECLARE_METHOD(t_Integer, floatValue, METH_VARARGS),
      DECLARE_METHOD(t_Integer, getInteger, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Integer, hashCode, METH_VARARGS),
      DECLARE_METHOD(t_Integer, highestOneBit, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, intValue, METH_VARARGS),
      DECLARE_METHOD(t_Integer, longValue, METH_VARARGS),
      DECLARE_METHOD(t_Integer, lowestOneBit, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, numberOfLeadingZeros, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, numberOfTrailingZeros, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, parseInt, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Integer, reverse, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, reverseBytes, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, rotateLeft, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Integer, rotateRight, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Integer, shortValue, METH_VARARGS),
      DECLARE_METHOD(t_Integer, signum, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, toBinaryString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, toHexString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, toOctalString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Integer, toString, METH_VARARGS),
      DECLARE_METHOD(t_Integer, toString_, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Integer, valueOf, METH_VARARGS | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Integer, t_Integer, ::java::lang::Number, Integer, t_Integer_init_, 0, 0, 0, 0, 0);

    void t_Integer::install(PyObject *module)
    {
      installType(&PY_TYPE(Integer), module, "Integer", 0);
    }

    void t_Integer::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "class_", make_descriptor(Integer::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "wrapfn_", make_descriptor(unboxInteger));
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "boxfn_", make_descriptor(boxInteger));
      env->getClass(Integer::initializeClass);
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "MAX_VALUE", make_descriptor(Integer::MAX_VALUE));
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "MIN_VALUE", make_descriptor(Integer::MIN_VALUE));
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "SIZE", make_descriptor(Integer::SIZE));
      PyDict_SetItemString(PY_TYPE(Integer).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Integer::TYPE)));
    }

    static PyObject *t_Integer_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Integer::initializeClass, 1)))
        return NULL;
      return t_Integer::wrap_Object(Integer(((t_Integer *) arg)->object.this$));
    }
    static PyObject *t_Integer_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Integer::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Integer_init_(t_Integer *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jint a0;
          Integer object((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            INT_CALL(object = Integer(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Integer object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = Integer(a0));
            self->object = object;
            break;
          }
        }
       default:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_Integer_bitCount(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::bitCount(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "bitCount", arg);
      return NULL;
    }

    static PyObject *t_Integer_byteValue(t_Integer *self, PyObject *args)
    {
      jbyte result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.byteValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "byteValue", args, 2);
    }

    static PyObject *t_Integer_compareTo(t_Integer *self, PyObject *arg)
    {
      Integer a0((jobject) NULL);
      jint result;

      if (!parseArg(arg, "O", &::java::lang::PY_TYPE(Integer), &a0))
      {
        OBJ_CALL(result = self->object.compareTo(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "compareTo", arg);
      return NULL;
    }

    static PyObject *t_Integer_decode(PyTypeObject *type, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      Integer result((jobject) NULL);

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::decode(a0));
        return t_Integer::wrap_Object(result);
      }

      PyErr_SetArgsError(type, "decode", arg);
      return NULL;
    }

    static PyObject *t_Integer_doubleValue(t_Integer *self, PyObject *args)
    {
      jdouble result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.doubleValue());
        return PyFloat_FromDouble((double) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "doubleValue", args, 2);
    }

    static PyObject *t_Integer_equals(t_Integer *self, PyObject *args)
    {
      ::java::lang::Object a0((jobject) NULL);
      jboolean result;

      if (!parseArgs(args, "o", &a0))
      {
        OBJ_CALL(result = self->object.equals(a0));
        Py_RETURN_BOOL(result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "equals", args, 2);
    }

    static PyObject *t_Integer_floatValue(t_Integer *self, PyObject *args)
    {
      jfloat result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.floatValue());
        return PyFloat_FromDouble((double) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "floatValue", args, 2);
    }

    static PyObject *t_Integer_getInteger(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          Integer result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Integer::getInteger(a0));
            return t_Integer::wrap_Object(result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          Integer a1((jobject) NULL);
          Integer result((jobject) NULL);

          if (!parseArgs(args, "sO", &::java::lang::PY_TYPE(Integer), &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Integer::getInteger(a0, a1));
            return t_Integer::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          Integer result((jobject) NULL);

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Integer::getInteger(a0, a1));
            return t_Integer::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "getInteger", args);
      return NULL;
    }

    static PyObject *t_Integer_hashCode(t_Integer *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.hashCode());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "hashCode", args, 2);
    }

    static PyObject *t_Integer_highestOneBit(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::highestOneBit(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "highestOneBit", arg);
      return NULL;
    }

    static PyObject *t_Integer_intValue(t_Integer *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.intValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "intValue", args, 2);
    }

    static PyObject *t_Integer_longValue(t_Integer *self, PyObject *args)
    {
      jlong result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.longValue());
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "longValue", args, 2);
    }

    static PyObject *t_Integer_lowestOneBit(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::lowestOneBit(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "lowestOneBit", arg);
      return NULL;
    }

    static PyObject *t_Integer_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::numberOfLeadingZeros(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "numberOfLeadingZeros", arg);
      return NULL;
    }

    static PyObject *t_Integer_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::numberOfTrailingZeros(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "numberOfTrailingZeros", arg);
      return NULL;
    }

    static PyObject *t_Integer_parseInt(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Integer::parseInt(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Integer::parseInt(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      PyErr_SetArgsError(type, "parseInt", args);
      return NULL;
    }

    static PyObject *t_Integer_reverse(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::reverse(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "reverse", arg);
      return NULL;
    }

    static PyObject *t_Integer_reverseBytes(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::reverseBytes(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "reverseBytes", arg);
      return NULL;
    }

    static PyObject *t_Integer_rotateLeft(PyTypeObject *type, PyObject *args)
    {
      jint a0;
      jint a1;
      jint result;

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = ::java::lang::Integer::rotateLeft(a0, a1));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "rotateLeft", args);
      return NULL;
    }

    static PyObject *t_Integer_rotateRight(PyTypeObject *type, PyObject *args)
    {
      jint a0;
      jint a1;
      jint result;

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = ::java::lang::Integer::rotateRight(a0, a1));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "rotateRight", args);
      return NULL;
    }

    static PyObject *t_Integer_shortValue(t_Integer *self, PyObject *args)
    {
      jshort result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.shortValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "shortValue", args, 2);
    }

    static PyObject *t_Integer_signum(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::signum(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "signum", arg);
      return NULL;
    }

    static PyObject *t_Integer_toBinaryString(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::toBinaryString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toBinaryString", arg);
      return NULL;
    }

    static PyObject *t_Integer_toHexString(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::toHexString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toHexString", arg);
      return NULL;
    }

    static PyObject *t_Integer_toOctalString(PyTypeObject *type, PyObject *arg)
    {
      jint a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = ::java::lang::Integer::toOctalString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toOctalString", arg);
      return NULL;
    }

    static PyObject *t_Integer_toString(t_Integer *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Integer), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_Integer_toString_(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jint a0;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = ::java::lang::Integer::toString(a0));
            return j2p(result);
          }
        }
        break;
       case 2:
        {
          jint a0;
          jint a1;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "II", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Integer::toString(a0, a1));
            return j2p(result);
          }
        }
      }

      PyErr_SetArgsError(type, "toString_", args);
      return NULL;
    }

    static PyObject *t_Integer_valueOf(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jint a0;
          Integer result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = ::java::lang::Integer::valueOf(a0));
            return t_Integer::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Integer result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Integer::valueOf(a0));
            return t_Integer::wrap_Object(result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          Integer result((jobject) NULL);

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Integer::valueOf(a0, a1));
            return t_Integer::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "valueOf", args);
      return NULL;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/io/IO.h"
#include "stallone/api/io/IOUtilities.h"
#include "stallone/api/io/IOFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace io {

      ::java::lang::Class *IO::class$ = NULL;
      jmethodID *IO::mids$ = NULL;
      bool IO::live$ = false;
      ::stallone::api::io::IOFactory *IO::create = NULL;
      ::stallone::api::io::IOUtilities *IO::util = NULL;

      jclass IO::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/io/IO");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::io::IOFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/io/IOFactory;"));
          util = new ::stallone::api::io::IOUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/io/IOUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      IO::IO() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace io {
      static PyObject *t_IO_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IO_instance_(PyTypeObject *type, PyObject *arg);
      static int t_IO_init_(t_IO *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_IO__methods_[] = {
        DECLARE_METHOD(t_IO, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IO, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IO, t_IO, ::java::lang::Object, IO, t_IO_init_, 0, 0, 0, 0, 0);

      void t_IO::install(PyObject *module)
      {
        installType(&PY_TYPE(IO), module, "IO", 0);
      }

      void t_IO::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IO).tp_dict, "class_", make_descriptor(IO::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IO).tp_dict, "wrapfn_", make_descriptor(t_IO::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IO).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(IO::initializeClass);
        PyDict_SetItemString(PY_TYPE(IO).tp_dict, "create", make_descriptor(::stallone::api::io::t_IOFactory::wrap_Object(*IO::create)));
        PyDict_SetItemString(PY_TYPE(IO).tp_dict, "util", make_descriptor(::stallone::api::io::t_IOUtilities::wrap_Object(*IO::util)));
      }

      static PyObject *t_IO_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IO::initializeClass, 1)))
          return NULL;
        return t_IO::wrap_Object(IO(((t_IO *) arg)->object.this$));
      }
      static PyObject *t_IO_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IO::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_IO_init_(t_IO *self, PyObject *args, PyObject *kwds)
      {
        IO object((jobject) NULL);

        INT_CALL(object = IO());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Exception.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Exception::class$ = NULL;
    jmethodID *Exception::mids$ = NULL;
    bool Exception::live$ = false;

    jclass Exception::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Exception");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
        mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Exception::Exception() : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    Exception::Exception(const ::java::lang::String & a0) : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    Exception::Exception(const ::java::lang::Throwable & a0) : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

    Exception::Exception(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::Throwable(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Exception_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Exception_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Exception_init_(t_Exception *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_Exception__methods_[] = {
      DECLARE_METHOD(t_Exception, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Exception, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Exception, t_Exception, ::java::lang::Throwable, Exception, t_Exception_init_, 0, 0, 0, 0, 0);

    void t_Exception::install(PyObject *module)
    {
      installType(&PY_TYPE(Exception), module, "Exception", 0);
    }

    void t_Exception::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Exception).tp_dict, "class_", make_descriptor(Exception::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Exception).tp_dict, "wrapfn_", make_descriptor(t_Exception::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Exception).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Exception_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Exception::initializeClass, 1)))
        return NULL;
      return t_Exception::wrap_Object(Exception(((t_Exception *) arg)->object.this$));
    }
    static PyObject *t_Exception_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Exception::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Exception_init_(t_Exception *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          Exception object((jobject) NULL);

          INT_CALL(object = Exception());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          Exception object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = Exception(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::Throwable a0((jobject) NULL);
          Exception object((jobject) NULL);

          if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
          {
            INT_CALL(object = Exception(a0));
            self->object = object;
            break;
          }
        }
        goto err;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          ::java::lang::Throwable a1((jobject) NULL);
          Exception object((jobject) NULL);

          if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
          {
            INT_CALL(object = Exception(a0, a1));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/cluster/INeighborSearch.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/doubles/IMetric.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace cluster {

      ::java::lang::Class *INeighborSearch::class$ = NULL;
      jmethodID *INeighborSearch::mids$ = NULL;
      bool INeighborSearch::live$ = false;

      jclass INeighborSearch::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/cluster/INeighborSearch");

          mids$ = new jmethodID[max_mid];
          mids$[mid_nearestNeighbor_02530855] = env->getMethodID(cls, "nearestNeighbor", "(Lstallone/api/doubles/IDoubleArray;)I");
          mids$[mid_nearestNeighbor_39c7bd23] = env->getMethodID(cls, "nearestNeighbor", "(I)I");
          mids$[mid_nearestNeighbors_acd005c5] = env->getMethodID(cls, "nearestNeighbors", "(II)[I");
          mids$[mid_nearestNeighbors_8e0c7267] = env->getMethodID(cls, "nearestNeighbors", "(Lstallone/api/doubles/IDoubleArray;I)[I");
          mids$[mid_neighbors_2dc291e0] = env->getMethodID(cls, "neighbors", "(Lstallone/api/doubles/IDoubleArray;D)[I");
          mids$[mid_neighbors_f417ea92] = env->getMethodID(cls, "neighbors", "(ID)[I");
          mids$[mid_setData_d7ef70c8] = env->getMethodID(cls, "setData", "(Lstallone/api/datasequence/IDataSequence;)V");
          mids$[mid_setMetric_9f46b3d3] = env->getMethodID(cls, "setMetric", "(Lstallone/api/doubles/IMetric;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jint INeighborSearch::nearestNeighbor(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callIntMethod(this$, mids$[mid_nearestNeighbor_02530855], a0.this$);
      }

      jint INeighborSearch::nearestNeighbor(jint a0) const
      {
        return env->callIntMethod(this$, mids$[mid_nearestNeighbor_39c7bd23], a0);
      }

      JArray< jint > INeighborSearch::nearestNeighbors(jint a0, jint a1) const
      {
        return JArray< jint >(env->callObjectMethod(this$, mids$[mid_nearestNeighbors_acd005c5], a0, a1));
      }

      JArray< jint > INeighborSearch::nearestNeighbors(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return JArray< jint >(env->callObjectMethod(this$, mids$[mid_nearestNeighbors_8e0c7267], a0.this$, a1));
      }

      JArray< jint > INeighborSearch::neighbors(const ::stallone::api::doubles::IDoubleArray & a0, jdouble a1) const
      {
        return JArray< jint >(env->callObjectMethod(this$, mids$[mid_neighbors_2dc291e0], a0.this$, a1));
      }

      JArray< jint > INeighborSearch::neighbors(jint a0, jdouble a1) const
      {
        return JArray< jint >(env->callObjectMethod(this$, mids$[mid_neighbors_f417ea92], a0, a1));
      }

      void INeighborSearch::setData(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setData_d7ef70c8], a0.this$);
      }

      void INeighborSearch::setMetric(const ::stallone::api::doubles::IMetric & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setMetric_9f46b3d3], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace cluster {
      static PyObject *t_INeighborSearch_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_INeighborSearch_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_INeighborSearch_nearestNeighbor(t_INeighborSearch *self, PyObject *args);
      static PyObject *t_INeighborSearch_nearestNeighbors(t_INeighborSearch *self, PyObject *args);
      static PyObject *t_INeighborSearch_neighbors(t_INeighborSearch *self, PyObject *args);
      static PyObject *t_INeighborSearch_setData(t_INeighborSearch *self, PyObject *arg);
      static PyObject *t_INeighborSearch_setMetric(t_INeighborSearch *self, PyObject *arg);
      static int t_INeighborSearch_set__data(t_INeighborSearch *self, PyObject *arg, void *data);
      static int t_INeighborSearch_set__metric(t_INeighborSearch *self, PyObject *arg, void *data);
      static PyGetSetDef t_INeighborSearch__fields_[] = {
        DECLARE_SET_FIELD(t_INeighborSearch, data),
        DECLARE_SET_FIELD(t_INeighborSearch, metric),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_INeighborSearch__methods_[] = {
        DECLARE_METHOD(t_INeighborSearch, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_INeighborSearch, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_INeighborSearch, nearestNeighbor, METH_VARARGS),
        DECLARE_METHOD(t_INeighborSearch, nearestNeighbors, METH_VARARGS),
        DECLARE_METHOD(t_INeighborSearch, neighbors, METH_VARARGS),
        DECLARE_METHOD(t_INeighborSearch, setData, METH_O),
        DECLARE_METHOD(t_INeighborSearch, setMetric, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(INeighborSearch, t_INeighborSearch, ::java::lang::Object, INeighborSearch, abstract_init, 0, 0, t_INeighborSearch__fields_, 0, 0);

      void t_INeighborSearch::install(PyObject *module)
      {
        installType(&PY_TYPE(INeighborSearch), module, "INeighborSearch", 0);
      }

      void t_INeighborSearch::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(INeighborSearch).tp_dict, "class_", make_descriptor(INeighborSearch::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(INeighborSearch).tp_dict, "wrapfn_", make_descriptor(t_INeighborSearch::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(INeighborSearch).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_INeighborSearch_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, INeighborSearch::initializeClass, 1)))
          return NULL;
        return t_INeighborSearch::wrap_Object(INeighborSearch(((t_INeighborSearch *) arg)->object.this$));
      }
      static PyObject *t_INeighborSearch_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, INeighborSearch::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_INeighborSearch_nearestNeighbor(t_INeighborSearch *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint result;

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.nearestNeighbor(a0));
              return PyInt_FromLong((long) result);
            }
          }
          {
            jint a0;
            jint result;

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.nearestNeighbor(a0));
              return PyInt_FromLong((long) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "nearestNeighbor", args);
        return NULL;
      }

      static PyObject *t_INeighborSearch_nearestNeighbors(t_INeighborSearch *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jint a0;
            jint a1;
            JArray< jint > result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.nearestNeighbors(a0, a1));
              return result.wrap();
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint a1;
            JArray< jint > result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.nearestNeighbors(a0, a1));
              return result.wrap();
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "nearestNeighbors", args);
        return NULL;
      }

      static PyObject *t_INeighborSearch_neighbors(t_INeighborSearch *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jdouble a1;
            JArray< jint > result((jobject) NULL);

            if (!parseArgs(args, "kD", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.neighbors(a0, a1));
              return result.wrap();
            }
          }
          {
            jint a0;
            jdouble a1;
            JArray< jint > result((jobject) NULL);

            if (!parseArgs(args, "ID", &a0, &a1))
            {
              OBJ_CALL(result = self->object.neighbors(a0, a1));
              return result.wrap();
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "neighbors", args);
        return NULL;
      }

      static PyObject *t_INeighborSearch_setData(t_INeighborSearch *self, PyObject *arg)
      {
        ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setData(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setData", arg);
        return NULL;
      }

      static PyObject *t_INeighborSearch_setMetric(t_INeighborSearch *self, PyObject *arg)
      {
        ::stallone::api::doubles::IMetric a0((jobject) NULL);
        PyTypeObject **p0;

        if (!parseArg(arg, "K", ::stallone::api::doubles::IMetric::initializeClass, &a0, &p0, ::stallone::api::doubles::t_IMetric::parameters_))
        {
          OBJ_CALL(self->object.setMetric(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setMetric", arg);
        return NULL;
      }

      static int t_INeighborSearch_set__data(t_INeighborSearch *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::datasequence::IDataSequence value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &value))
          {
            INT_CALL(self->object.setData(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "data", arg);
        return -1;
      }

      static int t_INeighborSearch_set__metric(t_INeighborSearch *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IMetric value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IMetric::initializeClass, &value))
          {
            INT_CALL(self->object.setMetric(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "metric", arg);
        return -1;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/mc/tpt/ICommittor.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace mc {
      namespace tpt {

        ::java::lang::Class *ICommittor::class$ = NULL;
        jmethodID *ICommittor::mids$ = NULL;
        bool ICommittor::live$ = false;

        jclass ICommittor::initializeClass(bool getOnly)
        {
          if (getOnly)
            return (jclass) (live$ ? class$->this$ : NULL);
          if (class$ == NULL)
          {
            jclass cls = (jclass) env->findClass("stallone/api/mc/tpt/ICommittor");

            mids$ = new jmethodID[max_mid];
            mids$[mid_backwardCommittor_1d53e353] = env->getMethodID(cls, "backwardCommittor", "()Lstallone/api/doubles/IDoubleArray;");
            mids$[mid_forwardCommittor_1d53e353] = env->getMethodID(cls, "forwardCommittor", "()Lstallone/api/doubles/IDoubleArray;");
            mids$[mid_setRateMatrix_0253084a] = env->getMethodID(cls, "setRateMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");
            mids$[mid_setStationaryDistribution_0253084a] = env->getMethodID(cls, "setStationaryDistribution", "(Lstallone/api/doubles/IDoubleArray;)V");
            mids$[mid_setTransitionMatrix_0253084a] = env->getMethodID(cls, "setTransitionMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");

            class$ = (::java::lang::Class *) new JObject(cls);
            live$ = true;
          }
          return (jclass) class$->this$;
        }

        ::stallone::api::doubles::IDoubleArray ICommittor::backwardCommittor() const
        {
          return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_backwardCommittor_1d53e353]));
        }

        ::stallone::api::doubles::IDoubleArray ICommittor::forwardCommittor() const
        {
          return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_forwardCommittor_1d53e353]));
        }

        void ICommittor::setRateMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
        {
          env->callVoidMethod(this$, mids$[mid_setRateMatrix_0253084a], a0.this$);
        }

        void ICommittor::setStationaryDistribution(const ::stallone::api::doubles::IDoubleArray & a0) const
        {
          env->callVoidMethod(this$, mids$[mid_setStationaryDistribution_0253084a], a0.this$);
        }

        void ICommittor::setTransitionMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
        {
          env->callVoidMethod(this$, mids$[mid_setTransitionMatrix_0253084a], a0.this$);
        }
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace mc {
      namespace tpt {
        static PyObject *t_ICommittor_cast_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_ICommittor_instance_(PyTypeObject *type, PyObject *arg);
        static PyObject *t_ICommittor_backwardCommittor(t_ICommittor *self);
        static PyObject *t_ICommittor_forwardCommittor(t_ICommittor *self);
        static PyObject *t_ICommittor_setRateMatrix(t_ICommittor *self, PyObject *arg);
        static PyObject *t_ICommittor_setStationaryDistribution(t_ICommittor *self, PyObject *arg);
        static PyObject *t_ICommittor_setTransitionMatrix(t_ICommittor *self, PyObject *arg);
        static int t_ICommittor_set__rateMatrix(t_ICommittor *self, PyObject *arg, void *data);
        static int t_ICommittor_set__stationaryDistribution(t_ICommittor *self, PyObject *arg, void *data);
        static int t_ICommittor_set__transitionMatrix(t_ICommittor *self, PyObject *arg, void *data);
        static PyGetSetDef t_ICommittor__fields_[] = {
          DECLARE_SET_FIELD(t_ICommittor, rateMatrix),
          DECLARE_SET_FIELD(t_ICommittor, stationaryDistribution),
          DECLARE_SET_FIELD(t_ICommittor, transitionMatrix),
          { NULL, NULL, NULL, NULL, NULL }
        };

        static PyMethodDef t_ICommittor__methods_[] = {
          DECLARE_METHOD(t_ICommittor, cast_, METH_O | METH_CLASS),
          DECLARE_METHOD(t_ICommittor, instance_, METH_O | METH_CLASS),
          DECLARE_METHOD(t_ICommittor, backwardCommittor, METH_NOARGS),
          DECLARE_METHOD(t_ICommittor, forwardCommittor, METH_NOARGS),
          DECLARE_METHOD(t_ICommittor, setRateMatrix, METH_O),
          DECLARE_METHOD(t_ICommittor, setStationaryDistribution, METH_O),
          DECLARE_METHOD(t_ICommittor, setTransitionMatrix, METH_O),
          { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(ICommittor, t_ICommittor, ::java::lang::Object, ICommittor, abstract_init, 0, 0, t_ICommittor__fields_, 0, 0);

        void t_ICommittor::install(PyObject *module)
        {
          installType(&PY_TYPE(ICommittor), module, "ICommittor", 0);
        }

        void t_ICommittor::initialize(PyObject *module)
        {
          PyDict_SetItemString(PY_TYPE(ICommittor).tp_dict, "class_", make_descriptor(ICommittor::initializeClass, 1));
          PyDict_SetItemString(PY_TYPE(ICommittor).tp_dict, "wrapfn_", make_descriptor(t_ICommittor::wrap_jobject));
          PyDict_SetItemString(PY_TYPE(ICommittor).tp_dict, "boxfn_", make_descriptor(boxObject));
        }

        static PyObject *t_ICommittor_cast_(PyTypeObject *type, PyObject *arg)
        {
          if (!(arg = castCheck(arg, ICommittor::initializeClass, 1)))
            return NULL;
          return t_ICommittor::wrap_Object(ICommittor(((t_ICommittor *) arg)->object.this$));
        }
        static PyObject *t_ICommittor_instance_(PyTypeObject *type, PyObject *arg)
        {
          if (!castCheck(arg, ICommittor::initializeClass, 0))
            Py_RETURN_FALSE;
          Py_RETURN_TRUE;
        }

        static PyObject *t_ICommittor_backwardCommittor(t_ICommittor *self)
        {
          ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
          OBJ_CALL(result = self->object.backwardCommittor());
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        static PyObject *t_ICommittor_forwardCommittor(t_ICommittor *self)
        {
          ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
          OBJ_CALL(result = self->object.forwardCommittor());
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        static PyObject *t_ICommittor_setRateMatrix(t_ICommittor *self, PyObject *arg)
        {
          ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
          {
            OBJ_CALL(self->object.setRateMatrix(a0));
            Py_RETURN_NONE;
          }

          PyErr_SetArgsError((PyObject *) self, "setRateMatrix", arg);
          return NULL;
        }

        static PyObject *t_ICommittor_setStationaryDistribution(t_ICommittor *self, PyObject *arg)
        {
          ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
          {
            OBJ_CALL(self->object.setStationaryDistribution(a0));
            Py_RETURN_NONE;
          }

          PyErr_SetArgsError((PyObject *) self, "setStationaryDistribution", arg);
          return NULL;
        }

        static PyObject *t_ICommittor_setTransitionMatrix(t_ICommittor *self, PyObject *arg)
        {
          ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
          {
            OBJ_CALL(self->object.setTransitionMatrix(a0));
            Py_RETURN_NONE;
          }

          PyErr_SetArgsError((PyObject *) self, "setTransitionMatrix", arg);
          return NULL;
        }

        static int t_ICommittor_set__rateMatrix(t_ICommittor *self, PyObject *arg, void *data)
        {
          {
            ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
            if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
            {
              INT_CALL(self->object.setRateMatrix(value));
              return 0;
            }
          }
          PyErr_SetArgsError((PyObject *) self, "rateMatrix", arg);
          return -1;
        }

        static int t_ICommittor_set__stationaryDistribution(t_ICommittor *self, PyObject *arg, void *data)
        {
          {
            ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
            if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
            {
              INT_CALL(self->object.setStationaryDistribution(value));
              return 0;
            }
          }
          PyErr_SetArgsError((PyObject *) self, "stationaryDistribution", arg);
          return -1;
        }

        static int t_ICommittor_set__transitionMatrix(t_ICommittor *self, PyObject *arg, void *data)
        {
          {
            ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
            if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
            {
              INT_CALL(self->object.setTransitionMatrix(value));
              return 0;
            }
          }
          PyErr_SetArgsError((PyObject *) self, "transitionMatrix", arg);
          return -1;
        }
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Double.h"
#include "java/lang/String.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Comparable.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Double::class$ = NULL;
    jmethodID *Double::mids$ = NULL;
    bool Double::live$ = false;
    jint Double::MAX_EXPONENT = (jint) 0;
    jdouble Double::MAX_VALUE = (jdouble) 0;
    jint Double::MIN_EXPONENT = (jint) 0;
    jdouble Double::MIN_NORMAL = (jdouble) 0;
    jdouble Double::MIN_VALUE = (jdouble) 0;
    jdouble Double::NEGATIVE_INFINITY = (jdouble) 0;
    jdouble Double::NaN = (jdouble) 0;
    jdouble Double::POSITIVE_INFINITY = (jdouble) 0;
    jint Double::SIZE = (jint) 0;
    ::java::lang::Class *Double::TYPE = NULL;

    jclass Double::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Double");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_5d1c7645] = env->getMethodID(cls, "<init>", "(D)V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
        mids$[mid_compare_b1e28667] = env->getStaticMethodID(cls, "compare", "(DD)I");
        mids$[mid_compareTo_8baed073] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Double;)I");
        mids$[mid_doubleToLongBits_5d1c7659] = env->getStaticMethodID(cls, "doubleToLongBits", "(D)J");
        mids$[mid_doubleToRawLongBits_5d1c7659] = env->getStaticMethodID(cls, "doubleToRawLongBits", "(D)J");
        mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
        mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
        mids$[mid_isInfinite_54c6a16a] = env->getMethodID(cls, "isInfinite", "()Z");
        mids$[mid_isInfinite_5d1c7649] = env->getStaticMethodID(cls, "isInfinite", "(D)Z");
        mids$[mid_isNaN_54c6a16a] = env->getMethodID(cls, "isNaN", "()Z");
        mids$[mid_isNaN_5d1c7649] = env->getStaticMethodID(cls, "isNaN", "(D)Z");
        mids$[mid_longBitsToDouble_0ee6df3d] = env->getStaticMethodID(cls, "longBitsToDouble", "(J)D");
        mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
        mids$[mid_parseDouble_5fdc3f5a] = env->getStaticMethodID(cls, "parseDouble", "(Ljava/lang/String;)D");
        mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
        mids$[mid_toHexString_1b4624f8] = env->getStaticMethodID(cls, "toHexString", "(D)Ljava/lang/String;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_toString_1b4624f8] = env->getStaticMethodID(cls, "toString", "(D)Ljava/lang/String;");
        mids$[mid_valueOf_ad1fcbf0] = env->getStaticMethodID(cls, "valueOf", "(D)Ljava/lang/Double;");
        mids$[mid_valueOf_16296787] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Double;");

        class$ = (::java::lang::Class *) new JObject(cls);
        cls = (jclass) class$->this$;

        MAX_EXPONENT = env->getStaticIntField(cls, "MAX_EXPONENT");
        MAX_VALUE = env->getStaticDoubleField(cls, "MAX_VALUE");
        MIN_EXPONENT = env->getStaticIntField(cls, "MIN_EXPONENT");
        MIN_NORMAL = env->getStaticDoubleField(cls, "MIN_NORMAL");
        MIN_VALUE = env->getStaticDoubleField(cls, "MIN_VALUE");
        NEGATIVE_INFINITY = env->getStaticDoubleField(cls, "NEGATIVE_INFINITY");
        NaN = env->getStaticDoubleField(cls, "NaN");
        POSITIVE_INFINITY = env->getStaticDoubleField(cls, "POSITIVE_INFINITY");
        SIZE = env->getStaticIntField(cls, "SIZE");
        TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Double::Double(jdouble a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5d1c7645, a0)) {}

    Double::Double(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    jbyte Double::byteValue() const
    {
      return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
    }

    jint Double::compare(jdouble a0, jdouble a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_compare_b1e28667], a0, a1);
    }

    jint Double::compareTo(const Double & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_compareTo_8baed073], a0.this$);
    }

    jlong Double::doubleToLongBits(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_doubleToLongBits_5d1c7659], a0);
    }

    jlong Double::doubleToRawLongBits(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_doubleToRawLongBits_5d1c7659], a0);
    }

    jdouble Double::doubleValue() const
    {
      return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
    }

    jboolean Double::equals(const ::java::lang::Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
    }

    jfloat Double::floatValue() const
    {
      return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
    }

    jint Double::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    jint Double::intValue() const
    {
      return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
    }

    jboolean Double::isInfinite() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isInfinite_54c6a16a]);
    }

    jboolean Double::isInfinite(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticBooleanMethod(cls, mids$[mid_isInfinite_5d1c7649], a0);
    }

    jboolean Double::isNaN() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isNaN_54c6a16a]);
    }

    jboolean Double::isNaN(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticBooleanMethod(cls, mids$[mid_isNaN_5d1c7649], a0);
    }

    jdouble Double::longBitsToDouble(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticDoubleMethod(cls, mids$[mid_longBitsToDouble_0ee6df3d], a0);
    }

    jlong Double::longValue() const
    {
      return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
    }

    jdouble Double::parseDouble(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticDoubleMethod(cls, mids$[mid_parseDouble_5fdc3f5a], a0.this$);
    }

    jshort Double::shortValue() const
    {
      return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
    }

    ::java::lang::String Double::toHexString(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_1b4624f8], a0));
    }

    ::java::lang::String Double::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    ::java::lang::String Double::toString(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_1b4624f8], a0));
    }

    Double Double::valueOf(jdouble a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Double(env->callStaticObjectMethod(cls, mids$[mid_valueOf_ad1fcbf0], a0));
    }

    Double Double::valueOf(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Double(env->callStaticObjectMethod(cls, mids$[mid_valueOf_16296787], a0.this$));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Double_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Double_init_(t_Double *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Double_byteValue(t_Double *self, PyObject *args);
    static PyObject *t_Double_compare(PyTypeObject *type, PyObject *args);
    static PyObject *t_Double_compareTo(t_Double *self, PyObject *arg);
    static PyObject *t_Double_doubleToLongBits(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_doubleToRawLongBits(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_doubleValue(t_Double *self, PyObject *args);
    static PyObject *t_Double_equals(t_Double *self, PyObject *args);
    static PyObject *t_Double_floatValue(t_Double *self, PyObject *args);
    static PyObject *t_Double_hashCode(t_Double *self, PyObject *args);
    static PyObject *t_Double_intValue(t_Double *self, PyObject *args);
    static PyObject *t_Double_isInfinite(t_Double *self);
    static PyObject *t_Double_isInfinite_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_isNaN(t_Double *self);
    static PyObject *t_Double_isNaN_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_longBitsToDouble(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_longValue(t_Double *self, PyObject *args);
    static PyObject *t_Double_parseDouble(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_shortValue(t_Double *self, PyObject *args);
    static PyObject *t_Double_toHexString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Double_toString(t_Double *self, PyObject *args);
    static PyObject *t_Double_toString_(PyTypeObject *type, PyObject *args);
    static PyObject *t_Double_valueOf(PyTypeObject *type, PyObject *args);
    static PyObject *t_Double_get__infinite(t_Double *self, void *data);
    static PyObject *t_Double_get__naN(t_Double *self, void *data);
    static PyGetSetDef t_Double__fields_[] = {
      DECLARE_GET_FIELD(t_Double, infinite),
      DECLARE_GET_FIELD(t_Double, naN),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Double__methods_[] = {
      DECLARE_METHOD(t_Double, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, byteValue, METH_VARARGS),
      DECLARE_METHOD(t_Double, compare, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Double, compareTo, METH_O),
      DECLARE_METHOD(t_Double, doubleToLongBits, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, doubleToRawLongBits, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, doubleValue, METH_VARARGS),
      DECLARE_METHOD(t_Double, equals, METH_VARARGS),
      DECLARE_METHOD(t_Double, floatValue, METH_VARARGS),
      DECLARE_METHOD(t_Double, hashCode, METH_VARARGS),
      DECLARE_METHOD(t_Double, intValue, METH_VARARGS),
      DECLARE_METHOD(t_Double, isInfinite, METH_NOARGS),
      DECLARE_METHOD(t_Double, isInfinite_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, isNaN, METH_NOARGS),
      DECLARE_METHOD(t_Double, isNaN_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, longBitsToDouble, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, longValue, METH_VARARGS),
      DECLARE_METHOD(t_Double, parseDouble, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, shortValue, METH_VARARGS),
      DECLARE_METHOD(t_Double, toHexString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, toString, METH_VARARGS),
      DECLARE_METHOD(t_Double, toString_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Double, valueOf, METH_VARARGS | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Double, t_Double, ::java::lang::Number, Double, t_Double_init_, 0, 0, t_Double__fields_, 0, 0);

    void t_Double::install(PyObject *module)
    {
      installType(&PY_TYPE(Double), module, "Double", 0);
    }

    void t_Double::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "class_", make_descriptor(Double::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "wrapfn_", make_descriptor(unboxDouble));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "boxfn_", make_descriptor(boxDouble));
      env->getClass(Double::initializeClass);
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MAX_EXPONENT", make_descriptor(Double::MAX_EXPONENT));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MAX_VALUE", make_descriptor(Double::MAX_VALUE));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MIN_EXPONENT", make_descriptor(Double::MIN_EXPONENT));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MIN_NORMAL", make_descriptor(Double::MIN_NORMAL));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "MIN_VALUE", make_descriptor(Double::MIN_VALUE));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "NEGATIVE_INFINITY", make_descriptor(Double::NEGATIVE_INFINITY));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "NaN", make_descriptor(Double::NaN));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "POSITIVE_INFINITY", make_descriptor(Double::POSITIVE_INFINITY));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "SIZE", make_descriptor(Double::SIZE));
      PyDict_SetItemString(PY_TYPE(Double).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Double::TYPE)));
    }

    static PyObject *t_Double_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Double::initializeClass, 1)))
        return NULL;
      return t_Double::wrap_Object(Double(((t_Double *) arg)->object.this$));
    }
    static PyObject *t_Double_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Double::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Double_init_(t_Double *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jdouble a0;
          Double object((jobject) NULL);

          if (!parseArgs(args, "D", &a0))
          {
            INT_CALL(object = Double(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Double object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = Double(a0));
            self->object = object;
            break;
          }
        }
       default:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_Double_byteValue(t_Double *self, PyObject *args)
    {
      jbyte result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.byteValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "byteValue", args, 2);
    }

    static PyObject *t_Double_compare(PyTypeObject *type, PyObject *args)
    {
      jdouble a0;
      jdouble a1;
      jint result;

      if (!parseArgs(args, "DD", &a0, &a1))
      {
        OBJ_CALL(result = ::java::lang::Double::compare(a0, a1));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "compare", args);
      return NULL;
    }

    static PyObject *t_Double_compareTo(t_Double *self, PyObject *arg)
    {
      Double a0((jobject) NULL);
      jint result;

      if (!parseArg(arg, "O", &::java::lang::PY_TYPE(Double), &a0))
      {
        OBJ_CALL(result = self->object.compareTo(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "compareTo", arg);
      return NULL;
    }

    static PyObject *t_Double_doubleToLongBits(PyTypeObject *type, PyObject *arg)
    {
      jdouble a0;
      jlong result;

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::doubleToLongBits(a0));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "doubleToLongBits", arg);
      return NULL;
    }

    static PyObject *t_Double_doubleToRawLongBits(PyTypeObject *type, PyObject *arg)
    {
      jdouble a0;
      jlong result;

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::doubleToRawLongBits(a0));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "doubleToRawLongBits", arg);
      return NULL;
    }

    static PyObject *t_Double_doubleValue(t_Double *self, PyObject *args)
    {
      jdouble result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.doubleValue());
        return PyFloat_FromDouble((double) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "doubleValue", args, 2);
    }

    static PyObject *t_Double_equals(t_Double *self, PyObject *args)
    {
      ::java::lang::Object a0((jobject) NULL);
      jboolean result;

      if (!parseArgs(args, "o", &a0))
      {
        OBJ_CALL(result = self->object.equals(a0));
        Py_RETURN_BOOL(result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "equals", args, 2);
    }

    static PyObject *t_Double_floatValue(t_Double *self, PyObject *args)
    {
      jfloat result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.floatValue());
        return PyFloat_FromDouble((double) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "floatValue", args, 2);
    }

    static PyObject *t_Double_hashCode(t_Double *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.hashCode());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "hashCode", args, 2);
    }

    static PyObject *t_Double_intValue(t_Double *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.intValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "intValue", args, 2);
    }

    static PyObject *t_Double_isInfinite(t_Double *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isInfinite());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Double_isInfinite_(PyTypeObject *type, PyObject *arg)
    {
      jdouble a0;
      jboolean result;

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::isInfinite(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError(type, "isInfinite_", arg);
      return NULL;
    }

    static PyObject *t_Double_isNaN(t_Double *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isNaN());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Double_isNaN_(PyTypeObject *type, PyObject *arg)
    {
      jdouble a0;
      jboolean result;

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::isNaN(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError(type, "isNaN_", arg);
      return NULL;
    }

    static PyObject *t_Double_longBitsToDouble(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jdouble result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::longBitsToDouble(a0));
        return PyFloat_FromDouble((double) result);
      }

      PyErr_SetArgsError(type, "longBitsToDouble", arg);
      return NULL;
    }

    static PyObject *t_Double_longValue(t_Double *self, PyObject *args)
    {
      jlong result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.longValue());
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "longValue", args, 2);
    }

    static PyObject *t_Double_parseDouble(PyTypeObject *type, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      jdouble result;

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::parseDouble(a0));
        return PyFloat_FromDouble((double) result);
      }

      PyErr_SetArgsError(type, "parseDouble", arg);
      return NULL;
    }

    static PyObject *t_Double_shortValue(t_Double *self, PyObject *args)
    {
      jshort result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.shortValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "shortValue", args, 2);
    }

    static PyObject *t_Double_toHexString(PyTypeObject *type, PyObject *arg)
    {
      jdouble a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::toHexString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toHexString", arg);
      return NULL;
    }

    static PyObject *t_Double_toString(t_Double *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Double), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_Double_toString_(PyTypeObject *type, PyObject *args)
    {
      jdouble a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, "D", &a0))
      {
        OBJ_CALL(result = ::java::lang::Double::toString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toString_", args);
      return NULL;
    }

    static PyObject *t_Double_valueOf(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jdouble a0;
          Double result((jobject) NULL);

          if (!parseArgs(args, "D", &a0))
          {
            OBJ_CALL(result = ::java::lang::Double::valueOf(a0));
            return t_Double::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Double result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Double::valueOf(a0));
            return t_Double::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "valueOf", args);
      return NULL;
    }

    static PyObject *t_Double_get__infinite(t_Double *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isInfinite());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Double_get__naN(t_Double *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isNaN());
      Py_RETURN_BOOL(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/stat/IParameterEstimator.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace stat {

      ::java::lang::Class *IParameterEstimator::class$ = NULL;
      jmethodID *IParameterEstimator::mids$ = NULL;
      bool IParameterEstimator::live$ = false;

      jclass IParameterEstimator::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/stat/IParameterEstimator");

          mids$ = new jmethodID[max_mid];
          mids$[mid_addToEstimate_d7ef70c8] = env->getMethodID(cls, "addToEstimate", "(Lstallone/api/datasequence/IDataSequence;)V");
          mids$[mid_addToEstimate_86440024] = env->getMethodID(cls, "addToEstimate", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_copy_e97d706e] = env->getMethodID(cls, "copy", "()Lstallone/api/stat/IParameterEstimator;");
          mids$[mid_estimate_2f8669d9] = env->getMethodID(cls, "estimate", "(Lstallone/api/datasequence/IDataSequence;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimate_9e4ae5c1] = env->getMethodID(cls, "estimate", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_getEstimate_1d53e353] = env->getMethodID(cls, "getEstimate", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_initialize_54c6a166] = env->getMethodID(cls, "initialize", "()V");
          mids$[mid_initialize_0253084a] = env->getMethodID(cls, "initialize", "(Lstallone/api/doubles/IDoubleArray;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void IParameterEstimator::addToEstimate(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_addToEstimate_d7ef70c8], a0.this$);
      }

      void IParameterEstimator::addToEstimate(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_addToEstimate_86440024], a0.this$, a1.this$);
      }

      IParameterEstimator IParameterEstimator::copy() const
      {
        return IParameterEstimator(env->callObjectMethod(this$, mids$[mid_copy_e97d706e]));
      }

      ::stallone::api::doubles::IDoubleArray IParameterEstimator::estimate(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimate_2f8669d9], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray IParameterEstimator::estimate(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimate_9e4ae5c1], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray IParameterEstimator::getEstimate() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getEstimate_1d53e353]));
      }

      void IParameterEstimator::initialize() const
      {
        env->callVoidMethod(this$, mids$[mid_initialize_54c6a166]);
      }

      void IParameterEstimator::initialize(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_initialize_0253084a], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace stat {
      static PyObject *t_IParameterEstimator_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IParameterEstimator_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IParameterEstimator_addToEstimate(t_IParameterEstimator *self, PyObject *args);
      static PyObject *t_IParameterEstimator_copy(t_IParameterEstimator *self);
      static PyObject *t_IParameterEstimator_estimate(t_IParameterEstimator *self, PyObject *args);
      static PyObject *t_IParameterEstimator_getEstimate(t_IParameterEstimator *self);
      static PyObject *t_IParameterEstimator_initialize(t_IParameterEstimator *self, PyObject *args);

      static PyMethodDef t_IParameterEstimator__methods_[] = {
        DECLARE_METHOD(t_IParameterEstimator, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IParameterEstimator, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IParameterEstimator, addToEstimate, METH_VARARGS),
        DECLARE_METHOD(t_IParameterEstimator, copy, METH_NOARGS),
        DECLARE_METHOD(t_IParameterEstimator, estimate, METH_VARARGS),
        DECLARE_METHOD(t_IParameterEstimator, getEstimate, METH_NOARGS),
        DECLARE_METHOD(t_IParameterEstimator, initialize, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IParameterEstimator, t_IParameterEstimator, ::java::lang::Object, IParameterEstimator, abstract_init, 0, 0, 0, 0, 0);

      void t_IParameterEstimator::install(PyObject *module)
      {
        installType(&PY_TYPE(IParameterEstimator), module, "IParameterEstimator", 0);
      }

      void t_IParameterEstimator::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IParameterEstimator).tp_dict, "class_", make_descriptor(IParameterEstimator::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IParameterEstimator).tp_dict, "wrapfn_", make_descriptor(t_IParameterEstimator::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IParameterEstimator).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IParameterEstimator_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IParameterEstimator::initializeClass, 1)))
          return NULL;
        return t_IParameterEstimator::wrap_Object(IParameterEstimator(((t_IParameterEstimator *) arg)->object.this$));
      }
      static PyObject *t_IParameterEstimator_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IParameterEstimator::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IParameterEstimator_addToEstimate(t_IParameterEstimator *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
            {
              OBJ_CALL(self->object.addToEstimate(a0));
              Py_RETURN_NONE;
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.addToEstimate(a0, a1));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "addToEstimate", args);
        return NULL;
      }

      static PyObject *t_IParameterEstimator_copy(t_IParameterEstimator *self)
      {
        IParameterEstimator result((jobject) NULL);
        OBJ_CALL(result = self->object.copy());
        return t_IParameterEstimator::wrap_Object(result);
      }

      static PyObject *t_IParameterEstimator_estimate(t_IParameterEstimator *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.estimate(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.estimate(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "estimate", args);
        return NULL;
      }

      static PyObject *t_IParameterEstimator_getEstimate(t_IParameterEstimator *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getEstimate());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IParameterEstimator_initialize(t_IParameterEstimator *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 0:
          {
            OBJ_CALL(self->object.initialize());
            Py_RETURN_NONE;
          }
          break;
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.initialize(a0));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "initialize", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/datasequence/IDataList.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace datasequence {

      ::java::lang::Class *IDataList::class$ = NULL;
      jmethodID *IDataList::mids$ = NULL;
      bool IDataList::live$ = false;

      jclass IDataList::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/datasequence/IDataList");

          mids$ = new jmethodID[max_mid];
          mids$[mid_add_02530846] = env->getMethodID(cls, "add", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_remove_02530846] = env->getMethodID(cls, "remove", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_remove_e3ead0f5] = env->getMethodID(cls, "remove", "(I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_set_9665a230] = env->getMethodID(cls, "set", "(ILstallone/api/doubles/IDoubleArray;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jboolean IDataList::add(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_add_02530846], a0.this$);
      }

      jboolean IDataList::remove(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_remove_02530846], a0.this$);
      }

      ::stallone::api::doubles::IDoubleArray IDataList::remove(jint a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_remove_e3ead0f5], a0));
      }

      void IDataList::set(jint a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_set_9665a230], a0, a1.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace datasequence {
      static PyObject *t_IDataList_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDataList_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDataList_add(t_IDataList *self, PyObject *arg);
      static PyObject *t_IDataList_remove(t_IDataList *self, PyObject *args);
      static PyObject *t_IDataList_set(t_IDataList *self, PyObject *args);

      static PyMethodDef t_IDataList__methods_[] = {
        DECLARE_METHOD(t_IDataList, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDataList, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDataList, add, METH_O),
        DECLARE_METHOD(t_IDataList, remove, METH_VARARGS),
        DECLARE_METHOD(t_IDataList, set, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDataList, t_IDataList, ::stallone::api::datasequence::IDataSequence, IDataList, abstract_init, 0, 0, 0, 0, 0);

      void t_IDataList::install(PyObject *module)
      {
        installType(&PY_TYPE(IDataList), module, "IDataList", 0);
      }

      void t_IDataList::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDataList).tp_dict, "class_", make_descriptor(IDataList::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDataList).tp_dict, "wrapfn_", make_descriptor(t_IDataList::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDataList).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDataList_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDataList::initializeClass, 1)))
          return NULL;
        return t_IDataList::wrap_Object(IDataList(((t_IDataList *) arg)->object.this$));
      }
      static PyObject *t_IDataList_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDataList::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDataList_add(t_IDataList *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.add(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "add", arg);
        return NULL;
      }

      static PyObject *t_IDataList_remove(t_IDataList *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.remove(a0));
              Py_RETURN_BOOL(result);
            }
          }
          {
            jint a0;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.remove(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "remove", args);
        return NULL;
      }

      static PyObject *t_IDataList_set(t_IDataList *self, PyObject *args)
      {
        jint a0;
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);

        if (!parseArgs(args, "Ik", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.set(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "set", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/mc/ITransitionMatrixEstimator.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace mc {

      ::java::lang::Class *ITransitionMatrixEstimator::class$ = NULL;
      jmethodID *ITransitionMatrixEstimator::mids$ = NULL;
      bool ITransitionMatrixEstimator::live$ = false;

      jclass ITransitionMatrixEstimator::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/mc/ITransitionMatrixEstimator");

          mids$ = new jmethodID[max_mid];
          mids$[mid_estimate_54c6a166] = env->getMethodID(cls, "estimate", "()V");
          mids$[mid_getTransitionMatrix_1d53e353] = env->getMethodID(cls, "getTransitionMatrix", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_setCounts_0253084a] = env->getMethodID(cls, "setCounts", "(Lstallone/api/doubles/IDoubleArray;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void ITransitionMatrixEstimator::estimate() const
      {
        env->callVoidMethod(this$, mids$[mid_estimate_54c6a166]);
      }

      ::stallone::api::doubles::IDoubleArray ITransitionMatrixEstimator::getTransitionMatrix() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getTransitionMatrix_1d53e353]));
      }

      void ITransitionMatrixEstimator::setCounts(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setCounts_0253084a], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace mc {
      static PyObject *t_ITransitionMatrixEstimator_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ITransitionMatrixEstimator_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ITransitionMatrixEstimator_estimate(t_ITransitionMatrixEstimator *self);
      static PyObject *t_ITransitionMatrixEstimator_getTransitionMatrix(t_ITransitionMatrixEstimator *self);
      static PyObject *t_ITransitionMatrixEstimator_setCounts(t_ITransitionMatrixEstimator *self, PyObject *arg);
      static int t_ITransitionMatrixEstimator_set__counts(t_ITransitionMatrixEstimator *self, PyObject *arg, void *data);
      static PyObject *t_ITransitionMatrixEstimator_get__transitionMatrix(t_ITransitionMatrixEstimator *self, void *data);
      static PyGetSetDef t_ITransitionMatrixEstimator__fields_[] = {
        DECLARE_SET_FIELD(t_ITransitionMatrixEstimator, counts),
        DECLARE_GET_FIELD(t_ITransitionMatrixEstimator, transitionMatrix),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_ITransitionMatrixEstimator__methods_[] = {
        DECLARE_METHOD(t_ITransitionMatrixEstimator, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ITransitionMatrixEstimator, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ITransitionMatrixEstimator, estimate, METH_NOARGS),
        DECLARE_METHOD(t_ITransitionMatrixEstimator, getTransitionMatrix, METH_NOARGS),
        DECLARE_METHOD(t_ITransitionMatrixEstimator, setCounts, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(ITransitionMatrixEstimator, t_ITransitionMatrixEstimator, ::java::lang::Object, ITransitionMatrixEstimator, abstract_init, 0, 0, t_ITransitionMatrixEstimator__fields_, 0, 0);

      void t_ITransitionMatrixEstimator::install(PyObject *module)
      {
        installType(&PY_TYPE(ITransitionMatrixEstimator), module, "ITransitionMatrixEstimator", 0);
      }

      void t_ITransitionMatrixEstimator::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(ITransitionMatrixEstimator).tp_dict, "class_", make_descriptor(ITransitionMatrixEstimator::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ITransitionMatrixEstimator).tp_dict, "wrapfn_", make_descriptor(t_ITransitionMatrixEstimator::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ITransitionMatrixEstimator).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_ITransitionMatrixEstimator_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, ITransitionMatrixEstimator::initializeClass, 1)))
          return NULL;
        return t_ITransitionMatrixEstimator::wrap_Object(ITransitionMatrixEstimator(((t_ITransitionMatrixEstimator *) arg)->object.this$));
      }
      static PyObject *t_ITransitionMatrixEstimator_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, ITransitionMatrixEstimator::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_ITransitionMatrixEstimator_estimate(t_ITransitionMatrixEstimator *self)
      {
        OBJ_CALL(self->object.estimate());
        Py_RETURN_NONE;
      }

      static PyObject *t_ITransitionMatrixEstimator_getTransitionMatrix(t_ITransitionMatrixEstimator *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getTransitionMatrix());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_ITransitionMatrixEstimator_setCounts(t_ITransitionMatrixEstimator *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setCounts(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setCounts", arg);
        return NULL;
      }

      static int t_ITransitionMatrixEstimator_set__counts(t_ITransitionMatrixEstimator *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setCounts(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "counts", arg);
        return -1;
      }

      static PyObject *t_ITransitionMatrixEstimator_get__transitionMatrix(t_ITransitionMatrixEstimator *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getTransitionMatrix());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/strings/StringUtilities.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace strings {

      ::java::lang::Class *StringUtilities::class$ = NULL;
      jmethodID *StringUtilities::mids$ = NULL;
      bool StringUtilities::live$ = false;

      jclass StringUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/strings/StringUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_concat_52efb6d5] = env->getMethodID(cls, "concat", "([Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_concat_bdc16ed9] = env->getMethodID(cls, "concat", "([Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_concat_702502e1] = env->getMethodID(cls, "concat", "([[Ljava/lang/String;[Ljava/lang/String;)[[Ljava/lang/String;");
          mids$[mid_concat_c43bee99] = env->getMethodID(cls, "concat", "([[Ljava/lang/String;[[Ljava/lang/String;)[[Ljava/lang/String;");
          mids$[mid_contains_2d75732a] = env->getMethodID(cls, "contains", "([Ljava/lang/String;Ljava/lang/String;)Z");
          mids$[mid_copy_dc523beb] = env->getMethodID(cls, "copy", "([Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_drop_a23934a5] = env->getMethodID(cls, "drop", "([Ljava/lang/String;[I)[Ljava/lang/String;");
          mids$[mid_dropLeading_52efb6d5] = env->getMethodID(cls, "dropLeading", "([Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_findBackward_2d757339] = env->getMethodID(cls, "findBackward", "([Ljava/lang/String;Ljava/lang/String;)I");
          mids$[mid_findBackward_4d3b16d3] = env->getMethodID(cls, "findBackward", "([Ljava/lang/String;Ljava/lang/String;I)I");
          mids$[mid_findForward_2d757339] = env->getMethodID(cls, "findForward", "([Ljava/lang/String;Ljava/lang/String;)I");
          mids$[mid_findForward_4d3b16d3] = env->getMethodID(cls, "findForward", "([Ljava/lang/String;Ljava/lang/String;I)I");
          mids$[mid_getColumn_d73de0bd] = env->getMethodID(cls, "getColumn", "([[Ljava/lang/String;I)[Ljava/lang/String;");
          mids$[mid_getLines_1f6a174f] = env->getMethodID(cls, "getLines", "(Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_isDouble_5fdc3f44] = env->getMethodID(cls, "isDouble", "(Ljava/lang/String;)Z");
          mids$[mid_isDoubleArray_5fdc3f44] = env->getMethodID(cls, "isDoubleArray", "(Ljava/lang/String;)Z");
          mids$[mid_isInt_5fdc3f44] = env->getMethodID(cls, "isInt", "(Ljava/lang/String;)Z");
          mids$[mid_isIntArray_5fdc3f44] = env->getMethodID(cls, "isIntArray", "(Ljava/lang/String;)Z");
          mids$[mid_leadingInt_5fdc3f57] = env->getMethodID(cls, "leadingInt", "(Ljava/lang/String;)I");
          mids$[mid_mergeLines_1034289b] = env->getMethodID(cls, "mergeLines", "([Ljava/lang/String;)Ljava/lang/String;");
          mids$[mid_nextInt_6e53ccd9] = env->getMethodID(cls, "nextInt", "(Ljava/lang/String;I)I");
          mids$[mid_nextLong_6e53ccda] = env->getMethodID(cls, "nextLong", "(Ljava/lang/String;I)J");
          mids$[mid_purgeEmpty_dc523beb] = env->getMethodID(cls, "purgeEmpty", "([Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_replaceAll_af6d27e3] = env->getMethodID(cls, "replaceAll", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
          mids$[mid_split_65e3fad3] = env->getMethodID(cls, "split", "([Ljava/lang/String;)[[Ljava/lang/String;");
          mids$[mid_split_1f6a174f] = env->getMethodID(cls, "split", "(Ljava/lang/String;)[Ljava/lang/String;");
          mids$[mid_startsWithInt_5fdc3f44] = env->getMethodID(cls, "startsWithInt", "(Ljava/lang/String;)Z");
          mids$[mid_subarray_a23934a5] = env->getMethodID(cls, "subarray", "([Ljava/lang/String;[I)[Ljava/lang/String;");
          mids$[mid_subarray_b0bbba5d] = env->getMethodID(cls, "subarray", "([[Ljava/lang/String;[I)[[Ljava/lang/String;");
          mids$[mid_subarray_4b8ddbd3] = env->getMethodID(cls, "subarray", "([Ljava/lang/String;II)[Ljava/lang/String;");
          mids$[mid_subarray_7846ea3b] = env->getMethodID(cls, "subarray", "([[Ljava/lang/String;II)[[Ljava/lang/String;");
          mids$[mid_toDouble_5fdc3f5a] = env->getMethodID(cls, "toDouble", "(Ljava/lang/String;)D");
          mids$[mid_toDoubleArray_33e9f57a] = env->getMethodID(cls, "toDoubleArray", "([[Ljava/lang/String;)[[D");
          mids$[mid_toDoubleArray_94a731a2] = env->getMethodID(cls, "toDoubleArray", "(Ljava/lang/String;)[D");
          mids$[mid_toDoubleArray_0998f056] = env->getMethodID(cls, "toDoubleArray", "([Ljava/lang/String;)[D");
          mids$[mid_toDoubleTable_eb951592] = env->getMethodID(cls, "toDoubleTable", "(Ljava/lang/String;)[[D");
          mids$[mid_toInt_5fdc3f57] = env->getMethodID(cls, "toInt", "(Ljava/lang/String;)I");
          mids$[mid_toIntArray_0998f05b] = env->getMethodID(cls, "toIntArray", "([Ljava/lang/String;)[I");
          mids$[mid_toIntArray_94a731af] = env->getMethodID(cls, "toIntArray", "(Ljava/lang/String;)[I");
          mids$[mid_toIntMatrix_33e9f577] = env->getMethodID(cls, "toIntMatrix", "([[Ljava/lang/String;)[[I");
          mids$[mid_toLong_5fdc3f54] = env->getMethodID(cls, "toLong", "(Ljava/lang/String;)J");
          mids$[mid_transpose_96c66b57] = env->getMethodID(cls, "transpose", "([[Ljava/lang/String;)[[Ljava/lang/String;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      StringUtilities::StringUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      JArray< ::java::lang::String > StringUtilities::concat(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_concat_52efb6d5], a0.this$, a1.this$));
      }

      JArray< ::java::lang::String > StringUtilities::concat(const JArray< ::java::lang::String > & a0, const JArray< ::java::lang::String > & a1) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_concat_bdc16ed9], a0.this$, a1.this$));
      }

      JArray< JArray< ::java::lang::String > > StringUtilities::concat(const JArray< JArray< ::java::lang::String > > & a0, const JArray< ::java::lang::String > & a1) const
      {
        return JArray< JArray< ::java::lang::String > >(env->callObjectMethod(this$, mids$[mid_concat_702502e1], a0.this$, a1.this$));
      }

      JArray< JArray< ::java::lang::String > > StringUtilities::concat(const JArray< JArray< ::java::lang::String > > & a0, const JArray< JArray< ::java::lang::String > > & a1) const
      {
        return JArray< JArray< ::java::lang::String > >(env->callObjectMethod(this$, mids$[mid_concat_c43bee99], a0.this$, a1.this$));
      }

      jboolean StringUtilities::contains(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1) const
      {
        return env->callBooleanMethod(this$, mids$[mid_contains_2d75732a], a0.this$, a1.this$);
      }

      JArray< ::java::lang::String > StringUtilities::copy(const JArray< ::java::lang::String > & a0) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_copy_dc523beb], a0.this$));
      }

      JArray< ::java::lang::String > StringUtilities::drop(const JArray< ::java::lang::String > & a0, const JArray< jint > & a1) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_drop_a23934a5], a0.this$, a1.this$));
      }

      JArray< ::java::lang::String > StringUtilities::dropLeading(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_dropLeading_52efb6d5], a0.this$, a1.this$));
      }

      jint StringUtilities::findBackward(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1) const
      {
        return env->callIntMethod(this$, mids$[mid_findBackward_2d757339], a0.this$, a1.this$);
      }

      jint StringUtilities::findBackward(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1, jint a2) const
      {
        return env->callIntMethod(this$, mids$[mid_findBackward_4d3b16d3], a0.this$, a1.this$, a2);
      }

      jint StringUtilities::findForward(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1) const
      {
        return env->callIntMethod(this$, mids$[mid_findForward_2d757339], a0.this$, a1.this$);
      }

      jint StringUtilities::findForward(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1, jint a2) const
      {
        return env->callIntMethod(this$, mids$[mid_findForward_4d3b16d3], a0.this$, a1.this$, a2);
      }

      JArray< ::java::lang::String > StringUtilities::getColumn(const JArray< JArray< ::java::lang::String > > & a0, jint a1) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_getColumn_d73de0bd], a0.this$, a1));
      }

      JArray< ::java::lang::String > StringUtilities::getLines(const ::java::lang::String & a0) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_getLines_1f6a174f], a0.this$));
      }

      jboolean StringUtilities::isDouble(const ::java::lang::String & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isDouble_5fdc3f44], a0.this$);
      }

      jboolean StringUtilities::isDoubleArray(const ::java::lang::String & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isDoubleArray_5fdc3f44], a0.this$);
      }

      jboolean StringUtilities::isInt(const ::java::lang::String & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isInt_5fdc3f44], a0.this$);
      }

      jboolean StringUtilities::isIntArray(const ::java::lang::String & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isIntArray_5fdc3f44], a0.this$);
      }

      jint StringUtilities::leadingInt(const ::java::lang::String & a0) const
      {
        return env->callIntMethod(this$, mids$[mid_leadingInt_5fdc3f57], a0.this$);
      }

      ::java::lang::String StringUtilities::mergeLines(const JArray< ::java::lang::String > & a0) const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_mergeLines_1034289b], a0.this$));
      }

      jint StringUtilities::nextInt(const ::java::lang::String & a0, jint a1) const
      {
        return env->callIntMethod(this$, mids$[mid_nextInt_6e53ccd9], a0.this$, a1);
      }

      jlong StringUtilities::nextLong(const ::java::lang::String & a0, jint a1) const
      {
        return env->callLongMethod(this$, mids$[mid_nextLong_6e53ccda], a0.this$, a1);
      }

      JArray< ::java::lang::String > StringUtilities::purgeEmpty(const JArray< ::java::lang::String > & a0) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_purgeEmpty_dc523beb], a0.this$));
      }

      ::java::lang::String StringUtilities::replaceAll(const ::java::lang::String & a0, const ::java::lang::String & a1, const ::java::lang::String & a2) const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_replaceAll_af6d27e3], a0.this$, a1.this$, a2.this$));
      }

      JArray< JArray< ::java::lang::String > > StringUtilities::split(const JArray< ::java::lang::String > & a0) const
      {
        return JArray< JArray< ::java::lang::String > >(env->callObjectMethod(this$, mids$[mid_split_65e3fad3], a0.this$));
      }

      JArray< ::java::lang::String > StringUtilities::split(const ::java::lang::String & a0) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_split_1f6a174f], a0.this$));
      }

      jboolean StringUtilities::startsWithInt(const ::java::lang::String & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_startsWithInt_5fdc3f44], a0.this$);
      }

      JArray< ::java::lang::String > StringUtilities::subarray(const JArray< ::java::lang::String > & a0, const JArray< jint > & a1) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_subarray_a23934a5], a0.this$, a1.this$));
      }

      JArray< JArray< ::java::lang::String > > StringUtilities::subarray(const JArray< JArray< ::java::lang::String > > & a0, const JArray< jint > & a1) const
      {
        return JArray< JArray< ::java::lang::String > >(env->callObjectMethod(this$, mids$[mid_subarray_b0bbba5d], a0.this$, a1.this$));
      }

      JArray< ::java::lang::String > StringUtilities::subarray(const JArray< ::java::lang::String > & a0, jint a1, jint a2) const
      {
        return JArray< ::java::lang::String >(env->callObjectMethod(this$, mids$[mid_subarray_4b8ddbd3], a0.this$, a1, a2));
      }

      JArray< JArray< ::java::lang::String > > StringUtilities::subarray(const JArray< JArray< ::java::lang::String > > & a0, jint a1, jint a2) const
      {
        return JArray< JArray< ::java::lang::String > >(env->callObjectMethod(this$, mids$[mid_subarray_7846ea3b], a0.this$, a1, a2));
      }

      jdouble StringUtilities::toDouble(const ::java::lang::String & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_toDouble_5fdc3f5a], a0.this$);
      }

      JArray< JArray< jdouble > > StringUtilities::toDoubleArray(const JArray< JArray< ::java::lang::String > > & a0) const
      {
        return JArray< JArray< jdouble > >(env->callObjectMethod(this$, mids$[mid_toDoubleArray_33e9f57a], a0.this$));
      }

      JArray< jdouble > StringUtilities::toDoubleArray(const ::java::lang::String & a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_toDoubleArray_94a731a2], a0.this$));
      }

      JArray< jdouble > StringUtilities::toDoubleArray(const JArray< ::java::lang::String > & a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_toDoubleArray_0998f056], a0.this$));
      }

      JArray< JArray< jdouble > > StringUtilities::toDoubleTable(const ::java::lang::String & a0) const
      {
        return JArray< JArray< jdouble > >(env->callObjectMethod(this$, mids$[mid_toDoubleTable_eb951592], a0.this$));
      }

      jint StringUtilities::toInt(const ::java::lang::String & a0) const
      {
        return env->callIntMethod(this$, mids$[mid_toInt_5fdc3f57], a0.this$);
      }

      JArray< jint > StringUtilities::toIntArray(const JArray< ::java::lang::String > & a0) const
      {
        return JArray< jint >(env->callObjectMethod(this$, mids$[mid_toIntArray_0998f05b], a0.this$));
      }

      JArray< jint > StringUtilities::toIntArray(const ::java::lang::String & a0) const
      {
        return JArray< jint >(env->callObjectMethod(this$, mids$[mid_toIntArray_94a731af], a0.this$));
      }

      JArray< JArray< jint > > StringUtilities::toIntMatrix(const JArray< JArray< ::java::lang::String > > & a0) const
      {
        return JArray< JArray< jint > >(env->callObjectMethod(this$, mids$[mid_toIntMatrix_33e9f577], a0.this$));
      }

      jlong StringUtilities::toLong(const ::java::lang::String & a0) const
      {
        return env->callLongMethod(this$, mids$[mid_toLong_5fdc3f54], a0.this$);
      }

      JArray< JArray< ::java::lang::String > > StringUtilities::transpose(const JArray< JArray< ::java::lang::String > > & a0) const
      {
        return JArray< JArray< ::java::lang::String > >(env->callObjectMethod(this$, mids$[mid_transpose_96c66b57], a0.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace strings {
      static PyObject *t_StringUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_StringUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_StringUtilities_init_(t_StringUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_StringUtilities_concat(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_contains(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_copy(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_drop(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_dropLeading(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_findBackward(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_findForward(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_getColumn(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_getLines(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_isDouble(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_isDoubleArray(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_isInt(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_isIntArray(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_leadingInt(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_mergeLines(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_nextInt(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_nextLong(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_purgeEmpty(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_replaceAll(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_split(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_startsWithInt(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_subarray(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_toDouble(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_toDoubleArray(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_toDoubleTable(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_toInt(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_toIntArray(t_StringUtilities *self, PyObject *args);
      static PyObject *t_StringUtilities_toIntMatrix(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_toLong(t_StringUtilities *self, PyObject *arg);
      static PyObject *t_StringUtilities_transpose(t_StringUtilities *self, PyObject *arg);

      static PyMethodDef t_StringUtilities__methods_[] = {
        DECLARE_METHOD(t_StringUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_StringUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_StringUtilities, concat, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, contains, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, copy, METH_O),
        DECLARE_METHOD(t_StringUtilities, drop, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, dropLeading, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, findBackward, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, findForward, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, getColumn, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, getLines, METH_O),
        DECLARE_METHOD(t_StringUtilities, isDouble, METH_O),
        DECLARE_METHOD(t_StringUtilities, isDoubleArray, METH_O),
        DECLARE_METHOD(t_StringUtilities, isInt, METH_O),
        DECLARE_METHOD(t_StringUtilities, isIntArray, METH_O),
        DECLARE_METHOD(t_StringUtilities, leadingInt, METH_O),
        DECLARE_METHOD(t_StringUtilities, mergeLines, METH_O),
        DECLARE_METHOD(t_StringUtilities, nextInt, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, nextLong, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, purgeEmpty, METH_O),
        DECLARE_METHOD(t_StringUtilities, replaceAll, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, split, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, startsWithInt, METH_O),
        DECLARE_METHOD(t_StringUtilities, subarray, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, toDouble, METH_O),
        DECLARE_METHOD(t_StringUtilities, toDoubleArray, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, toDoubleTable, METH_O),
        DECLARE_METHOD(t_StringUtilities, toInt, METH_O),
        DECLARE_METHOD(t_StringUtilities, toIntArray, METH_VARARGS),
        DECLARE_METHOD(t_StringUtilities, toIntMatrix, METH_O),
        DECLARE_METHOD(t_StringUtilities, toLong, METH_O),
        DECLARE_METHOD(t_StringUtilities, transpose, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(StringUtilities, t_StringUtilities, ::java::lang::Object, StringUtilities, t_StringUtilities_init_, 0, 0, 0, 0, 0);

      void t_StringUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(StringUtilities), module, "StringUtilities", 0);
      }

      void t_StringUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(StringUtilities).tp_dict, "class_", make_descriptor(StringUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(StringUtilities).tp_dict, "wrapfn_", make_descriptor(t_StringUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(StringUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_StringUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, StringUtilities::initializeClass, 1)))
          return NULL;
        return t_StringUtilities::wrap_Object(StringUtilities(((t_StringUtilities *) arg)->object.this$));
      }
      static PyObject *t_StringUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, StringUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_StringUtilities_init_(t_StringUtilities *self, PyObject *args, PyObject *kwds)
      {
        StringUtilities object((jobject) NULL);

        INT_CALL(object = StringUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_StringUtilities_concat(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            JArray< ::java::lang::String > result((jobject) NULL);

            if (!parseArgs(args, "[ss", &a0, &a1))
            {
              OBJ_CALL(result = self->object.concat(a0, a1));
              return JArray<jstring>(result.this$).wrap();
            }
          }
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            JArray< ::java::lang::String > a1((jobject) NULL);
            JArray< ::java::lang::String > result((jobject) NULL);

            if (!parseArgs(args, "[s[s", &a0, &a1))
            {
              OBJ_CALL(result = self->object.concat(a0, a1));
              return JArray<jstring>(result.this$).wrap();
            }
          }
          {
            JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
            JArray< ::java::lang::String > a1((jobject) NULL);
            JArray< JArray< ::java::lang::String > > result((jobject) NULL);

            if (!parseArgs(args, "[[s[s", &a0, &a1))
            {
              OBJ_CALL(result = self->object.concat(a0, a1));
              return JArray<jobject>(result.this$).wrap(NULL);
            }
          }
          {
            JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
            JArray< JArray< ::java::lang::String > > a1((jobject) NULL);
            JArray< JArray< ::java::lang::String > > result((jobject) NULL);

            if (!parseArgs(args, "[[s[[s", &a0, &a1))
            {
              OBJ_CALL(result = self->object.concat(a0, a1));
              return JArray<jobject>(result.this$).wrap(NULL);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "concat", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_contains(t_StringUtilities *self, PyObject *args)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);
        jboolean result;

        if (!parseArgs(args, "[ss", &a0, &a1))
        {
          OBJ_CALL(result = self->object.contains(a0, a1));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "contains", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_copy(t_StringUtilities *self, PyObject *arg)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);
        JArray< ::java::lang::String > result((jobject) NULL);

        if (!parseArg(arg, "[s", &a0))
        {
          OBJ_CALL(result = self->object.copy(a0));
          return JArray<jstring>(result.this$).wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "copy", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_drop(t_StringUtilities *self, PyObject *args)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);
        JArray< jint > a1((jobject) NULL);
        JArray< ::java::lang::String > result((jobject) NULL);

        if (!parseArgs(args, "[s[I", &a0, &a1))
        {
          OBJ_CALL(result = self->object.drop(a0, a1));
          return JArray<jstring>(result.this$).wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "drop", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_dropLeading(t_StringUtilities *self, PyObject *args)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);
        JArray< ::java::lang::String > result((jobject) NULL);

        if (!parseArgs(args, "[ss", &a0, &a1))
        {
          OBJ_CALL(result = self->object.dropLeading(a0, a1));
          return JArray<jstring>(result.this$).wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "dropLeading", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_findBackward(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            jint result;

            if (!parseArgs(args, "[ss", &a0, &a1))
            {
              OBJ_CALL(result = self->object.findBackward(a0, a1));
              return PyInt_FromLong((long) result);
            }
          }
          break;
         case 3:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            jint a2;
            jint result;

            if (!parseArgs(args, "[ssI", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.findBackward(a0, a1, a2));
              return PyInt_FromLong((long) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "findBackward", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_findForward(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            jint result;

            if (!parseArgs(args, "[ss", &a0, &a1))
            {
              OBJ_CALL(result = self->object.findForward(a0, a1));
              return PyInt_FromLong((long) result);
            }
          }
          break;
         case 3:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            jint a2;
            jint result;

            if (!parseArgs(args, "[ssI", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.findForward(a0, a1, a2));
              return PyInt_FromLong((long) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "findForward", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_getColumn(t_StringUtilities *self, PyObject *args)
      {
        JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
        jint a1;
        JArray< ::java::lang::String > result((jobject) NULL);

        if (!parseArgs(args, "[[sI", &a0, &a1))
        {
          OBJ_CALL(result = self->object.getColumn(a0, a1));
          return JArray<jstring>(result.this$).wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getColumn", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_getLines(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        JArray< ::java::lang::String > result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.getLines(a0));
          return JArray<jstring>(result.this$).wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getLines", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_isDouble(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.isDouble(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isDouble", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_isDoubleArray(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.isDoubleArray(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isDoubleArray", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_isInt(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.isInt(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isInt", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_isIntArray(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.isIntArray(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isIntArray", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_leadingInt(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jint result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.leadingInt(a0));
          return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "leadingInt", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_mergeLines(t_StringUtilities *self, PyObject *arg)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);
        ::java::lang::String result((jobject) NULL);

        if (!parseArg(arg, "[s", &a0))
        {
          OBJ_CALL(result = self->object.mergeLines(a0));
          return j2p(result);
        }

        PyErr_SetArgsError((PyObject *) self, "mergeLines", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_nextInt(t_StringUtilities *self, PyObject *args)
      {
        ::java::lang::String a0((jobject) NULL);
        jint a1;
        jint result;

        if (!parseArgs(args, "sI", &a0, &a1))
        {
          OBJ_CALL(result = self->object.nextInt(a0, a1));
          return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "nextInt", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_nextLong(t_StringUtilities *self, PyObject *args)
      {
        ::java::lang::String a0((jobject) NULL);
        jint a1;
        jlong result;

        if (!parseArgs(args, "sI", &a0, &a1))
        {
          OBJ_CALL(result = self->object.nextLong(a0, a1));
          return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        PyErr_SetArgsError((PyObject *) self, "nextLong", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_purgeEmpty(t_StringUtilities *self, PyObject *arg)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);
        JArray< ::java::lang::String > result((jobject) NULL);

        if (!parseArg(arg, "[s", &a0))
        {
          OBJ_CALL(result = self->object.purgeEmpty(a0));
          return JArray<jstring>(result.this$).wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "purgeEmpty", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_replaceAll(t_StringUtilities *self, PyObject *args)
      {
        ::java::lang::String a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);
        ::java::lang::String a2((jobject) NULL);
        ::java::lang::String result((jobject) NULL);

        if (!parseArgs(args, "sss", &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.replaceAll(a0, a1, a2));
          return j2p(result);
        }

        PyErr_SetArgsError((PyObject *) self, "replaceAll", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_split(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            JArray< JArray< ::java::lang::String > > result((jobject) NULL);

            if (!parseArgs(args, "[s", &a0))
            {
              OBJ_CALL(result = self->object.split(a0));
              return JArray<jobject>(result.this$).wrap(NULL);
            }
          }
          {
            ::java::lang::String a0((jobject) NULL);
            JArray< ::java::lang::String > result((jobject) NULL);

            if (!parseArgs(args, "s", &a0))
            {
              OBJ_CALL(result = self->object.split(a0));
              return JArray<jstring>(result.this$).wrap();
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "split", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_startsWithInt(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.startsWithInt(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "startsWithInt", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_subarray(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            JArray< jint > a1((jobject) NULL);
            JArray< ::java::lang::String > result((jobject) NULL);

            if (!parseArgs(args, "[s[I", &a0, &a1))
            {
              OBJ_CALL(result = self->object.subarray(a0, a1));
              return JArray<jstring>(result.this$).wrap();
            }
          }
          {
            JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
            JArray< jint > a1((jobject) NULL);
            JArray< JArray< ::java::lang::String > > result((jobject) NULL);

            if (!parseArgs(args, "[[s[I", &a0, &a1))
            {
              OBJ_CALL(result = self->object.subarray(a0, a1));
              return JArray<jobject>(result.this$).wrap(NULL);
            }
          }
          break;
         case 3:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            jint a1;
            jint a2;
            JArray< ::java::lang::String > result((jobject) NULL);

            if (!parseArgs(args, "[sII", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.subarray(a0, a1, a2));
              return JArray<jstring>(result.this$).wrap();
            }
          }
          {
            JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
            jint a1;
            jint a2;
            JArray< JArray< ::java::lang::String > > result((jobject) NULL);

            if (!parseArgs(args, "[[sII", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.subarray(a0, a1, a2));
              return JArray<jobject>(result.this$).wrap(NULL);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "subarray", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_toDouble(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jdouble result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.toDouble(a0));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "toDouble", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_toDoubleArray(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
            JArray< JArray< jdouble > > result((jobject) NULL);

            if (!parseArgs(args, "[[s", &a0))
            {
              OBJ_CALL(result = self->object.toDoubleArray(a0));
              return JArray<jobject>(result.this$).wrap(NULL);
            }
          }
          {
            ::java::lang::String a0((jobject) NULL);
            JArray< jdouble > result((jobject) NULL);

            if (!parseArgs(args, "s", &a0))
            {
              OBJ_CALL(result = self->object.toDoubleArray(a0));
              return result.wrap();
            }
          }
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            JArray< jdouble > result((jobject) NULL);

            if (!parseArgs(args, "[s", &a0))
            {
              OBJ_CALL(result = self->object.toDoubleArray(a0));
              return result.wrap();
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "toDoubleArray", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_toDoubleTable(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        JArray< JArray< jdouble > > result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.toDoubleTable(a0));
          return JArray<jobject>(result.this$).wrap(NULL);
        }

        PyErr_SetArgsError((PyObject *) self, "toDoubleTable", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_toInt(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jint result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.toInt(a0));
          return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "toInt", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_toIntArray(t_StringUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            JArray< jint > result((jobject) NULL);

            if (!parseArgs(args, "[s", &a0))
            {
              OBJ_CALL(result = self->object.toIntArray(a0));
              return result.wrap();
            }
          }
          {
            ::java::lang::String a0((jobject) NULL);
            JArray< jint > result((jobject) NULL);

            if (!parseArgs(args, "s", &a0))
            {
              OBJ_CALL(result = self->object.toIntArray(a0));
              return result.wrap();
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "toIntArray", args);
        return NULL;
      }

      static PyObject *t_StringUtilities_toIntMatrix(t_StringUtilities *self, PyObject *arg)
      {
        JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
        JArray< JArray< jint > > result((jobject) NULL);

        if (!parseArg(arg, "[[s", &a0))
        {
          OBJ_CALL(result = self->object.toIntMatrix(a0));
          return JArray<jobject>(result.this$).wrap(NULL);
        }

        PyErr_SetArgsError((PyObject *) self, "toIntMatrix", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_toLong(t_StringUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jlong result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.toLong(a0));
          return PyLong_FromLongLong((PY_LONG_LONG) result);
        }

        PyErr_SetArgsError((PyObject *) self, "toLong", arg);
        return NULL;
      }

      static PyObject *t_StringUtilities_transpose(t_StringUtilities *self, PyObject *arg)
      {
        JArray< JArray< ::java::lang::String > > a0((jobject) NULL);
        JArray< JArray< ::java::lang::String > > result((jobject) NULL);

        if (!parseArg(arg, "[[s", &a0))
        {
          OBJ_CALL(result = self->object.transpose(a0));
          return JArray<jobject>(result.this$).wrap(NULL);
        }

        PyErr_SetArgsError((PyObject *) self, "transpose", arg);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/ints/IIntList.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace ints {

      ::java::lang::Class *IIntList::class$ = NULL;
      jmethodID *IIntList::mids$ = NULL;
      bool IIntList::live$ = false;

      jclass IIntList::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/ints/IIntList");

          mids$ = new jmethodID[max_mid];
          mids$[mid_append_39c7bd3c] = env->getMethodID(cls, "append", "(I)V");
          mids$[mid_appendAll_059aa494] = env->getMethodID(cls, "appendAll", "(Lstallone/api/ints/IIntArray;)V");
          mids$[mid_clear_54c6a166] = env->getMethodID(cls, "clear", "()V");
          mids$[mid_insert_d8d154a6] = env->getMethodID(cls, "insert", "(II)V");
          mids$[mid_insertAll_537625be] = env->getMethodID(cls, "insertAll", "(ILstallone/api/ints/IIntArray;)V");
          mids$[mid_remove_39c7bd3c] = env->getMethodID(cls, "remove", "(I)V");
          mids$[mid_removeByValue_39c7bd3c] = env->getMethodID(cls, "removeByValue", "(I)V");
          mids$[mid_removeRange_d8d154a6] = env->getMethodID(cls, "removeRange", "(II)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void IIntList::append(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_append_39c7bd3c], a0);
      }

      void IIntList::appendAll(const ::stallone::api::ints::IIntArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_appendAll_059aa494], a0.this$);
      }

      void IIntList::clear() const
      {
        env->callVoidMethod(this$, mids$[mid_clear_54c6a166]);
      }

      void IIntList::insert(jint a0, jint a1) const
      {
        env->callVoidMethod(this$, mids$[mid_insert_d8d154a6], a0, a1);
      }

      void IIntList::insertAll(jint a0, const ::stallone::api::ints::IIntArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_insertAll_537625be], a0, a1.this$);
      }

      void IIntList::remove(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_remove_39c7bd3c], a0);
      }

      void IIntList::removeByValue(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_removeByValue_39c7bd3c], a0);
      }

      void IIntList::removeRange(jint a0, jint a1) const
      {
        env->callVoidMethod(this$, mids$[mid_removeRange_d8d154a6], a0, a1);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace ints {
      static PyObject *t_IIntList_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntList_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntList_append(t_IIntList *self, PyObject *arg);
      static PyObject *t_IIntList_appendAll(t_IIntList *self, PyObject *arg);
      static PyObject *t_IIntList_clear(t_IIntList *self);
      static PyObject *t_IIntList_insert(t_IIntList *self, PyObject *args);
      static PyObject *t_IIntList_insertAll(t_IIntList *self, PyObject *args);
      static PyObject *t_IIntList_remove(t_IIntList *self, PyObject *arg);
      static PyObject *t_IIntList_removeByValue(t_IIntList *self, PyObject *arg);
      static PyObject *t_IIntList_removeRange(t_IIntList *self, PyObject *args);

      static PyMethodDef t_IIntList__methods_[] = {
        DECLARE_METHOD(t_IIntList, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntList, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntList, append, METH_O),
        DECLARE_METHOD(t_IIntList, appendAll, METH_O),
        DECLARE_METHOD(t_IIntList, clear, METH_NOARGS),
        DECLARE_METHOD(t_IIntList, insert, METH_VARARGS),
        DECLARE_METHOD(t_IIntList, insertAll, METH_VARARGS),
        DECLARE_METHOD(t_IIntList, remove, METH_O),
        DECLARE_METHOD(t_IIntList, removeByValue, METH_O),
        DECLARE_METHOD(t_IIntList, removeRange, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IIntList, t_IIntList, ::stallone::api::ints::IIntArray, IIntList, abstract_init, 0, 0, 0, 0, 0);

      void t_IIntList::install(PyObject *module)
      {
        installType(&PY_TYPE(IIntList), module, "IIntList", 0);
      }

      void t_IIntList::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IIntList).tp_dict, "class_", make_descriptor(IIntList::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IIntList).tp_dict, "wrapfn_", make_descriptor(t_IIntList::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IIntList).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IIntList_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IIntList::initializeClass, 1)))
          return NULL;
        return t_IIntList::wrap_Object(IIntList(((t_IIntList *) arg)->object.this$));
      }
      static PyObject *t_IIntList_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IIntList::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IIntList_append(t_IIntList *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.append(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "append", arg);
        return NULL;
      }

      static PyObject *t_IIntList_appendAll(t_IIntList *self, PyObject *arg)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::ints::IIntArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.appendAll(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "appendAll", arg);
        return NULL;
      }

      static PyObject *t_IIntList_clear(t_IIntList *self)
      {
        OBJ_CALL(self->object.clear());
        Py_RETURN_NONE;
      }

      static PyObject *t_IIntList_insert(t_IIntList *self, PyObject *args)
      {
        jint a0;
        jint a1;

        if (!parseArgs(args, "II", &a0, &a1))
        {
          OBJ_CALL(self->object.insert(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "insert", args);
        return NULL;
      }

      static PyObject *t_IIntList_insertAll(t_IIntList *self, PyObject *args)
      {
        jint a0;
        ::stallone::api::ints::IIntArray a1((jobject) NULL);

        if (!parseArgs(args, "Ik", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.insertAll(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "insertAll", args);
        return NULL;
      }

      static PyObject *t_IIntList_remove(t_IIntList *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.remove(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "remove", arg);
        return NULL;
      }

      static PyObject *t_IIntList_removeByValue(t_IIntList *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.removeByValue(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "removeByValue", arg);
        return NULL;
      }

      static PyObject *t_IIntList_removeRange(t_IIntList *self, PyObject *args)
      {
        jint a0;
        jint a1;

        if (!parseArgs(args, "II", &a0, &a1))
        {
          OBJ_CALL(self->object.removeRange(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "removeRange", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/IQRDecomposition.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *IQRDecomposition::class$ = NULL;
      jmethodID *IQRDecomposition::mids$ = NULL;
      bool IQRDecomposition::live$ = false;

      jclass IQRDecomposition::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/IQRDecomposition");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getQ_1d53e353] = env->getMethodID(cls, "getQ", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_getR_1d53e353] = env->getMethodID(cls, "getR", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_isFullRank_54c6a16a] = env->getMethodID(cls, "isFullRank", "()Z");
          mids$[mid_perform_54c6a166] = env->getMethodID(cls, "perform", "()V");
          mids$[mid_setMatrix_0253084a] = env->getMethodID(cls, "setMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::doubles::IDoubleArray IQRDecomposition::getQ() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getQ_1d53e353]));
      }

      ::stallone::api::doubles::IDoubleArray IQRDecomposition::getR() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getR_1d53e353]));
      }

      jboolean IQRDecomposition::isFullRank() const
      {
        return env->callBooleanMethod(this$, mids$[mid_isFullRank_54c6a16a]);
      }

      void IQRDecomposition::perform() const
      {
        env->callVoidMethod(this$, mids$[mid_perform_54c6a166]);
      }

      void IQRDecomposition::setMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setMatrix_0253084a], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_IQRDecomposition_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IQRDecomposition_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IQRDecomposition_getQ(t_IQRDecomposition *self);
      static PyObject *t_IQRDecomposition_getR(t_IQRDecomposition *self);
      static PyObject *t_IQRDecomposition_isFullRank(t_IQRDecomposition *self);
      static PyObject *t_IQRDecomposition_perform(t_IQRDecomposition *self);
      static PyObject *t_IQRDecomposition_setMatrix(t_IQRDecomposition *self, PyObject *arg);
      static PyObject *t_IQRDecomposition_get__fullRank(t_IQRDecomposition *self, void *data);
      static int t_IQRDecomposition_set__matrix(t_IQRDecomposition *self, PyObject *arg, void *data);
      static PyObject *t_IQRDecomposition_get__q(t_IQRDecomposition *self, void *data);
      static PyObject *t_IQRDecomposition_get__r(t_IQRDecomposition *self, void *data);
      static PyGetSetDef t_IQRDecomposition__fields_[] = {
        DECLARE_GET_FIELD(t_IQRDecomposition, fullRank),
        DECLARE_SET_FIELD(t_IQRDecomposition, matrix),
        DECLARE_GET_FIELD(t_IQRDecomposition, q),
        DECLARE_GET_FIELD(t_IQRDecomposition, r),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IQRDecomposition__methods_[] = {
        DECLARE_METHOD(t_IQRDecomposition, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IQRDecomposition, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IQRDecomposition, getQ, METH_NOARGS),
        DECLARE_METHOD(t_IQRDecomposition, getR, METH_NOARGS),
        DECLARE_METHOD(t_IQRDecomposition, isFullRank, METH_NOARGS),
        DECLARE_METHOD(t_IQRDecomposition, perform, METH_NOARGS),
        DECLARE_METHOD(t_IQRDecomposition, setMatrix, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IQRDecomposition, t_IQRDecomposition, ::java::lang::Object, IQRDecomposition, abstract_init, 0, 0, t_IQRDecomposition__fields_, 0, 0);

      void t_IQRDecomposition::install(PyObject *module)
      {
        installType(&PY_TYPE(IQRDecomposition), module, "IQRDecomposition", 0);
      }

      void t_IQRDecomposition::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IQRDecomposition).tp_dict, "class_", make_descriptor(IQRDecomposition::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IQRDecomposition).tp_dict, "wrapfn_", make_descriptor(t_IQRDecomposition::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IQRDecomposition).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IQRDecomposition_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IQRDecomposition::initializeClass, 1)))
          return NULL;
        return t_IQRDecomposition::wrap_Object(IQRDecomposition(((t_IQRDecomposition *) arg)->object.this$));
      }
      static PyObject *t_IQRDecomposition_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IQRDecomposition::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IQRDecomposition_getQ(t_IQRDecomposition *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getQ());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IQRDecomposition_getR(t_IQRDecomposition *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getR());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IQRDecomposition_isFullRank(t_IQRDecomposition *self)
      {
        jboolean result;
        OBJ_CALL(result = self->object.isFullRank());
        Py_RETURN_BOOL(result);
      }

      static PyObject *t_IQRDecomposition_perform(t_IQRDecomposition *self)
      {
        OBJ_CALL(self->object.perform());
        Py_RETURN_NONE;
      }

      static PyObject *t_IQRDecomposition_setMatrix(t_IQRDecomposition *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setMatrix(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setMatrix", arg);
        return NULL;
      }

      static PyObject *t_IQRDecomposition_get__fullRank(t_IQRDecomposition *self, void *data)
      {
        jboolean value;
        OBJ_CALL(value = self->object.isFullRank());
        Py_RETURN_BOOL(value);
      }

      static int t_IQRDecomposition_set__matrix(t_IQRDecomposition *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setMatrix(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "matrix", arg);
        return -1;
      }

      static PyObject *t_IQRDecomposition_get__q(t_IQRDecomposition *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getQ());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }

      static PyObject *t_IQRDecomposition_get__r(t_IQRDecomposition *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getR());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/util/Iterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace datasequence {

      ::java::lang::Class *IDataSequence::class$ = NULL;
      jmethodID *IDataSequence::mids$ = NULL;
      bool IDataSequence::live$ = false;

      jclass IDataSequence::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/datasequence/IDataSequence");

          mids$ = new jmethodID[max_mid];
          mids$[mid_dimension_54c6a179] = env->getMethodID(cls, "dimension", "()I");
          mids$[mid_get_e3ead0f5] = env->getMethodID(cls, "get", "(I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_getTime_39c7bd2e] = env->getMethodID(cls, "getTime", "(I)D");
          mids$[mid_getView_e3ead0f5] = env->getMethodID(cls, "getView", "(I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_iterator_40858c90] = env->getMethodID(cls, "iterator", "()Ljava/util/Iterator;");
          mids$[mid_size_54c6a179] = env->getMethodID(cls, "size", "()I");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jint IDataSequence::dimension() const
      {
        return env->callIntMethod(this$, mids$[mid_dimension_54c6a179]);
      }

      ::stallone::api::doubles::IDoubleArray IDataSequence::get(jint a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_get_e3ead0f5], a0));
      }

      jdouble IDataSequence::getTime(jint a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_getTime_39c7bd2e], a0);
      }

      ::stallone::api::doubles::IDoubleArray IDataSequence::getView(jint a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getView_e3ead0f5], a0));
      }

      ::java::util::Iterator IDataSequence::iterator() const
      {
        return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_iterator_40858c90]));
      }

      jint IDataSequence::size() const
      {
        return env->callIntMethod(this$, mids$[mid_size_54c6a179]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace datasequence {
      static PyObject *t_IDataSequence_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDataSequence_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDataSequence_dimension(t_IDataSequence *self);
      static PyObject *t_IDataSequence_get(t_IDataSequence *self, PyObject *arg);
      static PyObject *t_IDataSequence_getTime(t_IDataSequence *self, PyObject *arg);
      static PyObject *t_IDataSequence_getView(t_IDataSequence *self, PyObject *arg);
      static PyObject *t_IDataSequence_iterator(t_IDataSequence *self, PyObject *args);
      static PyObject *t_IDataSequence_size(t_IDataSequence *self);

      static PyMethodDef t_IDataSequence__methods_[] = {
        DECLARE_METHOD(t_IDataSequence, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDataSequence, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDataSequence, dimension, METH_NOARGS),
        DECLARE_METHOD(t_IDataSequence, get, METH_O),
        DECLARE_METHOD(t_IDataSequence, getTime, METH_O),
        DECLARE_METHOD(t_IDataSequence, getView, METH_O),
        DECLARE_METHOD(t_IDataSequence, iterator, METH_VARARGS),
        DECLARE_METHOD(t_IDataSequence, size, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDataSequence, t_IDataSequence, ::java::lang::Iterable, IDataSequence, abstract_init, ((PyObject *(*)(t_IDataSequence *)) get_iterator< t_IDataSequence >), 0, 0, 0, 0);

      void t_IDataSequence::install(PyObject *module)
      {
        installType(&PY_TYPE(IDataSequence), module, "IDataSequence", 0);
      }

      void t_IDataSequence::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDataSequence).tp_dict, "class_", make_descriptor(IDataSequence::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDataSequence).tp_dict, "wrapfn_", make_descriptor(t_IDataSequence::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDataSequence).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDataSequence_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDataSequence::initializeClass, 1)))
          return NULL;
        return t_IDataSequence::wrap_Object(IDataSequence(((t_IDataSequence *) arg)->object.this$));
      }
      static PyObject *t_IDataSequence_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDataSequence::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDataSequence_dimension(t_IDataSequence *self)
      {
        jint result;
        OBJ_CALL(result = self->object.dimension());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDataSequence_get(t_IDataSequence *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.get(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "get", arg);
        return NULL;
      }

      static PyObject *t_IDataSequence_getTime(t_IDataSequence *self, PyObject *arg)
      {
        jint a0;
        jdouble result;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getTime(a0));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "getTime", arg);
        return NULL;
      }

      static PyObject *t_IDataSequence_getView(t_IDataSequence *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getView(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getView", arg);
        return NULL;
      }

      static PyObject *t_IDataSequence_iterator(t_IDataSequence *self, PyObject *args)
      {
        ::java::util::Iterator result((jobject) NULL);

        if (!parseArgs(args, ""))
        {
          OBJ_CALL(result = self->object.iterator());
          return ::java::util::t_Iterator::wrap_Object(result, &::stallone::api::doubles::PY_TYPE(IDoubleArray));
        }

        return callSuper(&PY_TYPE(IDataSequence), (PyObject *) self, "iterator", args, 2);
      }

      static PyObject *t_IDataSequence_size(t_IDataSequence *self)
      {
        jint result;
        OBJ_CALL(result = self->object.size());
        return PyInt_FromLong((long) result);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/graph/IEdge.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace graph {

      ::java::lang::Class *IEdge::class$ = NULL;
      jmethodID *IEdge::mids$ = NULL;
      bool IEdge::live$ = false;

      jclass IEdge::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/graph/IEdge");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getNode1_846352c3] = env->getMethodID(cls, "getNode1", "()Ljava/lang/Object;");
          mids$[mid_getNode2_846352c3] = env->getMethodID(cls, "getNode2", "()Ljava/lang/Object;");
          mids$[mid_getWeight_54c6a174] = env->getMethodID(cls, "getWeight", "()D");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::java::lang::Object IEdge::getNode1() const
      {
        return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_getNode1_846352c3]));
      }

      ::java::lang::Object IEdge::getNode2() const
      {
        return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_getNode2_846352c3]));
      }

      jdouble IEdge::getWeight() const
      {
        return env->callDoubleMethod(this$, mids$[mid_getWeight_54c6a174]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace graph {
      static PyObject *t_IEdge_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IEdge_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IEdge_of_(t_IEdge *self, PyObject *args);
      static PyObject *t_IEdge_getNode1(t_IEdge *self);
      static PyObject *t_IEdge_getNode2(t_IEdge *self);
      static PyObject *t_IEdge_getWeight(t_IEdge *self);
      static PyObject *t_IEdge_get__node1(t_IEdge *self, void *data);
      static PyObject *t_IEdge_get__node2(t_IEdge *self, void *data);
      static PyObject *t_IEdge_get__weight(t_IEdge *self, void *data);
      static PyObject *t_IEdge_get__parameters_(t_IEdge *self, void *data);
      static PyGetSetDef t_IEdge__fields_[] = {
        DECLARE_GET_FIELD(t_IEdge, node1),
        DECLARE_GET_FIELD(t_IEdge, node2),
        DECLARE_GET_FIELD(t_IEdge, weight),
        DECLARE_GET_FIELD(t_IEdge, parameters_),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IEdge__methods_[] = {
        DECLARE_METHOD(t_IEdge, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IEdge, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IEdge, of_, METH_VARARGS),
        DECLARE_METHOD(t_IEdge, getNode1, METH_NOARGS),
        DECLARE_METHOD(t_IEdge, getNode2, METH_NOARGS),
        DECLARE_METHOD(t_IEdge, getWeight, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IEdge, t_IEdge, ::java::lang::Object, IEdge, abstract_init, 0, 0, t_IEdge__fields_, 0, 0);
      PyObject *t_IEdge::wrap_Object(const IEdge& object, PyTypeObject *V)
      {
        PyObject *obj = t_IEdge::wrap_Object(object);
        if (obj != NULL && obj != Py_None)
        {
          t_IEdge *self = (t_IEdge *) obj;
          self->parameters[0] = V;
        }
        return obj;
      }

      PyObject *t_IEdge::wrap_jobject(const jobject& object, PyTypeObject *V)
      {
        PyObject *obj = t_IEdge::wrap_jobject(object);
        if (obj != NULL && obj != Py_None)
        {
          t_IEdge *self = (t_IEdge *) obj;
          self->parameters[0] = V;
        }
        return obj;
      }

      void t_IEdge::install(PyObject *module)
      {
        installType(&PY_TYPE(IEdge), module, "IEdge", 0);
      }

      void t_IEdge::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IEdge).tp_dict, "class_", make_descriptor(IEdge::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IEdge).tp_dict, "wrapfn_", make_descriptor(t_IEdge::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IEdge).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IEdge_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IEdge::initializeClass, 1)))
          return NULL;
        return t_IEdge::wrap_Object(IEdge(((t_IEdge *) arg)->object.this$));
      }
      static PyObject *t_IEdge_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IEdge::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IEdge_of_(t_IEdge *self, PyObject *args)
      {
        if (!parseArg(args, "T", 1, &(self->parameters)))
          Py_RETURN_SELF;
        return PyErr_SetArgsError((PyObject *) self, "of_", args);
      }

      static PyObject *t_IEdge_getNode1(t_IEdge *self)
      {
        ::java::lang::Object result((jobject) NULL);
        OBJ_CALL(result = self->object.getNode1());
        return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
      }

      static PyObject *t_IEdge_getNode2(t_IEdge *self)
      {
        ::java::lang::Object result((jobject) NULL);
        OBJ_CALL(result = self->object.getNode2());
        return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
      }

      static PyObject *t_IEdge_getWeight(t_IEdge *self)
      {
        jdouble result;
        OBJ_CALL(result = self->object.getWeight());
        return PyFloat_FromDouble((double) result);
      }
      static PyObject *t_IEdge_get__parameters_(t_IEdge *self, void *data)
      {
        return typeParameters(self->parameters, sizeof(self->parameters));
      }

      static PyObject *t_IEdge_get__node1(t_IEdge *self, void *data)
      {
        ::java::lang::Object value((jobject) NULL);
        OBJ_CALL(value = self->object.getNode1());
        return ::java::lang::t_Object::wrap_Object(value);
      }

      static PyObject *t_IEdge_get__node2(t_IEdge *self, void *data)
      {
        ::java::lang::Object value((jobject) NULL);
        OBJ_CALL(value = self->object.getNode2());
        return ::java::lang::t_Object::wrap_Object(value);
      }

      static PyObject *t_IEdge_get__weight(t_IEdge *self, void *data)
      {
        jdouble value;
        OBJ_CALL(value = self->object.getWeight());
        return PyFloat_FromDouble((double) value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/hmm/IHMMOptimizer.h"
#include "stallone/api/hmm/IHMM.h"
#include "stallone/api/hmm/ParameterEstimationException.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace hmm {

      ::java::lang::Class *IHMMOptimizer::class$ = NULL;
      jmethodID *IHMMOptimizer::mids$ = NULL;
      bool IHMMOptimizer::live$ = false;

      jclass IHMMOptimizer::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/hmm/IHMMOptimizer");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getHMM_612e48e3] = env->getMethodID(cls, "getHMM", "()Lstallone/api/hmm/IHMM;");
          mids$[mid_run_54c6a166] = env->getMethodID(cls, "run", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::hmm::IHMM IHMMOptimizer::getHMM() const
      {
        return ::stallone::api::hmm::IHMM(env->callObjectMethod(this$, mids$[mid_getHMM_612e48e3]));
      }

      void IHMMOptimizer::run() const
      {
        env->callVoidMethod(this$, mids$[mid_run_54c6a166]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace hmm {
      static PyObject *t_IHMMOptimizer_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IHMMOptimizer_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IHMMOptimizer_getHMM(t_IHMMOptimizer *self);
      static PyObject *t_IHMMOptimizer_run(t_IHMMOptimizer *self);
      static PyObject *t_IHMMOptimizer_get__hMM(t_IHMMOptimizer *self, void *data);
      static PyGetSetDef t_IHMMOptimizer__fields_[] = {
        DECLARE_GET_FIELD(t_IHMMOptimizer, hMM),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IHMMOptimizer__methods_[] = {
        DECLARE_METHOD(t_IHMMOptimizer, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IHMMOptimizer, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IHMMOptimizer, getHMM, METH_NOARGS),
        DECLARE_METHOD(t_IHMMOptimizer, run, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IHMMOptimizer, t_IHMMOptimizer, ::java::lang::Object, IHMMOptimizer, abstract_init, 0, 0, t_IHMMOptimizer__fields_, 0, 0);

      void t_IHMMOptimizer::install(PyObject *module)
      {
        installType(&PY_TYPE(IHMMOptimizer), module, "IHMMOptimizer", 0);
      }

      void t_IHMMOptimizer::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IHMMOptimizer).tp_dict, "class_", make_descriptor(IHMMOptimizer::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IHMMOptimizer).tp_dict, "wrapfn_", make_descriptor(t_IHMMOptimizer::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IHMMOptimizer).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IHMMOptimizer_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IHMMOptimizer::initializeClass, 1)))
          return NULL;
        return t_IHMMOptimizer::wrap_Object(IHMMOptimizer(((t_IHMMOptimizer *) arg)->object.this$));
      }
      static PyObject *t_IHMMOptimizer_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IHMMOptimizer::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IHMMOptimizer_getHMM(t_IHMMOptimizer *self)
      {
        ::stallone::api::hmm::IHMM result((jobject) NULL);
        OBJ_CALL(result = self->object.getHMM());
        return ::stallone::api::hmm::t_IHMM::wrap_Object(result);
      }

      static PyObject *t_IHMMOptimizer_run(t_IHMMOptimizer *self)
      {
        OBJ_CALL(self->object.run());
        Py_RETURN_NONE;
      }

      static PyObject *t_IHMMOptimizer_get__hMM(t_IHMMOptimizer *self, void *data)
      {
        ::stallone::api::hmm::IHMM value((jobject) NULL);
        OBJ_CALL(value = self->object.getHMM());
        return ::stallone::api::hmm::t_IHMM::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/io/IReleasableFile.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace io {

      ::java::lang::Class *IReleasableFile::class$ = NULL;
      jmethodID *IReleasableFile::mids$ = NULL;
      bool IReleasableFile::live$ = false;

      jclass IReleasableFile::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/io/IReleasableFile");

          mids$ = new jmethodID[max_mid];
          mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");
          mids$[mid_getFileName_14c7b5c5] = env->getMethodID(cls, "getFileName", "()Ljava/lang/String;");
          mids$[mid_open_54c6a166] = env->getMethodID(cls, "open", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void IReleasableFile::close() const
      {
        env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
      }

      ::java::lang::String IReleasableFile::getFileName() const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getFileName_14c7b5c5]));
      }

      void IReleasableFile::open() const
      {
        env->callVoidMethod(this$, mids$[mid_open_54c6a166]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace io {
      static PyObject *t_IReleasableFile_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IReleasableFile_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IReleasableFile_close(t_IReleasableFile *self);
      static PyObject *t_IReleasableFile_getFileName(t_IReleasableFile *self);
      static PyObject *t_IReleasableFile_open(t_IReleasableFile *self);
      static PyObject *t_IReleasableFile_get__fileName(t_IReleasableFile *self, void *data);
      static PyGetSetDef t_IReleasableFile__fields_[] = {
        DECLARE_GET_FIELD(t_IReleasableFile, fileName),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IReleasableFile__methods_[] = {
        DECLARE_METHOD(t_IReleasableFile, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IReleasableFile, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IReleasableFile, close, METH_NOARGS),
        DECLARE_METHOD(t_IReleasableFile, getFileName, METH_NOARGS),
        DECLARE_METHOD(t_IReleasableFile, open, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IReleasableFile, t_IReleasableFile, ::java::lang::Object, IReleasableFile, abstract_init, 0, 0, t_IReleasableFile__fields_, 0, 0);

      void t_IReleasableFile::install(PyObject *module)
      {
        installType(&PY_TYPE(IReleasableFile), module, "IReleasableFile", 0);
      }

      void t_IReleasableFile::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IReleasableFile).tp_dict, "class_", make_descriptor(IReleasableFile::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IReleasableFile).tp_dict, "wrapfn_", make_descriptor(t_IReleasableFile::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IReleasableFile).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IReleasableFile_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IReleasableFile::initializeClass, 1)))
          return NULL;
        return t_IReleasableFile::wrap_Object(IReleasableFile(((t_IReleasableFile *) arg)->object.this$));
      }
      static PyObject *t_IReleasableFile_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IReleasableFile::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IReleasableFile_close(t_IReleasableFile *self)
      {
        OBJ_CALL(self->object.close());
        Py_RETURN_NONE;
      }

      static PyObject *t_IReleasableFile_getFileName(t_IReleasableFile *self)
      {
        ::java::lang::String result((jobject) NULL);
        OBJ_CALL(result = self->object.getFileName());
        return j2p(result);
      }

      static PyObject *t_IReleasableFile_open(t_IReleasableFile *self)
      {
        OBJ_CALL(self->object.open());
        Py_RETURN_NONE;
      }

      static PyObject *t_IReleasableFile_get__fileName(t_IReleasableFile *self, void *data)
      {
        ::java::lang::String value((jobject) NULL);
        OBJ_CALL(value = self->object.getFileName());
        return j2p(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/doubles/IDoubleList.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace doubles {

      ::java::lang::Class *IDoubleList::class$ = NULL;
      jmethodID *IDoubleList::mids$ = NULL;
      bool IDoubleList::live$ = false;

      jclass IDoubleList::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/doubles/IDoubleList");

          mids$ = new jmethodID[max_mid];
          mids$[mid_append_5d1c7645] = env->getMethodID(cls, "append", "(D)V");
          mids$[mid_appendAll_0253084a] = env->getMethodID(cls, "appendAll", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_insert_5aa51c57] = env->getMethodID(cls, "insert", "(ID)V");
          mids$[mid_insertAll_9665a230] = env->getMethodID(cls, "insertAll", "(ILstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_remove_39c7bd3c] = env->getMethodID(cls, "remove", "(I)V");
          mids$[mid_removeByValue_5d1c7645] = env->getMethodID(cls, "removeByValue", "(D)V");
          mids$[mid_removeRange_d8d154a6] = env->getMethodID(cls, "removeRange", "(II)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void IDoubleList::append(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_append_5d1c7645], a0);
      }

      void IDoubleList::appendAll(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_appendAll_0253084a], a0.this$);
      }

      void IDoubleList::insert(jint a0, jdouble a1) const
      {
        env->callVoidMethod(this$, mids$[mid_insert_5aa51c57], a0, a1);
      }

      void IDoubleList::insertAll(jint a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_insertAll_9665a230], a0, a1.this$);
      }

      void IDoubleList::remove(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_remove_39c7bd3c], a0);
      }

      void IDoubleList::removeByValue(jdouble a0) const
      {
        env->callVoidMethod(this$, mids$[mid_removeByValue_5d1c7645], a0);
      }

      void IDoubleList::removeRange(jint a0, jint a1) const
      {
        env->callVoidMethod(this$, mids$[mid_removeRange_d8d154a6], a0, a1);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace doubles {
      static PyObject *t_IDoubleList_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDoubleList_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDoubleList_append(t_IDoubleList *self, PyObject *arg);
      static PyObject *t_IDoubleList_appendAll(t_IDoubleList *self, PyObject *arg);
      static PyObject *t_IDoubleList_insert(t_IDoubleList *self, PyObject *args);
      static PyObject *t_IDoubleList_insertAll(t_IDoubleList *self, PyObject *args);
      static PyObject *t_IDoubleList_remove(t_IDoubleList *self, PyObject *arg);
      static PyObject *t_IDoubleList_removeByValue(t_IDoubleList *self, PyObject *arg);
      static PyObject *t_IDoubleList_removeRange(t_IDoubleList *self, PyObject *args);

      static PyMethodDef t_IDoubleList__methods_[] = {
        DECLARE_METHOD(t_IDoubleList, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDoubleList, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDoubleList, append, METH_O),
        DECLARE_METHOD(t_IDoubleList, appendAll, METH_O),
        DECLARE_METHOD(t_IDoubleList, insert, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleList, insertAll, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleList, remove, METH_O),
        DECLARE_METHOD(t_IDoubleList, removeByValue, METH_O),
        DECLARE_METHOD(t_IDoubleList, removeRange, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDoubleList, t_IDoubleList, ::stallone::api::doubles::IDoubleArray, IDoubleList, abstract_init, 0, 0, 0, 0, 0);

      void t_IDoubleList::install(PyObject *module)
      {
        installType(&PY_TYPE(IDoubleList), module, "IDoubleList", 0);
      }

      void t_IDoubleList::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDoubleList).tp_dict, "class_", make_descriptor(IDoubleList::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDoubleList).tp_dict, "wrapfn_", make_descriptor(t_IDoubleList::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDoubleList).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDoubleList_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDoubleList::initializeClass, 1)))
          return NULL;
        return t_IDoubleList::wrap_Object(IDoubleList(((t_IDoubleList *) arg)->object.this$));
      }
      static PyObject *t_IDoubleList_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDoubleList::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDoubleList_append(t_IDoubleList *self, PyObject *arg)
      {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
          OBJ_CALL(self->object.append(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "append", arg);
        return NULL;
      }

      static PyObject *t_IDoubleList_appendAll(t_IDoubleList *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.appendAll(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "appendAll", arg);
        return NULL;
      }

      static PyObject *t_IDoubleList_insert(t_IDoubleList *self, PyObject *args)
      {
        jint a0;
        jdouble a1;

        if (!parseArgs(args, "ID", &a0, &a1))
        {
          OBJ_CALL(self->object.insert(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "insert", args);
        return NULL;
      }

      static PyObject *t_IDoubleList_insertAll(t_IDoubleList *self, PyObject *args)
      {
        jint a0;
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);

        if (!parseArgs(args, "Ik", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.insertAll(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "insertAll", args);
        return NULL;
      }

      static PyObject *t_IDoubleList_remove(t_IDoubleList *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.remove(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "remove", arg);
        return NULL;
      }

      static PyObject *t_IDoubleList_removeByValue(t_IDoubleList *self, PyObject *arg)
      {
        jdouble a0;

        if (!parseArg(arg, "D", &a0))
        {
          OBJ_CALL(self->object.removeByValue(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "removeByValue", arg);
        return NULL;
      }

      static PyObject *t_IDoubleList_removeRange(t_IDoubleList *self, PyObject *args)
      {
        jint a0;
        jint a1;

        if (!parseArgs(args, "II", &a0, &a1))
        {
          OBJ_CALL(self->object.removeRange(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "removeRange", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/io/IOUtilities.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace io {

      ::java::lang::Class *IOUtilities::class$ = NULL;
      jmethodID *IOUtilities::mids$ = NULL;
      bool IOUtilities::live$ = false;

      jclass IOUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/io/IOUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_canCreateFile_5fdc3f44] = env->getMethodID(cls, "canCreateFile", "(Ljava/lang/String;)Z");
          mids$[mid_error_5fdc3f48] = env->getMethodID(cls, "error", "(Ljava/lang/String;)V");
          mids$[mid_getBasename_97a5258f] = env->getMethodID(cls, "getBasename", "(Ljava/lang/String;)Ljava/lang/String;");
          mids$[mid_getDirectory_97a5258f] = env->getMethodID(cls, "getDirectory", "(Ljava/lang/String;)Ljava/lang/String;");
          mids$[mid_getExtension_97a5258f] = env->getMethodID(cls, "getExtension", "(Ljava/lang/String;)Ljava/lang/String;");
          mids$[mid_getFilename_97a5258f] = env->getMethodID(cls, "getFilename", "(Ljava/lang/String;)Ljava/lang/String;");
          mids$[mid_writeString_4a264742] = env->getMethodID(cls, "writeString", "(Ljava/lang/String;Ljava/lang/String;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      IOUtilities::IOUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      jboolean IOUtilities::canCreateFile(const ::java::lang::String & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_canCreateFile_5fdc3f44], a0.this$);
      }

      void IOUtilities::error(const ::java::lang::String & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_error_5fdc3f48], a0.this$);
      }

      ::java::lang::String IOUtilities::getBasename(const ::java::lang::String & a0) const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getBasename_97a5258f], a0.this$));
      }

      ::java::lang::String IOUtilities::getDirectory(const ::java::lang::String & a0) const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getDirectory_97a5258f], a0.this$));
      }

      ::java::lang::String IOUtilities::getExtension(const ::java::lang::String & a0) const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getExtension_97a5258f], a0.this$));
      }

      ::java::lang::String IOUtilities::getFilename(const ::java::lang::String & a0) const
      {
        return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getFilename_97a5258f], a0.this$));
      }

      void IOUtilities::writeString(const ::java::lang::String & a0, const ::java::lang::String & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_writeString_4a264742], a0.this$, a1.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace io {
      static PyObject *t_IOUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IOUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_IOUtilities_init_(t_IOUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_IOUtilities_canCreateFile(t_IOUtilities *self, PyObject *arg);
      static PyObject *t_IOUtilities_error(t_IOUtilities *self, PyObject *arg);
      static PyObject *t_IOUtilities_getBasename(t_IOUtilities *self, PyObject *arg);
      static PyObject *t_IOUtilities_getDirectory(t_IOUtilities *self, PyObject *arg);
      static PyObject *t_IOUtilities_getExtension(t_IOUtilities *self, PyObject *arg);
      static PyObject *t_IOUtilities_getFilename(t_IOUtilities *self, PyObject *arg);
      static PyObject *t_IOUtilities_writeString(t_IOUtilities *self, PyObject *args);

      static PyMethodDef t_IOUtilities__methods_[] = {
        DECLARE_METHOD(t_IOUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IOUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IOUtilities, canCreateFile, METH_O),
        DECLARE_METHOD(t_IOUtilities, error, METH_O),
        DECLARE_METHOD(t_IOUtilities, getBasename, METH_O),
        DECLARE_METHOD(t_IOUtilities, getDirectory, METH_O),
        DECLARE_METHOD(t_IOUtilities, getExtension, METH_O),
        DECLARE_METHOD(t_IOUtilities, getFilename, METH_O),
        DECLARE_METHOD(t_IOUtilities, writeString, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IOUtilities, t_IOUtilities, ::java::lang::Object, IOUtilities, t_IOUtilities_init_, 0, 0, 0, 0, 0);

      void t_IOUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(IOUtilities), module, "IOUtilities", 0);
      }

      void t_IOUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IOUtilities).tp_dict, "class_", make_descriptor(IOUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IOUtilities).tp_dict, "wrapfn_", make_descriptor(t_IOUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IOUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IOUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IOUtilities::initializeClass, 1)))
          return NULL;
        return t_IOUtilities::wrap_Object(IOUtilities(((t_IOUtilities *) arg)->object.this$));
      }
      static PyObject *t_IOUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IOUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_IOUtilities_init_(t_IOUtilities *self, PyObject *args, PyObject *kwds)
      {
        IOUtilities object((jobject) NULL);

        INT_CALL(object = IOUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_IOUtilities_canCreateFile(t_IOUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.canCreateFile(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "canCreateFile", arg);
        return NULL;
      }

      static PyObject *t_IOUtilities_error(t_IOUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(self->object.error(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "error", arg);
        return NULL;
      }

      static PyObject *t_IOUtilities_getBasename(t_IOUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::java::lang::String result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.getBasename(a0));
          return j2p(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getBasename", arg);
        return NULL;
      }

      static PyObject *t_IOUtilities_getDirectory(t_IOUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::java::lang::String result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.getDirectory(a0));
          return j2p(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getDirectory", arg);
        return NULL;
      }

      static PyObject *t_IOUtilities_getExtension(t_IOUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::java::lang::String result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.getExtension(a0));
          return j2p(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getExtension", arg);
        return NULL;
      }

      static PyObject *t_IOUtilities_getFilename(t_IOUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::java::lang::String result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.getFilename(a0));
          return j2p(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getFilename", arg);
        return NULL;
      }

      static PyObject *t_IOUtilities_writeString(t_IOUtilities *self, PyObject *args)
      {
        ::java::lang::String a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);

        if (!parseArgs(args, "ss", &a0, &a1))
        {
          OBJ_CALL(self->object.writeString(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "writeString", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/hmm/HMM.h"
#include "stallone/api/hmm/HMMFactory.h"
#include "stallone/api/hmm/HMMUtilities.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace hmm {

      ::java::lang::Class *HMM::class$ = NULL;
      jmethodID *HMM::mids$ = NULL;
      bool HMM::live$ = false;
      ::stallone::api::hmm::HMMFactory *HMM::create = NULL;
      ::stallone::api::hmm::HMMUtilities *HMM::util = NULL;

      jclass HMM::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/hmm/HMM");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::hmm::HMMFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/hmm/HMMFactory;"));
          util = new ::stallone::api::hmm::HMMUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/hmm/HMMUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      HMM::HMM() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace hmm {
      static PyObject *t_HMM_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_HMM_instance_(PyTypeObject *type, PyObject *arg);
      static int t_HMM_init_(t_HMM *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_HMM__methods_[] = {
        DECLARE_METHOD(t_HMM, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_HMM, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(HMM, t_HMM, ::java::lang::Object, HMM, t_HMM_init_, 0, 0, 0, 0, 0);

      void t_HMM::install(PyObject *module)
      {
        installType(&PY_TYPE(HMM), module, "HMM", 0);
      }

      void t_HMM::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(HMM).tp_dict, "class_", make_descriptor(HMM::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(HMM).tp_dict, "wrapfn_", make_descriptor(t_HMM::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(HMM).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(HMM::initializeClass);
        PyDict_SetItemString(PY_TYPE(HMM).tp_dict, "create", make_descriptor(::stallone::api::hmm::t_HMMFactory::wrap_Object(*HMM::create)));
        PyDict_SetItemString(PY_TYPE(HMM).tp_dict, "util", make_descriptor(::stallone::api::hmm::t_HMMUtilities::wrap_Object(*HMM::util)));
      }

      static PyObject *t_HMM_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, HMM::initializeClass, 1)))
          return NULL;
        return t_HMM::wrap_Object(HMM(((t_HMM *) arg)->object.this$));
      }
      static PyObject *t_HMM_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, HMM::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_HMM_init_(t_HMM *self, PyObject *args, PyObject *kwds)
      {
        HMM object((jobject) NULL);

        INT_CALL(object = HMM());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/function/Functions.h"
#include "stallone/api/function/FunctionFactory.h"
#include "stallone/api/function/FunctionUtilities.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace function {

      ::java::lang::Class *Functions::class$ = NULL;
      jmethodID *Functions::mids$ = NULL;
      bool Functions::live$ = false;
      ::stallone::api::function::FunctionFactory *Functions::create = NULL;
      ::stallone::api::function::FunctionUtilities *Functions::util = NULL;

      jclass Functions::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/function/Functions");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::function::FunctionFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/function/FunctionFactory;"));
          util = new ::stallone::api::function::FunctionUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/function/FunctionUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      Functions::Functions() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace function {
      static PyObject *t_Functions_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_Functions_instance_(PyTypeObject *type, PyObject *arg);
      static int t_Functions_init_(t_Functions *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_Functions__methods_[] = {
        DECLARE_METHOD(t_Functions, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Functions, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(Functions, t_Functions, ::java::lang::Object, Functions, t_Functions_init_, 0, 0, 0, 0, 0);

      void t_Functions::install(PyObject *module)
      {
        installType(&PY_TYPE(Functions), module, "Functions", 0);
      }

      void t_Functions::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(Functions).tp_dict, "class_", make_descriptor(Functions::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Functions).tp_dict, "wrapfn_", make_descriptor(t_Functions::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Functions).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(Functions::initializeClass);
        PyDict_SetItemString(PY_TYPE(Functions).tp_dict, "create", make_descriptor(::stallone::api::function::t_FunctionFactory::wrap_Object(*Functions::create)));
        PyDict_SetItemString(PY_TYPE(Functions).tp_dict, "util", make_descriptor(::stallone::api::function::t_FunctionUtilities::wrap_Object(*Functions::util)));
      }

      static PyObject *t_Functions_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, Functions::initializeClass, 1)))
          return NULL;
        return t_Functions::wrap_Object(Functions(((t_Functions *) arg)->object.this$));
      }
      static PyObject *t_Functions_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, Functions::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_Functions_init_(t_Functions *self, PyObject *args, PyObject *kwds)
      {
        Functions object((jobject) NULL);

        INT_CALL(object = Functions());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/io/Writer.h"
#include "java/lang/Appendable.h"
#include "java/lang/CharSequence.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace io {

    ::java::lang::Class *Writer::class$ = NULL;
    jmethodID *Writer::mids$ = NULL;
    bool Writer::live$ = false;

    jclass Writer::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/io/Writer");

        mids$ = new jmethodID[max_mid];
        mids$[mid_append_368f1679] = env->getMethodID(cls, "append", "(C)Ljava/io/Writer;");
        mids$[mid_append_31d2f801] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/io/Writer;");
        mids$[mid_append_b3d4aa31] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/io/Writer;");
        mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");
        mids$[mid_flush_54c6a166] = env->getMethodID(cls, "flush", "()V");
        mids$[mid_write_5fdc3f48] = env->getMethodID(cls, "write", "(Ljava/lang/String;)V");
        mids$[mid_write_700e23d6] = env->getMethodID(cls, "write", "([C)V");
        mids$[mid_write_39c7bd3c] = env->getMethodID(cls, "write", "(I)V");
        mids$[mid_write_555f322c] = env->getMethodID(cls, "write", "(Ljava/lang/String;II)V");
        mids$[mid_write_6f0bb356] = env->getMethodID(cls, "write", "([CII)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Writer Writer::append(jchar a0) const
    {
      return Writer(env->callObjectMethod(this$, mids$[mid_append_368f1679], a0));
    }

    Writer Writer::append(const ::java::lang::CharSequence & a0) const
    {
      return Writer(env->callObjectMethod(this$, mids$[mid_append_31d2f801], a0.this$));
    }

    Writer Writer::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
    {
      return Writer(env->callObjectMethod(this$, mids$[mid_append_b3d4aa31], a0.this$, a1, a2));
    }

    void Writer::close() const
    {
      env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
    }

    void Writer::flush() const
    {
      env->callVoidMethod(this$, mids$[mid_flush_54c6a166]);
    }

    void Writer::write(const ::java::lang::String & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_write_5fdc3f48], a0.this$);
    }

    void Writer::write(const JArray< jchar > & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_write_700e23d6], a0.this$);
    }

    void Writer::write(jint a0) const
    {
      env->callVoidMethod(this$, mids$[mid_write_39c7bd3c], a0);
    }

    void Writer::write(const ::java::lang::String & a0, jint a1, jint a2) const
    {
      env->callVoidMethod(this$, mids$[mid_write_555f322c], a0.this$, a1, a2);
    }

    void Writer::write(const JArray< jchar > & a0, jint a1, jint a2) const
    {
      env->callVoidMethod(this$, mids$[mid_write_6f0bb356], a0.this$, a1, a2);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace io {
    static PyObject *t_Writer_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Writer_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Writer_append(t_Writer *self, PyObject *args);
    static PyObject *t_Writer_close(t_Writer *self);
    static PyObject *t_Writer_flush(t_Writer *self);
    static PyObject *t_Writer_write(t_Writer *self, PyObject *args);

    static PyMethodDef t_Writer__methods_[] = {
      DECLARE_METHOD(t_Writer, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Writer, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Writer, append, METH_VARARGS),
      DECLARE_METHOD(t_Writer, close, METH_NOARGS),
      DECLARE_METHOD(t_Writer, flush, METH_NOARGS),
      DECLARE_METHOD(t_Writer, write, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Writer, t_Writer, ::java::lang::Object, Writer, abstract_init, 0, 0, 0, 0, 0);

    void t_Writer::install(PyObject *module)
    {
      installType(&PY_TYPE(Writer), module, "Writer", 0);
    }

    void t_Writer::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Writer).tp_dict, "class_", make_descriptor(Writer::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Writer).tp_dict, "wrapfn_", make_descriptor(t_Writer::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Writer).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Writer_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Writer::initializeClass, 1)))
        return NULL;
      return t_Writer::wrap_Object(Writer(((t_Writer *) arg)->object.this$));
    }
    static PyObject *t_Writer_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Writer::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Writer_append(t_Writer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jchar a0;
          Writer result((jobject) NULL);

          if (!parseArgs(args, "C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_Writer::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          Writer result((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_Writer::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          jint a1;
          jint a2;
          Writer result((jobject) NULL);

          if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_Writer::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "append", args);
      return NULL;
    }

    static PyObject *t_Writer_close(t_Writer *self)
    {
      OBJ_CALL(self->object.close());
      Py_RETURN_NONE;
    }

    static PyObject *t_Writer_flush(t_Writer *self)
    {
      OBJ_CALL(self->object.flush());
      Py_RETURN_NONE;
    }

    static PyObject *t_Writer_write(t_Writer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(self->object.write(a0));
            Py_RETURN_NONE;
          }
        }
        {
          JArray< jchar > a0((jobject) NULL);

          if (!parseArgs(args, "[C", &a0))
          {
            OBJ_CALL(self->object.write(a0));
            Py_RETURN_NONE;
          }
        }
        {
          jint a0;

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(self->object.write(a0));
            Py_RETURN_NONE;
          }
        }
        break;
       case 3:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint a2;

          if (!parseArgs(args, "sII", &a0, &a1, &a2))
          {
            OBJ_CALL(self->object.write(a0, a1, a2));
            Py_RETURN_NONE;
          }
        }
        {
          JArray< jchar > a0((jobject) NULL);
          jint a1;
          jint a2;

          if (!parseArgs(args, "[CII", &a0, &a1, &a2))
          {
            OBJ_CALL(self->object.write(a0, a1, a2));
            Py_RETURN_NONE;
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "write", args);
      return NULL;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/stat/StatisticsFactory.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/stat/IParameterEstimator.h"
#include "stallone/api/stat/IDiscreteDistribution.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace stat {

      ::java::lang::Class *StatisticsFactory::class$ = NULL;
      jmethodID *StatisticsFactory::mids$ = NULL;
      bool StatisticsFactory::live$ = false;

      jclass StatisticsFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/stat/StatisticsFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_discreteDistribution_a0d9efea] = env->getMethodID(cls, "discreteDistribution", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/stat/IDiscreteDistribution;");
          mids$[mid_parameterEstimatorGaussian1D_e97d706e] = env->getMethodID(cls, "parameterEstimatorGaussian1D", "()Lstallone/api/stat/IParameterEstimator;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      StatisticsFactory::StatisticsFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::stat::IDiscreteDistribution StatisticsFactory::discreteDistribution(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::stat::IDiscreteDistribution(env->callObjectMethod(this$, mids$[mid_discreteDistribution_a0d9efea], a0.this$));
      }

      ::stallone::api::stat::IParameterEstimator StatisticsFactory::parameterEstimatorGaussian1D() const
      {
        return ::stallone::api::stat::IParameterEstimator(env->callObjectMethod(this$, mids$[mid_parameterEstimatorGaussian1D_e97d706e]));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace stat {
      static PyObject *t_StatisticsFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_StatisticsFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_StatisticsFactory_init_(t_StatisticsFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_StatisticsFactory_discreteDistribution(t_StatisticsFactory *self, PyObject *arg);
      static PyObject *t_StatisticsFactory_parameterEstimatorGaussian1D(t_StatisticsFactory *self);

      static PyMethodDef t_StatisticsFactory__methods_[] = {
        DECLARE_METHOD(t_StatisticsFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_StatisticsFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_StatisticsFactory, discreteDistribution, METH_O),
        DECLARE_METHOD(t_StatisticsFactory, parameterEstimatorGaussian1D, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(StatisticsFactory, t_StatisticsFactory, ::java::lang::Object, StatisticsFactory, t_StatisticsFactory_init_, 0, 0, 0, 0, 0);

      void t_StatisticsFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(StatisticsFactory), module, "StatisticsFactory", 0);
      }

      void t_StatisticsFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(StatisticsFactory).tp_dict, "class_", make_descriptor(StatisticsFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(StatisticsFactory).tp_dict, "wrapfn_", make_descriptor(t_StatisticsFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(StatisticsFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_StatisticsFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, StatisticsFactory::initializeClass, 1)))
          return NULL;
        return t_StatisticsFactory::wrap_Object(StatisticsFactory(((t_StatisticsFactory *) arg)->object.this$));
      }
      static PyObject *t_StatisticsFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, StatisticsFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_StatisticsFactory_init_(t_StatisticsFactory *self, PyObject *args, PyObject *kwds)
      {
        StatisticsFactory object((jobject) NULL);

        INT_CALL(object = StatisticsFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_StatisticsFactory_discreteDistribution(t_StatisticsFactory *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::stat::IDiscreteDistribution result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.discreteDistribution(a0));
          return ::stallone::api::stat::t_IDiscreteDistribution::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "discreteDistribution", arg);
        return NULL;
      }

      static PyObject *t_StatisticsFactory_parameterEstimatorGaussian1D(t_StatisticsFactory *self)
      {
        ::stallone::api::stat::IParameterEstimator result((jobject) NULL);
        OBJ_CALL(result = self->object.parameterEstimatorGaussian1D());
        return ::stallone::api::stat::t_IParameterEstimator::wrap_Object(result);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Class.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/SecurityException.h"
#include "java/lang/String.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/Package.h"
#include "java/lang/ClassLoader.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Class::class$ = NULL;
    jmethodID *Class::mids$ = NULL;
    bool Class::live$ = false;

    jclass Class::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Class");

        mids$ = new jmethodID[max_mid];
        mids$[mid_asSubclass_ecb22eb3] = env->getMethodID(cls, "asSubclass", "(Ljava/lang/Class;)Ljava/lang/Class;");
        mids$[mid_cast_a932a95f] = env->getMethodID(cls, "cast", "(Ljava/lang/Object;)Ljava/lang/Object;");
        mids$[mid_desiredAssertionStatus_54c6a16a] = env->getMethodID(cls, "desiredAssertionStatus", "()Z");
        mids$[mid_forName_7d663d97] = env->getStaticMethodID(cls, "forName", "(Ljava/lang/String;)Ljava/lang/Class;");
        mids$[mid_forName_4c5c10fb] = env->getStaticMethodID(cls, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");
        mids$[mid_getCanonicalName_14c7b5c5] = env->getMethodID(cls, "getCanonicalName", "()Ljava/lang/String;");
        mids$[mid_getClassLoader_8d2f11fc] = env->getMethodID(cls, "getClassLoader", "()Ljava/lang/ClassLoader;");
        mids$[mid_getClasses_ffb25e7d] = env->getMethodID(cls, "getClasses", "()[Ljava/lang/Class;");
        mids$[mid_getComponentType_44a5f2c9] = env->getMethodID(cls, "getComponentType", "()Ljava/lang/Class;");
        mids$[mid_getDeclaredClasses_ffb25e7d] = env->getMethodID(cls, "getDeclaredClasses", "()[Ljava/lang/Class;");
        mids$[mid_getDeclaringClass_44a5f2c9] = env->getMethodID(cls, "getDeclaringClass", "()Ljava/lang/Class;");
        mids$[mid_getEnclosingClass_44a5f2c9] = env->getMethodID(cls, "getEnclosingClass", "()Ljava/lang/Class;");
        mids$[mid_getEnumConstants_94e49c77] = env->getMethodID(cls, "getEnumConstants", "()[Ljava/lang/Object;");
        mids$[mid_getInterfaces_ffb25e7d] = env->getMethodID(cls, "getInterfaces", "()[Ljava/lang/Class;");
        mids$[mid_getModifiers_54c6a179] = env->getMethodID(cls, "getModifiers", "()I");
        mids$[mid_getName_14c7b5c5] = env->getMethodID(cls, "getName", "()Ljava/lang/String;");
        mids$[mid_getPackage_b0f2f7bb] = env->getMethodID(cls, "getPackage", "()Ljava/lang/Package;");
        mids$[mid_getSigners_94e49c77] = env->getMethodID(cls, "getSigners", "()[Ljava/lang/Object;");
        mids$[mid_getSimpleName_14c7b5c5] = env->getMethodID(cls, "getSimpleName", "()Ljava/lang/String;");
        mids$[mid_getSuperclass_44a5f2c9] = env->getMethodID(cls, "getSuperclass", "()Ljava/lang/Class;");
        mids$[mid_isAnnotation_54c6a16a] = env->getMethodID(cls, "isAnnotation", "()Z");
        mids$[mid_isAnonymousClass_54c6a16a] = env->getMethodID(cls, "isAnonymousClass", "()Z");
        mids$[mid_isArray_54c6a16a] = env->getMethodID(cls, "isArray", "()Z");
        mids$[mid_isAssignableFrom_a5deaff8] = env->getMethodID(cls, "isAssignableFrom", "(Ljava/lang/Class;)Z");
        mids$[mid_isEnum_54c6a16a] = env->getMethodID(cls, "isEnum", "()Z");
        mids$[mid_isInstance_290588e2] = env->getMethodID(cls, "isInstance", "(Ljava/lang/Object;)Z");
        mids$[mid_isInterface_54c6a16a] = env->getMethodID(cls, "isInterface", "()Z");
        mids$[mid_isLocalClass_54c6a16a] = env->getMethodID(cls, "isLocalClass", "()Z");
        mids$[mid_isMemberClass_54c6a16a] = env->getMethodID(cls, "isMemberClass", "()Z");
        mids$[mid_isPrimitive_54c6a16a] = env->getMethodID(cls, "isPrimitive", "()Z");
        mids$[mid_isSynthetic_54c6a16a] = env->getMethodID(cls, "isSynthetic", "()Z");
        mids$[mid_newInstance_846352c3] = env->getMethodID(cls, "newInstance", "()Ljava/lang/Object;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Class Class::asSubclass(const Class & a0) const
    {
      return Class(env->callObjectMethod(this$, mids$[mid_asSubclass_ecb22eb3], a0.this$));
    }

    ::java::lang::Object Class::cast(const ::java::lang::Object & a0) const
    {
      return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_cast_a932a95f], a0.this$));
    }

    jboolean Class::desiredAssertionStatus() const
    {
      return env->callBooleanMethod(this$, mids$[mid_desiredAssertionStatus_54c6a16a]);
    }

    Class Class::forName(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Class(env->callStaticObjectMethod(cls, mids$[mid_forName_7d663d97], a0.this$));
    }

    Class Class::forName(const ::java::lang::String & a0, jboolean a1, const ::java::lang::ClassLoader & a2)
    {
      jclass cls = env->getClass(initializeClass);
      return Class(env->callStaticObjectMethod(cls, mids$[mid_forName_4c5c10fb], a0.this$, a1, a2.this$));
    }

    ::java::lang::String Class::getCanonicalName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getCanonicalName_14c7b5c5]));
    }

    ::java::lang::ClassLoader Class::getClassLoader() const
    {
      return ::java::lang::ClassLoader(env->callObjectMethod(this$, mids$[mid_getClassLoader_8d2f11fc]));
    }

    JArray< Class > Class::getClasses() const
    {
      return JArray< Class >(env->callObjectMethod(this$, mids$[mid_getClasses_ffb25e7d]));
    }

    Class Class::getComponentType() const
    {
      return Class(env->callObjectMethod(this$, mids$[mid_getComponentType_44a5f2c9]));
    }

    JArray< Class > Class::getDeclaredClasses() const
    {
      return JArray< Class >(env->callObjectMethod(this$, mids$[mid_getDeclaredClasses_ffb25e7d]));
    }

    Class Class::getDeclaringClass() const
    {
      return Class(env->callObjectMethod(this$, mids$[mid_getDeclaringClass_44a5f2c9]));
    }

    Class Class::getEnclosingClass() const
    {
      return Class(env->callObjectMethod(this$, mids$[mid_getEnclosingClass_44a5f2c9]));
    }

    JArray< ::java::lang::Object > Class::getEnumConstants() const
    {
      return JArray< ::java::lang::Object >(env->callObjectMethod(this$, mids$[mid_getEnumConstants_94e49c77]));
    }

    JArray< Class > Class::getInterfaces() const
    {
      return JArray< Class >(env->callObjectMethod(this$, mids$[mid_getInterfaces_ffb25e7d]));
    }

    jint Class::getModifiers() const
    {
      return env->callIntMethod(this$, mids$[mid_getModifiers_54c6a179]);
    }

    ::java::lang::String Class::getName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getName_14c7b5c5]));
    }

    ::java::lang::Package Class::getPackage() const
    {
      return ::java::lang::Package(env->callObjectMethod(this$, mids$[mid_getPackage_b0f2f7bb]));
    }

    JArray< ::java::lang::Object > Class::getSigners() const
    {
      return JArray< ::java::lang::Object >(env->callObjectMethod(this$, mids$[mid_getSigners_94e49c77]));
    }

    ::java::lang::String Class::getSimpleName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSimpleName_14c7b5c5]));
    }

    Class Class::getSuperclass() const
    {
      return Class(env->callObjectMethod(this$, mids$[mid_getSuperclass_44a5f2c9]));
    }

    jboolean Class::isAnnotation() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isAnnotation_54c6a16a]);
    }

    jboolean Class::isAnonymousClass() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isAnonymousClass_54c6a16a]);
    }

    jboolean Class::isArray() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isArray_54c6a16a]);
    }

    jboolean Class::isAssignableFrom(const Class & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_isAssignableFrom_a5deaff8], a0.this$);
    }

    jboolean Class::isEnum() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isEnum_54c6a16a]);
    }

    jboolean Class::isInstance(const ::java::lang::Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_isInstance_290588e2], a0.this$);
    }

    jboolean Class::isInterface() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isInterface_54c6a16a]);
    }

    jboolean Class::isLocalClass() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isLocalClass_54c6a16a]);
    }

    jboolean Class::isMemberClass() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isMemberClass_54c6a16a]);
    }

    jboolean Class::isPrimitive() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isPrimitive_54c6a16a]);
    }

    jboolean Class::isSynthetic() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isSynthetic_54c6a16a]);
    }

    ::java::lang::Object Class::newInstance() const
    {
      return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_newInstance_846352c3]));
    }

    ::java::lang::String Class::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Class_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Class_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Class_of_(t_Class *self, PyObject *args);
    static PyObject *t_Class_asSubclass(t_Class *self, PyObject *arg);
    static PyObject *t_Class_cast(t_Class *self, PyObject *arg);
    static PyObject *t_Class_desiredAssertionStatus(t_Class *self);
    static PyObject *t_Class_forName(PyTypeObject *type, PyObject *args);
    static PyObject *t_Class_getCanonicalName(t_Class *self);
    static PyObject *t_Class_getClassLoader(t_Class *self);
    static PyObject *t_Class_getClasses(t_Class *self);
    static PyObject *t_Class_getComponentType(t_Class *self);
    static PyObject *t_Class_getDeclaredClasses(t_Class *self);
    static PyObject *t_Class_getDeclaringClass(t_Class *self);
    static PyObject *t_Class_getEnclosingClass(t_Class *self);
    static PyObject *t_Class_getEnumConstants(t_Class *self);
    static PyObject *t_Class_getInterfaces(t_Class *self);
    static PyObject *t_Class_getModifiers(t_Class *self);
    static PyObject *t_Class_getName(t_Class *self);
    static PyObject *t_Class_getPackage(t_Class *self);
    static PyObject *t_Class_getSigners(t_Class *self);
    static PyObject *t_Class_getSimpleName(t_Class *self);
    static PyObject *t_Class_getSuperclass(t_Class *self);
    static PyObject *t_Class_isAnnotation(t_Class *self);
    static PyObject *t_Class_isAnonymousClass(t_Class *self);
    static PyObject *t_Class_isArray(t_Class *self);
    static PyObject *t_Class_isAssignableFrom(t_Class *self, PyObject *arg);
    static PyObject *t_Class_isEnum(t_Class *self);
    static PyObject *t_Class_isInstance(t_Class *self, PyObject *arg);
    static PyObject *t_Class_isInterface(t_Class *self);
    static PyObject *t_Class_isLocalClass(t_Class *self);
    static PyObject *t_Class_isMemberClass(t_Class *self);
    static PyObject *t_Class_isPrimitive(t_Class *self);
    static PyObject *t_Class_isSynthetic(t_Class *self);
    static PyObject *t_Class_newInstance(t_Class *self);
    static PyObject *t_Class_toString(t_Class *self, PyObject *args);
    static PyObject *t_Class_get__annotation(t_Class *self, void *data);
    static PyObject *t_Class_get__anonymousClass(t_Class *self, void *data);
    static PyObject *t_Class_get__array(t_Class *self, void *data);
    static PyObject *t_Class_get__canonicalName(t_Class *self, void *data);
    static PyObject *t_Class_get__classLoader(t_Class *self, void *data);
    static PyObject *t_Class_get__classes(t_Class *self, void *data);
    static PyObject *t_Class_get__componentType(t_Class *self, void *data);
    static PyObject *t_Class_get__declaredClasses(t_Class *self, void *data);
    static PyObject *t_Class_get__declaringClass(t_Class *self, void *data);
    static PyObject *t_Class_get__enclosingClass(t_Class *self, void *data);
    static PyObject *t_Class_get__enum(t_Class *self, void *data);
    static PyObject *t_Class_get__enumConstants(t_Class *self, void *data);
    static PyObject *t_Class_get__interface(t_Class *self, void *data);
    static PyObject *t_Class_get__interfaces(t_Class *self, void *data);
    static PyObject *t_Class_get__localClass(t_Class *self, void *data);
    static PyObject *t_Class_get__memberClass(t_Class *self, void *data);
    static PyObject *t_Class_get__modifiers(t_Class *self, void *data);
    static PyObject *t_Class_get__name(t_Class *self, void *data);
    static PyObject *t_Class_get__package(t_Class *self, void *data);
    static PyObject *t_Class_get__primitive(t_Class *self, void *data);
    static PyObject *t_Class_get__signers(t_Class *self, void *data);
    static PyObject *t_Class_get__simpleName(t_Class *self, void *data);
    static PyObject *t_Class_get__superclass(t_Class *self, void *data);
    static PyObject *t_Class_get__synthetic(t_Class *self, void *data);
    static PyObject *t_Class_get__parameters_(t_Class *self, void *data);
    static PyGetSetDef t_Class__fields_[] = {
      DECLARE_GET_FIELD(t_Class, annotation),
      DECLARE_GET_FIELD(t_Class, anonymousClass),
      DECLARE_GET_FIELD(t_Class, array),
      DECLARE_GET_FIELD(t_Class, canonicalName),
      DECLARE_GET_FIELD(t_Class, classLoader),
      DECLARE_GET_FIELD(t_Class, classes),
      DECLARE_GET_FIELD(t_Class, componentType),
      DECLARE_GET_FIELD(t_Class, declaredClasses),
      DECLARE_GET_FIELD(t_Class, declaringClass),
      DECLARE_GET_FIELD(t_Class, enclosingClass),
      DECLARE_GET_FIELD(t_Class, enum),
      DECLARE_GET_FIELD(t_Class, enumConstants),
      DECLARE_GET_FIELD(t_Class, interface),
      DECLARE_GET_FIELD(t_Class, interfaces),
      DECLARE_GET_FIELD(t_Class, localClass),
      DECLARE_GET_FIELD(t_Class, memberClass),
      DECLARE_GET_FIELD(t_Class, modifiers),
      DECLARE_GET_FIELD(t_Class, name),
      DECLARE_GET_FIELD(t_Class, package),
      DECLARE_GET_FIELD(t_Class, primitive),
      DECLARE_GET_FIELD(t_Class, signers),
      DECLARE_GET_FIELD(t_Class, simpleName),
      DECLARE_GET_FIELD(t_Class, superclass),
      DECLARE_GET_FIELD(t_Class, synthetic),
      DECLARE_GET_FIELD(t_Class, parameters_),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Class__methods_[] = {
      DECLARE_METHOD(t_Class, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Class, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Class, of_, METH_VARARGS),
      DECLARE_METHOD(t_Class, asSubclass, METH_O),
      DECLARE_METHOD(t_Class, cast, METH_O),
      DECLARE_METHOD(t_Class, desiredAssertionStatus, METH_NOARGS),
      DECLARE_METHOD(t_Class, forName, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Class, getCanonicalName, METH_NOARGS),
      DECLARE_METHOD(t_Class, getClassLoader, METH_NOARGS),
      DECLARE_METHOD(t_Class, getClasses, METH_NOARGS),
      DECLARE_METHOD(t_Class, getComponentType, METH_NOARGS),
      DECLARE_METHOD(t_Class, getDeclaredClasses, METH_NOARGS),
      DECLARE_METHOD(t_Class, getDeclaringClass, METH_NOARGS),
      DECLARE_METHOD(t_Class, getEnclosingClass, METH_NOARGS),
      DECLARE_METHOD(t_Class, getEnumConstants, METH_NOARGS),
      DECLARE_METHOD(t_Class, getInterfaces, METH_NOARGS),
      DECLARE_METHOD(t_Class, getModifiers, METH_NOARGS),
      DECLARE_METHOD(t_Class, getName, METH_NOARGS),
      DECLARE_METHOD(t_Class, getPackage, METH_NOARGS),
      DECLARE_METHOD(t_Class, getSigners, METH_NOARGS),
      DECLARE_METHOD(t_Class, getSimpleName, METH_NOARGS),
      DECLARE_METHOD(t_Class, getSuperclass, METH_NOARGS),
      DECLARE_METHOD(t_Class, isAnnotation, METH_NOARGS),
      DECLARE_METHOD(t_Class, isAnonymousClass, METH_NOARGS),
      DECLARE_METHOD(t_Class, isArray, METH_NOARGS),
      DECLARE_METHOD(t_Class, isAssignableFrom, METH_O),
      DECLARE_METHOD(t_Class, isEnum, METH_NOARGS),
      DECLARE_METHOD(t_Class, isInstance, METH_O),
      DECLARE_METHOD(t_Class, isInterface, METH_NOARGS),
      DECLARE_METHOD(t_Class, isLocalClass, METH_NOARGS),
      DECLARE_METHOD(t_Class, isMemberClass, METH_NOARGS),
      DECLARE_METHOD(t_Class, isPrimitive, METH_NOARGS),
      DECLARE_METHOD(t_Class, isSynthetic, METH_NOARGS),
      DECLARE_METHOD(t_Class, newInstance, METH_NOARGS),
      DECLARE_METHOD(t_Class, toString, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Class, t_Class, ::java::lang::Object, Class, abstract_init, 0, 0, t_Class__fields_, 0, 0);
    PyObject *t_Class::wrap_Object(const Class& object, PyTypeObject *T)
    {
      PyObject *obj = t_Class::wrap_Object(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Class *self = (t_Class *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    PyObject *t_Class::wrap_jobject(const jobject& object, PyTypeObject *T)
    {
      PyObject *obj = t_Class::wrap_jobject(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Class *self = (t_Class *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    void t_Class::install(PyObject *module)
    {
      installType(&PY_TYPE(Class), module, "Class", 0);
    }

    void t_Class::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Class).tp_dict, "class_", make_descriptor(Class::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Class).tp_dict, "wrapfn_", make_descriptor(t_Class::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Class).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Class_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Class::initializeClass, 1)))
        return NULL;
      return t_Class::wrap_Object(Class(((t_Class *) arg)->object.this$));
    }
    static PyObject *t_Class_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Class::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Class_of_(t_Class *self, PyObject *args)
    {
      if (!parseArg(args, "T", 1, &(self->parameters)))
        Py_RETURN_SELF;
      return PyErr_SetArgsError((PyObject *) self, "of_", args);
    }

    static PyObject *t_Class_asSubclass(t_Class *self, PyObject *arg)
    {
      Class a0((jobject) NULL);
      PyTypeObject **p0;
      Class result((jobject) NULL);

      if (!parseArg(arg, "K", Class::initializeClass, &a0, &p0, t_Class::parameters_))
      {
        OBJ_CALL(result = self->object.asSubclass(a0));
        return t_Class::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "asSubclass", arg);
      return NULL;
    }

    static PyObject *t_Class_cast(t_Class *self, PyObject *arg)
    {
      ::java::lang::Object a0((jobject) NULL);
      ::java::lang::Object result((jobject) NULL);

      if (!parseArg(arg, "o", &a0))
      {
        OBJ_CALL(result = self->object.cast(a0));
        return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "cast", arg);
      return NULL;
    }

    static PyObject *t_Class_desiredAssertionStatus(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.desiredAssertionStatus());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_forName(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          Class result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Class::forName(a0));
            return t_Class::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          ::java::lang::String a0((jobject) NULL);
          jboolean a1;
          ::java::lang::ClassLoader a2((jobject) NULL);
          Class result((jobject) NULL);

          if (!parseArgs(args, "sZk", ::java::lang::ClassLoader::initializeClass, &a0, &a1, &a2))
          {
            OBJ_CALL(result = ::java::lang::Class::forName(a0, a1, a2));
            return t_Class::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "forName", args);
      return NULL;
    }

    static PyObject *t_Class_getCanonicalName(t_Class *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getCanonicalName());
      return j2p(result);
    }

    static PyObject *t_Class_getClassLoader(t_Class *self)
    {
      ::java::lang::ClassLoader result((jobject) NULL);
      OBJ_CALL(result = self->object.getClassLoader());
      return ::java::lang::t_ClassLoader::wrap_Object(result);
    }

    static PyObject *t_Class_getClasses(t_Class *self)
    {
      JArray< Class > result((jobject) NULL);
      OBJ_CALL(result = self->object.getClasses());
      return JArray<jobject>(result.this$).wrap(t_Class::wrap_jobject);
    }

    static PyObject *t_Class_getComponentType(t_Class *self)
    {
      Class result((jobject) NULL);
      OBJ_CALL(result = self->object.getComponentType());
      return t_Class::wrap_Object(result);
    }

    static PyObject *t_Class_getDeclaredClasses(t_Class *self)
    {
      JArray< Class > result((jobject) NULL);
      OBJ_CALL(result = self->object.getDeclaredClasses());
      return JArray<jobject>(result.this$).wrap(t_Class::wrap_jobject);
    }

    static PyObject *t_Class_getDeclaringClass(t_Class *self)
    {
      Class result((jobject) NULL);
      OBJ_CALL(result = self->object.getDeclaringClass());
      return t_Class::wrap_Object(result);
    }

    static PyObject *t_Class_getEnclosingClass(t_Class *self)
    {
      Class result((jobject) NULL);
      OBJ_CALL(result = self->object.getEnclosingClass());
      return t_Class::wrap_Object(result);
    }

    static PyObject *t_Class_getEnumConstants(t_Class *self)
    {
      JArray< ::java::lang::Object > result((jobject) NULL);
      OBJ_CALL(result = self->object.getEnumConstants());
      return JArray<jobject>(result.this$).wrap(::java::lang::t_Object::wrap_jobject);
    }

    static PyObject *t_Class_getInterfaces(t_Class *self)
    {
      JArray< Class > result((jobject) NULL);
      OBJ_CALL(result = self->object.getInterfaces());
      return JArray<jobject>(result.this$).wrap(t_Class::wrap_jobject);
    }

    static PyObject *t_Class_getModifiers(t_Class *self)
    {
      jint result;
      OBJ_CALL(result = self->object.getModifiers());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_Class_getName(t_Class *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getName());
      return j2p(result);
    }

    static PyObject *t_Class_getPackage(t_Class *self)
    {
      ::java::lang::Package result((jobject) NULL);
      OBJ_CALL(result = self->object.getPackage());
      return ::java::lang::t_Package::wrap_Object(result);
    }

    static PyObject *t_Class_getSigners(t_Class *self)
    {
      JArray< ::java::lang::Object > result((jobject) NULL);
      OBJ_CALL(result = self->object.getSigners());
      return JArray<jobject>(result.this$).wrap(::java::lang::t_Object::wrap_jobject);
    }

    static PyObject *t_Class_getSimpleName(t_Class *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getSimpleName());
      return j2p(result);
    }

    static PyObject *t_Class_getSuperclass(t_Class *self)
    {
      Class result((jobject) NULL);
      OBJ_CALL(result = self->object.getSuperclass());
      return t_Class::wrap_Object(result);
    }

    static PyObject *t_Class_isAnnotation(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isAnnotation());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isAnonymousClass(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isAnonymousClass());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isArray(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isArray());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isAssignableFrom(t_Class *self, PyObject *arg)
    {
      Class a0((jobject) NULL);
      PyTypeObject **p0;
      jboolean result;

      if (!parseArg(arg, "K", Class::initializeClass, &a0, &p0, t_Class::parameters_))
      {
        OBJ_CALL(result = self->object.isAssignableFrom(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError((PyObject *) self, "isAssignableFrom", arg);
      return NULL;
    }

    static PyObject *t_Class_isEnum(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isEnum());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isInstance(t_Class *self, PyObject *arg)
    {
      ::java::lang::Object a0((jobject) NULL);
      jboolean result;

      if (!parseArg(arg, "o", &a0))
      {
        OBJ_CALL(result = self->object.isInstance(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError((PyObject *) self, "isInstance", arg);
      return NULL;
    }

    static PyObject *t_Class_isInterface(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isInterface());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isLocalClass(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isLocalClass());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isMemberClass(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isMemberClass());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isPrimitive(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isPrimitive());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_isSynthetic(t_Class *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isSynthetic());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Class_newInstance(t_Class *self)
    {
      ::java::lang::Object result((jobject) NULL);
      OBJ_CALL(result = self->object.newInstance());
      return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
    }

    static PyObject *t_Class_toString(t_Class *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Class), (PyObject *) self, "toString", args, 2);
    }
    static PyObject *t_Class_get__parameters_(t_Class *self, void *data)
    {
      return typeParameters(self->parameters, sizeof(self->parameters));
    }

    static PyObject *t_Class_get__annotation(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isAnnotation());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__anonymousClass(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isAnonymousClass());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__array(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isArray());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__canonicalName(t_Class *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getCanonicalName());
      return j2p(value);
    }

    static PyObject *t_Class_get__classLoader(t_Class *self, void *data)
    {
      ::java::lang::ClassLoader value((jobject) NULL);
      OBJ_CALL(value = self->object.getClassLoader());
      return ::java::lang::t_ClassLoader::wrap_Object(value);
    }

    static PyObject *t_Class_get__classes(t_Class *self, void *data)
    {
      JArray< Class > value((jobject) NULL);
      OBJ_CALL(value = self->object.getClasses());
      return JArray<jobject>(value.this$).wrap(t_Class::wrap_jobject);
    }

    static PyObject *t_Class_get__componentType(t_Class *self, void *data)
    {
      Class value((jobject) NULL);
      OBJ_CALL(value = self->object.getComponentType());
      return t_Class::wrap_Object(value);
    }

    static PyObject *t_Class_get__declaredClasses(t_Class *self, void *data)
    {
      JArray< Class > value((jobject) NULL);
      OBJ_CALL(value = self->object.getDeclaredClasses());
      return JArray<jobject>(value.this$).wrap(t_Class::wrap_jobject);
    }

    static PyObject *t_Class_get__declaringClass(t_Class *self, void *data)
    {
      Class value((jobject) NULL);
      OBJ_CALL(value = self->object.getDeclaringClass());
      return t_Class::wrap_Object(value);
    }

    static PyObject *t_Class_get__enclosingClass(t_Class *self, void *data)
    {
      Class value((jobject) NULL);
      OBJ_CALL(value = self->object.getEnclosingClass());
      return t_Class::wrap_Object(value);
    }

    static PyObject *t_Class_get__enum(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isEnum());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__enumConstants(t_Class *self, void *data)
    {
      JArray< ::java::lang::Object > value((jobject) NULL);
      OBJ_CALL(value = self->object.getEnumConstants());
      return JArray<jobject>(value.this$).wrap(::java::lang::t_Object::wrap_jobject);
    }

    static PyObject *t_Class_get__interface(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isInterface());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__interfaces(t_Class *self, void *data)
    {
      JArray< Class > value((jobject) NULL);
      OBJ_CALL(value = self->object.getInterfaces());
      return JArray<jobject>(value.this$).wrap(t_Class::wrap_jobject);
    }

    static PyObject *t_Class_get__localClass(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isLocalClass());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__memberClass(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isMemberClass());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__modifiers(t_Class *self, void *data)
    {
      jint value;
      OBJ_CALL(value = self->object.getModifiers());
      return PyInt_FromLong((long) value);
    }

    static PyObject *t_Class_get__name(t_Class *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getName());
      return j2p(value);
    }

    static PyObject *t_Class_get__package(t_Class *self, void *data)
    {
      ::java::lang::Package value((jobject) NULL);
      OBJ_CALL(value = self->object.getPackage());
      return ::java::lang::t_Package::wrap_Object(value);
    }

    static PyObject *t_Class_get__primitive(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isPrimitive());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Class_get__signers(t_Class *self, void *data)
    {
      JArray< ::java::lang::Object > value((jobject) NULL);
      OBJ_CALL(value = self->object.getSigners());
      return JArray<jobject>(value.this$).wrap(::java::lang::t_Object::wrap_jobject);
    }

    static PyObject *t_Class_get__simpleName(t_Class *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getSimpleName());
      return j2p(value);
    }

    static PyObject *t_Class_get__superclass(t_Class *self, void *data)
    {
      Class value((jobject) NULL);
      OBJ_CALL(value = self->object.getSuperclass());
      return t_Class::wrap_Object(value);
    }

    static PyObject *t_Class_get__synthetic(t_Class *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isSynthetic());
      Py_RETURN_BOOL(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Boolean.h"
#include "java/lang/String.h"
#include "java/lang/Comparable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Boolean::class$ = NULL;
    jmethodID *Boolean::mids$ = NULL;
    bool Boolean::live$ = false;
    Boolean *Boolean::FALSE = NULL;
    Boolean *Boolean::TRUE = NULL;
    ::java::lang::Class *Boolean::TYPE = NULL;

    jclass Boolean::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Boolean");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_bb0c767f] = env->getMethodID(cls, "<init>", "(Z)V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_booleanValue_54c6a16a] = env->getMethodID(cls, "booleanValue", "()Z");
        mids$[mid_compareTo_d07f0c91] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Boolean;)I");
        mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        mids$[mid_getBoolean_5fdc3f44] = env->getStaticMethodID(cls, "getBoolean", "(Ljava/lang/String;)Z");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_parseBoolean_5fdc3f44] = env->getStaticMethodID(cls, "parseBoolean", "(Ljava/lang/String;)Z");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_toString_445a175e] = env->getStaticMethodID(cls, "toString", "(Z)Ljava/lang/String;");
        mids$[mid_valueOf_a98d5bba] = env->getStaticMethodID(cls, "valueOf", "(Z)Ljava/lang/Boolean;");
        mids$[mid_valueOf_9d4a8ff9] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Boolean;");

        class$ = (::java::lang::Class *) new JObject(cls);
        cls = (jclass) class$->this$;

        FALSE = new Boolean(env->getStaticObjectField(cls, "FALSE", "Ljava/lang/Boolean;"));
        TRUE = new Boolean(env->getStaticObjectField(cls, "TRUE", "Ljava/lang/Boolean;"));
        TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Boolean::Boolean(jboolean a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_bb0c767f, a0)) {}

    Boolean::Boolean(const ::java::lang::String & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    jboolean Boolean::booleanValue() const
    {
      return env->callBooleanMethod(this$, mids$[mid_booleanValue_54c6a16a]);
    }

    jint Boolean::compareTo(const Boolean & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_compareTo_d07f0c91], a0.this$);
    }

    jboolean Boolean::equals(const ::java::lang::Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
    }

    jboolean Boolean::getBoolean(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticBooleanMethod(cls, mids$[mid_getBoolean_5fdc3f44], a0.this$);
    }

    jint Boolean::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    jboolean Boolean::parseBoolean(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticBooleanMethod(cls, mids$[mid_parseBoolean_5fdc3f44], a0.this$);
    }

    ::java::lang::String Boolean::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    ::java::lang::String Boolean::toString(jboolean a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_445a175e], a0));
    }

    Boolean Boolean::valueOf(jboolean a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Boolean(env->callStaticObjectMethod(cls, mids$[mid_valueOf_a98d5bba], a0));
    }

    Boolean Boolean::valueOf(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Boolean(env->callStaticObjectMethod(cls, mids$[mid_valueOf_9d4a8ff9], a0.this$));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Boolean_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Boolean_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Boolean_init_(t_Boolean *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Boolean_booleanValue(t_Boolean *self);
    static PyObject *t_Boolean_compareTo(t_Boolean *self, PyObject *arg);
    static PyObject *t_Boolean_equals(t_Boolean *self, PyObject *args);
    static PyObject *t_Boolean_getBoolean(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Boolean_hashCode(t_Boolean *self, PyObject *args);
    static PyObject *t_Boolean_parseBoolean(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Boolean_toString(t_Boolean *self, PyObject *args);
    static PyObject *t_Boolean_toString_(PyTypeObject *type, PyObject *args);
    static PyObject *t_Boolean_valueOf(PyTypeObject *type, PyObject *args);

    static PyMethodDef t_Boolean__methods_[] = {
      DECLARE_METHOD(t_Boolean, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Boolean, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Boolean, booleanValue, METH_NOARGS),
      DECLARE_METHOD(t_Boolean, compareTo, METH_O),
      DECLARE_METHOD(t_Boolean, equals, METH_VARARGS),
      DECLARE_METHOD(t_Boolean, getBoolean, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Boolean, hashCode, METH_VARARGS),
      DECLARE_METHOD(t_Boolean, parseBoolean, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Boolean, toString, METH_VARARGS),
      DECLARE_METHOD(t_Boolean, toString_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Boolean, valueOf, METH_VARARGS | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Boolean, t_Boolean, ::java::lang::Object, Boolean, t_Boolean_init_, 0, 0, 0, 0, 0);

    void t_Boolean::install(PyObject *module)
    {
      installType(&PY_TYPE(Boolean), module, "Boolean", 0);
    }

    void t_Boolean::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "class_", make_descriptor(Boolean::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "wrapfn_", make_descriptor(unboxBoolean));
      PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "boxfn_", make_descriptor(boxBoolean));
      env->getClass(Boolean::initializeClass);
      PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "FALSE", make_descriptor(t_Boolean::wrap_Object(*Boolean::FALSE)));
      PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "TRUE", make_descriptor(t_Boolean::wrap_Object(*Boolean::TRUE)));
      PyDict_SetItemString(PY_TYPE(Boolean).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Boolean::TYPE)));
    }

    static PyObject *t_Boolean_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Boolean::initializeClass, 1)))
        return NULL;
      return t_Boolean::wrap_Object(Boolean(((t_Boolean *) arg)->object.this$));
    }
    static PyObject *t_Boolean_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Boolean::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Boolean_init_(t_Boolean *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jboolean a0;
          Boolean object((jobject) NULL);

          if (!parseArgs(args, "Z", &a0))
          {
            INT_CALL(object = Boolean(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Boolean object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = Boolean(a0));
            self->object = object;
            break;
          }
        }
       default:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_Boolean_booleanValue(t_Boolean *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.booleanValue());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Boolean_compareTo(t_Boolean *self, PyObject *arg)
    {
      Boolean a0((jobject) NULL);
      jint result;

      if (!parseArg(arg, "O", &::java::lang::PY_TYPE(Boolean), &a0))
      {
        OBJ_CALL(result = self->object.compareTo(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "compareTo", arg);
      return NULL;
    }

    static PyObject *t_Boolean_equals(t_Boolean *self, PyObject *args)
    {
      ::java::lang::Object a0((jobject) NULL);
      jboolean result;

      if (!parseArgs(args, "o", &a0))
      {
        OBJ_CALL(result = self->object.equals(a0));
        Py_RETURN_BOOL(result);
      }

      return callSuper(&PY_TYPE(Boolean), (PyObject *) self, "equals", args, 2);
    }

    static PyObject *t_Boolean_getBoolean(PyTypeObject *type, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      jboolean result;

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = ::java::lang::Boolean::getBoolean(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError(type, "getBoolean", arg);
      return NULL;
    }

    static PyObject *t_Boolean_hashCode(t_Boolean *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.hashCode());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Boolean), (PyObject *) self, "hashCode", args, 2);
    }

    static PyObject *t_Boolean_parseBoolean(PyTypeObject *type, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      jboolean result;

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = ::java::lang::Boolean::parseBoolean(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError(type, "parseBoolean", arg);
      return NULL;
    }

    static PyObject *t_Boolean_toString(t_Boolean *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Boolean), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_Boolean_toString_(PyTypeObject *type, PyObject *args)
    {
      jboolean a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, "Z", &a0))
      {
        OBJ_CALL(result = ::java::lang::Boolean::toString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toString_", args);
      return NULL;
    }

    static PyObject *t_Boolean_valueOf(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jboolean a0;
          Boolean result((jobject) NULL);

          if (!parseArgs(args, "Z", &a0))
          {
            OBJ_CALL(result = ::java::lang::Boolean::valueOf(a0));
            return t_Boolean::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Boolean result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Boolean::valueOf(a0));
            return t_Boolean::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "valueOf", args);
      return NULL;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/ICopyable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {

    ::java::lang::Class *ICopyable::class$ = NULL;
    jmethodID *ICopyable::mids$ = NULL;
    bool ICopyable::live$ = false;

    jclass ICopyable::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("stallone/api/ICopyable");

        mids$ = new jmethodID[max_mid];
        mids$[mid_copy_846352c3] = env->getMethodID(cls, "copy", "()Ljava/lang/Object;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    ::java::lang::Object ICopyable::copy() const
    {
      return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_copy_846352c3]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    static PyObject *t_ICopyable_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_ICopyable_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_ICopyable_of_(t_ICopyable *self, PyObject *args);
    static PyObject *t_ICopyable_copy(t_ICopyable *self);
    static PyObject *t_ICopyable_get__parameters_(t_ICopyable *self, void *data);
    static PyGetSetDef t_ICopyable__fields_[] = {
      DECLARE_GET_FIELD(t_ICopyable, parameters_),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_ICopyable__methods_[] = {
      DECLARE_METHOD(t_ICopyable, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_ICopyable, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_ICopyable, of_, METH_VARARGS),
      DECLARE_METHOD(t_ICopyable, copy, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(ICopyable, t_ICopyable, ::java::lang::Object, ICopyable, abstract_init, 0, 0, t_ICopyable__fields_, 0, 0);
    PyObject *t_ICopyable::wrap_Object(const ICopyable& object, PyTypeObject *T)
    {
      PyObject *obj = t_ICopyable::wrap_Object(object);
      if (obj != NULL && obj != Py_None)
      {
        t_ICopyable *self = (t_ICopyable *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    PyObject *t_ICopyable::wrap_jobject(const jobject& object, PyTypeObject *T)
    {
      PyObject *obj = t_ICopyable::wrap_jobject(object);
      if (obj != NULL && obj != Py_None)
      {
        t_ICopyable *self = (t_ICopyable *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    void t_ICopyable::install(PyObject *module)
    {
      installType(&PY_TYPE(ICopyable), module, "ICopyable", 0);
    }

    void t_ICopyable::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(ICopyable).tp_dict, "class_", make_descriptor(ICopyable::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(ICopyable).tp_dict, "wrapfn_", make_descriptor(t_ICopyable::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(ICopyable).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_ICopyable_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, ICopyable::initializeClass, 1)))
        return NULL;
      return t_ICopyable::wrap_Object(ICopyable(((t_ICopyable *) arg)->object.this$));
    }
    static PyObject *t_ICopyable_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, ICopyable::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_ICopyable_of_(t_ICopyable *self, PyObject *args)
    {
      if (!parseArg(args, "T", 1, &(self->parameters)))
        Py_RETURN_SELF;
      return PyErr_SetArgsError((PyObject *) self, "of_", args);
    }

    static PyObject *t_ICopyable_copy(t_ICopyable *self)
    {
      ::java::lang::Object result((jobject) NULL);
      OBJ_CALL(result = self->object.copy());
      return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
    }
    static PyObject *t_ICopyable_get__parameters_(t_ICopyable *self, void *data)
    {
      return typeParameters(self->parameters, sizeof(self->parameters));
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/intsequence/IntSequenceUtilities.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/ints/IIntList.h"
#include "java/lang/Iterable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace intsequence {

      ::java::lang::Class *IntSequenceUtilities::class$ = NULL;
      jmethodID *IntSequenceUtilities::mids$ = NULL;
      bool IntSequenceUtilities::live$ = false;

      jclass IntSequenceUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/intsequence/IntSequenceUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_lifetimesByState_e8cc7f5f] = env->getMethodID(cls, "lifetimesByState", "(Lstallone/api/ints/IIntArray;)[Lstallone/api/ints/IIntList;");
          mids$[mid_loadIntSequence_24ec4a57] = env->getMethodID(cls, "loadIntSequence", "(Ljava/lang/String;)Lstallone/api/ints/IIntArray;");
          mids$[mid_max_d1cac21a] = env->getMethodID(cls, "max", "(Ljava/lang/Iterable;)I");
          mids$[mid_writeIntSequence_e256d906] = env->getMethodID(cls, "writeIntSequence", "(Lstallone/api/ints/IIntArray;Ljava/lang/String;)V");
          mids$[mid_writeIntSequenceSparse_e256d906] = env->getMethodID(cls, "writeIntSequenceSparse", "(Lstallone/api/ints/IIntArray;Ljava/lang/String;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      IntSequenceUtilities::IntSequenceUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      JArray< ::stallone::api::ints::IIntList > IntSequenceUtilities::lifetimesByState(const ::stallone::api::ints::IIntArray & a0) const
      {
        return JArray< ::stallone::api::ints::IIntList >(env->callObjectMethod(this$, mids$[mid_lifetimesByState_e8cc7f5f], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntSequenceUtilities::loadIntSequence(const ::java::lang::String & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_loadIntSequence_24ec4a57], a0.this$));
      }

      jint IntSequenceUtilities::max$(const ::java::lang::Iterable & a0) const
      {
        return env->callIntMethod(this$, mids$[mid_max_d1cac21a], a0.this$);
      }

      void IntSequenceUtilities::writeIntSequence(const ::stallone::api::ints::IIntArray & a0, const ::java::lang::String & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_writeIntSequence_e256d906], a0.this$, a1.this$);
      }

      void IntSequenceUtilities::writeIntSequenceSparse(const ::stallone::api::ints::IIntArray & a0, const ::java::lang::String & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_writeIntSequenceSparse_e256d906], a0.this$, a1.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace intsequence {
      static PyObject *t_IntSequenceUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IntSequenceUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_IntSequenceUtilities_init_(t_IntSequenceUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_IntSequenceUtilities_lifetimesByState(t_IntSequenceUtilities *self, PyObject *arg);
      static PyObject *t_IntSequenceUtilities_loadIntSequence(t_IntSequenceUtilities *self, PyObject *arg);
      static PyObject *t_IntSequenceUtilities_max(t_IntSequenceUtilities *self, PyObject *arg);
      static PyObject *t_IntSequenceUtilities_writeIntSequence(t_IntSequenceUtilities *self, PyObject *args);
      static PyObject *t_IntSequenceUtilities_writeIntSequenceSparse(t_IntSequenceUtilities *self, PyObject *args);

      static PyMethodDef t_IntSequenceUtilities__methods_[] = {
        DECLARE_METHOD(t_IntSequenceUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntSequenceUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntSequenceUtilities, lifetimesByState, METH_O),
        DECLARE_METHOD(t_IntSequenceUtilities, loadIntSequence, METH_O),
        DECLARE_METHOD(t_IntSequenceUtilities, max, METH_O),
        DECLARE_METHOD(t_IntSequenceUtilities, writeIntSequence, METH_VARARGS),
        DECLARE_METHOD(t_IntSequenceUtilities, writeIntSequenceSparse, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IntSequenceUtilities, t_IntSequenceUtilities, ::java::lang::Object, IntSequenceUtilities, t_IntSequenceUtilities_init_, 0, 0, 0, 0, 0);

      void t_IntSequenceUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(IntSequenceUtilities), module, "IntSequenceUtilities", 0);
      }

      void t_IntSequenceUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IntSequenceUtilities).tp_dict, "class_", make_descriptor(IntSequenceUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IntSequenceUtilities).tp_dict, "wrapfn_", make_descriptor(t_IntSequenceUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IntSequenceUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IntSequenceUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IntSequenceUtilities::initializeClass, 1)))
          return NULL;
        return t_IntSequenceUtilities::wrap_Object(IntSequenceUtilities(((t_IntSequenceUtilities *) arg)->object.this$));
      }
      static PyObject *t_IntSequenceUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IntSequenceUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_IntSequenceUtilities_init_(t_IntSequenceUtilities *self, PyObject *args, PyObject *kwds)
      {
        IntSequenceUtilities object((jobject) NULL);

        INT_CALL(object = IntSequenceUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_IntSequenceUtilities_lifetimesByState(t_IntSequenceUtilities *self, PyObject *arg)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);
        JArray< ::stallone::api::ints::IIntList > result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::ints::IIntArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.lifetimesByState(a0));
          return JArray<jobject>(result.this$).wrap(::stallone::api::ints::t_IIntList::wrap_jobject);
        }

        PyErr_SetArgsError((PyObject *) self, "lifetimesByState", arg);
        return NULL;
      }

      static PyObject *t_IntSequenceUtilities_loadIntSequence(t_IntSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.loadIntSequence(a0));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "loadIntSequence", arg);
        return NULL;
      }

      static PyObject *t_IntSequenceUtilities_max(t_IntSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::Iterable a0((jobject) NULL);
        PyTypeObject **p0;
        jint result;

        if (!parseArg(arg, "K", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_))
        {
          OBJ_CALL(result = self->object.max$(a0));
          return PyInt_FromLong((long) result);
        }

        PyErr_SetArgsError((PyObject *) self, "max", arg);
        return NULL;
      }

      static PyObject *t_IntSequenceUtilities_writeIntSequence(t_IntSequenceUtilities *self, PyObject *args)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);

        if (!parseArgs(args, "ks", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.writeIntSequence(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "writeIntSequence", args);
        return NULL;
      }

      static PyObject *t_IntSequenceUtilities_writeIntSequenceSparse(t_IntSequenceUtilities *self, PyObject *args)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);

        if (!parseArgs(args, "ks", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.writeIntSequenceSparse(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "writeIntSequenceSparse", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/mc/MarkovModelFactory.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/mc/tpt/ICommittor.h"
#include "stallone/api/mc/IDynamicalExpectationsSpectral.h"
#include "stallone/api/mc/ITransitionMatrixEstimator.h"
#include "stallone/api/mc/tpt/ITPTFlux.h"
#include "java/lang/Iterable.h"
#include "stallone/api/function/IGriddedFunction.h"
#include "stallone/mc/sampling/ITransitionMatrixSampler.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/mc/ICountMatrixEstimator.h"
#include "stallone/api/mc/IMarkovChain.h"
#include "stallone/api/mc/IDynamicalExpectations.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace mc {

      ::java::lang::Class *MarkovModelFactory::class$ = NULL;
      jmethodID *MarkovModelFactory::mids$ = NULL;
      bool MarkovModelFactory::live$ = false;

      jclass MarkovModelFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/mc/MarkovModelFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_createCommittor_870b6049] = env->getMethodID(cls, "createCommittor", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/ints/IIntArray;Lstallone/api/ints/IIntArray;)Lstallone/api/mc/tpt/ICommittor;");
          mids$[mid_createCommittor_3f63ad7d] = env->getMethodID(cls, "createCommittor", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/ints/IIntArray;Lstallone/api/ints/IIntArray;)Lstallone/api/mc/tpt/ICommittor;");
          mids$[mid_createCountMatrixEstimatorSliding_c083c1f7] = env->getMethodID(cls, "createCountMatrixEstimatorSliding", "(Lstallone/api/ints/IIntArray;I)Lstallone/api/mc/ICountMatrixEstimator;");
          mids$[mid_createCountMatrixEstimatorSliding_8189d6b4] = env->getMethodID(cls, "createCountMatrixEstimatorSliding", "(Ljava/lang/Iterable;I)Lstallone/api/mc/ICountMatrixEstimator;");
          mids$[mid_createCountMatrixEstimatorStepping_8189d6b4] = env->getMethodID(cls, "createCountMatrixEstimatorStepping", "(Ljava/lang/Iterable;I)Lstallone/api/mc/ICountMatrixEstimator;");
          mids$[mid_createCountMatrixEstimatorStepping_c083c1f7] = env->getMethodID(cls, "createCountMatrixEstimatorStepping", "(Lstallone/api/ints/IIntArray;I)Lstallone/api/mc/ICountMatrixEstimator;");
          mids$[mid_createDynamicalExpectations_de594d69] = env->getMethodID(cls, "createDynamicalExpectations", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/IDynamicalExpectations;");
          mids$[mid_createDynamicalExpectations_d135d589] = env->getMethodID(cls, "createDynamicalExpectations", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/IDynamicalExpectations;");
          mids$[mid_createDynamicalFingerprint_2aadcea1] = env->getMethodID(cls, "createDynamicalFingerprint", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/IDynamicalExpectationsSpectral;");
          mids$[mid_createDynamicalFingerprint_1cefcc2d] = env->getMethodID(cls, "createDynamicalFingerprint", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/IDynamicalExpectationsSpectral;");
          mids$[mid_createPosteriorCountsNeighbor_dfd01cbc] = env->getMethodID(cls, "createPosteriorCountsNeighbor", "(Lstallone/api/doubles/IDoubleArray;D)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_createTPT_27159afe] = env->getMethodID(cls, "createTPT", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/ints/IIntArray;Lstallone/api/ints/IIntArray;)Lstallone/api/mc/tpt/ITPTFlux;");
          mids$[mid_createTPT_4040b74e] = env->getMethodID(cls, "createTPT", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/ints/IIntArray;Lstallone/api/ints/IIntArray;)Lstallone/api/mc/tpt/ITPTFlux;");
          mids$[mid_createTransitionMatrixEstimatorNonrev_73c61eaa] = env->getMethodID(cls, "createTransitionMatrixEstimatorNonrev", "()Lstallone/api/mc/ITransitionMatrixEstimator;");
          mids$[mid_createTransitionMatrixEstimatorRev_73c61eaa] = env->getMethodID(cls, "createTransitionMatrixEstimatorRev", "()Lstallone/api/mc/ITransitionMatrixEstimator;");
          mids$[mid_createTransitionMatrixEstimatorRev_a47d591e] = env->getMethodID(cls, "createTransitionMatrixEstimatorRev", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/ITransitionMatrixEstimator;");
          mids$[mid_createTransitionMatrixSamplerNonrev_1d2309ec] = env->getMethodID(cls, "createTransitionMatrixSamplerNonrev", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/mc/sampling/ITransitionMatrixSampler;");
          mids$[mid_createTransitionMatrixSamplerRev_1d2309ec] = env->getMethodID(cls, "createTransitionMatrixSamplerRev", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/mc/sampling/ITransitionMatrixSampler;");
          mids$[mid_createTransitionMatrixSamplerRev_838432fc] = env->getMethodID(cls, "createTransitionMatrixSamplerRev", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/mc/sampling/ITransitionMatrixSampler;");
          mids$[mid_markovChain_0f97f92d] = env->getMethodID(cls, "markovChain", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/IMarkovChain;");
          mids$[mid_markovChain_589965e1] = env->getMethodID(cls, "markovChain", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/mc/IMarkovChain;");
          mids$[mid_metropolisMC_c40bdb68] = env->getMethodID(cls, "metropolisMC", "(Lstallone/api/function/IGriddedFunction;D)Lstallone/api/doubles/IDoubleArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      MarkovModelFactory::MarkovModelFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::mc::tpt::ICommittor MarkovModelFactory::createCommittor(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::ints::IIntArray & a1, const ::stallone::api::ints::IIntArray & a2) const
      {
        return ::stallone::api::mc::tpt::ICommittor(env->callObjectMethod(this$, mids$[mid_createCommittor_870b6049], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::mc::tpt::ICommittor MarkovModelFactory::createCommittor(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::ints::IIntArray & a2, const ::stallone::api::ints::IIntArray & a3) const
      {
        return ::stallone::api::mc::tpt::ICommittor(env->callObjectMethod(this$, mids$[mid_createCommittor_3f63ad7d], a0.this$, a1.this$, a2.this$, a3.this$));
      }

      ::stallone::api::mc::ICountMatrixEstimator MarkovModelFactory::createCountMatrixEstimatorSliding(const ::stallone::api::ints::IIntArray & a0, jint a1) const
      {
        return ::stallone::api::mc::ICountMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createCountMatrixEstimatorSliding_c083c1f7], a0.this$, a1));
      }

      ::stallone::api::mc::ICountMatrixEstimator MarkovModelFactory::createCountMatrixEstimatorSliding(const ::java::lang::Iterable & a0, jint a1) const
      {
        return ::stallone::api::mc::ICountMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createCountMatrixEstimatorSliding_8189d6b4], a0.this$, a1));
      }

      ::stallone::api::mc::ICountMatrixEstimator MarkovModelFactory::createCountMatrixEstimatorStepping(const ::java::lang::Iterable & a0, jint a1) const
      {
        return ::stallone::api::mc::ICountMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createCountMatrixEstimatorStepping_8189d6b4], a0.this$, a1));
      }

      ::stallone::api::mc::ICountMatrixEstimator MarkovModelFactory::createCountMatrixEstimatorStepping(const ::stallone::api::ints::IIntArray & a0, jint a1) const
      {
        return ::stallone::api::mc::ICountMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createCountMatrixEstimatorStepping_c083c1f7], a0.this$, a1));
      }

      ::stallone::api::mc::IDynamicalExpectations MarkovModelFactory::createDynamicalExpectations(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::mc::IDynamicalExpectations(env->callObjectMethod(this$, mids$[mid_createDynamicalExpectations_de594d69], a0.this$));
      }

      ::stallone::api::mc::IDynamicalExpectations MarkovModelFactory::createDynamicalExpectations(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::mc::IDynamicalExpectations(env->callObjectMethod(this$, mids$[mid_createDynamicalExpectations_d135d589], a0.this$, a1.this$));
      }

      ::stallone::api::mc::IDynamicalExpectationsSpectral MarkovModelFactory::createDynamicalFingerprint(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::mc::IDynamicalExpectationsSpectral(env->callObjectMethod(this$, mids$[mid_createDynamicalFingerprint_2aadcea1], a0.this$));
      }

      ::stallone::api::mc::IDynamicalExpectationsSpectral MarkovModelFactory::createDynamicalFingerprint(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::mc::IDynamicalExpectationsSpectral(env->callObjectMethod(this$, mids$[mid_createDynamicalFingerprint_1cefcc2d], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelFactory::createPosteriorCountsNeighbor(const ::stallone::api::doubles::IDoubleArray & a0, jdouble a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_createPosteriorCountsNeighbor_dfd01cbc], a0.this$, a1));
      }

      ::stallone::api::mc::tpt::ITPTFlux MarkovModelFactory::createTPT(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::ints::IIntArray & a1, const ::stallone::api::ints::IIntArray & a2) const
      {
        return ::stallone::api::mc::tpt::ITPTFlux(env->callObjectMethod(this$, mids$[mid_createTPT_27159afe], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::mc::tpt::ITPTFlux MarkovModelFactory::createTPT(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::ints::IIntArray & a2, const ::stallone::api::ints::IIntArray & a3) const
      {
        return ::stallone::api::mc::tpt::ITPTFlux(env->callObjectMethod(this$, mids$[mid_createTPT_4040b74e], a0.this$, a1.this$, a2.this$, a3.this$));
      }

      ::stallone::api::mc::ITransitionMatrixEstimator MarkovModelFactory::createTransitionMatrixEstimatorNonrev() const
      {
        return ::stallone::api::mc::ITransitionMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createTransitionMatrixEstimatorNonrev_73c61eaa]));
      }

      ::stallone::api::mc::ITransitionMatrixEstimator MarkovModelFactory::createTransitionMatrixEstimatorRev() const
      {
        return ::stallone::api::mc::ITransitionMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createTransitionMatrixEstimatorRev_73c61eaa]));
      }

      ::stallone::api::mc::ITransitionMatrixEstimator MarkovModelFactory::createTransitionMatrixEstimatorRev(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::mc::ITransitionMatrixEstimator(env->callObjectMethod(this$, mids$[mid_createTransitionMatrixEstimatorRev_a47d591e], a0.this$));
      }

      ::stallone::mc::sampling::ITransitionMatrixSampler MarkovModelFactory::createTransitionMatrixSamplerNonrev(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::mc::sampling::ITransitionMatrixSampler(env->callObjectMethod(this$, mids$[mid_createTransitionMatrixSamplerNonrev_1d2309ec], a0.this$));
      }

      ::stallone::mc::sampling::ITransitionMatrixSampler MarkovModelFactory::createTransitionMatrixSamplerRev(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::mc::sampling::ITransitionMatrixSampler(env->callObjectMethod(this$, mids$[mid_createTransitionMatrixSamplerRev_1d2309ec], a0.this$));
      }

      ::stallone::mc::sampling::ITransitionMatrixSampler MarkovModelFactory::createTransitionMatrixSamplerRev(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::mc::sampling::ITransitionMatrixSampler(env->callObjectMethod(this$, mids$[mid_createTransitionMatrixSamplerRev_838432fc], a0.this$, a1.this$));
      }

      ::stallone::api::mc::IMarkovChain MarkovModelFactory::markovChain(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::mc::IMarkovChain(env->callObjectMethod(this$, mids$[mid_markovChain_0f97f92d], a0.this$));
      }

      ::stallone::api::mc::IMarkovChain MarkovModelFactory::markovChain(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::mc::IMarkovChain(env->callObjectMethod(this$, mids$[mid_markovChain_589965e1], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelFactory::metropolisMC(const ::stallone::api::function::IGriddedFunction & a0, jdouble a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_metropolisMC_c40bdb68], a0.this$, a1));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace mc {
      static PyObject *t_MarkovModelFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_MarkovModelFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_MarkovModelFactory_init_(t_MarkovModelFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_MarkovModelFactory_createCommittor(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createCountMatrixEstimatorSliding(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createCountMatrixEstimatorStepping(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createDynamicalExpectations(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createDynamicalFingerprint(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createPosteriorCountsNeighbor(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createTPT(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createTransitionMatrixEstimatorNonrev(t_MarkovModelFactory *self);
      static PyObject *t_MarkovModelFactory_createTransitionMatrixEstimatorRev(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_createTransitionMatrixSamplerNonrev(t_MarkovModelFactory *self, PyObject *arg);
      static PyObject *t_MarkovModelFactory_createTransitionMatrixSamplerRev(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_markovChain(t_MarkovModelFactory *self, PyObject *args);
      static PyObject *t_MarkovModelFactory_metropolisMC(t_MarkovModelFactory *self, PyObject *args);

      static PyMethodDef t_MarkovModelFactory__methods_[] = {
        DECLARE_METHOD(t_MarkovModelFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_MarkovModelFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_MarkovModelFactory, createCommittor, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createCountMatrixEstimatorSliding, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createCountMatrixEstimatorStepping, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createDynamicalExpectations, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createDynamicalFingerprint, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createPosteriorCountsNeighbor, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createTPT, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createTransitionMatrixEstimatorNonrev, METH_NOARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createTransitionMatrixEstimatorRev, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, createTransitionMatrixSamplerNonrev, METH_O),
        DECLARE_METHOD(t_MarkovModelFactory, createTransitionMatrixSamplerRev, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, markovChain, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelFactory, metropolisMC, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(MarkovModelFactory, t_MarkovModelFactory, ::java::lang::Object, MarkovModelFactory, t_MarkovModelFactory_init_, 0, 0, 0, 0, 0);

      void t_MarkovModelFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(MarkovModelFactory), module, "MarkovModelFactory", 0);
      }

      void t_MarkovModelFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(MarkovModelFactory).tp_dict, "class_", make_descriptor(MarkovModelFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(MarkovModelFactory).tp_dict, "wrapfn_", make_descriptor(t_MarkovModelFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(MarkovModelFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_MarkovModelFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, MarkovModelFactory::initializeClass, 1)))
          return NULL;
        return t_MarkovModelFactory::wrap_Object(MarkovModelFactory(((t_MarkovModelFactory *) arg)->object.this$));
      }
      static PyObject *t_MarkovModelFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, MarkovModelFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_MarkovModelFactory_init_(t_MarkovModelFactory *self, PyObject *args, PyObject *kwds)
      {
        MarkovModelFactory object((jobject) NULL);

        INT_CALL(object = MarkovModelFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_MarkovModelFactory_createCommittor(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::ints::IIntArray a1((jobject) NULL);
            ::stallone::api::ints::IIntArray a2((jobject) NULL);
            ::stallone::api::mc::tpt::ICommittor result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createCommittor(a0, a1, a2));
              return ::stallone::api::mc::tpt::t_ICommittor::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::ints::IIntArray a2((jobject) NULL);
            ::stallone::api::ints::IIntArray a3((jobject) NULL);
            ::stallone::api::mc::tpt::ICommittor result((jobject) NULL);

            if (!parseArgs(args, "kkkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.createCommittor(a0, a1, a2, a3));
              return ::stallone::api::mc::tpt::t_ICommittor::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createCommittor", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createCountMatrixEstimatorSliding(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::mc::ICountMatrixEstimator result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createCountMatrixEstimatorSliding(a0, a1));
              return ::stallone::api::mc::t_ICountMatrixEstimator::wrap_Object(result);
            }
          }
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::mc::ICountMatrixEstimator result((jobject) NULL);

            if (!parseArgs(args, "KI", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1))
            {
              OBJ_CALL(result = self->object.createCountMatrixEstimatorSliding(a0, a1));
              return ::stallone::api::mc::t_ICountMatrixEstimator::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createCountMatrixEstimatorSliding", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createCountMatrixEstimatorStepping(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::mc::ICountMatrixEstimator result((jobject) NULL);

            if (!parseArgs(args, "KI", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1))
            {
              OBJ_CALL(result = self->object.createCountMatrixEstimatorStepping(a0, a1));
              return ::stallone::api::mc::t_ICountMatrixEstimator::wrap_Object(result);
            }
          }
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::mc::ICountMatrixEstimator result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createCountMatrixEstimatorStepping(a0, a1));
              return ::stallone::api::mc::t_ICountMatrixEstimator::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createCountMatrixEstimatorStepping", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createDynamicalExpectations(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::mc::IDynamicalExpectations result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.createDynamicalExpectations(a0));
              return ::stallone::api::mc::t_IDynamicalExpectations::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::mc::IDynamicalExpectations result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createDynamicalExpectations(a0, a1));
              return ::stallone::api::mc::t_IDynamicalExpectations::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createDynamicalExpectations", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createDynamicalFingerprint(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::mc::IDynamicalExpectationsSpectral result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.createDynamicalFingerprint(a0));
              return ::stallone::api::mc::t_IDynamicalExpectationsSpectral::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::mc::IDynamicalExpectationsSpectral result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createDynamicalFingerprint(a0, a1));
              return ::stallone::api::mc::t_IDynamicalExpectationsSpectral::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createDynamicalFingerprint", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createPosteriorCountsNeighbor(t_MarkovModelFactory *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jdouble a1;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kD", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.createPosteriorCountsNeighbor(a0, a1));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "createPosteriorCountsNeighbor", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createTPT(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 3:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::ints::IIntArray a1((jobject) NULL);
            ::stallone::api::ints::IIntArray a2((jobject) NULL);
            ::stallone::api::mc::tpt::ITPTFlux result((jobject) NULL);

            if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createTPT(a0, a1, a2));
              return ::stallone::api::mc::tpt::t_ITPTFlux::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::ints::IIntArray a2((jobject) NULL);
            ::stallone::api::ints::IIntArray a3((jobject) NULL);
            ::stallone::api::mc::tpt::ITPTFlux result((jobject) NULL);

            if (!parseArgs(args, "kkkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.createTPT(a0, a1, a2, a3));
              return ::stallone::api::mc::tpt::t_ITPTFlux::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createTPT", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createTransitionMatrixEstimatorNonrev(t_MarkovModelFactory *self)
      {
        ::stallone::api::mc::ITransitionMatrixEstimator result((jobject) NULL);
        OBJ_CALL(result = self->object.createTransitionMatrixEstimatorNonrev());
        return ::stallone::api::mc::t_ITransitionMatrixEstimator::wrap_Object(result);
      }

      static PyObject *t_MarkovModelFactory_createTransitionMatrixEstimatorRev(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 0:
          {
            ::stallone::api::mc::ITransitionMatrixEstimator result((jobject) NULL);
            OBJ_CALL(result = self->object.createTransitionMatrixEstimatorRev());
            return ::stallone::api::mc::t_ITransitionMatrixEstimator::wrap_Object(result);
          }
          break;
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::mc::ITransitionMatrixEstimator result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.createTransitionMatrixEstimatorRev(a0));
              return ::stallone::api::mc::t_ITransitionMatrixEstimator::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createTransitionMatrixEstimatorRev", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createTransitionMatrixSamplerNonrev(t_MarkovModelFactory *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::mc::sampling::ITransitionMatrixSampler result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.createTransitionMatrixSamplerNonrev(a0));
          return ::stallone::mc::sampling::t_ITransitionMatrixSampler::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "createTransitionMatrixSamplerNonrev", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_createTransitionMatrixSamplerRev(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::mc::sampling::ITransitionMatrixSampler result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.createTransitionMatrixSamplerRev(a0));
              return ::stallone::mc::sampling::t_ITransitionMatrixSampler::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::mc::sampling::ITransitionMatrixSampler result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createTransitionMatrixSamplerRev(a0, a1));
              return ::stallone::mc::sampling::t_ITransitionMatrixSampler::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createTransitionMatrixSamplerRev", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_markovChain(t_MarkovModelFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::mc::IMarkovChain result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.markovChain(a0));
              return ::stallone::api::mc::t_IMarkovChain::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::mc::IMarkovChain result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.markovChain(a0, a1));
              return ::stallone::api::mc::t_IMarkovChain::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "markovChain", args);
        return NULL;
      }

      static PyObject *t_MarkovModelFactory_metropolisMC(t_MarkovModelFactory *self, PyObject *args)
      {
        ::stallone::api::function::IGriddedFunction a0((jobject) NULL);
        jdouble a1;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kD", ::stallone::api::function::IGriddedFunction::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.metropolisMC(a0, a1));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "metropolisMC", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/IPartialEigensystem.h"
#include "stallone/api/complex/IComplexArray.h"
#include "stallone/api/algebra/IComplexNumber.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *IPartialEigensystem::class$ = NULL;
      jmethodID *IPartialEigensystem::mids$ = NULL;
      bool IPartialEigensystem::live$ = false;

      jclass IPartialEigensystem::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/IPartialEigensystem");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getEigenvalue_3219f116] = env->getMethodID(cls, "getEigenvalue", "(I)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_getLeftEigenvector_f6210079] = env->getMethodID(cls, "getLeftEigenvector", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_getNumberOfAvailableEigenvectors_54c6a179] = env->getMethodID(cls, "getNumberOfAvailableEigenvectors", "()I");
          mids$[mid_getRightEigenvector_f6210079] = env->getMethodID(cls, "getRightEigenvector", "(I)Lstallone/api/complex/IComplexArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::algebra::IComplexNumber IPartialEigensystem::getEigenvalue(jint a0) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_getEigenvalue_3219f116], a0));
      }

      ::stallone::api::complex::IComplexArray IPartialEigensystem::getLeftEigenvector(jint a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_getLeftEigenvector_f6210079], a0));
      }

      jint IPartialEigensystem::getNumberOfAvailableEigenvectors() const
      {
        return env->callIntMethod(this$, mids$[mid_getNumberOfAvailableEigenvectors_54c6a179]);
      }

      ::stallone::api::complex::IComplexArray IPartialEigensystem::getRightEigenvector(jint a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_getRightEigenvector_f6210079], a0));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_IPartialEigensystem_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IPartialEigensystem_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IPartialEigensystem_getEigenvalue(t_IPartialEigensystem *self, PyObject *arg);
      static PyObject *t_IPartialEigensystem_getLeftEigenvector(t_IPartialEigensystem *self, PyObject *arg);
      static PyObject *t_IPartialEigensystem_getNumberOfAvailableEigenvectors(t_IPartialEigensystem *self);
      static PyObject *t_IPartialEigensystem_getRightEigenvector(t_IPartialEigensystem *self, PyObject *arg);
      static PyObject *t_IPartialEigensystem_get__numberOfAvailableEigenvectors(t_IPartialEigensystem *self, void *data);
      static PyGetSetDef t_IPartialEigensystem__fields_[] = {
        DECLARE_GET_FIELD(t_IPartialEigensystem, numberOfAvailableEigenvectors),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IPartialEigensystem__methods_[] = {
        DECLARE_METHOD(t_IPartialEigensystem, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IPartialEigensystem, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IPartialEigensystem, getEigenvalue, METH_O),
        DECLARE_METHOD(t_IPartialEigensystem, getLeftEigenvector, METH_O),
        DECLARE_METHOD(t_IPartialEigensystem, getNumberOfAvailableEigenvectors, METH_NOARGS),
        DECLARE_METHOD(t_IPartialEigensystem, getRightEigenvector, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IPartialEigensystem, t_IPartialEigensystem, ::java::lang::Object, IPartialEigensystem, abstract_init, 0, 0, t_IPartialEigensystem__fields_, 0, 0);

      void t_IPartialEigensystem::install(PyObject *module)
      {
        installType(&PY_TYPE(IPartialEigensystem), module, "IPartialEigensystem", 0);
      }

      void t_IPartialEigensystem::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IPartialEigensystem).tp_dict, "class_", make_descriptor(IPartialEigensystem::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IPartialEigensystem).tp_dict, "wrapfn_", make_descriptor(t_IPartialEigensystem::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IPartialEigensystem).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IPartialEigensystem_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IPartialEigensystem::initializeClass, 1)))
          return NULL;
        return t_IPartialEigensystem::wrap_Object(IPartialEigensystem(((t_IPartialEigensystem *) arg)->object.this$));
      }
      static PyObject *t_IPartialEigensystem_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IPartialEigensystem::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IPartialEigensystem_getEigenvalue(t_IPartialEigensystem *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getEigenvalue(a0));
          return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getEigenvalue", arg);
        return NULL;
      }

      static PyObject *t_IPartialEigensystem_getLeftEigenvector(t_IPartialEigensystem *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::complex::IComplexArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getLeftEigenvector(a0));
          return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getLeftEigenvector", arg);
        return NULL;
      }

      static PyObject *t_IPartialEigensystem_getNumberOfAvailableEigenvectors(t_IPartialEigensystem *self)
      {
        jint result;
        OBJ_CALL(result = self->object.getNumberOfAvailableEigenvectors());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IPartialEigensystem_getRightEigenvector(t_IPartialEigensystem *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::complex::IComplexArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getRightEigenvector(a0));
          return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "getRightEigenvector", arg);
        return NULL;
      }

      static PyObject *t_IPartialEigensystem_get__numberOfAvailableEigenvectors(t_IPartialEigensystem *self, void *data)
      {
        jint value;
        OBJ_CALL(value = self->object.getNumberOfAvailableEigenvectors());
        return PyInt_FromLong((long) value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/ints/IntFactory.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/ints/IIntList.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace ints {

      ::java::lang::Class *IntFactory::class$ = NULL;
      jmethodID *IntFactory::mids$ = NULL;
      bool IntFactory::live$ = false;

      jclass IntFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/ints/IntFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_array_fcbe62e3] = env->getMethodID(cls, "array", "(Lstallone/api/ints/IIntArray;)Lstallone/api/ints/IIntArray;");
          mids$[mid_array_62213cdb] = env->getMethodID(cls, "array", "(I)Lstallone/api/ints/IIntArray;");
          mids$[mid_array_004e62f1] = env->getMethodID(cls, "array", "(II)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayFrom_e2b10697] = env->getMethodID(cls, "arrayFrom", "([I)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayFrom_62213cdb] = env->getMethodID(cls, "arrayFrom", "(I)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayFrom_df29d4b8] = env->getMethodID(cls, "arrayFrom", "([F)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayFrom_ed7b64a6] = env->getMethodID(cls, "arrayFrom", "([D)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayFrom_9b80c139] = env->getMethodID(cls, "arrayFrom", "(I[I)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayRandomIndexes_004e62f1] = env->getMethodID(cls, "arrayRandomIndexes", "(II)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayRange_62213cdb] = env->getMethodID(cls, "arrayRange", "(I)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayRange_004e62f1] = env->getMethodID(cls, "arrayRange", "(II)Lstallone/api/ints/IIntArray;");
          mids$[mid_arrayRange_03ba5ae3] = env->getMethodID(cls, "arrayRange", "(III)Lstallone/api/ints/IIntArray;");
          mids$[mid_like_3c84c841] = env->getMethodID(cls, "like", "(Lstallone/api/ints/IIntArray;I)Lstallone/api/ints/IIntArray;");
          mids$[mid_list_d218958f] = env->getMethodID(cls, "list", "(Lstallone/api/ints/IIntArray;)Lstallone/api/ints/IIntList;");
          mids$[mid_list_65bad777] = env->getMethodID(cls, "list", "(I)Lstallone/api/ints/IIntList;");
          mids$[mid_list_44a3774d] = env->getMethodID(cls, "list", "(II)Lstallone/api/ints/IIntList;");
          mids$[mid_listFrom_1615017e] = env->getMethodID(cls, "listFrom", "([F)Lstallone/api/ints/IIntList;");
          mids$[mid_listFrom_3d9702f3] = env->getMethodID(cls, "listFrom", "([I)Lstallone/api/ints/IIntList;");
          mids$[mid_listFrom_b772d97c] = env->getMethodID(cls, "listFrom", "([D)Lstallone/api/ints/IIntList;");
          mids$[mid_listFrom_65bad777] = env->getMethodID(cls, "listFrom", "(I)Lstallone/api/ints/IIntList;");
          mids$[mid_listFrom_8b467429] = env->getMethodID(cls, "listFrom", "(I[I)Lstallone/api/ints/IIntList;");
          mids$[mid_listRandomIndexes_44a3774d] = env->getMethodID(cls, "listRandomIndexes", "(II)Lstallone/api/ints/IIntList;");
          mids$[mid_listRange_65bad777] = env->getMethodID(cls, "listRange", "(I)Lstallone/api/ints/IIntList;");
          mids$[mid_listRange_44a3774d] = env->getMethodID(cls, "listRange", "(II)Lstallone/api/ints/IIntList;");
          mids$[mid_listRange_2f53b807] = env->getMethodID(cls, "listRange", "(III)Lstallone/api/ints/IIntList;");
          mids$[mid_table_004e62f1] = env->getMethodID(cls, "table", "(II)Lstallone/api/ints/IIntArray;");
          mids$[mid_table_03ba5ae3] = env->getMethodID(cls, "table", "(III)Lstallone/api/ints/IIntArray;");
          mids$[mid_tableFrom_d12b2044] = env->getMethodID(cls, "tableFrom", "([[F)Lstallone/api/ints/IIntArray;");
          mids$[mid_tableFrom_1cb5f11a] = env->getMethodID(cls, "tableFrom", "([[D)Lstallone/api/ints/IIntArray;");
          mids$[mid_tableReshape_236de56b] = env->getMethodID(cls, "tableReshape", "(Lstallone/api/ints/IIntArray;II)Lstallone/api/ints/IIntArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      IntFactory::IntFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::ints::IIntArray IntFactory::array(const ::stallone::api::ints::IIntArray & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_array_fcbe62e3], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::array(jint a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_array_62213cdb], a0));
      }

      ::stallone::api::ints::IIntArray IntFactory::array(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_array_004e62f1], a0, a1));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayFrom(const JArray< jint > & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayFrom_e2b10697], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayFrom(jint a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayFrom_62213cdb], a0));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayFrom(const JArray< jfloat > & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayFrom_df29d4b8], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayFrom(const JArray< jdouble > & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayFrom_ed7b64a6], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayFrom(jint a0, const JArray< jint > & a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayFrom_9b80c139], a0, a1.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayRandomIndexes(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayRandomIndexes_004e62f1], a0, a1));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayRange(jint a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayRange_62213cdb], a0));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayRange(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayRange_004e62f1], a0, a1));
      }

      ::stallone::api::ints::IIntArray IntFactory::arrayRange(jint a0, jint a1, jint a2) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_arrayRange_03ba5ae3], a0, a1, a2));
      }

      ::stallone::api::ints::IIntArray IntFactory::like(const ::stallone::api::ints::IIntArray & a0, jint a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_like_3c84c841], a0.this$, a1));
      }

      ::stallone::api::ints::IIntList IntFactory::list(const ::stallone::api::ints::IIntArray & a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_list_d218958f], a0.this$));
      }

      ::stallone::api::ints::IIntList IntFactory::list(jint a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_list_65bad777], a0));
      }

      ::stallone::api::ints::IIntList IntFactory::list(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_list_44a3774d], a0, a1));
      }

      ::stallone::api::ints::IIntList IntFactory::listFrom(const JArray< jfloat > & a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listFrom_1615017e], a0.this$));
      }

      ::stallone::api::ints::IIntList IntFactory::listFrom(const JArray< jint > & a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listFrom_3d9702f3], a0.this$));
      }

      ::stallone::api::ints::IIntList IntFactory::listFrom(const JArray< jdouble > & a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listFrom_b772d97c], a0.this$));
      }

      ::stallone::api::ints::IIntList IntFactory::listFrom(jint a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listFrom_65bad777], a0));
      }

      ::stallone::api::ints::IIntList IntFactory::listFrom(jint a0, const JArray< jint > & a1) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listFrom_8b467429], a0, a1.this$));
      }

      ::stallone::api::ints::IIntList IntFactory::listRandomIndexes(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listRandomIndexes_44a3774d], a0, a1));
      }

      ::stallone::api::ints::IIntList IntFactory::listRange(jint a0) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listRange_65bad777], a0));
      }

      ::stallone::api::ints::IIntList IntFactory::listRange(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listRange_44a3774d], a0, a1));
      }

      ::stallone::api::ints::IIntList IntFactory::listRange(jint a0, jint a1, jint a2) const
      {
        return ::stallone::api::ints::IIntList(env->callObjectMethod(this$, mids$[mid_listRange_2f53b807], a0, a1, a2));
      }

      ::stallone::api::ints::IIntArray IntFactory::table(jint a0, jint a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_table_004e62f1], a0, a1));
      }

      ::stallone::api::ints::IIntArray IntFactory::table(jint a0, jint a1, jint a2) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_table_03ba5ae3], a0, a1, a2));
      }

      ::stallone::api::ints::IIntArray IntFactory::tableFrom(const JArray< JArray< jfloat > > & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_tableFrom_d12b2044], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::tableFrom(const JArray< JArray< jdouble > > & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_tableFrom_1cb5f11a], a0.this$));
      }

      ::stallone::api::ints::IIntArray IntFactory::tableReshape(const ::stallone::api::ints::IIntArray & a0, jint a1, jint a2) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_tableReshape_236de56b], a0.this$, a1, a2));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace ints {
      static PyObject *t_IntFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IntFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_IntFactory_init_(t_IntFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_IntFactory_array(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_arrayFrom(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_arrayRandomIndexes(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_arrayRange(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_like(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_list(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_listFrom(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_listRandomIndexes(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_listRange(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_table(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_tableFrom(t_IntFactory *self, PyObject *args);
      static PyObject *t_IntFactory_tableReshape(t_IntFactory *self, PyObject *args);

      static PyMethodDef t_IntFactory__methods_[] = {
        DECLARE_METHOD(t_IntFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntFactory, array, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, arrayFrom, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, arrayRandomIndexes, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, arrayRange, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, like, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, list, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, listFrom, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, listRandomIndexes, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, listRange, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, table, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, tableFrom, METH_VARARGS),
        DECLARE_METHOD(t_IntFactory, tableReshape, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IntFactory, t_IntFactory, ::java::lang::Object, IntFactory, t_IntFactory_init_, 0, 0, 0, 0, 0);

      void t_IntFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(IntFactory), module, "IntFactory", 0);
      }

      void t_IntFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IntFactory).tp_dict, "class_", make_descriptor(IntFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IntFactory).tp_dict, "wrapfn_", make_descriptor(t_IntFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IntFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IntFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IntFactory::initializeClass, 1)))
          return NULL;
        return t_IntFactory::wrap_Object(IntFactory(((t_IntFactory *) arg)->object.this$));
      }
      static PyObject *t_IntFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IntFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_IntFactory_init_(t_IntFactory *self, PyObject *args, PyObject *kwds)
      {
        IntFactory object((jobject) NULL);

        INT_CALL(object = IntFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_IntFactory_array(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::ints::IIntArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.array(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          {
            jint a0;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.array(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.array(a0, a1));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "array", args);
        return NULL;
      }

      static PyObject *t_IntFactory_arrayFrom(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< jint > a0((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "[I", &a0))
            {
              OBJ_CALL(result = self->object.arrayFrom(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          {
            jint a0;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.arrayFrom(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          {
            JArray< jfloat > a0((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "[F", &a0))
            {
              OBJ_CALL(result = self->object.arrayFrom(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          {
            JArray< jdouble > a0((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "[D", &a0))
            {
              OBJ_CALL(result = self->object.arrayFrom(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            JArray< jint > a1((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "I[I", &a0, &a1))
            {
              OBJ_CALL(result = self->object.arrayFrom(a0, a1));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "arrayFrom", args);
        return NULL;
      }

      static PyObject *t_IntFactory_arrayRandomIndexes(t_IntFactory *self, PyObject *args)
      {
        jint a0;
        jint a1;
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArgs(args, "II", &a0, &a1))
        {
          OBJ_CALL(result = self->object.arrayRandomIndexes(a0, a1));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "arrayRandomIndexes", args);
        return NULL;
      }

      static PyObject *t_IntFactory_arrayRange(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.arrayRange(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.arrayRange(a0, a1));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            jint a0;
            jint a1;
            jint a2;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "III", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.arrayRange(a0, a1, a2));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "arrayRange", args);
        return NULL;
      }

      static PyObject *t_IntFactory_like(t_IntFactory *self, PyObject *args)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);
        jint a1;
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArgs(args, "kI", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.like(a0, a1));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "like", args);
        return NULL;
      }

      static PyObject *t_IntFactory_list(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::ints::IIntArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.list(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          {
            jint a0;
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.list(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.list(a0, a1));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "list", args);
        return NULL;
      }

      static PyObject *t_IntFactory_listFrom(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< jfloat > a0((jobject) NULL);
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "[F", &a0))
            {
              OBJ_CALL(result = self->object.listFrom(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          {
            JArray< jint > a0((jobject) NULL);
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "[I", &a0))
            {
              OBJ_CALL(result = self->object.listFrom(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          {
            JArray< jdouble > a0((jobject) NULL);
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "[D", &a0))
            {
              OBJ_CALL(result = self->object.listFrom(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          {
            jint a0;
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.listFrom(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            JArray< jint > a1((jobject) NULL);
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "I[I", &a0, &a1))
            {
              OBJ_CALL(result = self->object.listFrom(a0, a1));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "listFrom", args);
        return NULL;
      }

      static PyObject *t_IntFactory_listRandomIndexes(t_IntFactory *self, PyObject *args)
      {
        jint a0;
        jint a1;
        ::stallone::api::ints::IIntList result((jobject) NULL);

        if (!parseArgs(args, "II", &a0, &a1))
        {
          OBJ_CALL(result = self->object.listRandomIndexes(a0, a1));
          return ::stallone::api::ints::t_IIntList::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "listRandomIndexes", args);
        return NULL;
      }

      static PyObject *t_IntFactory_listRange(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.listRange(a0));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.listRange(a0, a1));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            jint a0;
            jint a1;
            jint a2;
            ::stallone::api::ints::IIntList result((jobject) NULL);

            if (!parseArgs(args, "III", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.listRange(a0, a1, a2));
              return ::stallone::api::ints::t_IIntList::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "listRange", args);
        return NULL;
      }

      static PyObject *t_IntFactory_table(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jint a0;
            jint a1;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.table(a0, a1));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            jint a0;
            jint a1;
            jint a2;
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "III", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.table(a0, a1, a2));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "table", args);
        return NULL;
      }

      static PyObject *t_IntFactory_tableFrom(t_IntFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< JArray< jfloat > > a0((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "[[F", &a0))
            {
              OBJ_CALL(result = self->object.tableFrom(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
          {
            JArray< JArray< jdouble > > a0((jobject) NULL);
            ::stallone::api::ints::IIntArray result((jobject) NULL);

            if (!parseArgs(args, "[[D", &a0))
            {
              OBJ_CALL(result = self->object.tableFrom(a0));
              return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "tableFrom", args);
        return NULL;
      }

      static PyObject *t_IntFactory_tableReshape(t_IntFactory *self, PyObject *args)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);
        jint a1;
        jint a2;
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArgs(args, "kII", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.tableReshape(a0, a1, a2));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "tableReshape", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/ints/IntsPrimitive.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace ints {

      ::java::lang::Class *IntsPrimitive::class$ = NULL;
      jmethodID *IntsPrimitive::mids$ = NULL;
      bool IntsPrimitive::live$ = false;

      jclass IntsPrimitive::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/ints/IntsPrimitive");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      IntsPrimitive::IntsPrimitive() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace ints {
      static PyObject *t_IntsPrimitive_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IntsPrimitive_instance_(PyTypeObject *type, PyObject *arg);
      static int t_IntsPrimitive_init_(t_IntsPrimitive *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_IntsPrimitive__methods_[] = {
        DECLARE_METHOD(t_IntsPrimitive, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntsPrimitive, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IntsPrimitive, t_IntsPrimitive, ::java::lang::Object, IntsPrimitive, t_IntsPrimitive_init_, 0, 0, 0, 0, 0);

      void t_IntsPrimitive::install(PyObject *module)
      {
        installType(&PY_TYPE(IntsPrimitive), module, "IntsPrimitive", 0);
      }

      void t_IntsPrimitive::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IntsPrimitive).tp_dict, "class_", make_descriptor(IntsPrimitive::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IntsPrimitive).tp_dict, "wrapfn_", make_descriptor(t_IntsPrimitive::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IntsPrimitive).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IntsPrimitive_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IntsPrimitive::initializeClass, 1)))
          return NULL;
        return t_IntsPrimitive::wrap_Object(IntsPrimitive(((t_IntsPrimitive *) arg)->object.this$));
      }
      static PyObject *t_IntsPrimitive_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IntsPrimitive::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_IntsPrimitive_init_(t_IntsPrimitive *self, PyObject *args, PyObject *kwds)
      {
        IntsPrimitive object((jobject) NULL);

        INT_CALL(object = IntsPrimitive());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/doubles/IMetric.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace doubles {

      ::java::lang::Class *IMetric::class$ = NULL;
      jmethodID *IMetric::mids$ = NULL;
      bool IMetric::live$ = false;

      jclass IMetric::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/doubles/IMetric");

          mids$ = new jmethodID[max_mid];
          mids$[mid_distance_608d4898] = env->getMethodID(cls, "distance", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)D");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jdouble IMetric::distance(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_distance_608d4898], a0.this$, a1.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace doubles {
      static PyObject *t_IMetric_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IMetric_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IMetric_of_(t_IMetric *self, PyObject *args);
      static PyObject *t_IMetric_distance(t_IMetric *self, PyObject *args);
      static PyObject *t_IMetric_get__parameters_(t_IMetric *self, void *data);
      static PyGetSetDef t_IMetric__fields_[] = {
        DECLARE_GET_FIELD(t_IMetric, parameters_),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IMetric__methods_[] = {
        DECLARE_METHOD(t_IMetric, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IMetric, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IMetric, of_, METH_VARARGS),
        DECLARE_METHOD(t_IMetric, distance, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IMetric, t_IMetric, ::java::lang::Object, IMetric, abstract_init, 0, 0, t_IMetric__fields_, 0, 0);
      PyObject *t_IMetric::wrap_Object(const IMetric& object, PyTypeObject *T)
      {
        PyObject *obj = t_IMetric::wrap_Object(object);
        if (obj != NULL && obj != Py_None)
        {
          t_IMetric *self = (t_IMetric *) obj;
          self->parameters[0] = T;
        }
        return obj;
      }

      PyObject *t_IMetric::wrap_jobject(const jobject& object, PyTypeObject *T)
      {
        PyObject *obj = t_IMetric::wrap_jobject(object);
        if (obj != NULL && obj != Py_None)
        {
          t_IMetric *self = (t_IMetric *) obj;
          self->parameters[0] = T;
        }
        return obj;
      }

      void t_IMetric::install(PyObject *module)
      {
        installType(&PY_TYPE(IMetric), module, "IMetric", 0);
      }

      void t_IMetric::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IMetric).tp_dict, "class_", make_descriptor(IMetric::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IMetric).tp_dict, "wrapfn_", make_descriptor(t_IMetric::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IMetric).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IMetric_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IMetric::initializeClass, 1)))
          return NULL;
        return t_IMetric::wrap_Object(IMetric(((t_IMetric *) arg)->object.this$));
      }
      static PyObject *t_IMetric_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IMetric::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IMetric_of_(t_IMetric *self, PyObject *args)
      {
        if (!parseArg(args, "T", 1, &(self->parameters)))
          Py_RETURN_SELF;
        return PyErr_SetArgsError((PyObject *) self, "of_", args);
      }

      static PyObject *t_IMetric_distance(t_IMetric *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        jdouble result;

        if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.distance(a0, a1));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "distance", args);
        return NULL;
      }
      static PyObject *t_IMetric_get__parameters_(t_IMetric *self, void *data)
      {
        return typeParameters(self->parameters, sizeof(self->parameters));
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/potential/PotentialUtilities.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace potential {

      ::java::lang::Class *PotentialUtilities::class$ = NULL;
      jmethodID *PotentialUtilities::mids$ = NULL;
      bool PotentialUtilities::live$ = false;

      jclass PotentialUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/potential/PotentialUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      PotentialUtilities::PotentialUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace potential {
      static PyObject *t_PotentialUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_PotentialUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_PotentialUtilities_init_(t_PotentialUtilities *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_PotentialUtilities__methods_[] = {
        DECLARE_METHOD(t_PotentialUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_PotentialUtilities, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(PotentialUtilities, t_PotentialUtilities, ::java::lang::Object, PotentialUtilities, t_PotentialUtilities_init_, 0, 0, 0, 0, 0);

      void t_PotentialUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(PotentialUtilities), module, "PotentialUtilities", 0);
      }

      void t_PotentialUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(PotentialUtilities).tp_dict, "class_", make_descriptor(PotentialUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(PotentialUtilities).tp_dict, "wrapfn_", make_descriptor(t_PotentialUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(PotentialUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_PotentialUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, PotentialUtilities::initializeClass, 1)))
          return NULL;
        return t_PotentialUtilities::wrap_Object(PotentialUtilities(((t_PotentialUtilities *) arg)->object.this$));
      }
      static PyObject *t_PotentialUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, PotentialUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_PotentialUtilities_init_(t_PotentialUtilities *self, PyObject *args, PyObject *kwds)
      {
        PotentialUtilities object((jobject) NULL);

        INT_CALL(object = PotentialUtilities());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/complex/ComplexFactory.h"
#include "stallone/api/complex/IComplexArray.h"
#include "stallone/api/algebra/IComplexNumber.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace complex {

      ::java::lang::Class *ComplexFactory::class$ = NULL;
      jmethodID *ComplexFactory::mids$ = NULL;
      bool ComplexFactory::live$ = false;

      jclass ComplexFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/complex/ComplexFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_array_618dde96] = env->getMethodID(cls, "array", "([[Lstallone/api/algebra/IComplexNumber;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_array_f6210079] = env->getMethodID(cls, "array", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_array_fba5fcc9] = env->getMethodID(cls, "array", "([[D[[D)Lstallone/api/complex/IComplexArray;");
          mids$[mid_array_74a6154f] = env->getMethodID(cls, "array", "(II)Lstallone/api/complex/IComplexArray;");
          mids$[mid_column_f6210079] = env->getMethodID(cls, "column", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_column_777b15cf] = env->getMethodID(cls, "column", "([D[D)Lstallone/api/complex/IComplexArray;");
          mids$[mid_complexScalar_8803cf94] = env->getMethodID(cls, "complexScalar", "()Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_complexScalar_0acceaa2] = env->getMethodID(cls, "complexScalar", "(DD)Lstallone/api/algebra/IComplexNumber;");
          mids$[mid_diag_338c567a] = env->getMethodID(cls, "diag", "([D)Lstallone/api/complex/IComplexArray;");
          mids$[mid_diag_2e81309f] = env->getMethodID(cls, "diag", "(Lstallone/api/complex/IComplexArray;)Lstallone/api/complex/IComplexArray;");
          mids$[mid_diag_df6a3e1c] = env->getMethodID(cls, "diag", "(ID)Lstallone/api/complex/IComplexArray;");
          mids$[mid_identity_f6210079] = env->getMethodID(cls, "identity", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_row_f6210079] = env->getMethodID(cls, "row", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_row_777b15cf] = env->getMethodID(cls, "row", "([D[D)Lstallone/api/complex/IComplexArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ComplexFactory::ComplexFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::complex::IComplexArray ComplexFactory::array(const JArray< JArray< ::stallone::api::algebra::IComplexNumber > > & a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_array_618dde96], a0.this$));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::array(jint a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_array_f6210079], a0));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::array(const JArray< JArray< jdouble > > & a0, const JArray< JArray< jdouble > > & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_array_fba5fcc9], a0.this$, a1.this$));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::array(jint a0, jint a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_array_74a6154f], a0, a1));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::column(jint a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_column_f6210079], a0));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::column(const JArray< jdouble > & a0, const JArray< jdouble > & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_column_777b15cf], a0.this$, a1.this$));
      }

      ::stallone::api::algebra::IComplexNumber ComplexFactory::complexScalar() const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_complexScalar_8803cf94]));
      }

      ::stallone::api::algebra::IComplexNumber ComplexFactory::complexScalar(jdouble a0, jdouble a1) const
      {
        return ::stallone::api::algebra::IComplexNumber(env->callObjectMethod(this$, mids$[mid_complexScalar_0acceaa2], a0, a1));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::diag(const JArray< jdouble > & a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_diag_338c567a], a0.this$));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::diag(const ::stallone::api::complex::IComplexArray & a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_diag_2e81309f], a0.this$));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::diag(jint a0, jdouble a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_diag_df6a3e1c], a0, a1));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::identity(jint a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_identity_f6210079], a0));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::row(jint a0) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_row_f6210079], a0));
      }

      ::stallone::api::complex::IComplexArray ComplexFactory::row(const JArray< jdouble > & a0, const JArray< jdouble > & a1) const
      {
        return ::stallone::api::complex::IComplexArray(env->callObjectMethod(this$, mids$[mid_row_777b15cf], a0.this$, a1.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace complex {
      static PyObject *t_ComplexFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ComplexFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_ComplexFactory_init_(t_ComplexFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_ComplexFactory_array(t_ComplexFactory *self, PyObject *args);
      static PyObject *t_ComplexFactory_column(t_ComplexFactory *self, PyObject *args);
      static PyObject *t_ComplexFactory_complexScalar(t_ComplexFactory *self, PyObject *args);
      static PyObject *t_ComplexFactory_diag(t_ComplexFactory *self, PyObject *args);
      static PyObject *t_ComplexFactory_identity(t_ComplexFactory *self, PyObject *arg);
      static PyObject *t_ComplexFactory_row(t_ComplexFactory *self, PyObject *args);

      static PyMethodDef t_ComplexFactory__methods_[] = {
        DECLARE_METHOD(t_ComplexFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ComplexFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ComplexFactory, array, METH_VARARGS),
        DECLARE_METHOD(t_ComplexFactory, column, METH_VARARGS),
        DECLARE_METHOD(t_ComplexFactory, complexScalar, METH_VARARGS),
        DECLARE_METHOD(t_ComplexFactory, diag, METH_VARARGS),
        DECLARE_METHOD(t_ComplexFactory, identity, METH_O),
        DECLARE_METHOD(t_ComplexFactory, row, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(ComplexFactory, t_ComplexFactory, ::java::lang::Object, ComplexFactory, t_ComplexFactory_init_, 0, 0, 0, 0, 0);

      void t_ComplexFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(ComplexFactory), module, "ComplexFactory", 0);
      }

      void t_ComplexFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(ComplexFactory).tp_dict, "class_", make_descriptor(ComplexFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ComplexFactory).tp_dict, "wrapfn_", make_descriptor(t_ComplexFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ComplexFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_ComplexFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, ComplexFactory::initializeClass, 1)))
          return NULL;
        return t_ComplexFactory::wrap_Object(ComplexFactory(((t_ComplexFactory *) arg)->object.this$));
      }
      static PyObject *t_ComplexFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, ComplexFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_ComplexFactory_init_(t_ComplexFactory *self, PyObject *args, PyObject *kwds)
      {
        ComplexFactory object((jobject) NULL);

        INT_CALL(object = ComplexFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_ComplexFactory_array(t_ComplexFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< JArray< ::stallone::api::algebra::IComplexNumber > > a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "[[k", ::stallone::api::algebra::IComplexNumber::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.array(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            jint a0;
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.array(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            JArray< JArray< jdouble > > a0((jobject) NULL);
            JArray< JArray< jdouble > > a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "[[D[[D", &a0, &a1))
            {
              OBJ_CALL(result = self->object.array(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            jint a0;
            jint a1;
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.array(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "array", args);
        return NULL;
      }

      static PyObject *t_ComplexFactory_column(t_ComplexFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.column(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            JArray< jdouble > a0((jobject) NULL);
            JArray< jdouble > a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "[D[D", &a0, &a1))
            {
              OBJ_CALL(result = self->object.column(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "column", args);
        return NULL;
      }

      static PyObject *t_ComplexFactory_complexScalar(t_ComplexFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 0:
          {
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);
            OBJ_CALL(result = self->object.complexScalar());
            return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
          }
          break;
         case 2:
          {
            jdouble a0;
            jdouble a1;
            ::stallone::api::algebra::IComplexNumber result((jobject) NULL);

            if (!parseArgs(args, "DD", &a0, &a1))
            {
              OBJ_CALL(result = self->object.complexScalar(a0, a1));
              return ::stallone::api::algebra::t_IComplexNumber::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "complexScalar", args);
        return NULL;
      }

      static PyObject *t_ComplexFactory_diag(t_ComplexFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            JArray< jdouble > a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "[D", &a0))
            {
              OBJ_CALL(result = self->object.diag(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::complex::IComplexArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.diag(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jdouble a1;
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "ID", &a0, &a1))
            {
              OBJ_CALL(result = self->object.diag(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "diag", args);
        return NULL;
      }

      static PyObject *t_ComplexFactory_identity(t_ComplexFactory *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::complex::IComplexArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.identity(a0));
          return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "identity", arg);
        return NULL;
      }

      static PyObject *t_ComplexFactory_row(t_ComplexFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.row(a0));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            JArray< jdouble > a0((jobject) NULL);
            JArray< jdouble > a1((jobject) NULL);
            ::stallone::api::complex::IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "[D[D", &a0, &a1))
            {
              OBJ_CALL(result = self->object.row(a0, a1));
              return ::stallone::api::complex::t_IComplexArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "row", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/dynamics/IIntegratorThermostatted.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace dynamics {

    ::java::lang::Class *IIntegratorThermostatted::class$ = NULL;
    jmethodID *IIntegratorThermostatted::mids$ = NULL;
    bool IIntegratorThermostatted::live$ = false;

    jclass IIntegratorThermostatted::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("stallone/dynamics/IIntegratorThermostatted");

        mids$ = new jmethodID[max_mid];
        mids$[mid_setkT_5d1c7645] = env->getMethodID(cls, "setkT", "(D)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    void IIntegratorThermostatted::setkT(jdouble a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setkT_5d1c7645], a0);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace dynamics {
    static PyObject *t_IIntegratorThermostatted_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_IIntegratorThermostatted_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_IIntegratorThermostatted_setkT(t_IIntegratorThermostatted *self, PyObject *arg);
    static int t_IIntegratorThermostatted_set__kT(t_IIntegratorThermostatted *self, PyObject *arg, void *data);
    static PyGetSetDef t_IIntegratorThermostatted__fields_[] = {
      DECLARE_SET_FIELD(t_IIntegratorThermostatted, kT),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_IIntegratorThermostatted__methods_[] = {
      DECLARE_METHOD(t_IIntegratorThermostatted, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_IIntegratorThermostatted, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_IIntegratorThermostatted, setkT, METH_O),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(IIntegratorThermostatted, t_IIntegratorThermostatted, ::stallone::dynamics::IIntegrator, IIntegratorThermostatted, abstract_init, 0, 0, t_IIntegratorThermostatted__fields_, 0, 0);

    void t_IIntegratorThermostatted::install(PyObject *module)
    {
      installType(&PY_TYPE(IIntegratorThermostatted), module, "IIntegratorThermostatted", 0);
    }

    void t_IIntegratorThermostatted::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(IIntegratorThermostatted).tp_dict, "class_", make_descriptor(IIntegratorThermostatted::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(IIntegratorThermostatted).tp_dict, "wrapfn_", make_descriptor(t_IIntegratorThermostatted::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(IIntegratorThermostatted).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_IIntegratorThermostatted_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, IIntegratorThermostatted::initializeClass, 1)))
        return NULL;
      return t_IIntegratorThermostatted::wrap_Object(IIntegratorThermostatted(((t_IIntegratorThermostatted *) arg)->object.this$));
    }
    static PyObject *t_IIntegratorThermostatted_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, IIntegratorThermostatted::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_IIntegratorThermostatted_setkT(t_IIntegratorThermostatted *self, PyObject *arg)
    {
      jdouble a0;

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(self->object.setkT(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setkT", arg);
      return NULL;
    }

    static int t_IIntegratorThermostatted_set__kT(t_IIntegratorThermostatted *self, PyObject *arg, void *data)
    {
      {
        jdouble value;
        if (!parseArg(arg, "D", &value))
        {
          INT_CALL(self->object.setkT(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "kT", arg);
      return -1;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/stat/IDiscreteDistribution.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace stat {

      ::java::lang::Class *IDiscreteDistribution::class$ = NULL;
      jmethodID *IDiscreteDistribution::mids$ = NULL;
      bool IDiscreteDistribution::live$ = false;

      jclass IDiscreteDistribution::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/stat/IDiscreteDistribution");

          mids$ = new jmethodID[max_mid];
          mids$[mid_sample_54c6a179] = env->getMethodID(cls, "sample", "()I");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jint IDiscreteDistribution::sample() const
      {
        return env->callIntMethod(this$, mids$[mid_sample_54c6a179]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace stat {
      static PyObject *t_IDiscreteDistribution_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDiscreteDistribution_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDiscreteDistribution_sample(t_IDiscreteDistribution *self);

      static PyMethodDef t_IDiscreteDistribution__methods_[] = {
        DECLARE_METHOD(t_IDiscreteDistribution, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDiscreteDistribution, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDiscreteDistribution, sample, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDiscreteDistribution, t_IDiscreteDistribution, ::java::lang::Object, IDiscreteDistribution, abstract_init, 0, 0, 0, 0, 0);

      void t_IDiscreteDistribution::install(PyObject *module)
      {
        installType(&PY_TYPE(IDiscreteDistribution), module, "IDiscreteDistribution", 0);
      }

      void t_IDiscreteDistribution::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDiscreteDistribution).tp_dict, "class_", make_descriptor(IDiscreteDistribution::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDiscreteDistribution).tp_dict, "wrapfn_", make_descriptor(t_IDiscreteDistribution::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDiscreteDistribution).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDiscreteDistribution_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDiscreteDistribution::initializeClass, 1)))
          return NULL;
        return t_IDiscreteDistribution::wrap_Object(IDiscreteDistribution(((t_IDiscreteDistribution *) arg)->object.this$));
      }
      static PyObject *t_IDiscreteDistribution_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDiscreteDistribution::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDiscreteDistribution_sample(t_IDiscreteDistribution *self)
      {
        jint result;
        OBJ_CALL(result = self->object.sample());
        return PyInt_FromLong((long) result);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/hmm/HMMUtilities.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace hmm {

      ::java::lang::Class *HMMUtilities::class$ = NULL;
      jmethodID *HMMUtilities::mids$ = NULL;
      bool HMMUtilities::live$ = false;

      jclass HMMUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/hmm/HMMUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      HMMUtilities::HMMUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace hmm {
      static PyObject *t_HMMUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_HMMUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_HMMUtilities_init_(t_HMMUtilities *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_HMMUtilities__methods_[] = {
        DECLARE_METHOD(t_HMMUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_HMMUtilities, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(HMMUtilities, t_HMMUtilities, ::java::lang::Object, HMMUtilities, t_HMMUtilities_init_, 0, 0, 0, 0, 0);

      void t_HMMUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(HMMUtilities), module, "HMMUtilities", 0);
      }

      void t_HMMUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(HMMUtilities).tp_dict, "class_", make_descriptor(HMMUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(HMMUtilities).tp_dict, "wrapfn_", make_descriptor(t_HMMUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(HMMUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_HMMUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, HMMUtilities::initializeClass, 1)))
          return NULL;
        return t_HMMUtilities::wrap_Object(HMMUtilities(((t_HMMUtilities *) arg)->object.this$));
      }
      static PyObject *t_HMMUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, HMMUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_HMMUtilities_init_(t_HMMUtilities *self, PyObject *args, PyObject *kwds)
      {
        HMMUtilities object((jobject) NULL);

        INT_CALL(object = HMMUtilities());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/complex/Complex.h"
#include "stallone/api/complex/ComplexUtilities.h"
#include "stallone/api/complex/ComplexFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace complex {

      ::java::lang::Class *Complex::class$ = NULL;
      jmethodID *Complex::mids$ = NULL;
      bool Complex::live$ = false;
      ::stallone::api::complex::ComplexFactory *Complex::create = NULL;
      ::stallone::api::complex::ComplexUtilities *Complex::util = NULL;

      jclass Complex::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/complex/Complex");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::complex::ComplexFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/complex/ComplexFactory;"));
          util = new ::stallone::api::complex::ComplexUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/complex/ComplexUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      Complex::Complex() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace complex {
      static PyObject *t_Complex_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_Complex_instance_(PyTypeObject *type, PyObject *arg);
      static int t_Complex_init_(t_Complex *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_Complex__methods_[] = {
        DECLARE_METHOD(t_Complex, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Complex, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(Complex, t_Complex, ::java::lang::Object, Complex, t_Complex_init_, 0, 0, 0, 0, 0);

      void t_Complex::install(PyObject *module)
      {
        installType(&PY_TYPE(Complex), module, "Complex", 0);
      }

      void t_Complex::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(Complex).tp_dict, "class_", make_descriptor(Complex::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Complex).tp_dict, "wrapfn_", make_descriptor(t_Complex::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Complex).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(Complex::initializeClass);
        PyDict_SetItemString(PY_TYPE(Complex).tp_dict, "create", make_descriptor(::stallone::api::complex::t_ComplexFactory::wrap_Object(*Complex::create)));
        PyDict_SetItemString(PY_TYPE(Complex).tp_dict, "util", make_descriptor(::stallone::api::complex::t_ComplexUtilities::wrap_Object(*Complex::util)));
      }

      static PyObject *t_Complex_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, Complex::initializeClass, 1)))
          return NULL;
        return t_Complex::wrap_Object(Complex(((t_Complex *) arg)->object.this$));
      }
      static PyObject *t_Complex_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, Complex::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_Complex_init_(t_Complex *self, PyObject *args, PyObject *kwds)
      {
        Complex object((jobject) NULL);

        INT_CALL(object = Complex());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/intsequence/IntSequenceFactory.h"
#include "stallone/api/intsequence/IIntWriter.h"
#include "stallone/api/intsequence/IIntSequenceLoader.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace intsequence {

      ::java::lang::Class *IntSequenceFactory::class$ = NULL;
      jmethodID *IntSequenceFactory::mids$ = NULL;
      bool IntSequenceFactory::live$ = false;

      jclass IntSequenceFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/intsequence/IntSequenceFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_intSequenceWriter_244dd0ed] = env->getMethodID(cls, "intSequenceWriter", "(Ljava/lang/String;)Lstallone/api/intsequence/IIntWriter;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      IntSequenceFactory::IntSequenceFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::intsequence::IIntWriter IntSequenceFactory::intSequenceWriter(const ::java::lang::String & a0) const
      {
        return ::stallone::api::intsequence::IIntWriter(env->callObjectMethod(this$, mids$[mid_intSequenceWriter_244dd0ed], a0.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace intsequence {
      static PyObject *t_IntSequenceFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IntSequenceFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_IntSequenceFactory_init_(t_IntSequenceFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_IntSequenceFactory_intSequenceWriter(t_IntSequenceFactory *self, PyObject *arg);

      static PyMethodDef t_IntSequenceFactory__methods_[] = {
        DECLARE_METHOD(t_IntSequenceFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntSequenceFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IntSequenceFactory, intSequenceWriter, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IntSequenceFactory, t_IntSequenceFactory, ::java::lang::Object, IntSequenceFactory, t_IntSequenceFactory_init_, 0, 0, 0, 0, 0);

      void t_IntSequenceFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(IntSequenceFactory), module, "IntSequenceFactory", 0);
      }

      void t_IntSequenceFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IntSequenceFactory).tp_dict, "class_", make_descriptor(IntSequenceFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IntSequenceFactory).tp_dict, "wrapfn_", make_descriptor(t_IntSequenceFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IntSequenceFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IntSequenceFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IntSequenceFactory::initializeClass, 1)))
          return NULL;
        return t_IntSequenceFactory::wrap_Object(IntSequenceFactory(((t_IntSequenceFactory *) arg)->object.this$));
      }
      static PyObject *t_IntSequenceFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IntSequenceFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_IntSequenceFactory_init_(t_IntSequenceFactory *self, PyObject *args, PyObject *kwds)
      {
        IntSequenceFactory object((jobject) NULL);

        INT_CALL(object = IntSequenceFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_IntSequenceFactory_intSequenceWriter(t_IntSequenceFactory *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::stallone::api::intsequence::IIntWriter result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.intSequenceWriter(a0));
          return ::stallone::api::intsequence::t_IIntWriter::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "intSequenceWriter", arg);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/graph/IGraph.h"
#include "stallone/api/graph/IEdge.h"
#include "java/util/Iterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace graph {

      ::java::lang::Class *IGraph::class$ = NULL;
      jmethodID *IGraph::mids$ = NULL;
      bool IGraph::live$ = false;

      jclass IGraph::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/graph/IGraph");

          mids$ = new jmethodID[max_mid];
          mids$[mid_contains_290588e2] = env->getMethodID(cls, "contains", "(Ljava/lang/Object;)Z");
          mids$[mid_contains_ee8d062c] = env->getMethodID(cls, "contains", "(Lstallone/api/graph/IEdge;)Z");
          mids$[mid_edgeIterator_40858c90] = env->getMethodID(cls, "edgeIterator", "()Ljava/util/Iterator;");
          mids$[mid_neighborIterator_a04f5304] = env->getMethodID(cls, "neighborIterator", "(Ljava/lang/Object;)Ljava/util/Iterator;");
          mids$[mid_nodeIterator_40858c90] = env->getMethodID(cls, "nodeIterator", "()Ljava/util/Iterator;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jboolean IGraph::contains(const ::java::lang::Object & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_contains_290588e2], a0.this$);
      }

      jboolean IGraph::contains(const ::stallone::api::graph::IEdge & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_contains_ee8d062c], a0.this$);
      }

      ::java::util::Iterator IGraph::edgeIterator() const
      {
        return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_edgeIterator_40858c90]));
      }

      ::java::util::Iterator IGraph::neighborIterator(const ::java::lang::Object & a0) const
      {
        return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_neighborIterator_a04f5304], a0.this$));
      }

      ::java::util::Iterator IGraph::nodeIterator() const
      {
        return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_nodeIterator_40858c90]));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace graph {
      static PyObject *t_IGraph_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IGraph_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IGraph_of_(t_IGraph *self, PyObject *args);
      static PyObject *t_IGraph_contains(t_IGraph *self, PyObject *args);
      static PyObject *t_IGraph_edgeIterator(t_IGraph *self);
      static PyObject *t_IGraph_neighborIterator(t_IGraph *self, PyObject *arg);
      static PyObject *t_IGraph_nodeIterator(t_IGraph *self);
      static PyObject *t_IGraph_get__parameters_(t_IGraph *self, void *data);
      static PyGetSetDef t_IGraph__fields_[] = {
        DECLARE_GET_FIELD(t_IGraph, parameters_),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IGraph__methods_[] = {
        DECLARE_METHOD(t_IGraph, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IGraph, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IGraph, of_, METH_VARARGS),
        DECLARE_METHOD(t_IGraph, contains, METH_VARARGS),
        DECLARE_METHOD(t_IGraph, edgeIterator, METH_NOARGS),
        DECLARE_METHOD(t_IGraph, neighborIterator, METH_O),
        DECLARE_METHOD(t_IGraph, nodeIterator, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IGraph, t_IGraph, ::java::lang::Object, IGraph, abstract_init, 0, 0, t_IGraph__fields_, 0, 0);
      PyObject *t_IGraph::wrap_Object(const IGraph& object, PyTypeObject *NodeType, PyTypeObject *EdgeType)
      {
        PyObject *obj = t_IGraph::wrap_Object(object);
        if (obj != NULL && obj != Py_None)
        {
          t_IGraph *self = (t_IGraph *) obj;
          self->parameters[0] = NodeType;
          self->parameters[1] = EdgeType;
        }
        return obj;
      }

      PyObject *t_IGraph::wrap_jobject(const jobject& object, PyTypeObject *NodeType, PyTypeObject *EdgeType)
      {
        PyObject *obj = t_IGraph::wrap_jobject(object);
        if (obj != NULL && obj != Py_None)
        {
          t_IGraph *self = (t_IGraph *) obj;
          self->parameters[0] = NodeType;
          self->parameters[1] = EdgeType;
        }
        return obj;
      }

      void t_IGraph::install(PyObject *module)
      {
        installType(&PY_TYPE(IGraph), module, "IGraph", 0);
      }

      void t_IGraph::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IGraph).tp_dict, "class_", make_descriptor(IGraph::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IGraph).tp_dict, "wrapfn_", make_descriptor(t_IGraph::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IGraph).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IGraph_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IGraph::initializeClass, 1)))
          return NULL;
        return t_IGraph::wrap_Object(IGraph(((t_IGraph *) arg)->object.this$));
      }
      static PyObject *t_IGraph_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IGraph::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IGraph_of_(t_IGraph *self, PyObject *args)
      {
        if (!parseArg(args, "T", 2, &(self->parameters)))
          Py_RETURN_SELF;
        return PyErr_SetArgsError((PyObject *) self, "of_", args);
      }

      static PyObject *t_IGraph_contains(t_IGraph *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::java::lang::Object a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "O", self->parameters[0], &a0))
            {
              OBJ_CALL(result = self->object.contains(a0));
              Py_RETURN_BOOL(result);
            }
          }
          {
            ::stallone::api::graph::IEdge a0((jobject) NULL);
            PyTypeObject **p0;
            jboolean result;

            if (!parseArgs(args, "K", ::stallone::api::graph::IEdge::initializeClass, &a0, &p0, ::stallone::api::graph::t_IEdge::parameters_))
            {
              OBJ_CALL(result = self->object.contains(a0));
              Py_RETURN_BOOL(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "contains", args);
        return NULL;
      }

      static PyObject *t_IGraph_edgeIterator(t_IGraph *self)
      {
        ::java::util::Iterator result((jobject) NULL);
        OBJ_CALL(result = self->object.edgeIterator());
        return ::java::util::t_Iterator::wrap_Object(result, self->parameters[1]);
      }

      static PyObject *t_IGraph_neighborIterator(t_IGraph *self, PyObject *arg)
      {
        ::java::lang::Object a0((jobject) NULL);
        ::java::util::Iterator result((jobject) NULL);

        if (!parseArg(arg, "O", self->parameters[0], &a0))
        {
          OBJ_CALL(result = self->object.neighborIterator(a0));
          return ::java::util::t_Iterator::wrap_Object(result, self->parameters[0]);
        }

        PyErr_SetArgsError((PyObject *) self, "neighborIterator", arg);
        return NULL;
      }

      static PyObject *t_IGraph_nodeIterator(t_IGraph *self)
      {
        ::java::util::Iterator result((jobject) NULL);
        OBJ_CALL(result = self->object.nodeIterator());
        return ::java::util::t_Iterator::wrap_Object(result, self->parameters[0]);
      }
      static PyObject *t_IGraph_get__parameters_(t_IGraph *self, void *data)
      {
        return typeParameters(self->parameters, sizeof(self->parameters));
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/mc/MarkovModelUtilities.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/mc/ITransitionMatrixEstimator.h"
#include "java/lang/Iterable.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/mc/ICountMatrixEstimator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace mc {

      ::java::lang::Class *MarkovModelUtilities::class$ = NULL;
      jmethodID *MarkovModelUtilities::mids$ = NULL;
      bool MarkovModelUtilities::live$ = false;

      jclass MarkovModelUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/mc/MarkovModelUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_autocorrelation_3313c4fb] = env->getMethodID(cls, "autocorrelation", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_backwardCommittor_c5afb567] = env->getMethodID(cls, "backwardCommittor", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/ints/IIntArray;Lstallone/api/ints/IIntArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_correlation_ea708cbb] = env->getMethodID(cls, "correlation", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateC_b74ef8f0] = env->getMethodID(cls, "estimateC", "(Ljava/lang/Iterable;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateC_5bff2c17] = env->getMethodID(cls, "estimateC", "(Lstallone/api/ints/IIntArray;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateCmilestoning_b74ef8f0] = env->getMethodID(cls, "estimateCmilestoning", "(Ljava/lang/Iterable;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateCmilestoning_5bff2c17] = env->getMethodID(cls, "estimateCmilestoning", "(Lstallone/api/ints/IIntArray;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateCmilestoning_b16959dd] = env->getMethodID(cls, "estimateCmilestoning", "(Ljava/lang/Iterable;Ljava/lang/Iterable;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateCmilestoning_86e7ef1e] = env->getMethodID(cls, "estimateCmilestoning", "(Lstallone/api/ints/IIntArray;Ljava/lang/Iterable;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateCstepping_b74ef8f0] = env->getMethodID(cls, "estimateCstepping", "(Ljava/lang/Iterable;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateCstepping_5bff2c17] = env->getMethodID(cls, "estimateCstepping", "(Lstallone/api/ints/IIntArray;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateT_32638cb7] = env->getMethodID(cls, "estimateT", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateTrev_32638cb7] = env->getMethodID(cls, "estimateTrev", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_estimateTrev_76419023] = env->getMethodID(cls, "estimateTrev", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_fingerprintAutocorrelation_76419023] = env->getMethodID(cls, "fingerprintAutocorrelation", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_fingerprintCorrelation_3313c4fb] = env->getMethodID(cls, "fingerprintCorrelation", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_fingerprintPerturbation_3313c4fb] = env->getMethodID(cls, "fingerprintPerturbation", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_forwardCommittor_c5afb567] = env->getMethodID(cls, "forwardCommittor", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/ints/IIntArray;Lstallone/api/ints/IIntArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_giantComponent_c221c4b5] = env->getMethodID(cls, "giantComponent", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/ints/IIntArray;");
          mids$[mid_isConnected_02530846] = env->getMethodID(cls, "isConnected", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_isRateMatrix_02530846] = env->getMethodID(cls, "isRateMatrix", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_isReversible_02530846] = env->getMethodID(cls, "isReversible", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_isReversible_608d4886] = env->getMethodID(cls, "isReversible", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_isTransitionMatrix_02530846] = env->getMethodID(cls, "isTransitionMatrix", "(Lstallone/api/doubles/IDoubleArray;)Z");
          mids$[mid_logLikelihood_608d4898] = env->getMethodID(cls, "logLikelihood", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_logLikelihoodCorrelationMatrix_608d4898] = env->getMethodID(cls, "logLikelihoodCorrelationMatrix", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_metastableMemberships_e79ba665] = env->getMethodID(cls, "metastableMemberships", "(Lstallone/api/doubles/IDoubleArray;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_metastableStates_980dd7f7] = env->getMethodID(cls, "metastableStates", "(Lstallone/api/doubles/IDoubleArray;I)Lstallone/api/ints/IIntArray;");
          mids$[mid_perturbationExpectation_ea708cbb] = env->getMethodID(cls, "perturbationExpectation", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_stationaryDistribution_32638cb7] = env->getMethodID(cls, "stationaryDistribution", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_stationaryDistributionRevQuick_32638cb7] = env->getMethodID(cls, "stationaryDistributionRevQuick", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_timescales_dfd01cbc] = env->getMethodID(cls, "timescales", "(Lstallone/api/doubles/IDoubleArray;D)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_timescales_c5fddb47] = env->getMethodID(cls, "timescales", "(Ljava/lang/Iterable;Lstallone/api/mc/ICountMatrixEstimator;Lstallone/api/mc/ITransitionMatrixEstimator;ILstallone/api/ints/IIntArray;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_trajectory_dafcf1a9] = env->getMethodID(cls, "trajectory", "(Lstallone/api/doubles/IDoubleArray;II)Lstallone/api/ints/IIntArray;");
          mids$[mid_trajectoryToState_d54dbd05] = env->getMethodID(cls, "trajectoryToState", "(Lstallone/api/doubles/IDoubleArray;I[I)Lstallone/api/ints/IIntArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      MarkovModelUtilities::MarkovModelUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::autocorrelation(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_autocorrelation_3313c4fb], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::backwardCommittor(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::ints::IIntArray & a1, const ::stallone::api::ints::IIntArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_backwardCommittor_c5afb567], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::correlation(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2, const ::stallone::api::doubles::IDoubleArray & a3) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_correlation_ea708cbb], a0.this$, a1.this$, a2.this$, a3.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateC(const ::java::lang::Iterable & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateC_b74ef8f0], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateC(const ::stallone::api::ints::IIntArray & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateC_5bff2c17], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateCmilestoning(const ::java::lang::Iterable & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateCmilestoning_b74ef8f0], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateCmilestoning(const ::stallone::api::ints::IIntArray & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateCmilestoning_5bff2c17], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateCmilestoning(const ::java::lang::Iterable & a0, const ::java::lang::Iterable & a1, jint a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateCmilestoning_b16959dd], a0.this$, a1.this$, a2));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateCmilestoning(const ::stallone::api::ints::IIntArray & a0, const ::java::lang::Iterable & a1, jint a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateCmilestoning_86e7ef1e], a0.this$, a1.this$, a2));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateCstepping(const ::java::lang::Iterable & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateCstepping_b74ef8f0], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateCstepping(const ::stallone::api::ints::IIntArray & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateCstepping_5bff2c17], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateT(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateT_32638cb7], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateTrev(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateTrev_32638cb7], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::estimateTrev(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_estimateTrev_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::fingerprintAutocorrelation(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_fingerprintAutocorrelation_76419023], a0.this$, a1.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::fingerprintCorrelation(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_fingerprintCorrelation_3313c4fb], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::fingerprintPerturbation(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_fingerprintPerturbation_3313c4fb], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::forwardCommittor(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::ints::IIntArray & a1, const ::stallone::api::ints::IIntArray & a2) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_forwardCommittor_c5afb567], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::ints::IIntArray MarkovModelUtilities::giantComponent(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_giantComponent_c221c4b5], a0.this$));
      }

      jboolean MarkovModelUtilities::isConnected(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isConnected_02530846], a0.this$);
      }

      jboolean MarkovModelUtilities::isRateMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isRateMatrix_02530846], a0.this$);
      }

      jboolean MarkovModelUtilities::isReversible(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isReversible_02530846], a0.this$);
      }

      jboolean MarkovModelUtilities::isReversible(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isReversible_608d4886], a0.this$, a1.this$);
      }

      jboolean MarkovModelUtilities::isTransitionMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_isTransitionMatrix_02530846], a0.this$);
      }

      jdouble MarkovModelUtilities::logLikelihood(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_logLikelihood_608d4898], a0.this$, a1.this$);
      }

      jdouble MarkovModelUtilities::logLikelihoodCorrelationMatrix(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_logLikelihoodCorrelationMatrix_608d4898], a0.this$, a1.this$);
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::metastableMemberships(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_metastableMemberships_e79ba665], a0.this$, a1));
      }

      ::stallone::api::ints::IIntArray MarkovModelUtilities::metastableStates(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_metastableStates_980dd7f7], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::perturbationExpectation(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1, const ::stallone::api::doubles::IDoubleArray & a2, const ::stallone::api::doubles::IDoubleArray & a3) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_perturbationExpectation_ea708cbb], a0.this$, a1.this$, a2.this$, a3.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::stationaryDistribution(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_stationaryDistribution_32638cb7], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::stationaryDistributionRevQuick(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_stationaryDistributionRevQuick_32638cb7], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::timescales(const ::stallone::api::doubles::IDoubleArray & a0, jdouble a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_timescales_dfd01cbc], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray MarkovModelUtilities::timescales(const ::java::lang::Iterable & a0, const ::stallone::api::mc::ICountMatrixEstimator & a1, const ::stallone::api::mc::ITransitionMatrixEstimator & a2, jint a3, const ::stallone::api::ints::IIntArray & a4) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_timescales_c5fddb47], a0.this$, a1.this$, a2.this$, a3, a4.this$));
      }

      ::stallone::api::ints::IIntArray MarkovModelUtilities::trajectory(const ::stallone::api::doubles::IDoubleArray & a0, jint a1, jint a2) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_trajectory_dafcf1a9], a0.this$, a1, a2));
      }

      ::stallone::api::ints::IIntArray MarkovModelUtilities::trajectoryToState(const ::stallone::api::doubles::IDoubleArray & a0, jint a1, const JArray< jint > & a2) const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_trajectoryToState_d54dbd05], a0.this$, a1, a2.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace mc {
      static PyObject *t_MarkovModelUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_MarkovModelUtilities_init_(t_MarkovModelUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_MarkovModelUtilities_autocorrelation(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_backwardCommittor(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_correlation(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_estimateC(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_estimateCmilestoning(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_estimateCstepping(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_estimateT(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_estimateTrev(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_fingerprintAutocorrelation(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_fingerprintCorrelation(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_fingerprintPerturbation(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_forwardCommittor(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_giantComponent(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_isConnected(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_isRateMatrix(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_isReversible(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_isTransitionMatrix(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_logLikelihood(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_logLikelihoodCorrelationMatrix(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_metastableMemberships(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_metastableStates(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_perturbationExpectation(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_stationaryDistribution(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_stationaryDistributionRevQuick(t_MarkovModelUtilities *self, PyObject *arg);
      static PyObject *t_MarkovModelUtilities_timescales(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_trajectory(t_MarkovModelUtilities *self, PyObject *args);
      static PyObject *t_MarkovModelUtilities_trajectoryToState(t_MarkovModelUtilities *self, PyObject *args);

      static PyMethodDef t_MarkovModelUtilities__methods_[] = {
        DECLARE_METHOD(t_MarkovModelUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_MarkovModelUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_MarkovModelUtilities, autocorrelation, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, backwardCommittor, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, correlation, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, estimateC, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, estimateCmilestoning, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, estimateCstepping, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, estimateT, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, estimateTrev, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, fingerprintAutocorrelation, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, fingerprintCorrelation, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, fingerprintPerturbation, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, forwardCommittor, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, giantComponent, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, isConnected, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, isRateMatrix, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, isReversible, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, isTransitionMatrix, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, logLikelihood, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, logLikelihoodCorrelationMatrix, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, metastableMemberships, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, metastableStates, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, perturbationExpectation, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, stationaryDistribution, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, stationaryDistributionRevQuick, METH_O),
        DECLARE_METHOD(t_MarkovModelUtilities, timescales, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, trajectory, METH_VARARGS),
        DECLARE_METHOD(t_MarkovModelUtilities, trajectoryToState, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(MarkovModelUtilities, t_MarkovModelUtilities, ::java::lang::Object, MarkovModelUtilities, t_MarkovModelUtilities_init_, 0, 0, 0, 0, 0);

      void t_MarkovModelUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(MarkovModelUtilities), module, "MarkovModelUtilities", 0);
      }

      void t_MarkovModelUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(MarkovModelUtilities).tp_dict, "class_", make_descriptor(MarkovModelUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(MarkovModelUtilities).tp_dict, "wrapfn_", make_descriptor(t_MarkovModelUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(MarkovModelUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_MarkovModelUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, MarkovModelUtilities::initializeClass, 1)))
          return NULL;
        return t_MarkovModelUtilities::wrap_Object(MarkovModelUtilities(((t_MarkovModelUtilities *) arg)->object.this$));
      }
      static PyObject *t_MarkovModelUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, MarkovModelUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_MarkovModelUtilities_init_(t_MarkovModelUtilities *self, PyObject *args, PyObject *kwds)
      {
        MarkovModelUtilities object((jobject) NULL);

        INT_CALL(object = MarkovModelUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_MarkovModelUtilities_autocorrelation(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.autocorrelation(a0, a1, a2));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "autocorrelation", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_backwardCommittor(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::ints::IIntArray a1((jobject) NULL);
        ::stallone::api::ints::IIntArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.backwardCommittor(a0, a1, a2));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "backwardCommittor", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_correlation(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a3((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2, &a3))
        {
          OBJ_CALL(result = self->object.correlation(a0, a1, a2, a3));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "correlation", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_estimateC(t_MarkovModelUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "KI", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1))
            {
              OBJ_CALL(result = self->object.estimateC(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.estimateC(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "estimateC", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_estimateCmilestoning(t_MarkovModelUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "KI", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1))
            {
              OBJ_CALL(result = self->object.estimateCmilestoning(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.estimateCmilestoning(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            ::java::lang::Iterable a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "KKI", ::java::lang::Iterable::initializeClass, ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &p1, ::java::lang::t_Iterable::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.estimateCmilestoning(a0, a1, a2));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            ::java::lang::Iterable a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kKI", ::stallone::api::ints::IIntArray::initializeClass, ::java::lang::Iterable::initializeClass, &a0, &a1, &p1, ::java::lang::t_Iterable::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.estimateCmilestoning(a0, a1, a2));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "estimateCmilestoning", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_estimateCstepping(t_MarkovModelUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "KI", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1))
            {
              OBJ_CALL(result = self->object.estimateCstepping(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::ints::IIntArray a0((jobject) NULL);
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.estimateCstepping(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "estimateCstepping", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_estimateT(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.estimateT(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "estimateT", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_estimateTrev(t_MarkovModelUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.estimateTrev(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.estimateTrev(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "estimateTrev", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_fingerprintAutocorrelation(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.fingerprintAutocorrelation(a0, a1));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "fingerprintAutocorrelation", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_fingerprintCorrelation(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.fingerprintCorrelation(a0, a1, a2));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "fingerprintCorrelation", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_fingerprintPerturbation(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.fingerprintPerturbation(a0, a1, a2));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "fingerprintPerturbation", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_forwardCommittor(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::ints::IIntArray a1((jobject) NULL);
        ::stallone::api::ints::IIntArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.forwardCommittor(a0, a1, a2));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "forwardCommittor", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_giantComponent(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.giantComponent(a0));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "giantComponent", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_isConnected(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.isConnected(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isConnected", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_isRateMatrix(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.isRateMatrix(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isRateMatrix", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_isReversible(t_MarkovModelUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.isReversible(a0));
              Py_RETURN_BOOL(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            jboolean result;

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.isReversible(a0, a1));
              Py_RETURN_BOOL(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "isReversible", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_isTransitionMatrix(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jboolean result;

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.isTransitionMatrix(a0));
          Py_RETURN_BOOL(result);
        }

        PyErr_SetArgsError((PyObject *) self, "isTransitionMatrix", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_logLikelihood(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        jdouble result;

        if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.logLikelihood(a0, a1));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "logLikelihood", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_logLikelihoodCorrelationMatrix(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        jdouble result;

        if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.logLikelihoodCorrelationMatrix(a0, a1));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "logLikelihoodCorrelationMatrix", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_metastableMemberships(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jint a1;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.metastableMemberships(a0, a1));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "metastableMemberships", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_metastableStates(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jint a1;
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.metastableStates(a0, a1));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "metastableStates", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_perturbationExpectation(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a2((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray a3((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "kkkk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2, &a3))
        {
          OBJ_CALL(result = self->object.perturbationExpectation(a0, a1, a2, a3));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "perturbationExpectation", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_stationaryDistribution(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.stationaryDistribution(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "stationaryDistribution", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_stationaryDistributionRevQuick(t_MarkovModelUtilities *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.stationaryDistributionRevQuick(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "stationaryDistributionRevQuick", arg);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_timescales(t_MarkovModelUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jdouble a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kD", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.timescales(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 5:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            ::stallone::api::mc::ICountMatrixEstimator a1((jobject) NULL);
            ::stallone::api::mc::ITransitionMatrixEstimator a2((jobject) NULL);
            jint a3;
            ::stallone::api::ints::IIntArray a4((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "KkkIk", ::java::lang::Iterable::initializeClass, ::stallone::api::mc::ICountMatrixEstimator::initializeClass, ::stallone::api::mc::ITransitionMatrixEstimator::initializeClass, ::stallone::api::ints::IIntArray::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2, &a3, &a4))
            {
              OBJ_CALL(result = self->object.timescales(a0, a1, a2, a3, a4));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "timescales", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_trajectory(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jint a1;
        jint a2;
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArgs(args, "kII", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.trajectory(a0, a1, a2));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "trajectory", args);
        return NULL;
      }

      static PyObject *t_MarkovModelUtilities_trajectoryToState(t_MarkovModelUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jint a1;
        JArray< jint > a2((jobject) NULL);
        ::stallone::api::ints::IIntArray result((jobject) NULL);

        if (!parseArgs(args, "kI[I", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.trajectoryToState(a0, a1, a2));
          return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "trajectoryToState", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/doubles/ISortDouble.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace doubles {

      ::java::lang::Class *ISortDouble::class$ = NULL;
      jmethodID *ISortDouble::mids$ = NULL;
      bool ISortDouble::live$ = false;

      jclass ISortDouble::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/doubles/ISortDouble");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getSortedData_1d53e353] = env->getMethodID(cls, "getSortedData", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_getSortedIndexes_4ac77731] = env->getMethodID(cls, "getSortedIndexes", "()Lstallone/api/ints/IIntArray;");
          mids$[mid_setData_0253084a] = env->getMethodID(cls, "setData", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_setData_608d488a] = env->getMethodID(cls, "setData", "(Lstallone/api/doubles/IDoubleArray;Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_sort_1d53e353] = env->getMethodID(cls, "sort", "()Lstallone/api/doubles/IDoubleArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::doubles::IDoubleArray ISortDouble::getSortedData() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getSortedData_1d53e353]));
      }

      ::stallone::api::ints::IIntArray ISortDouble::getSortedIndexes() const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_getSortedIndexes_4ac77731]));
      }

      void ISortDouble::setData(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setData_0253084a], a0.this$);
      }

      void ISortDouble::setData(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_setData_608d488a], a0.this$, a1.this$);
      }

      ::stallone::api::doubles::IDoubleArray ISortDouble::sort() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_sort_1d53e353]));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace doubles {
      static PyObject *t_ISortDouble_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ISortDouble_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ISortDouble_getSortedData(t_ISortDouble *self);
      static PyObject *t_ISortDouble_getSortedIndexes(t_ISortDouble *self);
      static PyObject *t_ISortDouble_setData(t_ISortDouble *self, PyObject *args);
      static PyObject *t_ISortDouble_sort(t_ISortDouble *self);
      static int t_ISortDouble_set__data(t_ISortDouble *self, PyObject *arg, void *data);
      static PyObject *t_ISortDouble_get__sortedData(t_ISortDouble *self, void *data);
      static PyObject *t_ISortDouble_get__sortedIndexes(t_ISortDouble *self, void *data);
      static PyGetSetDef t_ISortDouble__fields_[] = {
        DECLARE_SET_FIELD(t_ISortDouble, data),
        DECLARE_GET_FIELD(t_ISortDouble, sortedData),
        DECLARE_GET_FIELD(t_ISortDouble, sortedIndexes),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_ISortDouble__methods_[] = {
        DECLARE_METHOD(t_ISortDouble, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ISortDouble, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ISortDouble, getSortedData, METH_NOARGS),
        DECLARE_METHOD(t_ISortDouble, getSortedIndexes, METH_NOARGS),
        DECLARE_METHOD(t_ISortDouble, setData, METH_VARARGS),
        DECLARE_METHOD(t_ISortDouble, sort, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(ISortDouble, t_ISortDouble, ::java::lang::Object, ISortDouble, abstract_init, 0, 0, t_ISortDouble__fields_, 0, 0);

      void t_ISortDouble::install(PyObject *module)
      {
        installType(&PY_TYPE(ISortDouble), module, "ISortDouble", 0);
      }

      void t_ISortDouble::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(ISortDouble).tp_dict, "class_", make_descriptor(ISortDouble::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ISortDouble).tp_dict, "wrapfn_", make_descriptor(t_ISortDouble::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ISortDouble).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_ISortDouble_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, ISortDouble::initializeClass, 1)))
          return NULL;
        return t_ISortDouble::wrap_Object(ISortDouble(((t_ISortDouble *) arg)->object.this$));
      }
      static PyObject *t_ISortDouble_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, ISortDouble::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_ISortDouble_getSortedData(t_ISortDouble *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getSortedData());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_ISortDouble_getSortedIndexes(t_ISortDouble *self)
      {
        ::stallone::api::ints::IIntArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getSortedIndexes());
        return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
      }

      static PyObject *t_ISortDouble_setData(t_ISortDouble *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(self->object.setData(a0));
              Py_RETURN_NONE;
            }
          }
          break;
         case 2:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(self->object.setData(a0, a1));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "setData", args);
        return NULL;
      }

      static PyObject *t_ISortDouble_sort(t_ISortDouble *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.sort());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static int t_ISortDouble_set__data(t_ISortDouble *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setData(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "data", arg);
        return -1;
      }

      static PyObject *t_ISortDouble_get__sortedData(t_ISortDouble *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getSortedData());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }

      static PyObject *t_ISortDouble_get__sortedIndexes(t_ISortDouble *self, void *data)
      {
        ::stallone::api::ints::IIntArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getSortedIndexes());
        return ::stallone::api::ints::t_IIntArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/dynamics/IIntegrator.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/potential/IEnergyModel.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace dynamics {

    ::java::lang::Class *IIntegrator::class$ = NULL;
    jmethodID *IIntegrator::mids$ = NULL;
    bool IIntegrator::live$ = false;

    jclass IIntegrator::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("stallone/dynamics/IIntegrator");

        mids$ = new jmethodID[max_mid];
        mids$[mid_copy_dc93dc5d] = env->getMethodID(cls, "copy", "()Lstallone/dynamics/IIntegrator;");
        mids$[mid_getA_1d53e353] = env->getMethodID(cls, "getA", "()Lstallone/api/doubles/IDoubleArray;");
        mids$[mid_getStepLength_54c6a174] = env->getMethodID(cls, "getStepLength", "()D");
        mids$[mid_getV_1d53e353] = env->getMethodID(cls, "getV", "()Lstallone/api/doubles/IDoubleArray;");
        mids$[mid_getX_1d53e353] = env->getMethodID(cls, "getX", "()Lstallone/api/doubles/IDoubleArray;");
        mids$[mid_kineticEnergy_54c6a174] = env->getMethodID(cls, "kineticEnergy", "()D");
        mids$[mid_potentialEnergy_54c6a174] = env->getMethodID(cls, "potentialEnergy", "()D");
        mids$[mid_setEnergyModel_07a15343] = env->getMethodID(cls, "setEnergyModel", "(Lstallone/api/potential/IEnergyModel;)V");
        mids$[mid_setMasses_0253084a] = env->getMethodID(cls, "setMasses", "(Lstallone/api/doubles/IDoubleArray;)V");
        mids$[mid_setStepLength_5d1c7645] = env->getMethodID(cls, "setStepLength", "(D)V");
        mids$[mid_setV_0253084a] = env->getMethodID(cls, "setV", "(Lstallone/api/doubles/IDoubleArray;)V");
        mids$[mid_setX_0253084a] = env->getMethodID(cls, "setX", "(Lstallone/api/doubles/IDoubleArray;)V");
        mids$[mid_step_54c6a16a] = env->getMethodID(cls, "step", "()Z");
        mids$[mid_totalEnergy_54c6a174] = env->getMethodID(cls, "totalEnergy", "()D");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    IIntegrator IIntegrator::copy() const
    {
      return IIntegrator(env->callObjectMethod(this$, mids$[mid_copy_dc93dc5d]));
    }

    ::stallone::api::doubles::IDoubleArray IIntegrator::getA() const
    {
      return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getA_1d53e353]));
    }

    jdouble IIntegrator::getStepLength() const
    {
      return env->callDoubleMethod(this$, mids$[mid_getStepLength_54c6a174]);
    }

    ::stallone::api::doubles::IDoubleArray IIntegrator::getV() const
    {
      return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getV_1d53e353]));
    }

    ::stallone::api::doubles::IDoubleArray IIntegrator::getX() const
    {
      return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getX_1d53e353]));
    }

    jdouble IIntegrator::kineticEnergy() const
    {
      return env->callDoubleMethod(this$, mids$[mid_kineticEnergy_54c6a174]);
    }

    jdouble IIntegrator::potentialEnergy() const
    {
      return env->callDoubleMethod(this$, mids$[mid_potentialEnergy_54c6a174]);
    }

    void IIntegrator::setEnergyModel(const ::stallone::api::potential::IEnergyModel & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setEnergyModel_07a15343], a0.this$);
    }

    void IIntegrator::setMasses(const ::stallone::api::doubles::IDoubleArray & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setMasses_0253084a], a0.this$);
    }

    void IIntegrator::setStepLength(jdouble a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setStepLength_5d1c7645], a0);
    }

    void IIntegrator::setV(const ::stallone::api::doubles::IDoubleArray & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setV_0253084a], a0.this$);
    }

    void IIntegrator::setX(const ::stallone::api::doubles::IDoubleArray & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setX_0253084a], a0.this$);
    }

    jboolean IIntegrator::step() const
    {
      return env->callBooleanMethod(this$, mids$[mid_step_54c6a16a]);
    }

    jdouble IIntegrator::totalEnergy() const
    {
      return env->callDoubleMethod(this$, mids$[mid_totalEnergy_54c6a174]);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace dynamics {
    static PyObject *t_IIntegrator_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_IIntegrator_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_IIntegrator_copy(t_IIntegrator *self);
    static PyObject *t_IIntegrator_getA(t_IIntegrator *self);
    static PyObject *t_IIntegrator_getStepLength(t_IIntegrator *self);
    static PyObject *t_IIntegrator_getV(t_IIntegrator *self);
    static PyObject *t_IIntegrator_getX(t_IIntegrator *self);
    static PyObject *t_IIntegrator_kineticEnergy(t_IIntegrator *self);
    static PyObject *t_IIntegrator_potentialEnergy(t_IIntegrator *self);
    static PyObject *t_IIntegrator_setEnergyModel(t_IIntegrator *self, PyObject *arg);
    static PyObject *t_IIntegrator_setMasses(t_IIntegrator *self, PyObject *arg);
    static PyObject *t_IIntegrator_setStepLength(t_IIntegrator *self, PyObject *arg);
    static PyObject *t_IIntegrator_setV(t_IIntegrator *self, PyObject *arg);
    static PyObject *t_IIntegrator_setX(t_IIntegrator *self, PyObject *arg);
    static PyObject *t_IIntegrator_step(t_IIntegrator *self);
    static PyObject *t_IIntegrator_totalEnergy(t_IIntegrator *self);
    static PyObject *t_IIntegrator_get__a(t_IIntegrator *self, void *data);
    static int t_IIntegrator_set__energyModel(t_IIntegrator *self, PyObject *arg, void *data);
    static int t_IIntegrator_set__masses(t_IIntegrator *self, PyObject *arg, void *data);
    static PyObject *t_IIntegrator_get__stepLength(t_IIntegrator *self, void *data);
    static int t_IIntegrator_set__stepLength(t_IIntegrator *self, PyObject *arg, void *data);
    static PyObject *t_IIntegrator_get__v(t_IIntegrator *self, void *data);
    static int t_IIntegrator_set__v(t_IIntegrator *self, PyObject *arg, void *data);
    static PyObject *t_IIntegrator_get__x(t_IIntegrator *self, void *data);
    static int t_IIntegrator_set__x(t_IIntegrator *self, PyObject *arg, void *data);
    static PyGetSetDef t_IIntegrator__fields_[] = {
      DECLARE_GET_FIELD(t_IIntegrator, a),
      DECLARE_SET_FIELD(t_IIntegrator, energyModel),
      DECLARE_SET_FIELD(t_IIntegrator, masses),
      DECLARE_GETSET_FIELD(t_IIntegrator, stepLength),
      DECLARE_GETSET_FIELD(t_IIntegrator, v),
      DECLARE_GETSET_FIELD(t_IIntegrator, x),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_IIntegrator__methods_[] = {
      DECLARE_METHOD(t_IIntegrator, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_IIntegrator, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_IIntegrator, copy, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, getA, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, getStepLength, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, getV, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, getX, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, kineticEnergy, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, potentialEnergy, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, setEnergyModel, METH_O),
      DECLARE_METHOD(t_IIntegrator, setMasses, METH_O),
      DECLARE_METHOD(t_IIntegrator, setStepLength, METH_O),
      DECLARE_METHOD(t_IIntegrator, setV, METH_O),
      DECLARE_METHOD(t_IIntegrator, setX, METH_O),
      DECLARE_METHOD(t_IIntegrator, step, METH_NOARGS),
      DECLARE_METHOD(t_IIntegrator, totalEnergy, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(IIntegrator, t_IIntegrator, ::java::lang::Object, IIntegrator, abstract_init, 0, 0, t_IIntegrator__fields_, 0, 0);

    void t_IIntegrator::install(PyObject *module)
    {
      installType(&PY_TYPE(IIntegrator), module, "IIntegrator", 0);
    }

    void t_IIntegrator::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(IIntegrator).tp_dict, "class_", make_descriptor(IIntegrator::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(IIntegrator).tp_dict, "wrapfn_", make_descriptor(t_IIntegrator::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(IIntegrator).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_IIntegrator_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, IIntegrator::initializeClass, 1)))
        return NULL;
      return t_IIntegrator::wrap_Object(IIntegrator(((t_IIntegrator *) arg)->object.this$));
    }
    static PyObject *t_IIntegrator_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, IIntegrator::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_IIntegrator_copy(t_IIntegrator *self)
    {
      IIntegrator result((jobject) NULL);
      OBJ_CALL(result = self->object.copy());
      return t_IIntegrator::wrap_Object(result);
    }

    static PyObject *t_IIntegrator_getA(t_IIntegrator *self)
    {
      ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
      OBJ_CALL(result = self->object.getA());
      return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
    }

    static PyObject *t_IIntegrator_getStepLength(t_IIntegrator *self)
    {
      jdouble result;
      OBJ_CALL(result = self->object.getStepLength());
      return PyFloat_FromDouble((double) result);
    }

    static PyObject *t_IIntegrator_getV(t_IIntegrator *self)
    {
      ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
      OBJ_CALL(result = self->object.getV());
      return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
    }

    static PyObject *t_IIntegrator_getX(t_IIntegrator *self)
    {
      ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
      OBJ_CALL(result = self->object.getX());
      return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
    }

    static PyObject *t_IIntegrator_kineticEnergy(t_IIntegrator *self)
    {
      jdouble result;
      OBJ_CALL(result = self->object.kineticEnergy());
      return PyFloat_FromDouble((double) result);
    }

    static PyObject *t_IIntegrator_potentialEnergy(t_IIntegrator *self)
    {
      jdouble result;
      OBJ_CALL(result = self->object.potentialEnergy());
      return PyFloat_FromDouble((double) result);
    }

    static PyObject *t_IIntegrator_setEnergyModel(t_IIntegrator *self, PyObject *arg)
    {
      ::stallone::api::potential::IEnergyModel a0((jobject) NULL);

      if (!parseArg(arg, "k", ::stallone::api::potential::IEnergyModel::initializeClass, &a0))
      {
        OBJ_CALL(self->object.setEnergyModel(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setEnergyModel", arg);
      return NULL;
    }

    static PyObject *t_IIntegrator_setMasses(t_IIntegrator *self, PyObject *arg)
    {
      ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

      if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
      {
        OBJ_CALL(self->object.setMasses(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setMasses", arg);
      return NULL;
    }

    static PyObject *t_IIntegrator_setStepLength(t_IIntegrator *self, PyObject *arg)
    {
      jdouble a0;

      if (!parseArg(arg, "D", &a0))
      {
        OBJ_CALL(self->object.setStepLength(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setStepLength", arg);
      return NULL;
    }

    static PyObject *t_IIntegrator_setV(t_IIntegrator *self, PyObject *arg)
    {
      ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

      if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
      {
        OBJ_CALL(self->object.setV(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setV", arg);
      return NULL;
    }

    static PyObject *t_IIntegrator_setX(t_IIntegrator *self, PyObject *arg)
    {
      ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

      if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
      {
        OBJ_CALL(self->object.setX(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setX", arg);
      return NULL;
    }

    static PyObject *t_IIntegrator_step(t_IIntegrator *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.step());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_IIntegrator_totalEnergy(t_IIntegrator *self)
    {
      jdouble result;
      OBJ_CALL(result = self->object.totalEnergy());
      return PyFloat_FromDouble((double) result);
    }

    static PyObject *t_IIntegrator_get__a(t_IIntegrator *self, void *data)
    {
      ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
      OBJ_CALL(value = self->object.getA());
      return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
    }

    static int t_IIntegrator_set__energyModel(t_IIntegrator *self, PyObject *arg, void *data)
    {
      {
        ::stallone::api::potential::IEnergyModel value((jobject) NULL);
        if (!parseArg(arg, "k", ::stallone::api::potential::IEnergyModel::initializeClass, &value))
        {
          INT_CALL(self->object.setEnergyModel(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "energyModel", arg);
      return -1;
    }

    static int t_IIntegrator_set__masses(t_IIntegrator *self, PyObject *arg, void *data)
    {
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
        {
          INT_CALL(self->object.setMasses(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "masses", arg);
      return -1;
    }

    static PyObject *t_IIntegrator_get__stepLength(t_IIntegrator *self, void *data)
    {
      jdouble value;
      OBJ_CALL(value = self->object.getStepLength());
      return PyFloat_FromDouble((double) value);
    }
    static int t_IIntegrator_set__stepLength(t_IIntegrator *self, PyObject *arg, void *data)
    {
      {
        jdouble value;
        if (!parseArg(arg, "D", &value))
        {
          INT_CALL(self->object.setStepLength(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "stepLength", arg);
      return -1;
    }

    static PyObject *t_IIntegrator_get__v(t_IIntegrator *self, void *data)
    {
      ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
      OBJ_CALL(value = self->object.getV());
      return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
    }
    static int t_IIntegrator_set__v(t_IIntegrator *self, PyObject *arg, void *data)
    {
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
        {
          INT_CALL(self->object.setV(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "v", arg);
      return -1;
    }

    static PyObject *t_IIntegrator_get__x(t_IIntegrator *self, void *data)
    {
      ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
      OBJ_CALL(value = self->object.getX());
      return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
    }
    static int t_IIntegrator_set__x(t_IIntegrator *self, PyObject *arg, void *data)
    {
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
        {
          INT_CALL(self->object.setX(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "x", arg);
      return -1;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/INorm.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/complex/IComplexArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *INorm::class$ = NULL;
      jmethodID *INorm::mids$ = NULL;
      bool INorm::live$ = false;

      jclass INorm::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/INorm");

          mids$ = new jmethodID[max_mid];
          mids$[mid_norm_02530858] = env->getMethodID(cls, "norm", "(Lstallone/api/doubles/IDoubleArray;)D");
          mids$[mid_norm_ce2e75d8] = env->getMethodID(cls, "norm", "(Lstallone/api/complex/IComplexArray;)D");
          mids$[mid_norm_77eaab7a] = env->getMethodID(cls, "norm", "(Lstallone/api/complex/IComplexArray;I)D");
          mids$[mid_norm_20d144ba] = env->getMethodID(cls, "norm", "(Lstallone/api/doubles/IDoubleArray;I)D");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jdouble INorm::norm(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_norm_02530858], a0.this$);
      }

      jdouble INorm::norm(const ::stallone::api::complex::IComplexArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_norm_ce2e75d8], a0.this$);
      }

      jdouble INorm::norm(const ::stallone::api::complex::IComplexArray & a0, jint a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_norm_77eaab7a], a0.this$, a1);
      }

      jdouble INorm::norm(const ::stallone::api::doubles::IDoubleArray & a0, jint a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_norm_20d144ba], a0.this$, a1);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_INorm_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_INorm_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_INorm_norm(t_INorm *self, PyObject *args);

      static PyMethodDef t_INorm__methods_[] = {
        DECLARE_METHOD(t_INorm, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_INorm, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_INorm, norm, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(INorm, t_INorm, ::java::lang::Object, INorm, abstract_init, 0, 0, 0, 0, 0);

      void t_INorm::install(PyObject *module)
      {
        installType(&PY_TYPE(INorm), module, "INorm", 0);
      }

      void t_INorm::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(INorm).tp_dict, "class_", make_descriptor(INorm::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(INorm).tp_dict, "wrapfn_", make_descriptor(t_INorm::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(INorm).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_INorm_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, INorm::initializeClass, 1)))
          return NULL;
        return t_INorm::wrap_Object(INorm(((t_INorm *) arg)->object.this$));
      }
      static PyObject *t_INorm_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, INorm::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_INorm_norm(t_INorm *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.norm(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            jdouble result;

            if (!parseArgs(args, "k", ::stallone::api::complex::IComplexArray::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.norm(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::complex::IComplexArray a0((jobject) NULL);
            jint a1;
            jdouble result;

            if (!parseArgs(args, "kI", ::stallone::api::complex::IComplexArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.norm(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
          {
            ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
            jint a1;
            jdouble result;

            if (!parseArgs(args, "kI", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.norm(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "norm", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/stat/Statistics.h"
#include "stallone/api/stat/StatisticsUtilities.h"
#include "stallone/api/stat/StatisticsFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace stat {

      ::java::lang::Class *Statistics::class$ = NULL;
      jmethodID *Statistics::mids$ = NULL;
      bool Statistics::live$ = false;
      ::stallone::api::stat::StatisticsFactory *Statistics::create = NULL;
      ::stallone::api::stat::StatisticsUtilities *Statistics::util = NULL;

      jclass Statistics::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/stat/Statistics");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::stat::StatisticsFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/stat/StatisticsFactory;"));
          util = new ::stallone::api::stat::StatisticsUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/stat/StatisticsUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      Statistics::Statistics() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace stat {
      static PyObject *t_Statistics_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_Statistics_instance_(PyTypeObject *type, PyObject *arg);
      static int t_Statistics_init_(t_Statistics *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_Statistics__methods_[] = {
        DECLARE_METHOD(t_Statistics, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Statistics, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(Statistics, t_Statistics, ::java::lang::Object, Statistics, t_Statistics_init_, 0, 0, 0, 0, 0);

      void t_Statistics::install(PyObject *module)
      {
        installType(&PY_TYPE(Statistics), module, "Statistics", 0);
      }

      void t_Statistics::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(Statistics).tp_dict, "class_", make_descriptor(Statistics::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Statistics).tp_dict, "wrapfn_", make_descriptor(t_Statistics::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Statistics).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(Statistics::initializeClass);
        PyDict_SetItemString(PY_TYPE(Statistics).tp_dict, "create", make_descriptor(::stallone::api::stat::t_StatisticsFactory::wrap_Object(*Statistics::create)));
        PyDict_SetItemString(PY_TYPE(Statistics).tp_dict, "util", make_descriptor(::stallone::api::stat::t_StatisticsUtilities::wrap_Object(*Statistics::util)));
      }

      static PyObject *t_Statistics_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, Statistics::initializeClass, 1)))
          return NULL;
        return t_Statistics::wrap_Object(Statistics(((t_Statistics *) arg)->object.this$));
      }
      static PyObject *t_Statistics_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, Statistics::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_Statistics_init_(t_Statistics *self, PyObject *args, PyObject *kwds)
      {
        Statistics object((jobject) NULL);

        INT_CALL(object = Statistics());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/potential/IMassEnergyModel.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace potential {

      ::java::lang::Class *IMassEnergyModel::class$ = NULL;
      jmethodID *IMassEnergyModel::mids$ = NULL;
      bool IMassEnergyModel::live$ = false;

      jclass IMassEnergyModel::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/potential/IMassEnergyModel");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getMasses_1d53e353] = env->getMethodID(cls, "getMasses", "()Lstallone/api/doubles/IDoubleArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::doubles::IDoubleArray IMassEnergyModel::getMasses() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getMasses_1d53e353]));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace potential {
      static PyObject *t_IMassEnergyModel_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IMassEnergyModel_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IMassEnergyModel_getMasses(t_IMassEnergyModel *self);
      static PyObject *t_IMassEnergyModel_get__masses(t_IMassEnergyModel *self, void *data);
      static PyGetSetDef t_IMassEnergyModel__fields_[] = {
        DECLARE_GET_FIELD(t_IMassEnergyModel, masses),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IMassEnergyModel__methods_[] = {
        DECLARE_METHOD(t_IMassEnergyModel, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IMassEnergyModel, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IMassEnergyModel, getMasses, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IMassEnergyModel, t_IMassEnergyModel, ::stallone::api::potential::IEnergyModel, IMassEnergyModel, abstract_init, 0, 0, t_IMassEnergyModel__fields_, 0, 0);

      void t_IMassEnergyModel::install(PyObject *module)
      {
        installType(&PY_TYPE(IMassEnergyModel), module, "IMassEnergyModel", 0);
      }

      void t_IMassEnergyModel::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IMassEnergyModel).tp_dict, "class_", make_descriptor(IMassEnergyModel::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IMassEnergyModel).tp_dict, "wrapfn_", make_descriptor(t_IMassEnergyModel::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IMassEnergyModel).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IMassEnergyModel_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IMassEnergyModel::initializeClass, 1)))
          return NULL;
        return t_IMassEnergyModel::wrap_Object(IMassEnergyModel(((t_IMassEnergyModel *) arg)->object.this$));
      }
      static PyObject *t_IMassEnergyModel_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IMassEnergyModel::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IMassEnergyModel_getMasses(t_IMassEnergyModel *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getMasses());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IMassEnergyModel_get__masses(t_IMassEnergyModel *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getMasses());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Long.h"
#include "java/lang/String.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Comparable.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Long::class$ = NULL;
    jmethodID *Long::mids$ = NULL;
    bool Long::live$ = false;
    jlong Long::MAX_VALUE = (jlong) 0;
    jlong Long::MIN_VALUE = (jlong) 0;
    jint Long::SIZE = (jint) 0;
    ::java::lang::Class *Long::TYPE = NULL;

    jclass Long::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Long");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_0ee6df2f] = env->getMethodID(cls, "<init>", "(J)V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_bitCount_0ee6df30] = env->getStaticMethodID(cls, "bitCount", "(J)I");
        mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
        mids$[mid_compareTo_da55802e] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Long;)I");
        mids$[mid_decode_ee9f94be] = env->getStaticMethodID(cls, "decode", "(Ljava/lang/String;)Ljava/lang/Long;");
        mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
        mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
        mids$[mid_getLong_ee9f94be] = env->getStaticMethodID(cls, "getLong", "(Ljava/lang/String;)Ljava/lang/Long;");
        mids$[mid_getLong_9f081a1d] = env->getStaticMethodID(cls, "getLong", "(Ljava/lang/String;J)Ljava/lang/Long;");
        mids$[mid_getLong_9a12142f] = env->getStaticMethodID(cls, "getLong", "(Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_highestOneBit_0ee6df33] = env->getStaticMethodID(cls, "highestOneBit", "(J)J");
        mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
        mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
        mids$[mid_lowestOneBit_0ee6df33] = env->getStaticMethodID(cls, "lowestOneBit", "(J)J");
        mids$[mid_numberOfLeadingZeros_0ee6df30] = env->getStaticMethodID(cls, "numberOfLeadingZeros", "(J)I");
        mids$[mid_numberOfTrailingZeros_0ee6df30] = env->getStaticMethodID(cls, "numberOfTrailingZeros", "(J)I");
        mids$[mid_parseLong_5fdc3f54] = env->getStaticMethodID(cls, "parseLong", "(Ljava/lang/String;)J");
        mids$[mid_parseLong_6e53ccda] = env->getStaticMethodID(cls, "parseLong", "(Ljava/lang/String;I)J");
        mids$[mid_reverse_0ee6df33] = env->getStaticMethodID(cls, "reverse", "(J)J");
        mids$[mid_reverseBytes_0ee6df33] = env->getStaticMethodID(cls, "reverseBytes", "(J)J");
        mids$[mid_rotateLeft_25d05c93] = env->getStaticMethodID(cls, "rotateLeft", "(JI)J");
        mids$[mid_rotateRight_25d05c93] = env->getStaticMethodID(cls, "rotateRight", "(JI)J");
        mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");
        mids$[mid_signum_0ee6df30] = env->getStaticMethodID(cls, "signum", "(J)I");
        mids$[mid_toBinaryString_3e02f30e] = env->getStaticMethodID(cls, "toBinaryString", "(J)Ljava/lang/String;");
        mids$[mid_toHexString_3e02f30e] = env->getStaticMethodID(cls, "toHexString", "(J)Ljava/lang/String;");
        mids$[mid_toOctalString_3e02f30e] = env->getStaticMethodID(cls, "toOctalString", "(J)Ljava/lang/String;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_toString_3e02f30e] = env->getStaticMethodID(cls, "toString", "(J)Ljava/lang/String;");
        mids$[mid_toString_36a2b01a] = env->getStaticMethodID(cls, "toString", "(JI)Ljava/lang/String;");
        mids$[mid_valueOf_62a69723] = env->getStaticMethodID(cls, "valueOf", "(J)Ljava/lang/Long;");
        mids$[mid_valueOf_ee9f94be] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;)Ljava/lang/Long;");
        mids$[mid_valueOf_212f058c] = env->getStaticMethodID(cls, "valueOf", "(Ljava/lang/String;I)Ljava/lang/Long;");

        class$ = (::java::lang::Class *) new JObject(cls);
        cls = (jclass) class$->this$;

        MAX_VALUE = env->getStaticLongField(cls, "MAX_VALUE");
        MIN_VALUE = env->getStaticLongField(cls, "MIN_VALUE");
        SIZE = env->getStaticIntField(cls, "SIZE");
        TYPE = new ::java::lang::Class(env->getStaticObjectField(cls, "TYPE", "Ljava/lang/Class;"));
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Long::Long(jlong a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_0ee6df2f, a0)) {}

    Long::Long(const ::java::lang::String & a0) : ::java::lang::Number(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    jint Long::bitCount(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_bitCount_0ee6df30], a0);
    }

    jbyte Long::byteValue() const
    {
      return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
    }

    jint Long::compareTo(const Long & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_compareTo_da55802e], a0.this$);
    }

    Long Long::decode(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_decode_ee9f94be], a0.this$));
    }

    jdouble Long::doubleValue() const
    {
      return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
    }

    jboolean Long::equals(const ::java::lang::Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
    }

    jfloat Long::floatValue() const
    {
      return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
    }

    Long Long::getLong(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_getLong_ee9f94be], a0.this$));
    }

    Long Long::getLong(const ::java::lang::String & a0, jlong a1)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_getLong_9f081a1d], a0.this$, a1));
    }

    Long Long::getLong(const ::java::lang::String & a0, const Long & a1)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_getLong_9a12142f], a0.this$, a1.this$));
    }

    jint Long::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    jlong Long::highestOneBit(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_highestOneBit_0ee6df33], a0);
    }

    jint Long::intValue() const
    {
      return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
    }

    jlong Long::longValue() const
    {
      return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
    }

    jlong Long::lowestOneBit(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_lowestOneBit_0ee6df33], a0);
    }

    jint Long::numberOfLeadingZeros(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_numberOfLeadingZeros_0ee6df30], a0);
    }

    jint Long::numberOfTrailingZeros(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_numberOfTrailingZeros_0ee6df30], a0);
    }

    jlong Long::parseLong(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_parseLong_5fdc3f54], a0.this$);
    }

    jlong Long::parseLong(const ::java::lang::String & a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_parseLong_6e53ccda], a0.this$, a1);
    }

    jlong Long::reverse(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_reverse_0ee6df33], a0);
    }

    jlong Long::reverseBytes(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_reverseBytes_0ee6df33], a0);
    }

    jlong Long::rotateLeft(jlong a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_rotateLeft_25d05c93], a0, a1);
    }

    jlong Long::rotateRight(jlong a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticLongMethod(cls, mids$[mid_rotateRight_25d05c93], a0, a1);
    }

    jshort Long::shortValue() const
    {
      return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
    }

    jint Long::signum(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return env->callStaticIntMethod(cls, mids$[mid_signum_0ee6df30], a0);
    }

    ::java::lang::String Long::toBinaryString(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toBinaryString_3e02f30e], a0));
    }

    ::java::lang::String Long::toHexString(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toHexString_3e02f30e], a0));
    }

    ::java::lang::String Long::toOctalString(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toOctalString_3e02f30e], a0));
    }

    ::java::lang::String Long::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    ::java::lang::String Long::toString(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_3e02f30e], a0));
    }

    ::java::lang::String Long::toString(jlong a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return ::java::lang::String(env->callStaticObjectMethod(cls, mids$[mid_toString_36a2b01a], a0, a1));
    }

    Long Long::valueOf(jlong a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_valueOf_62a69723], a0));
    }

    Long Long::valueOf(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_valueOf_ee9f94be], a0.this$));
    }

    Long Long::valueOf(const ::java::lang::String & a0, jint a1)
    {
      jclass cls = env->getClass(initializeClass);
      return Long(env->callStaticObjectMethod(cls, mids$[mid_valueOf_212f058c], a0.this$, a1));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Long_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Long_init_(t_Long *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Long_bitCount(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_byteValue(t_Long *self, PyObject *args);
    static PyObject *t_Long_compareTo(t_Long *self, PyObject *arg);
    static PyObject *t_Long_decode(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_doubleValue(t_Long *self, PyObject *args);
    static PyObject *t_Long_equals(t_Long *self, PyObject *args);
    static PyObject *t_Long_floatValue(t_Long *self, PyObject *args);
    static PyObject *t_Long_getLong(PyTypeObject *type, PyObject *args);
    static PyObject *t_Long_hashCode(t_Long *self, PyObject *args);
    static PyObject *t_Long_highestOneBit(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_intValue(t_Long *self, PyObject *args);
    static PyObject *t_Long_longValue(t_Long *self, PyObject *args);
    static PyObject *t_Long_lowestOneBit(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_parseLong(PyTypeObject *type, PyObject *args);
    static PyObject *t_Long_reverse(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_reverseBytes(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_rotateLeft(PyTypeObject *type, PyObject *args);
    static PyObject *t_Long_rotateRight(PyTypeObject *type, PyObject *args);
    static PyObject *t_Long_shortValue(t_Long *self, PyObject *args);
    static PyObject *t_Long_signum(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_toBinaryString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_toHexString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_toOctalString(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Long_toString(t_Long *self, PyObject *args);
    static PyObject *t_Long_toString_(PyTypeObject *type, PyObject *args);
    static PyObject *t_Long_valueOf(PyTypeObject *type, PyObject *args);

    static PyMethodDef t_Long__methods_[] = {
      DECLARE_METHOD(t_Long, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, bitCount, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, byteValue, METH_VARARGS),
      DECLARE_METHOD(t_Long, compareTo, METH_O),
      DECLARE_METHOD(t_Long, decode, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, doubleValue, METH_VARARGS),
      DECLARE_METHOD(t_Long, equals, METH_VARARGS),
      DECLARE_METHOD(t_Long, floatValue, METH_VARARGS),
      DECLARE_METHOD(t_Long, getLong, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Long, hashCode, METH_VARARGS),
      DECLARE_METHOD(t_Long, highestOneBit, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, intValue, METH_VARARGS),
      DECLARE_METHOD(t_Long, longValue, METH_VARARGS),
      DECLARE_METHOD(t_Long, lowestOneBit, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, numberOfLeadingZeros, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, numberOfTrailingZeros, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, parseLong, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Long, reverse, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, reverseBytes, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, rotateLeft, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Long, rotateRight, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Long, shortValue, METH_VARARGS),
      DECLARE_METHOD(t_Long, signum, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, toBinaryString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, toHexString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, toOctalString, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Long, toString, METH_VARARGS),
      DECLARE_METHOD(t_Long, toString_, METH_VARARGS | METH_CLASS),
      DECLARE_METHOD(t_Long, valueOf, METH_VARARGS | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Long, t_Long, ::java::lang::Number, Long, t_Long_init_, 0, 0, 0, 0, 0);

    void t_Long::install(PyObject *module)
    {
      installType(&PY_TYPE(Long), module, "Long", 0);
    }

    void t_Long::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "class_", make_descriptor(Long::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "wrapfn_", make_descriptor(unboxLong));
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "boxfn_", make_descriptor(boxLong));
      env->getClass(Long::initializeClass);
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "MAX_VALUE", make_descriptor(Long::MAX_VALUE));
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "MIN_VALUE", make_descriptor(Long::MIN_VALUE));
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "SIZE", make_descriptor(Long::SIZE));
      PyDict_SetItemString(PY_TYPE(Long).tp_dict, "TYPE", make_descriptor(::java::lang::t_Class::wrap_Object(*Long::TYPE)));
    }

    static PyObject *t_Long_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Long::initializeClass, 1)))
        return NULL;
      return t_Long::wrap_Object(Long(((t_Long *) arg)->object.this$));
    }
    static PyObject *t_Long_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Long::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Long_init_(t_Long *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jlong a0;
          Long object((jobject) NULL);

          if (!parseArgs(args, "J", &a0))
          {
            INT_CALL(object = Long(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Long object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = Long(a0));
            self->object = object;
            break;
          }
        }
       default:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_Long_bitCount(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jint result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::bitCount(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "bitCount", arg);
      return NULL;
    }

    static PyObject *t_Long_byteValue(t_Long *self, PyObject *args)
    {
      jbyte result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.byteValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "byteValue", args, 2);
    }

    static PyObject *t_Long_compareTo(t_Long *self, PyObject *arg)
    {
      Long a0((jobject) NULL);
      jint result;

      if (!parseArg(arg, "O", &::java::lang::PY_TYPE(Long), &a0))
      {
        OBJ_CALL(result = self->object.compareTo(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "compareTo", arg);
      return NULL;
    }

    static PyObject *t_Long_decode(PyTypeObject *type, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      Long result((jobject) NULL);

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::decode(a0));
        return t_Long::wrap_Object(result);
      }

      PyErr_SetArgsError(type, "decode", arg);
      return NULL;
    }

    static PyObject *t_Long_doubleValue(t_Long *self, PyObject *args)
    {
      jdouble result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.doubleValue());
        return PyFloat_FromDouble((double) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "doubleValue", args, 2);
    }

    static PyObject *t_Long_equals(t_Long *self, PyObject *args)
    {
      ::java::lang::Object a0((jobject) NULL);
      jboolean result;

      if (!parseArgs(args, "o", &a0))
      {
        OBJ_CALL(result = self->object.equals(a0));
        Py_RETURN_BOOL(result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "equals", args, 2);
    }

    static PyObject *t_Long_floatValue(t_Long *self, PyObject *args)
    {
      jfloat result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.floatValue());
        return PyFloat_FromDouble((double) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "floatValue", args, 2);
    }

    static PyObject *t_Long_getLong(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          Long result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Long::getLong(a0));
            return t_Long::wrap_Object(result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jlong a1;
          Long result((jobject) NULL);

          if (!parseArgs(args, "sJ", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Long::getLong(a0, a1));
            return t_Long::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Long a1((jobject) NULL);
          Long result((jobject) NULL);

          if (!parseArgs(args, "sO", &::java::lang::PY_TYPE(Long), &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Long::getLong(a0, a1));
            return t_Long::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "getLong", args);
      return NULL;
    }

    static PyObject *t_Long_hashCode(t_Long *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.hashCode());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "hashCode", args, 2);
    }

    static PyObject *t_Long_highestOneBit(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jlong result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::highestOneBit(a0));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "highestOneBit", arg);
      return NULL;
    }

    static PyObject *t_Long_intValue(t_Long *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.intValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "intValue", args, 2);
    }

    static PyObject *t_Long_longValue(t_Long *self, PyObject *args)
    {
      jlong result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.longValue());
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "longValue", args, 2);
    }

    static PyObject *t_Long_lowestOneBit(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jlong result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::lowestOneBit(a0));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "lowestOneBit", arg);
      return NULL;
    }

    static PyObject *t_Long_numberOfLeadingZeros(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jint result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::numberOfLeadingZeros(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "numberOfLeadingZeros", arg);
      return NULL;
    }

    static PyObject *t_Long_numberOfTrailingZeros(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jint result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::numberOfTrailingZeros(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "numberOfTrailingZeros", arg);
      return NULL;
    }

    static PyObject *t_Long_parseLong(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jlong result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Long::parseLong(a0));
            return PyLong_FromLongLong((PY_LONG_LONG) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jlong result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Long::parseLong(a0, a1));
            return PyLong_FromLongLong((PY_LONG_LONG) result);
          }
        }
      }

      PyErr_SetArgsError(type, "parseLong", args);
      return NULL;
    }

    static PyObject *t_Long_reverse(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jlong result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::reverse(a0));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "reverse", arg);
      return NULL;
    }

    static PyObject *t_Long_reverseBytes(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jlong result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::reverseBytes(a0));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "reverseBytes", arg);
      return NULL;
    }

    static PyObject *t_Long_rotateLeft(PyTypeObject *type, PyObject *args)
    {
      jlong a0;
      jint a1;
      jlong result;

      if (!parseArgs(args, "JI", &a0, &a1))
      {
        OBJ_CALL(result = ::java::lang::Long::rotateLeft(a0, a1));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "rotateLeft", args);
      return NULL;
    }

    static PyObject *t_Long_rotateRight(PyTypeObject *type, PyObject *args)
    {
      jlong a0;
      jint a1;
      jlong result;

      if (!parseArgs(args, "JI", &a0, &a1))
      {
        OBJ_CALL(result = ::java::lang::Long::rotateRight(a0, a1));
        return PyLong_FromLongLong((PY_LONG_LONG) result);
      }

      PyErr_SetArgsError(type, "rotateRight", args);
      return NULL;
    }

    static PyObject *t_Long_shortValue(t_Long *self, PyObject *args)
    {
      jshort result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.shortValue());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "shortValue", args, 2);
    }

    static PyObject *t_Long_signum(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      jint result;

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::signum(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError(type, "signum", arg);
      return NULL;
    }

    static PyObject *t_Long_toBinaryString(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::toBinaryString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toBinaryString", arg);
      return NULL;
    }

    static PyObject *t_Long_toHexString(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::toHexString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toHexString", arg);
      return NULL;
    }

    static PyObject *t_Long_toOctalString(PyTypeObject *type, PyObject *arg)
    {
      jlong a0;
      ::java::lang::String result((jobject) NULL);

      if (!parseArg(arg, "J", &a0))
      {
        OBJ_CALL(result = ::java::lang::Long::toOctalString(a0));
        return j2p(result);
      }

      PyErr_SetArgsError(type, "toOctalString", arg);
      return NULL;
    }

    static PyObject *t_Long_toString(t_Long *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Long), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_Long_toString_(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jlong a0;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "J", &a0))
          {
            OBJ_CALL(result = ::java::lang::Long::toString(a0));
            return j2p(result);
          }
        }
        break;
       case 2:
        {
          jlong a0;
          jint a1;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "JI", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Long::toString(a0, a1));
            return j2p(result);
          }
        }
      }

      PyErr_SetArgsError(type, "toString_", args);
      return NULL;
    }

    static PyObject *t_Long_valueOf(PyTypeObject *type, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jlong a0;
          Long result((jobject) NULL);

          if (!parseArgs(args, "J", &a0))
          {
            OBJ_CALL(result = ::java::lang::Long::valueOf(a0));
            return t_Long::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          Long result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = ::java::lang::Long::valueOf(a0));
            return t_Long::wrap_Object(result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          Long result((jobject) NULL);

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = ::java::lang::Long::valueOf(a0, a1));
            return t_Long::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError(type, "valueOf", args);
      return NULL;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Throwable.h"
#include "java/lang/StackTraceElement.h"
#include "java/io/PrintWriter.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Throwable::class$ = NULL;
    jmethodID *Throwable::mids$ = NULL;
    bool Throwable::live$ = false;

    jclass Throwable::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Throwable");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
        mids$[mid_fillInStackTrace_9a29189d] = env->getMethodID(cls, "fillInStackTrace", "()Ljava/lang/Throwable;");
        mids$[mid_getCause_9a29189d] = env->getMethodID(cls, "getCause", "()Ljava/lang/Throwable;");
        mids$[mid_getLocalizedMessage_14c7b5c5] = env->getMethodID(cls, "getLocalizedMessage", "()Ljava/lang/String;");
        mids$[mid_getMessage_14c7b5c5] = env->getMethodID(cls, "getMessage", "()Ljava/lang/String;");
        mids$[mid_getStackTrace_25f1f6aa] = env->getMethodID(cls, "getStackTrace", "()[Ljava/lang/StackTraceElement;");
        mids$[mid_initCause_dabad90f] = env->getMethodID(cls, "initCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;");
        mids$[mid_printStackTrace_54c6a166] = env->getMethodID(cls, "printStackTrace", "()V");
        mids$[mid_printStackTrace_82fffd94] = env->getMethodID(cls, "printStackTrace", "(Ljava/io/PrintWriter;)V");
        mids$[mid_setStackTrace_3d8798bf] = env->getMethodID(cls, "setStackTrace", "([Ljava/lang/StackTraceElement;)V");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Throwable::Throwable() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    Throwable::Throwable(const ::java::lang::String & a0) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    Throwable::Throwable(const ::java::lang::String & a0, const Throwable & a1) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}

    Throwable Throwable::fillInStackTrace() const
    {
      return Throwable(env->callObjectMethod(this$, mids$[mid_fillInStackTrace_9a29189d]));
    }

    Throwable Throwable::getCause() const
    {
      return Throwable(env->callObjectMethod(this$, mids$[mid_getCause_9a29189d]));
    }

    ::java::lang::String Throwable::getLocalizedMessage() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getLocalizedMessage_14c7b5c5]));
    }

    ::java::lang::String Throwable::getMessage() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getMessage_14c7b5c5]));
    }

    JArray< ::java::lang::StackTraceElement > Throwable::getStackTrace() const
    {
      return JArray< ::java::lang::StackTraceElement >(env->callObjectMethod(this$, mids$[mid_getStackTrace_25f1f6aa]));
    }

    Throwable Throwable::initCause(const Throwable & a0) const
    {
      return Throwable(env->callObjectMethod(this$, mids$[mid_initCause_dabad90f], a0.this$));
    }

    void Throwable::printStackTrace() const
    {
      env->callVoidMethod(this$, mids$[mid_printStackTrace_54c6a166]);
    }

    void Throwable::printStackTrace(const ::java::io::PrintWriter & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_printStackTrace_82fffd94], a0.this$);
    }

    void Throwable::setStackTrace(const JArray< ::java::lang::StackTraceElement > & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setStackTrace_3d8798bf], a0.this$);
    }

    ::java::lang::String Throwable::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Throwable_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Throwable_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Throwable_init_(t_Throwable *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Throwable_fillInStackTrace(t_Throwable *self);
    static PyObject *t_Throwable_getCause(t_Throwable *self);
    static PyObject *t_Throwable_getLocalizedMessage(t_Throwable *self);
    static PyObject *t_Throwable_getMessage(t_Throwable *self);
    static PyObject *t_Throwable_getStackTrace(t_Throwable *self);
    static PyObject *t_Throwable_initCause(t_Throwable *self, PyObject *arg);
    static PyObject *t_Throwable_printStackTrace(t_Throwable *self, PyObject *args);
    static PyObject *t_Throwable_setStackTrace(t_Throwable *self, PyObject *arg);
    static PyObject *t_Throwable_toString(t_Throwable *self, PyObject *args);
    static PyObject *t_Throwable_get__cause(t_Throwable *self, void *data);
    static PyObject *t_Throwable_get__localizedMessage(t_Throwable *self, void *data);
    static PyObject *t_Throwable_get__message(t_Throwable *self, void *data);
    static PyObject *t_Throwable_get__stackTrace(t_Throwable *self, void *data);
    static int t_Throwable_set__stackTrace(t_Throwable *self, PyObject *arg, void *data);
    static PyGetSetDef t_Throwable__fields_[] = {
      DECLARE_GET_FIELD(t_Throwable, cause),
      DECLARE_GET_FIELD(t_Throwable, localizedMessage),
      DECLARE_GET_FIELD(t_Throwable, message),
      DECLARE_GETSET_FIELD(t_Throwable, stackTrace),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Throwable__methods_[] = {
      DECLARE_METHOD(t_Throwable, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Throwable, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Throwable, fillInStackTrace, METH_NOARGS),
      DECLARE_METHOD(t_Throwable, getCause, METH_NOARGS),
      DECLARE_METHOD(t_Throwable, getLocalizedMessage, METH_NOARGS),
      DECLARE_METHOD(t_Throwable, getMessage, METH_NOARGS),
      DECLARE_METHOD(t_Throwable, getStackTrace, METH_NOARGS),
      DECLARE_METHOD(t_Throwable, initCause, METH_O),
      DECLARE_METHOD(t_Throwable, printStackTrace, METH_VARARGS),
      DECLARE_METHOD(t_Throwable, setStackTrace, METH_O),
      DECLARE_METHOD(t_Throwable, toString, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Throwable, t_Throwable, ::java::lang::Object, Throwable, t_Throwable_init_, 0, 0, t_Throwable__fields_, 0, 0);

    void t_Throwable::install(PyObject *module)
    {
      installType(&PY_TYPE(Throwable), module, "Throwable", 0);
    }

    void t_Throwable::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Throwable).tp_dict, "class_", make_descriptor(Throwable::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Throwable).tp_dict, "wrapfn_", make_descriptor(t_Throwable::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Throwable).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Throwable_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Throwable::initializeClass, 1)))
        return NULL;
      return t_Throwable::wrap_Object(Throwable(((t_Throwable *) arg)->object.this$));
    }
    static PyObject *t_Throwable_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Throwable::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Throwable_init_(t_Throwable *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          Throwable object((jobject) NULL);

          INT_CALL(object = Throwable());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          Throwable object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = Throwable(a0));
            self->object = object;
            break;
          }
        }
        goto err;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          Throwable a1((jobject) NULL);
          Throwable object((jobject) NULL);

          if (!parseArgs(args, "sk", Throwable::initializeClass, &a0, &a1))
          {
            INT_CALL(object = Throwable(a0, a1));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_Throwable_fillInStackTrace(t_Throwable *self)
    {
      Throwable result((jobject) NULL);
      OBJ_CALL(result = self->object.fillInStackTrace());
      return t_Throwable::wrap_Object(result);
    }

    static PyObject *t_Throwable_getCause(t_Throwable *self)
    {
      Throwable result((jobject) NULL);
      OBJ_CALL(result = self->object.getCause());
      return t_Throwable::wrap_Object(result);
    }

    static PyObject *t_Throwable_getLocalizedMessage(t_Throwable *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getLocalizedMessage());
      return j2p(result);
    }

    static PyObject *t_Throwable_getMessage(t_Throwable *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getMessage());
      return j2p(result);
    }

    static PyObject *t_Throwable_getStackTrace(t_Throwable *self)
    {
      JArray< ::java::lang::StackTraceElement > result((jobject) NULL);
      OBJ_CALL(result = self->object.getStackTrace());
      return JArray<jobject>(result.this$).wrap(::java::lang::t_StackTraceElement::wrap_jobject);
    }

    static PyObject *t_Throwable_initCause(t_Throwable *self, PyObject *arg)
    {
      Throwable a0((jobject) NULL);
      Throwable result((jobject) NULL);

      if (!parseArg(arg, "k", Throwable::initializeClass, &a0))
      {
        OBJ_CALL(result = self->object.initCause(a0));
        return t_Throwable::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "initCause", arg);
      return NULL;
    }

    static PyObject *t_Throwable_printStackTrace(t_Throwable *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          OBJ_CALL(self->object.printStackTrace());
          Py_RETURN_NONE;
        }
        break;
       case 1:
        {
          ::java::io::PrintWriter a0((jobject) NULL);

          if (!parseArgs(args, "k", ::java::io::PrintWriter::initializeClass, &a0))
          {
            OBJ_CALL(self->object.printStackTrace(a0));
            Py_RETURN_NONE;
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "printStackTrace", args);
      return NULL;
    }

    static PyObject *t_Throwable_setStackTrace(t_Throwable *self, PyObject *arg)
    {
      JArray< ::java::lang::StackTraceElement > a0((jobject) NULL);

      if (!parseArg(arg, "[k", ::java::lang::StackTraceElement::initializeClass, &a0))
      {
        OBJ_CALL(self->object.setStackTrace(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setStackTrace", arg);
      return NULL;
    }

    static PyObject *t_Throwable_toString(t_Throwable *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Throwable), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_Throwable_get__cause(t_Throwable *self, void *data)
    {
      Throwable value((jobject) NULL);
      OBJ_CALL(value = self->object.getCause());
      return t_Throwable::wrap_Object(value);
    }

    static PyObject *t_Throwable_get__localizedMessage(t_Throwable *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getLocalizedMessage());
      return j2p(value);
    }

    static PyObject *t_Throwable_get__message(t_Throwable *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getMessage());
      return j2p(value);
    }

    static PyObject *t_Throwable_get__stackTrace(t_Throwable *self, void *data)
    {
      JArray< ::java::lang::StackTraceElement > value((jobject) NULL);
      OBJ_CALL(value = self->object.getStackTrace());
      return JArray<jobject>(value.this$).wrap(::java::lang::t_StackTraceElement::wrap_jobject);
    }
    static int t_Throwable_set__stackTrace(t_Throwable *self, PyObject *arg, void *data)
    {
      {
        JArray< ::java::lang::StackTraceElement > value((jobject) NULL);
        if (!parseArg(arg, "[k", ::java::lang::StackTraceElement::initializeClass, &value))
        {
          INT_CALL(self->object.setStackTrace(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "stackTrace", arg);
      return -1;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/hmm/HMMFactory.h"
#include "stallone/api/function/IParametricFunction.h"
#include "stallone/api/hmm/IExpectationMaximization.h"
#include "stallone/api/hmm/IHMMParameters.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/hmm/IHMMOptimizer.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace hmm {

      ::java::lang::Class *HMMFactory::class$ = NULL;
      jmethodID *HMMFactory::mids$ = NULL;
      bool HMMFactory::live$ = false;

      jclass HMMFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/hmm/HMMFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_parameters_f9c1f285] = env->getMethodID(cls, "parameters", "(IZZ)Lstallone/api/hmm/IHMMParameters;");
          mids$[mid_parameters_52a2b433] = env->getMethodID(cls, "parameters", "(IZZLstallone/api/function/IParametricFunction;)Lstallone/api/hmm/IHMMParameters;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      HMMFactory::HMMFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::hmm::IHMMParameters HMMFactory::parameters(jint a0, jboolean a1, jboolean a2) const
      {
        return ::stallone::api::hmm::IHMMParameters(env->callObjectMethod(this$, mids$[mid_parameters_f9c1f285], a0, a1, a2));
      }

      ::stallone::api::hmm::IHMMParameters HMMFactory::parameters(jint a0, jboolean a1, jboolean a2, const ::stallone::api::function::IParametricFunction & a3) const
      {
        return ::stallone::api::hmm::IHMMParameters(env->callObjectMethod(this$, mids$[mid_parameters_52a2b433], a0, a1, a2, a3.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace hmm {
      static PyObject *t_HMMFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_HMMFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_HMMFactory_init_(t_HMMFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_HMMFactory_parameters(t_HMMFactory *self, PyObject *args);

      static PyMethodDef t_HMMFactory__methods_[] = {
        DECLARE_METHOD(t_HMMFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_HMMFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_HMMFactory, parameters, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(HMMFactory, t_HMMFactory, ::java::lang::Object, HMMFactory, t_HMMFactory_init_, 0, 0, 0, 0, 0);

      void t_HMMFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(HMMFactory), module, "HMMFactory", 0);
      }

      void t_HMMFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(HMMFactory).tp_dict, "class_", make_descriptor(HMMFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(HMMFactory).tp_dict, "wrapfn_", make_descriptor(t_HMMFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(HMMFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_HMMFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, HMMFactory::initializeClass, 1)))
          return NULL;
        return t_HMMFactory::wrap_Object(HMMFactory(((t_HMMFactory *) arg)->object.this$));
      }
      static PyObject *t_HMMFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, HMMFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_HMMFactory_init_(t_HMMFactory *self, PyObject *args, PyObject *kwds)
      {
        HMMFactory object((jobject) NULL);

        INT_CALL(object = HMMFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_HMMFactory_parameters(t_HMMFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 3:
          {
            jint a0;
            jboolean a1;
            jboolean a2;
            ::stallone::api::hmm::IHMMParameters result((jobject) NULL);

            if (!parseArgs(args, "IZZ", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.parameters(a0, a1, a2));
              return ::stallone::api::hmm::t_IHMMParameters::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            jint a0;
            jboolean a1;
            jboolean a2;
            ::stallone::api::function::IParametricFunction a3((jobject) NULL);
            ::stallone::api::hmm::IHMMParameters result((jobject) NULL);

            if (!parseArgs(args, "IZZk", ::stallone::api::function::IParametricFunction::initializeClass, &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.parameters(a0, a1, a2, a3));
              return ::stallone::api::hmm::t_IHMMParameters::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "parameters", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/complex/IComplexArray.h"
#include "stallone/api/complex/IComplexIterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace complex {

      ::java::lang::Class *IComplexArray::class$ = NULL;
      jmethodID *IComplexArray::mids$ = NULL;
      bool IComplexArray::live$ = false;

      jclass IComplexArray::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/complex/IComplexArray");

          mids$ = new jmethodID[max_mid];
          mids$[mid_complexIterator_bbde838d] = env->getMethodID(cls, "complexIterator", "()Lstallone/api/complex/IComplexIterator;");
          mids$[mid_copy_d54418bb] = env->getMethodID(cls, "copy", "()Lstallone/api/complex/IComplexArray;");
          mids$[mid_copyFrom_ce2e75ca] = env->getMethodID(cls, "copyFrom", "(Lstallone/api/complex/IComplexArray;)V");
          mids$[mid_copyInto_ce2e75ca] = env->getMethodID(cls, "copyInto", "(Lstallone/api/complex/IComplexArray;)V");
          mids$[mid_create_f6210079] = env->getMethodID(cls, "create", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_create_74a6154f] = env->getMethodID(cls, "create", "(II)Lstallone/api/complex/IComplexArray;");
          mids$[mid_getIm_39c7bd2e] = env->getMethodID(cls, "getIm", "(I)D");
          mids$[mid_getIm_d8d154b4] = env->getMethodID(cls, "getIm", "(II)D");
          mids$[mid_getImaginaryArray_dab10e78] = env->getMethodID(cls, "getImaginaryArray", "()[D");
          mids$[mid_getImaginaryColumn_b4292e9e] = env->getMethodID(cls, "getImaginaryColumn", "(I)[D");
          mids$[mid_getImaginaryRow_b4292e9e] = env->getMethodID(cls, "getImaginaryRow", "(I)[D");
          mids$[mid_getImaginaryTable_b9d949a8] = env->getMethodID(cls, "getImaginaryTable", "()[[D");
          mids$[mid_getRe_39c7bd2e] = env->getMethodID(cls, "getRe", "(I)D");
          mids$[mid_getRe_d8d154b4] = env->getMethodID(cls, "getRe", "(II)D");
          mids$[mid_getRealArray_dab10e78] = env->getMethodID(cls, "getRealArray", "()[D");
          mids$[mid_getRealColumn_b4292e9e] = env->getMethodID(cls, "getRealColumn", "(I)[D");
          mids$[mid_getRealRow_b4292e9e] = env->getMethodID(cls, "getRealRow", "(I)[D");
          mids$[mid_getRealTable_b9d949a8] = env->getMethodID(cls, "getRealTable", "()[[D");
          mids$[mid_isReal_54c6a16a] = env->getMethodID(cls, "isReal", "()Z");
          mids$[mid_nonzeroComplexIterator_bbde838d] = env->getMethodID(cls, "nonzeroComplexIterator", "()Lstallone/api/complex/IComplexIterator;");
          mids$[mid_set_6a0b612e] = env->getMethodID(cls, "set", "(IDD)V");
          mids$[mid_set_8b16f164] = env->getMethodID(cls, "set", "(IIDD)V");
          mids$[mid_setIm_5aa51c57] = env->getMethodID(cls, "setIm", "(ID)V");
          mids$[mid_setIm_514fa3b5] = env->getMethodID(cls, "setIm", "(IID)V");
          mids$[mid_setRe_5aa51c57] = env->getMethodID(cls, "setRe", "(ID)V");
          mids$[mid_setRe_514fa3b5] = env->getMethodID(cls, "setRe", "(IID)V");
          mids$[mid_view_eb1c1787] = env->getMethodID(cls, "view", "([I[I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_viewBlock_9d679403] = env->getMethodID(cls, "viewBlock", "(IIII)Lstallone/api/complex/IComplexArray;");
          mids$[mid_viewColumn_f6210079] = env->getMethodID(cls, "viewColumn", "(I)Lstallone/api/complex/IComplexArray;");
          mids$[mid_viewImaginary_1d53e353] = env->getMethodID(cls, "viewImaginary", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_viewReal_1d53e353] = env->getMethodID(cls, "viewReal", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_viewRow_f6210079] = env->getMethodID(cls, "viewRow", "(I)Lstallone/api/complex/IComplexArray;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::complex::IComplexIterator IComplexArray::complexIterator() const
      {
        return ::stallone::api::complex::IComplexIterator(env->callObjectMethod(this$, mids$[mid_complexIterator_bbde838d]));
      }

      IComplexArray IComplexArray::copy() const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_copy_d54418bb]));
      }

      void IComplexArray::copyFrom(const IComplexArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_copyFrom_ce2e75ca], a0.this$);
      }

      void IComplexArray::copyInto(const IComplexArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_copyInto_ce2e75ca], a0.this$);
      }

      IComplexArray IComplexArray::create(jint a0) const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_create_f6210079], a0));
      }

      IComplexArray IComplexArray::create(jint a0, jint a1) const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_create_74a6154f], a0, a1));
      }

      jdouble IComplexArray::getIm(jint a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_getIm_39c7bd2e], a0);
      }

      jdouble IComplexArray::getIm(jint a0, jint a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_getIm_d8d154b4], a0, a1);
      }

      JArray< jdouble > IComplexArray::getImaginaryArray() const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getImaginaryArray_dab10e78]));
      }

      JArray< jdouble > IComplexArray::getImaginaryColumn(jint a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getImaginaryColumn_b4292e9e], a0));
      }

      JArray< jdouble > IComplexArray::getImaginaryRow(jint a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getImaginaryRow_b4292e9e], a0));
      }

      JArray< JArray< jdouble > > IComplexArray::getImaginaryTable() const
      {
        return JArray< JArray< jdouble > >(env->callObjectMethod(this$, mids$[mid_getImaginaryTable_b9d949a8]));
      }

      jdouble IComplexArray::getRe(jint a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_getRe_39c7bd2e], a0);
      }

      jdouble IComplexArray::getRe(jint a0, jint a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_getRe_d8d154b4], a0, a1);
      }

      JArray< jdouble > IComplexArray::getRealArray() const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getRealArray_dab10e78]));
      }

      JArray< jdouble > IComplexArray::getRealColumn(jint a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getRealColumn_b4292e9e], a0));
      }

      JArray< jdouble > IComplexArray::getRealRow(jint a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getRealRow_b4292e9e], a0));
      }

      JArray< JArray< jdouble > > IComplexArray::getRealTable() const
      {
        return JArray< JArray< jdouble > >(env->callObjectMethod(this$, mids$[mid_getRealTable_b9d949a8]));
      }

      jboolean IComplexArray::isReal() const
      {
        return env->callBooleanMethod(this$, mids$[mid_isReal_54c6a16a]);
      }

      ::stallone::api::complex::IComplexIterator IComplexArray::nonzeroComplexIterator() const
      {
        return ::stallone::api::complex::IComplexIterator(env->callObjectMethod(this$, mids$[mid_nonzeroComplexIterator_bbde838d]));
      }

      void IComplexArray::set(jint a0, jdouble a1, jdouble a2) const
      {
        env->callVoidMethod(this$, mids$[mid_set_6a0b612e], a0, a1, a2);
      }

      void IComplexArray::set(jint a0, jint a1, jdouble a2, jdouble a3) const
      {
        env->callVoidMethod(this$, mids$[mid_set_8b16f164], a0, a1, a2, a3);
      }

      void IComplexArray::setIm(jint a0, jdouble a1) const
      {
        env->callVoidMethod(this$, mids$[mid_setIm_5aa51c57], a0, a1);
      }

      void IComplexArray::setIm(jint a0, jint a1, jdouble a2) const
      {
        env->callVoidMethod(this$, mids$[mid_setIm_514fa3b5], a0, a1, a2);
      }

      void IComplexArray::setRe(jint a0, jdouble a1) const
      {
        env->callVoidMethod(this$, mids$[mid_setRe_5aa51c57], a0, a1);
      }

      void IComplexArray::setRe(jint a0, jint a1, jdouble a2) const
      {
        env->callVoidMethod(this$, mids$[mid_setRe_514fa3b5], a0, a1, a2);
      }

      IComplexArray IComplexArray::view(const JArray< jint > & a0, const JArray< jint > & a1) const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_view_eb1c1787], a0.this$, a1.this$));
      }

      IComplexArray IComplexArray::viewBlock(jint a0, jint a1, jint a2, jint a3) const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_viewBlock_9d679403], a0, a1, a2, a3));
      }

      IComplexArray IComplexArray::viewColumn(jint a0) const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_viewColumn_f6210079], a0));
      }

      ::stallone::api::doubles::IDoubleArray IComplexArray::viewImaginary() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_viewImaginary_1d53e353]));
      }

      ::stallone::api::doubles::IDoubleArray IComplexArray::viewReal() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_viewReal_1d53e353]));
      }

      IComplexArray IComplexArray::viewRow(jint a0) const
      {
        return IComplexArray(env->callObjectMethod(this$, mids$[mid_viewRow_f6210079], a0));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace complex {
      static PyObject *t_IComplexArray_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IComplexArray_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IComplexArray_complexIterator(t_IComplexArray *self);
      static PyObject *t_IComplexArray_copy(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_copyFrom(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_copyInto(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_create(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_getIm(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_getImaginaryArray(t_IComplexArray *self);
      static PyObject *t_IComplexArray_getImaginaryColumn(t_IComplexArray *self, PyObject *arg);
      static PyObject *t_IComplexArray_getImaginaryRow(t_IComplexArray *self, PyObject *arg);
      static PyObject *t_IComplexArray_getImaginaryTable(t_IComplexArray *self);
      static PyObject *t_IComplexArray_getRe(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_getRealArray(t_IComplexArray *self);
      static PyObject *t_IComplexArray_getRealColumn(t_IComplexArray *self, PyObject *arg);
      static PyObject *t_IComplexArray_getRealRow(t_IComplexArray *self, PyObject *arg);
      static PyObject *t_IComplexArray_getRealTable(t_IComplexArray *self);
      static PyObject *t_IComplexArray_isReal(t_IComplexArray *self);
      static PyObject *t_IComplexArray_nonzeroComplexIterator(t_IComplexArray *self);
      static PyObject *t_IComplexArray_set(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_setIm(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_setRe(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_view(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_viewBlock(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_viewColumn(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_viewImaginary(t_IComplexArray *self);
      static PyObject *t_IComplexArray_viewReal(t_IComplexArray *self);
      static PyObject *t_IComplexArray_viewRow(t_IComplexArray *self, PyObject *args);
      static PyObject *t_IComplexArray_get__imaginaryArray(t_IComplexArray *self, void *data);
      static PyObject *t_IComplexArray_get__imaginaryTable(t_IComplexArray *self, void *data);
      static PyObject *t_IComplexArray_get__real(t_IComplexArray *self, void *data);
      static PyObject *t_IComplexArray_get__realArray(t_IComplexArray *self, void *data);
      static PyObject *t_IComplexArray_get__realTable(t_IComplexArray *self, void *data);
      static PyGetSetDef t_IComplexArray__fields_[] = {
        DECLARE_GET_FIELD(t_IComplexArray, imaginaryArray),
        DECLARE_GET_FIELD(t_IComplexArray, imaginaryTable),
        DECLARE_GET_FIELD(t_IComplexArray, real),
        DECLARE_GET_FIELD(t_IComplexArray, realArray),
        DECLARE_GET_FIELD(t_IComplexArray, realTable),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IComplexArray__methods_[] = {
        DECLARE_METHOD(t_IComplexArray, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IComplexArray, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IComplexArray, complexIterator, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, copy, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, copyFrom, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, copyInto, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, create, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, getIm, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, getImaginaryArray, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, getImaginaryColumn, METH_O),
        DECLARE_METHOD(t_IComplexArray, getImaginaryRow, METH_O),
        DECLARE_METHOD(t_IComplexArray, getImaginaryTable, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, getRe, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, getRealArray, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, getRealColumn, METH_O),
        DECLARE_METHOD(t_IComplexArray, getRealRow, METH_O),
        DECLARE_METHOD(t_IComplexArray, getRealTable, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, isReal, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, nonzeroComplexIterator, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, set, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, setIm, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, setRe, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, view, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, viewBlock, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, viewColumn, METH_VARARGS),
        DECLARE_METHOD(t_IComplexArray, viewImaginary, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, viewReal, METH_NOARGS),
        DECLARE_METHOD(t_IComplexArray, viewRow, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IComplexArray, t_IComplexArray, ::stallone::api::doubles::IDoubleArray, IComplexArray, abstract_init, 0, 0, t_IComplexArray__fields_, 0, 0);

      void t_IComplexArray::install(PyObject *module)
      {
        installType(&PY_TYPE(IComplexArray), module, "IComplexArray", 0);
      }

      void t_IComplexArray::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IComplexArray).tp_dict, "class_", make_descriptor(IComplexArray::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IComplexArray).tp_dict, "wrapfn_", make_descriptor(t_IComplexArray::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IComplexArray).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IComplexArray_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IComplexArray::initializeClass, 1)))
          return NULL;
        return t_IComplexArray::wrap_Object(IComplexArray(((t_IComplexArray *) arg)->object.this$));
      }
      static PyObject *t_IComplexArray_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IComplexArray::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IComplexArray_complexIterator(t_IComplexArray *self)
      {
        ::stallone::api::complex::IComplexIterator result((jobject) NULL);
        OBJ_CALL(result = self->object.complexIterator());
        return ::stallone::api::complex::t_IComplexIterator::wrap_Object(result);
      }

      static PyObject *t_IComplexArray_copy(t_IComplexArray *self, PyObject *args)
      {
        IComplexArray result((jobject) NULL);

        if (!parseArgs(args, ""))
        {
          OBJ_CALL(result = self->object.copy());
          return t_IComplexArray::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "copy", args, 2);
      }

      static PyObject *t_IComplexArray_copyFrom(t_IComplexArray *self, PyObject *args)
      {
        IComplexArray a0((jobject) NULL);

        if (!parseArgs(args, "k", IComplexArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.copyFrom(a0));
          Py_RETURN_NONE;
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "copyFrom", args, 2);
      }

      static PyObject *t_IComplexArray_copyInto(t_IComplexArray *self, PyObject *args)
      {
        IComplexArray a0((jobject) NULL);

        if (!parseArgs(args, "k", IComplexArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.copyInto(a0));
          Py_RETURN_NONE;
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "copyInto", args, 2);
      }

      static PyObject *t_IComplexArray_create(t_IComplexArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.create(a0));
              return t_IComplexArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            IComplexArray result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.create(a0, a1));
              return t_IComplexArray::wrap_Object(result);
            }
          }
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "create", args, 2);
      }

      static PyObject *t_IComplexArray_getIm(t_IComplexArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            jdouble result;

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.getIm(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            jdouble result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.getIm(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "getIm", args);
        return NULL;
      }

      static PyObject *t_IComplexArray_getImaginaryArray(t_IComplexArray *self)
      {
        JArray< jdouble > result((jobject) NULL);
        OBJ_CALL(result = self->object.getImaginaryArray());
        return result.wrap();
      }

      static PyObject *t_IComplexArray_getImaginaryColumn(t_IComplexArray *self, PyObject *arg)
      {
        jint a0;
        JArray< jdouble > result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getImaginaryColumn(a0));
          return result.wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getImaginaryColumn", arg);
        return NULL;
      }

      static PyObject *t_IComplexArray_getImaginaryRow(t_IComplexArray *self, PyObject *arg)
      {
        jint a0;
        JArray< jdouble > result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getImaginaryRow(a0));
          return result.wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getImaginaryRow", arg);
        return NULL;
      }

      static PyObject *t_IComplexArray_getImaginaryTable(t_IComplexArray *self)
      {
        JArray< JArray< jdouble > > result((jobject) NULL);
        OBJ_CALL(result = self->object.getImaginaryTable());
        return JArray<jobject>(result.this$).wrap(NULL);
      }

      static PyObject *t_IComplexArray_getRe(t_IComplexArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            jdouble result;

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.getRe(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            jdouble result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.getRe(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "getRe", args);
        return NULL;
      }

      static PyObject *t_IComplexArray_getRealArray(t_IComplexArray *self)
      {
        JArray< jdouble > result((jobject) NULL);
        OBJ_CALL(result = self->object.getRealArray());
        return result.wrap();
      }

      static PyObject *t_IComplexArray_getRealColumn(t_IComplexArray *self, PyObject *arg)
      {
        jint a0;
        JArray< jdouble > result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getRealColumn(a0));
          return result.wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getRealColumn", arg);
        return NULL;
      }

      static PyObject *t_IComplexArray_getRealRow(t_IComplexArray *self, PyObject *arg)
      {
        jint a0;
        JArray< jdouble > result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getRealRow(a0));
          return result.wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getRealRow", arg);
        return NULL;
      }

      static PyObject *t_IComplexArray_getRealTable(t_IComplexArray *self)
      {
        JArray< JArray< jdouble > > result((jobject) NULL);
        OBJ_CALL(result = self->object.getRealTable());
        return JArray<jobject>(result.this$).wrap(NULL);
      }

      static PyObject *t_IComplexArray_isReal(t_IComplexArray *self)
      {
        jboolean result;
        OBJ_CALL(result = self->object.isReal());
        Py_RETURN_BOOL(result);
      }

      static PyObject *t_IComplexArray_nonzeroComplexIterator(t_IComplexArray *self)
      {
        ::stallone::api::complex::IComplexIterator result((jobject) NULL);
        OBJ_CALL(result = self->object.nonzeroComplexIterator());
        return ::stallone::api::complex::t_IComplexIterator::wrap_Object(result);
      }

      static PyObject *t_IComplexArray_set(t_IComplexArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 3:
          {
            jint a0;
            jdouble a1;
            jdouble a2;

            if (!parseArgs(args, "IDD", &a0, &a1, &a2))
            {
              OBJ_CALL(self->object.set(a0, a1, a2));
              Py_RETURN_NONE;
            }
          }
          break;
         case 4:
          {
            jint a0;
            jint a1;
            jdouble a2;
            jdouble a3;

            if (!parseArgs(args, "IIDD", &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(self->object.set(a0, a1, a2, a3));
              Py_RETURN_NONE;
            }
          }
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "set", args, 2);
      }

      static PyObject *t_IComplexArray_setIm(t_IComplexArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jint a0;
            jdouble a1;

            if (!parseArgs(args, "ID", &a0, &a1))
            {
              OBJ_CALL(self->object.setIm(a0, a1));
              Py_RETURN_NONE;
            }
          }
          break;
         case 3:
          {
            jint a0;
            jint a1;
            jdouble a2;

            if (!parseArgs(args, "IID", &a0, &a1, &a2))
            {
              OBJ_CALL(self->object.setIm(a0, a1, a2));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "setIm", args);
        return NULL;
      }

      static PyObject *t_IComplexArray_setRe(t_IComplexArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jint a0;
            jdouble a1;

            if (!parseArgs(args, "ID", &a0, &a1))
            {
              OBJ_CALL(self->object.setRe(a0, a1));
              Py_RETURN_NONE;
            }
          }
          break;
         case 3:
          {
            jint a0;
            jint a1;
            jdouble a2;

            if (!parseArgs(args, "IID", &a0, &a1, &a2))
            {
              OBJ_CALL(self->object.setRe(a0, a1, a2));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "setRe", args);
        return NULL;
      }

      static PyObject *t_IComplexArray_view(t_IComplexArray *self, PyObject *args)
      {
        JArray< jint > a0((jobject) NULL);
        JArray< jint > a1((jobject) NULL);
        IComplexArray result((jobject) NULL);

        if (!parseArgs(args, "[I[I", &a0, &a1))
        {
          OBJ_CALL(result = self->object.view(a0, a1));
          return t_IComplexArray::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "view", args, 2);
      }

      static PyObject *t_IComplexArray_viewBlock(t_IComplexArray *self, PyObject *args)
      {
        jint a0;
        jint a1;
        jint a2;
        jint a3;
        IComplexArray result((jobject) NULL);

        if (!parseArgs(args, "IIII", &a0, &a1, &a2, &a3))
        {
          OBJ_CALL(result = self->object.viewBlock(a0, a1, a2, a3));
          return t_IComplexArray::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "viewBlock", args, 2);
      }

      static PyObject *t_IComplexArray_viewColumn(t_IComplexArray *self, PyObject *args)
      {
        jint a0;
        IComplexArray result((jobject) NULL);

        if (!parseArgs(args, "I", &a0))
        {
          OBJ_CALL(result = self->object.viewColumn(a0));
          return t_IComplexArray::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "viewColumn", args, 2);
      }

      static PyObject *t_IComplexArray_viewImaginary(t_IComplexArray *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.viewImaginary());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IComplexArray_viewReal(t_IComplexArray *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.viewReal());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IComplexArray_viewRow(t_IComplexArray *self, PyObject *args)
      {
        jint a0;
        IComplexArray result((jobject) NULL);

        if (!parseArgs(args, "I", &a0))
        {
          OBJ_CALL(result = self->object.viewRow(a0));
          return t_IComplexArray::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IComplexArray), (PyObject *) self, "viewRow", args, 2);
      }

      static PyObject *t_IComplexArray_get__imaginaryArray(t_IComplexArray *self, void *data)
      {
        JArray< jdouble > value((jobject) NULL);
        OBJ_CALL(value = self->object.getImaginaryArray());
        return value.wrap();
      }

      static PyObject *t_IComplexArray_get__imaginaryTable(t_IComplexArray *self, void *data)
      {
        JArray< JArray< jdouble > > value((jobject) NULL);
        OBJ_CALL(value = self->object.getImaginaryTable());
        return JArray<jobject>(value.this$).wrap(NULL);
      }

      static PyObject *t_IComplexArray_get__real(t_IComplexArray *self, void *data)
      {
        jboolean value;
        OBJ_CALL(value = self->object.isReal());
        Py_RETURN_BOOL(value);
      }

      static PyObject *t_IComplexArray_get__realArray(t_IComplexArray *self, void *data)
      {
        JArray< jdouble > value((jobject) NULL);
        OBJ_CALL(value = self->object.getRealArray());
        return value.wrap();
      }

      static PyObject *t_IComplexArray_get__realTable(t_IComplexArray *self, void *data)
      {
        JArray< JArray< jdouble > > value((jobject) NULL);
        OBJ_CALL(value = self->object.getRealTable());
        return JArray<jobject>(value.this$).wrap(NULL);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Number.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Number::class$ = NULL;
    jmethodID *Number::mids$ = NULL;
    bool Number::live$ = false;

    jclass Number::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Number");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_byteValue_54c6a172] = env->getMethodID(cls, "byteValue", "()B");
        mids$[mid_doubleValue_54c6a174] = env->getMethodID(cls, "doubleValue", "()D");
        mids$[mid_floatValue_54c6a176] = env->getMethodID(cls, "floatValue", "()F");
        mids$[mid_intValue_54c6a179] = env->getMethodID(cls, "intValue", "()I");
        mids$[mid_longValue_54c6a17a] = env->getMethodID(cls, "longValue", "()J");
        mids$[mid_shortValue_54c6a163] = env->getMethodID(cls, "shortValue", "()S");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Number::Number() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    jbyte Number::byteValue() const
    {
      return env->callByteMethod(this$, mids$[mid_byteValue_54c6a172]);
    }

    jdouble Number::doubleValue() const
    {
      return env->callDoubleMethod(this$, mids$[mid_doubleValue_54c6a174]);
    }

    jfloat Number::floatValue() const
    {
      return env->callFloatMethod(this$, mids$[mid_floatValue_54c6a176]);
    }

    jint Number::intValue() const
    {
      return env->callIntMethod(this$, mids$[mid_intValue_54c6a179]);
    }

    jlong Number::longValue() const
    {
      return env->callLongMethod(this$, mids$[mid_longValue_54c6a17a]);
    }

    jshort Number::shortValue() const
    {
      return env->callShortMethod(this$, mids$[mid_shortValue_54c6a163]);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Number_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Number_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Number_init_(t_Number *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Number_byteValue(t_Number *self);
    static PyObject *t_Number_doubleValue(t_Number *self);
    static PyObject *t_Number_floatValue(t_Number *self);
    static PyObject *t_Number_intValue(t_Number *self);
    static PyObject *t_Number_longValue(t_Number *self);
    static PyObject *t_Number_shortValue(t_Number *self);

    static PyMethodDef t_Number__methods_[] = {
      DECLARE_METHOD(t_Number, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Number, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Number, byteValue, METH_NOARGS),
      DECLARE_METHOD(t_Number, doubleValue, METH_NOARGS),
      DECLARE_METHOD(t_Number, floatValue, METH_NOARGS),
      DECLARE_METHOD(t_Number, intValue, METH_NOARGS),
      DECLARE_METHOD(t_Number, longValue, METH_NOARGS),
      DECLARE_METHOD(t_Number, shortValue, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Number, t_Number, ::java::lang::Object, Number, t_Number_init_, 0, 0, 0, 0, 0);

    void t_Number::install(PyObject *module)
    {
      installType(&PY_TYPE(Number), module, "Number", 0);
    }

    void t_Number::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Number).tp_dict, "class_", make_descriptor(Number::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Number).tp_dict, "wrapfn_", make_descriptor(t_Number::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Number).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Number_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Number::initializeClass, 1)))
        return NULL;
      return t_Number::wrap_Object(Number(((t_Number *) arg)->object.this$));
    }
    static PyObject *t_Number_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Number::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Number_init_(t_Number *self, PyObject *args, PyObject *kwds)
    {
      Number object((jobject) NULL);

      INT_CALL(object = Number());
      self->object = object;

      return 0;
    }

    static PyObject *t_Number_byteValue(t_Number *self)
    {
      jbyte result;
      OBJ_CALL(result = self->object.byteValue());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_Number_doubleValue(t_Number *self)
    {
      jdouble result;
      OBJ_CALL(result = self->object.doubleValue());
      return PyFloat_FromDouble((double) result);
    }

    static PyObject *t_Number_floatValue(t_Number *self)
    {
      jfloat result;
      OBJ_CALL(result = self->object.floatValue());
      return PyFloat_FromDouble((double) result);
    }

    static PyObject *t_Number_intValue(t_Number *self)
    {
      jint result;
      OBJ_CALL(result = self->object.intValue());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_Number_longValue(t_Number *self)
    {
      jlong result;
      OBJ_CALL(result = self->object.longValue());
      return PyLong_FromLongLong((PY_LONG_LONG) result);
    }

    static PyObject *t_Number_shortValue(t_Number *self)
    {
      jshort result;
      OBJ_CALL(result = self->object.shortValue());
      return PyInt_FromLong((long) result);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/graph/IIntGraph.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/graph/IIntEdge.h"
#include "stallone/api/ints/IIntIterator.h"
#include "java/util/Iterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace graph {

      ::java::lang::Class *IIntGraph::class$ = NULL;
      jmethodID *IIntGraph::mids$ = NULL;
      bool IIntGraph::live$ = false;

      jclass IIntGraph::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/graph/IIntGraph");

          mids$ = new jmethodID[max_mid];
          mids$[mid_contains_39c7bd30] = env->getMethodID(cls, "contains", "(I)Z");
          mids$[mid_contains_d8d154aa] = env->getMethodID(cls, "contains", "(II)Z");
          mids$[mid_edgeIterator_40858c90] = env->getMethodID(cls, "edgeIterator", "()Ljava/util/Iterator;");
          mids$[mid_getNodes_4ac77731] = env->getMethodID(cls, "getNodes", "()Lstallone/api/ints/IIntArray;");
          mids$[mid_neighborIterator_136bab09] = env->getMethodID(cls, "neighborIterator", "(I)Lstallone/api/ints/IIntIterator;");
          mids$[mid_nodeIterator_6c27215b] = env->getMethodID(cls, "nodeIterator", "()Lstallone/api/ints/IIntIterator;");
          mids$[mid_numberOfArcs_54c6a179] = env->getMethodID(cls, "numberOfArcs", "()I");
          mids$[mid_numberOfNodes_54c6a179] = env->getMethodID(cls, "numberOfNodes", "()I");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jboolean IIntGraph::contains(jint a0) const
      {
        return env->callBooleanMethod(this$, mids$[mid_contains_39c7bd30], a0);
      }

      jboolean IIntGraph::contains(jint a0, jint a1) const
      {
        return env->callBooleanMethod(this$, mids$[mid_contains_d8d154aa], a0, a1);
      }

      ::java::util::Iterator IIntGraph::edgeIterator() const
      {
        return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_edgeIterator_40858c90]));
      }

      ::stallone::api::ints::IIntArray IIntGraph::getNodes() const
      {
        return ::stallone::api::ints::IIntArray(env->callObjectMethod(this$, mids$[mid_getNodes_4ac77731]));
      }

      ::stallone::api::ints::IIntIterator IIntGraph::neighborIterator(jint a0) const
      {
        return ::stallone::api::ints::IIntIterator(env->callObjectMethod(this$, mids$[mid_neighborIterator_136bab09], a0));
      }

      ::stallone::api::ints::IIntIterator IIntGraph::nodeIterator() const
      {
        return ::stallone::api::ints::IIntIterator(env->callObjectMethod(this$, mids$[mid_nodeIterator_6c27215b]));
      }

      jint IIntGraph::numberOfArcs() const
      {
        return env->callIntMethod(this$, mids$[mid_numberOfArcs_54c6a179]);
      }

      jint IIntGraph::numberOfNodes() const
      {
        return env->callIntMethod(this$, mids$[mid_numberOfNodes_54c6a179]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace graph {
      static PyObject *t_IIntGraph_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntGraph_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntGraph_contains(t_IIntGraph *self, PyObject *args);
      static PyObject *t_IIntGraph_edgeIterator(t_IIntGraph *self);
      static PyObject *t_IIntGraph_getNodes(t_IIntGraph *self);
      static PyObject *t_IIntGraph_neighborIterator(t_IIntGraph *self, PyObject *arg);
      static PyObject *t_IIntGraph_nodeIterator(t_IIntGraph *self);
      static PyObject *t_IIntGraph_numberOfArcs(t_IIntGraph *self);
      static PyObject *t_IIntGraph_numberOfNodes(t_IIntGraph *self);
      static PyObject *t_IIntGraph_get__nodes(t_IIntGraph *self, void *data);
      static PyGetSetDef t_IIntGraph__fields_[] = {
        DECLARE_GET_FIELD(t_IIntGraph, nodes),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IIntGraph__methods_[] = {
        DECLARE_METHOD(t_IIntGraph, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntGraph, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntGraph, contains, METH_VARARGS),
        DECLARE_METHOD(t_IIntGraph, edgeIterator, METH_NOARGS),
        DECLARE_METHOD(t_IIntGraph, getNodes, METH_NOARGS),
        DECLARE_METHOD(t_IIntGraph, neighborIterator, METH_O),
        DECLARE_METHOD(t_IIntGraph, nodeIterator, METH_NOARGS),
        DECLARE_METHOD(t_IIntGraph, numberOfArcs, METH_NOARGS),
        DECLARE_METHOD(t_IIntGraph, numberOfNodes, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IIntGraph, t_IIntGraph, ::java::lang::Object, IIntGraph, abstract_init, 0, 0, t_IIntGraph__fields_, 0, 0);

      void t_IIntGraph::install(PyObject *module)
      {
        installType(&PY_TYPE(IIntGraph), module, "IIntGraph", 0);
      }

      void t_IIntGraph::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IIntGraph).tp_dict, "class_", make_descriptor(IIntGraph::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IIntGraph).tp_dict, "wrapfn_", make_descriptor(t_IIntGraph::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IIntGraph).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IIntGraph_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IIntGraph::initializeClass, 1)))
          return NULL;
        return t_IIntGraph::wrap_Object(IIntGraph(((t_IIntGraph *) arg)->object.this$));
      }
      static PyObject *t_IIntGraph_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IIntGraph::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IIntGraph_contains(t_IIntGraph *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            jboolean result;

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.contains(a0));
              Py_RETURN_BOOL(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            jboolean result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.contains(a0, a1));
              Py_RETURN_BOOL(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "contains", args);
        return NULL;
      }

      static PyObject *t_IIntGraph_edgeIterator(t_IIntGraph *self)
      {
        ::java::util::Iterator result((jobject) NULL);
        OBJ_CALL(result = self->object.edgeIterator());
        return ::java::util::t_Iterator::wrap_Object(result, &::stallone::api::graph::PY_TYPE(IIntEdge));
      }

      static PyObject *t_IIntGraph_getNodes(t_IIntGraph *self)
      {
        ::stallone::api::ints::IIntArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getNodes());
        return ::stallone::api::ints::t_IIntArray::wrap_Object(result);
      }

      static PyObject *t_IIntGraph_neighborIterator(t_IIntGraph *self, PyObject *arg)
      {
        jint a0;
        ::stallone::api::ints::IIntIterator result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.neighborIterator(a0));
          return ::stallone::api::ints::t_IIntIterator::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "neighborIterator", arg);
        return NULL;
      }

      static PyObject *t_IIntGraph_nodeIterator(t_IIntGraph *self)
      {
        ::stallone::api::ints::IIntIterator result((jobject) NULL);
        OBJ_CALL(result = self->object.nodeIterator());
        return ::stallone::api::ints::t_IIntIterator::wrap_Object(result);
      }

      static PyObject *t_IIntGraph_numberOfArcs(t_IIntGraph *self)
      {
        jint result;
        OBJ_CALL(result = self->object.numberOfArcs());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IIntGraph_numberOfNodes(t_IIntGraph *self)
      {
        jint result;
        OBJ_CALL(result = self->object.numberOfNodes());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IIntGraph_get__nodes(t_IIntGraph *self, void *data)
      {
        ::stallone::api::ints::IIntArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getNodes());
        return ::stallone::api::ints::t_IIntArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/ILinearMatrixSystem.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *ILinearMatrixSystem::class$ = NULL;
      jmethodID *ILinearMatrixSystem::mids$ = NULL;
      bool ILinearMatrixSystem::live$ = false;

      jclass ILinearMatrixSystem::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/ILinearMatrixSystem");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getSolutionMatrix_1d53e353] = env->getMethodID(cls, "getSolutionMatrix", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_perform_54c6a166] = env->getMethodID(cls, "perform", "()V");
          mids$[mid_setCoefficientMatrix_0253084a] = env->getMethodID(cls, "setCoefficientMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_setMatrix_0253084a] = env->getMethodID(cls, "setMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::doubles::IDoubleArray ILinearMatrixSystem::getSolutionMatrix() const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_getSolutionMatrix_1d53e353]));
      }

      void ILinearMatrixSystem::perform() const
      {
        env->callVoidMethod(this$, mids$[mid_perform_54c6a166]);
      }

      void ILinearMatrixSystem::setCoefficientMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setCoefficientMatrix_0253084a], a0.this$);
      }

      void ILinearMatrixSystem::setMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setMatrix_0253084a], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_ILinearMatrixSystem_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ILinearMatrixSystem_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ILinearMatrixSystem_getSolutionMatrix(t_ILinearMatrixSystem *self);
      static PyObject *t_ILinearMatrixSystem_perform(t_ILinearMatrixSystem *self);
      static PyObject *t_ILinearMatrixSystem_setCoefficientMatrix(t_ILinearMatrixSystem *self, PyObject *arg);
      static PyObject *t_ILinearMatrixSystem_setMatrix(t_ILinearMatrixSystem *self, PyObject *arg);
      static int t_ILinearMatrixSystem_set__coefficientMatrix(t_ILinearMatrixSystem *self, PyObject *arg, void *data);
      static int t_ILinearMatrixSystem_set__matrix(t_ILinearMatrixSystem *self, PyObject *arg, void *data);
      static PyObject *t_ILinearMatrixSystem_get__solutionMatrix(t_ILinearMatrixSystem *self, void *data);
      static PyGetSetDef t_ILinearMatrixSystem__fields_[] = {
        DECLARE_SET_FIELD(t_ILinearMatrixSystem, coefficientMatrix),
        DECLARE_SET_FIELD(t_ILinearMatrixSystem, matrix),
        DECLARE_GET_FIELD(t_ILinearMatrixSystem, solutionMatrix),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_ILinearMatrixSystem__methods_[] = {
        DECLARE_METHOD(t_ILinearMatrixSystem, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ILinearMatrixSystem, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ILinearMatrixSystem, getSolutionMatrix, METH_NOARGS),
        DECLARE_METHOD(t_ILinearMatrixSystem, perform, METH_NOARGS),
        DECLARE_METHOD(t_ILinearMatrixSystem, setCoefficientMatrix, METH_O),
        DECLARE_METHOD(t_ILinearMatrixSystem, setMatrix, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(ILinearMatrixSystem, t_ILinearMatrixSystem, ::java::lang::Object, ILinearMatrixSystem, abstract_init, 0, 0, t_ILinearMatrixSystem__fields_, 0, 0);

      void t_ILinearMatrixSystem::install(PyObject *module)
      {
        installType(&PY_TYPE(ILinearMatrixSystem), module, "ILinearMatrixSystem", 0);
      }

      void t_ILinearMatrixSystem::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(ILinearMatrixSystem).tp_dict, "class_", make_descriptor(ILinearMatrixSystem::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ILinearMatrixSystem).tp_dict, "wrapfn_", make_descriptor(t_ILinearMatrixSystem::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ILinearMatrixSystem).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_ILinearMatrixSystem_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, ILinearMatrixSystem::initializeClass, 1)))
          return NULL;
        return t_ILinearMatrixSystem::wrap_Object(ILinearMatrixSystem(((t_ILinearMatrixSystem *) arg)->object.this$));
      }
      static PyObject *t_ILinearMatrixSystem_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, ILinearMatrixSystem::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_ILinearMatrixSystem_getSolutionMatrix(t_ILinearMatrixSystem *self)
      {
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.getSolutionMatrix());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_ILinearMatrixSystem_perform(t_ILinearMatrixSystem *self)
      {
        OBJ_CALL(self->object.perform());
        Py_RETURN_NONE;
      }

      static PyObject *t_ILinearMatrixSystem_setCoefficientMatrix(t_ILinearMatrixSystem *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setCoefficientMatrix(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setCoefficientMatrix", arg);
        return NULL;
      }

      static PyObject *t_ILinearMatrixSystem_setMatrix(t_ILinearMatrixSystem *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setMatrix(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setMatrix", arg);
        return NULL;
      }

      static int t_ILinearMatrixSystem_set__coefficientMatrix(t_ILinearMatrixSystem *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setCoefficientMatrix(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "coefficientMatrix", arg);
        return -1;
      }

      static int t_ILinearMatrixSystem_set__matrix(t_ILinearMatrixSystem *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setMatrix(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "matrix", arg);
        return -1;
      }

      static PyObject *t_ILinearMatrixSystem_get__solutionMatrix(t_ILinearMatrixSystem *self, void *data)
      {
        ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
        OBJ_CALL(value = self->object.getSolutionMatrix());
        return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/datasequence/DataSequenceFactory.h"
#include "stallone/api/datasequence/IDataReader.h"
#include "stallone/api/datasequence/IDataWriter.h"
#include "stallone/api/datasequence/IDataList.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "java/lang/String.h"
#include "java/lang/Iterable.h"
#include "java/util/Iterator.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/datasequence/IDataSequenceLoader.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace datasequence {

      ::java::lang::Class *DataSequenceFactory::class$ = NULL;
      jmethodID *DataSequenceFactory::mids$ = NULL;
      bool DataSequenceFactory::live$ = false;

      jclass DataSequenceFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/datasequence/DataSequenceFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_createASCIIDataReader_66d6ac43] = env->getMethodID(cls, "createASCIIDataReader", "(Ljava/lang/String;)Lstallone/api/datasequence/IDataReader;");
          mids$[mid_createASCIIDataWriter_4e494859] = env->getMethodID(cls, "createASCIIDataWriter", "(Ljava/lang/String;I)Lstallone/api/datasequence/IDataWriter;");
          mids$[mid_createASCIIDataWriter_352bba45] = env->getMethodID(cls, "createASCIIDataWriter", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;)Lstallone/api/datasequence/IDataWriter;");
          mids$[mid_createConsoleDataOutput_67d8e9b7] = env->getMethodID(cls, "createConsoleDataOutput", "(I)Lstallone/api/datasequence/IDataWriter;");
          mids$[mid_createConsoleDataOutput_482bfdd3] = env->getMethodID(cls, "createConsoleDataOutput", "(ILjava/lang/String;Ljava/lang/String;)Lstallone/api/datasequence/IDataWriter;");
          mids$[mid_createDataWriter_85286d37] = env->getMethodID(cls, "createDataWriter", "(Ljava/lang/String;II)Lstallone/api/datasequence/IDataWriter;");
          mids$[mid_createDatalist_15c437fc] = env->getMethodID(cls, "createDatalist", "()Lstallone/api/datasequence/IDataList;");
          mids$[mid_dataSequenceLoader_66d6ac43] = env->getMethodID(cls, "dataSequenceLoader", "(Ljava/lang/String;)Lstallone/api/datasequence/IDataReader;");
          mids$[mid_interleavedDataIterable_9bf0a4fd] = env->getMethodID(cls, "interleavedDataIterable", "(Lstallone/api/datasequence/IDataSequenceLoader;I)Ljava/lang/Iterable;");
          mids$[mid_iterator_58368f82] = env->getMethodID(cls, "iterator", "(Lstallone/api/datasequence/IDataSequence;)Ljava/util/Iterator;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      DataSequenceFactory::DataSequenceFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::datasequence::IDataReader DataSequenceFactory::createASCIIDataReader(const ::java::lang::String & a0) const
      {
        return ::stallone::api::datasequence::IDataReader(env->callObjectMethod(this$, mids$[mid_createASCIIDataReader_66d6ac43], a0.this$));
      }

      ::stallone::api::datasequence::IDataWriter DataSequenceFactory::createASCIIDataWriter(const ::java::lang::String & a0, jint a1) const
      {
        return ::stallone::api::datasequence::IDataWriter(env->callObjectMethod(this$, mids$[mid_createASCIIDataWriter_4e494859], a0.this$, a1));
      }

      ::stallone::api::datasequence::IDataWriter DataSequenceFactory::createASCIIDataWriter(const ::java::lang::String & a0, jint a1, const ::java::lang::String & a2, const ::java::lang::String & a3) const
      {
        return ::stallone::api::datasequence::IDataWriter(env->callObjectMethod(this$, mids$[mid_createASCIIDataWriter_352bba45], a0.this$, a1, a2.this$, a3.this$));
      }

      ::stallone::api::datasequence::IDataWriter DataSequenceFactory::createConsoleDataOutput(jint a0) const
      {
        return ::stallone::api::datasequence::IDataWriter(env->callObjectMethod(this$, mids$[mid_createConsoleDataOutput_67d8e9b7], a0));
      }

      ::stallone::api::datasequence::IDataWriter DataSequenceFactory::createConsoleDataOutput(jint a0, const ::java::lang::String & a1, const ::java::lang::String & a2) const
      {
        return ::stallone::api::datasequence::IDataWriter(env->callObjectMethod(this$, mids$[mid_createConsoleDataOutput_482bfdd3], a0, a1.this$, a2.this$));
      }

      ::stallone::api::datasequence::IDataWriter DataSequenceFactory::createDataWriter(const ::java::lang::String & a0, jint a1, jint a2) const
      {
        return ::stallone::api::datasequence::IDataWriter(env->callObjectMethod(this$, mids$[mid_createDataWriter_85286d37], a0.this$, a1, a2));
      }

      ::stallone::api::datasequence::IDataList DataSequenceFactory::createDatalist() const
      {
        return ::stallone::api::datasequence::IDataList(env->callObjectMethod(this$, mids$[mid_createDatalist_15c437fc]));
      }

      ::stallone::api::datasequence::IDataReader DataSequenceFactory::dataSequenceLoader(const ::java::lang::String & a0) const
      {
        return ::stallone::api::datasequence::IDataReader(env->callObjectMethod(this$, mids$[mid_dataSequenceLoader_66d6ac43], a0.this$));
      }

      ::java::lang::Iterable DataSequenceFactory::interleavedDataIterable(const ::stallone::api::datasequence::IDataSequenceLoader & a0, jint a1) const
      {
        return ::java::lang::Iterable(env->callObjectMethod(this$, mids$[mid_interleavedDataIterable_9bf0a4fd], a0.this$, a1));
      }

      ::java::util::Iterator DataSequenceFactory::iterator(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_iterator_58368f82], a0.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace datasequence {
      static PyObject *t_DataSequenceFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_DataSequenceFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_DataSequenceFactory_init_(t_DataSequenceFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_DataSequenceFactory_createASCIIDataReader(t_DataSequenceFactory *self, PyObject *arg);
      static PyObject *t_DataSequenceFactory_createASCIIDataWriter(t_DataSequenceFactory *self, PyObject *args);
      static PyObject *t_DataSequenceFactory_createConsoleDataOutput(t_DataSequenceFactory *self, PyObject *args);
      static PyObject *t_DataSequenceFactory_createDataWriter(t_DataSequenceFactory *self, PyObject *args);
      static PyObject *t_DataSequenceFactory_createDatalist(t_DataSequenceFactory *self);
      static PyObject *t_DataSequenceFactory_dataSequenceLoader(t_DataSequenceFactory *self, PyObject *arg);
      static PyObject *t_DataSequenceFactory_interleavedDataIterable(t_DataSequenceFactory *self, PyObject *args);
      static PyObject *t_DataSequenceFactory_iterator(t_DataSequenceFactory *self, PyObject *arg);

      static PyMethodDef t_DataSequenceFactory__methods_[] = {
        DECLARE_METHOD(t_DataSequenceFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DataSequenceFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DataSequenceFactory, createASCIIDataReader, METH_O),
        DECLARE_METHOD(t_DataSequenceFactory, createASCIIDataWriter, METH_VARARGS),
        DECLARE_METHOD(t_DataSequenceFactory, createConsoleDataOutput, METH_VARARGS),
        DECLARE_METHOD(t_DataSequenceFactory, createDataWriter, METH_VARARGS),
        DECLARE_METHOD(t_DataSequenceFactory, createDatalist, METH_NOARGS),
        DECLARE_METHOD(t_DataSequenceFactory, dataSequenceLoader, METH_O),
        DECLARE_METHOD(t_DataSequenceFactory, interleavedDataIterable, METH_VARARGS),
        DECLARE_METHOD(t_DataSequenceFactory, iterator, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(DataSequenceFactory, t_DataSequenceFactory, ::java::lang::Object, DataSequenceFactory, t_DataSequenceFactory_init_, 0, 0, 0, 0, 0);

      void t_DataSequenceFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(DataSequenceFactory), module, "DataSequenceFactory", 0);
      }

      void t_DataSequenceFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(DataSequenceFactory).tp_dict, "class_", make_descriptor(DataSequenceFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(DataSequenceFactory).tp_dict, "wrapfn_", make_descriptor(t_DataSequenceFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(DataSequenceFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_DataSequenceFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, DataSequenceFactory::initializeClass, 1)))
          return NULL;
        return t_DataSequenceFactory::wrap_Object(DataSequenceFactory(((t_DataSequenceFactory *) arg)->object.this$));
      }
      static PyObject *t_DataSequenceFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, DataSequenceFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_DataSequenceFactory_init_(t_DataSequenceFactory *self, PyObject *args, PyObject *kwds)
      {
        DataSequenceFactory object((jobject) NULL);

        INT_CALL(object = DataSequenceFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_DataSequenceFactory_createASCIIDataReader(t_DataSequenceFactory *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::stallone::api::datasequence::IDataReader result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.createASCIIDataReader(a0));
          return ::stallone::api::datasequence::t_IDataReader::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "createASCIIDataReader", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceFactory_createASCIIDataWriter(t_DataSequenceFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::java::lang::String a0((jobject) NULL);
            jint a1;
            ::stallone::api::datasequence::IDataWriter result((jobject) NULL);

            if (!parseArgs(args, "sI", &a0, &a1))
            {
              OBJ_CALL(result = self->object.createASCIIDataWriter(a0, a1));
              return ::stallone::api::datasequence::t_IDataWriter::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::java::lang::String a0((jobject) NULL);
            jint a1;
            ::java::lang::String a2((jobject) NULL);
            ::java::lang::String a3((jobject) NULL);
            ::stallone::api::datasequence::IDataWriter result((jobject) NULL);

            if (!parseArgs(args, "sIss", &a0, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.createASCIIDataWriter(a0, a1, a2, a3));
              return ::stallone::api::datasequence::t_IDataWriter::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createASCIIDataWriter", args);
        return NULL;
      }

      static PyObject *t_DataSequenceFactory_createConsoleDataOutput(t_DataSequenceFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::datasequence::IDataWriter result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.createConsoleDataOutput(a0));
              return ::stallone::api::datasequence::t_IDataWriter::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            jint a0;
            ::java::lang::String a1((jobject) NULL);
            ::java::lang::String a2((jobject) NULL);
            ::stallone::api::datasequence::IDataWriter result((jobject) NULL);

            if (!parseArgs(args, "Iss", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createConsoleDataOutput(a0, a1, a2));
              return ::stallone::api::datasequence::t_IDataWriter::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createConsoleDataOutput", args);
        return NULL;
      }

      static PyObject *t_DataSequenceFactory_createDataWriter(t_DataSequenceFactory *self, PyObject *args)
      {
        ::java::lang::String a0((jobject) NULL);
        jint a1;
        jint a2;
        ::stallone::api::datasequence::IDataWriter result((jobject) NULL);

        if (!parseArgs(args, "sII", &a0, &a1, &a2))
        {
          OBJ_CALL(result = self->object.createDataWriter(a0, a1, a2));
          return ::stallone::api::datasequence::t_IDataWriter::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "createDataWriter", args);
        return NULL;
      }

      static PyObject *t_DataSequenceFactory_createDatalist(t_DataSequenceFactory *self)
      {
        ::stallone::api::datasequence::IDataList result((jobject) NULL);
        OBJ_CALL(result = self->object.createDatalist());
        return ::stallone::api::datasequence::t_IDataList::wrap_Object(result);
      }

      static PyObject *t_DataSequenceFactory_dataSequenceLoader(t_DataSequenceFactory *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::stallone::api::datasequence::IDataReader result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.dataSequenceLoader(a0));
          return ::stallone::api::datasequence::t_IDataReader::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "dataSequenceLoader", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceFactory_interleavedDataIterable(t_DataSequenceFactory *self, PyObject *args)
      {
        ::stallone::api::datasequence::IDataSequenceLoader a0((jobject) NULL);
        jint a1;
        ::java::lang::Iterable result((jobject) NULL);

        if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequenceLoader::initializeClass, &a0, &a1))
        {
          OBJ_CALL(result = self->object.interleavedDataIterable(a0, a1));
          return ::java::lang::t_Iterable::wrap_Object(result, &::stallone::api::doubles::PY_TYPE(IDoubleArray));
        }

        PyErr_SetArgsError((PyObject *) self, "interleavedDataIterable", args);
        return NULL;
      }

      static PyObject *t_DataSequenceFactory_iterator(t_DataSequenceFactory *self, PyObject *arg)
      {
        ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
        ::java::util::Iterator result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.iterator(a0));
          return ::java::util::t_Iterator::wrap_Object(result, &::stallone::api::doubles::PY_TYPE(IDoubleArray));
        }

        PyErr_SetArgsError((PyObject *) self, "iterator", arg);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/dynamics/DynamicsUtilities.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/datasequence/IDataWriter.h"
#include "stallone/dynamics/IIntegrator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace dynamics {

      ::java::lang::Class *DynamicsUtilities::class$ = NULL;
      jmethodID *DynamicsUtilities::mids$ = NULL;
      bool DynamicsUtilities::live$ = false;

      jclass DynamicsUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/dynamics/DynamicsUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_run_f7a18c66] = env->getMethodID(cls, "run", "(Lstallone/api/doubles/IDoubleArray;Lstallone/dynamics/IIntegrator;Lstallone/api/datasequence/IDataWriter;II)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      DynamicsUtilities::DynamicsUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      void DynamicsUtilities::run(const ::stallone::api::doubles::IDoubleArray & a0, const ::stallone::dynamics::IIntegrator & a1, const ::stallone::api::datasequence::IDataWriter & a2, jint a3, jint a4) const
      {
        env->callVoidMethod(this$, mids$[mid_run_f7a18c66], a0.this$, a1.this$, a2.this$, a3, a4);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace dynamics {
      static PyObject *t_DynamicsUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_DynamicsUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_DynamicsUtilities_init_(t_DynamicsUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_DynamicsUtilities_run(t_DynamicsUtilities *self, PyObject *args);

      static PyMethodDef t_DynamicsUtilities__methods_[] = {
        DECLARE_METHOD(t_DynamicsUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DynamicsUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DynamicsUtilities, run, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(DynamicsUtilities, t_DynamicsUtilities, ::java::lang::Object, DynamicsUtilities, t_DynamicsUtilities_init_, 0, 0, 0, 0, 0);

      void t_DynamicsUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(DynamicsUtilities), module, "DynamicsUtilities", 0);
      }

      void t_DynamicsUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(DynamicsUtilities).tp_dict, "class_", make_descriptor(DynamicsUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(DynamicsUtilities).tp_dict, "wrapfn_", make_descriptor(t_DynamicsUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(DynamicsUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_DynamicsUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, DynamicsUtilities::initializeClass, 1)))
          return NULL;
        return t_DynamicsUtilities::wrap_Object(DynamicsUtilities(((t_DynamicsUtilities *) arg)->object.this$));
      }
      static PyObject *t_DynamicsUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, DynamicsUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_DynamicsUtilities_init_(t_DynamicsUtilities *self, PyObject *args, PyObject *kwds)
      {
        DynamicsUtilities object((jobject) NULL);

        INT_CALL(object = DynamicsUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_DynamicsUtilities_run(t_DynamicsUtilities *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::dynamics::IIntegrator a1((jobject) NULL);
        ::stallone::api::datasequence::IDataWriter a2((jobject) NULL);
        jint a3;
        jint a4;

        if (!parseArgs(args, "kkkII", ::stallone::api::doubles::IDoubleArray::initializeClass, ::stallone::dynamics::IIntegrator::initializeClass, ::stallone::api::datasequence::IDataWriter::initializeClass, &a0, &a1, &a2, &a3, &a4))
        {
          OBJ_CALL(self->object.run(a0, a1, a2, a3, a4));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "run", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/dynamics/Dynamics.h"
#include "stallone/api/dynamics/DynamicsUtilities.h"
#include "stallone/api/dynamics/DynamicsFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace dynamics {

      ::java::lang::Class *Dynamics::class$ = NULL;
      jmethodID *Dynamics::mids$ = NULL;
      bool Dynamics::live$ = false;
      ::stallone::api::dynamics::DynamicsFactory *Dynamics::create = NULL;
      ::stallone::api::dynamics::DynamicsUtilities *Dynamics::util = NULL;

      jclass Dynamics::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/dynamics/Dynamics");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::dynamics::DynamicsFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/dynamics/DynamicsFactory;"));
          util = new ::stallone::api::dynamics::DynamicsUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/dynamics/DynamicsUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      Dynamics::Dynamics() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace dynamics {
      static PyObject *t_Dynamics_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_Dynamics_instance_(PyTypeObject *type, PyObject *arg);
      static int t_Dynamics_init_(t_Dynamics *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_Dynamics__methods_[] = {
        DECLARE_METHOD(t_Dynamics, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Dynamics, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(Dynamics, t_Dynamics, ::java::lang::Object, Dynamics, t_Dynamics_init_, 0, 0, 0, 0, 0);

      void t_Dynamics::install(PyObject *module)
      {
        installType(&PY_TYPE(Dynamics), module, "Dynamics", 0);
      }

      void t_Dynamics::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(Dynamics).tp_dict, "class_", make_descriptor(Dynamics::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Dynamics).tp_dict, "wrapfn_", make_descriptor(t_Dynamics::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Dynamics).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(Dynamics::initializeClass);
        PyDict_SetItemString(PY_TYPE(Dynamics).tp_dict, "create", make_descriptor(::stallone::api::dynamics::t_DynamicsFactory::wrap_Object(*Dynamics::create)));
        PyDict_SetItemString(PY_TYPE(Dynamics).tp_dict, "util", make_descriptor(::stallone::api::dynamics::t_DynamicsUtilities::wrap_Object(*Dynamics::util)));
      }

      static PyObject *t_Dynamics_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, Dynamics::initializeClass, 1)))
          return NULL;
        return t_Dynamics::wrap_Object(Dynamics(((t_Dynamics *) arg)->object.this$));
      }
      static PyObject *t_Dynamics_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, Dynamics::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_Dynamics_init_(t_Dynamics *self, PyObject *args, PyObject *kwds)
      {
        Dynamics object((jobject) NULL);

        INT_CALL(object = Dynamics());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/IEigenvalueSolver.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/algebra/IEigenvalueDecomposition.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *IEigenvalueSolver::class$ = NULL;
      jmethodID *IEigenvalueSolver::mids$ = NULL;
      bool IEigenvalueSolver::live$ = false;

      jclass IEigenvalueSolver::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/IEigenvalueSolver");

          mids$ = new jmethodID[max_mid];
          mids$[mid_getResult_706a1153] = env->getMethodID(cls, "getResult", "()Lstallone/api/algebra/IEigenvalueDecomposition;");
          mids$[mid_perform_54c6a166] = env->getMethodID(cls, "perform", "()V");
          mids$[mid_setMatrix_0253084a] = env->getMethodID(cls, "setMatrix", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_setNumberOfRequestedEigenvalues_39c7bd3c] = env->getMethodID(cls, "setNumberOfRequestedEigenvalues", "(I)V");
          mids$[mid_setPerformLeftComputation_bb0c767f] = env->getMethodID(cls, "setPerformLeftComputation", "(Z)V");
          mids$[mid_setPerformRightComputation_bb0c767f] = env->getMethodID(cls, "setPerformRightComputation", "(Z)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ::stallone::api::algebra::IEigenvalueDecomposition IEigenvalueSolver::getResult() const
      {
        return ::stallone::api::algebra::IEigenvalueDecomposition(env->callObjectMethod(this$, mids$[mid_getResult_706a1153]));
      }

      void IEigenvalueSolver::perform() const
      {
        env->callVoidMethod(this$, mids$[mid_perform_54c6a166]);
      }

      void IEigenvalueSolver::setMatrix(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setMatrix_0253084a], a0.this$);
      }

      void IEigenvalueSolver::setNumberOfRequestedEigenvalues(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setNumberOfRequestedEigenvalues_39c7bd3c], a0);
      }

      void IEigenvalueSolver::setPerformLeftComputation(jboolean a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setPerformLeftComputation_bb0c767f], a0);
      }

      void IEigenvalueSolver::setPerformRightComputation(jboolean a0) const
      {
        env->callVoidMethod(this$, mids$[mid_setPerformRightComputation_bb0c767f], a0);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_IEigenvalueSolver_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IEigenvalueSolver_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IEigenvalueSolver_getResult(t_IEigenvalueSolver *self);
      static PyObject *t_IEigenvalueSolver_perform(t_IEigenvalueSolver *self);
      static PyObject *t_IEigenvalueSolver_setMatrix(t_IEigenvalueSolver *self, PyObject *arg);
      static PyObject *t_IEigenvalueSolver_setNumberOfRequestedEigenvalues(t_IEigenvalueSolver *self, PyObject *arg);
      static PyObject *t_IEigenvalueSolver_setPerformLeftComputation(t_IEigenvalueSolver *self, PyObject *arg);
      static PyObject *t_IEigenvalueSolver_setPerformRightComputation(t_IEigenvalueSolver *self, PyObject *arg);
      static int t_IEigenvalueSolver_set__matrix(t_IEigenvalueSolver *self, PyObject *arg, void *data);
      static int t_IEigenvalueSolver_set__numberOfRequestedEigenvalues(t_IEigenvalueSolver *self, PyObject *arg, void *data);
      static int t_IEigenvalueSolver_set__performLeftComputation(t_IEigenvalueSolver *self, PyObject *arg, void *data);
      static int t_IEigenvalueSolver_set__performRightComputation(t_IEigenvalueSolver *self, PyObject *arg, void *data);
      static PyObject *t_IEigenvalueSolver_get__result(t_IEigenvalueSolver *self, void *data);
      static PyGetSetDef t_IEigenvalueSolver__fields_[] = {
        DECLARE_SET_FIELD(t_IEigenvalueSolver, matrix),
        DECLARE_SET_FIELD(t_IEigenvalueSolver, numberOfRequestedEigenvalues),
        DECLARE_SET_FIELD(t_IEigenvalueSolver, performLeftComputation),
        DECLARE_SET_FIELD(t_IEigenvalueSolver, performRightComputation),
        DECLARE_GET_FIELD(t_IEigenvalueSolver, result),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IEigenvalueSolver__methods_[] = {
        DECLARE_METHOD(t_IEigenvalueSolver, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IEigenvalueSolver, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IEigenvalueSolver, getResult, METH_NOARGS),
        DECLARE_METHOD(t_IEigenvalueSolver, perform, METH_NOARGS),
        DECLARE_METHOD(t_IEigenvalueSolver, setMatrix, METH_O),
        DECLARE_METHOD(t_IEigenvalueSolver, setNumberOfRequestedEigenvalues, METH_O),
        DECLARE_METHOD(t_IEigenvalueSolver, setPerformLeftComputation, METH_O),
        DECLARE_METHOD(t_IEigenvalueSolver, setPerformRightComputation, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IEigenvalueSolver, t_IEigenvalueSolver, ::java::lang::Object, IEigenvalueSolver, abstract_init, 0, 0, t_IEigenvalueSolver__fields_, 0, 0);

      void t_IEigenvalueSolver::install(PyObject *module)
      {
        installType(&PY_TYPE(IEigenvalueSolver), module, "IEigenvalueSolver", 0);
      }

      void t_IEigenvalueSolver::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IEigenvalueSolver).tp_dict, "class_", make_descriptor(IEigenvalueSolver::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IEigenvalueSolver).tp_dict, "wrapfn_", make_descriptor(t_IEigenvalueSolver::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IEigenvalueSolver).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IEigenvalueSolver_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IEigenvalueSolver::initializeClass, 1)))
          return NULL;
        return t_IEigenvalueSolver::wrap_Object(IEigenvalueSolver(((t_IEigenvalueSolver *) arg)->object.this$));
      }
      static PyObject *t_IEigenvalueSolver_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IEigenvalueSolver::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IEigenvalueSolver_getResult(t_IEigenvalueSolver *self)
      {
        ::stallone::api::algebra::IEigenvalueDecomposition result((jobject) NULL);
        OBJ_CALL(result = self->object.getResult());
        return ::stallone::api::algebra::t_IEigenvalueDecomposition::wrap_Object(result);
      }

      static PyObject *t_IEigenvalueSolver_perform(t_IEigenvalueSolver *self)
      {
        OBJ_CALL(self->object.perform());
        Py_RETURN_NONE;
      }

      static PyObject *t_IEigenvalueSolver_setMatrix(t_IEigenvalueSolver *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.setMatrix(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setMatrix", arg);
        return NULL;
      }

      static PyObject *t_IEigenvalueSolver_setNumberOfRequestedEigenvalues(t_IEigenvalueSolver *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.setNumberOfRequestedEigenvalues(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setNumberOfRequestedEigenvalues", arg);
        return NULL;
      }

      static PyObject *t_IEigenvalueSolver_setPerformLeftComputation(t_IEigenvalueSolver *self, PyObject *arg)
      {
        jboolean a0;

        if (!parseArg(arg, "Z", &a0))
        {
          OBJ_CALL(self->object.setPerformLeftComputation(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setPerformLeftComputation", arg);
        return NULL;
      }

      static PyObject *t_IEigenvalueSolver_setPerformRightComputation(t_IEigenvalueSolver *self, PyObject *arg)
      {
        jboolean a0;

        if (!parseArg(arg, "Z", &a0))
        {
          OBJ_CALL(self->object.setPerformRightComputation(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "setPerformRightComputation", arg);
        return NULL;
      }

      static int t_IEigenvalueSolver_set__matrix(t_IEigenvalueSolver *self, PyObject *arg, void *data)
      {
        {
          ::stallone::api::doubles::IDoubleArray value((jobject) NULL);
          if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &value))
          {
            INT_CALL(self->object.setMatrix(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "matrix", arg);
        return -1;
      }

      static int t_IEigenvalueSolver_set__numberOfRequestedEigenvalues(t_IEigenvalueSolver *self, PyObject *arg, void *data)
      {
        {
          jint value;
          if (!parseArg(arg, "I", &value))
          {
            INT_CALL(self->object.setNumberOfRequestedEigenvalues(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "numberOfRequestedEigenvalues", arg);
        return -1;
      }

      static int t_IEigenvalueSolver_set__performLeftComputation(t_IEigenvalueSolver *self, PyObject *arg, void *data)
      {
        {
          jboolean value;
          if (!parseArg(arg, "Z", &value))
          {
            INT_CALL(self->object.setPerformLeftComputation(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "performLeftComputation", arg);
        return -1;
      }

      static int t_IEigenvalueSolver_set__performRightComputation(t_IEigenvalueSolver *self, PyObject *arg, void *data)
      {
        {
          jboolean value;
          if (!parseArg(arg, "Z", &value))
          {
            INT_CALL(self->object.setPerformRightComputation(value));
            return 0;
          }
        }
        PyErr_SetArgsError((PyObject *) self, "performRightComputation", arg);
        return -1;
      }

      static PyObject *t_IEigenvalueSolver_get__result(t_IEigenvalueSolver *self, void *data)
      {
        ::stallone::api::algebra::IEigenvalueDecomposition value((jobject) NULL);
        OBJ_CALL(value = self->object.getResult());
        return ::stallone::api::algebra::t_IEigenvalueDecomposition::wrap_Object(value);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/function/FunctionFactory.h"
#include "stallone/api/function/IFunctionC1.h"
#include "stallone/api/function/IFunction.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace function {

      ::java::lang::Class *FunctionFactory::class$ = NULL;
      jmethodID *FunctionFactory::mids$ = NULL;
      bool FunctionFactory::live$ = false;

      jclass FunctionFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/function/FunctionFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_createDifferentiableFunction_27744d9b] = env->getMethodID(cls, "createDifferentiableFunction", "(Ljava/lang/String;[Ljava/lang/String;)Lstallone/api/function/IFunctionC1;");
          mids$[mid_createDifferentiableFunction_9fa18969] = env->getMethodID(cls, "createDifferentiableFunction", "([Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Lstallone/api/function/IFunctionC1;");
          mids$[mid_createFunction_74899c4f] = env->getMethodID(cls, "createFunction", "(Ljava/lang/String;)Lstallone/api/function/IFunction;");
          mids$[mid_createFunction_9cbc3d09] = env->getMethodID(cls, "createFunction", "([Ljava/lang/String;Ljava/lang/String;)Lstallone/api/function/IFunction;");
          mids$[mid_main_4dd4540c] = env->getStaticMethodID(cls, "main", "([Ljava/lang/String;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      FunctionFactory::FunctionFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::function::IFunctionC1 FunctionFactory::createDifferentiableFunction(const ::java::lang::String & a0, const JArray< ::java::lang::String > & a1) const
      {
        return ::stallone::api::function::IFunctionC1(env->callObjectMethod(this$, mids$[mid_createDifferentiableFunction_27744d9b], a0.this$, a1.this$));
      }

      ::stallone::api::function::IFunctionC1 FunctionFactory::createDifferentiableFunction(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1, const JArray< ::java::lang::String > & a2) const
      {
        return ::stallone::api::function::IFunctionC1(env->callObjectMethod(this$, mids$[mid_createDifferentiableFunction_9fa18969], a0.this$, a1.this$, a2.this$));
      }

      ::stallone::api::function::IFunction FunctionFactory::createFunction(const ::java::lang::String & a0) const
      {
        return ::stallone::api::function::IFunction(env->callObjectMethod(this$, mids$[mid_createFunction_74899c4f], a0.this$));
      }

      ::stallone::api::function::IFunction FunctionFactory::createFunction(const JArray< ::java::lang::String > & a0, const ::java::lang::String & a1) const
      {
        return ::stallone::api::function::IFunction(env->callObjectMethod(this$, mids$[mid_createFunction_9cbc3d09], a0.this$, a1.this$));
      }

      void FunctionFactory::main(const JArray< ::java::lang::String > & a0)
      {
        jclass cls = env->getClass(initializeClass);
        env->callStaticVoidMethod(cls, mids$[mid_main_4dd4540c], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace function {
      static PyObject *t_FunctionFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_FunctionFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_FunctionFactory_init_(t_FunctionFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_FunctionFactory_createDifferentiableFunction(t_FunctionFactory *self, PyObject *args);
      static PyObject *t_FunctionFactory_createFunction(t_FunctionFactory *self, PyObject *args);
      static PyObject *t_FunctionFactory_main(PyTypeObject *type, PyObject *arg);

      static PyMethodDef t_FunctionFactory__methods_[] = {
        DECLARE_METHOD(t_FunctionFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_FunctionFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_FunctionFactory, createDifferentiableFunction, METH_VARARGS),
        DECLARE_METHOD(t_FunctionFactory, createFunction, METH_VARARGS),
        DECLARE_METHOD(t_FunctionFactory, main, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(FunctionFactory, t_FunctionFactory, ::java::lang::Object, FunctionFactory, t_FunctionFactory_init_, 0, 0, 0, 0, 0);

      void t_FunctionFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(FunctionFactory), module, "FunctionFactory", 0);
      }

      void t_FunctionFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(FunctionFactory).tp_dict, "class_", make_descriptor(FunctionFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(FunctionFactory).tp_dict, "wrapfn_", make_descriptor(t_FunctionFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(FunctionFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_FunctionFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, FunctionFactory::initializeClass, 1)))
          return NULL;
        return t_FunctionFactory::wrap_Object(FunctionFactory(((t_FunctionFactory *) arg)->object.this$));
      }
      static PyObject *t_FunctionFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, FunctionFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_FunctionFactory_init_(t_FunctionFactory *self, PyObject *args, PyObject *kwds)
      {
        FunctionFactory object((jobject) NULL);

        INT_CALL(object = FunctionFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_FunctionFactory_createDifferentiableFunction(t_FunctionFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::java::lang::String a0((jobject) NULL);
            JArray< ::java::lang::String > a1((jobject) NULL);
            ::stallone::api::function::IFunctionC1 result((jobject) NULL);

            if (!parseArgs(args, "s[s", &a0, &a1))
            {
              OBJ_CALL(result = self->object.createDifferentiableFunction(a0, a1));
              return ::stallone::api::function::t_IFunctionC1::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            JArray< ::java::lang::String > a2((jobject) NULL);
            ::stallone::api::function::IFunctionC1 result((jobject) NULL);

            if (!parseArgs(args, "[ss[s", &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createDifferentiableFunction(a0, a1, a2));
              return ::stallone::api::function::t_IFunctionC1::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createDifferentiableFunction", args);
        return NULL;
      }

      static PyObject *t_FunctionFactory_createFunction(t_FunctionFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::java::lang::String a0((jobject) NULL);
            ::stallone::api::function::IFunction result((jobject) NULL);

            if (!parseArgs(args, "s", &a0))
            {
              OBJ_CALL(result = self->object.createFunction(a0));
              return ::stallone::api::function::t_IFunction::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            JArray< ::java::lang::String > a0((jobject) NULL);
            ::java::lang::String a1((jobject) NULL);
            ::stallone::api::function::IFunction result((jobject) NULL);

            if (!parseArgs(args, "[ss", &a0, &a1))
            {
              OBJ_CALL(result = self->object.createFunction(a0, a1));
              return ::stallone::api::function::t_IFunction::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createFunction", args);
        return NULL;
      }

      static PyObject *t_FunctionFactory_main(PyTypeObject *type, PyObject *arg)
      {
        JArray< ::java::lang::String > a0((jobject) NULL);

        if (!parseArg(arg, "[s", &a0))
        {
          OBJ_CALL(::stallone::api::function::FunctionFactory::main(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError(type, "main", arg);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/doubles/IDoubleIterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace doubles {

      ::java::lang::Class *IDoubleArray::class$ = NULL;
      jmethodID *IDoubleArray::mids$ = NULL;
      bool IDoubleArray::live$ = false;

      jclass IDoubleArray::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/doubles/IDoubleArray");

          mids$ = new jmethodID[max_mid];
          mids$[mid_columns_54c6a179] = env->getMethodID(cls, "columns", "()I");
          mids$[mid_copy_1d53e353] = env->getMethodID(cls, "copy", "()Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_copyFrom_0253084a] = env->getMethodID(cls, "copyFrom", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_copyInto_0253084a] = env->getMethodID(cls, "copyInto", "(Lstallone/api/doubles/IDoubleArray;)V");
          mids$[mid_create_e3ead0f5] = env->getMethodID(cls, "create", "(I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_create_3cbb604f] = env->getMethodID(cls, "create", "(II)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_get_39c7bd2e] = env->getMethodID(cls, "get", "(I)D");
          mids$[mid_get_d8d154b4] = env->getMethodID(cls, "get", "(II)D");
          mids$[mid_getArray_dab10e78] = env->getMethodID(cls, "getArray", "()[D");
          mids$[mid_getColumn_b4292e9e] = env->getMethodID(cls, "getColumn", "(I)[D");
          mids$[mid_getRow_b4292e9e] = env->getMethodID(cls, "getRow", "(I)[D");
          mids$[mid_getTable_b9d949a8] = env->getMethodID(cls, "getTable", "()[[D");
          mids$[mid_isSparse_54c6a16a] = env->getMethodID(cls, "isSparse", "()Z");
          mids$[mid_iterator_c2219c49] = env->getMethodID(cls, "iterator", "()Lstallone/api/doubles/IDoubleIterator;");
          mids$[mid_nonzeroIterator_c2219c49] = env->getMethodID(cls, "nonzeroIterator", "()Lstallone/api/doubles/IDoubleIterator;");
          mids$[mid_order_54c6a179] = env->getMethodID(cls, "order", "()I");
          mids$[mid_rows_54c6a179] = env->getMethodID(cls, "rows", "()I");
          mids$[mid_set_5aa51c57] = env->getMethodID(cls, "set", "(ID)V");
          mids$[mid_set_514fa3b5] = env->getMethodID(cls, "set", "(IID)V");
          mids$[mid_size_54c6a179] = env->getMethodID(cls, "size", "()I");
          mids$[mid_view_1259a6af] = env->getMethodID(cls, "view", "([I[I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_viewBlock_6662d773] = env->getMethodID(cls, "viewBlock", "(IIII)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_viewColumn_e3ead0f5] = env->getMethodID(cls, "viewColumn", "(I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_viewRow_e3ead0f5] = env->getMethodID(cls, "viewRow", "(I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_zero_54c6a166] = env->getMethodID(cls, "zero", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jint IDoubleArray::columns() const
      {
        return env->callIntMethod(this$, mids$[mid_columns_54c6a179]);
      }

      IDoubleArray IDoubleArray::copy() const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_copy_1d53e353]));
      }

      void IDoubleArray::copyFrom(const IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_copyFrom_0253084a], a0.this$);
      }

      void IDoubleArray::copyInto(const IDoubleArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_copyInto_0253084a], a0.this$);
      }

      IDoubleArray IDoubleArray::create(jint a0) const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_create_e3ead0f5], a0));
      }

      IDoubleArray IDoubleArray::create(jint a0, jint a1) const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_create_3cbb604f], a0, a1));
      }

      jdouble IDoubleArray::get(jint a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_get_39c7bd2e], a0);
      }

      jdouble IDoubleArray::get(jint a0, jint a1) const
      {
        return env->callDoubleMethod(this$, mids$[mid_get_d8d154b4], a0, a1);
      }

      JArray< jdouble > IDoubleArray::getArray() const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getArray_dab10e78]));
      }

      JArray< jdouble > IDoubleArray::getColumn(jint a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getColumn_b4292e9e], a0));
      }

      JArray< jdouble > IDoubleArray::getRow(jint a0) const
      {
        return JArray< jdouble >(env->callObjectMethod(this$, mids$[mid_getRow_b4292e9e], a0));
      }

      JArray< JArray< jdouble > > IDoubleArray::getTable() const
      {
        return JArray< JArray< jdouble > >(env->callObjectMethod(this$, mids$[mid_getTable_b9d949a8]));
      }

      jboolean IDoubleArray::isSparse() const
      {
        return env->callBooleanMethod(this$, mids$[mid_isSparse_54c6a16a]);
      }

      ::stallone::api::doubles::IDoubleIterator IDoubleArray::iterator() const
      {
        return ::stallone::api::doubles::IDoubleIterator(env->callObjectMethod(this$, mids$[mid_iterator_c2219c49]));
      }

      ::stallone::api::doubles::IDoubleIterator IDoubleArray::nonzeroIterator() const
      {
        return ::stallone::api::doubles::IDoubleIterator(env->callObjectMethod(this$, mids$[mid_nonzeroIterator_c2219c49]));
      }

      jint IDoubleArray::order() const
      {
        return env->callIntMethod(this$, mids$[mid_order_54c6a179]);
      }

      jint IDoubleArray::rows() const
      {
        return env->callIntMethod(this$, mids$[mid_rows_54c6a179]);
      }

      void IDoubleArray::set(jint a0, jdouble a1) const
      {
        env->callVoidMethod(this$, mids$[mid_set_5aa51c57], a0, a1);
      }

      void IDoubleArray::set(jint a0, jint a1, jdouble a2) const
      {
        env->callVoidMethod(this$, mids$[mid_set_514fa3b5], a0, a1, a2);
      }

      jint IDoubleArray::size() const
      {
        return env->callIntMethod(this$, mids$[mid_size_54c6a179]);
      }

      IDoubleArray IDoubleArray::view(const JArray< jint > & a0, const JArray< jint > & a1) const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_view_1259a6af], a0.this$, a1.this$));
      }

      IDoubleArray IDoubleArray::viewBlock(jint a0, jint a1, jint a2, jint a3) const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_viewBlock_6662d773], a0, a1, a2, a3));
      }

      IDoubleArray IDoubleArray::viewColumn(jint a0) const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_viewColumn_e3ead0f5], a0));
      }

      IDoubleArray IDoubleArray::viewRow(jint a0) const
      {
        return IDoubleArray(env->callObjectMethod(this$, mids$[mid_viewRow_e3ead0f5], a0));
      }

      void IDoubleArray::zero() const
      {
        env->callVoidMethod(this$, mids$[mid_zero_54c6a166]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace doubles {
      static PyObject *t_IDoubleArray_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDoubleArray_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDoubleArray_columns(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_copy(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_copyFrom(t_IDoubleArray *self, PyObject *arg);
      static PyObject *t_IDoubleArray_copyInto(t_IDoubleArray *self, PyObject *arg);
      static PyObject *t_IDoubleArray_create(t_IDoubleArray *self, PyObject *args);
      static PyObject *t_IDoubleArray_get(t_IDoubleArray *self, PyObject *args);
      static PyObject *t_IDoubleArray_getArray(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_getColumn(t_IDoubleArray *self, PyObject *arg);
      static PyObject *t_IDoubleArray_getRow(t_IDoubleArray *self, PyObject *arg);
      static PyObject *t_IDoubleArray_getTable(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_isSparse(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_iterator(t_IDoubleArray *self, PyObject *args);
      static PyObject *t_IDoubleArray_nonzeroIterator(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_order(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_rows(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_set(t_IDoubleArray *self, PyObject *args);
      static PyObject *t_IDoubleArray_size(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_view(t_IDoubleArray *self, PyObject *args);
      static PyObject *t_IDoubleArray_viewBlock(t_IDoubleArray *self, PyObject *args);
      static PyObject *t_IDoubleArray_viewColumn(t_IDoubleArray *self, PyObject *arg);
      static PyObject *t_IDoubleArray_viewRow(t_IDoubleArray *self, PyObject *arg);
      static PyObject *t_IDoubleArray_zero(t_IDoubleArray *self);
      static PyObject *t_IDoubleArray_get__array(t_IDoubleArray *self, void *data);
      static PyObject *t_IDoubleArray_get__sparse(t_IDoubleArray *self, void *data);
      static PyObject *t_IDoubleArray_get__table(t_IDoubleArray *self, void *data);
      static PyGetSetDef t_IDoubleArray__fields_[] = {
        DECLARE_GET_FIELD(t_IDoubleArray, array),
        DECLARE_GET_FIELD(t_IDoubleArray, sparse),
        DECLARE_GET_FIELD(t_IDoubleArray, table),
        { NULL, NULL, NULL, NULL, NULL }
      };

      static PyMethodDef t_IDoubleArray__methods_[] = {
        DECLARE_METHOD(t_IDoubleArray, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDoubleArray, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDoubleArray, columns, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, copy, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, copyFrom, METH_O),
        DECLARE_METHOD(t_IDoubleArray, copyInto, METH_O),
        DECLARE_METHOD(t_IDoubleArray, create, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleArray, get, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleArray, getArray, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, getColumn, METH_O),
        DECLARE_METHOD(t_IDoubleArray, getRow, METH_O),
        DECLARE_METHOD(t_IDoubleArray, getTable, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, isSparse, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, iterator, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleArray, nonzeroIterator, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, order, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, rows, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, set, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleArray, size, METH_NOARGS),
        DECLARE_METHOD(t_IDoubleArray, view, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleArray, viewBlock, METH_VARARGS),
        DECLARE_METHOD(t_IDoubleArray, viewColumn, METH_O),
        DECLARE_METHOD(t_IDoubleArray, viewRow, METH_O),
        DECLARE_METHOD(t_IDoubleArray, zero, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDoubleArray, t_IDoubleArray, ::java::lang::Iterable, IDoubleArray, abstract_init, ((PyObject *(*)(t_IDoubleArray *)) get_iterator< t_IDoubleArray >), 0, t_IDoubleArray__fields_, 0, 0);

      void t_IDoubleArray::install(PyObject *module)
      {
        installType(&PY_TYPE(IDoubleArray), module, "IDoubleArray", 0);
      }

      void t_IDoubleArray::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDoubleArray).tp_dict, "class_", make_descriptor(IDoubleArray::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDoubleArray).tp_dict, "wrapfn_", make_descriptor(t_IDoubleArray::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDoubleArray).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDoubleArray_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDoubleArray::initializeClass, 1)))
          return NULL;
        return t_IDoubleArray::wrap_Object(IDoubleArray(((t_IDoubleArray *) arg)->object.this$));
      }
      static PyObject *t_IDoubleArray_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDoubleArray::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDoubleArray_columns(t_IDoubleArray *self)
      {
        jint result;
        OBJ_CALL(result = self->object.columns());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleArray_copy(t_IDoubleArray *self)
      {
        IDoubleArray result((jobject) NULL);
        OBJ_CALL(result = self->object.copy());
        return t_IDoubleArray::wrap_Object(result);
      }

      static PyObject *t_IDoubleArray_copyFrom(t_IDoubleArray *self, PyObject *arg)
      {
        IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.copyFrom(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "copyFrom", arg);
        return NULL;
      }

      static PyObject *t_IDoubleArray_copyInto(t_IDoubleArray *self, PyObject *arg)
      {
        IDoubleArray a0((jobject) NULL);

        if (!parseArg(arg, "k", IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.copyInto(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "copyInto", arg);
        return NULL;
      }

      static PyObject *t_IDoubleArray_create(t_IDoubleArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.create(a0));
              return t_IDoubleArray::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.create(a0, a1));
              return t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "create", args);
        return NULL;
      }

      static PyObject *t_IDoubleArray_get(t_IDoubleArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            jdouble result;

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.get(a0));
              return PyFloat_FromDouble((double) result);
            }
          }
          break;
         case 2:
          {
            jint a0;
            jint a1;
            jdouble result;

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.get(a0, a1));
              return PyFloat_FromDouble((double) result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "get", args);
        return NULL;
      }

      static PyObject *t_IDoubleArray_getArray(t_IDoubleArray *self)
      {
        JArray< jdouble > result((jobject) NULL);
        OBJ_CALL(result = self->object.getArray());
        return result.wrap();
      }

      static PyObject *t_IDoubleArray_getColumn(t_IDoubleArray *self, PyObject *arg)
      {
        jint a0;
        JArray< jdouble > result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getColumn(a0));
          return result.wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getColumn", arg);
        return NULL;
      }

      static PyObject *t_IDoubleArray_getRow(t_IDoubleArray *self, PyObject *arg)
      {
        jint a0;
        JArray< jdouble > result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.getRow(a0));
          return result.wrap();
        }

        PyErr_SetArgsError((PyObject *) self, "getRow", arg);
        return NULL;
      }

      static PyObject *t_IDoubleArray_getTable(t_IDoubleArray *self)
      {
        JArray< JArray< jdouble > > result((jobject) NULL);
        OBJ_CALL(result = self->object.getTable());
        return JArray<jobject>(result.this$).wrap(NULL);
      }

      static PyObject *t_IDoubleArray_isSparse(t_IDoubleArray *self)
      {
        jboolean result;
        OBJ_CALL(result = self->object.isSparse());
        Py_RETURN_BOOL(result);
      }

      static PyObject *t_IDoubleArray_iterator(t_IDoubleArray *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleIterator result((jobject) NULL);

        if (!parseArgs(args, ""))
        {
          OBJ_CALL(result = self->object.iterator());
          return ::stallone::api::doubles::t_IDoubleIterator::wrap_Object(result);
        }

        return callSuper(&PY_TYPE(IDoubleArray), (PyObject *) self, "iterator", args, 2);
      }

      static PyObject *t_IDoubleArray_nonzeroIterator(t_IDoubleArray *self)
      {
        ::stallone::api::doubles::IDoubleIterator result((jobject) NULL);
        OBJ_CALL(result = self->object.nonzeroIterator());
        return ::stallone::api::doubles::t_IDoubleIterator::wrap_Object(result);
      }

      static PyObject *t_IDoubleArray_order(t_IDoubleArray *self)
      {
        jint result;
        OBJ_CALL(result = self->object.order());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleArray_rows(t_IDoubleArray *self)
      {
        jint result;
        OBJ_CALL(result = self->object.rows());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleArray_set(t_IDoubleArray *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jint a0;
            jdouble a1;

            if (!parseArgs(args, "ID", &a0, &a1))
            {
              OBJ_CALL(self->object.set(a0, a1));
              Py_RETURN_NONE;
            }
          }
          break;
         case 3:
          {
            jint a0;
            jint a1;
            jdouble a2;

            if (!parseArgs(args, "IID", &a0, &a1, &a2))
            {
              OBJ_CALL(self->object.set(a0, a1, a2));
              Py_RETURN_NONE;
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "set", args);
        return NULL;
      }

      static PyObject *t_IDoubleArray_size(t_IDoubleArray *self)
      {
        jint result;
        OBJ_CALL(result = self->object.size());
        return PyInt_FromLong((long) result);
      }

      static PyObject *t_IDoubleArray_view(t_IDoubleArray *self, PyObject *args)
      {
        JArray< jint > a0((jobject) NULL);
        JArray< jint > a1((jobject) NULL);
        IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "[I[I", &a0, &a1))
        {
          OBJ_CALL(result = self->object.view(a0, a1));
          return t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "view", args);
        return NULL;
      }

      static PyObject *t_IDoubleArray_viewBlock(t_IDoubleArray *self, PyObject *args)
      {
        jint a0;
        jint a1;
        jint a2;
        jint a3;
        IDoubleArray result((jobject) NULL);

        if (!parseArgs(args, "IIII", &a0, &a1, &a2, &a3))
        {
          OBJ_CALL(result = self->object.viewBlock(a0, a1, a2, a3));
          return t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "viewBlock", args);
        return NULL;
      }

      static PyObject *t_IDoubleArray_viewColumn(t_IDoubleArray *self, PyObject *arg)
      {
        jint a0;
        IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.viewColumn(a0));
          return t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "viewColumn", arg);
        return NULL;
      }

      static PyObject *t_IDoubleArray_viewRow(t_IDoubleArray *self, PyObject *arg)
      {
        jint a0;
        IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(result = self->object.viewRow(a0));
          return t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "viewRow", arg);
        return NULL;
      }

      static PyObject *t_IDoubleArray_zero(t_IDoubleArray *self)
      {
        OBJ_CALL(self->object.zero());
        Py_RETURN_NONE;
      }

      static PyObject *t_IDoubleArray_get__array(t_IDoubleArray *self, void *data)
      {
        JArray< jdouble > value((jobject) NULL);
        OBJ_CALL(value = self->object.getArray());
        return value.wrap();
      }

      static PyObject *t_IDoubleArray_get__sparse(t_IDoubleArray *self, void *data)
      {
        jboolean value;
        OBJ_CALL(value = self->object.isSparse());
        Py_RETURN_BOOL(value);
      }

      static PyObject *t_IDoubleArray_get__table(t_IDoubleArray *self, void *data)
      {
        JArray< JArray< jdouble > > value((jobject) NULL);
        OBJ_CALL(value = self->object.getTable());
        return JArray<jobject>(value.this$).wrap(NULL);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/algebra/Algebra.h"
#include "stallone/api/algebra/AlgebraUtilities.h"
#include "stallone/api/algebra/AlgebraFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace algebra {

      ::java::lang::Class *Algebra::class$ = NULL;
      jmethodID *Algebra::mids$ = NULL;
      bool Algebra::live$ = false;
      ::stallone::api::algebra::AlgebraFactory *Algebra::create = NULL;
      ::stallone::api::algebra::AlgebraUtilities *Algebra::util = NULL;

      jclass Algebra::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/algebra/Algebra");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::algebra::AlgebraFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/algebra/AlgebraFactory;"));
          util = new ::stallone::api::algebra::AlgebraUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/algebra/AlgebraUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      Algebra::Algebra() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace algebra {
      static PyObject *t_Algebra_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_Algebra_instance_(PyTypeObject *type, PyObject *arg);
      static int t_Algebra_init_(t_Algebra *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_Algebra__methods_[] = {
        DECLARE_METHOD(t_Algebra, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Algebra, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(Algebra, t_Algebra, ::java::lang::Object, Algebra, t_Algebra_init_, 0, 0, 0, 0, 0);

      void t_Algebra::install(PyObject *module)
      {
        installType(&PY_TYPE(Algebra), module, "Algebra", 0);
      }

      void t_Algebra::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(Algebra).tp_dict, "class_", make_descriptor(Algebra::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Algebra).tp_dict, "wrapfn_", make_descriptor(t_Algebra::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Algebra).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(Algebra::initializeClass);
        PyDict_SetItemString(PY_TYPE(Algebra).tp_dict, "create", make_descriptor(::stallone::api::algebra::t_AlgebraFactory::wrap_Object(*Algebra::create)));
        PyDict_SetItemString(PY_TYPE(Algebra).tp_dict, "util", make_descriptor(::stallone::api::algebra::t_AlgebraUtilities::wrap_Object(*Algebra::util)));
      }

      static PyObject *t_Algebra_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, Algebra::initializeClass, 1)))
          return NULL;
        return t_Algebra::wrap_Object(Algebra(((t_Algebra *) arg)->object.this$));
      }
      static PyObject *t_Algebra_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, Algebra::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_Algebra_init_(t_Algebra *self, PyObject *args, PyObject *kwds)
      {
        Algebra object((jobject) NULL);

        INT_CALL(object = Algebra());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/graph/GraphFactory.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/graph/IIntGraph.h"
#include "stallone/api/graph/IIntConnectivity.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace graph {

      ::java::lang::Class *GraphFactory::class$ = NULL;
      jmethodID *GraphFactory::mids$ = NULL;
      bool GraphFactory::live$ = false;

      jclass GraphFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/graph/GraphFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_connectivityChecker_f03ea51b] = env->getMethodID(cls, "connectivityChecker", "(Lstallone/api/graph/IIntGraph;)Lstallone/api/graph/IIntConnectivity;");
          mids$[mid_intGraph_3333943b] = env->getMethodID(cls, "intGraph", "(Lstallone/api/doubles/IDoubleArray;)Lstallone/api/graph/IIntGraph;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      GraphFactory::GraphFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::graph::IIntConnectivity GraphFactory::connectivityChecker(const ::stallone::api::graph::IIntGraph & a0) const
      {
        return ::stallone::api::graph::IIntConnectivity(env->callObjectMethod(this$, mids$[mid_connectivityChecker_f03ea51b], a0.this$));
      }

      ::stallone::api::graph::IIntGraph GraphFactory::intGraph(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return ::stallone::api::graph::IIntGraph(env->callObjectMethod(this$, mids$[mid_intGraph_3333943b], a0.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace graph {
      static PyObject *t_GraphFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_GraphFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_GraphFactory_init_(t_GraphFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_GraphFactory_connectivityChecker(t_GraphFactory *self, PyObject *arg);
      static PyObject *t_GraphFactory_intGraph(t_GraphFactory *self, PyObject *arg);

      static PyMethodDef t_GraphFactory__methods_[] = {
        DECLARE_METHOD(t_GraphFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_GraphFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_GraphFactory, connectivityChecker, METH_O),
        DECLARE_METHOD(t_GraphFactory, intGraph, METH_O),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(GraphFactory, t_GraphFactory, ::java::lang::Object, GraphFactory, t_GraphFactory_init_, 0, 0, 0, 0, 0);

      void t_GraphFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(GraphFactory), module, "GraphFactory", 0);
      }

      void t_GraphFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(GraphFactory).tp_dict, "class_", make_descriptor(GraphFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(GraphFactory).tp_dict, "wrapfn_", make_descriptor(t_GraphFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(GraphFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_GraphFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, GraphFactory::initializeClass, 1)))
          return NULL;
        return t_GraphFactory::wrap_Object(GraphFactory(((t_GraphFactory *) arg)->object.this$));
      }
      static PyObject *t_GraphFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, GraphFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_GraphFactory_init_(t_GraphFactory *self, PyObject *args, PyObject *kwds)
      {
        GraphFactory object((jobject) NULL);

        INT_CALL(object = GraphFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_GraphFactory_connectivityChecker(t_GraphFactory *self, PyObject *arg)
      {
        ::stallone::api::graph::IIntGraph a0((jobject) NULL);
        ::stallone::api::graph::IIntConnectivity result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::graph::IIntGraph::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.connectivityChecker(a0));
          return ::stallone::api::graph::t_IIntConnectivity::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "connectivityChecker", arg);
        return NULL;
      }

      static PyObject *t_GraphFactory_intGraph(t_GraphFactory *self, PyObject *arg)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        ::stallone::api::graph::IIntGraph result((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.intGraph(a0));
          return ::stallone::api::graph::t_IIntGraph::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "intGraph", arg);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Object.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Object::class$ = NULL;
    jmethodID *Object::mids$ = NULL;
    bool Object::live$ = false;

    jclass Object::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Object");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        mids$[mid_getClass_44a5f2c9] = env->getMethodID(cls, "getClass", "()Ljava/lang/Class;");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_notify_54c6a166] = env->getMethodID(cls, "notify", "()V");
        mids$[mid_notifyAll_54c6a166] = env->getMethodID(cls, "notifyAll", "()V");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_wait_54c6a166] = env->getMethodID(cls, "wait", "()V");
        mids$[mid_wait_0ee6df2f] = env->getMethodID(cls, "wait", "(J)V");
        mids$[mid_wait_25d05c8f] = env->getMethodID(cls, "wait", "(JI)V");
        mids$[mid_finalize_54c6a166] = env->getMethodID(cls, "finalize", "()V");
        mids$[mid_clone_846352c3] = env->getMethodID(cls, "clone", "()Ljava/lang/Object;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Object::Object() : ::JObject(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    jboolean Object::equals(const Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
    }

    ::java::lang::Class Object::getClass() const
    {
      return ::java::lang::Class(env->callObjectMethod(this$, mids$[mid_getClass_44a5f2c9]));
    }

    jint Object::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    void Object::notify() const
    {
      env->callVoidMethod(this$, mids$[mid_notify_54c6a166]);
    }

    void Object::notifyAll() const
    {
      env->callVoidMethod(this$, mids$[mid_notifyAll_54c6a166]);
    }

    ::java::lang::String Object::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    void Object::wait() const
    {
      env->callVoidMethod(this$, mids$[mid_wait_54c6a166]);
    }

    void Object::wait(jlong a0) const
    {
      env->callVoidMethod(this$, mids$[mid_wait_0ee6df2f], a0);
    }

    void Object::wait(jlong a0, jint a1) const
    {
      env->callVoidMethod(this$, mids$[mid_wait_25d05c8f], a0, a1);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Object_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Object_instance_(PyTypeObject *type, PyObject *arg);
    static int t_Object_init_(t_Object *self, PyObject *args, PyObject *kwds);
    static PyObject *t_Object_equals(t_Object *self, PyObject *arg);
    static PyObject *t_Object_getClass(t_Object *self);
    static PyObject *t_Object_hashCode(t_Object *self);
    static PyObject *t_Object_notify(t_Object *self);
    static PyObject *t_Object_notifyAll(t_Object *self);
    static PyObject *t_Object_toString(t_Object *self);
    static PyObject *t_Object_wait(t_Object *self, PyObject *args);
    static PyObject *t_Object_get__class(t_Object *self, void *data);
    static PyGetSetDef t_Object__fields_[] = {
      DECLARE_GET_FIELD(t_Object, class),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Object__methods_[] = {
      DECLARE_METHOD(t_Object, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Object, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Object, equals, METH_O),
      DECLARE_METHOD(t_Object, getClass, METH_NOARGS),
      DECLARE_METHOD(t_Object, hashCode, METH_NOARGS),
      DECLARE_METHOD(t_Object, notify, METH_NOARGS),
      DECLARE_METHOD(t_Object, notifyAll, METH_NOARGS),
      DECLARE_METHOD(t_Object, toString, METH_NOARGS),
      DECLARE_METHOD(t_Object, wait, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Object, t_Object, JObject, Object, t_Object_init_, 0, 0, t_Object__fields_, 0, 0);

    void t_Object::install(PyObject *module)
    {
      installType(&PY_TYPE(Object), module, "Object", 0);
    }

    void t_Object::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Object).tp_dict, "class_", make_descriptor(Object::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Object).tp_dict, "wrapfn_", make_descriptor(t_Object::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Object).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Object_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Object::initializeClass, 1)))
        return NULL;
      return t_Object::wrap_Object(Object(((t_Object *) arg)->object.this$));
    }
    static PyObject *t_Object_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Object::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_Object_init_(t_Object *self, PyObject *args, PyObject *kwds)
    {
      Object object((jobject) NULL);

      INT_CALL(object = Object());
      self->object = object;

      return 0;
    }

    static PyObject *t_Object_equals(t_Object *self, PyObject *arg)
    {
      Object a0((jobject) NULL);
      jboolean result;

      if (!parseArg(arg, "o", &a0))
      {
        OBJ_CALL(result = self->object.equals(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError((PyObject *) self, "equals", arg);
      return NULL;
    }

    static PyObject *t_Object_getClass(t_Object *self)
    {
      ::java::lang::Class result((jobject) NULL);
      OBJ_CALL(result = self->object.getClass());
      return ::java::lang::t_Class::wrap_Object(result);
    }

    static PyObject *t_Object_hashCode(t_Object *self)
    {
      jint result;
      OBJ_CALL(result = self->object.hashCode());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_Object_notify(t_Object *self)
    {
      OBJ_CALL(self->object.notify());
      Py_RETURN_NONE;
    }

    static PyObject *t_Object_notifyAll(t_Object *self)
    {
      OBJ_CALL(self->object.notifyAll());
      Py_RETURN_NONE;
    }

    static PyObject *t_Object_toString(t_Object *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.toString());
      return j2p(result);
    }

    static PyObject *t_Object_wait(t_Object *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          OBJ_CALL(self->object.wait());
          Py_RETURN_NONE;
        }
        break;
       case 1:
        {
          jlong a0;

          if (!parseArgs(args, "J", &a0))
          {
            OBJ_CALL(self->object.wait(a0));
            Py_RETURN_NONE;
          }
        }
        break;
       case 2:
        {
          jlong a0;
          jint a1;

          if (!parseArgs(args, "JI", &a0, &a1))
          {
            OBJ_CALL(self->object.wait(a0, a1));
            Py_RETURN_NONE;
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "wait", args);
      return NULL;
    }

    static PyObject *t_Object_get__class(t_Object *self, void *data)
    {
      ::java::lang::Class value((jobject) NULL);
      OBJ_CALL(value = self->object.getClass());
      return ::java::lang::t_Class::wrap_Object(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/graph/Graph.h"
#include "stallone/api/graph/GraphUtilities.h"
#include "stallone/api/graph/GraphFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace graph {

      ::java::lang::Class *Graph::class$ = NULL;
      jmethodID *Graph::mids$ = NULL;
      bool Graph::live$ = false;
      ::stallone::api::graph::GraphFactory *Graph::create = NULL;
      ::stallone::api::graph::GraphUtilities *Graph::util = NULL;

      jclass Graph::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/graph/Graph");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::graph::GraphFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/graph/GraphFactory;"));
          util = new ::stallone::api::graph::GraphUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/graph/GraphUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      Graph::Graph() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace graph {
      static PyObject *t_Graph_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_Graph_instance_(PyTypeObject *type, PyObject *arg);
      static int t_Graph_init_(t_Graph *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_Graph__methods_[] = {
        DECLARE_METHOD(t_Graph, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_Graph, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(Graph, t_Graph, ::java::lang::Object, Graph, t_Graph_init_, 0, 0, 0, 0, 0);

      void t_Graph::install(PyObject *module)
      {
        installType(&PY_TYPE(Graph), module, "Graph", 0);
      }

      void t_Graph::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(Graph).tp_dict, "class_", make_descriptor(Graph::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(Graph).tp_dict, "wrapfn_", make_descriptor(t_Graph::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(Graph).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(Graph::initializeClass);
        PyDict_SetItemString(PY_TYPE(Graph).tp_dict, "create", make_descriptor(::stallone::api::graph::t_GraphFactory::wrap_Object(*Graph::create)));
        PyDict_SetItemString(PY_TYPE(Graph).tp_dict, "util", make_descriptor(::stallone::api::graph::t_GraphUtilities::wrap_Object(*Graph::util)));
      }

      static PyObject *t_Graph_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, Graph::initializeClass, 1)))
          return NULL;
        return t_Graph::wrap_Object(Graph(((t_Graph *) arg)->object.this$));
      }
      static PyObject *t_Graph_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, Graph::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_Graph_init_(t_Graph *self, PyObject *args, PyObject *kwds)
      {
        Graph object((jobject) NULL);

        INT_CALL(object = Graph());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/discretization/DiscretizationFactory.h"
#include "stallone/api/doubles/IMetric.h"
#include "stallone/api/function/IGriddedFunction.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/function/IFunction.h"
#include "stallone/api/discretization/IDiscretization.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace discretization {

      ::java::lang::Class *DiscretizationFactory::class$ = NULL;
      jmethodID *DiscretizationFactory::mids$ = NULL;
      bool DiscretizationFactory::live$ = false;

      jclass DiscretizationFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/discretization/DiscretizationFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_coreDiscretization_d4adc0e8] = env->getMethodID(cls, "coreDiscretization", "(Lstallone/api/datasequence/IDataSequence;D)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_coreDiscretization_420bbdd1] = env->getMethodID(cls, "coreDiscretization", "(Lstallone/api/datasequence/IDataSequence;DLstallone/api/doubles/IMetric;)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_createGridDiscretization_520f5e61] = env->getMethodID(cls, "createGridDiscretization", "(Lstallone/api/function/IFunction;Lstallone/api/doubles/IDoubleArray;)Lstallone/api/function/IGriddedFunction;");
          mids$[mid_createGridDiscretization_036175b0] = env->getMethodID(cls, "createGridDiscretization", "(Lstallone/api/function/IFunction;Lstallone/api/doubles/IDoubleArray;D)Lstallone/api/function/IGriddedFunction;");
          mids$[mid_randomSelectionDiscretization_b095688d] = env->getMethodID(cls, "randomSelectionDiscretization", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_randomSelectionDiscretization_cdbbabe6] = env->getMethodID(cls, "randomSelectionDiscretization", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;I)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_regularSelectionDiscretization_b095688d] = env->getMethodID(cls, "regularSelectionDiscretization", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_regularSelectionDiscretization_cdbbabe6] = env->getMethodID(cls, "regularSelectionDiscretization", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;I)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_voronoiDiscretization_f8e8794f] = env->getMethodID(cls, "voronoiDiscretization", "(Lstallone/api/datasequence/IDataSequence;)Lstallone/api/discretization/IDiscretization;");
          mids$[mid_voronoiDiscretization_e9a384f2] = env->getMethodID(cls, "voronoiDiscretization", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;)Lstallone/api/discretization/IDiscretization;");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      DiscretizationFactory::DiscretizationFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::coreDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, jdouble a1) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_coreDiscretization_d4adc0e8], a0.this$, a1));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::coreDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, jdouble a1, const ::stallone::api::doubles::IMetric & a2) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_coreDiscretization_420bbdd1], a0.this$, a1, a2.this$));
      }

      ::stallone::api::function::IGriddedFunction DiscretizationFactory::createGridDiscretization(const ::stallone::api::function::IFunction & a0, const ::stallone::api::doubles::IDoubleArray & a1) const
      {
        return ::stallone::api::function::IGriddedFunction(env->callObjectMethod(this$, mids$[mid_createGridDiscretization_520f5e61], a0.this$, a1.this$));
      }

      ::stallone::api::function::IGriddedFunction DiscretizationFactory::createGridDiscretization(const ::stallone::api::function::IFunction & a0, const ::stallone::api::doubles::IDoubleArray & a1, jdouble a2) const
      {
        return ::stallone::api::function::IGriddedFunction(env->callObjectMethod(this$, mids$[mid_createGridDiscretization_036175b0], a0.this$, a1.this$, a2));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::randomSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_randomSelectionDiscretization_b095688d], a0.this$, a1));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::randomSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jint a2) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_randomSelectionDiscretization_cdbbabe6], a0.this$, a1.this$, a2));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::regularSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_regularSelectionDiscretization_b095688d], a0.this$, a1));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::regularSelectionDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jint a2) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_regularSelectionDiscretization_cdbbabe6], a0.this$, a1.this$, a2));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::voronoiDiscretization(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_voronoiDiscretization_f8e8794f], a0.this$));
      }

      ::stallone::api::discretization::IDiscretization DiscretizationFactory::voronoiDiscretization(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1) const
      {
        return ::stallone::api::discretization::IDiscretization(env->callObjectMethod(this$, mids$[mid_voronoiDiscretization_e9a384f2], a0.this$, a1.this$));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace discretization {
      static PyObject *t_DiscretizationFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_DiscretizationFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_DiscretizationFactory_init_(t_DiscretizationFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_DiscretizationFactory_coreDiscretization(t_DiscretizationFactory *self, PyObject *args);
      static PyObject *t_DiscretizationFactory_createGridDiscretization(t_DiscretizationFactory *self, PyObject *args);
      static PyObject *t_DiscretizationFactory_randomSelectionDiscretization(t_DiscretizationFactory *self, PyObject *args);
      static PyObject *t_DiscretizationFactory_regularSelectionDiscretization(t_DiscretizationFactory *self, PyObject *args);
      static PyObject *t_DiscretizationFactory_voronoiDiscretization(t_DiscretizationFactory *self, PyObject *args);

      static PyMethodDef t_DiscretizationFactory__methods_[] = {
        DECLARE_METHOD(t_DiscretizationFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DiscretizationFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DiscretizationFactory, coreDiscretization, METH_VARARGS),
        DECLARE_METHOD(t_DiscretizationFactory, createGridDiscretization, METH_VARARGS),
        DECLARE_METHOD(t_DiscretizationFactory, randomSelectionDiscretization, METH_VARARGS),
        DECLARE_METHOD(t_DiscretizationFactory, regularSelectionDiscretization, METH_VARARGS),
        DECLARE_METHOD(t_DiscretizationFactory, voronoiDiscretization, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(DiscretizationFactory, t_DiscretizationFactory, ::java::lang::Object, DiscretizationFactory, t_DiscretizationFactory_init_, 0, 0, 0, 0, 0);

      void t_DiscretizationFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(DiscretizationFactory), module, "DiscretizationFactory", 0);
      }

      void t_DiscretizationFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(DiscretizationFactory).tp_dict, "class_", make_descriptor(DiscretizationFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(DiscretizationFactory).tp_dict, "wrapfn_", make_descriptor(t_DiscretizationFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(DiscretizationFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_DiscretizationFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, DiscretizationFactory::initializeClass, 1)))
          return NULL;
        return t_DiscretizationFactory::wrap_Object(DiscretizationFactory(((t_DiscretizationFactory *) arg)->object.this$));
      }
      static PyObject *t_DiscretizationFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, DiscretizationFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_DiscretizationFactory_init_(t_DiscretizationFactory *self, PyObject *args, PyObject *kwds)
      {
        DiscretizationFactory object((jobject) NULL);

        INT_CALL(object = DiscretizationFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_DiscretizationFactory_coreDiscretization(t_DiscretizationFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jdouble a1;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kD", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.coreDiscretization(a0, a1));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jdouble a1;
            ::stallone::api::doubles::IMetric a2((jobject) NULL);
            PyTypeObject **p2;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kDK", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &a2, &p2, ::stallone::api::doubles::t_IMetric::parameters_))
            {
              OBJ_CALL(result = self->object.coreDiscretization(a0, a1, a2));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "coreDiscretization", args);
        return NULL;
      }

      static PyObject *t_DiscretizationFactory_createGridDiscretization(t_DiscretizationFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::function::IFunction a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            ::stallone::api::function::IGriddedFunction result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::function::IFunction::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createGridDiscretization(a0, a1));
              return ::stallone::api::function::t_IGriddedFunction::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::function::IFunction a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray a1((jobject) NULL);
            jdouble a2;
            ::stallone::api::function::IGriddedFunction result((jobject) NULL);

            if (!parseArgs(args, "kkD", ::stallone::api::function::IFunction::initializeClass, ::stallone::api::doubles::IDoubleArray::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createGridDiscretization(a0, a1, a2));
              return ::stallone::api::function::t_IGriddedFunction::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createGridDiscretization", args);
        return NULL;
      }

      static PyObject *t_DiscretizationFactory_randomSelectionDiscretization(t_DiscretizationFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.randomSelectionDiscretization(a0, a1));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kKI", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.randomSelectionDiscretization(a0, a1, a2));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "randomSelectionDiscretization", args);
        return NULL;
      }

      static PyObject *t_DiscretizationFactory_regularSelectionDiscretization(t_DiscretizationFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.regularSelectionDiscretization(a0, a1));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kKI", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.regularSelectionDiscretization(a0, a1, a2));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "regularSelectionDiscretization", args);
        return NULL;
      }

      static PyObject *t_DiscretizationFactory_voronoiDiscretization(t_DiscretizationFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.voronoiDiscretization(a0));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            ::stallone::api::discretization::IDiscretization result((jobject) NULL);

            if (!parseArgs(args, "kK", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_))
            {
              OBJ_CALL(result = self->object.voronoiDiscretization(a0, a1));
              return ::stallone::api::discretization::t_IDiscretization::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "voronoiDiscretization", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/function/IDiscretizedFunction.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace function {

      ::java::lang::Class *IDiscretizedFunction::class$ = NULL;
      jmethodID *IDiscretizedFunction::mids$ = NULL;
      bool IDiscretizedFunction::live$ = false;

      jclass IDiscretizedFunction::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/function/IDiscretizedFunction");

          mids$ = new jmethodID[max_mid];
          mids$[mid_f_02530858] = env->getMethodID(cls, "f", "(Lstallone/api/doubles/IDoubleArray;)D");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      jdouble IDiscretizedFunction::f(const ::stallone::api::doubles::IDoubleArray & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_f_02530858], a0.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace function {
      static PyObject *t_IDiscretizedFunction_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDiscretizedFunction_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IDiscretizedFunction_f(t_IDiscretizedFunction *self, PyObject *args);

      static PyMethodDef t_IDiscretizedFunction__methods_[] = {
        DECLARE_METHOD(t_IDiscretizedFunction, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDiscretizedFunction, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IDiscretizedFunction, f, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IDiscretizedFunction, t_IDiscretizedFunction, ::stallone::api::function::IFunction, IDiscretizedFunction, abstract_init, 0, 0, 0, 0, 0);

      void t_IDiscretizedFunction::install(PyObject *module)
      {
        installType(&PY_TYPE(IDiscretizedFunction), module, "IDiscretizedFunction", 0);
      }

      void t_IDiscretizedFunction::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IDiscretizedFunction).tp_dict, "class_", make_descriptor(IDiscretizedFunction::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IDiscretizedFunction).tp_dict, "wrapfn_", make_descriptor(t_IDiscretizedFunction::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IDiscretizedFunction).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IDiscretizedFunction_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IDiscretizedFunction::initializeClass, 1)))
          return NULL;
        return t_IDiscretizedFunction::wrap_Object(IDiscretizedFunction(((t_IDiscretizedFunction *) arg)->object.this$));
      }
      static PyObject *t_IDiscretizedFunction_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IDiscretizedFunction::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IDiscretizedFunction_f(t_IDiscretizedFunction *self, PyObject *args)
      {
        ::stallone::api::doubles::IDoubleArray a0((jobject) NULL);
        jdouble result;

        if (!parseArgs(args, "k", ::stallone::api::doubles::IDoubleArray::initializeClass, &a0))
        {
          OBJ_CALL(result = self->object.f(a0));
          return PyFloat_FromDouble((double) result);
        }

        return callSuper(&PY_TYPE(IDiscretizedFunction), (PyObject *) self, "f", args, 2);
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/io/StringWriter.h"
#include "java/lang/CharSequence.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace io {

    ::java::lang::Class *StringWriter::class$ = NULL;
    jmethodID *StringWriter::mids$ = NULL;
    bool StringWriter::live$ = false;

    jclass StringWriter::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/io/StringWriter");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
        mids$[mid_append_3aee6342] = env->getMethodID(cls, "append", "(C)Ljava/io/StringWriter;");
        mids$[mid_append_e2d4acee] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/io/StringWriter;");
        mids$[mid_append_199526fa] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/io/StringWriter;");
        mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");
        mids$[mid_flush_54c6a166] = env->getMethodID(cls, "flush", "()V");
        mids$[mid_getBuffer_d54172a5] = env->getMethodID(cls, "getBuffer", "()Ljava/lang/StringBuffer;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_write_5fdc3f48] = env->getMethodID(cls, "write", "(Ljava/lang/String;)V");
        mids$[mid_write_39c7bd3c] = env->getMethodID(cls, "write", "(I)V");
        mids$[mid_write_555f322c] = env->getMethodID(cls, "write", "(Ljava/lang/String;II)V");
        mids$[mid_write_6f0bb356] = env->getMethodID(cls, "write", "([CII)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    StringWriter::StringWriter() : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    StringWriter::StringWriter(jint a0) : ::java::io::Writer(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

    StringWriter StringWriter::append(jchar a0) const
    {
      return StringWriter(env->callObjectMethod(this$, mids$[mid_append_3aee6342], a0));
    }

    StringWriter StringWriter::append(const ::java::lang::CharSequence & a0) const
    {
      return StringWriter(env->callObjectMethod(this$, mids$[mid_append_e2d4acee], a0.this$));
    }

    StringWriter StringWriter::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
    {
      return StringWriter(env->callObjectMethod(this$, mids$[mid_append_199526fa], a0.this$, a1, a2));
    }

    void StringWriter::close() const
    {
      env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
    }

    void StringWriter::flush() const
    {
      env->callVoidMethod(this$, mids$[mid_flush_54c6a166]);
    }

    ::java::lang::StringBuffer StringWriter::getBuffer() const
    {
      return ::java::lang::StringBuffer(env->callObjectMethod(this$, mids$[mid_getBuffer_d54172a5]));
    }

    ::java::lang::String StringWriter::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    void StringWriter::write(const ::java::lang::String & a0) const
    {
      env->callVoidMethod(this$, mids$[mid_write_5fdc3f48], a0.this$);
    }

    void StringWriter::write(jint a0) const
    {
      env->callVoidMethod(this$, mids$[mid_write_39c7bd3c], a0);
    }

    void StringWriter::write(const ::java::lang::String & a0, jint a1, jint a2) const
    {
      env->callVoidMethod(this$, mids$[mid_write_555f322c], a0.this$, a1, a2);
    }

    void StringWriter::write(const JArray< jchar > & a0, jint a1, jint a2) const
    {
      env->callVoidMethod(this$, mids$[mid_write_6f0bb356], a0.this$, a1, a2);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace io {
    static PyObject *t_StringWriter_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_StringWriter_instance_(PyTypeObject *type, PyObject *arg);
    static int t_StringWriter_init_(t_StringWriter *self, PyObject *args, PyObject *kwds);
    static PyObject *t_StringWriter_append(t_StringWriter *self, PyObject *args);
    static PyObject *t_StringWriter_close(t_StringWriter *self, PyObject *args);
    static PyObject *t_StringWriter_flush(t_StringWriter *self, PyObject *args);
    static PyObject *t_StringWriter_getBuffer(t_StringWriter *self);
    static PyObject *t_StringWriter_toString(t_StringWriter *self, PyObject *args);
    static PyObject *t_StringWriter_write(t_StringWriter *self, PyObject *args);
    static PyObject *t_StringWriter_get__buffer(t_StringWriter *self, void *data);
    static PyGetSetDef t_StringWriter__fields_[] = {
      DECLARE_GET_FIELD(t_StringWriter, buffer),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_StringWriter__methods_[] = {
      DECLARE_METHOD(t_StringWriter, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StringWriter, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StringWriter, append, METH_VARARGS),
      DECLARE_METHOD(t_StringWriter, close, METH_VARARGS),
      DECLARE_METHOD(t_StringWriter, flush, METH_VARARGS),
      DECLARE_METHOD(t_StringWriter, getBuffer, METH_NOARGS),
      DECLARE_METHOD(t_StringWriter, toString, METH_VARARGS),
      DECLARE_METHOD(t_StringWriter, write, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(StringWriter, t_StringWriter, ::java::io::Writer, StringWriter, t_StringWriter_init_, 0, 0, t_StringWriter__fields_, 0, 0);

    void t_StringWriter::install(PyObject *module)
    {
      installType(&PY_TYPE(StringWriter), module, "StringWriter", 0);
    }

    void t_StringWriter::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(StringWriter).tp_dict, "class_", make_descriptor(StringWriter::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(StringWriter).tp_dict, "wrapfn_", make_descriptor(t_StringWriter::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(StringWriter).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_StringWriter_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, StringWriter::initializeClass, 1)))
        return NULL;
      return t_StringWriter::wrap_Object(StringWriter(((t_StringWriter *) arg)->object.this$));
    }
    static PyObject *t_StringWriter_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, StringWriter::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_StringWriter_init_(t_StringWriter *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          StringWriter object((jobject) NULL);

          INT_CALL(object = StringWriter());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          jint a0;
          StringWriter object((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            INT_CALL(object = StringWriter(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_StringWriter_append(t_StringWriter *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jchar a0;
          StringWriter result((jobject) NULL);

          if (!parseArgs(args, "C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringWriter::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          StringWriter result((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringWriter::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          jint a1;
          jint a2;
          StringWriter result((jobject) NULL);

          if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_StringWriter::wrap_Object(result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "append", args, 2);
    }

    static PyObject *t_StringWriter_close(t_StringWriter *self, PyObject *args)
    {

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(self->object.close());
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "close", args, 2);
    }

    static PyObject *t_StringWriter_flush(t_StringWriter *self, PyObject *args)
    {

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(self->object.flush());
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "flush", args, 2);
    }

    static PyObject *t_StringWriter_getBuffer(t_StringWriter *self)
    {
      ::java::lang::StringBuffer result((jobject) NULL);
      OBJ_CALL(result = self->object.getBuffer());
      return ::java::lang::t_StringBuffer::wrap_Object(result);
    }

    static PyObject *t_StringWriter_toString(t_StringWriter *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_StringWriter_write(t_StringWriter *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(self->object.write(a0));
            Py_RETURN_NONE;
          }
        }
        {
          jint a0;

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(self->object.write(a0));
            Py_RETURN_NONE;
          }
        }
        break;
       case 3:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint a2;

          if (!parseArgs(args, "sII", &a0, &a1, &a2))
          {
            OBJ_CALL(self->object.write(a0, a1, a2));
            Py_RETURN_NONE;
          }
        }
        {
          JArray< jchar > a0((jobject) NULL);
          jint a1;
          jint a2;

          if (!parseArgs(args, "[CII", &a0, &a1, &a2))
          {
            OBJ_CALL(self->object.write(a0, a1, a2));
            Py_RETURN_NONE;
          }
        }
      }

      return callSuper(&PY_TYPE(StringWriter), (PyObject *) self, "write", args, 2);
    }

    static PyObject *t_StringWriter_get__buffer(t_StringWriter *self, void *data)
    {
      ::java::lang::StringBuffer value((jobject) NULL);
      OBJ_CALL(value = self->object.getBuffer());
      return ::java::lang::t_StringBuffer::wrap_Object(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/intsequence/IIntWriter.h"
#include "stallone/api/ints/IIntArray.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace intsequence {

      ::java::lang::Class *IIntWriter::class$ = NULL;
      jmethodID *IIntWriter::mids$ = NULL;
      bool IIntWriter::live$ = false;

      jclass IIntWriter::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/intsequence/IIntWriter");

          mids$ = new jmethodID[max_mid];
          mids$[mid_add_39c7bd3c] = env->getMethodID(cls, "add", "(I)V");
          mids$[mid_addAll_059aa494] = env->getMethodID(cls, "addAll", "(Lstallone/api/ints/IIntArray;)V");
          mids$[mid_close_54c6a166] = env->getMethodID(cls, "close", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      void IIntWriter::add(jint a0) const
      {
        env->callVoidMethod(this$, mids$[mid_add_39c7bd3c], a0);
      }

      void IIntWriter::addAll(const ::stallone::api::ints::IIntArray & a0) const
      {
        env->callVoidMethod(this$, mids$[mid_addAll_059aa494], a0.this$);
      }

      void IIntWriter::close() const
      {
        env->callVoidMethod(this$, mids$[mid_close_54c6a166]);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace intsequence {
      static PyObject *t_IIntWriter_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntWriter_instance_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_IIntWriter_add(t_IIntWriter *self, PyObject *arg);
      static PyObject *t_IIntWriter_addAll(t_IIntWriter *self, PyObject *arg);
      static PyObject *t_IIntWriter_close(t_IIntWriter *self);

      static PyMethodDef t_IIntWriter__methods_[] = {
        DECLARE_METHOD(t_IIntWriter, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntWriter, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_IIntWriter, add, METH_O),
        DECLARE_METHOD(t_IIntWriter, addAll, METH_O),
        DECLARE_METHOD(t_IIntWriter, close, METH_NOARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(IIntWriter, t_IIntWriter, ::java::lang::Object, IIntWriter, abstract_init, 0, 0, 0, 0, 0);

      void t_IIntWriter::install(PyObject *module)
      {
        installType(&PY_TYPE(IIntWriter), module, "IIntWriter", 0);
      }

      void t_IIntWriter::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(IIntWriter).tp_dict, "class_", make_descriptor(IIntWriter::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(IIntWriter).tp_dict, "wrapfn_", make_descriptor(t_IIntWriter::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(IIntWriter).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_IIntWriter_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, IIntWriter::initializeClass, 1)))
          return NULL;
        return t_IIntWriter::wrap_Object(IIntWriter(((t_IIntWriter *) arg)->object.this$));
      }
      static PyObject *t_IIntWriter_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, IIntWriter::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static PyObject *t_IIntWriter_add(t_IIntWriter *self, PyObject *arg)
      {
        jint a0;

        if (!parseArg(arg, "I", &a0))
        {
          OBJ_CALL(self->object.add(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "add", arg);
        return NULL;
      }

      static PyObject *t_IIntWriter_addAll(t_IIntWriter *self, PyObject *arg)
      {
        ::stallone::api::ints::IIntArray a0((jobject) NULL);

        if (!parseArg(arg, "k", ::stallone::api::ints::IIntArray::initializeClass, &a0))
        {
          OBJ_CALL(self->object.addAll(a0));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "addAll", arg);
        return NULL;
      }

      static PyObject *t_IIntWriter_close(t_IIntWriter *self)
      {
        OBJ_CALL(self->object.close());
        Py_RETURN_NONE;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/util/Iterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace util {

    ::java::lang::Class *Iterator::class$ = NULL;
    jmethodID *Iterator::mids$ = NULL;
    bool Iterator::live$ = false;

    jclass Iterator::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/util/Iterator");

        mids$ = new jmethodID[max_mid];
        mids$[mid_hasNext_54c6a16a] = env->getMethodID(cls, "hasNext", "()Z");
        mids$[mid_next_846352c3] = env->getMethodID(cls, "next", "()Ljava/lang/Object;");
        mids$[mid_remove_54c6a166] = env->getMethodID(cls, "remove", "()V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    jboolean Iterator::hasNext() const
    {
      return env->callBooleanMethod(this$, mids$[mid_hasNext_54c6a16a]);
    }

    ::java::lang::Object Iterator::next() const
    {
      return ::java::lang::Object(env->callObjectMethod(this$, mids$[mid_next_846352c3]));
    }

    void Iterator::remove() const
    {
      env->callVoidMethod(this$, mids$[mid_remove_54c6a166]);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace util {
    static PyObject *t_Iterator_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Iterator_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Iterator_of_(t_Iterator *self, PyObject *args);
    static PyObject *t_Iterator_hasNext(t_Iterator *self);
    static PyObject *t_Iterator_next(t_Iterator *self);
    static PyObject *t_Iterator_remove(t_Iterator *self);
    static PyObject *t_Iterator_get__parameters_(t_Iterator *self, void *data);
    static PyGetSetDef t_Iterator__fields_[] = {
      DECLARE_GET_FIELD(t_Iterator, parameters_),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Iterator__methods_[] = {
      DECLARE_METHOD(t_Iterator, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Iterator, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Iterator, of_, METH_VARARGS),
      DECLARE_METHOD(t_Iterator, hasNext, METH_NOARGS),
      DECLARE_METHOD(t_Iterator, next, METH_NOARGS),
      DECLARE_METHOD(t_Iterator, remove, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Iterator, t_Iterator, ::java::lang::Object, Iterator, abstract_init, PyObject_SelfIter, ((PyObject *(*)(::java::util::t_Iterator *)) get_generic_iterator_next< ::java::util::t_Iterator,::java::lang::t_Object >), t_Iterator__fields_, 0, 0);
    PyObject *t_Iterator::wrap_Object(const Iterator& object, PyTypeObject *E)
    {
      PyObject *obj = t_Iterator::wrap_Object(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Iterator *self = (t_Iterator *) obj;
        self->parameters[0] = E;
      }
      return obj;
    }

    PyObject *t_Iterator::wrap_jobject(const jobject& object, PyTypeObject *E)
    {
      PyObject *obj = t_Iterator::wrap_jobject(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Iterator *self = (t_Iterator *) obj;
        self->parameters[0] = E;
      }
      return obj;
    }

    void t_Iterator::install(PyObject *module)
    {
      installType(&PY_TYPE(Iterator), module, "Iterator", 0);
    }

    void t_Iterator::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Iterator).tp_dict, "class_", make_descriptor(Iterator::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Iterator).tp_dict, "wrapfn_", make_descriptor(t_Iterator::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Iterator).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Iterator_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Iterator::initializeClass, 1)))
        return NULL;
      return t_Iterator::wrap_Object(Iterator(((t_Iterator *) arg)->object.this$));
    }
    static PyObject *t_Iterator_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Iterator::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Iterator_of_(t_Iterator *self, PyObject *args)
    {
      if (!parseArg(args, "T", 1, &(self->parameters)))
        Py_RETURN_SELF;
      return PyErr_SetArgsError((PyObject *) self, "of_", args);
    }

    static PyObject *t_Iterator_hasNext(t_Iterator *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.hasNext());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Iterator_next(t_Iterator *self)
    {
      ::java::lang::Object result((jobject) NULL);
      OBJ_CALL(result = self->object.next());
      return self->parameters[0] != NULL ? wrapType(self->parameters[0], result.this$) : ::java::lang::t_Object::wrap_Object(result);
    }

    static PyObject *t_Iterator_remove(t_Iterator *self)
    {
      OBJ_CALL(self->object.remove());
      Py_RETURN_NONE;
    }
    static PyObject *t_Iterator_get__parameters_(t_Iterator *self, void *data)
    {
      return typeParameters(self->parameters, sizeof(self->parameters));
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/datasequence/DataSequence.h"
#include "stallone/api/datasequence/DataSequenceUtilities.h"
#include "stallone/api/datasequence/DataSequenceFactory.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace datasequence {

      ::java::lang::Class *DataSequence::class$ = NULL;
      jmethodID *DataSequence::mids$ = NULL;
      bool DataSequence::live$ = false;
      ::stallone::api::datasequence::DataSequenceFactory *DataSequence::create = NULL;
      ::stallone::api::datasequence::DataSequenceUtilities *DataSequence::util = NULL;

      jclass DataSequence::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/datasequence/DataSequence");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          create = new ::stallone::api::datasequence::DataSequenceFactory(env->getStaticObjectField(cls, "create", "Lstallone/api/datasequence/DataSequenceFactory;"));
          util = new ::stallone::api::datasequence::DataSequenceUtilities(env->getStaticObjectField(cls, "util", "Lstallone/api/datasequence/DataSequenceUtilities;"));
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      DataSequence::DataSequence() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace datasequence {
      static PyObject *t_DataSequence_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_DataSequence_instance_(PyTypeObject *type, PyObject *arg);
      static int t_DataSequence_init_(t_DataSequence *self, PyObject *args, PyObject *kwds);

      static PyMethodDef t_DataSequence__methods_[] = {
        DECLARE_METHOD(t_DataSequence, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DataSequence, instance_, METH_O | METH_CLASS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(DataSequence, t_DataSequence, ::java::lang::Object, DataSequence, t_DataSequence_init_, 0, 0, 0, 0, 0);

      void t_DataSequence::install(PyObject *module)
      {
        installType(&PY_TYPE(DataSequence), module, "DataSequence", 0);
      }

      void t_DataSequence::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(DataSequence).tp_dict, "class_", make_descriptor(DataSequence::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(DataSequence).tp_dict, "wrapfn_", make_descriptor(t_DataSequence::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(DataSequence).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(DataSequence::initializeClass);
        PyDict_SetItemString(PY_TYPE(DataSequence).tp_dict, "create", make_descriptor(::stallone::api::datasequence::t_DataSequenceFactory::wrap_Object(*DataSequence::create)));
        PyDict_SetItemString(PY_TYPE(DataSequence).tp_dict, "util", make_descriptor(::stallone::api::datasequence::t_DataSequenceUtilities::wrap_Object(*DataSequence::util)));
      }

      static PyObject *t_DataSequence_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, DataSequence::initializeClass, 1)))
          return NULL;
        return t_DataSequence::wrap_Object(DataSequence(((t_DataSequence *) arg)->object.this$));
      }
      static PyObject *t_DataSequence_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, DataSequence::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_DataSequence_init_(t_DataSequence *self, PyObject *args, PyObject *kwds)
      {
        DataSequence object((jobject) NULL);

        INT_CALL(object = DataSequence());
        self->object = object;

        return 0;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/datasequence/DataSequenceUtilities.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "java/lang/Iterable.h"
#include "java/lang/String.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace datasequence {

      ::java::lang::Class *DataSequenceUtilities::class$ = NULL;
      jmethodID *DataSequenceUtilities::mids$ = NULL;
      bool DataSequenceUtilities::live$ = false;

      jclass DataSequenceUtilities::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/datasequence/DataSequenceUtilities");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_mean_c668b3b0] = env->getMethodID(cls, "mean", "(Ljava/lang/Iterable;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_readColumn_2e3d0a4b] = env->getMethodID(cls, "readColumn", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_readColumn_3b6bdd13] = env->getMethodID(cls, "readColumn", "(Ljava/lang/String;I)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_readDataList_38f3407b] = env->getMethodID(cls, "readDataList", "(Ljava/lang/String;)Lstallone/api/datasequence/IDataSequence;");
          mids$[mid_readDataSequence_38f3407b] = env->getMethodID(cls, "readDataSequence", "(Ljava/lang/String;)Lstallone/api/datasequence/IDataSequence;");
          mids$[mid_readDataTable_ae6f32f9] = env->getMethodID(cls, "readDataTable", "(Ljava/lang/String;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_readDataTable_2f8669d9] = env->getMethodID(cls, "readDataTable", "(Lstallone/api/datasequence/IDataSequence;)Lstallone/api/doubles/IDoubleArray;");
          mids$[mid_rgyr_d1cac217] = env->getMethodID(cls, "rgyr", "(Ljava/lang/Iterable;)D");
          mids$[mid_rmax_d1cac217] = env->getMethodID(cls, "rmax", "(Ljava/lang/Iterable;)D");
          mids$[mid_writeData_f5ccc47a] = env->getMethodID(cls, "writeData", "(Lstallone/api/datasequence/IDataSequence;Ljava/lang/String;)V");

          class$ = (::java::lang::Class *) new JObject(cls);
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      DataSequenceUtilities::DataSequenceUtilities() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::doubles::IDoubleArray DataSequenceUtilities::mean(const ::java::lang::Iterable & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_mean_c668b3b0], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray DataSequenceUtilities::readColumn(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_readColumn_2e3d0a4b], a0.this$, a1));
      }

      ::stallone::api::doubles::IDoubleArray DataSequenceUtilities::readColumn(const ::java::lang::String & a0, jint a1) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_readColumn_3b6bdd13], a0.this$, a1));
      }

      ::stallone::api::datasequence::IDataSequence DataSequenceUtilities::readDataList(const ::java::lang::String & a0) const
      {
        return ::stallone::api::datasequence::IDataSequence(env->callObjectMethod(this$, mids$[mid_readDataList_38f3407b], a0.this$));
      }

      ::stallone::api::datasequence::IDataSequence DataSequenceUtilities::readDataSequence(const ::java::lang::String & a0) const
      {
        return ::stallone::api::datasequence::IDataSequence(env->callObjectMethod(this$, mids$[mid_readDataSequence_38f3407b], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray DataSequenceUtilities::readDataTable(const ::java::lang::String & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_readDataTable_ae6f32f9], a0.this$));
      }

      ::stallone::api::doubles::IDoubleArray DataSequenceUtilities::readDataTable(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        return ::stallone::api::doubles::IDoubleArray(env->callObjectMethod(this$, mids$[mid_readDataTable_2f8669d9], a0.this$));
      }

      jdouble DataSequenceUtilities::rgyr(const ::java::lang::Iterable & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_rgyr_d1cac217], a0.this$);
      }

      jdouble DataSequenceUtilities::rmax(const ::java::lang::Iterable & a0) const
      {
        return env->callDoubleMethod(this$, mids$[mid_rmax_d1cac217], a0.this$);
      }

      void DataSequenceUtilities::writeData(const ::stallone::api::datasequence::IDataSequence & a0, const ::java::lang::String & a1) const
      {
        env->callVoidMethod(this$, mids$[mid_writeData_f5ccc47a], a0.this$, a1.this$);
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace datasequence {
      static PyObject *t_DataSequenceUtilities_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_DataSequenceUtilities_instance_(PyTypeObject *type, PyObject *arg);
      static int t_DataSequenceUtilities_init_(t_DataSequenceUtilities *self, PyObject *args, PyObject *kwds);
      static PyObject *t_DataSequenceUtilities_mean(t_DataSequenceUtilities *self, PyObject *arg);
      static PyObject *t_DataSequenceUtilities_readColumn(t_DataSequenceUtilities *self, PyObject *args);
      static PyObject *t_DataSequenceUtilities_readDataList(t_DataSequenceUtilities *self, PyObject *arg);
      static PyObject *t_DataSequenceUtilities_readDataSequence(t_DataSequenceUtilities *self, PyObject *arg);
      static PyObject *t_DataSequenceUtilities_readDataTable(t_DataSequenceUtilities *self, PyObject *args);
      static PyObject *t_DataSequenceUtilities_rgyr(t_DataSequenceUtilities *self, PyObject *arg);
      static PyObject *t_DataSequenceUtilities_rmax(t_DataSequenceUtilities *self, PyObject *arg);
      static PyObject *t_DataSequenceUtilities_writeData(t_DataSequenceUtilities *self, PyObject *args);

      static PyMethodDef t_DataSequenceUtilities__methods_[] = {
        DECLARE_METHOD(t_DataSequenceUtilities, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DataSequenceUtilities, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_DataSequenceUtilities, mean, METH_O),
        DECLARE_METHOD(t_DataSequenceUtilities, readColumn, METH_VARARGS),
        DECLARE_METHOD(t_DataSequenceUtilities, readDataList, METH_O),
        DECLARE_METHOD(t_DataSequenceUtilities, readDataSequence, METH_O),
        DECLARE_METHOD(t_DataSequenceUtilities, readDataTable, METH_VARARGS),
        DECLARE_METHOD(t_DataSequenceUtilities, rgyr, METH_O),
        DECLARE_METHOD(t_DataSequenceUtilities, rmax, METH_O),
        DECLARE_METHOD(t_DataSequenceUtilities, writeData, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(DataSequenceUtilities, t_DataSequenceUtilities, ::java::lang::Object, DataSequenceUtilities, t_DataSequenceUtilities_init_, 0, 0, 0, 0, 0);

      void t_DataSequenceUtilities::install(PyObject *module)
      {
        installType(&PY_TYPE(DataSequenceUtilities), module, "DataSequenceUtilities", 0);
      }

      void t_DataSequenceUtilities::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(DataSequenceUtilities).tp_dict, "class_", make_descriptor(DataSequenceUtilities::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(DataSequenceUtilities).tp_dict, "wrapfn_", make_descriptor(t_DataSequenceUtilities::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(DataSequenceUtilities).tp_dict, "boxfn_", make_descriptor(boxObject));
      }

      static PyObject *t_DataSequenceUtilities_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, DataSequenceUtilities::initializeClass, 1)))
          return NULL;
        return t_DataSequenceUtilities::wrap_Object(DataSequenceUtilities(((t_DataSequenceUtilities *) arg)->object.this$));
      }
      static PyObject *t_DataSequenceUtilities_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, DataSequenceUtilities::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_DataSequenceUtilities_init_(t_DataSequenceUtilities *self, PyObject *args, PyObject *kwds)
      {
        DataSequenceUtilities object((jobject) NULL);

        INT_CALL(object = DataSequenceUtilities());
        self->object = object;

        return 0;
      }

      static PyObject *t_DataSequenceUtilities_mean(t_DataSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::Iterable a0((jobject) NULL);
        PyTypeObject **p0;
        ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

        if (!parseArg(arg, "K", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_))
        {
          OBJ_CALL(result = self->object.mean(a0));
          return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "mean", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_readColumn(t_DataSequenceUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.readColumn(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::java::lang::String a0((jobject) NULL);
            jint a1;
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "sI", &a0, &a1))
            {
              OBJ_CALL(result = self->object.readColumn(a0, a1));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "readColumn", args);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_readDataList(t_DataSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::stallone::api::datasequence::IDataSequence result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.readDataList(a0));
          return ::stallone::api::datasequence::t_IDataSequence::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "readDataList", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_readDataSequence(t_DataSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::String a0((jobject) NULL);
        ::stallone::api::datasequence::IDataSequence result((jobject) NULL);

        if (!parseArg(arg, "s", &a0))
        {
          OBJ_CALL(result = self->object.readDataSequence(a0));
          return ::stallone::api::datasequence::t_IDataSequence::wrap_Object(result);
        }

        PyErr_SetArgsError((PyObject *) self, "readDataSequence", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_readDataTable(t_DataSequenceUtilities *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::java::lang::String a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "s", &a0))
            {
              OBJ_CALL(result = self->object.readDataTable(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IDoubleArray result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.readDataTable(a0));
              return ::stallone::api::doubles::t_IDoubleArray::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "readDataTable", args);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_rgyr(t_DataSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::Iterable a0((jobject) NULL);
        PyTypeObject **p0;
        jdouble result;

        if (!parseArg(arg, "K", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_))
        {
          OBJ_CALL(result = self->object.rgyr(a0));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "rgyr", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_rmax(t_DataSequenceUtilities *self, PyObject *arg)
      {
        ::java::lang::Iterable a0((jobject) NULL);
        PyTypeObject **p0;
        jdouble result;

        if (!parseArg(arg, "K", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_))
        {
          OBJ_CALL(result = self->object.rmax(a0));
          return PyFloat_FromDouble((double) result);
        }

        PyErr_SetArgsError((PyObject *) self, "rmax", arg);
        return NULL;
      }

      static PyObject *t_DataSequenceUtilities_writeData(t_DataSequenceUtilities *self, PyObject *args)
      {
        ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
        ::java::lang::String a1((jobject) NULL);

        if (!parseArgs(args, "ks", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
        {
          OBJ_CALL(self->object.writeData(a0, a1));
          Py_RETURN_NONE;
        }

        PyErr_SetArgsError((PyObject *) self, "writeData", args);
        return NULL;
      }
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "stallone/api/cluster/ClusterFactory.h"
#include "stallone/api/doubles/IMetric.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "java/lang/Iterable.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/cluster/IClustering.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace stallone {
  namespace api {
    namespace cluster {

      ::java::lang::Class *ClusterFactory::class$ = NULL;
      jmethodID *ClusterFactory::mids$ = NULL;
      bool ClusterFactory::live$ = false;
      jint ClusterFactory::METRIC_EUCLIDEAN = (jint) 0;
      jint ClusterFactory::METRIC_MINRMSD = (jint) 0;

      jclass ClusterFactory::initializeClass(bool getOnly)
      {
        if (getOnly)
          return (jclass) (live$ ? class$->this$ : NULL);
        if (class$ == NULL)
        {
          jclass cls = (jclass) env->findClass("stallone/api/cluster/ClusterFactory");

          mids$ = new jmethodID[max_mid];
          mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
          mids$[mid_createDensityBased_dcea8e74] = env->getMethodID(cls, "createDensityBased", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createDensityBased_544bdf51] = env->getMethodID(cls, "createDensityBased", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createDensityBased_66646433] = env->getMethodID(cls, "createDensityBased", "(Lstallone/api/datasequence/IDataSequence;DI)Lstallone/api/cluster/IClustering;");
          mids$[mid_createDensityBased_810dc3c0] = env->getMethodID(cls, "createDensityBased", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;DI)Lstallone/api/cluster/IClustering;");
          mids$[mid_createFixed_dca311aa] = env->getMethodID(cls, "createFixed", "(Lstallone/api/datasequence/IDataSequence;)Lstallone/api/cluster/IClustering;");
          mids$[mid_createFixed_4e346fc0] = env->getMethodID(cls, "createFixed", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/datasequence/IDataSequence;)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKcenter_a743e72e] = env->getMethodID(cls, "createKcenter", "(I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKcenter_dcea8e74] = env->getMethodID(cls, "createKcenter", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKcenter_9a5b1f9b] = env->getMethodID(cls, "createKcenter", "(Lstallone/api/doubles/IMetric;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKcenter_544bdf51] = env->getMethodID(cls, "createKcenter", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKcenter_591b59c5] = env->getMethodID(cls, "createKcenter", "(Ljava/lang/Iterable;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKcenter_d426b214] = env->getMethodID(cls, "createKcenter", "(Ljava/lang/Iterable;ILstallone/api/doubles/IMetric;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_a743e72e] = env->getMethodID(cls, "createKmeans", "(I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_dcea8e74] = env->getMethodID(cls, "createKmeans", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_b5b0c110] = env->getMethodID(cls, "createKmeans", "(II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_591b59c5] = env->getMethodID(cls, "createKmeans", "(Ljava/lang/Iterable;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_7777b89b] = env->getMethodID(cls, "createKmeans", "(Lstallone/api/doubles/IMetric;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_c5cf10c2] = env->getMethodID(cls, "createKmeans", "(Lstallone/api/datasequence/IDataSequence;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_504866f1] = env->getMethodID(cls, "createKmeans", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_a5d60e49] = env->getMethodID(cls, "createKmeans", "(Ljava/lang/Iterable;III)Lstallone/api/cluster/IClustering;");
          mids$[mid_createKmeans_f2ad93a2] = env->getMethodID(cls, "createKmeans", "(Ljava/lang/Iterable;ILstallone/api/doubles/IMetric;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRandom_a743e72e] = env->getMethodID(cls, "createRandom", "(I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRandom_dcea8e74] = env->getMethodID(cls, "createRandom", "(Lstallone/api/datasequence/IDataSequence;I)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRandomCompact_b5b0c110] = env->getMethodID(cls, "createRandomCompact", "(II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRandomCompact_c5cf10c2] = env->getMethodID(cls, "createRandomCompact", "(Lstallone/api/datasequence/IDataSequence;II)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRegularSpatial_22ddb313] = env->getMethodID(cls, "createRegularSpatial", "(Lstallone/api/datasequence/IDataSequence;D)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRegularSpatial_a59e2bf6] = env->getMethodID(cls, "createRegularSpatial", "(Lstallone/api/datasequence/IDataSequence;Lstallone/api/doubles/IMetric;D)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRegularSpatial_532aac9e] = env->getMethodID(cls, "createRegularSpatial", "(Ljava/lang/Iterable;ID)Lstallone/api/cluster/IClustering;");
          mids$[mid_createRegularSpatial_1f660d8f] = env->getMethodID(cls, "createRegularSpatial", "(Ljava/lang/Iterable;ILstallone/api/doubles/IMetric;D)Lstallone/api/cluster/IClustering;");
          mids$[mid_metric_419347da] = env->getMethodID(cls, "metric", "(II)Lstallone/api/doubles/IMetric;");

          class$ = (::java::lang::Class *) new JObject(cls);
          cls = (jclass) class$->this$;

          METRIC_EUCLIDEAN = env->getStaticIntField(cls, "METRIC_EUCLIDEAN");
          METRIC_MINRMSD = env->getStaticIntField(cls, "METRIC_MINRMSD");
          live$ = true;
        }
        return (jclass) class$->this$;
      }

      ClusterFactory::ClusterFactory() : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

      ::stallone::api::cluster::IClustering ClusterFactory::createDensityBased(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createDensityBased_dcea8e74], a0.this$, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createDensityBased(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createDensityBased_544bdf51], a0.this$, a1.this$, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createDensityBased(const ::stallone::api::datasequence::IDataSequence & a0, jdouble a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createDensityBased_66646433], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createDensityBased(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jdouble a2, jint a3) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createDensityBased_810dc3c0], a0.this$, a1.this$, a2, a3));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createFixed(const ::stallone::api::datasequence::IDataSequence & a0) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createFixed_dca311aa], a0.this$));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createFixed(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::datasequence::IDataSequence & a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createFixed_4e346fc0], a0.this$, a1.this$));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKcenter(jint a0) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKcenter_a743e72e], a0));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKcenter(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKcenter_dcea8e74], a0.this$, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKcenter(const ::stallone::api::doubles::IMetric & a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKcenter_9a5b1f9b], a0.this$, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKcenter(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKcenter_544bdf51], a0.this$, a1.this$, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKcenter(const ::java::lang::Iterable & a0, jint a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKcenter_591b59c5], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKcenter(const ::java::lang::Iterable & a0, jint a1, const ::stallone::api::doubles::IMetric & a2, jint a3) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKcenter_d426b214], a0.this$, a1, a2.this$, a3));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(jint a0) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_a743e72e], a0));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_dcea8e74], a0.this$, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(jint a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_b5b0c110], a0, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::java::lang::Iterable & a0, jint a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_591b59c5], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::stallone::api::doubles::IMetric & a0, jint a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_7777b89b], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::stallone::api::datasequence::IDataSequence & a0, jint a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_c5cf10c2], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jint a2, jint a3) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_504866f1], a0.this$, a1.this$, a2, a3));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::java::lang::Iterable & a0, jint a1, jint a2, jint a3) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_a5d60e49], a0.this$, a1, a2, a3));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createKmeans(const ::java::lang::Iterable & a0, jint a1, const ::stallone::api::doubles::IMetric & a2, jint a3, jint a4) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createKmeans_f2ad93a2], a0.this$, a1, a2.this$, a3, a4));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRandom(jint a0) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRandom_a743e72e], a0));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRandom(const ::stallone::api::datasequence::IDataSequence & a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRandom_dcea8e74], a0.this$, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRandomCompact(jint a0, jint a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRandomCompact_b5b0c110], a0, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRandomCompact(const ::stallone::api::datasequence::IDataSequence & a0, jint a1, jint a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRandomCompact_c5cf10c2], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRegularSpatial(const ::stallone::api::datasequence::IDataSequence & a0, jdouble a1) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRegularSpatial_22ddb313], a0.this$, a1));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRegularSpatial(const ::stallone::api::datasequence::IDataSequence & a0, const ::stallone::api::doubles::IMetric & a1, jdouble a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRegularSpatial_a59e2bf6], a0.this$, a1.this$, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRegularSpatial(const ::java::lang::Iterable & a0, jint a1, jdouble a2) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRegularSpatial_532aac9e], a0.this$, a1, a2));
      }

      ::stallone::api::cluster::IClustering ClusterFactory::createRegularSpatial(const ::java::lang::Iterable & a0, jint a1, const ::stallone::api::doubles::IMetric & a2, jdouble a3) const
      {
        return ::stallone::api::cluster::IClustering(env->callObjectMethod(this$, mids$[mid_createRegularSpatial_1f660d8f], a0.this$, a1, a2.this$, a3));
      }

      ::stallone::api::doubles::IMetric ClusterFactory::metric(jint a0, jint a1) const
      {
        return ::stallone::api::doubles::IMetric(env->callObjectMethod(this$, mids$[mid_metric_419347da], a0, a1));
      }
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace stallone {
  namespace api {
    namespace cluster {
      static PyObject *t_ClusterFactory_cast_(PyTypeObject *type, PyObject *arg);
      static PyObject *t_ClusterFactory_instance_(PyTypeObject *type, PyObject *arg);
      static int t_ClusterFactory_init_(t_ClusterFactory *self, PyObject *args, PyObject *kwds);
      static PyObject *t_ClusterFactory_createDensityBased(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_createFixed(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_createKcenter(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_createKmeans(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_createRandom(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_createRandomCompact(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_createRegularSpatial(t_ClusterFactory *self, PyObject *args);
      static PyObject *t_ClusterFactory_metric(t_ClusterFactory *self, PyObject *args);

      static PyMethodDef t_ClusterFactory__methods_[] = {
        DECLARE_METHOD(t_ClusterFactory, cast_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ClusterFactory, instance_, METH_O | METH_CLASS),
        DECLARE_METHOD(t_ClusterFactory, createDensityBased, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, createFixed, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, createKcenter, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, createKmeans, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, createRandom, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, createRandomCompact, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, createRegularSpatial, METH_VARARGS),
        DECLARE_METHOD(t_ClusterFactory, metric, METH_VARARGS),
        { NULL, NULL, 0, NULL }
      };

      DECLARE_TYPE(ClusterFactory, t_ClusterFactory, ::java::lang::Object, ClusterFactory, t_ClusterFactory_init_, 0, 0, 0, 0, 0);

      void t_ClusterFactory::install(PyObject *module)
      {
        installType(&PY_TYPE(ClusterFactory), module, "ClusterFactory", 0);
      }

      void t_ClusterFactory::initialize(PyObject *module)
      {
        PyDict_SetItemString(PY_TYPE(ClusterFactory).tp_dict, "class_", make_descriptor(ClusterFactory::initializeClass, 1));
        PyDict_SetItemString(PY_TYPE(ClusterFactory).tp_dict, "wrapfn_", make_descriptor(t_ClusterFactory::wrap_jobject));
        PyDict_SetItemString(PY_TYPE(ClusterFactory).tp_dict, "boxfn_", make_descriptor(boxObject));
        env->getClass(ClusterFactory::initializeClass);
        PyDict_SetItemString(PY_TYPE(ClusterFactory).tp_dict, "METRIC_EUCLIDEAN", make_descriptor(ClusterFactory::METRIC_EUCLIDEAN));
        PyDict_SetItemString(PY_TYPE(ClusterFactory).tp_dict, "METRIC_MINRMSD", make_descriptor(ClusterFactory::METRIC_MINRMSD));
      }

      static PyObject *t_ClusterFactory_cast_(PyTypeObject *type, PyObject *arg)
      {
        if (!(arg = castCheck(arg, ClusterFactory::initializeClass, 1)))
          return NULL;
        return t_ClusterFactory::wrap_Object(ClusterFactory(((t_ClusterFactory *) arg)->object.this$));
      }
      static PyObject *t_ClusterFactory_instance_(PyTypeObject *type, PyObject *arg)
      {
        if (!castCheck(arg, ClusterFactory::initializeClass, 0))
          Py_RETURN_FALSE;
        Py_RETURN_TRUE;
      }

      static int t_ClusterFactory_init_(t_ClusterFactory *self, PyObject *args, PyObject *kwds)
      {
        ClusterFactory object((jobject) NULL);

        INT_CALL(object = ClusterFactory());
        self->object = object;

        return 0;
      }

      static PyObject *t_ClusterFactory_createDensityBased(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createDensityBased(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kKI", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.createDensityBased(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jdouble a1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kDI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createDensityBased(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jdouble a2;
            jint a3;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kKDI", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2, &a3))
            {
              OBJ_CALL(result = self->object.createDensityBased(a0, a1, a2, a3));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createDensityBased", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_createFixed(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "k", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0))
            {
              OBJ_CALL(result = self->object.createFixed(a0));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::datasequence::IDataSequence a1((jobject) NULL);
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kk", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createFixed(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createFixed", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_createKcenter(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.createKcenter(a0));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createKcenter(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IMetric a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KI", ::stallone::api::doubles::IMetric::initializeClass, &a0, &p0, ::stallone::api::doubles::t_IMetric::parameters_, &a1))
            {
              OBJ_CALL(result = self->object.createKcenter(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kKI", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.createKcenter(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KII", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createKcenter(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::doubles::IMetric a2((jobject) NULL);
            PyTypeObject **p2;
            jint a3;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KIKI", ::java::lang::Iterable::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2, &p2, ::stallone::api::doubles::t_IMetric::parameters_, &a3))
            {
              OBJ_CALL(result = self->object.createKcenter(a0, a1, a2, a3));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createKcenter", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_createKmeans(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.createKmeans(a0));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            jint a0;
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KII", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::stallone::api::doubles::IMetric a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KII", ::stallone::api::doubles::IMetric::initializeClass, &a0, &p0, ::stallone::api::doubles::t_IMetric::parameters_, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kII", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jint a2;
            jint a3;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kKII", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2, &a3))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1, a2, a3));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            jint a2;
            jint a3;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KIII", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2, &a3))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1, a2, a3));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 5:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::doubles::IMetric a2((jobject) NULL);
            PyTypeObject **p2;
            jint a3;
            jint a4;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KIKII", ::java::lang::Iterable::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2, &p2, ::stallone::api::doubles::t_IMetric::parameters_, &a3, &a4))
            {
              OBJ_CALL(result = self->object.createKmeans(a0, a1, a2, a3, a4));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createKmeans", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_createRandom(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 1:
          {
            jint a0;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "I", &a0))
            {
              OBJ_CALL(result = self->object.createRandom(a0));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kI", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createRandom(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createRandom", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_createRandomCompact(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            jint a0;
            jint a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "II", &a0, &a1))
            {
              OBJ_CALL(result = self->object.createRandomCompact(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jint a1;
            jint a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kII", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createRandomCompact(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createRandomCompact", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_createRegularSpatial(t_ClusterFactory *self, PyObject *args)
      {
        switch (PyTuple_GET_SIZE(args)) {
         case 2:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            jdouble a1;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kD", ::stallone::api::datasequence::IDataSequence::initializeClass, &a0, &a1))
            {
              OBJ_CALL(result = self->object.createRegularSpatial(a0, a1));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 3:
          {
            ::stallone::api::datasequence::IDataSequence a0((jobject) NULL);
            ::stallone::api::doubles::IMetric a1((jobject) NULL);
            PyTypeObject **p1;
            jdouble a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "kKD", ::stallone::api::datasequence::IDataSequence::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &a1, &p1, ::stallone::api::doubles::t_IMetric::parameters_, &a2))
            {
              OBJ_CALL(result = self->object.createRegularSpatial(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            jdouble a2;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KID", ::java::lang::Iterable::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2))
            {
              OBJ_CALL(result = self->object.createRegularSpatial(a0, a1, a2));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
          break;
         case 4:
          {
            ::java::lang::Iterable a0((jobject) NULL);
            PyTypeObject **p0;
            jint a1;
            ::stallone::api::doubles::IMetric a2((jobject) NULL);
            PyTypeObject **p2;
            jdouble a3;
            ::stallone::api::cluster::IClustering result((jobject) NULL);

            if (!parseArgs(args, "KIKD", ::java::lang::Iterable::initializeClass, ::stallone::api::doubles::IMetric::initializeClass, &a0, &p0, ::java::lang::t_Iterable::parameters_, &a1, &a2, &p2, ::stallone::api::doubles::t_IMetric::parameters_, &a3))
            {
              OBJ_CALL(result = self->object.createRegularSpatial(a0, a1, a2, a3));
              return ::stallone::api::cluster::t_IClustering::wrap_Object(result);
            }
          }
        }

        PyErr_SetArgsError((PyObject *) self, "createRegularSpatial", args);
        return NULL;
      }

      static PyObject *t_ClusterFactory_metric(t_ClusterFactory *self, PyObject *args)
      {
        jint a0;
        jint a1;
        ::stallone::api::doubles::IMetric result((jobject) NULL);

        if (!parseArgs(args, "II", &a0, &a1))
        {
          OBJ_CALL(result = self->object.metric(a0, a1));
          return ::stallone::api::doubles::t_IMetric::wrap_Object(result, &::stallone::api::doubles::PY_TYPE(IDoubleArray));
        }

        PyErr_SetArgsError((PyObject *) self, "metric", args);
        return NULL;
      }
    }
  }
}
