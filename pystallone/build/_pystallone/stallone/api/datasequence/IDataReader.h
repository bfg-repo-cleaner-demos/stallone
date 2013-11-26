#ifndef stallone_api_datasequence_IDataReader_H
#define stallone_api_datasequence_IDataReader_H

#include "stallone/api/datasequence/IDataSequence.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
  namespace util {
    class Iterator;
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

      class IDataReader : public ::stallone::api::datasequence::IDataSequence {
      public:
        enum {
          mid_close_54c6a166,
          mid_dimension_54c6a179,
          mid_get_e3ead0f5,
          mid_iterator_40858c90,
          mid_load_26787975,
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

        explicit IDataReader(jobject obj) : ::stallone::api::datasequence::IDataSequence(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDataReader(const IDataReader& obj) : ::stallone::api::datasequence::IDataSequence(obj) {}

        void close() const;
        jint dimension() const;
        ::stallone::api::doubles::IDoubleArray get(jint) const;
        ::java::util::Iterator iterator() const;
        ::stallone::api::datasequence::IDataSequence load() const;
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
    namespace datasequence {
      extern PyTypeObject PY_TYPE(IDataReader);

      class t_IDataReader {
      public:
        PyObject_HEAD
        IDataReader object;
        static PyObject *wrap_Object(const IDataReader&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
