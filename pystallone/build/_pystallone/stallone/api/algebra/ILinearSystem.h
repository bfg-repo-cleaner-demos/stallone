#ifndef stallone_api_algebra_ILinearSystem_H
#define stallone_api_algebra_ILinearSystem_H

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

      class ILinearSystem : public ::java::lang::Object {
      public:
        enum {
          mid_getSolutionVector_1d53e353,
          mid_perform_54c6a166,
          mid_setCoefficientVector_0253084a,
          mid_setMatrix_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ILinearSystem(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ILinearSystem(const ILinearSystem& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray getSolutionVector() const;
        void perform() const;
        void setCoefficientVector(const ::stallone::api::doubles::IDoubleArray &) const;
        void setMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(ILinearSystem);

      class t_ILinearSystem {
      public:
        PyObject_HEAD
        ILinearSystem object;
        static PyObject *wrap_Object(const ILinearSystem&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
