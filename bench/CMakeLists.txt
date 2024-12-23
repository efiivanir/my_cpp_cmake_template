# include(Benchmark)

add_executable("main_bench" "main_bench.cpp")
target_link_libraries("main_bench" benchmark::benchmark)
