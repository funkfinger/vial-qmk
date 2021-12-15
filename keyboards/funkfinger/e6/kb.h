#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
      k00, k01, k02, \
      k10, k11, k12, \
                k22  \
) \
{ \
    { k00, k01, k02 }, \
    { k10, k11, k12 }, \
    { XXX, XXX, k22 } \
}
