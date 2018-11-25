#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QObject>
#include <QtDebug>
#include "datamodel.h"
#include <thread>
//class DataModel : public QObject
//{
//    Q_OBJECT
//    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
//    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
//public:
//    DataObject(QString* name,QString* color){this->q_name = name;this->q_color = color;}
//    QString name(){ return *this->q_name; }
//    QString color(){ return *this->q_color; }
//    void setName(const QString* name){ this->q_name = name; }
//    void setColor(const QString* color){ this->q_color = color; }
//private:
//    QString* q_name;
//    QString* q_color;
//};
int width[100];
int changeWidth(){
    const int range = 100;
    int index;
    while(true){
        index = rand() % range;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        width[index]+=1;
        width[index]%=640;
        emit G::instance()->widthChanged(index);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<DataModel>("Tmp", 1, 0, "DataModel");

    std::thread t(changeWidth);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
