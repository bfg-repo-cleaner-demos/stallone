#ifndef stallone_api_datasequence_DataSequenceUtilities_H
#define stallone_api_datasequence_DataSequenceUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
    class Iterable;
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
    namespace datasequence {
      class IDataSequence;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace datasequence {

      class DataSequenceUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_mean_c668b3b0,
          mid_readColumn_2e3d0a4b,
          mid_readColumn_3b6bdd13,
          mid_readDataList_38f3407b,
          mid_readDataSequence_38f3407b,
          mid_readDataTable_ae6f32f9,
          mid_readDataTable_2f8669d9,
          mid_rgyr_d1cac217,
          mid_rmax_d1cac217,
          mid_writeData_f5ccc47a,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DataSequenceUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DataSequenceUtilities(const DataSequenceUtilities& obj) : ::java::lang::Object(obj) {}

        DataSequenceUtilities();

        ::stallone::api::doubles::IDoubleArray mean(const ::java::lang::Iterable &) const;
        ::stallone::api::doubles::IDoubleArray readColumn(const ::stallone::api::datasequence::IDataSequence &, jint) const;
        ::stallone::api::doubles::IDoubleArray readColumn(const ::java::lang::String &, jint) const;
        ::stallone::api::datasequence::IDataSequence readDataList(const ::java::lang::String &) const;
        ::stallone::api::datasequence::IDataSequence readDataSequence(const ::java::lang::String &) const;
        ::stallone::api::doubles::IDoubleArray readDataTable(const ::java::lang::String &) const;
        ::stallone::api::doubles::IDoubleArray readDataTable(const ::stallone::api::datasequence::IDataSequence &) const;
        jdouble rgyr(const ::java::lang::Iterable &) const;
        jdouble rmax(const ::java::lang::Iterable &) const;
        void writeData(const ::stallone::api::datasequence::IDataSequence &, const ::java::lang::String &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(DataSequenceUtilities);

      class t_DataSequenceUtilities {
      public:
        PyObject_HEAD
        DataSequenceUtilities object;
        static PyObject *wrap_Object(const DataSequenceUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
