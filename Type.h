#ifndef TYPE_H
#define TYPE_H

#include <QObject>
#include<QColor>

class Type : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nameOfType READ nameOfType WRITE setNameOfType NOTIFY nameOfTypeChanged FINAL)
    Q_PROPERTY(QColor nameOfColor READ nameOfColor WRITE setNameOfColor NOTIFY nameOfColorChanged FINAL)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
public:
    explicit Type(QObject *parent = nullptr);
    explicit Type(const QColor &nameOfColor, const QString &nameOfType, int id = 0, QObject *parent = nullptr);

    QString nameOfType() const {return m_nameOfType;};
    void setNameOfType(const QString &newNameOfType);

    QColor nameOfColor() const {return m_nameOfColor;};
    void setNameOfColor(const QColor &newNameOfColor);

    int id()  { return m_id;};
    void setId(int newId);

signals:
    void nameOfTypeChanged();
    void nameOfColorChanged();
    void idChanged();

private:
    QString m_nameOfType;
    QColor m_nameOfColor;
    int m_id;
};

#endif // TYPE_H
