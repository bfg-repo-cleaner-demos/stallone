#ifndef stallone_api_algebra_IEigenvalueSolver_H
#define stallone_api_algebra_IEigenvalueSolver_H

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
    namespace algebra {
      class IEigenvalueDecomposition;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class IEigenvalueSolver : public ::java::lang::Object {
      public:
        enum {
          mid_getResult_706a1153,
          mid_perform_54c6a166,
          mid_setMatrix_0253084a,
          mid_setNumberOfRequestedEigenvalues_39c7bd3c,
          mid_setPerformLeftComputation_bb0c767f,
          mid_setPerformRightComputation_bb0c767f,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IEigenvalueSolver(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IEigenvalueSolver(const IEigenvalueSolver& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::algebra::IEigenvalueDecomposition getResult() const;
        void perform() const;
        void setMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
        void setNumberOfRequestedEigenvalues(jint) const;
        void setPerformLeftComputation(jboolean) const;
        void setPerformRightComputation(jboolean) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(IEigenvalueSolver);

      class t_IEigenvalueSolver {
      public:
        PyObject_HEAD
        IEigenvalueSolver object;
        static PyObject *wrap_Object(const IEigenvalueSolver&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
