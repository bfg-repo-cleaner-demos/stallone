#ifndef stallone_api_ICopyable_H
#define stallone_api_ICopyable_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {

    class ICopyable : public ::java::lang::Object {
    public:
      enum {
        mid_copy_846352c3,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit ICopyable(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      ICopyable(const ICopyable& obj) : ::java::lang::Object(obj) {}

      ::java::lang::Object copy() const;
    };
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    extern PyTypeObject PY_TYPE(ICopyable);

    class t_ICopyable {
    public:
      PyObject_HEAD
      ICopyable object;
      PyTypeObject *parameters[1];
      static PyTypeObject **parameters_(t_ICopyable *self)
      {
        return (PyTypeObject **) &(self->parameters);
      }
      static PyObject *wrap_Object(const ICopyable&);
      static PyObject *wrap_jobject(const jobject&);
      static PyObject *wrap_Object(const ICopyable&, PyTypeObject *);
      static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
