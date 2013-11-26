#include <jni.h>
#include <Python.h>
#include "JCCEnv.h"
#include "functions.h"

PyObject *initVM(PyObject *module, PyObject *args, PyObject *kwds);

namespace java {
  void __install__(PyObject *module);
  void __initialize__(PyObject *module);
}
namespace stallone {
  void __install__(PyObject *module);
  void __initialize__(PyObject *module);
}

void __install__(PyObject *module)
{
  java::__install__(module);
  stallone::__install__(module);
}

PyObject *__initialize__(PyObject *module, PyObject *args, PyObject *kwds)
{
  PyObject *env = initVM(module, args, kwds);

  if (env == NULL)
    return NULL;

  try {
    java::__initialize__(module);
    stallone::__initialize__(module);
    return env;
  } catch (int e) {
    switch(e) {
      case _EXC_JAVA:
      return PyErr_SetJavaError();
      default:
      throw;
    }
  }
}


namespace java {

  namespace io {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }
  namespace lang {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }
  namespace util {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }

  void __install__(PyObject *module)
  {
    io::__install__(module);
    lang::__install__(module);
    util::__install__(module);
  }

  void __initialize__(PyObject *module)
  {
    io::__initialize__(module);
    lang::__initialize__(module);
    util::__initialize__(module);
  }
}

#include "java/io/PrintWriter.h"
#include "java/io/StringWriter.h"
#include "java/io/Writer.h"

namespace java {
  namespace io {


    void __install__(PyObject *module)
    {
      t_PrintWriter::install(module);
      t_StringWriter::install(module);
      t_Writer::install(module);
    }

    void __initialize__(PyObject *module)
    {
      t_PrintWriter::initialize(module);
      t_StringWriter::initialize(module);
      t_Writer::initialize(module);
    }
  }
}

#include "java/lang/AbstractStringBuilder.h"
#include "java/lang/Appendable.h"
#include "java/lang/Boolean.h"
#include "java/lang/Byte.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Character.h"
#include "java/lang/Class.h"
#include "java/lang/ClassLoader.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/Comparable.h"
#include "java/lang/Double.h"
#include "java/lang/Enum.h"
#include "java/lang/Exception.h"
#include "java/lang/Float.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/IllegalArgumentException.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/Integer.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/Iterable.h"
#include "java/lang/Long.h"
#include "java/lang/Number.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Object.h"
#include "java/lang/Package.h"
#include "java/lang/RuntimeException.h"
#include "java/lang/SecurityException.h"
#include "java/lang/Short.h"
#include "java/lang/StackTraceElement.h"
#include "java/lang/String.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/StringBuilder.h"
#include "java/lang/Throwable.h"

namespace java {
  namespace lang {


    void __install__(PyObject *module)
    {
      t_AbstractStringBuilder::install(module);
      t_Appendable::install(module);
      t_Boolean::install(module);
      t_Byte::install(module);
      t_CharSequence::install(module);
      t_Character::install(module);
      t_Class::install(module);
      t_ClassLoader::install(module);
      t_ClassNotFoundException::install(module);
      t_Comparable::install(module);
      t_Double::install(module);
      t_Enum::install(module);
      t_Exception::install(module);
      t_Float::install(module);
      t_IllegalAccessException::install(module);
      t_IllegalArgumentException::install(module);
      t_InstantiationException::install(module);
      t_Integer::install(module);
      t_InterruptedException::install(module);
      t_Iterable::install(module);
      t_Long::install(module);
      t_Number::install(module);
      t_NumberFormatException::install(module);
      t_Object::install(module);
      t_Package::install(module);
      t_RuntimeException::install(module);
      t_SecurityException::install(module);
      t_Short::install(module);
      t_StackTraceElement::install(module);
      t_String::install(module);
      t_StringBuffer::install(module);
      t_StringBuilder::install(module);
      t_Throwable::install(module);
    }

