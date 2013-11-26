#ifndef stallone_api_ints_IIndexMap_H
#define stallone_api_ints_IIndexMap_H

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

      class IIndexMap : public ::java::lang::Object {
      public:
        enum {
          mid_map_39c7bd23,
          mid_size_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIndexMap(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIndexMap(const IIndexMap& obj) : ::java::lang::Object(obj) {}

        jint map(jint) const;
        jint size() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IIndexMap);

      class t_IIndexMap {
      public:
        PyObject_HEAD
        IIndexMap object;
        static PyObject *wrap_Object(const IIndexMap&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
