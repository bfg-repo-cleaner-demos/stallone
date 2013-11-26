#ifndef stallone_api_algebra_IEigenvalueDecomposition_H
#define stallone_api_algebra_IEigenvalueDecomposition_H

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
    }
    namespace complex {
      class IComplexArray;
    }
    namespace algebra {
      class IComplexNumber;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class IEigenvalueDecomposition : public ::java::lang::Object {
      public:
        enum {
          mid_D_d54418bb,
          mid_L_d54418bb,
          mid_R_d54418bb,
          mid_availableEigenpairs_54c6a179,
          mid_fullRank_54c6a179,
          mid_getDiagonalMatrix_d54418bb,
          mid_getEval_d54418bb,
          mid_getEval_3219f116,
          mid_getEvalIm_1d53e353,
          mid_getEvalIm_39c7bd2e,
          mid_getEvalNorm_1d53e353,
          mid_getEvalNorm_39c7bd2e,
          mid_getEvalRe_1d53e353,
          mid_getEvalRe_39c7bd2e,
          mid_getLeftEigenvector_f6210079,
          mid_getLeftEigenvectorMatrix_d54418bb,
          mid_getRightEigenvector_f6210079,
          mid_getRightEigenvectorMatrix_d54418bb,
          mid_hasLeftEigenvectors_54c6a16a,
          mid_hasRightEigenvectors_54c6a16a,
          mid_sortNormAscending_54c6a166,
          mid_sortNormDescending_54c6a166,
          mid_sortRealAscending_54c6a166,
          mid_sortRealDescending_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IEigenvalueDecomposition(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IEigenvalueDecomposition(const IEigenvalueDecomposition& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::complex::IComplexArray D() const;
        ::stallone::api::complex::IComplexArray L() const;
        ::stallone::api::complex::IComplexArray R() const;
        jint availableEigenpairs() const;
        jint fullRank() const;
        ::stallone::api::complex::IComplexArray getDiagonalMatrix() const;
        ::stallone::api::complex::IComplexArray getEval() const;
        ::stallone::api::algebra::IComplexNumber getEval(jint) const;
        ::stallone::api::doubles::IDoubleArray getEvalIm() const;
        jdouble getEvalIm(jint) const;
        ::stallone::api::doubles::IDoubleArray getEvalNorm() const;
        jdouble getEvalNorm(jint) const;
        ::stallone::api::doubles::IDoubleArray getEvalRe() const;
        jdouble getEvalRe(jint) const;
        ::stallone::api::complex::IComplexArray getLeftEigenvector(jint) const;
        ::stallone::api::complex::IComplexArray getLeftEigenvectorMatrix() const;
        ::stallone::api::complex::IComplexArray getRightEigenvector(jint) const;
        ::stallone::api::complex::IComplexArray getRightEigenvectorMatrix() const;
        jboolean hasLeftEigenvectors() const;
        jboolean hasRightEigenvectors() const;
        void sortNormAscending() const;
        void sortNormDescending() const;
        void sortRealAscending() const;
        void sortRealDescending() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(IEigenvalueDecomposition);

      class t_IEigenvalueDecomposition {
      public:
        PyObject_HEAD
        IEigenvalueDecomposition object;
        static PyObject *wrap_Object(const IEigenvalueDecomposition&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
