#ifndef stallone_api_ints_IIntIterator_H
#define stallone_api_ints_IIntIterator_H

#include "java/util/Iterator.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntElement;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class IIntIterator : public ::java::util::Iterator {
      public:
        enum {
          mid_advance_54c6a166,
          mid_column_54c6a179,
          mid_get_54c6a179,
          mid_getIndex_54c6a179,
          mid_hasNext_54c6a16a,
          mid_next_b8c6f70a,
          mid_reset_54c6a166,
          mid_row_54c6a179,
          mid_set_39c7bd3c,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IIntIterator(jobject obj) : ::java::util::Iterator(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IIntIterator(const IIntIterator& obj) : ::java::util::Iterator(obj) {}

        void advance() const;
        jint column() const;
        jint get() const;
        jint getIndex() const;
        jboolean hasNext() const;
        ::stallone::api::ints::IIntElement next() const;
        void reset() const;
        jint row() const;
        void set(jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IIntIterator);

      class t_IIntIterator {
      public:
        PyObject_HEAD
        IIntIterator object;
        static PyObject *wrap_Object(const IIntIterator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
