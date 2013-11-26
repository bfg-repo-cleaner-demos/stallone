#ifndef stallone_api_algebra_ICholeskyDecomposition_H
#define stallone_api_algebra_ICholeskyDecomposition_H

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

      class ICholeskyDecomposition : public ::java::lang::Object {
      public:
        enum {
          mid_getInputMatrix_1d53e353,
          mid_getRMatrix_1d53e353,
          mid_hasDecomposition_54c6a16a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ICholeskyDecomposition(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ICholeskyDecomposition(const ICholeskyDecomposition& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray getInputMatrix() const;
        ::stallone::api::doubles::IDoubleArray getRMatrix() const;
        jboolean hasDecomposition() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(ICholeskyDecomposition);

      class t_ICholeskyDecomposition {
      public:
        PyObject_HEAD
        ICholeskyDecomposition object;
        static PyObject *wrap_Object(const ICholeskyDecomposition&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
