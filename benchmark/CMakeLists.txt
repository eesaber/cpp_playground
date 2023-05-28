add_executable(magic_enum_performance 
  magic_enum_performance.cpp
)

target_link_libraries(magic_enum_performance 
  PRIVATE
    benchmark::benchmark
    magic_enum::magic_enum
    fmt::fmt
)
