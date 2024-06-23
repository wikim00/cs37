#include <iostream>

//basic fibonacci recursive
int fibonacci(int n) {
    if (n<=1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// constexpr version of fibonacci
constexpr int fibonacci_c(int n) {
    if (n <= 1) return n;
    return fibonacci_c(n-1) + fibonacci_c(n-2);
}

#include <chrono>

int main() {
    // record the current start time so we can calculate the toal run-time at the end
    auto start = std::chrono::high_resolution_clock::now();
    constexpr int num = 35;

    constexpr int result_c = fibonacci_c(num); //this is evaluated at compiling

    std::cout << "Fibonacci_c " << result_c << std::endl;
    std::cout << "Time Taken: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

    start = std::chrono::high_resolution_clock::now();

    int result = fibonacci(num); // this is evaluated at compile time

    std::cout << "Fibonacci: " << result << std::endl;
    std::cout << "Time Taken: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
}