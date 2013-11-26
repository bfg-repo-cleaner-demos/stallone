#ifndef stallone_api_algebra_IPartialEigensystem_H
#define stallone_api_algebra_IPartialEigensystem_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace complex {
      class IComplexArray;
    }
    namespace algebra {
      class IComplexNumber;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class IPartialEigensystem : public ::java::lang::Object {
      public:
        enum {
          mid_getEigenvalue_3219f116,
          mid_getLeftEigenvector_f6210079,
          mid_getNumberOfAvailableEigenvectors_54c6a179,
          mid_getRightEigenvector_f6210079,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IPartialEigensystem(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IPartialEigensystem(const IPartialEigensystem& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::algebra::IComplexNumber getEigenvalue(jint) const;
        ::stallone::api::complex::IComplexArray getLeftEigenvector(jint) const;
        jint getNumberOfAvailableEigenvectors() const;
        ::stallone::api::complex::IComplexArray getRightEigenvector(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(IPartialEigensystem);

      class t_IPartialEigensystem {
      public:
        PyObject_HEAD
        IPartialEigensystem object;
        static PyObject *wrap_Object(const IPartialEigensystem&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