    void __initialize__(PyObject *module)
    {
      t_AbstractStringBuilder::initialize(module);
      t_Appendable::initialize(module);
      t_Boolean::initialize(module);
      t_Byte::initialize(module);
      t_CharSequence::initialize(module);
      t_Character::initialize(module);
      t_Class::initialize(module);
      t_ClassLoader::initialize(module);
      t_ClassNotFoundException::initialize(module);
      t_Comparable::initialize(module);
      t_Double::initialize(module);
      t_Enum::initialize(module);
      t_Exception::initialize(module);
      t_Float::initialize(module);
      t_IllegalAccessException::initialize(module);
      t_IllegalArgumentException::initialize(module);
      t_InstantiationException::initialize(module);
      t_Integer::initialize(module);
      t_InterruptedException::initialize(module);
      t_Iterable::initialize(module);
      t_Long::initialize(module);
      t_Number::initialize(module);
      t_NumberFormatException::initialize(module);
      t_Object::initialize(module);
      t_Package::initialize(module);
      t_RuntimeException::initialize(module);
      t_SecurityException::initialize(module);
      t_Short::initialize(module);
      t_StackTraceElement::initialize(module);
      t_String::initialize(module);
      t_StringBuffer::initialize(module);
      t_StringBuilder::initialize(module);
      t_Throwable::initialize(module);
    }
  }
}

#include "java/util/Enumeration.h"
#include "java/util/Iterator.h"

namespace java {
  namespace util {


    void __install__(PyObject *module)
    {
      t_Enumeration::install(module);
      t_Iterator::install(module);
    }

    void __initialize__(PyObject *module)
    {
      t_Enumeration::initialize(module);
      t_Iterator::initialize(module);
    }
  }
}


namespace stallone {

  namespace api {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }
  namespace doubles {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }
  namespace dynamics {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }
  namespace mc {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
  }

  void __install__(PyObject *module)
  {
    api::__install__(module);
    doubles::__install__(module);
    dynamics::__install__(module);
    mc::__install__(module);
  }

  void __initialize__(PyObject *module)
  {
    api::__initialize__(module);
    doubles::__initialize__(module);
    dynamics::__initialize__(module);
    mc::__initialize__(module);
  }
}

#include "stallone/api/API.h"
#include "stallone/api/IAlgorithm.h"
#include "stallone/api/ICopyable.h"

namespace stallone {
  namespace api {

    namespace algebra {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace cluster {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace complex {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace datasequence {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace discretization {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace doubles {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace dynamics {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace function {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace graph {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace hmm {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace ints {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace intsequence {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace io {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace mc {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace potential {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace stat {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }
    namespace strings {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }

    void __install__(PyObject *module)
    {
      t_API::install(module);
      t_IAlgorithm::install(module);
      t_ICopyable::install(module);
      algebra::__install__(module);
      cluster::__install__(module);
      complex::__install__(module);
      datasequence::__install__(module);
      discretization::__install__(module);
      doubles::__install__(module);
      dynamics::__install__(module);
      function::__install__(module);
      graph::__install__(module);
      hmm::__install__(module);
      ints::__install__(module);
      intsequence::__install__(module);
      io::__install__(module);
      mc::__install__(module);
      potential::__install__(module);
      stat::__install__(module);
      strings::__install__(module);
    }

    void __initialize__(PyObject *module)
    {
      t_API::initialize(module);
      t_IAlgorithm::initialize(module);
      t_ICopyable::initialize(module);
      algebra::__initialize__(module);
      cluster::__initialize__(module);
      complex::__initialize__(module);
      datasequence::__initialize__(module);
      discretization::__initialize__(module);
      doubles::__initialize__(module);
      dynamics::__initialize__(module);
      function::__initialize__(module);
      graph::__initialize__(module);
      hmm::__initialize__(module);
      ints::__initialize__(module);
      intsequence::__initialize__(module);
      io::__initialize__(module);
      mc::__initialize__(module);
      potential::__initialize__(module);
      stat::__initialize__(module);
      strings::__initialize__(module);
    }
  }
}

#include "stallone/api/algebra/Algebra.h"
#include "stallone/api/algebra/AlgebraFactory.h"
#include "stallone/api/algebra/AlgebraFactory$EigenvalueDecompositionEnum.h"
#include "stallone/api/algebra/AlgebraFactory$LinearSystemEnum.h"
#include "stallone/api/algebra/AlgebraUtilities.h"
#include "stallone/api/algebra/ICholeskyDecomposition.h"
#include "stallone/api/algebra/IComplexNumber.h"
#include "stallone/api/algebra/IEigenvalueDecomposition.h"
#include "stallone/api/algebra/IEigenvalueSolver.h"
#include "stallone/api/algebra/ILUDecomposition.h"
#include "stallone/api/algebra/ILinearMatrixSystem.h"
#include "stallone/api/algebra/ILinearSystem.h"
#include "stallone/api/algebra/INorm.h"
#include "stallone/api/algebra/INumericalEquality.h"
#include "stallone/api/algebra/IPartialEigensystem.h"
#include "stallone/api/algebra/IQRDecomposition.h"

namespace stallone {
  namespace api {
    namespace algebra {


