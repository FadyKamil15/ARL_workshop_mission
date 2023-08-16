#include <iostream>
#include <Eigen/Dense>
 
using namespace Eigen;
using namespace std; 

#define T 0.005
int main()
{
    //system states and input. p -> position. u -> input 
    double p_double_dot = 5, p = 5, p_dot = 10;

    //noise parameters  Q -> process variance, R -> measurement noise, P -> predicted covariance
    Matrix2d Q; Q << 0.1, 0,
                    0, 0.1;
    double R = 0.1;
    
    Matrix2d P; P << 0, 0,  //random initialization
                    0, 0;
    
    //system parameters
    Matrix2d A; A << 1, T,
                    0, 1;
    Vector2d B(0, T);
    RowVector2d C(1, 0);

    Vector2d x_predicted(p, p_dot);   //predicted states 

    Vector2d x_estimated(0, 0);   //estimated states

    RowVector2d u(5, 7);    //system input with random initialization

    VectorXd y;   
    y = C * x_estimated;
   
    //predict
    x_predicted = A * x_estimated + p_double_dot* B;
    P = A * P * A.transpose() + Q;
    
    //update
    MatrixXd K;
    K = P * C.transpose() / (C * P * C.transpose() + R);

    x_estimated = x_predicted + K*(y - C*x_predicted);

    #P = (1 - K*C) * P;
}   