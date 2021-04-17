/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"

using namespace std;
using namespace Rcpp;

//' Cubic expansion coefficient vs temperature and pressure
//'
//' @param T
//'   absolute temperature, [\emph{K}]
//' @param p
//'   absolute pressure, [\emph{MPa}]
//' @return
//'   cubic expansion coefficient, [\eqn{1/K}]
//' @export
//[[Rcpp::export]]
NumericVector tpe(NumericVector T, NumericVector p)
{
    NumericVector y = 0*T;
    int n = y.size();

    for(int i = 0; i < n; i++){
        // if first region:
        y[i] = r797tp1::e1Tp(T[i], p[i]);
        // if second region:
        y[i] = r797tp2::e2Tp(T[i], p[i]);
        // if metastable region:
        y[i] = r797tp2metastable::e2msTp(T[i], p[i]);
        // if fifth region:
        y[i] = r797tp5::e5Tp(T[i], p[i]);
    }
    return y;
}
