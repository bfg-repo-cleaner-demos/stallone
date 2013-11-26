#ifndef stallone_api_IAlgorithm_H
#define stallone_api_IAlgorithm_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {

    class IAlgorithm : public ::java::lang::Object {
    public:
      enum {
        mid_perform_54c6a166,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit IAlgorithm(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      IAlgorithm(const IAlgorithm& obj) : ::java::lang::Object(obj) {}

      void perform() const;
    };
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    extern PyTypeObject PY_TYPE(IAlgorithm);

    class t_IAlgorithm {
    public:
      PyObject_HEAD
      IAlgorithm object;
      static PyObject *wrap_Object(const IAlgorithm&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
