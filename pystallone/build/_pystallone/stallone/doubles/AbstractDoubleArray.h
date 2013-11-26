#ifndef stallone_doubles_AbstractDoubleArray_H
#define stallone_doubles_AbstractDoubleArray_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
      class IDoubleIterator;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace doubles {

    class AbstractDoubleArray : public ::java::lang::Object {
    public:
      enum {
        mid_init$_54c6a166,
        mid_copyFrom_0253084a,
        mid_copyInto_0253084a,
        mid_equals_290588e2,
        mid_get_39c7bd2e,
        mid_getArray_dab10e78,
        mid_getColumn_b4292e9e,
        mid_getRow_b4292e9e,
        mid_getTable_b9d949a8,
        mid_hashCode_54c6a179,
        mid_iterator_c2219c49,
        mid_nonzeroIterator_c2219c49,
        mid_order_54c6a179,
        mid_set_5aa51c57,
        mid_size_54c6a179,
        mid_toString_14c7b5c5,
        mid_view_1259a6af,
        mid_viewBlock_6662d773,
        mid_viewColumn_e3ead0f5,
        mid_viewRow_e3ead0f5,
        mid_zero_54c6a166,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit AbstractDoubleArray(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      AbstractDoubleArray(const AbstractDoubleArray& obj) : ::java::lang::Object(obj) {}

      AbstractDoubleArray();

      void copyFrom(const ::stallone::api::doubles::IDoubleArray &) const;
      void copyInto(const ::stallone::api::doubles::IDoubleArray &) const;
      jboolean equals(const ::java::lang::Object &) const;
      jdouble get(jint) const;
      JArray< jdouble > getArray() const;
      JArray< jdouble > getColumn(jint) const;
      JArray< jdouble > getRow(jint) const;
      JArray< JArray< jdouble > > getTable() const;
      jint hashCode() const;
      ::stallone::api::doubles::IDoubleIterator iterator() const;
      ::stallone::api::doubles::IDoubleIterator nonzeroIterator() const;
      jint order() const;
      void set(jint, jdouble) const;
      jint size() const;
      ::java::lang::String toString() const;
      ::stallone::api::doubles::IDoubleArray view(const JArray< jint > &, const JArray< jint > &) const;
      ::stallone::api::doubles::IDoubleArray viewBlock(jint, jint, jint, jint) const;
      ::stallone::api::doubles::IDoubleArray viewColumn(jint) const;
      ::stallone::api::doubles::IDoubleArray viewRow(jint) const;
      void zero() const;
    };
  }
}

#include <Python.h>

namespace stallone {
  namespace doubles {
    extern PyTypeObject PY_TYPE(AbstractDoubleArray);

    class t_AbstractDoubleArray {
    public:
      PyObject_HEAD
      AbstractDoubleArray object;
      static PyObject *wrap_Object(const AbstractDoubleArray&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
