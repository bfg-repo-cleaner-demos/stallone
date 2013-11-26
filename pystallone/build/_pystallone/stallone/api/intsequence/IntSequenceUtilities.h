#ifndef stallone_api_intsequence_IntSequenceUtilities_H
#define stallone_api_intsequence_IntSequenceUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Iterable;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntArray;
      class IIntList;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace intsequence {

      class IntSequenceUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_lifetimesByState_e8cc7f5f,
          mid_loadIntSequence_24ec4a57,
          mid_max_d1cac21a,
          mid_writeIntSequence_e256d906,
          mid_writeIntSequenceSparse_e256d906,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IntSequenceUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IntSequenceUtilities(const IntSequenceUtilities& obj) : ::java::lang::Object(obj) {}

        IntSequenceUtilities();

        JArray< ::stallone::api::ints::IIntList > lifetimesByState(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray loadIntSequence(const ::java::lang::String &) const;
        jint max$(const ::java::lang::Iterable &) const;
        void writeIntSequence(const ::stallone::api::ints::IIntArray &, const ::java::lang::String &) const;
        void writeIntSequenceSparse(const ::stallone::api::ints::IIntArray &, const ::java::lang::String &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace intsequence {
      extern PyTypeObject PY_TYPE(IntSequenceUtilities);

      class t_IntSequenceUtilities {
      public:
        PyObject_HEAD
        IntSequenceUtilities object;
        static PyObject *wrap_Object(const IntSequenceUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
