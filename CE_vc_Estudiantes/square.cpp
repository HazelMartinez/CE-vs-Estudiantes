#include "square.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>

Square::Square(QGraphicsItem *parent)()
{
    QVector<QPointF> squarePoints;
    squarePoints << QPointF(0,0) << QPointF(1,0) << QPointF(0,1) << QPointF(1,1);

    // scale the points
    int SCALE_BY = 40;
    for (size_t i = 0, n = squarePoints.size(); i < n; ++i){
        squarePoints[i] = squarePoints[i] * SCALE_BY;
    }

    // create a polygon with the scaled points
    QPolygonF square(squarePoints);

    // draw the poly
    setPolygon(square);

}