      void __install__(PyObject *module)
      {
        t_Algebra::install(module);
        t_AlgebraFactory::install(module);
        t_AlgebraFactory$EigenvalueDecompositionEnum::install(module);
        t_AlgebraFactory$LinearSystemEnum::install(module);
        t_AlgebraUtilities::install(module);
        t_ICholeskyDecomposition::install(module);
        t_IComplexNumber::install(module);
        t_IEigenvalueDecomposition::install(module);
        t_IEigenvalueSolver::install(module);
        t_ILUDecomposition::install(module);
        t_ILinearMatrixSystem::install(module);
        t_ILinearSystem::install(module);
        t_INorm::install(module);
        t_INumericalEquality::install(module);
        t_IPartialEigensystem::install(module);
        t_IQRDecomposition::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_Algebra::initialize(module);
        t_AlgebraFactory::initialize(module);
        t_AlgebraFactory$EigenvalueDecompositionEnum::initialize(module);
        t_AlgebraFactory$LinearSystemEnum::initialize(module);
        t_AlgebraUtilities::initialize(module);
        t_ICholeskyDecomposition::initialize(module);
        t_IComplexNumber::initialize(module);
        t_IEigenvalueDecomposition::initialize(module);
        t_IEigenvalueSolver::initialize(module);
        t_ILUDecomposition::initialize(module);
        t_ILinearMatrixSystem::initialize(module);
        t_ILinearSystem::initialize(module);
        t_INorm::initialize(module);
        t_INumericalEquality::initialize(module);
        t_IPartialEigensystem::initialize(module);
        t_IQRDecomposition::initialize(module);
      }
    }
  }
}

#include "stallone/api/cluster/ClusterFactory.h"
#include "stallone/api/cluster/ClusterUtilities.h"
#include "stallone/api/cluster/Clustering.h"
#include "stallone/api/cluster/IClustering.h"
#include "stallone/api/cluster/INeighborSearch.h"

namespace stallone {
  namespace api {
    namespace cluster {


      void __install__(PyObject *module)
      {
        t_ClusterFactory::install(module);
        t_ClusterUtilities::install(module);
        t_Clustering::install(module);
        t_IClustering::install(module);
        t_INeighborSearch::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_ClusterFactory::initialize(module);
        t_ClusterUtilities::initialize(module);
        t_Clustering::initialize(module);
        t_IClustering::initialize(module);
        t_INeighborSearch::initialize(module);
      }
    }
  }
}

#include "stallone/api/complex/Complex.h"
#include "stallone/api/complex/ComplexFactory.h"
#include "stallone/api/complex/ComplexUtilities.h"
#include "stallone/api/complex/IComplexArray.h"
#include "stallone/api/complex/IComplexElement.h"
#include "stallone/api/complex/IComplexIterator.h"
#include "stallone/api/complex/ImaginaryView.h"

namespace stallone {
  namespace api {
    namespace complex {


      void __install__(PyObject *module)
      {
        t_Complex::install(module);
        t_ComplexFactory::install(module);
        t_ComplexUtilities::install(module);
        t_IComplexArray::install(module);
        t_IComplexElement::install(module);
        t_IComplexIterator::install(module);
        t_ImaginaryView::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_Complex::initialize(module);
        t_ComplexFactory::initialize(module);
        t_ComplexUtilities::initialize(module);
        t_IComplexArray::initialize(module);
        t_IComplexElement::initialize(module);
        t_IComplexIterator::initialize(module);
        t_ImaginaryView::initialize(module);
      }
    }
  }
}

#include "stallone/api/datasequence/DataSequence.h"
#include "stallone/api/datasequence/DataSequenceFactory.h"
#include "stallone/api/datasequence/DataSequenceUtilities.h"
#include "stallone/api/datasequence/IDataList.h"
#include "stallone/api/datasequence/IDataReader.h"
#include "stallone/api/datasequence/IDataSequence.h"
#include "stallone/api/datasequence/IDataSequenceLoader.h"
#include "stallone/api/datasequence/IDataWriter.h"

namespace stallone {
  namespace api {
    namespace datasequence {


