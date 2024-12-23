#include <benchmark/benchmark.h>

size_t SumOf3and5Until_1(size_t maxval) {
  size_t sum = 0;
  for(size_t i = 0; i < maxval; ++i) {
      sum += (i % 3 == 0 || i % 5 == 0) ? i : 0;
  }
  return sum;
}

static void BM_SumOf3and5Until_1(benchmark::State& state) {
    for (auto _ : state)
        SumOf3and5Until_1(state.range(0));
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_SumOf3and5Until_1)->Arg(100)->Arg(1000)->Arg(10000)->Complexity();

size_t SumOf3and5Until_2(size_t maxval) {
  auto gauss_sum=[](size_t n) { return n * (n+1) / 2;};
  --maxval;
  return gauss_sum(maxval / 3) * 3 +
  gauss_sum(maxval / 5) * 5 -
  gauss_sum(maxval / 15) * 15;
}

static void BM_SumOf3and5Until_2(benchmark::State& state) {
    for (auto _ : state)
        SumOf3and5Until_2(state.range(0));
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_SumOf3and5Until_2)->Arg(100)->Arg(1000)->Arg(10000)->Complexity();

BENCHMARK_MAIN();
