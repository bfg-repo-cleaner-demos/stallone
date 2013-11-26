#ifndef stallone_api_discretization_DiscretizationUtilities_H
#define stallone_api_discretization_DiscretizationUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace discretization {

      class DiscretizationUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DiscretizationUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DiscretizationUtilities(const DiscretizationUtilities& obj) : ::java::lang::Object(obj) {}

        DiscretizationUtilities();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace discretization {
      extern PyTypeObject PY_TYPE(DiscretizationUtilities);

      class t_DiscretizationUtilities {
      public:
        PyObject_HEAD
        DiscretizationUtilities object;
        static PyObject *wrap_Object(const DiscretizationUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
