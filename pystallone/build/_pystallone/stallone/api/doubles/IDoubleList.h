#ifndef stallone_api_doubles_IDoubleList_H
#define stallone_api_doubles_IDoubleList_H

#include "stallone/api/doubles/IDoubleArray.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class IDoubleList : public ::stallone::api::doubles::IDoubleArray {
      public:
        enum {
          mid_append_5d1c7645,
          mid_appendAll_0253084a,
          mid_insert_5aa51c57,
          mid_insertAll_9665a230,
          mid_remove_39c7bd3c,
          mid_removeByValue_5d1c7645,
          mid_removeRange_d8d154a6,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDoubleList(jobject obj) : ::stallone::api::doubles::IDoubleArray(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDoubleList(const IDoubleList& obj) : ::stallone::api::doubles::IDoubleArray(obj) {}

        void append(jdouble) const;
        void appendAll(const ::stallone::api::doubles::IDoubleArray &) const;
        void insert(jint, jdouble) const;
        void insertAll(jint, const ::stallone::api::doubles::IDoubleArray &) const;
        void remove(jint) const;
        void removeByValue(jdouble) const;
        void removeRange(jint, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(IDoubleList);

      class t_IDoubleList {
      public:
        PyObject_HEAD
        IDoubleList object;
        static PyObject *wrap_Object(const IDoubleList&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
