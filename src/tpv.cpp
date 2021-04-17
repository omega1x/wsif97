/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"
#include "wsif97satline.h"
#include "wsif97tr.h"

using namespace std;
using namespace Rcpp;

//' Specific volume vs temperature and pressure
//'
//' @param T
//'   absolute temperature, [\emph{K}]
//' @param p
//'   absolute pressure, [\emph{MPa}]
//' @return
//'   specific volume, [\eqn{m^3/kg}]
//' @export
//[[Rcpp::export]]
NumericVector tpv(NumericVector T, NumericVector p)
{
    NumericVector y = 0*T;
    int n = y.size();

    for(int i = 0; i < n; i++){
        // if first region:
        //  y[i] = r797tp1::v1Tp(T[i], p[i]);
        // if second region:
          //y[i] = r797tp2::v2Tp(T[i], p[i]);
        // if metastable region:
          //y[i] = r797tp2metastable::v2msTp(T[i], p[i]);
        // if third region
        y[i] = sr505tp3::v3Tp(T[i], p[i]);

        // if fifth region:
        //y[i] = r797tp5::v5Tp(T[i], p[i]);
    }
    return y;
}


//[[Rcpp::export]]
double f(double T, double r){
      return r797tr3::cv3Tr(T, r);
}


