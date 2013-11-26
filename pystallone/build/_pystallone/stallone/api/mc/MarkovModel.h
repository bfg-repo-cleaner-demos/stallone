#ifndef stallone_api_mc_MarkovModel_H
#define stallone_api_mc_MarkovModel_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace mc {
      class MarkovModelFactory;
      class MarkovModelUtilities;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace mc {

      class MarkovModel : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit MarkovModel(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        MarkovModel(const MarkovModel& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::mc::MarkovModelFactory *create;
        static ::stallone::api::mc::MarkovModelUtilities *util;

        MarkovModel();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(MarkovModel);

      class t_MarkovModel {
      public:
        PyObject_HEAD
        MarkovModel object;
        static PyObject *wrap_Object(const MarkovModel&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