      void __install__(PyObject *module)
      {
        t_DataSequence::install(module);
        t_DataSequenceFactory::install(module);
        t_DataSequenceUtilities::install(module);
        t_IDataList::install(module);
        t_IDataReader::install(module);
        t_IDataSequence::install(module);
        t_IDataSequenceLoader::install(module);
        t_IDataWriter::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_DataSequence::initialize(module);
        t_DataSequenceFactory::initialize(module);
        t_DataSequenceUtilities::initialize(module);
        t_IDataList::initialize(module);
        t_IDataReader::initialize(module);
        t_IDataSequence::initialize(module);
        t_IDataSequenceLoader::initialize(module);
        t_IDataWriter::initialize(module);
      }
    }
  }
}

#include "stallone/api/discretization/Discretization.h"
#include "stallone/api/discretization/DiscretizationFactory.h"
#include "stallone/api/discretization/DiscretizationUtilities.h"
#include "stallone/api/discretization/IDiscretization.h"

namespace stallone {
  namespace api {
    namespace discretization {


      void __install__(PyObject *module)
      {
        t_Discretization::install(module);
        t_DiscretizationFactory::install(module);
        t_DiscretizationUtilities::install(module);
        t_IDiscretization::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_Discretization::initialize(module);
        t_DiscretizationFactory::initialize(module);
        t_DiscretizationUtilities::initialize(module);
        t_IDiscretization::initialize(module);
      }
    }
  }
}

#include "stallone/api/doubles/DoubleFactory.h"
#include "stallone/api/doubles/DoubleUtilities.h"
#include "stallone/api/doubles/Doubles.h"
#include "stallone/api/doubles/DoublesPrimitive.h"
#include "stallone/api/doubles/IDifferentiableMetric.h"
#include "stallone/api/doubles/IDoubleArray.h"
#include "stallone/api/doubles/IDoubleElement.h"
#include "stallone/api/doubles/IDoubleIterator.h"
#include "stallone/api/doubles/IDoubleList.h"
#include "stallone/api/doubles/IMetric.h"
#include "stallone/api/doubles/ISortDouble.h"

namespace stallone {
  namespace api {
    namespace doubles {


      void __install__(PyObject *module)
      {
        t_DoubleFactory::install(module);
        t_DoubleUtilities::install(module);
        t_Doubles::install(module);
        t_DoublesPrimitive::install(module);
        t_IDifferentiableMetric::install(module);
        t_IDoubleArray::install(module);
        t_IDoubleElement::install(module);
        t_IDoubleIterator::install(module);
        t_IDoubleList::install(module);
        t_IMetric::install(module);
        t_ISortDouble::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_DoubleFactory::initialize(module);
        t_DoubleUtilities::initialize(module);
        t_Doubles::initialize(module);
        t_DoublesPrimitive::initialize(module);
        t_IDifferentiableMetric::initialize(module);
        t_IDoubleArray::initialize(module);
        t_IDoubleElement::initialize(module);
        t_IDoubleIterator::initialize(module);
        t_IDoubleList::initialize(module);
        t_IMetric::initialize(module);
        t_ISortDouble::initialize(module);
      }
    }
  }
}

#include "stallone/api/dynamics/Dynamics.h"
#include "stallone/api/dynamics/DynamicsFactory.h"
#include "stallone/api/dynamics/DynamicsUtilities.h"

namespace stallone {
  namespace api {
    namespace dynamics {


      void __install__(PyObject *module)
      {
        t_Dynamics::install(module);
        t_DynamicsFactory::install(module);
        t_DynamicsUtilities::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_Dynamics::initialize(module);
        t_DynamicsFactory::initialize(module);
        t_DynamicsUtilities::initialize(module);
      }
    }
  }
}

#include "stallone/api/function/FunctionFactory.h"
#include "stallone/api/function/FunctionUtilities.h"
#include "stallone/api/function/Functions.h"
#include "stallone/api/function/IDiscretizedFunction.h"
#include "stallone/api/function/IFunction.h"
#include "stallone/api/function/IFunctionC1.h"
#include "stallone/api/function/IGrid.h"
#include "stallone/api/function/IGriddedFunction.h"
#include "stallone/api/function/IParametricFunction.h"

namespace stallone {
  namespace api {
    namespace function {


