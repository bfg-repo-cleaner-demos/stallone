#ifndef stallone_api_dynamics_DynamicsUtilities_H
#define stallone_api_dynamics_DynamicsUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace dynamics {
    class IIntegrator;
  }
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
    namespace datasequence {
      class IDataWriter;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace dynamics {

      class DynamicsUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_run_f7a18c66,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DynamicsUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DynamicsUtilities(const DynamicsUtilities& obj) : ::java::lang::Object(obj) {}

        DynamicsUtilities();

        void run(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::dynamics::IIntegrator &, const ::stallone::api::datasequence::IDataWriter &, jint, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace dynamics {
      extern PyTypeObject PY_TYPE(DynamicsUtilities);

      class t_DynamicsUtilities {
      public:
        PyObject_HEAD
        DynamicsUtilities object;
        static PyObject *wrap_Object(const DynamicsUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
