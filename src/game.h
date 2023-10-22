#pragma once
#include "monster.h"
#include "tower.h"
#include <vector>

static std::vector<Tower> s_towers;
static std::vector<Monster> s_monsters;

class game_map
{
  public:
    int stage = 0;
    int turn = 0;
    int stages = 5;
    int spawned = 0;
    int wave1 = 5;
    int wave2 = 6;
    int wave3 = 7;
    int wave4 = 8;
    int wave5 = 9;
    int start_x = 990;
    int start_y = 480;
    int delayInSeconds = 1;
    float timer = 0;
    float prev_time = 0;

    void Loop();
};