      void __install__(PyObject *module)
      {
        t_FunctionFactory::install(module);
        t_FunctionUtilities::install(module);
        t_Functions::install(module);
        t_IDiscretizedFunction::install(module);
        t_IFunction::install(module);
        t_IFunctionC1::install(module);
        t_IGrid::install(module);
        t_IGriddedFunction::install(module);
        t_IParametricFunction::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_FunctionFactory::initialize(module);
        t_FunctionUtilities::initialize(module);
        t_Functions::initialize(module);
        t_IDiscretizedFunction::initialize(module);
        t_IFunction::initialize(module);
        t_IFunctionC1::initialize(module);
        t_IGrid::initialize(module);
        t_IGriddedFunction::initialize(module);
        t_IParametricFunction::initialize(module);
      }
    }
  }
}

#include "stallone/api/graph/Graph.h"
#include "stallone/api/graph/GraphFactory.h"
#include "stallone/api/graph/GraphUtilities.h"
#include "stallone/api/graph/IDynamicIntGraph.h"
#include "stallone/api/graph/IEdge.h"
#include "stallone/api/graph/IGraph.h"
#include "stallone/api/graph/IIntConnectivity.h"
#include "stallone/api/graph/IIntEdge.h"
#include "stallone/api/graph/IIntGraph.h"

namespace stallone {
  namespace api {
    namespace graph {


      void __install__(PyObject *module)
      {
        t_Graph::install(module);
        t_GraphFactory::install(module);
        t_GraphUtilities::install(module);
        t_IDynamicIntGraph::install(module);
        t_IEdge::install(module);
        t_IGraph::install(module);
        t_IIntConnectivity::install(module);
        t_IIntEdge::install(module);
        t_IIntGraph::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_Graph::initialize(module);
        t_GraphFactory::initialize(module);
        t_GraphUtilities::initialize(module);
        t_IDynamicIntGraph::initialize(module);
        t_IEdge::initialize(module);
        t_IGraph::initialize(module);
        t_IIntConnectivity::initialize(module);
        t_IIntEdge::initialize(module);
        t_IIntGraph::initialize(module);
      }
    }
  }
}

#include "stallone/api/hmm/HMM.h"
#include "stallone/api/hmm/HMMFactory.h"
#include "stallone/api/hmm/HMMUtilities.h"
#include "stallone/api/hmm/IExpectationMaximization.h"
#include "stallone/api/hmm/IHMM.h"
#include "stallone/api/hmm/IHMMHiddenVariables.h"
#include "stallone/api/hmm/IHMMOptimizer.h"
#include "stallone/api/hmm/IHMMParameters.h"
#include "stallone/api/hmm/ParameterEstimationException.h"

namespace stallone {
  namespace api {
    namespace hmm {


      void __install__(PyObject *module)
      {
        t_HMM::install(module);
        t_HMMFactory::install(module);
        t_HMMUtilities::install(module);
        t_IExpectationMaximization::install(module);
        t_IHMM::install(module);
        t_IHMMHiddenVariables::install(module);
        t_IHMMOptimizer::install(module);
        t_IHMMParameters::install(module);
        t_ParameterEstimationException::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_HMM::initialize(module);
        t_HMMFactory::initialize(module);
        t_HMMUtilities::initialize(module);
        t_IExpectationMaximization::initialize(module);
        t_IHMM::initialize(module);
        t_IHMMHiddenVariables::initialize(module);
        t_IHMMOptimizer::initialize(module);
        t_IHMMParameters::initialize(module);
        t_ParameterEstimationException::initialize(module);
      }
    }
  }
}

#include "stallone/api/ints/IIndexMap.h"
#include "stallone/api/ints/IIntArray.h"
#include "stallone/api/ints/IIntElement.h"
#include "stallone/api/ints/IIntIterator.h"
#include "stallone/api/ints/IIntList.h"
#include "stallone/api/ints/ISortInt.h"
#include "stallone/api/ints/IntFactory.h"
#include "stallone/api/ints/IntUtilities.h"
#include "stallone/api/ints/Ints.h"
#include "stallone/api/ints/IntsPrimitive.h"

namespace stallone {
  namespace api {
    namespace ints {


