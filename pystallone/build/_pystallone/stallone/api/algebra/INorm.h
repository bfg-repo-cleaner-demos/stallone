#ifndef stallone_api_algebra_INorm_H
#define stallone_api_algebra_INorm_H

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
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class INorm : public ::java::lang::Object {
      public:
        enum {
          mid_norm_02530858,
          mid_norm_ce2e75d8,
          mid_norm_77eaab7a,
          mid_norm_20d144ba,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit INorm(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        INorm(const INorm& obj) : ::java::lang::Object(obj) {}

        jdouble norm(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble norm(const ::stallone::api::complex::IComplexArray &) const;
        jdouble norm(const ::stallone::api::complex::IComplexArray &, jint) const;
        jdouble norm(const ::stallone::api::doubles::IDoubleArray &, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(INorm);

      class t_INorm {
      public:
        PyObject_HEAD
        INorm object;
        static PyObject *wrap_Object(const INorm&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
