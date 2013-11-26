#ifndef stallone_api_mc_IMarkovPropagator_H
#define stallone_api_mc_IMarkovPropagator_H

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
    namespace mc {

      class IMarkovPropagator : public ::java::lang::Object {
      public:
        enum {
          mid_propagate_e50533dc,
          mid_set_0253084a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IMarkovPropagator(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IMarkovPropagator(const IMarkovPropagator& obj) : ::java::lang::Object(obj) {}

        ::stallone::api::doubles::IDoubleArray propagate(jdouble) const;
        void set(const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(IMarkovPropagator);

      class t_IMarkovPropagator {
      public:
        PyObject_HEAD
        IMarkovPropagator object;
        static PyObject *wrap_Object(const IMarkovPropagator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
