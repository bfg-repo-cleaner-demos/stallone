#ifndef stallone_api_io_IO_H
#define stallone_api_io_IO_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace io {
      class IOUtilities;
      class IOFactory;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace io {

      class IO : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IO(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IO(const IO& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::io::IOFactory *create;
        static ::stallone::api::io::IOUtilities *util;

        IO();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace io {
      extern PyTypeObject PY_TYPE(IO);

      class t_IO {
      public:
        PyObject_HEAD
        IO object;
        static PyObject *wrap_Object(const IO&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
