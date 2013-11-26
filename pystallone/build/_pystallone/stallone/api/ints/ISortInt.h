#ifndef stallone_api_ints_ISortInt_H
#define stallone_api_ints_ISortInt_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class ISortInt : public ::java::lang::Object {
      public:
        enum {
          mid_getSortedData_4ac77731,
          mid_getSortedIndexes_4ac77731,
          mid_setData_059aa494,
          mid_setData_88ee849e,
          mid_sort_4ac77731,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ISortInt(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ISortInt(const ISortInt& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::ints::IIntArray getSortedData() const;
        ::stallone::api::ints::IIntArray getSortedIndexes() const;
        void setData(const ::stallone::api::ints::IIntArray &) const;
        void setData(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray sort() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(ISortInt);

      class t_ISortInt {
      public:
        PyObject_HEAD
        ISortInt object;
        static PyObject *wrap_Object(const ISortInt&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
