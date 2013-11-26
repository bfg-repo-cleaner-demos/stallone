#ifndef stallone_api_ints_IntUtilities_H
#define stallone_api_ints_IntUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class String;
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

      class IntUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_addToNew_00a49289,
          mid_addToNew_3c84c841,
          mid_addWeightedToNew_6cbdeeb1,
          mid_cleanToNew_fcbe62e3,
          mid_contains_216ff4fa,
          mid_containsAll_88ee8492,
          mid_containsAny_88ee8492,
          mid_copyInto_7f2ce4ac,
          mid_copyInto_6060468e,
          mid_copyRowsInto_f0691f5e,
          mid_count_216ff4e9,
          mid_countRows_88ee8481,
          mid_distance_88ee848c,
          mid_divideElementsToNew_00a49289,
          mid_equal_88ee8492,
          mid_exchange_0f2cb3ac,
          mid_fill_216ff4f6,
          mid_findAll_3ee017bd,
          mid_findAll_71898735,
          mid_findAllRows_00a49289,
          mid_findBackwards_216ff4e9,
          mid_findBackwards_88ee8481,
          mid_findBackwards_0f2cb3b3,
          mid_findBackwards_4126fa83,
          mid_findForward_216ff4e9,
          mid_findForward_0f2cb3b3,
          mid_findRowForward_88ee8481,
          mid_findRowForward_4126fa83,
          mid_findSorted_216ff4e9,
          mid_increment_216ff4f6,
          mid_increment_88ee849e,
          mid_insertRowToNew_69e38273,
          mid_insertSorted_814f05aa,
          mid_insertSortedFixed_216ff4e9,
          mid_insertToNew_236de56b,
          mid_intersectionToNew_71898735,
          mid_largeValueIndexes_3c84c841,
          mid_largeValues_3c84c841,
          mid_largest_3c84c841,
          mid_largestIndexes_3c84c841,
          mid_locateSorted_216ff4e9,
          mid_max_059aa48b,
          mid_maxInColumn_216ff4e4,
          mid_maxInLine_216ff4e4,
          mid_maxIndex_059aa48b,
          mid_mergeRowsToNew_00a49289,
          mid_mergeToNew_3c84c841,
          mid_mergeToNew_00a49289,
          mid_min_059aa48b,
          mid_minIndex_059aa48b,
          mid_mirror_059aa494,
          mid_multiplyElementsToNew_00a49289,
          mid_negate_059aa494,
          mid_print_059aa494,
          mid_print_ce6111f0,
          mid_print_323608c8,
          mid_removeIndex_00a49289,
          mid_removeIndexToNew_00a49289,
          mid_removeIndexToNew_3c84c841,
          mid_removeRow_3c84c841,
          mid_removeValueToNew_3c84c841,
          mid_removeValueToNew_00a49289,
          mid_scale_537625be,
          mid_smallValueIndexes_3c84c841,
          mid_smallValues_3c84c841,
          mid_smallest_3c84c841,
          mid_smallestIndexes_3c84c841,
          mid_sort_059aa494,
          mid_sortedIndexes_fcbe62e3,
          mid_square_059aa494,
          mid_subColsToNew_00a49289,
          mid_subRowsToNew_00a49289,
          mid_subToNew_00a49289,
          mid_subToNew_236de56b,
          mid_subToNew_fdab4d13,
          mid_sum_059aa486,
          mid_sumCol_216ff4e9,
          mid_sumRow_216ff4e9,
          mid_toString_a9a4a8f3,
          mid_toString_0003ef97,
          mid_toString_44702867,
          mid_transpose_059aa494,
          mid_unionToNew_00a49289,
          mid_within_236de56b,
          mid_withinIndexes_236de56b,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit IntUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        IntUtilities(const IntUtilities& obj) : ::java::lang::Object(obj) {}

        IntUtilities();

        ::stallone::api::ints::IIntArray addToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray addToNew(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray addWeightedToNew(jint, const ::stallone::api::ints::IIntArray &, jint, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray cleanToNew(const ::stallone::api::ints::IIntArray &) const;
        jboolean contains(const ::stallone::api::ints::IIntArray &, jint) const;
        jboolean containsAll(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jboolean containsAny(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        void copyInto(const ::stallone::api::ints::IIntArray &, jint, jint, const ::stallone::api::ints::IIntArray &, jint) const;
        void copyInto(const ::stallone::api::ints::IIntArray &, jint, jint, jint, jint, const ::stallone::api::ints::IIntArray &, jint, jint) const;
        void copyRowsInto(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &, jint, jint) const;
        jint count(const ::stallone::api::ints::IIntArray &, jint) const;
        jint countRows(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jdouble distance(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray divideElementsToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jboolean equal(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        void exchange(const ::stallone::api::ints::IIntArray &, jint, jint) const;
        void fill(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntList findAll(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntList findAll(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray findAllRows(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jint findBackwards(const ::stallone::api::ints::IIntArray &, jint) const;
        jint findBackwards(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jint findBackwards(const ::stallone::api::ints::IIntArray &, jint, jint) const;
        jint findBackwards(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &, jint) const;
        jint findForward(const ::stallone::api::ints::IIntArray &, jint) const;
        jint findForward(const ::stallone::api::ints::IIntArray &, jint, jint) const;
        jint findRowForward(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jint findRowForward(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &, jint) const;
        jint findSorted(const ::stallone::api::ints::IIntArray &, jint) const;
        void increment(const ::stallone::api::ints::IIntArray &, jint) const;
        void increment(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray insertRowToNew(const ::stallone::api::ints::IIntArray &, jint, const ::stallone::api::ints::IIntArray &) const;
        void insertSorted(const ::stallone::api::ints::IIntList &, jint) const;
        jint insertSortedFixed(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray insertToNew(const ::stallone::api::ints::IIntArray &, jint, jint) const;
        ::stallone::api::ints::IIntList intersectionToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray largeValueIndexes(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray largeValues(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray largest(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray largestIndexes(const ::stallone::api::ints::IIntArray &, jint) const;
        jint locateSorted(const ::stallone::api::ints::IIntArray &, jint) const;
        jint max$(const ::stallone::api::ints::IIntArray &) const;
        jdouble maxInColumn(const ::stallone::api::ints::IIntArray &, jint) const;
        jdouble maxInLine(const ::stallone::api::ints::IIntArray &, jint) const;
        jint maxIndex(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray mergeRowsToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray mergeToNew(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray mergeToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jint min$(const ::stallone::api::ints::IIntArray &) const;
        jint minIndex(const ::stallone::api::ints::IIntArray &) const;
        void mirror(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray multiplyElementsToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        void negate(const ::stallone::api::ints::IIntArray &) const;
        void print(const ::stallone::api::ints::IIntArray &) const;
        void print(const ::stallone::api::ints::IIntArray &, const ::java::lang::String &, const ::java::lang::String &) const;
        void print(const ::stallone::api::ints::IIntArray &, const ::java::lang::String &, const ::java::lang::String &, jint, jint) const;
        ::stallone::api::ints::IIntArray removeIndex(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray removeIndexToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray removeIndexToNew(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray removeRow(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray removeValueToNew(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray removeValueToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        void scale(jint, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray smallValueIndexes(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray smallValues(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray smallest(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::ints::IIntArray smallestIndexes(const ::stallone::api::ints::IIntArray &, jint) const;
        void sort(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray sortedIndexes(const ::stallone::api::ints::IIntArray &) const;
        void square(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray subColsToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray subRowsToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray subToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray subToNew(const ::stallone::api::ints::IIntArray &, jint, jint) const;
        ::stallone::api::ints::IIntArray subToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        jdouble sum(const ::stallone::api::ints::IIntArray &) const;
        jint sumCol(const ::stallone::api::ints::IIntArray &, jint) const;
        jint sumRow(const ::stallone::api::ints::IIntArray &, jint) const;
        ::java::lang::String toString(const ::stallone::api::ints::IIntArray &) const;
        ::java::lang::String toString(const ::stallone::api::ints::IIntArray &, const ::java::lang::String &, const ::java::lang::String &) const;
        ::java::lang::String toString(const ::stallone::api::ints::IIntArray &, const ::java::lang::String &, const ::java::lang::String &, jint, jint) const;
        void transpose(const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray unionToNew(const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray within(const ::stallone::api::ints::IIntArray &, jint, jint) const;
        ::stallone::api::ints::IIntArray withinIndexes(const ::stallone::api::ints::IIntArray &, jint, jint) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace ints {
      extern PyTypeObject PY_TYPE(IntUtilities);

      class t_IntUtilities {
      public:
        PyObject_HEAD
        IntUtilities object;
        static PyObject *wrap_Object(const IntUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
