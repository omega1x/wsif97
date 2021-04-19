/**  Functions for describing lines:
 *   - saturation line between water and steam (region 4)
 *   - line between regions 2 and 3
 *  Reference:
 *     - IAPWS R7-97(2012)  <http://www.iapws.org/relguide/IF97-Rev.pdf>
  * Units:
 *     - [T] = K
 *     - [p] = MPa
 */

#ifndef WSIF97SATLINE_H
#define WSIF97SATLINE_H

namespace r797satline
{
    double pT(double T);
    double Tp(double p);
}

namespace r797b23
{
    double pT(double T);
    double Tp(double p);
}

# endif
