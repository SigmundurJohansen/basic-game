#pragma once
#include <string>
#include <vector>


std::string default_tile = "isometric_0028";
std::string road_tile = "isometric_0055";
std::string spawn_tile = "isometric_0151";
std::string tower_unit = "tower01";
std::vector<std::string> altar = {"altar1", "altar2", "altar3"};
std::vector<std::string> fire = {"fire1", "fire2", "fire3", "fire4", "fire5", "fire6", "fire7", "fire8"};

std::vector<std::string> game_map_default = {
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile};

std::vector<std::string> game_map1 = {
    // 1                        2                       3                       4                       5                           6                           7                       8                           9
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, road_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, road_tile, road_tile, road_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, road_tile, road_tile, default_tile, road_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, road_tile, road_tile, default_tile, default_tile, road_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile, default_tile, default_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, road_tile, default_tile,
    default_tile, default_tile, default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile, road_tile,
    default_tile, default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile, road_tile, default_tile,
    default_tile, default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile, road_tile, default_tile,
    default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile, road_tile, default_tile, default_tile,
    default_tile, default_tile, road_tile, default_tile, default_tile, road_tile, default_tile, road_tile, default_tile, default_tile,
    default_tile, default_tile, road_tile, road_tile, road_tile, default_tile, default_tile, road_tile, road_tile, default_tile,
    default_tile, default_tile, default_tile, road_tile, road_tile, default_tile, default_tile, default_tile, road_tile, road_tile,
    default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, default_tile, spawn_tile};
