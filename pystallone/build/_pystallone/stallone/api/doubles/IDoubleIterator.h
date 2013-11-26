#ifndef stallone_api_doubles_IDoubleIterator_H
#define stallone_api_doubles_IDoubleIterator_H

#include "java/util/Iterator.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleElement;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class IDoubleIterator : public ::java::util::Iterator {
      public:
        enum {
          mid_advance_54c6a166,
          mid_column_54c6a179,
          mid_get_54c6a174,
          mid_getIndex_54c6a179,
          mid_hasNext_54c6a16a,
          mid_next_7098f674,
          mid_reset_54c6a166,
          mid_row_54c6a179,
          mid_set_5d1c7645,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDoubleIterator(jobject obj) : ::java::util::Iterator(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDoubleIterator(const IDoubleIterator& obj) : ::java::util::Iterator(obj) {}

        void advance() const;
        jint column() const;
        jdouble get() const;
        jint getIndex() const;
        jboolean hasNext() const;
        ::stallone::api::doubles::IDoubleElement next() const;
        void reset() const;
        jint row() const;
        void set(jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(IDoubleIterator);

      class t_IDoubleIterator {
      public:
        PyObject_HEAD
        IDoubleIterator object;
        static PyObject *wrap_Object(const IDoubleIterator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
