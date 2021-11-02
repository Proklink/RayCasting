#include "rcpainter.h"
#include <QPen>
#include <QtMath>
#include <QDebug>

RCPainter::RCPainter()
{

}

void RCPainter::paint(QPainter *painter, QPaintEvent *event) {
    QPen pen(Qt::SolidLine);

    float delta = aFOV / ScreenWidth;
    float startDir = aPOV - aFOV / 2;

    for (float aDirection = startDir; aDirection <= aPOV + aFOV / 2; aDirection += delta) {

        float DistanceToWall = 0.0f;

        float xUnitVector = qCos(aDirection);
        float yUnitVector = qSin(aDirection);

        bool HitWall = false;

        while (!HitWall && (DistanceToWall <= VisibilityRange)) {
            DistanceToWall += 0.1f;

            float xSum = xPlayer + xUnitVector * DistanceToWall;
            float ySum = yPlayer + yUnitVector * DistanceToWall;

            if ( xSum <= 0 || ySum <= 0        ||
                 xSum > MapWidth  || ySum > MapHeigth ||
                 Map[(int)xSum + (int)ySum * MapWidth] == '#' )
                HitWall = true;
        }

        float Ceiling = ScreenHeigth / 2 - (ScreenHeigth / 2) / DistanceToWall;
        float Floor = ScreenHeigth - Ceiling;
        
        for (int y = 0; y < ScreenHeigth; y++) {
            if (y <= Ceiling) {
                pen.setColor(0x556832);
            }
            else if (y > Ceiling && y < Floor) {
                if (DistanceToWall >= VisibilityRange) {
                    pen.setColor(Qt::black);
                } else {
                    pen.setColor(0x642424);
                }
            }
            else {
                pen.setColor(0xd3d2d6);
            }
            painter->setPen(pen);
            painter->drawPoint((aDirection - startDir) / delta, y);
        }
    }
}
