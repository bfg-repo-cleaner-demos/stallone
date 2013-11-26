#ifndef stallone_api_doubles_DoubleUtilities_H
#define stallone_api_doubles_DoubleUtilities_H

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
      class IDoubleList;
    }
    namespace ints {
      class IIntArray;
      class IIntList;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace doubles {

      class DoubleUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_cleanToNew_32638cb7,
          mid_contains_f5db6acd,
          mid_containsAll_608d4886,
          mid_containsAny_608d4886,
          mid_copyInto_023a5a4a,
          mid_copyInto_1536de50,
          mid_copyInto_cf02ba42,
          mid_count_f5db6ade,
          mid_countRows_608d4895,
          mid_equal_608d4886,
          mid_equal_cf067855,
          mid_exchange_30de0b4e,
          mid_fill_f5db6ac1,
          mid_findAll_f66faea9,
          mid_findAll_1a5a8a08,
          mid_findAllRows_a01ac655,
          mid_findBackwards_f5db6ade,
          mid_findBackwards_608d4895,
          mid_findBackwards_50da3f57,
          mid_findBackwards_0ceafc4a,
          mid_findClosest_f5db6ade,
          mid_findForward_f5db6ade,
          mid_findForward_0ceafc4a,
          mid_findRowForward_608d4895,
          mid_findRowForward_50da3f57,
          mid_findSorted_f5db6ade,
          mid_insertRowToNew_5abbcb2d,
          mid_insertSorted_3fc00bf5,
          mid_insertSortedFixed_f5db6ade,
          mid_insertToNew_11e74ae6,
          mid_intersectionToNew_76419023,
          mid_isSorted_02530846,
          mid_largeValueIndexes_286a392e,
          mid_largeValues_dfd01cbc,
          mid_largest_e79ba665,
          mid_largestIndexes_980dd7f7,
          mid_locateSorted_f5db6ade,
          mid_max_02530858,
          mid_maxInColumn_20d144ba,
          mid_maxInLine_20d144ba,
          mid_maxIndex_02530855,
          mid_merge_76419023,
          mid_mergeColumns_76419023,
          mid_mergeToNew_76419023,
          mid_mergeToNew_dfd01cbc,
          mid_min_02530858,
          mid_minIndex_02530855,
          mid_mirror_0253084a,
          mid_print_0253084a,
          mid_print_e14c9e64,
          mid_print_38fff926,
          mid_print_2501036c,
          mid_print_8338042a,
          mid_removeIndex_8197bfb5,
          mid_removeIndexToNew_8197bfb5,
          mid_removeIndexToNew_e79ba665,
          mid_removeRow_e79ba665,
          mid_removeValueToNew_e79ba665,
          mid_removeValueToNew_76419023,
          mid_smallValueIndexes_286a392e,
          mid_smallValues_dfd01cbc,
          mid_smallest_e79ba665,
          mid_smallestIndexes_980dd7f7,
          mid_sort_0253084a,
          mid_sortedIndexes_c221c4b5,
          mid_subColumns_8197bfb5,
          mid_subRows_8197bfb5,
          mid_subTable_c5afb567,
          mid_subToNew_8197bfb5,
          mid_subToNew_0a1bc13f,
          mid_sum_02530858,
          mid_sumCol_20d144ba,
          mid_sumRow_20d144ba,
          mid_toString_9ad9dfed,
          mid_toString_d56ff963,
          mid_toString_d3dcb281,
          mid_toString_ce8f9a33,
          mid_toString_800057f5,
          mid_transpose_0253084a,
          mid_unionToNew_76419023,
          mid_within_ce1f9f15,
          mid_withinIndexes_a57cac13,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit DoubleUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        DoubleUtilities(const DoubleUtilities& obj) : ::java::lang::Object(obj) {}

        DoubleUtilities();

        ::stallone::api::doubles::IDoubleArray cleanToNew(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean contains(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jboolean containsAll(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean containsAny(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        void copyInto(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jint, jint) const;
        void copyInto(const ::stallone::api::doubles::IDoubleArray &, jint, jint, const ::stallone::api::doubles::IDoubleArray &, jint) const;
        void copyInto(const ::stallone::api::doubles::IDoubleArray &, jint, jint, jint, jint, const ::stallone::api::doubles::IDoubleArray &, jint, jint) const;
        jint count(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jint countRows(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean equal(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean equal(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        void exchange(const ::stallone::api::doubles::IDoubleArray &, jint, jint) const;
        void fill(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::ints::IIntList findAll(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::ints::IIntList findAll(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::ints::IIntArray findAllRows(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jint findBackwards(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jint findBackwards(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jint findBackwards(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jint findBackwards(const ::stallone::api::doubles::IDoubleArray &, jdouble, jint) const;
        jint findClosest(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jint findForward(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jint findForward(const ::stallone::api::doubles::IDoubleArray &, jdouble, jint) const;
        jint findRowForward(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jint findRowForward(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jint findSorted(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray insertRowToNew(const ::stallone::api::doubles::IDoubleArray &, jint, const ::stallone::api::doubles::IDoubleArray &) const;
        void insertSorted(const ::stallone::api::doubles::IDoubleList &, jdouble) const;
        jint insertSortedFixed(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray insertToNew(const ::stallone::api::doubles::IDoubleArray &, jint, jdouble) const;
        ::stallone::api::doubles::IDoubleArray intersectionToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isSorted(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::ints::IIntArray largeValueIndexes(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray largeValues(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray largest(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::ints::IIntArray largestIndexes(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jint locateSorted(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jdouble max$(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble maxInColumn(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jdouble maxInLine(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jint maxIndex(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray merge(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray mergeColumns(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray mergeToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray mergeToNew(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        jdouble min$(const ::stallone::api::doubles::IDoubleArray &) const;
        jint minIndex(const ::stallone::api::doubles::IDoubleArray &) const;
        void mirror(const ::stallone::api::doubles::IDoubleArray &) const;
        void print(const ::stallone::api::doubles::IDoubleArray &) const;
        void print(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        void print(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &, const ::java::lang::String &) const;
        void print(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &, jint, jint) const;
        void print(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &, const ::java::lang::String &, jint, jint) const;
        ::stallone::api::doubles::IDoubleArray removeIndex(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray removeIndexToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray removeIndexToNew(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray removeRow(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray removeValueToNew(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray removeValueToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::ints::IIntArray smallValueIndexes(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray smallValues(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray smallest(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::ints::IIntArray smallestIndexes(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        void sort(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::ints::IIntArray sortedIndexes(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray subColumns(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray subRows(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray subTable(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray subToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray subToNew(const ::stallone::api::doubles::IDoubleArray &, jint, jint) const;
        jdouble sum(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble sumCol(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        jdouble sumRow(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::java::lang::String toString(const ::stallone::api::doubles::IDoubleArray &) const;
        ::java::lang::String toString(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &) const;
        ::java::lang::String toString(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &, const ::java::lang::String &) const;
        ::java::lang::String toString(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &, jint, jint) const;
        ::java::lang::String toString(const ::stallone::api::doubles::IDoubleArray &, const ::java::lang::String &, const ::java::lang::String &, jint, jint) const;
        void transpose(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray unionToNew(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray within(const ::stallone::api::doubles::IDoubleArray &, jdouble, jdouble) const;
        ::stallone::api::ints::IIntArray withinIndexes(const ::stallone::api::doubles::IDoubleArray &, jdouble, jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace doubles {
      extern PyTypeObject PY_TYPE(DoubleUtilities);

      class t_DoubleUtilities {
      public:
        PyObject_HEAD
        DoubleUtilities object;
        static PyObject *wrap_Object(const DoubleUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
