#ifndef stallone_api_complex_IComplexElement_H
#define stallone_api_complex_IComplexElement_H

#include "stallone/api/doubles/IDoubleElement.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class IComplexElement : public ::stallone::api::doubles::IDoubleElement {
      public:
        enum {
          mid_im_54c6a174,
          mid_re_54c6a174,
          mid_setIm_5d1c7645,
          mid_setRe_5d1c7645,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IComplexElement(jobject obj) : ::stallone::api::doubles::IDoubleElement(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IComplexElement(const IComplexElement& obj) : ::stallone::api::doubles::IDoubleElement(obj) {}

        jdouble im() const;
        jdouble re() const;
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
      extern PyTypeObject PY_TYPE(IComplexElement);

      class t_IComplexElement {
      public:
        PyObject_HEAD
        IComplexElement object;
        static PyObject *wrap_Object(const IComplexElement&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
