#ifndef stallone_api_dynamics_Dynamics_H
#define stallone_api_dynamics_Dynamics_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace dynamics {
      class DynamicsFactory;
      class DynamicsUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace dynamics {

      class Dynamics : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Dynamics(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Dynamics(const Dynamics& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::dynamics::DynamicsFactory *create;
        static ::stallone::api::dynamics::DynamicsUtilities *util;

        Dynamics();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace dynamics {
      extern PyTypeObject PY_TYPE(Dynamics);

      class t_Dynamics {
      public:
        PyObject_HEAD
        Dynamics object;
        static PyObject *wrap_Object(const Dynamics&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
