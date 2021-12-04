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
#include <math.h>
#include <testthat.h>
#include "wsif97linetp.h"

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
context("IAPWS R7-97(2012). Verification of 2-3 region boundary") {
  // The format for specifying tests is similar to that of
  // testthat's R functions. Use 'test_that()' to define a
  // unit test, and use 'expect_true()' and 'expect_false()'
  // to test the desired conditions.
  constexpr double EPS6 {1e-6};

  test_that("*r797b23::pT* fails on computer-program verification with IAPWS R7-97(2012)") {
    expect_true(abs(r797b23::pT(623.15) - 16.5291643) < EPS6);
  }

  test_that("*r797b23::Tp* fails on computer-program verification with IAPWS R7-97(2012)") {
    expect_true(abs(r797b23::Tp(16.5291643) - 623.15) < EPS6);
  }
}

context("IAPWS R7-97(2012). Verification of saturation line") {
  constexpr double EPS6 {1e-6};

  test_that("*r797satline::pT* fails on computer-program verification with IAPWS R7-97(2012) at 300 K") {
    expect_true(abs(r797satline::pT(300) - .353658941e-2) < EPS6);
  }

  test_that("*r797satline::pT* fails on computer-program verification with IAPWS R7-97(2012) at 500 K") {
    expect_true(abs(r797satline::pT(500) - 2.63889776) < EPS6);
  }

  test_that("*r797satline::pT* fails on computer-program verification with IAPWS R7-97(2012) at 600 K") {
    expect_true(abs(r797satline::pT(600) - 12.3443146) < EPS6);
  }


  test_that("*r797satline::Tp* fails on computer-program verification with IAPWS R7-97(2012) at 0.1 MPa") {
    expect_true(abs(r797satline::Tp(.1) - 372.755919) < EPS6);
  }

  test_that("*r797satline::Tp* fails on computer-program verification with IAPWS R7-97(2012) at 1 MPa") {
    expect_true(abs(r797satline::Tp(1) - 453.035632) < EPS6);
  }

  test_that("*r797satline::Tp* fails on computer-program verification with IAPWS R7-97(2012) at 10 MPa") {
    expect_true(abs(r797satline::Tp(10) - 584.149488) < EPS6);
  }
}
