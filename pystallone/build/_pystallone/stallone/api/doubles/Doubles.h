#ifndef stallone_api_doubles_Doubles_H
#define stallone_api_doubles_Doubles_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class DoubleUtilities;
      class DoubleFactory;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class Doubles : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Doubles(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Doubles(const Doubles& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::doubles::DoubleFactory *create;
        static ::stallone::api::doubles::DoubleUtilities *util;

        Doubles();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(Doubles);

      class t_Doubles {
      public:
        PyObject_HEAD
        Doubles object;
        static PyObject *wrap_Object(const Doubles&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
