#ifndef stallone_api_potential_Potentials_H
#define stallone_api_potential_Potentials_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace potential {
      class PotentialFactory;
      class PotentialUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace potential {

      class Potentials : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Potentials(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Potentials(const Potentials& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::potential::PotentialFactory *create;
        static ::stallone::api::potential::PotentialUtilities *util;

        Potentials();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace potential {
      extern PyTypeObject PY_TYPE(Potentials);

      class t_Potentials {
      public:
        PyObject_HEAD
        Potentials object;
        static PyObject *wrap_Object(const Potentials&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
