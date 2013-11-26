#ifndef stallone_api_datasequence_IDataWriter_H
#define stallone_api_datasequence_IDataWriter_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
    class Iterable;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace datasequence {

      class IDataWriter : public ::java::lang::Object {
      public:
        enum {
          mid_add_0253084a,
          mid_addAll_d1cac205,
          mid_close_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDataWriter(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDataWriter(const IDataWriter& obj) : ::java::lang::Object(obj) {}

        void add(const ::stallone::api::doubles::IDoubleArray &) const;
        void addAll(const ::java::lang::Iterable &) const;
        void close() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(IDataWriter);

      class t_IDataWriter {
      public:
        PyObject_HEAD
        IDataWriter object;
        static PyObject *wrap_Object(const IDataWriter&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
