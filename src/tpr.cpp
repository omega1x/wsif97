/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"

using namespace std;
using namespace Rcpp;

//' @title Mass density vs temperature and pressure
//'
//' @description
//'   Calculate \emph{mass density} as a function of \emph{temperature} and
//'   \emph{pressure} in accordance with \emph{IAPWS R7-97} formulation.
//'
//' @family temperature-pressure space
//'
//' @details
//'   Vectors \code{T} and \code{p} both must have the same length. Default
//'   \href{https://cran.r-project.org/doc/manuals/r-release/R-intro.html#Vector-arithmetic}{recycling rules}
//'   are not applicable in this context.
//'
//'   The accuracy of this property is
//'   In current version numerical consistency of the specific volume
//'   in \emph{Region 3} of \emph{IAPWS R7-97} is considered sufficient enough
//'   for most applications. That is why no additional iteration procedures are
//'   used for reaching higher accuracy in this region.
//'
//' @param T
//'   absolute temperature in validity range 273.15 -- 2273.15, [\emph{K}].
//'   Type: \code{NumericVector}
//' @param p
//'   absolute pressure in validity range 0 -- 100 \emph{MPa}, [\emph{MPa}].
//'   Type: \code{NumericVector}
//' @return
//'   specific volume, [\eqn{m^3/kg}], or the next error code:
//'   \describe{
//'       \item{\code{-10}}{
//'         Fail to determine region in temperature-pressure space into which the
//'         entire range of validity of \emph{IAPWS R7-97}
//'         is divided. Possibly values of one or both arguments are
//'         out of bounds or in undeterminable subspace.
//'       }
//'       \item{\code{-20}}{
//'         Fail to determine subregion inside \emph{Region 3} in accordance
//'         with \emph{IAPWS SR5-05}. Possibly values of one or both arguments
//'         are in undeterminable subspace or near singularity.
//'       }
//'   }
//'   Type: \code{NumericVector}
//'
//' @references
//'  \itemize{
//'   \item \href{http://www.iapws.org/relguide/IF97-Rev.pdf}{IAPWS R7-97 (2012)},
//'   \emph{Revised Release on the IAPWS Industrial Formulation 1997 for the
//'   Thermodynamic Properties of Water and Steam}. August 2007.
//'
//'   \item \href{http://www.iapws.org/relguide/Supp-VPT3-2016.pdf}{IAPWS SR5-05 (2016)},
//'   \emph{Revised Supplementary Release on Backward Equations for Specific
//'   Volume as a Function of Pressure and Temperature v(p,T) for Region 3 of the
//'   IAPWS Industrial Formulation 1997 for the Thermodynamic Properties of Water and
//'   Steam}. June 2014.
//'  }
//'
//' @examples
//'  t <- c(300,300,500,300,700,700,1500,1500,2000)  # [K]
//'  p <- c(3,80,3,.35e-2,.35e-2,30,.5,30,30)  # [MPa]
//'  tpv(t, p)
//'
//' @export
//[[Rcpp::export]]
NumericVector tpv(NumericVector T, NumericVector p)
{
    if (T.size() != p.size()) stop("Arguments must be of the same length");
    NumericVector y = T;
    const int n = y.size();
    for (int i = 0; i < n; i++) y[i] = r797tp::vTp(T[i], p[i]);
    return y;
}
