/**
 * \file PolarPointLandmark.h
 * \author Daniele Molinari -- 238168
 * \version 1.0
 */

#pragma once

////include
//SLAM
#include "../Base/types.h"

namespace SLAM { namespace Models { namespace PolarPointLandmark {
    ////model functions
    /**
     * This model make the following assumpions:
     * Xv = (X, Y, THETA)^t
     * Xm = (rho, alpha)^t
     * 
     * Where rho is the distance from the landmark and the robot, and alpha the relative angle.
     */
    ////perception
    VectorType H(const VectorType& Xv, const VectorType& Xm);
    MatrixType dH_dXv(const VectorType& Xv, const VectorType& Xm);
    MatrixType dH_dXm(const VectorType& Xv, const VectorType& Xm);
    ////initialization
    VectorType G(const VectorType& Xv, const VectorType& Z);
    MatrixType dG_dXv(const VectorType& Xv, const VectorType& Z);
    MatrixType dG_dZ(const VectorType& Xv, const VectorType& Z);
    ////distance and sorting
    VectorType PolarPointLandmarkDistance(const VectorType& z1, const VectorType& z2);
    bool Sort(const VectorType& z1, const VectorType& z2);
    
}
    ////model
    extern const LandmarkModel PolarPointLandmarkModel;
} }