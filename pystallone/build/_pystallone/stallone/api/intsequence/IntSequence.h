#ifndef stallone_api_intsequence_IntSequence_H
#define stallone_api_intsequence_IntSequence_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace intsequence {
      class IntSequenceFactory;
      class IntSequenceUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace intsequence {

      class IntSequence : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IntSequence(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IntSequence(const IntSequence& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::intsequence::IntSequenceFactory *create;
        static ::stallone::api::intsequence::IntSequenceUtilities *util;

        IntSequence();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace intsequence {
      extern PyTypeObject PY_TYPE(IntSequence);

      class t_IntSequence {
      public:
        PyObject_HEAD
        IntSequence object;
        static PyObject *wrap_Object(const IntSequence&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
