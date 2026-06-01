#pragma once

struct Score {
    long long chips;
    double mult;

    long long getTotal() const {
        return static_cast<long long>(chips * mult);
    }
};