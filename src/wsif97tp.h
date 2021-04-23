/**  Mini-library of properties of water and steam as functions of
  *  temperature and pressure in accordance with IAPWS formulation
  *  Reference:
  *     - IAPWS R7-97(2012)  <http://www.iapws.org/relguide/IF97-Rev.pdf>
  *     - IAPWS SR5-05(2016) <http://www.iapws.org/relguide/Supp-VPT3-2016.pdf>
  *     - iapws <doi:10.5281/zenodo.3734292>
  *  Argument units:
  *     - [T] = K
  *     - [p] = MPa
  *  Properties:
  *     - v  - specific volume, m³/kg
  *     - u  - specific internal energy, kJ/kg
  *     - s  - specific entropy, kJ/kg/K
  *     - h  - specific enthalpy, kJ/kg
  *     - cp - specific isobaric heat capacity, kJ/kg/K
  *     - cv - specific isohoric heat capacity, kJ/kg/K
  *     - w  - speed of sound, m/s
  *     - e  - cubic expansion coefficient, 1/K
  *     - i  - isothermal compressibility, 1/MPa
  **/

#ifndef WSIF97TP_H
#define WSIF97TP_H


/*
namespace r797tp1
{
    double v1Tp(double T,  double p) ;
    double u1Tp(double T,  double p) ;
    double s1Tp(double T,  double p) ;
    double h1Tp(double T,  double p) ;
    double cp1Tp(double T, double p) ;
    double cv1Tp(double T, double p) ;
    double w1Tp(double T, double p)  ;
    double e1Tp(double T, double p)  ;
    double i1Tp(double T, double p)  ;
}

namespace r797tp2
{
    double v2Tp(double T, double p)  ;
    double u2Tp(double T, double p)  ;
    double s2Tp(double T, double p)  ;
    double h2Tp(double T, double p)  ;
    double cp2Tp(double T, double p) ;
    double cv2Tp(double T, double p) ;
    double w2Tp(double T, double p)  ;
    double e2Tp(double T, double p)  ;
    double i2Tp(double T, double p)  ;
}

namespace r797tp2metastable
{
    double v2msTp(double T, double p)  ;
    double u2msTp(double T, double p)  ;
    double s2msTp(double T, double p)  ;
    double h2msTp(double T, double p)  ;
    double cp2msTp(double T, double p) ;
    double cv2msTp(double T, double p) ;
    double w2msTp(double T, double p)  ;
    double e2msTp(double T, double p)  ;
    double i2msTp(double T, double p)  ;
}

namespace sr505tp3
{
    double v3Tp(double T, double p) ;
    double u3Tp(double T, double p) ;
    double s3Tp(double T, double p) ;
    double h3Tp(double T, double p) ;
    double cp3Tp(double T, double p);
    double cv3Tp(double T, double p);
    double w3Tp(double T, double p) ;
    double e3Tp(double T, double p) ;
    double i3Tp(double T, double p) ;
}

namespace r797tp5
{
    double v5Tp(double T, double p)  ;
    double u5Tp(double T, double p)  ;
    double s5Tp(double T, double p)  ;
    double h5Tp(double T, double p)  ;
    double cp5Tp(double T, double p) ;
    double cv5Tp(double T, double p) ;
    double w5Tp(double T, double p)  ;
    double e5Tp(double T, double p)  ;
    double i5Tp(double T, double p)  ;
}

*/

namespace r797tp
{
    double vTp(double T, double p)  ;  /// specific volume, [m³/kg]
    double uTp(double T, double p)  ;  /// specific internal energy, [kJ/kg]
    double sTp(double T, double p)  ;  /// specific entropy, [kJ/kg/K]
    double hTp(double T, double p)  ;  /// specific enthalpy, [kJ/kg]
    double cpTp(double T, double p) ;  /// specific isobaric heat capacity, [kJ/kg/K]
    double cvTp(double T, double p) ;  /// specific isochoric heat capacity, [kJ/kg/K]
    double wTp(double T, double p)  ;  /// speed of sound, [m/s]
    double eTp(double T, double p)  ;  /// cubic expansion coefficient, [1/K]
    double iTp(double T, double p)  ;  /// isothermal compressibility, [1/MPa]

    double rTp(double T, double p)  ;  /// mass density, [kg/m³]
}

#endif
