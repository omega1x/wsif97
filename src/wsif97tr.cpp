/**  Properties of water and steam as functions of *temperature* and *mass density*
  *  Measurement units of property arguments:
  *      - [T] = K
  *      - [rho] = kg/m^3
  */

#include <math.h>


/**  IAPWS R7-97(2012). Region 3 **/
namespace r797tr3
{
    const int N = 39;
    const int I[N] = {
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2,  2,  2,  2, 2, 3, 3, 3, 3, 3, 4,
        4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 10, 10, 11
    };
    const int J[N] = {
         0, 1,  2,  7, 10, 12, 23,  2, 6, 15, 17, 0, 2,  6, 7, 22, 26,  0,
         2, 4, 16, 26,  0,  2,  4, 26, 1,  3, 26, 0, 2, 26, 2, 26,  2, 26,
         0, 1, 26
    };
    const double n[N] = {
      -1.573284529023900e+01, 2.094439697430700e+01,-7.686770787871600e+00,
       2.618594778795400e+00,-2.808078114862000e+00, 1.205336969651700e+00,
      -8.456681281250201e-03,-1.265431547771400e+00,-1.152440780668100e+00,
       8.852104398431800e-01,-6.420776518160700e-01, 3.849346018667100e-01,
      -8.521470882420600e-01, 4.897228154187700e+00,-3.050261725696500e+00,
       3.942053687915400e-02, 1.255840842430800e-01,-2.799932969871000e-01,
       1.389979956946000e+00,-2.018991502357000e+00,-8.214763717396300e-03,
      -4.759603573492300e-01, 4.398407447350000e-02,-4.447643542873900e-01,
       9.057207071973300e-01, 7.052245008796700e-01, 1.077051262633200e-01,
      -3.291362325895400e-01,-5.087106204115800e-01,-2.217540087309600e-02,
       9.426075166509200e-02, 1.643627844796100e-01,-1.350337224134800e-02,
      -1.483434535247200e-02, 5.792295362808399e-04, 3.230890470371100e-03,
       8.096480299621501e-05,-1.655767979503700e-04,-4.492389906181500e-05
    };

    double phi(double delta, double tau)
    {
        double z = 1.0658070028513 * log(delta);
        for (int i = 0; i < N; i++)
            z += n[i] * pow(delta, I[i]) * pow(tau, J[i]);
        return z;
    }

    double phid(double delta, double tau)
    {
        double z = 1.0658070028513/delta;
        for (int i = 0; i < N; i++)
            z += n[i] * I[i] * pow(delta, I[i] - 1) * pow(tau, J[i]);
        return z;
    }

    double phidd(double delta, double tau)
    {
        double z = -1.0658070028513 * pow(delta, -2);
        for (int i = 0; i < N; i++)
            z += n[i] * I[i] * (I[i] - 1) * pow(delta, I[i] - 2) * pow(tau, J[i]);
        return z;
    }

    double phit(double delta, double tau)
    {
        double z = 0;
        for (int i = 0; i < N; i++)
            z += n[i] * J[i] * pow(delta, I[i]) * pow(tau, J[i] - 1);
        return z;
    }

    double phitt(double delta, double tau)
    {
        double z = 0;
        for (int i = 0; i < N; i++)
            z += n[i] * pow(delta, I[i]) * J[i] * (J[i] - 1) *  pow(tau, J[i] - 2);
        return z;
    }

   double phidt(double delta, double tau)
   {
     double z = 0;
     for (int i = 0; i < N; i++)
       z += n[i] * I[i] * pow(delta, I[i] - 1) * J[i] * pow(tau, J[i] - 1);
     return z;
   }

   /** Properties */
   const double Tc = 647.096;  /// [K]
   const double rc = 322;      /// [kg/m³]

   double p3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        return 0.461526e-3 * delta * phid(delta, tau) * T * r;
   }

   double u3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        return 0.461526 * T * tau * phit(delta, tau);
   }

   double s3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        return 0.461526 * (tau * phit(delta, tau) - phi(delta, tau));
   }

   double h3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        return 0.461526 * T * (tau * phit(delta, tau) + delta * phid(delta, tau));
   }

   double cv3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        return -0.461526 * tau * tau * phitt(delta, tau);
   }

   double cp3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        const double pd = phid(delta, tau);
        return 0.461526 * (
            -tau * tau * phitt(delta, tau) + delta * pow(
                pd - tau * phidt(delta, tau), 2
        )/(2 * pd + delta * phidd(delta, tau)));
   }

   double w3Tr(double T, double r)
   {
        const double delta = r/rc;
        const double tau = Tc/T;
        const double pd = phid(delta, tau);
        return sqrt(
            461.526 * T * (
                2 * delta * pd + delta * delta * phidd(delta, tau) - pow(
                    delta * pd - delta * tau * phidt(delta, tau), 2
                    )/(tau * tau * phitt(delta, tau))
            )
        );
   }

   double e3Tr(double T, double r)
   {
     /// cubic expansion coefficient
     /// test: c(0.00441515098)
     const double delta = r/rc;
     const double tau = Tc/T;
     const double e = (
             phid(delta, tau) - tau * phidt(delta, tau)
         )/(2 * phid(delta, tau) + delta * phidd(delta, tau))/T;  /// [1/K]
     return e;
   }

   double i3Tr(double T, double r)
   {
     /// isothermal compressibility
     /// test: c(0.00806710817)
     const double delta = r/rc;
     const double tau = Tc/T;
     const double i = 1e3/(
             2 * delta * phid(delta, tau) + delta * delta *phidd(delta, tau)
        )/r/0.461526/T;  /// [1/MPa]
     return i;
   }

}
