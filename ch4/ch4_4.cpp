//
// Created by Razdan, Akhil on 2021/05/19.
//

#include <ctime>
#include <cstdio>

struct TimerClass {
    TimerClass() {
        timestamp = std::time(nullptr);
    }

    // Copy constructor
    TimerClass(const TimerClass &other) : timestamp{other.timestamp} {

    };

    // Move constructor
    TimerClass(TimerClass &&other) : timestamp{other.timestamp} {
        other.timestamp = 0;
    }

    TimerClass &operator=(const TimerClass &other) {
        if (this == &other) return *this;
        this->timestamp = other.timestamp;
        return *this;
    }

    // Move assignment
    TimerClass &operator=(TimerClass &&other)  noexcept {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        other.timestamp = 0;
    }

    ~TimerClass() noexcept {
        auto age = std::time(nullptr) - timestamp;
        printf("%ld\n", age);
    }

    std::time_t timestamp;
};

int main() {
    TimerClass timerClass{};
    TimerClass copy{timerClass};
    printf("%ld\n", timerClass.timestamp);
    printf("%ld\n", copy.timestamp);
    TimerClass b{};
    b = timerClass;
    printf("%ld\n", b.timestamp);
    return 0;
}