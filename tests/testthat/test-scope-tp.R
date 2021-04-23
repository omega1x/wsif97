# Regions:   1                  2                  5
scope_t <- c(273, 273, 273, 1075, 1075, 2275, 2275)  # [K]
scope_p <- c(120,  50,   0,  120,    0,   25,   90)  # [MPa]

test_that(
  "*tpv* fails out of scope",
  {
    expect_equal(tpv(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpu* fails out of scope",
  {
    expect_equal(tpu(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tps* fails out of scope",
  {
    expect_equal(tps(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tph* fails out of scope",
  {
    expect_equal(tph(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpcp* fails out of scope",
  {
    expect_equal(tpcp(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpcv* fails out of scope",
  {
    expect_equal(tpcv(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpw* fails out of scope",
  {
    expect_equal(tpw(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpe* fails out of scope",
  {
    expect_equal(tpe(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpi* fails out of scope",
  {
    expect_equal(tpi(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)

test_that(
  "*tpr* fails out of scope",
  {
    expect_equal(tpr(scope_t, scope_p), rep(-10, length(scope_t)))
  }
)
rm(scope_p, scope_t)
