#ifndef stallone_api_strings_StringUtilities_H
#define stallone_api_strings_StringUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Class;
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace strings {

      class StringUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_concat_52efb6d5,
          mid_concat_bdc16ed9,
          mid_concat_702502e1,
          mid_concat_c43bee99,
          mid_contains_2d75732a,
          mid_copy_dc523beb,
          mid_drop_a23934a5,
          mid_dropLeading_52efb6d5,
          mid_findBackward_2d757339,
          mid_findBackward_4d3b16d3,
          mid_findForward_2d757339,
          mid_findForward_4d3b16d3,
          mid_getColumn_d73de0bd,
          mid_getLines_1f6a174f,
          mid_isDouble_5fdc3f44,
          mid_isDoubleArray_5fdc3f44,
          mid_isInt_5fdc3f44,
          mid_isIntArray_5fdc3f44,
          mid_leadingInt_5fdc3f57,
          mid_mergeLines_1034289b,
          mid_nextInt_6e53ccd9,
          mid_nextLong_6e53ccda,
          mid_purgeEmpty_dc523beb,
          mid_replaceAll_af6d27e3,
          mid_split_65e3fad3,
          mid_split_1f6a174f,
          mid_startsWithInt_5fdc3f44,
          mid_subarray_a23934a5,
          mid_subarray_b0bbba5d,
          mid_subarray_4b8ddbd3,
          mid_subarray_7846ea3b,
          mid_toDouble_5fdc3f5a,
          mid_toDoubleArray_33e9f57a,
          mid_toDoubleArray_94a731a2,
          mid_toDoubleArray_0998f056,
          mid_toDoubleTable_eb951592,
          mid_toInt_5fdc3f57,
          mid_toIntArray_0998f05b,
          mid_toIntArray_94a731af,
          mid_toIntMatrix_33e9f577,
          mid_toLong_5fdc3f54,
          mid_transpose_96c66b57,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit StringUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        StringUtilities(const StringUtilities& obj) : ::java::lang::Object(obj) {}

        StringUtilities();

        JArray< ::java::lang::String > concat(const JArray< ::java::lang::String > &, const ::java::lang::String &) const;
        JArray< ::java::lang::String > concat(const JArray< ::java::lang::String > &, const JArray< ::java::lang::String > &) const;
        JArray< JArray< ::java::lang::String > > concat(const JArray< JArray< ::java::lang::String > > &, const JArray< ::java::lang::String > &) const;
        JArray< JArray< ::java::lang::String > > concat(const JArray< JArray< ::java::lang::String > > &, const JArray< JArray< ::java::lang::String > > &) const;
        jboolean contains(const JArray< ::java::lang::String > &, const ::java::lang::String &) const;
        JArray< ::java::lang::String > copy(const JArray< ::java::lang::String > &) const;
        JArray< ::java::lang::String > drop(const JArray< ::java::lang::String > &, const JArray< jint > &) const;
        JArray< ::java::lang::String > dropLeading(const JArray< ::java::lang::String > &, const ::java::lang::String &) const;
        jint findBackward(const JArray< ::java::lang::String > &, const ::java::lang::String &) const;
        jint findBackward(const JArray< ::java::lang::String > &, const ::java::lang::String &, jint) const;
        jint findForward(const JArray< ::java::lang::String > &, const ::java::lang::String &) const;
        jint findForward(const JArray< ::java::lang::String > &, const ::java::lang::String &, jint) const;
        JArray< ::java::lang::String > getColumn(const JArray< JArray< ::java::lang::String > > &, jint) const;
        JArray< ::java::lang::String > getLines(const ::java::lang::String &) const;
        jboolean isDouble(const ::java::lang::String &) const;
        jboolean isDoubleArray(const ::java::lang::String &) const;
        jboolean isInt(const ::java::lang::String &) const;
        jboolean isIntArray(const ::java::lang::String &) const;
        jint leadingInt(const ::java::lang::String &) const;
        ::java::lang::String mergeLines(const JArray< ::java::lang::String > &) const;
        jint nextInt(const ::java::lang::String &, jint) const;
        jlong nextLong(const ::java::lang::String &, jint) const;
        JArray< ::java::lang::String > purgeEmpty(const JArray< ::java::lang::String > &) const;
        ::java::lang::String replaceAll(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &) const;
        JArray< JArray< ::java::lang::String > > split(const JArray< ::java::lang::String > &) const;
        JArray< ::java::lang::String > split(const ::java::lang::String &) const;
        jboolean startsWithInt(const ::java::lang::String &) const;
        JArray< ::java::lang::String > subarray(const JArray< ::java::lang::String > &, const JArray< jint > &) const;
        JArray< JArray< ::java::lang::String > > subarray(const JArray< JArray< ::java::lang::String > > &, const JArray< jint > &) const;
        JArray< ::java::lang::String > subarray(const JArray< ::java::lang::String > &, jint, jint) const;
        JArray< JArray< ::java::lang::String > > subarray(const JArray< JArray< ::java::lang::String > > &, jint, jint) const;
        jdouble toDouble(const ::java::lang::String &) const;
        JArray< JArray< jdouble > > toDoubleArray(const JArray< JArray< ::java::lang::String > > &) const;
        JArray< jdouble > toDoubleArray(const ::java::lang::String &) const;
        JArray< jdouble > toDoubleArray(const JArray< ::java::lang::String > &) const;
        JArray< JArray< jdouble > > toDoubleTable(const ::java::lang::String &) const;
        jint toInt(const ::java::lang::String &) const;
        JArray< jint > toIntArray(const JArray< ::java::lang::String > &) const;
        JArray< jint > toIntArray(const ::java::lang::String &) const;
        JArray< JArray< jint > > toIntMatrix(const JArray< JArray< ::java::lang::String > > &) const;
        jlong toLong(const ::java::lang::String &) const;
        JArray< JArray< ::java::lang::String > > transpose(const JArray< JArray< ::java::lang::String > > &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace strings {
      extern PyTypeObject PY_TYPE(StringUtilities);

      class t_StringUtilities {
      public:
        PyObject_HEAD
        StringUtilities object;
        static PyObject *wrap_Object(const StringUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
