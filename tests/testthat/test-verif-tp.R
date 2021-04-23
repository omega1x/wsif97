# Regions:   1                  2                  5
if97t <- c(300, 300, 500,   300,   700,  700,   1500, 1500, 2000)  # [K]
if97p <- c(  3,  80,   3,   0.0035,0.0035,30,   0.5,   30,    30)  # [MPa]

test_that(
  "*tpv* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    v <- c(
      1.00215168e-03, 9.71180894e-04, 1.20241800e-03,
      3.94913866e+01, 9.23015898e+01, 5.42946619e-03,
      1.38455090e+00, 2.30761299e-02, 3.11385219e-02
    )
    expect_equal(tpv(if97t, if97p), v)
    rm(v)
  }
)


test_that(
    "*tpu* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
    {
      u <- c(
        .112324818e3, .106448356e3, .971934985e3,
        .241169160e4, .301262819e4, .246861076e4,
        .452749310e4, .447495124e4, .563707038e4
      )
      expect_equal(tpu(if97t, if97p), u)
      rm(u)
    }
)

test_that(
  "*tps* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    s <- c(
      .392294792  ,.368563852  ,.258041912e1,
      .852238967e1,.101749996e2,.517540298e1,
      .965408875e1,.772970133e1,.853640523e1
    )
    expect_equal(tps(if97t, if97p), s)
    rm(s)
  }
)

test_that(
  "*tph* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    h <- c(
      .115331273e3,.184142828e3,.975542239e3,
      .254991145e4,.333568375e4,.263149474e4,
      .521976855e4,.516723514e4,.657122604e4
    )
    expect_equal(tph(if97t, if97p), h)
    rm(h)
  }
)

test_that(
  "*tpcp* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    cp <- c(
      .417301218e1,.401008987e1,.465580682e1,
      .191300162e1,.208141274e1,.103505092e2,
      .261609445e1,.272724317e1,.288569882e1
    )
    expect_equal(tpcp(if97t, if97p), cp)
    rm(cp)
  }
)

test_that(
  "*tpcv* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    cv <- c(
      4.121201603587438,  3.9173660618448736, 3.2213922290283015,
      1.4413266189747822, 1.619783325600298 , 2.97553836890886,
      2.1533778352104127, 2.1927482936648652, 2.3958943623580446
    )
    expect_equal(tpcv(if97t, if97p), cv)
    rm(cv)
  }
)

test_that(
  "*tpw* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    w <- c(
      .150773921e4,.163469054e4,.124071337e4,
      .427920172e3,.644289068e3,.480386523e3,
      .917068690e3,.928548002e3,.106736948e4
    )
    expect_equal(tpw(if97t, if97p), w)
    rm(w)
  }
)

test_that(
  "*tpe* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    e <- c(
      .00027735453342661365,.00034409584308888705,.0016411812807641884,
      .0033757828943612863 ,.001428787358438332  ,.012601968775873438,
      .0006675389998334917 ,.0007169507536003152 ,.0005088306412790769
    )
    expect_equal(tpe(if97t, if97p), e)
    rm(e)
  }
)

test_that(
  "*tpi* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    i <- c(
         .0004463821228021935,   .0003720394372317089,.0011289218770058733,
      286.23965139           ,285.72546117           ,.08184114,
        2.0000385868728405,      .03328812532599134  ,.03291938922687314
    )
    expect_equal(tpi(if97t, if97p), i)
    rm(i)
  }
)

test_that(
  "*tpr* fails on computer-program verification with IAPWS-97 in regions 1, 2, 5",
  {
    r <- 1/c(
      1.00215168e-03, 9.71180894e-04, 1.20241800e-03,
      3.94913866e+01, 9.23015898e+01, 5.42946619e-03,
      1.38455090e+00, 2.30761299e-02, 3.11385219e-02
    )
    expect_equal(tpr(if97t, if97p), r)
  }
)
