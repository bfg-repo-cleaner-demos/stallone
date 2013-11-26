#ifndef stallone_api_algebra_AlgebraFactory_H
#define stallone_api_algebra_AlgebraFactory_H

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
    namespace algebra {
      class ILinearSystem;
      class IEigenvalueSolver;
      class ILinearMatrixSystem;
      class ICholeskyDecomposition;
      class ILUDecomposition;
      class IQRDecomposition;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class AlgebraFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_LUSolver_55a0a8d9,
          mid_QRSolver_6c4a0779,
          mid_createCholeskyDecomposition_aa69a7c2,
          mid_eigenSolver_2d5b7c70,
          mid_eigenSolver_9ed36252,
          mid_eigenSolver_36aacef2,
          mid_eigenSolver_ae618a52,
          mid_linearMatrixSolver_74c22355,
          mid_linearSolver_5463b672,
          mid_linearSolver_90696514,
          mid_concatenate_e60b36d8,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit AlgebraFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        AlgebraFactory(const AlgebraFactory& obj) : ::java::lang::Object(obj) {}

        AlgebraFactory();

        ::stallone::api::algebra::ILUDecomposition LUSolver(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IQRDecomposition QRSolver(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::ICholeskyDecomposition createCholeskyDecomposition(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IEigenvalueSolver eigenSolver(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::IEigenvalueSolver eigenSolver(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::algebra::IEigenvalueSolver eigenSolver(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        ::stallone::api::algebra::IEigenvalueSolver eigenSolver(const ::stallone::api::doubles::IDoubleArray &, jboolean, jboolean) const;
        ::stallone::api::algebra::ILinearMatrixSystem linearMatrixSolver(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::ILinearSystem linearSolver(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::algebra::ILinearSystem linearSolver(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(AlgebraFactory);

      class t_AlgebraFactory {
      public:
        PyObject_HEAD
        AlgebraFactory object;
        static PyObject *wrap_Object(const AlgebraFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
