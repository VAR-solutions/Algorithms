// Computes a specific index of the Fibonacci sequence
// Can be computed at compile-time under certain conditions

constexpr unsigned int fibonacci(unsigned int index) {

    constexpr auto gr = (1 + std::sqrt(5)) / 2;

    if(index == 0) {
        return 0;
    } else if(index == 1) {
        return 1;
    }

    return static_cast<unsigned int>(
            (std::pow(gr, index) - std::pow(1 - gr, index)) / sqrt(5)
    );
}
