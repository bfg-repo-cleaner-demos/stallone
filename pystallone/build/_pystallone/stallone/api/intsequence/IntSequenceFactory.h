#ifndef stallone_api_intsequence_IntSequenceFactory_H
#define stallone_api_intsequence_IntSequenceFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace intsequence {
      class IIntSequenceLoader;
      class IIntWriter;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace intsequence {

      class IntSequenceFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_intSequenceWriter_244dd0ed,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IntSequenceFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IntSequenceFactory(const IntSequenceFactory& obj) : ::java::lang::Object(obj) {}

        IntSequenceFactory();

        ::stallone::api::intsequence::IIntWriter intSequenceWriter(const ::java::lang::String &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace intsequence {
      extern PyTypeObject PY_TYPE(IntSequenceFactory);

      class t_IntSequenceFactory {
      public:
        PyObject_HEAD
        IntSequenceFactory object;
        static PyObject *wrap_Object(const IntSequenceFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
