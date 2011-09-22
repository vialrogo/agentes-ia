#include "imagencarro.h"

imagencarro::imagencarro() :
    QObject(0), QGraphicsPixmapItem(0)
{
    setCacheMode(DeviceCoordinateCache);
}

imagencarro::imagencarro(const QPixmap& pixmap) :
    QObject(0), QGraphicsPixmapItem(pixmap)
{
    setCacheMode(DeviceCoordinateCache);
}

imagencarro::imagencarro(QSizeF size, const QPixmap& pixmap, QObject* parent) :
    QObject(parent), QGraphicsPixmapItem(pixmap)
{
    m_size = size;
    setCacheMode(DeviceCoordinateCache);
}

imagencarro::~imagencarro()
{
}

QRectF imagencarro::boundingRect() const
{
return QRectF(0, 0, m_size.width(), m_size.height());
}

void imagencarro::animatePosition(const QPointF& end)
{
    // Start animate this class
    QPropertyAnimation* anim = new QPropertyAnimation(this, "pos");

    // 2 second duration animation
    anim->setDuration(1000);
    // position to start animation
    //anim->setStartValue(start);
    // end position of animation
    anim->setEndValue(end);
    // easing curve
    //anim->setEasingCurve(QEasingCurve::InOutElastic);

    // Listen animation finished signal
    QObject::connect(anim, SIGNAL(finished()), this, SLOT(animationFinished()));

    // Start animation and delete QPropertyAnimation class on the end
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void imagencarro::animationFinished()
{
    // This slot is called when animation ends
}
