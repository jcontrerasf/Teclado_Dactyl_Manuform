#pragma once

#include "dactyl_manuform.h"

#define XXX KC_NO

#define LAYOUT_5x7( \
    L11, L12, L13, L14, L15, L16, \
    L31, L32, L23, L24, L25, L26, \
    L41, L42, L33, L34, L35, L36, \
    L51, L52, L43, L44, L55, L56, \
              L53, L54, \
                        L57, L37, L17, \
                             L47, L27, \
              R16, R15, R14, R13, R12, R11, \
              R26, R25, R24, R23, R32, R31, \
              R36, R35, R34, R33, R42, R41, \
              R56, R55, R44, R43, R52, R51, \
                        R54, R53, \
    R17, R37, R57, \
    R27, R47 \
) { \
    { L11, L12, L13, L14, L15, L16, L17 }, \
    { XXX, XXX, L23, L24, L25, L26, L27 }, \
    { L31, L32, L33, L34, L35, L36, L37 }, \
    { L41, L42, L43, L44, XXX, XXX, L47 }, \
    { L51, L52, L53, L54, L55, L56, L57 }, \
    { R11, R12, R13, R14, R15, R16, R17 }, \
    { XXX, XXX, R23, R24, R25, R26, R27 }, \
    { R31, R32, R33, R34, R35, R36, R37 }, \
    { R41, R42, R43, R44, XXX, XXX, R47 }, \
    { R51, R52, R53, R54, R55, R56, R57 } \
}
