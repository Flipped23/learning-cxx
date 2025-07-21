#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        if (i < 0 || i >= 128) {
            throw std::out_of_range("Index out of range");
        }
        for (int j = cached + 1; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib = {};
    fib.cached = 1;
    fib.cache[0] = 0;
    fib.cache[1] = 1;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
