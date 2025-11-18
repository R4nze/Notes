#include "Type.h"

Type::Type(QObject *parent)
    : QObject{parent}
{}

Type::Type(const QColor &nameOfColor, const QString &nameOfType, int id, QObject *parent)
    : QObject{parent}, m_nameOfType{nameOfType}, m_nameOfColor{nameOfColor}, m_id{id}
{}

void Type::setNameOfType(const QString &newNameOfType)
{
    if (m_nameOfType == newNameOfType)
        return;
    m_nameOfType = newNameOfType;
    emit nameOfTypeChanged();
}

void Type::setNameOfColor(const QColor &newNameOfColor)
{
    if (m_nameOfColor == newNameOfColor)
        return;
    m_nameOfColor = newNameOfColor;
    emit nameOfColorChanged();
}

void Type::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}
