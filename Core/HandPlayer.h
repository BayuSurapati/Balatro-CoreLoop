// Core/HandPlayer.h
#pragma once
#include "../Models/Hand.h"
#include "../Models/ChosenHand.h"

class HandPlayer {
public:
    ChosenHand playHand(const Hand& hand);
};