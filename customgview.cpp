#include "customgview.h"

CustomGView::CustomGView(QWidget *parent, qreal x, qreal y, qreal w, qreal h)
    : QGraphicsView( scene = new QGraphicsScene(), parent ) {
    this->move(x, y);
    this->resize(w, h);
    }

CustomGView::~CustomGView() { }

void CustomGView::updateScene(QGraphicsScene* gs) {
    scene = gs;
    }

void CustomGView::setLabel(QString l) {
    label = l;
}

void CustomGView::setPath(QString filePath){
    path = filePath;
    }

void CustomGView::mousePressEvent(QMouseEvent *e) {
    FootDialog fd;
    fd.setup(scene, label, path);
    fd.exec();
    fd.show();
    }
