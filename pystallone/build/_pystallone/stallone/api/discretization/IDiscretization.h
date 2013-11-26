#ifndef stallone_api_discretization_IDiscretization_H
#define stallone_api_discretization_IDiscretization_H

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
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace discretization {

      class IDiscretization : public ::java::lang::Object {
      public:
        enum {
          mid_assign_02530855,
          mid_assignFuzzy_32638cb7,
          mid_getRepresentative_32638cb7,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDiscretization(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDiscretization(const IDiscretization& obj) : ::java::lang::Object(obj) {}

        jint assign(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray assignFuzzy(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray getRepresentative(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace discretization {
      extern PyTypeObject PY_TYPE(IDiscretization);

      class t_IDiscretization {
      public:
        PyObject_HEAD
        IDiscretization object;
        static PyObject *wrap_Object(const IDiscretization&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
