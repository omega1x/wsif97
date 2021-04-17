/**  Functions for describing saturation line between water and steam (region 4)
 *   Measurement units:
 *      - [T] = K
 *      - [p] = MPa
 */

#include <math.h>

namespace r797satline
{

double pT(double T)
{
    const double n[11] = {0,
         0.11670521452767e4, -0.72421316703206e6, -0.17073846940092e2,
         0.12020824702470e5, -0.32325550322333e7,  0.14915108613530e2,
        -0.48232657361591e4,  0.40511340542057e6, -0.23855557567849,
         0.65017534844798e3
    };
    const double t = T + n[9]/(T - n[10]);
    const double tsq = t * t;
    const double A = tsq + n[1] * t + n[2];
    const double B = n[3] * tsq + n[4] * t + n[5];
    const double C = n[6] * tsq + n[7] * t + n[8];
    return pow(2 * C / (-B + sqrt(B * B - 4 * A * C)), 4);
}

double Tp(double p)
{
    const int N = 11;
    const double n[N] = {0,
        0.11670521452767e4, -0.72421316703206e6, -0.17073846940092e2,
        0.12020824702470e5, -0.32325550322333e7,  0.14915108613530e2,
       -0.48232657361591e4,  0.40511340542057e6, -0.23855557567849  ,
        0.65017534844798e3
    };
    const double beta = pow(p, 0.25);
    const double E = beta * beta + n[3] * beta + n[6];
    const double F = n[1] * beta * beta + n[4] * beta + n[7];
    const double G = n[2] * beta * beta + n[5] * beta + n[8];
    const double D = 2 * G/(-F - sqrt(F * F - 4 * E * G));
    return (n[10] + D - sqrt(pow(n[10] + D, 2) - 4 * (n[9] +n[10] *D)))/2;
}

}
