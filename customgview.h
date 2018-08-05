#ifndef CUSTOMGVIEW_H
#define CUSTOMGVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include <opencv2/opencv.hpp>

class CustomGView : public QGraphicsView {
    private:
        QGraphicsScene* scene;
        cv::Mat oCVImg;

    public:
        explicit CustomGView( QWidget* parent = nullptr, qreal x = 0.0, qreal y = 0.0, qreal w = 0.0, qreal h = 0.0 );
        ~CustomGView();

    signals:
        public slots:
            void mousePressEvent(QMouseEvent * e);
    };

#endif // CUSTOMGVIEW_H
