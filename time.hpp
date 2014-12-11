#pragma once

#include <chrono>

typedef std::chrono::high_resolution_clock::time_point point;
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;

std::chrono::high_resolution_clock::time_point get_now() {
    return Time::now();
}

ms get_delta(point pA, point pB) {
    return std::chrono::duration_cast<ms>(pB - pA);
}

void print_delta(point pA, point pB) {
    ms diff = get_delta(pA, pB);
    std::cout << diff.count() << " milliseconds" << std::endl;
}