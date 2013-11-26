#ifndef stallone_api_hmm_HMMFactory_H
#define stallone_api_hmm_HMMFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class IParametricFunction;
    }
    namespace hmm {
      class IHMMOptimizer;
      class IExpectationMaximization;
      class IHMMParameters;
    }
    namespace doubles {
      class IDoubleArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace hmm {

      class HMMFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_parameters_f9c1f285,
          mid_parameters_52a2b433,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit HMMFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        HMMFactory(const HMMFactory& obj) : ::java::lang::Object(obj) {}

        HMMFactory();

        ::stallone::api::hmm::IHMMParameters parameters(jint, jboolean, jboolean) const;
        ::stallone::api::hmm::IHMMParameters parameters(jint, jboolean, jboolean, const ::stallone::api::function::IParametricFunction &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace hmm {
      extern PyTypeObject PY_TYPE(HMMFactory);

      class t_HMMFactory {
      public:
        PyObject_HEAD
        HMMFactory object;
        static PyObject *wrap_Object(const HMMFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
