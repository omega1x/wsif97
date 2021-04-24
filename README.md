[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) ![GitHub R package version](https://img.shields.io/github/r-package/v/omega1x/wsif97) [![CRAN_Status_Badge](https://www.r-pkg.org/badges/version/wsif97)](https://cran.r-project.org/package=wsif97) [![CodeFactor](https://www.codefactor.io/repository/github/omega1x/wsif97/badge)](https://www.codefactor.io/repository/github/omega1x/wsif97) ![R-CMD-check](https://github.com/omega1x/wsif97/workflows/R-CMD-check/badge.svg) [![Build Status](https://travis-ci.com/omega1x/wsif97.svg?branch=master)](https://travis-ci.com/omega1x/wsif97) [![Codecov test coverage](https://codecov.io/gh/omega1x/wsif97/branch/master/graph/badge.svg)](https://codecov.io/gh/omega1x/wsif97?branch=master)

[R-package](https://cran.r-project.org/package=wsif97) for fast calculation of thermophysical properties of water and steam as formulated by *International Association for the Properties of Water and Steam* ([IAPWS](http://iapws.org)).

------------------------------------------------------------------------

# Intro

The package is inspired by [Java IF97](https://www.if97.software/) library and *python's* [iapws](https://iapws.readthedocs.io/en/latest/index.html) module and tries to bring similar functionality to *R-community* without unwanted external dependencies. At present the package grows in functionality smoothly as needed in conjunction with analytic requirements of the author's company.

# Installation

For the stable release just install the latest version from [CRAN](https://cran.r-project.org/package=wsif97) (if any):

```r
install.packages("wsif97")
```
For the development version, you may use [devtools](https://cran.r-project.org/package=devtools):

```r
devtools::install_github("omega1x/wsif97")
```

> NOTE! The package is linked to and imports [Rcpp](https://cran.r-project.org/package=Rcpp)-package as the only dependency.

# Usage

The usage of [wsif97](https://github.com/omega1x/wsif97) package is rather straightforward. Most of thermophysical properties are calculated by *direct* vectorized functions of appropriate arguments:

``` r
## Calculate density (kg/m^3) of ordinary water at different temperatures
## and pressures:
> t <- c(300,500,300,700,1500,1500,2000)  # [K]
> p <- c(3,3,.35e-2,30,.5,30,30)        # [MPa]
> density <- tpr(t, p)                  # [kg/m^3]
> print(density)
[1] 997.85294010 831.65754105   0.02532198 184.18016876   0.72225586  43.33482271
[7]  32.11456228
```

For the present time the next thermophysical properties can be calculated.

| Property                           | Designation  | Units |(*T-p*)-space|
|------------------------------------|--------------|-------|-------------|
|Temperature                         |*T*           |K      | -           | 
|Pressure                            |*p*           |Mpa    | -           |
|Specific volume                     |*v*           |m³/kg  |`tpv`        |
|Specific internal energy            |*u*           |kJ/kg  |`tpu`        |
|Specific entropy                    |*s*           |kJ/kg/K|`tps`        |
|Specific enthalpy                   |*h*           |kJ/kg  |`tph`        |
|Specific isobaric heat capacity     |*c<sub>p*     |kJ/kg/K|`tpcp`       |
|Specific isohoric heat capacity     |*c<sub>v*     |kJ/kg/K|`tpcv`       |
|Speed of sound                      |*w*           |m/s    |`tpw`        |
|Isobaric cubic expansion coefficient|*&#945;<sub>v*|1/K    |`tpe`        |
|Isothermal compressibility          |*K<sub>T*     |1/MPa  |`tpi`        |
|Mass density                        |*&#961;*      |kg/m³  |`tpr`        |

Since [Industrial Formulation](http://iapws.org/relguide/IF97-Rev.html) abandons usage of iteration algorithms we similarly avoid using them in contrast to *pythonic* [iapws](https://iapws.readthedocs.io/en/latest/index.html). So be ready to meet some inconsistencies when compare results with [wsif97](https://github.com/omega1x/wsif97).
