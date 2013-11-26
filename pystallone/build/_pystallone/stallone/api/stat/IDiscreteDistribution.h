#ifndef stallone_api_stat_IDiscreteDistribution_H
#define stallone_api_stat_IDiscreteDistribution_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace stat {

      class IDiscreteDistribution : public ::java::lang::Object {
      public:
        enum {
          mid_sample_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDiscreteDistribution(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDiscreteDistribution(const IDiscreteDistribution& obj) : ::java::lang::Object(obj) {}

        jint sample() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace stat {
      extern PyTypeObject PY_TYPE(IDiscreteDistribution);

      class t_IDiscreteDistribution {
      public:
        PyObject_HEAD
        IDiscreteDistribution object;
        static PyObject *wrap_Object(const IDiscreteDistribution&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
