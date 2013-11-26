#ifndef stallone_api_graph_IIntGraph_H
#define stallone_api_graph_IIntGraph_H

#include "java/lang/Object.h"

namespace java {
  namespace util {
    class Iterator;
  }
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace graph {
      class IIntEdge;
    }
    namespace ints {
      class IIntArray;
      class IIntIterator;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace graph {

      class IIntGraph : public ::java::lang::Object {
      public:
        enum {
          mid_contains_39c7bd30,
          mid_contains_d8d154aa,
          mid_edgeIterator_40858c90,
          mid_getNodes_4ac77731,
          mid_neighborIterator_136bab09,
          mid_nodeIterator_6c27215b,
          mid_numberOfArcs_54c6a179,
          mid_numberOfNodes_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntGraph(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntGraph(const IIntGraph& obj) : ::java::lang::Object(obj) {}

        jboolean contains(jint) const;
        jboolean contains(jint, jint) const;
        ::java::util::Iterator edgeIterator() const;
        ::stallone::api::ints::IIntArray getNodes() const;
        ::stallone::api::ints::IIntIterator neighborIterator(jint) const;
        ::stallone::api::ints::IIntIterator nodeIterator() const;
        jint numberOfArcs() const;
        jint numberOfNodes() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace graph {
      extern PyTypeObject PY_TYPE(IIntGraph);

      class t_IIntGraph {
      public:
        PyObject_HEAD
        IIntGraph object;
        static PyObject *wrap_Object(const IIntGraph&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
