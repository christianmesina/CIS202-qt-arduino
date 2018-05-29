#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QWidget>
#include <QDateTime>

BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(50,50))

{
    setFixedSize(100,100);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::addToOrigin(const QPoint &point)
{
    m_origin += point;
    qDebug() << "Point x: " << m_origin.x() << "Point y: " << m_origin.y();
}

void BallAnimation::setMove(int mv_x, int mv_y)
{
    CollisionDetect();
    addToOrigin(QPoint((mv_x * xMod), (mv_y * yMod)));
}

void BallAnimation::CollisionDetect()
{
    if(m_origin.x() == 90 || m_origin.x() == 10 ||
       m_origin.y() == 90 || m_origin.y() == 10)
    {
        xMod *= -1;
        yMod *= -1;
    }
}

int BallAnimation::randomGenerator()
{
    int max = 4;
    int min = -2;
    qsrand(QDateTime::currentMSecsSinceEpoch() % 5000);
    int rand = qrand();
    rand %= max;
    return(rand + 5);
}


void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width(),height()));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);
    painter.drawEllipse(m_origin,10,10);
}

