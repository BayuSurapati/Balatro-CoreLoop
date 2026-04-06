#include "RewardRule.h"

int RewardRule::earnMoney(bool win, int score){
    return win ? 50:10;
}