#ifndef stallone_api_discretization_Discretization_H
#define stallone_api_discretization_Discretization_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace discretization {
      class DiscretizationFactory;
      class DiscretizationUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace discretization {

      class Discretization : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Discretization(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Discretization(const Discretization& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::discretization::DiscretizationFactory *create;
        static ::stallone::api::discretization::DiscretizationUtilities *util;

        Discretization();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace discretization {
      extern PyTypeObject PY_TYPE(Discretization);

      class t_Discretization {
      public:
        PyObject_HEAD
        Discretization object;
        static PyObject *wrap_Object(const Discretization&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
