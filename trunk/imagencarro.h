#ifndef IMAGENCARRO_H
#define IMAGENCARRO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QtGui>

class imagencarro : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

        // Change picture position property for QPropertyAnimation
        Q_PROPERTY(QPointF pos READ pos WRITE setPos)

    public:
        enum
        {
            PictureItemType = UserType + 1
        };

    public:
        imagencarro(QSizeF size, const QPixmap& pixmap = 0, QObject* parent = 0);
        imagencarro();
        imagencarro(const QPixmap& pixmap);
        ~imagencarro();

        // Animate position of this class
        void animatePosition(const QPointF& end);
        QRectF boundingRect() const;

        int type() const
        {
            return PictureItemType;
        }

    public slots:
        void animationFinished();

    private:
        QSizeF m_size;
};

#endif // IMAGENCARRO_H
