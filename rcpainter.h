#ifndef RCPAINTER_H
#define RCPAINTER_H

#include <QPaintEvent>
#include <QPainter>
#include "defs.h"

class RCPainter
{
public:
    RCPainter();

    void paint(QPainter *painter, QPaintEvent *event);

    // 270 degrees
    float aPOV = 3 * 3.14f / 2;
    float xPlayer = 7;
    float yPlayer = 14;
};

#endif // RCPAINTER_H
