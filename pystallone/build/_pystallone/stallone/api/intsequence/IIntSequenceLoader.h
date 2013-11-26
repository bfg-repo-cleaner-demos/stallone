#ifndef stallone_api_intsequence_IIntSequenceLoader_H
#define stallone_api_intsequence_IIntSequenceLoader_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Integer;
    class String;
    class Iterable;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntArray;
    }
    namespace intsequence {
      class IIntReader;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace intsequence {

      class IIntSequenceLoader : public ::java::lang::Object {
      public:
        enum {
          mid_addSource_5fdc3f48,
          mid_getSingleIntLoader_0ab6fc38,
          mid_getSingleSequenceLoader_0ab6fc38,
          mid_load_d8d154b9,
          mid_loadSequence_62213cdb,
          mid_memorySizeOfLargestSequence_54c6a17a,
          mid_memorySizeOfSingleSequence_39c7bd20,
          mid_memorySizeTotal_54c6a17a,
          mid_numberOfSequences_54c6a179,
          mid_scan_54c6a166,
          mid_setLoader_441086c2,
          mid_size_54c6a179,
          mid_size_39c7bd23,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntSequenceLoader(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntSequenceLoader(const IIntSequenceLoader& obj) : ::java::lang::Object(obj) {}

        void addSource(const ::java::lang::String &) const;
        ::java::lang::Iterable getSingleIntLoader() const;
        ::java::lang::Iterable getSingleSequenceLoader() const;
        jint load(jint, jint) const;
        ::stallone::api::ints::IIntArray loadSequence(jint) const;
        jlong memorySizeOfLargestSequence() const;
        jlong memorySizeOfSingleSequence(jint) const;
        jlong memorySizeTotal() const;
        jint numberOfSequences() const;
        void scan() const;
        void setLoader(const ::stallone::api::intsequence::IIntReader &) const;
        jint size() const;
        jint size(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace intsequence {
      extern PyTypeObject PY_TYPE(IIntSequenceLoader);

      class t_IIntSequenceLoader {
      public:
        PyObject_HEAD
        IIntSequenceLoader object;
        static PyObject *wrap_Object(const IIntSequenceLoader&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
