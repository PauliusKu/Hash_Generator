//
// Created by Paulius on 2019-10-03.
//

#ifndef HASH_GENERATOR_TIMER_H
#define HASH_GENERATOR_TIMER_H

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    typedef std::chrono::high_resolution_clock h_r_clock;
    typedef std::chrono::duration<double> double_duration;
private:
    std::chrono::time_point<h_r_clock> start;
public:
    Timer() :
            start(h_r_clock::now())
    {}
    inline void reset() { start = h_r_clock::now(); }
    [[nodiscard]] inline double elapsed() const { return double_duration(h_r_clock::now() - start).count(); }

};

#endif

#endif //HASH_GENERATOR_TIMER_H
