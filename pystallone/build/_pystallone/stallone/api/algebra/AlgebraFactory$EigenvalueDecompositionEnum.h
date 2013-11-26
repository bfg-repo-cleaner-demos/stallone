#ifndef stallone_api_algebra_AlgebraFactory$EigenvalueDecompositionEnum_H
#define stallone_api_algebra_AlgebraFactory$EigenvalueDecompositionEnum_H

#include "java/lang/Enum.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class AlgebraFactory$EigenvalueDecompositionEnum : public ::java::lang::Enum {
      public:
        enum {
          mid_isDense_54c6a16a,
          mid_valueOf_83753791,
          mid_values_ccbe51eb,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit AlgebraFactory$EigenvalueDecompositionEnum(jobject obj) : ::java::lang::Enum(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        AlgebraFactory$EigenvalueDecompositionEnum(const AlgebraFactory$EigenvalueDecompositionEnum& obj) : ::java::lang::Enum(obj) {}

        static AlgebraFactory$EigenvalueDecompositionEnum *DENSE_BLAS;
        static AlgebraFactory$EigenvalueDecompositionEnum *SPARSE_ARPACK;

        jboolean isDense() const;
        static AlgebraFactory$EigenvalueDecompositionEnum valueOf(const ::java::lang::String &);
        static JArray< AlgebraFactory$EigenvalueDecompositionEnum > values();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(AlgebraFactory$EigenvalueDecompositionEnum);

      class t_AlgebraFactory$EigenvalueDecompositionEnum {
      public:
        PyObject_HEAD
        AlgebraFactory$EigenvalueDecompositionEnum object;
        static PyObject *wrap_Object(const AlgebraFactory$EigenvalueDecompositionEnum&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
