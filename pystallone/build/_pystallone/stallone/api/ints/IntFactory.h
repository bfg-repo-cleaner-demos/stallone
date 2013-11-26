#ifndef stallone_api_ints_IntFactory_H
#define stallone_api_ints_IntFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace ints {
      class IIntArray;
      class IIntList;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace ints {

      class IntFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_array_fcbe62e3,
          mid_array_62213cdb,
          mid_array_004e62f1,
          mid_arrayFrom_e2b10697,
          mid_arrayFrom_62213cdb,
          mid_arrayFrom_df29d4b8,
          mid_arrayFrom_ed7b64a6,
          mid_arrayFrom_9b80c139,
          mid_arrayRandomIndexes_004e62f1,
          mid_arrayRange_62213cdb,
          mid_arrayRange_004e62f1,
          mid_arrayRange_03ba5ae3,
          mid_like_3c84c841,
          mid_list_d218958f,
          mid_list_65bad777,
          mid_list_44a3774d,
          mid_listFrom_1615017e,
          mid_listFrom_3d9702f3,
          mid_listFrom_b772d97c,
          mid_listFrom_65bad777,
          mid_listFrom_8b467429,
          mid_listRandomIndexes_44a3774d,
          mid_listRange_65bad777,
          mid_listRange_44a3774d,
          mid_listRange_2f53b807,
          mid_table_004e62f1,
          mid_table_03ba5ae3,
          mid_tableFrom_d12b2044,
          mid_tableFrom_1cb5f11a,
          mid_tableReshape_236de56b,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IntFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IntFactory(const IntFactory& obj) : ::java::lang::Object(obj) {}

        IntFactory();

        ::stallone::api::ints::IIntArray array(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray array(jint) const;
        ::stallone::api::ints::IIntArray array(jint, jint) const;
        ::stallone::api::ints::IIntArray arrayFrom(const JArray< jint > &) const;
        ::stallone::api::ints::IIntArray arrayFrom(jint) const;
        ::stallone::api::ints::IIntArray arrayFrom(const JArray< jfloat > &) const;
        ::stallone::api::ints::IIntArray arrayFrom(const JArray< jdouble > &) const;
        ::stallone::api::ints::IIntArray arrayFrom(jint, const JArray< jint > &) const;
        ::stallone::api::ints::IIntArray arrayRandomIndexes(jint, jint) const;
        ::stallone::api::ints::IIntArray arrayRange(jint) const;
        ::stallone::api::ints::IIntArray arrayRange(jint, jint) const;
        ::stallone::api::ints::IIntArray arrayRange(jint, jint, jint) const;
        ::stallone::api::ints::IIntArray like(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntList list(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntList list(jint) const;
        ::stallone::api::ints::IIntList list(jint, jint) const;
        ::stallone::api::ints::IIntList listFrom(const JArray< jfloat > &) const;
        ::stallone::api::ints::IIntList listFrom(const JArray< jint > &) const;
        ::stallone::api::ints::IIntList listFrom(const JArray< jdouble > &) const;
        ::stallone::api::ints::IIntList listFrom(jint) const;
        ::stallone::api::ints::IIntList listFrom(jint, const JArray< jint > &) const;
        ::stallone::api::ints::IIntList listRandomIndexes(jint, jint) const;
        ::stallone::api::ints::IIntList listRange(jint) const;
        ::stallone::api::ints::IIntList listRange(jint, jint) const;
        ::stallone::api::ints::IIntList listRange(jint, jint, jint) const;
        ::stallone::api::ints::IIntArray table(jint, jint) const;
        ::stallone::api::ints::IIntArray table(jint, jint, jint) const;
        ::stallone::api::ints::IIntArray tableFrom(const JArray< JArray< jfloat > > &) const;
        ::stallone::api::ints::IIntArray tableFrom(const JArray< JArray< jdouble > > &) const;
        ::stallone::api::ints::IIntArray tableReshape(const ::stallone::api::ints::IIntArray &, jint, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IntFactory);

      class t_IntFactory {
      public:
        PyObject_HEAD
        IntFactory object;
        static PyObject *wrap_Object(const IntFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
