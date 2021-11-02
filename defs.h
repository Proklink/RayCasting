#ifndef DEFS_H
#define DEFS_H
#include <QString>

const ushort FRAMEPERSEC = 24;

const QString Map = {"################"
               "#..........#...#"
               "#..........#...#"
               "#######....#...#"
               "#..............#"
               "#..............#"
               "#.##..##.#####.#"
               "#....#.....#####"
               "#####....#######"
               "#..............#"
               "#..............#"
               "#..............#"
               "#..............#"
               "#..............#"
               "#..............#"
               "################"
              };

const int ScreenWidth = 640;
const int ScreenHeigth = 640;

// 60 degrees
const float aFOV = 3.14f / 3.0f;

const float VisibilityRange = 30.0f;

const int MapWidth = 16;
const int MapHeigth = 16;

#endif // DEFS_H
