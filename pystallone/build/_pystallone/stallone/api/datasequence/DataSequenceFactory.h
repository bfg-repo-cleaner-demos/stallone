#ifndef stallone_api_datasequence_DataSequenceFactory_H
#define stallone_api_datasequence_DataSequenceFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Iterable;
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
    namespace datasequence {
      class IDataList;
      class IDataWriter;
      class IDataSequenceLoader;
      class IDataSequence;
      class IDataReader;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace datasequence {

      class DataSequenceFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_createASCIIDataReader_66d6ac43,
          mid_createASCIIDataWriter_4e494859,
          mid_createASCIIDataWriter_352bba45,
          mid_createConsoleDataOutput_67d8e9b7,
          mid_createConsoleDataOutput_482bfdd3,
          mid_createDataWriter_85286d37,
          mid_createDatalist_15c437fc,
          mid_dataSequenceLoader_66d6ac43,
          mid_interleavedDataIterable_9bf0a4fd,
          mid_iterator_58368f82,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DataSequenceFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DataSequenceFactory(const DataSequenceFactory& obj) : ::java::lang::Object(obj) {}

        DataSequenceFactory();

        ::stallone::api::datasequence::IDataReader createASCIIDataReader(const ::java::lang::String &) const;
        ::stallone::api::datasequence::IDataWriter createASCIIDataWriter(const ::java::lang::String &, jint) const;
        ::stallone::api::datasequence::IDataWriter createASCIIDataWriter(const ::java::lang::String &, jint, const ::java::lang::String &, const ::java::lang::String &) const;
        ::stallone::api::datasequence::IDataWriter createConsoleDataOutput(jint) const;
        ::stallone::api::datasequence::IDataWriter createConsoleDataOutput(jint, const ::java::lang::String &, const ::java::lang::String &) const;
        ::stallone::api::datasequence::IDataWriter createDataWriter(const ::java::lang::String &, jint, jint) const;
        ::stallone::api::datasequence::IDataList createDatalist() const;
        ::stallone::api::datasequence::IDataReader dataSequenceLoader(const ::java::lang::String &) const;
        ::java::lang::Iterable interleavedDataIterable(const ::stallone::api::datasequence::IDataSequenceLoader &, jint) const;
        ::java::util::Iterator iterator(const ::stallone::api::datasequence::IDataSequence &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(DataSequenceFactory);

      class t_DataSequenceFactory {
      public:
        PyObject_HEAD
        DataSequenceFactory object;
        static PyObject *wrap_Object(const DataSequenceFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
