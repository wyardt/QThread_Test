#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QThread>

class BackGround : public QThread
{
    Q_OBJECT
public:
    BackGround();

    void run() Q_DECL_OVERRIDE;
public slots:
    void Trigger(void);
private:
    bool triggered;
signals:
    void Generator(void);
};

#endif // BACKGROUND_H
