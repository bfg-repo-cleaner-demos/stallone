#ifndef stallone_api_mc_MarkovModelFactory_H
#define stallone_api_mc_MarkovModelFactory_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
    class Iterable;
  }
}
namespace stallone {
  namespace api {
    namespace function {
      class IGriddedFunction;
    }
    namespace doubles {
      class IDoubleArray;
    }
    namespace mc {
      class IMarkovChain;
      class ITransitionMatrixEstimator;
      class ICountMatrixEstimator;
      class IDynamicalExpectationsSpectral;
      class IDynamicalExpectations;
      namespace tpt {
        class ITPTFlux;
        class ICommittor;
      }
    }
    namespace ints {
      class IIntArray;
    }
  }
  namespace mc {
    namespace sampling {
      class ITransitionMatrixSampler;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace mc {

      class MarkovModelFactory : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_createCommittor_870b6049,
          mid_createCommittor_3f63ad7d,
          mid_createCountMatrixEstimatorSliding_c083c1f7,
          mid_createCountMatrixEstimatorSliding_8189d6b4,
          mid_createCountMatrixEstimatorStepping_8189d6b4,
          mid_createCountMatrixEstimatorStepping_c083c1f7,
          mid_createDynamicalExpectations_de594d69,
          mid_createDynamicalExpectations_d135d589,
          mid_createDynamicalFingerprint_2aadcea1,
          mid_createDynamicalFingerprint_1cefcc2d,
          mid_createPosteriorCountsNeighbor_dfd01cbc,
          mid_createTPT_27159afe,
          mid_createTPT_4040b74e,
          mid_createTransitionMatrixEstimatorNonrev_73c61eaa,
          mid_createTransitionMatrixEstimatorRev_73c61eaa,
          mid_createTransitionMatrixEstimatorRev_a47d591e,
          mid_createTransitionMatrixSamplerNonrev_1d2309ec,
          mid_createTransitionMatrixSamplerRev_1d2309ec,
          mid_createTransitionMatrixSamplerRev_838432fc,
          mid_markovChain_0f97f92d,
          mid_markovChain_589965e1,
          mid_metropolisMC_c40bdb68,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit MarkovModelFactory(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        MarkovModelFactory(const MarkovModelFactory& obj) : ::java::lang::Object(obj) {}

        MarkovModelFactory();

        ::stallone::api::mc::tpt::ICommittor createCommittor(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::mc::tpt::ICommittor createCommittor(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::mc::ICountMatrixEstimator createCountMatrixEstimatorSliding(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::mc::ICountMatrixEstimator createCountMatrixEstimatorSliding(const ::java::lang::Iterable &, jint) const;
        ::stallone::api::mc::ICountMatrixEstimator createCountMatrixEstimatorStepping(const ::java::lang::Iterable &, jint) const;
        ::stallone::api::mc::ICountMatrixEstimator createCountMatrixEstimatorStepping(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::mc::IDynamicalExpectations createDynamicalExpectations(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::mc::IDynamicalExpectations createDynamicalExpectations(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::mc::IDynamicalExpectationsSpectral createDynamicalFingerprint(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::mc::IDynamicalExpectationsSpectral createDynamicalFingerprint(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray createPosteriorCountsNeighbor(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::mc::tpt::ITPTFlux createTPT(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::mc::tpt::ITPTFlux createTPT(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::mc::ITransitionMatrixEstimator createTransitionMatrixEstimatorNonrev() const;
        ::stallone::api::mc::ITransitionMatrixEstimator createTransitionMatrixEstimatorRev() const;
        ::stallone::api::mc::ITransitionMatrixEstimator createTransitionMatrixEstimatorRev(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::mc::sampling::ITransitionMatrixSampler createTransitionMatrixSamplerNonrev(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::mc::sampling::ITransitionMatrixSampler createTransitionMatrixSamplerRev(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::mc::sampling::ITransitionMatrixSampler createTransitionMatrixSamplerRev(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::mc::IMarkovChain markovChain(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::mc::IMarkovChain markovChain(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray metropolisMC(const ::stallone::api::function::IGriddedFunction &, jdouble) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(MarkovModelFactory);

      class t_MarkovModelFactory {
      public:
        PyObject_HEAD
        MarkovModelFactory object;
        static PyObject *wrap_Object(const MarkovModelFactory&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
