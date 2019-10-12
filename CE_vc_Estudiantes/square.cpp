#include "square.h"
#include <QPointF>
#include <QRectF>
#include <QVector>

Square::Square(QGraphicsItem *parent){
    // draw the polygon

    // points needed to draw hexagon: (1,0), (2,0), (3,1), (2,2), (1,2), (0,1)

    QVector<QPointF> squarePoints;
    squarePoints << QPointF(1,0) << QPointF(2,0) << QPointF(2,1) << QPointF(1,1);
    // scale the points
    int SCALE_BY = 40;
    for (size_t i = 0, n = squarePoints.size(); i < n; ++i){
        squarePoints[i] = squarePoints[i] * SCALE_BY;
    }

    // create a polygon with the scaled points
    //QRectF square(squarePoints);
    QRectF square(10.0, 20.0, 80.0, 60.0);


    // draw the poly
    setPolygon(square);

}

