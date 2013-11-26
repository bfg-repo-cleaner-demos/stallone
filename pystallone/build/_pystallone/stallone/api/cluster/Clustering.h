#ifndef stallone_api_cluster_Clustering_H
#define stallone_api_cluster_Clustering_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace cluster {
      class ClusterUtilities;
      class ClusterFactory;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace cluster {

      class Clustering : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit Clustering(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        Clustering(const Clustering& obj) : ::java::lang::Object(obj) {}

        static ::stallone::api::cluster::ClusterFactory *create;
        static ::stallone::api::cluster::ClusterUtilities *util;

        Clustering();
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace cluster {
      extern PyTypeObject PY_TYPE(Clustering);

      class t_Clustering {
      public:
        PyObject_HEAD
        Clustering object;
        static PyObject *wrap_Object(const Clustering&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
