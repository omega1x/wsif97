/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"

using namespace std;
using namespace Rcpp;

//' Specific internal energy vs temperature and pressure
//'
//' @param T
//'   absolute temperature, [\emph{K}]
//' @param p
//'   absolute pressure, [\emph{MPa}]
//' @return
//'   specific internal energy, [\eqn{kJ/kg}]
//' @export
//[[Rcpp::export]]
NumericVector tpu(NumericVector T, NumericVector p)
{
    NumericVector y = 0*T;
    int n = y.size();

    for(int i = 0; i < n; i++){
        // if first region:
        y[i] = r797tp1::u1Tp(T[i], p[i]);
        // if second region:
        y[i] = r797tp2::u2Tp(T[i], p[i]);
        // if metastable region:
        y[i] = r797tp2metastable::u2msTp(T[i], p[i]);
        // if fifth region:
        y[i] = r797tp5::u5Tp(T[i], p[i]);
    }
    return y;
}
