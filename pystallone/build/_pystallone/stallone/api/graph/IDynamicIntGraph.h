#ifndef stallone_api_graph_IDynamicIntGraph_H
#define stallone_api_graph_IDynamicIntGraph_H

#include "stallone/api/graph/IIntGraph.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class IDynamicIntGraph : public ::stallone::api::graph::IIntGraph {
      public:
        enum {
          mid_addEdge_d8d154aa,
          mid_addNode_39c7bd3c,
          mid_hasEdge_d8d154aa,
          mid_removeAllEdges_54c6a166,
          mid_removeEdge_d8d154a6,
          mid_removeEdges_39c7bd3c,
          mid_removeNode_39c7bd3c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDynamicIntGraph(jobject obj) : ::stallone::api::graph::IIntGraph(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDynamicIntGraph(const IDynamicIntGraph& obj) : ::stallone::api::graph::IIntGraph(obj) {}

        jboolean addEdge(jint, jint) const;
        void addNode(jint) const;
        jboolean hasEdge(jint, jint) const;
        void removeAllEdges() const;
        void removeEdge(jint, jint) const;
        void removeEdges(jint) const;
        void removeNode(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(IDynamicIntGraph);

      class t_IDynamicIntGraph {
      public:
        PyObject_HEAD
        IDynamicIntGraph object;
        static PyObject *wrap_Object(const IDynamicIntGraph&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
