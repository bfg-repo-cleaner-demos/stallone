#ifndef stallone_api_algebra_IComplexNumber_H
#define stallone_api_algebra_IComplexNumber_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace algebra {

      class IComplexNumber : public ::java::lang::Object {
      public:
        enum {
          mid_abs_54c6a174,
          mid_add_4501e87b,
          mid_addIm_1bd67997,
          mid_addRe_1bd67997,
          mid_conj_8803cf94,
          mid_conj_4501e87b,
          mid_conjInplace_8803cf94,
          mid_copy_8803cf94,
          mid_copy_4501e87b,
          mid_get_54c6a174,
          mid_getIm_54c6a174,
          mid_getRe_54c6a174,
          mid_invert_8803cf94,
          mid_invert_4501e87b,
          mid_invertInplace_8803cf94,
          mid_isPurelyImaginary_54c6a16a,
          mid_isPurelyReal_54c6a16a,
          mid_isZero_54c6a16a,
          mid_multBy_4501e87b,
          mid_negate_8803cf94,
          mid_negate_4501e87b,
          mid_negateInplace_8803cf94,
          mid_set_5d1c7645,
          mid_setComplex_b1e28678,
          mid_setIm_5d1c7645,
          mid_setRe_5d1c7645,
          mid_setScalar_0cb5c9b1,
          mid_storesComplex_54c6a16a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IComplexNumber(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IComplexNumber(const IComplexNumber& obj) : ::java::lang::Object(obj) {}

        jdouble abs() const;
        IComplexNumber add(const IComplexNumber &) const;
        IComplexNumber addIm(jdouble) const;
        IComplexNumber addRe(jdouble) const;
        IComplexNumber conj() const;
        IComplexNumber conj(const IComplexNumber &) const;
        IComplexNumber conjInplace() const;
        IComplexNumber copy() const;
        IComplexNumber copy(const IComplexNumber &) const;
        jdouble get() const;
        jdouble getIm() const;
        jdouble getRe() const;
        IComplexNumber invert() const;
        IComplexNumber invert(const IComplexNumber &) const;
        IComplexNumber invertInplace() const;
        jboolean isPurelyImaginary() const;
        jboolean isPurelyReal() const;
        jboolean isZero() const;
        IComplexNumber multBy(const IComplexNumber &) const;
        IComplexNumber negate() const;
        IComplexNumber negate(const IComplexNumber &) const;
        IComplexNumber negateInplace() const;
        void set(jdouble) const;
        void setComplex(jdouble, jdouble) const;
        void setIm(jdouble) const;
        void setRe(jdouble) const;
        void setScalar(const IComplexNumber &) const;
        jboolean storesComplex() const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace algebra {
      extern PyTypeObject PY_TYPE(IComplexNumber);

      class t_IComplexNumber {
      public:
        PyObject_HEAD
        IComplexNumber object;
        static PyObject *wrap_Object(const IComplexNumber&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
