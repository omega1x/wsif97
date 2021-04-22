# Regions:   1                  2                  5
test_that(
  "*tpv* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    t <- c(300, 300, 500,   300,   700,  700,   1500, 1500, 2000)  # [K]
    p <- c(  3,  80,   3,   0.0035,0.0035,30,   0.5,   30,    30)  # [MPa]
    v <- c(
      1.00215168e-03, 9.71180894e-04, 1.20241800e-03,
      3.94913866e+01, 9.23015898e+01, 5.42946619e-03,
      1.38455090e+00, 2.30761299e-02, 3.11385219e-02
    )
    expect_equal(tpv(t, p), v)
  }
)

test_that(
  "*tpv* fails out of scope",
  {
    t <- c(273, 273, 273, 1075, 1075, 2275, 2275)
    p <- c(120,  50,   0,  120,    0,   25,   90)
    expect_equal(tpv(t, p), rep(-10, length(t)))
  }
)

test_that(
  "*tpr* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    t <- c(300, 300, 500,   300,   700,  700,   1500, 1500, 2000)  # [K]
    p <- c(  3,  80,   3,   0.0035,0.0035,30,   0.5,   30,    30)  # [MPa]

    r <- 1/c(
      1.00215168e-03, 9.71180894e-04, 1.20241800e-03,
      3.94913866e+01, 9.23015898e+01, 5.42946619e-03,
      1.38455090e+00, 2.30761299e-02, 3.11385219e-02
    )
    expect_equal(tpr(t, p), r)
  }
)

test_that(
  "*tpr* fails out of scope",
  {
    t <- c(273, 273, 273, 1075, 1075, 2275, 2275)
    p <- c(120,  50,   0,  120,    0,   25,   90)
    expect_equal(tpr(t, p), rep(-10, length(t)))
  }
)

test_that(
    "*tpu* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
    {
      t <- c(300, 300, 500,   300,   700,  700,   1500, 1500, 2000)  # [K]
      p <- c(  3,  80,   3,   0.0035,0.0035,30,   0.5,   30,    30)  # [MPa]

      u <- c(
        .112324818e3, .106448356e3, .971934985e3,
        .241169160e4, .301262819e4, .246861076e4,
        .452749310e4, .447495124e4, .563707038e4
      )
      expect_equal(tpu(t, p), u)
    }
)


test_that(
    "*tpu* fails out of scope",
    {
      t <- c(273, 273, 273, 1075, 1075, 2275, 2275)
      p <- c(120,  50,   0,  120,    0,   25,   90)
      expect_equal(tpu(t, p), rep(-10, length(t)))
    }

)

