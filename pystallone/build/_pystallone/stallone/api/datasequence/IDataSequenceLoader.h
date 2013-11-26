#ifndef stallone_api_datasequence_IDataSequenceLoader_H
#define stallone_api_datasequence_IDataSequenceLoader_H

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
    namespace datasequence {
      class IDataSequence;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace datasequence {

      class IDataSequenceLoader : public ::java::lang::Object {
      public:
        enum {
          mid_dimension_54c6a179,
          mid_getSingleDataLoader_0ab6fc38,
          mid_getSingleSequenceLoader_0ab6fc38,
          mid_load_3cbb604f,
          mid_loadSequence_062b33a3,
          mid_memorySizeOfLargestSequence_54c6a17a,
          mid_memorySizeOfSingleSequence_39c7bd20,
          mid_memorySizeTotal_54c6a17a,
          mid_numberOfSequences_54c6a179,
          mid_scan_54c6a166,
          mid_size_54c6a179,
          mid_size_39c7bd23,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDataSequenceLoader(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDataSequenceLoader(const IDataSequenceLoader& obj) : ::java::lang::Object(obj) {}

        jint dimension() const;
        ::java::lang::Iterable getSingleDataLoader() const;
        ::java::lang::Iterable getSingleSequenceLoader() const;
        ::stallone::api::doubles::IDoubleArray load(jint, jint) const;
        ::stallone::api::datasequence::IDataSequence loadSequence(jint) const;
        jlong memorySizeOfLargestSequence() const;
        jlong memorySizeOfSingleSequence(jint) const;
        jlong memorySizeTotal() const;
        jint numberOfSequences() const;
        void scan() const;
        jint size() const;
        jint size(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(IDataSequenceLoader);

      class t_IDataSequenceLoader {
      public:
        PyObject_HEAD
        IDataSequenceLoader object;
        static PyObject *wrap_Object(const IDataSequenceLoader&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
