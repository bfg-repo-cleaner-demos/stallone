#ifndef stallone_api_algebra_AlgebraFactory$LinearSystemEnum_H
#define stallone_api_algebra_AlgebraFactory$LinearSystemEnum_H

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

      class AlgebraFactory$LinearSystemEnum : public ::java::lang::Enum {
      public:
        enum {
          mid_isDense_54c6a16a,
          mid_valueOf_ac6d5092,
          mid_values_60249fb8,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit AlgebraFactory$LinearSystemEnum(jobject obj) : ::java::lang::Enum(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        AlgebraFactory$LinearSystemEnum(const AlgebraFactory$LinearSystemEnum& obj) : ::java::lang::Enum(obj) {}

        static AlgebraFactory$LinearSystemEnum *DENSE_QR;
        static AlgebraFactory$LinearSystemEnum *SPARSE_MTJ_BiCG;
        static AlgebraFactory$LinearSystemEnum *SPARSE_MTJ_CG;

        jboolean isDense() const;
        static AlgebraFactory$LinearSystemEnum valueOf(const ::java::lang::String &);
        static JArray< AlgebraFactory$LinearSystemEnum > values();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(AlgebraFactory$LinearSystemEnum);

      class t_AlgebraFactory$LinearSystemEnum {
      public:
        PyObject_HEAD
        AlgebraFactory$LinearSystemEnum object;
        static PyObject *wrap_Object(const AlgebraFactory$LinearSystemEnum&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
