#ifndef stallone_api_mc_MarkovModelUtilities_H
#define stallone_api_mc_MarkovModelUtilities_H

#include "java/lang/Object.h"

namespace java {
  namespace lang {
    class Class;
    class Iterable;
  }
}
namespace stallone {
  namespace api {
    namespace doubles {
      class IDoubleArray;
    }
    namespace mc {
      class ICountMatrixEstimator;
      class ITransitionMatrixEstimator;
    }
    namespace ints {
      class IIntArray;
    }
  }
}
template<class T> class JArray;

namespace stallone {
  namespace api {
    namespace mc {

      class MarkovModelUtilities : public ::java::lang::Object {
      public:
        enum {
          mid_init$_54c6a166,
          mid_autocorrelation_3313c4fb,
          mid_backwardCommittor_c5afb567,
          mid_correlation_ea708cbb,
          mid_estimateC_b74ef8f0,
          mid_estimateC_5bff2c17,
          mid_estimateCmilestoning_b74ef8f0,
          mid_estimateCmilestoning_5bff2c17,
          mid_estimateCmilestoning_b16959dd,
          mid_estimateCmilestoning_86e7ef1e,
          mid_estimateCstepping_b74ef8f0,
          mid_estimateCstepping_5bff2c17,
          mid_estimateT_32638cb7,
          mid_estimateTrev_32638cb7,
          mid_estimateTrev_76419023,
          mid_fingerprintAutocorrelation_76419023,
          mid_fingerprintCorrelation_3313c4fb,
          mid_fingerprintPerturbation_3313c4fb,
          mid_forwardCommittor_c5afb567,
          mid_giantComponent_c221c4b5,
          mid_isConnected_02530846,
          mid_isRateMatrix_02530846,
          mid_isReversible_02530846,
          mid_isReversible_608d4886,
          mid_isTransitionMatrix_02530846,
          mid_logLikelihood_608d4898,
          mid_logLikelihoodCorrelationMatrix_608d4898,
          mid_metastableMemberships_e79ba665,
          mid_metastableStates_980dd7f7,
          mid_perturbationExpectation_ea708cbb,
          mid_stationaryDistribution_32638cb7,
          mid_stationaryDistributionRevQuick_32638cb7,
          mid_timescales_dfd01cbc,
          mid_timescales_c5fddb47,
          mid_trajectory_dafcf1a9,
          mid_trajectoryToState_d54dbd05,
          max_mid
        };

        static ::java::lang::Class *class$;
        static jmethodID *mids$;
        static bool live$;
        static jclass initializeClass(bool);

        explicit MarkovModelUtilities(jobject obj) : ::java::lang::Object(obj) {
          if (obj != NULL)
            env->getClass(initializeClass);
        }
        MarkovModelUtilities(const MarkovModelUtilities& obj) : ::java::lang::Object(obj) {}

        MarkovModelUtilities();

        ::stallone::api::doubles::IDoubleArray autocorrelation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray backwardCommittor(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::doubles::IDoubleArray correlation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray estimateC(const ::java::lang::Iterable &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateC(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateCmilestoning(const ::java::lang::Iterable &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateCmilestoning(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateCmilestoning(const ::java::lang::Iterable &, const ::java::lang::Iterable &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateCmilestoning(const ::stallone::api::ints::IIntArray &, const ::java::lang::Iterable &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateCstepping(const ::java::lang::Iterable &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateCstepping(const ::stallone::api::ints::IIntArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray estimateT(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray estimateTrev(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray estimateTrev(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray fingerprintAutocorrelation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray fingerprintCorrelation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray fingerprintPerturbation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray forwardCommittor(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::ints::IIntArray &, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray giantComponent(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isConnected(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isRateMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isReversible(const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isReversible(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jboolean isTransitionMatrix(const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble logLikelihood(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        jdouble logLikelihoodCorrelationMatrix(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray metastableMemberships(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::ints::IIntArray metastableStates(const ::stallone::api::doubles::IDoubleArray &, jint) const;
        ::stallone::api::doubles::IDoubleArray perturbationExpectation(const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &, const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray stationaryDistribution(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray stationaryDistributionRevQuick(const ::stallone::api::doubles::IDoubleArray &) const;
        ::stallone::api::doubles::IDoubleArray timescales(const ::stallone::api::doubles::IDoubleArray &, jdouble) const;
        ::stallone::api::doubles::IDoubleArray timescales(const ::java::lang::Iterable &, const ::stallone::api::mc::ICountMatrixEstimator &, const ::stallone::api::mc::ITransitionMatrixEstimator &, jint, const ::stallone::api::ints::IIntArray &) const;
        ::stallone::api::ints::IIntArray trajectory(const ::stallone::api::doubles::IDoubleArray &, jint, jint) const;
        ::stallone::api::ints::IIntArray trajectoryToState(const ::stallone::api::doubles::IDoubleArray &, jint, const JArray< jint > &) const;
      };
    }
  }
}

#include <Python.h>

namespace stallone {
  namespace api {
    namespace mc {
      extern PyTypeObject PY_TYPE(MarkovModelUtilities);

      class t_MarkovModelUtilities {
      public:
        PyObject_HEAD
        MarkovModelUtilities object;
        static PyObject *wrap_Object(const MarkovModelUtilities&);
        static PyObject *wrap_jobject(const jobject&);
        static void install(PyObject *module);
        static void initialize(PyObject *module);
      };
    }
  }
}

#endif
