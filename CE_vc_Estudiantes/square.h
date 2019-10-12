#ifndef SQUARE_H
#define SQUARE_H
#include <QGraphicsPolygonItem>


class Square: public QGraphicsPolygonItem
{
public:
    Square(QGraphicsItem* parent=NULL);
private:
    QString duenio;
};

#endif // SQUARE_H
