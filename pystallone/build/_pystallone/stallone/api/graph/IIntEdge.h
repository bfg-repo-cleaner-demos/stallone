#ifndef stallone_api_graph_IIntEdge_H
#define stallone_api_graph_IIntEdge_H

#include "stallone/api/graph/IEdge.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class IIntEdge : public ::stallone::api::graph::IEdge {
      public:
        enum {
          mid_getV1_54c6a179,
          mid_getV2_54c6a179,
          mid_setV1_39c7bd3c,
          mid_setV2_39c7bd3c,
          mid_setWeight_5d1c7645,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntEdge(jobject obj) : ::stallone::api::graph::IEdge(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntEdge(const IIntEdge& obj) : ::stallone::api::graph::IEdge(obj) {}

        jint getV1() const;
        jint getV2() const;
        void setV1(jint) const;
        void setV2(jint) const;
        void setWeight(jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(IIntEdge);

      class t_IIntEdge {
      public:
        PyObject_HEAD
        IIntEdge object;
        static PyObject *wrap_Object(const IIntEdge&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
