#ifndef stallone_api_algebra_IQRDecomposition_H
#define stallone_api_algebra_IQRDecomposition_H

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

      class IQRDecomposition : public ::java::lang::Object {
      public:
        enum {
          mid_getQ_1d53e353,
          mid_getR_1d53e353,
          mid_isFullRank_54c6a16a,
          mid_perform_54c6a166,
          mid_setMatrix_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IQRDecomposition(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IQRDecomposition(const IQRDecomposition& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray getQ() const;
        ::stallone::api::doubles::IDoubleArray getR() const;
        jboolean isFullRank() const;
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
      extern PyTypeObject PY_TYPE(IQRDecomposition);

      class t_IQRDecomposition {
      public:
        PyObject_HEAD
        IQRDecomposition object;
        static PyObject *wrap_Object(const IQRDecomposition&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
