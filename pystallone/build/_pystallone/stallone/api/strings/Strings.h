#ifndef stallone_api_strings_Strings_H
#define stallone_api_strings_Strings_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace strings {
      class StringFactory;
      class StringUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace strings {

      class Strings : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Strings(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Strings(const Strings& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::strings::StringFactory *create;
        static ::stallone::api::strings::StringUtilities *util;

        Strings();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace strings {
      extern PyTypeObject PY_TYPE(Strings);

      class t_Strings {
      public:
        PyObject_HEAD
        Strings object;
        static PyObject *wrap_Object(const Strings&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
