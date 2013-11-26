#ifndef stallone_api_datasequence_IDataSequence_H
#define stallone_api_datasequence_IDataSequence_H

#include "java/lang/Iterable.h"

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
    namespace doubles {
      class IDoubleArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace datasequence {

      class IDataSequence : public ::java::lang::Iterable {
      public:
        enum {
          mid_dimension_54c6a179,
          mid_get_e3ead0f5,
          mid_getTime_39c7bd2e,
          mid_getView_e3ead0f5,
          mid_iterator_40858c90,
          mid_size_54c6a179,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDataSequence(jobject obj) : ::java::lang::Iterable(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDataSequence(const IDataSequence& obj) : ::java::lang::Iterable(obj) {}

        jint dimension() const;
        ::stallone::api::doubles::IDoubleArray get(jint) const;
        jdouble getTime(jint) const;
        ::stallone::api::doubles::IDoubleArray getView(jint) const;
        ::java::util::Iterator iterator() const;
        jint size() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(IDataSequence);

      class t_IDataSequence {
      public:
        PyObject_HEAD
        IDataSequence object;
        static PyObject *wrap_Object(const IDataSequence&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
