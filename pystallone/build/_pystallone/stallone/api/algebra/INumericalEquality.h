#ifndef stallone_api_algebra_INumericalEquality_H
#define stallone_api_algebra_INumericalEquality_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class INumericalEquality : public ::java::lang::Object {
      public:
        enum {
          mid_numericallyEqual_d0549eb5,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit INumericalEquality(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        INumericalEquality(const INumericalEquality& obj) : ::java::lang::Object(obj) {}

        jboolean numericallyEqual(const ::java::lang::Object &, const ::java::lang::Object &, jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(INumericalEquality);

      class t_INumericalEquality {
      public:
        PyObject_HEAD
        INumericalEquality object;
        PyTypeObject *parameters[1];
        static PyTypeObject **parameters_(t_INumericalEquality *self)
        {
          return (PyTypeObject **) &(self->parameters);
        }
        static PyObject *wrap_Object(const INumericalEquality&);
        static PyObject *wrap_jobject(const jobject&);
        static PyObject *wrap_Object(const INumericalEquality&, PyTypeObject *);
        static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
