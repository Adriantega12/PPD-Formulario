#include "customgview.h"

CustomGView::CustomGView(QWidget *parent, qreal x, qreal y, qreal w, qreal h)
    : QGraphicsView( scene = new QGraphicsScene(), parent ) {
    this->move(x, y);
    this->resize(w, h);
    }

CustomGView::~CustomGView() { }

void CustomGView::mousePressEvent(QMouseEvent *e) {

    }
