/**  Mini-library of properties of water and steam as functions of
  *  temperature and mass density in accordance with IAPWS formulation
  *  Reference:
  *     - IAPWS R7-97(2012)  <http://www.iapws.org/relguide/IF97-Rev.pdf>
  *  Units:
  *      - [T] = K
  *      - [rho] = kg/m^3
  */

#ifndef WSIF97TR_H
#define WSIF97TR_H

namespace r797tr3
{
    double p3Tr(double T, double r) ;
    double u3Tr(double T, double r) ;
    double s3Tr(double T, double r) ;
    double h3Tr(double T, double r) ;
    double cv3Tr(double T, double r);
    double cp3Tr(double T, double r);
    double w3Tr(double T, double r) ;
}
#endif
