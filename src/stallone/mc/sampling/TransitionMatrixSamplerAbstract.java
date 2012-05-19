/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package stallone.mc.sampling;

import stallone.api.algebra.Algebra;
import stallone.api.doubles.Doubles;
import stallone.api.doubles.IDoubleArray;
import stallone.api.mc.MarkovModel;

/**
 *
 * @author noe
 */
public abstract class TransitionMatrixSamplerAbstract implements ITransitionMatrixSampler
{

    protected IDoubleArray T, C;
    protected double logLikelihood = 0;
    
    public TransitionMatrixSamplerAbstract(IDoubleArray counts)
    {
        this.init(counts);
    }

    public TransitionMatrixSamplerAbstract(IDoubleArray counts, IDoubleArray Tinit)
    {
        this.init(counts,Tinit);
    }
    
    @Override
    public final void init(IDoubleArray counts)
    {
        this.C = counts;
        this.T = MarkovModel.util.estimateT(counts);
        this.logLikelihood = MarkovModel.util.logLikelihood(T, C);
    }

    @Override
    public final void init(IDoubleArray counts, IDoubleArray Tinit)
    {
        this.C = counts;
        this.T = Tinit;
        this.logLikelihood = MarkovModel.util.logLikelihood(T, C);
    }

    @Override
    public IDoubleArray sample(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            step();
        }

        this.logLikelihood = MarkovModel.util.logLikelihood(T, C);

        return (T);
    }

    /**
    Checks whether the given element is still within [0,1] or else puts it back to that
    value.
     */
    protected void validateElement(int i, int j)
    {
        if (T.get(i, j) < 0)
        {
            T.set(i, j, 0);
        }
        if (T.get(i, j) > 1)
        {
            T.set(i, j, 1);
        }
    }

    /**
    Makes sure that the row still sums up to 1.
     */
    protected void validateRow(int i)
    {
        IDoubleArray r = T.viewRow(i);
        Algebra.util.scale(1.0 / Doubles.util.sum(r), r);
    }

    protected abstract boolean step();

    @Override
    public double logLikelihood()
    {
        return (logLikelihood);
    }

}