#pragma once
#include <string>
#include <memory>

class BlindState {
public:
    virtual ~BlindState() = default;
    virtual std::string getName() const = 0;
    virtual int getTargetScore(int baseScore) const = 0;
    virtual bool canSkip() const = 0;
    virtual std::unique_ptr<BlindState> nextState() = 0;
};

class BossBlindState : public BlindState {
public:
    std::string getName() const override { return "Boss Blind"; }
    int getTargetScore(int baseScore) const override { return baseScore * 2; }
    bool canSkip() const override { return false; } // Boss cannot be skipped
    std::unique_ptr<BlindState> nextState() override; // Forward declaration
};

class BigBlindState : public BlindState {
public:
    std::string getName() const override { return "Big Blind"; }
    int getTargetScore(int baseScore) const override { return (int)(baseScore * 1.5); }
    bool canSkip() const override { return true; }
    std::unique_ptr<BlindState> nextState() override {
        return std::make_unique<BossBlindState>();
    }
};

class SmallBlindState : public BlindState {
public:
    std::string getName() const override { return "Small Blind"; }
    int getTargetScore(int baseScore) const override { return baseScore; }
    bool canSkip() const override { return true; }
    std::unique_ptr<BlindState> nextState() override {
        return std::make_unique<BigBlindState>();
    }
};

// Implementation for BossBlindState::nextState (back to Small Blind for Next Ante)
inline std::unique_ptr<BlindState> BossBlindState::nextState() {
    return std::make_unique<SmallBlindState>();
}
