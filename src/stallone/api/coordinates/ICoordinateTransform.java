/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package stallone.api.coordinates;

import stallone.api.datasequence.IDataInput;
import stallone.api.datasequence.IDataSequence;
import stallone.api.doubles.IDoubleArray;

/**
 *
 * Defines a map from one coordinate set to another coordinate set. 
 * Coordinate transforms include coordinate selection, linear projection (e.g. PCA),
 * calculation of nonlinear parameters (distances, angles, etc), projection onto
 * a basis set, etc.
 * 
 * @author noe
 */
public interface ICoordinateTransform
{
    /**
     * adds data to prepare the transform computation
     * @param data The data input
     */
    public void addData(IDataSequence data);
    
    /**
     * recomputes the transform based on all data added to this point. 
     * If the coordinate transform is constant, this call has no effect.
     * @param X A data sequence. 
     */
    public void computeTransform();

    /**
     * maps a single coordinate set using the current coordinate transform.
     * Default behavior: will call compute() if compute() has not yet been called, or if
     * data has been added after the last compute().
     * @param c a coordinate set
     * @return the transformed coordinate set
     */
    public IDoubleArray transform(IDoubleArray c);

    /**
     * Returns the output dimension of this transform
     * @return 
     */
    public int dimension();
}
