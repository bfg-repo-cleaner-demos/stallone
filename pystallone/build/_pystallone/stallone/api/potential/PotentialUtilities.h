#ifndef stallone_api_potential_PotentialUtilities_H
#define stallone_api_potential_PotentialUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace potential {

      class PotentialUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit PotentialUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        PotentialUtilities(const PotentialUtilities& obj) : ::java::lang::Object(obj) {}

        PotentialUtilities();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace potential {
      extern PyTypeObject PY_TYPE(PotentialUtilities);

      class t_PotentialUtilities {
      public:
        PyObject_HEAD
        PotentialUtilities object;
        static PyObject *wrap_Object(const PotentialUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
