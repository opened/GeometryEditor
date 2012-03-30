#ifndef MY3DWIDGET_H
#define MY3DWIDGET_H

#include <QGLWidget>

class My3DWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit My3DWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

private:
    void draw();
    int faceAtPosition(const QPoint &pos);
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;
};

#endif // MY3DWIDGET_H