      void __install__(PyObject *module)
      {
        t_IIndexMap::install(module);
        t_IIntArray::install(module);
        t_IIntElement::install(module);
        t_IIntIterator::install(module);
        t_IIntList::install(module);
        t_ISortInt::install(module);
        t_IntFactory::install(module);
        t_IntUtilities::install(module);
        t_Ints::install(module);
        t_IntsPrimitive::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_IIndexMap::initialize(module);
        t_IIntArray::initialize(module);
        t_IIntElement::initialize(module);
        t_IIntIterator::initialize(module);
        t_IIntList::initialize(module);
        t_ISortInt::initialize(module);
        t_IntFactory::initialize(module);
        t_IntUtilities::initialize(module);
        t_Ints::initialize(module);
        t_IntsPrimitive::initialize(module);
      }
    }
  }
}

#include "stallone/api/intsequence/IIntReader.h"
#include "stallone/api/intsequence/IIntSequenceLoader.h"
#include "stallone/api/intsequence/IIntWriter.h"
#include "stallone/api/intsequence/IntSequence.h"
#include "stallone/api/intsequence/IntSequenceFactory.h"
#include "stallone/api/intsequence/IntSequenceUtilities.h"

namespace stallone {
  namespace api {
    namespace intsequence {


      void __install__(PyObject *module)
      {
        t_IIntReader::install(module);
        t_IIntSequenceLoader::install(module);
        t_IIntWriter::install(module);
        t_IntSequence::install(module);
        t_IntSequenceFactory::install(module);
        t_IntSequenceUtilities::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_IIntReader::initialize(module);
        t_IIntSequenceLoader::initialize(module);
        t_IIntWriter::initialize(module);
        t_IntSequence::initialize(module);
        t_IntSequenceFactory::initialize(module);
        t_IntSequenceUtilities::initialize(module);
      }
    }
  }
}

#include "stallone/api/io/IO.h"
#include "stallone/api/io/IOFactory.h"
#include "stallone/api/io/IOUtilities.h"
#include "stallone/api/io/IReleasableFile.h"

namespace stallone {
  namespace api {
    namespace io {


      void __install__(PyObject *module)
      {
        t_IO::install(module);
        t_IOFactory::install(module);
        t_IOUtilities::install(module);
        t_IReleasableFile::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_IO::initialize(module);
        t_IOFactory::initialize(module);
        t_IOUtilities::initialize(module);
        t_IReleasableFile::initialize(module);
      }
    }
  }
}

#include "stallone/api/mc/ICountMatrixEstimator.h"
#include "stallone/api/mc/IDynamicalExpectations.h"
#include "stallone/api/mc/IDynamicalExpectationsSpectral.h"
#include "stallone/api/mc/IMarkovChain.h"
#include "stallone/api/mc/IMarkovPropagator.h"
#include "stallone/api/mc/ITransitionMatrixEstimator.h"
#include "stallone/api/mc/MarkovModel.h"
#include "stallone/api/mc/MarkovModelFactory.h"
#include "stallone/api/mc/MarkovModelUtilities.h"

namespace stallone {
  namespace api {
    namespace mc {

      namespace tpt {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
      }

      void __install__(PyObject *module)
      {
        t_ICountMatrixEstimator::install(module);
        t_IDynamicalExpectations::install(module);
        t_IDynamicalExpectationsSpectral::install(module);
        t_IMarkovChain::install(module);
        t_IMarkovPropagator::install(module);
        t_ITransitionMatrixEstimator::install(module);
        t_MarkovModel::install(module);
        t_MarkovModelFactory::install(module);
        t_MarkovModelUtilities::install(module);
        tpt::__install__(module);
      }

      void __initialize__(PyObject *module)
      {
        t_ICountMatrixEstimator::initialize(module);
        t_IDynamicalExpectations::initialize(module);
        t_IDynamicalExpectationsSpectral::initialize(module);
        t_IMarkovChain::initialize(module);
        t_IMarkovPropagator::initialize(module);
        t_ITransitionMatrixEstimator::initialize(module);
        t_MarkovModel::initialize(module);
        t_MarkovModelFactory::initialize(module);
        t_MarkovModelUtilities::initialize(module);
        tpt::__initialize__(module);
      }
    }
  }
}

#include "stallone/api/mc/tpt/ICommittor.h"
#include "stallone/api/mc/tpt/ITPTFlux.h"

namespace stallone {
  namespace api {
    namespace mc {
      namespace tpt {


