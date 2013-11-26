#ifndef stallone_api_API_H
#define stallone_api_API_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class FunctionUtilities;
      class FunctionFactory;
    }
    namespace discretization {
      class DiscretizationFactory;
      class DiscretizationUtilities;
    }
    namespace stat {
      class StatisticsFactory;
      class StatisticsUtilities;
    }
    namespace mc {
      class MarkovModelFactory;
      class MarkovModelUtilities;
    }
    namespace algebra {
      class AlgebraFactory;
      class AlgebraUtilities;
    }
    namespace graph {
      class GraphFactory;
      class GraphUtilities;
    }
    namespace complex {
      class ComplexFactory;
      class ComplexUtilities;
    }
    namespace cluster {
      class ClusterFactory;
      class ClusterUtilities;
    }
    namespace hmm {
      class HMMUtilities;
      class HMMFactory;
    }
    namespace ints {
      class IntFactory;
      class IntUtilities;
    }
    namespace potential {
      class PotentialFactory;
      class PotentialUtilities;
    }
    namespace io {
      class IOUtilities;
      class IOFactory;
    }
    namespace doubles {
      class DoubleFactory;
      class DoubleUtilities;
    }
    namespace dynamics {
      class DynamicsFactory;
      class DynamicsUtilities;
    }
    namespace datasequence {
      class DataSequenceUtilities;
      class DataSequenceFactory;
    }
    namespace strings {
      class StringFactory;
      class StringUtilities;
    }
    namespace intsequence {
      class IntSequenceUtilities;
      class IntSequenceFactory;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {

    class API : public ::java::lang::Object {
    public:
      enum {
        mid_init$_54c6a166,
        max_mid
      };

      static ::java::lang::Class *class$;
      static jmethodID *mids$;
      static bool live$;
      static jclass initializeClass(bool);

      explicit API(jobject obj) : ::java::lang::Object(obj) {
        if (obj != NULL)
          env->getClass(initializeClass);
      }
      API(const API& obj) : ::java::lang::Object(obj) {}

      static ::stallone::api::algebra::AlgebraUtilities *alg;
      static ::stallone::api::algebra::AlgebraFactory *algNew;
      static ::stallone::api::cluster::ClusterUtilities *cluster;
      static ::stallone::api::cluster::ClusterFactory *clusterNew;
      static ::stallone::api::complex::ComplexUtilities *complex;
      static ::stallone::api::complex::ComplexFactory *complexNew;
      static ::stallone::api::datasequence::DataSequenceUtilities *data;
      static ::stallone::api::datasequence::DataSequenceFactory *dataNew;
      static ::stallone::api::discretization::DiscretizationUtilities *disc;
      static ::stallone::api::discretization::DiscretizationFactory *discNew;
      static ::stallone::api::doubles::DoubleUtilities *doubles;
      static ::stallone::api::doubles::DoubleFactory *doublesNew;
      static ::stallone::api::dynamics::DynamicsUtilities *dyn;
      static ::stallone::api::dynamics::DynamicsFactory *dynNew;
      static ::stallone::api::function::FunctionUtilities *func;
      static ::stallone::api::function::FunctionFactory *funcNew;
      static ::stallone::api::graph::GraphUtilities *graph;
      static ::stallone::api::graph::GraphFactory *graphNew;
      static ::stallone::api::hmm::HMMUtilities *hmm;
      static ::stallone::api::hmm::HMMFactory *hmmNew;
      static ::stallone::api::ints::IntUtilities *ints;
      static ::stallone::api::ints::IntFactory *intsNew;
      static ::stallone::api::intsequence::IntSequenceUtilities *intseq;
      static ::stallone::api::intsequence::IntSequenceFactory *intseqNew;
      static ::stallone::api::io::IOUtilities *io;
      static ::stallone::api::io::IOFactory *ioNew;
      static ::stallone::api::mc::MarkovModelUtilities *msm;
      static ::stallone::api::mc::MarkovModelFactory *msmNew;
      static ::stallone::api::potential::PotentialUtilities *pot;
      static ::stallone::api::potential::PotentialFactory *potNew;
      static ::stallone::api::stat::StatisticsUtilities *stat;
      static ::stallone::api::stat::StatisticsFactory *statNew;
      static ::stallone::api::strings::StringUtilities *str;
      static ::stallone::api::strings::StringFactory *strNew;

      API();
    };
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    extern PyTypeObject PY_TYPE(API);

    class t_API {
    public:
      PyObject_HEAD
      API object;
      static PyObject *wrap_Object(const API&);
      static PyObject *wrap_jobject(const jobject&);
      static void install(PyObject *module);
      static void initialize(PyObject *module);
    };
  }
}

#endif
