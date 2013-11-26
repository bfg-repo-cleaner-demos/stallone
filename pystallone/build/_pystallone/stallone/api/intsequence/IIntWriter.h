#ifndef stallone_api_intsequence_IIntWriter_H
#define stallone_api_intsequence_IIntWriter_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
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

      class IIntWriter : public ::java::lang::Object {
      public:
        enum {
          mid_add_39c7bd3c,
          mid_addAll_059aa494,
          mid_close_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntWriter(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntWriter(const IIntWriter& obj) : ::java::lang::Object(obj) {}

        void add(jint) const;
        void addAll(const ::stallone::api::ints::IIntArray &) const;
        void close() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace intsequence {
      extern PyTypeObject PY_TYPE(IIntWriter);

      class t_IIntWriter {
      public:
        PyObject_HEAD
        IIntWriter object;
        static PyObject *wrap_Object(const IIntWriter&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
