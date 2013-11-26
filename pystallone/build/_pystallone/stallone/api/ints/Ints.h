#ifndef stallone_api_ints_Ints_H
#define stallone_api_ints_Ints_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IntFactory;
      class IntUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class Ints : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Ints(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Ints(const Ints& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::ints::IntFactory *create;
        static ::stallone::api::ints::IntUtilities *util;

        Ints();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(Ints);

      class t_Ints {
      public:
        PyObject_HEAD
        Ints object;
        static PyObject *wrap_Object(const Ints&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
