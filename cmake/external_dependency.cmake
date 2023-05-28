include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        a33701196adfad74917046096bf5a2aa0ab0bb50 # 9.1
  GIT_SHALLOW    TRUE
)
FetchContent_Declare(
  range-v3
  GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
  GIT_SHALLOW    TRUE
  GIT_TAG        a81477931a8aa2ad025c6bda0609f38e09e4d7ec # 0.12
)
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_SHALLOW    TRUE
  GIT_TAG        0817715923c9705e68994eb52ef9df3f6845beba #1.10.0
)
FetchContent_Declare(
  magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_SHALLOW    TRUE
  GIT_TAG        v0.9.0
)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_SHALLOW    TRUE
  GIT_TAG        v1.8.0
)

option(BENCHMARK_ENABLE_TESTING "." OFF)
option(BENCHMARK_ENABLE_GTEST_TESTS "." OFF)
option(BENCHMARK_USE_BUNDLED_GTEST "." OFF)

FetchContent_MakeAvailable(
  benchmark
  cpr
  fmt 
  magic_enum
  range-v3
)
