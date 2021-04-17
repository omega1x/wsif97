/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"

using namespace std;
using namespace Rcpp;

//' Specific entropy vs temperature and pressure
//'
//' @param T
//'   absolute temperature, [\emph{K}]
//' @param p
//'   absolute pressure, [\emph{MPa}]
//' @return
//'   specific entropy, [\eqn{kJ/kg/K}]
//' @export
//[[Rcpp::export]]
NumericVector tps(NumericVector T, NumericVector p)
{
    NumericVector y = 0*T;
    int n = y.size();

    for(int i = 0; i < n; i++){
        // if first region:
        y[i] = r797tp1::s1Tp(T[i], p[i]);
        // if second region:
        y[i] = r797tp2::s2Tp(T[i], p[i]);
        // if metastable region:
        y[i] = r797tp2metastable::s2msTp(T[i], p[i]);
        // if fifth region:
        y[i] = r797tp5::s5Tp(T[i], p[i]);
    }
    return y;
}
