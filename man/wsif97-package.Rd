\name{wsif97-package}
\alias{wsif97-package}
\docType{package}
\title{
  Industrial Formulation for Properties of Ordinary Water and Steam
}
\description{
  Implementation of some methods for fast calculation of thermophysical
  properties of water and steam as they formulated by \emph{International
  Association for the Properties of Water and Steam}
  (\href{http://iapws.org}{IAPWS}).
}
\details{
  The package is inspired by \href{https://www.if97.software/}{Java IF97} library
  and \href{https://iapws.readthedocs.io/en/latest/index.html}{iapws}
  \emph{python}-module and tries to bring similar functionality to
  \strong{R-community} without unwanted external dependencies. The package
  grows in functionality smoothly as needed in conjunction with analytic
  requirements of the author's company.

  Unlike most others the package contains
  vectorized functions aimed for speed by using \code{\link{Rcpp-package}} and
  by avoiding double cycling. For actual information about the package
  see package \href{https://github.com/omega1x/wsif97/blob/master/README.md}{README.md}.
}
\author{
Yuri Possokhov, possokhoff@gmail.com.

Maintainer: Yuri Possokhov <possokhoff@gmail.com>
}
\references{
  \href{http://www.iapws.org/relguide/IF97-Rev.pdf}{IAPWS R7-97 (2012)},
  \emph{Revised Release on the IAPWS Industrial Formulation 1997 for the
  Thermodynamic Properties of Water and Steam}. August 2007.

  \href{http://www.iapws.org/relguide/Supp-VPT3-2016.pdf}{IAPWS SR5-05 (2016)},
  \emph{Revised Supplementary Release on Backward Equations for Specific
  Volume as a Function of Pressure and Temperature v(p,T) for Region 3 of the
  IAPWS Industrial Formulation 1997 for the Thermodynamic Properties of Water and
  Steam}. June 2014.

  \href{http://www.iapws.org/relguide/Advise5.pdf}{IAPWS AN5-13(2016)},
  Advisory Note No. 5: \emph{Industrial Calculation of the Thermodynamic
  Properties of Seawater}. September 2013.
}
\keyword{ water, steam, enthalpy, entropy, spead of sound, heat capacity, iapws }
\examples{
   ## Calculate density of ordinary water at different temperatures
   ## and pressures:
   t <- c(300,300,500,300,700,700,1500,1500,2000,0)  # [K]
   p <- c(3,80,3,.35e-2,.35e-2,30,.5,30,30,0)  # [MPa]
   density <- tpr(t, p)  # [kg/m^3]
   print(density)
}
