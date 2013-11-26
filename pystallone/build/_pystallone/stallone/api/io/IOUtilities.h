#ifndef stallone_api_io_IOUtilities_H
#define stallone_api_io_IOUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace io {

      class IOUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_canCreateFile_5fdc3f44,
          mid_error_5fdc3f48,
          mid_getBasename_97a5258f,
          mid_getDirectory_97a5258f,
          mid_getExtension_97a5258f,
          mid_getFilename_97a5258f,
          mid_writeString_4a264742,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IOUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IOUtilities(const IOUtilities& obj) : ::java::lang::Object(obj) {}

        IOUtilities();

        jboolean canCreateFile(const ::java::lang::String &) const;
        void error(const ::java::lang::String &) const;
        ::java::lang::String getBasename(const ::java::lang::String &) const;
        ::java::lang::String getDirectory(const ::java::lang::String &) const;
        ::java::lang::String getExtension(const ::java::lang::String &) const;
        ::java::lang::String getFilename(const ::java::lang::String &) const;
        void writeString(const ::java::lang::String &, const ::java::lang::String &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace io {
      extern PyTypeObject PY_TYPE(IOUtilities);

      class t_IOUtilities {
      public:
        PyObject_HEAD
        IOUtilities object;
        static PyObject *wrap_Object(const IOUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
