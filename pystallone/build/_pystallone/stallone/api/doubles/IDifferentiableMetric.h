#ifndef stallone_api_doubles_IDifferentiableMetric_H
#define stallone_api_doubles_IDifferentiableMetric_H

#include "stallone/api/doubles/IMetric.h"

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

      class IDifferentiableMetric : public ::stallone::api::doubles::IMetric {
      public:
        enum {
          mid_gradientX_76419023,
          mid_gradientY_76419023,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDifferentiableMetric(jobject obj) : ::stallone::api::doubles::IMetric(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDifferentiableMetric(const IDifferentiableMetric& obj) : ::stallone::api::doubles::IMetric(obj) {}

        ::stallone::api::doubles::IDoubleArray gradientX(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray gradientY(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(IDifferentiableMetric);

      class t_IDifferentiableMetric {
      public:
        PyObject_HEAD
        IDifferentiableMetric object;
        PyTypeObject *parameters[1];
        static PyTypeObject **parameters_(t_IDifferentiableMetric *self)
        {
          return (PyTypeObject **) &(self->parameters);
        }
        static PyObject *wrap_Object(const IDifferentiableMetric&);
        static PyObject *wrap_jobject(const jobject&);
        static PyObject *wrap_Object(const IDifferentiableMetric&, PyTypeObject *);
        static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
