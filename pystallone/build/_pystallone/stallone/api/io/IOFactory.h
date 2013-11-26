#ifndef stallone_api_io_IOFactory_H
#define stallone_api_io_IOFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace io {

      class IOFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IOFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IOFactory(const IOFactory& obj) : ::java::lang::Object(obj) {}

        IOFactory();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace io {
      extern PyTypeObject PY_TYPE(IOFactory);

      class t_IOFactory {
      public:
        PyObject_HEAD
        IOFactory object;
        static PyObject *wrap_Object(const IOFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
