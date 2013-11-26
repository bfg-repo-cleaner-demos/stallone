#ifndef stallone_api_ints_IIntList_H
#define stallone_api_ints_IIntList_H

#include "stallone/api/ints/IIntArray.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class IIntList : public ::stallone::api::ints::IIntArray {
      public:
        enum {
          mid_append_39c7bd3c,
          mid_appendAll_059aa494,
          mid_clear_54c6a166,
          mid_insert_d8d154a6,
          mid_insertAll_537625be,
          mid_remove_39c7bd3c,
          mid_removeByValue_39c7bd3c,
          mid_removeRange_d8d154a6,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntList(jobject obj) : ::stallone::api::ints::IIntArray(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntList(const IIntList& obj) : ::stallone::api::ints::IIntArray(obj) {}

        void append(jint) const;
        void appendAll(const ::stallone::api::ints::IIntArray &) const;
        void clear() const;
        void insert(jint, jint) const;
        void insertAll(jint, const ::stallone::api::ints::IIntArray &) const;
        void remove(jint) const;
        void removeByValue(jint) const;
        void removeRange(jint, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IIntList);

      class t_IIntList {
      public:
        PyObject_HEAD
        IIntList object;
        static PyObject *wrap_Object(const IIntList&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
