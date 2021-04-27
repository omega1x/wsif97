/*
 * This file uses the Catch unit testing library, alongside
 * testthat's simple bindings, to test a C++ function.
 *
 * For your own packages, ensure that your test files are
 * placed within the `src/` folder, and that you include
 * `LinkingTo: testthat` within your DESCRIPTION file.
 */

// All test files should include the <testthat.h>
// header file.
#include <cmath>
#include <testthat.h>
#include "wsif97tp.h"

// Normally this would be a function from your package's
// compiled library -- you might instead just include a header
// file providing the definition, and let R CMD INSTALL
// handle building and linking.
//int twoPlusTwo() {
//  return 2 + 2;
//}

// Initialize a unit test context. This is similar to how you
// might begin an R test file with 'context()', expect the
// associated context should be wrapped in braced.
context("IAPWS SR5-05(2016). Verification of subregion boundary equations") {
  // The format for specifying tests is similar to that of
  // testthat's R functions. Use 'test_that()' to define a
  // unit test, and use 'expect_true()' and 'expect_false()'
  // to test the desired conditions.
  constexpr double EPS7 {1e-7};

  test_that("*sr505tp3::T3ab* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3ab(40) - 693.0341408) < EPS7);
  }

  test_that("*sr505tp3::T3cd* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3cd(25) - 649.3659208) < EPS7);
  }

  test_that("*sr505tp3::T3ef* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3ef(40) - 713.9593992) < EPS7);
  }

  test_that("*sr505tp3::T3gh* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3gh(23) - 649.8873759) < EPS7);
  }

  test_that("*sr505tp3::T3ij* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3ij(23) - 651.5778091) < EPS7);
  }

  test_that("*sr505tp3::T3jk* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3jk(23) - 655.8338344) < EPS7);
  }

  test_that("*sr505tp3::T3mn* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3mn(22.8) - 649.6054133) < EPS7);
  }

  test_that("*sr505tp3::T3op* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3op(22.8) - 650.0106943) < EPS7);
  }

  test_that("*sr505tp3::T3qu* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3qu(22) - 645.6355027) < EPS7);
  }

  test_that("*sr505tp3::T3rx* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3rx(22) - 648.2622754) < EPS7);
  }

  test_that("*sr505tp3::T3uv* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3uv(22.3) - 647.7996121) < EPS7);
  }

  test_that("*sr505tp3::T3wx* fails on computer-program verification with IAPWS SR5-05(2016)") {
    expect_true(abs(sr505tp3::T3wx(22.3) - 648.2049480) < EPS7);
  }
}

context("IAPWS SR5-05(2016). Verification of standalone subregion functions") {
  constexpr double verift[52][4] {
  ///id  p [MPa]  T [K]   v [m³/kg]e3
    { 0, 50.000, 630.00, 1.470853100},  ///a
    { 0, 80.000, 670.00, 1.503831359},  ///a
    { 1, 50.000, 710.00, 2.204728587},  ///b
    { 1, 80.000, 750.00, 1.973692940},  ///b
    { 2, 20.000, 630.00, 1.761696406},  ///c
    { 2, 30.000, 650.00, 1.819560617},  ///c
    { 3, 26.000, 656.00, 2.245587720},  ///d
    { 3, 30.000, 670.00, 2.506897702},  ///d
    { 4, 26.000, 661.00, 2.970225962},  ///e
    { 4, 30.000, 675.00, 3.004627086},  ///e
    { 5, 26.000, 671.00, 5.019029401},  ///f
    { 5, 30.000, 690.00, 4.656470142},  ///f
    { 6, 23.600, 649.00, 2.163198378},  ///g
    { 6, 24.000, 650.00, 2.166044161},  ///g
    { 7, 23.600, 652.00, 2.651081407},  ///h
    { 7, 24.000, 654.00, 2.967802335},  ///h
    { 8, 23.600, 653.00, 3.273916816},  ///i
    { 8, 24.000, 655.00, 3.550329864},  ///i
    { 9, 23.500, 655.00, 4.545001142},  ///j
    { 9, 24.000, 660.00, 5.100267704},  ///j
    {10, 23.000, 660.00, 6.109525997},  ///k
    {10, 24.000, 670.00, 6.427325645},  ///k
    {11, 22.600, 646.00, 2.117860851},  ///l
    {11, 23.000, 646.00, 2.062374674},  ///l
    {12, 22.600, 648.60, 2.533063780},  ///m
    {12, 22.800, 649.30, 2.572971781},  ///m
    {13, 22.600, 649.00, 2.923432711},  ///n
    {13, 22.800, 649.70, 2.913311494},  ///n
    {14, 22.600, 649.10, 3.131208996},  ///o
    {14, 22.800, 649.90, 3.221160278},  ///o
    {15, 22.600, 649.40, 3.715596186},  ///p
    {15, 22.800, 650.20, 3.664754790},  ///p
    {16, 21.100, 640.00, 1.970999272},  ///q
    {16, 21.800, 643.00, 2.043919161},  ///q
    {17, 21.100, 644.00, 5.251009921},  ///r
    {17, 21.800, 648.00, 5.256844741},  ///r
    {18, 19.100, 635.00, 1.932829079},  ///s
    {18, 20.000, 638.00, 1.985387227},  ///s
    {19, 17.000, 626.00, 8.483262001},  ///t
    {19, 20.000, 640.00, 6.227528101},  ///t
    {20, 21.500, 644.60, 2.268366647},  ///u
    {20, 22.000, 646.10, 2.296350553},  ///u
    {21, 22.500, 648.60, 2.832373260},  ///v
    {21, 22.300, 647.90, 2.811424405},  ///v
    {22, 22.150, 647.50, 3.694032281},  ///w
    {22, 22.300, 648.10, 3.622226305},  ///w
    {23, 22.110, 648.00, 4.528072649},  ///x
    {23, 22.300, 649.00, 4.556905799},  ///x
    {24, 22.000, 646.84, 2.698354719},  ///y
    {24, 22.064, 647.05, 2.717655648},  ///y
    {25, 22.000, 646.89, 3.798732962},  ///z
    {25, 22.064, 647.15, 3.701940010},  ///z
  };

  test_that("*sr505tp3::v3Tpid* on computer-program verification with IAPWS SR5-05(2016)") {
    for (int i = 0; i < 52; i++)
       expect_true(abs(sr505tp3::v3Tpid(
             verift[i][2], verift[i][1], (int) verift[i][0]
       )*1e3 - verift[i][3]) < 1e-9);
  }

  test_that("*sr505tp3::v3Tp* on computer-program verification with IAPWS SR5-05(2016)") {
    for (int i = 0; i < 52; i++)
      expect_true(abs(sr505tp3::v3Tp(verift[i][2], verift[i][1])*1e3 - verift[i][3]) < 1e-9);
  }
}