        void __install__(PyObject *module)
        {
          t_ICommittor::install(module);
          t_ITPTFlux::install(module);
        }

        void __initialize__(PyObject *module)
        {
          t_ICommittor::initialize(module);
          t_ITPTFlux::initialize(module);
        }
      }
    }
  }
}

#include "stallone/api/potential/IEnergyModel.h"
#include "stallone/api/potential/IMassEnergyModel.h"
#include "stallone/api/potential/PotentialFactory.h"
#include "stallone/api/potential/PotentialUtilities.h"
#include "stallone/api/potential/Potentials.h"

namespace stallone {
  namespace api {
    namespace potential {


      void __install__(PyObject *module)
      {
        t_IEnergyModel::install(module);
        t_IMassEnergyModel::install(module);
        t_PotentialFactory::install(module);
        t_PotentialUtilities::install(module);
        t_Potentials::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_IEnergyModel::initialize(module);
        t_IMassEnergyModel::initialize(module);
        t_PotentialFactory::initialize(module);
        t_PotentialUtilities::initialize(module);
        t_Potentials::initialize(module);
      }
    }
  }
}

#include "stallone/api/stat/IDiscreteDistribution.h"
#include "stallone/api/stat/IParameterEstimator.h"
#include "stallone/api/stat/Statistics.h"
#include "stallone/api/stat/StatisticsFactory.h"
#include "stallone/api/stat/StatisticsUtilities.h"

namespace stallone {
  namespace api {
    namespace stat {


      void __install__(PyObject *module)
      {
        t_IDiscreteDistribution::install(module);
        t_IParameterEstimator::install(module);
        t_Statistics::install(module);
        t_StatisticsFactory::install(module);
        t_StatisticsUtilities::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_IDiscreteDistribution::initialize(module);
        t_IParameterEstimator::initialize(module);
        t_Statistics::initialize(module);
        t_StatisticsFactory::initialize(module);
        t_StatisticsUtilities::initialize(module);
      }
    }
  }
}

#include "stallone/api/strings/StringFactory.h"
#include "stallone/api/strings/StringUtilities.h"
#include "stallone/api/strings/Strings.h"

namespace stallone {
  namespace api {
    namespace strings {


      void __install__(PyObject *module)
      {
        t_StringFactory::install(module);
        t_StringUtilities::install(module);
        t_Strings::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_StringFactory::initialize(module);
        t_StringUtilities::initialize(module);
        t_Strings::initialize(module);
      }
    }
  }
}

#include "stallone/doubles/AbstractDoubleArray.h"

namespace stallone {
  namespace doubles {


    void __install__(PyObject *module)
    {
      t_AbstractDoubleArray::install(module);
    }

    void __initialize__(PyObject *module)
    {
      t_AbstractDoubleArray::initialize(module);
    }
  }
}

#include "stallone/dynamics/IIntegrator.h"
#include "stallone/dynamics/IIntegratorThermostatted.h"

namespace stallone {
  namespace dynamics {


    void __install__(PyObject *module)
    {
      t_IIntegrator::install(module);
      t_IIntegratorThermostatted::install(module);
    }

    void __initialize__(PyObject *module)
    {
      t_IIntegrator::initialize(module);
      t_IIntegratorThermostatted::initialize(module);
    }
  }
}


namespace stallone {
  namespace mc {

    namespace sampling {
      void __install__(PyObject *module);
      void __initialize__(PyObject *module);
    }

    void __install__(PyObject *module)
    {
      sampling::__install__(module);
    }

    void __initialize__(PyObject *module)
    {
      sampling::__initialize__(module);
    }
  }
}

#include "stallone/mc/sampling/IReversibleSamplingStep.h"
#include "stallone/mc/sampling/ITransitionMatrixSampler.h"

namespace stallone {
  namespace mc {
    namespace sampling {


      void __install__(PyObject *module)
      {
        t_IReversibleSamplingStep::install(module);
        t_ITransitionMatrixSampler::install(module);
      }

      void __initialize__(PyObject *module)
      {
        t_IReversibleSamplingStep::initialize(module);
        t_ITransitionMatrixSampler::initialize(module);
      }
    }
  }
}

