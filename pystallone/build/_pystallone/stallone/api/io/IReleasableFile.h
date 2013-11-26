#ifndef stallone_api_io_IReleasableFile_H
#define stallone_api_io_IReleasableFile_H

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

      class IReleasableFile : public ::java::lang::Object {
      public:
        enum {
          mid_close_54c6a166,
          mid_getFileName_14c7b5c5,
          mid_open_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IReleasableFile(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IReleasableFile(const IReleasableFile& obj) : ::java::lang::Object(obj) {}

        void close() const;
        ::java::lang::String getFileName() const;
        void open() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace io {
      extern PyTypeObject PY_TYPE(IReleasableFile);

      class t_IReleasableFile {
      public:
        PyObject_HEAD
        IReleasableFile object;
        static PyObject *wrap_Object(const IReleasableFile&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
