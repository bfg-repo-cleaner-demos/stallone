#ifndef stallone_api_doubles_IDoubleElement_H
#define stallone_api_doubles_IDoubleElement_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class IDoubleElement : public ::java::lang::Object {
      public:
        enum {
          mid_column_54c6a179,
          mid_get_54c6a174,
          mid_index_54c6a179,
          mid_row_54c6a179,
          mid_set_5d1c7645,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDoubleElement(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDoubleElement(const IDoubleElement& obj) : ::java::lang::Object(obj) {}

        jint column() const;
        jdouble get() const;
        jint index() const;
        jint row() const;
        void set(jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(IDoubleElement);

      class t_IDoubleElement {
      public:
        PyObject_HEAD
        IDoubleElement object;
        static PyObject *wrap_Object(const IDoubleElement&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
