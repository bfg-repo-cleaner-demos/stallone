#ifndef stallone_api_doubles_IMetric_H
#define stallone_api_doubles_IMetric_H

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
    namespace doubles {

      class IMetric : public ::java::lang::Object {
      public:
        enum {
          mid_distance_608d4898,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IMetric(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IMetric(const IMetric& obj) : ::java::lang::Object(obj) {}

        jdouble distance(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(IMetric);

      class t_IMetric {
      public:
        PyObject_HEAD
        IMetric object;
        PyTypeObject *parameters[1];
        static PyTypeObject **parameters_(t_IMetric *self)
        {
          return (PyTypeObject **) &(self->parameters);
        }
        static PyObject *wrap_Object(const IMetric&);
        static PyObject *wrap_jobject(const jobject&);
        static PyObject *wrap_Object(const IMetric&, PyTypeObject *);
        static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
