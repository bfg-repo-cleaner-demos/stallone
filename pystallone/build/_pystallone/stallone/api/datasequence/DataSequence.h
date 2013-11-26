#ifndef stallone_api_datasequence_DataSequence_H
#define stallone_api_datasequence_DataSequence_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace datasequence {
      class DataSequenceUtilities;
      class DataSequenceFactory;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace datasequence {

      class DataSequence : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DataSequence(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DataSequence(const DataSequence& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::datasequence::DataSequenceFactory *create;
        static ::stallone::api::datasequence::DataSequenceUtilities *util;

        DataSequence();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(DataSequence);

      class t_DataSequence {
      public:
        PyObject_HEAD
        DataSequence object;
        static PyObject *wrap_Object(const DataSequence&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
