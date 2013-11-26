#ifndef stallone_api_algebra_ILUDecomposition_H
#define stallone_api_algebra_ILUDecomposition_H

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

      class ILUDecomposition : public ::java::lang::Object {
      public:
        enum {
          mid_det_54c6a174,
          mid_getL_1d53e353,
          mid_getU_1d53e353,
          mid_isNonsingular_54c6a16a,
          mid_perform_54c6a166,
          mid_setMatrix_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ILUDecomposition(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ILUDecomposition(const ILUDecomposition& obj) : ::java::lang::Object(obj) {}

        jdouble det() const;
        ::stallone::api::doubles::IDoubleArray getL() const;
        ::stallone::api::doubles::IDoubleArray getU() const;
        jboolean isNonsingular() const;
        void perform() const;
        void setMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(ILUDecomposition);

      class t_ILUDecomposition {
      public:
        PyObject_HEAD
        ILUDecomposition object;
        static PyObject *wrap_Object(const ILUDecomposition&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
