/** Rcpp exported function */

#include <Rcpp.h>
#include "wsif97tp.h"

using namespace Rcpp;

//' @title Speed of sound vs temperature and pressure
//'
//' @description
//'   Calculate \emph{speed of sound} as a function of \emph{temperature} and
//'   \emph{pressure} in accordance with \emph{IAPWS R7-97} formulation.
//'
//' @family properties in temperature-pressure space
//'
//' @details
//'   Vectors \code{T} and \code{p} both must have the same length. Default
//'   \href{https://cran.r-project.org/doc/manuals/r-release/R-intro.html#Vector-arithmetic}{recycling rules}
//'   are not applicable in this context.
//'
//'   The accuracy of calculation for this property in \emph{Region 3} depends
//'   on accuracy of \emph{specific volume} in this region. See details for
//'   \code{\link{tpv}}.
//'
//' @param T
//'   absolute temperature in validity range 273.15 -- 2273.15, [\emph{K}].
//'   Type: \code{NumericVector}
//' @param p
//'   absolute pressure in validity range 0 -- 100 \emph{MPa}, [\emph{MPa}].
//'   Type: \code{NumericVector}
//' @return
//'   speed of sound, [\eqn{m/s}], or the next error code:
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
//'  t <- c(300,300,500,300,700,700,1500,1500,2000,0)  # [K]
//'  p <- c(3,80,3,.35e-2,.35e-2,30,.5,30,30,0)  # [MPa]
//'  tpw(t, p)
//'
//' @export
//[[Rcpp::export]]
std::vector<double> tpw(const std::vector<double> T, const std::vector<double> p)
{
    const unsigned long N = T.size();
    if (N != p.size()) stop("Arguments must be of the same length");
    std::vector<double> y;
    y.reserve(N);
    for (unsigned long i = 0; i < N; ++i) y.push_back(r797tp::wTp(T[i], p[i]));
    return y;
}
