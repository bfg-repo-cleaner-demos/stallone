#ifndef stallone_api_complex_ComplexFactory_H
#define stallone_api_complex_ComplexFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace complex {
      class IComplexArray;
    }
    namespace algebra {
      class IComplexNumber;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace complex {

      class ComplexFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_array_618dde96,
          mid_array_f6210079,
          mid_array_fba5fcc9,
          mid_array_74a6154f,
          mid_column_f6210079,
          mid_column_777b15cf,
          mid_complexScalar_8803cf94,
          mid_complexScalar_0acceaa2,
          mid_diag_338c567a,
          mid_diag_2e81309f,
          mid_diag_df6a3e1c,
          mid_identity_f6210079,
          mid_row_f6210079,
          mid_row_777b15cf,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit ComplexFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        ComplexFactory(const ComplexFactory& obj) : ::java::lang::Object(obj) {}

        ComplexFactory();

        ::stallone::api::complex::IComplexArray array(const JArray< JArray< ::stallone::api::algebra::IComplexNumber > > &) const;
        ::stallone::api::complex::IComplexArray array(jint) const;
        ::stallone::api::complex::IComplexArray array(const JArray< JArray< jdouble > > &, const JArray< JArray< jdouble > > &) const;
        ::stallone::api::complex::IComplexArray array(jint, jint) const;
        ::stallone::api::complex::IComplexArray column(jint) const;
        ::stallone::api::complex::IComplexArray column(const JArray< jdouble > &, const JArray< jdouble > &) const;
        ::stallone::api::algebra::IComplexNumber complexScalar() const;
        ::stallone::api::algebra::IComplexNumber complexScalar(jdouble, jdouble) const;
        ::stallone::api::complex::IComplexArray diag(const JArray< jdouble > &) const;
        ::stallone::api::complex::IComplexArray diag(const ::stallone::api::complex::IComplexArray &) const;
        ::stallone::api::complex::IComplexArray diag(jint, jdouble) const;
        ::stallone::api::complex::IComplexArray identity(jint) const;
        ::stallone::api::complex::IComplexArray row(jint) const;
        ::stallone::api::complex::IComplexArray row(const JArray< jdouble > &, const JArray< jdouble > &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace complex {
      extern PyTypeObject PY_TYPE(ComplexFactory);

      class t_ComplexFactory {
      public:
        PyObject_HEAD
        ComplexFactory object;
        static PyObject *wrap_Object(const ComplexFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
