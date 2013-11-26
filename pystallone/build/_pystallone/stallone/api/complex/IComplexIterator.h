#ifndef stallone_api_complex_IComplexIterator_H
#define stallone_api_complex_IComplexIterator_H

#include "java/util/Iterator.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace complex {
      class IComplexElement;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class IComplexIterator : public ::java::util::Iterator {
      public:
        enum {
          mid_advance_54c6a166,
          mid_column_54c6a179,
          mid_get_54c6a174,
          mid_getIm_54c6a174,
          mid_getIndex_54c6a179,
          mid_getRe_54c6a174,
          mid_hasNext_54c6a16a,
          mid_next_4d8c4a74,
          mid_reset_54c6a166,
          mid_row_54c6a179,
          mid_set_5d1c7645,
          mid_set_b1e28678,
          mid_setIm_5d1c7645,
          mid_setRe_5d1c7645,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IComplexIterator(jobject obj) : ::java::util::Iterator(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IComplexIterator(const IComplexIterator& obj) : ::java::util::Iterator(obj) {}

        void advance() const;
        jint column() const;
        jdouble get() const;
        jdouble getIm() const;
        jint getIndex() const;
        jdouble getRe() const;
        jboolean hasNext() const;
        ::stallone::api::complex::IComplexElement next() const;
        void reset() const;
        jint row() const;
        void set(jdouble) const;
        void set(jdouble, jdouble) const;
        void setIm(jdouble) const;
        void setRe(jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace complex {
      extern PyTypeObject PY_TYPE(IComplexIterator);

      class t_IComplexIterator {
      public:
        PyObject_HEAD
        IComplexIterator object;
        static PyObject *wrap_Object(const IComplexIterator&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
