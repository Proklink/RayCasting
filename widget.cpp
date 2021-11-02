#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , timer(new QTimer)
    , rcp(new RCPainter)
{
    ui->setupUi(this);

    this->resize(ScreenWidth, ScreenHeigth);          // Устанавливаем размеры окна приложения

    mainLayout = new QVBoxLayout();

    mainScene = new QGraphicsScene();
    mainScene->setItemIndexMethod(QGraphicsScene::NoIndex);

    view = new QGraphicsView();
    view->resize(600,600);  // Устанавливаем размер graphicsView
    view->setScene(mainScene);  // Устанавливаем графическую сцену в graphicsView
//    view->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
//    view->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
//    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //mainScene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены

    //mainLayout->addWidget(view);
    //setLayout(mainLayout);

    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(1000 / FRAMEPERSEC);                   // Стартуем таймер на 50 миллисекунд

}

Widget::~Widget()
{
    delete ui;
    delete mainScene;
    delete view;
    delete timer;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter;
    qDebug() << "paintEvent";
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    rcp->paint(&painter, event);
    painter.end();
}

void Widget::slotAlarmTimer() {
    this->update();
}

void Widget::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    switch (key) {
        case Qt::Key_W: {
            rcp->yPlayer -= 0.1f;
            break;
        }
        case Qt::Key_S: {
            rcp->yPlayer += 0.1f;
            break;
        }
        case Qt::Key_A: {
            rcp->xPlayer -= 0.1f;
            break;
        }
        case Qt::Key_D: {
            rcp->xPlayer += 0.1f;
            break;
        }
        case Qt::Key_Left: {
            rcp->aPOV += 0.1f;
            break;
        }
        case Qt::Key_Right: {
            rcp->aPOV += 0.1f;
            break;
        }

    }


}
void Widget::keyReleaseEvent(QKeyEvent *event) {

}
