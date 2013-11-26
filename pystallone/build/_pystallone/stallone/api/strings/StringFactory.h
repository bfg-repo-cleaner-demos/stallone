#ifndef stallone_api_strings_StringFactory_H
#define stallone_api_strings_StringFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace strings {

      class StringFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit StringFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        StringFactory(const StringFactory& obj) : ::java::lang::Object(obj) {}

        StringFactory();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace strings {
      extern PyTypeObject PY_TYPE(StringFactory);

      class t_StringFactory {
      public:
        PyObject_HEAD
        StringFactory object;
        static PyObject *wrap_Object(const StringFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
