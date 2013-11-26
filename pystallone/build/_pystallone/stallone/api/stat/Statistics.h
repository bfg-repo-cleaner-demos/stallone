#ifndef stallone_api_stat_Statistics_H
#define stallone_api_stat_Statistics_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace stat {
      class StatisticsFactory;
      class StatisticsUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace stat {

      class Statistics : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Statistics(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Statistics(const Statistics& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::stat::StatisticsFactory *create;
        static ::stallone::api::stat::StatisticsUtilities *util;

        Statistics();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace stat {
      extern PyTypeObject PY_TYPE(Statistics);

      class t_Statistics {
      public:
        PyObject_HEAD
        Statistics object;
        static PyObject *wrap_Object(const Statistics&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
