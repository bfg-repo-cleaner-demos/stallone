#ifndef stallone_api_ints_IIntElement_H
#define stallone_api_ints_IIntElement_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class IIntElement : public ::java::lang::Object {
      public:
        enum {
          mid_column_54c6a179,
          mid_get_54c6a179,
          mid_index_54c6a179,
          mid_row_54c6a179,
          mid_set_39c7bd3c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntElement(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntElement(const IIntElement& obj) : ::java::lang::Object(obj) {}

        jint column() const;
        jint get() const;
        jint index() const;
        jint row() const;
        void set(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IIntElement);

      class t_IIntElement {
      public:
        PyObject_HEAD
        IIntElement object;
        static PyObject *wrap_Object(const IIntElement&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
