/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"

using namespace std;
using namespace Rcpp;

//' Speed of sound vs temperature and pressure
//'
//' @param T
//'   absolute temperature, [\emph{K}]
//' @param p
//'   absolute pressure, [\emph{MPa}]
//' @return
//'   Speed of sound, [\eqn{m/s}]
//' @export
//[[Rcpp::export]]
NumericVector tpw(NumericVector T, NumericVector p)
{
    NumericVector y = 0*T;
    int n = y.size();

    for(int i = 0; i < n; i++){
        // if first region:
        y[i] = r797tp1::w1Tp(T[i], p[i]);
        // if second region:
        y[i] = r797tp2::w2Tp(T[i], p[i]);
        // if metastable region:
        y[i] = r797tp2metastable::w2msTp(T[i], p[i]);
        // if fifth region:
        y[i] = r797tp5::w5Tp(T[i], p[i]);

    }
    return y;
}
