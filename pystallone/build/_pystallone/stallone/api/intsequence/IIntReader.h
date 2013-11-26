#ifndef stallone_api_intsequence_IIntReader_H
#define stallone_api_intsequence_IIntReader_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace intsequence {

      class IIntReader : public ::java::lang::Object {
      public:
        enum {
          mid_close_54c6a166,
          mid_get_39c7bd23,
          mid_load_4ac77731,
          mid_memorySize_54c6a17a,
          mid_open_54c6a166,
          mid_scan_54c6a166,
          mid_setSource_5fdc3f48,
          mid_size_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntReader(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntReader(const IIntReader& obj) : ::java::lang::Object(obj) {}

        void close() const;
        jint get(jint) const;
        ::stallone::api::ints::IIntArray load() const;
        jlong memorySize() const;
        void open() const;
        void scan() const;
        void setSource(const ::java::lang::String &) const;
        jint size() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace intsequence {
      extern PyTypeObject PY_TYPE(IIntReader);

      class t_IIntReader {
      public:
        PyObject_HEAD
        IIntReader object;
        static PyObject *wrap_Object(const IIntReader&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
