#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include "rcpainter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::Widget *ui;
    QGraphicsScene *mainScene;
    QTimer *timer;
    QGraphicsView *view;
    QVBoxLayout *mainLayout;
    RCPainter *rcp;

private slots:
    void slotAlarmTimer();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};
#endif // WIDGET_H
