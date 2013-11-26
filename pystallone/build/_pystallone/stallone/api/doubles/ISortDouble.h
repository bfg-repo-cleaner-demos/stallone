#ifndef stallone_api_doubles_ISortDouble_H
#define stallone_api_doubles_ISortDouble_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class ISortDouble : public ::java::lang::Object {
      public:
        enum {
          mid_getSortedData_1d53e353,
          mid_getSortedIndexes_4ac77731,
          mid_setData_0253084a,
          mid_setData_608d488a,
          mid_sort_1d53e353,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ISortDouble(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ISortDouble(const ISortDouble& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray getSortedData() const;
        ::stallone::api::ints::IIntArray getSortedIndexes() const;
        void setData(const ::stallone::api::doubles::IDoubleArray &) const;
        void setData(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray sort() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(ISortDouble);

      class t_ISortDouble {
      public:
        PyObject_HEAD
        ISortDouble object;
        static PyObject *wrap_Object(const ISortDouble&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
