#include <benchmark/benchmark.h>
#include <fmt/core.h>

#include <cstdlib>
#include <magic_enum.hpp>

enum class Status {
  ORDERED,
  PROCESSING,
  READY,
  DELIVERED,
  ARRIVED,
  kSize,
};

enum class HTTPStatus {
  CONTINUE,
  SWITCHING_PROTOCOLS,
  PROCESSING,
  EARLY_HINTS,
  OK,
  CREATED,
  ACCEPTED,
  NON_AUTHORITATIVE_INFORMATION,
  NO_CONTENT,
  RESET_CONTENT,
  PARTIAL_CONTENT,
  MULTI_STATUS,
  ALREADY_REPORTED,
  IM_USED,
  MULTIPLE_CHOICES,
  MOVED_PERMANENTLY,
  FOUND,
  SEE_OTHER,
  NOT_MODIFIED,
  USE_PROXY,
  TEMPORARY_REDIRECT,
  PERMANENT_REDIRECT,
  BAD_REQUEST,
  UNAUTHORIZED,
  PAYMENT_REQUIRED,
  FORBIDDEN,
  NOT_FOUND,
  METHOD_NOT_ALLOWED,
  NOT_ACCEPTABLE,
  PROXY_AUTHENTICATION_REQUIRED,
  REQUEST_TIMEOUT,
  CONFLICT,
  GONE,
  LENGTH_REQUIRED,
  PRECONDITION_FAILED,
  REQUEST_ENTITY_TOO_LARGE,
  REQUEST_URI_TOO_LONG,
  UNSUPPORTED_MEDIA_TYPE,
  REQUESTED_RANGE_NOT_SATISFIABLE,
  EXPECTATION_FAILED,
  kSize,
};

static void small_by_magic_enum(benchmark::State& state) {
  for (auto _ : state) {
    const auto status =
        static_cast<Status>(std::rand() % static_cast<int>(Status::kSize));
    auto sv = magic_enum::enum_name(status);
    auto s = fmt::format("log some enum: {:s}", sv);
  }
}
static void small_pure_int(benchmark::State& state) {
  for (auto _ : state) {
    const auto status =
        static_cast<Status>(std::rand() % static_cast<int>(Status::kSize));
    auto i = static_cast<int>(status);
    auto s = fmt::format("log some enum: {:d}", i);
  }
}
static void large_by_magic_enum(benchmark::State& state) {
  for (auto _ : state) {
    const auto status = static_cast<HTTPStatus>(
        std::rand() % static_cast<int>(HTTPStatus::kSize));
    auto sv = magic_enum::enum_name(status);
    auto s = fmt::format("log some enum: {:s}", sv);
  }
}
static void large_by_int(benchmark::State& state) {
  for (auto _ : state) {
    const auto status = static_cast<HTTPStatus>(
        std::rand() % static_cast<int>(HTTPStatus::kSize));
    auto i = static_cast<int>(status);
    auto s = fmt::format("log some enum: {:d}", i);
  }
}

BENCHMARK(small_by_magic_enum);
BENCHMARK(small_pure_int);
BENCHMARK(large_by_magic_enum);
BENCHMARK(large_by_int);

BENCHMARK_MAIN();
