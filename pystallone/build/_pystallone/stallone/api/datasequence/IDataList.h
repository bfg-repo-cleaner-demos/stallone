#ifndef stallone_api_datasequence_IDataList_H
#define stallone_api_datasequence_IDataList_H

#include "stallone/api/datasequence/IDataSequence.h"

namespace java {
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

      class IDataList : public ::stallone::api::datasequence::IDataSequence {
      public:
        enum {
          mid_add_02530846,
          mid_remove_02530846,
          mid_remove_e3ead0f5,
          mid_set_9665a230,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IDataList(jobject obj) : ::stallone::api::datasequence::IDataSequence(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IDataList(const IDataList& obj) : ::stallone::api::datasequence::IDataSequence(obj) {}

        jboolean add(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean remove(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray remove(jint) const;
        void set(jint, const ::stallone::api::doubles::IDoubleArray &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace datasequence {
      extern PyTypeObject PY_TYPE(IDataList);

      class t_IDataList {
      public:
        PyObject_HEAD
        IDataList object;
        static PyObject *wrap_Object(const IDataList&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
