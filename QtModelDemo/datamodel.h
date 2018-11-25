#include <QAbstractListModel>
#include <QtDebug>
#include "singleton.hpp"
#ifndef DATAMODEL_H
#define DATAMODEL_H
extern int width[];
class Global : public QObject{
    Q_OBJECT
signals:
    void widthChanged(int);
};
typedef Singleton<Global> G;
class DataModel : public QAbstractListModel{
    Q_OBJECT
public slots:
    void widthChanged(int i){
        emit dataChanged(createIndex(i,0),createIndex(i,0));
    }
public:
    explicit DataModel(QObject *parent = Q_NULLPTR){
        std::fill_n(width, 100, 100);
        connect(G::instance(),SIGNAL(widthChanged(int)),this,SLOT(widthChanged(int)));
    }
    virtual ~DataModel(){}
    enum Roles {
        WidthRole = Qt::UserRole + 1,
        HeightRole,
        ColorRole
    };
    Q_ENUM(Roles)
    QHash<int, QByteArray> roleNames() const {
        QHash<int, QByteArray> result = QAbstractListModel::roleNames();
        result.insert(WidthRole, ("mWidth"));
        result.insert(HeightRole, ("mHeight"));
        result.insert(ColorRole, ("mColor"));
        return result;
    }
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        return 100;
    }
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override{
        return 3;
    }
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{
        if(index.isValid()){
            switch(role){
            case WidthRole:
                return width[index.row()];
            }
            return 0;
        }
    }
};

#endif // DATAMODEL_H
