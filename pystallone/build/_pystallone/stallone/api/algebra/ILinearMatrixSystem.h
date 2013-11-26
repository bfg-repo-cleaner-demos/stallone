#ifndef stallone_api_algebra_ILinearMatrixSystem_H
#define stallone_api_algebra_ILinearMatrixSystem_H

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
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class ILinearMatrixSystem : public ::java::lang::Object {
      public:
        enum {
          mid_getSolutionMatrix_1d53e353,
          mid_perform_54c6a166,
          mid_setCoefficientMatrix_0253084a,
          mid_setMatrix_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ILinearMatrixSystem(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ILinearMatrixSystem(const ILinearMatrixSystem& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray getSolutionMatrix() const;
        void perform() const;
        void setCoefficientMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
        void setMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(ILinearMatrixSystem);

      class t_ILinearMatrixSystem {
      public:
        PyObject_HEAD
        ILinearMatrixSystem object;
        static PyObject *wrap_Object(const ILinearMatrixSystem&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
