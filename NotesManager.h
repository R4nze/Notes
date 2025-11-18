#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include <QObject>
#include<QList>
#include"NoteItem.h"
#include"Type.h"

class NotesManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> noteList READ noteList  NOTIFY noteListChanged FINAL)
    Q_PROPERTY(bool deletemode READ deletemode WRITE setDeletemode NOTIFY deletemodeChanged FINAL)
    Q_PROPERTY(QList<Type*> typeModel READ typeModel NOTIFY typeModelChanged FINAL)

public:
    explicit NotesManager(QObject *parent = nullptr);

    QList<QObject *> noteList() const {return m_noteList;}

    bool deletemode() const {return m_deletemode;};
    void setDeletemode(bool newDeletemode);

    QList<Type *> typeModel() const {return m_typeModel;};
    Q_INVOKABLE QColor getTypeColor(NoteItem *item) ;

public slots:
    void addNote(const QString &name, const QString &description, const QString &text, const int& id);
    void changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text, const QString &nameOfColor, const QColor &color);
    void deleteSelectedNotes();
    void addSelectedNote(NoteItem* item);
    void removeSelectedNote(NoteItem* item);
    void sortByType(int idOfType);
    int getOrCreateTypeId(const QString& name, const QColor &color);

private:
    QList<QObject *> m_noteList;
    QList<NoteItem *> m_selectedNotes;
    bool m_deletemode;
    int m_nextTypeId = 0;
    QList<Type *> m_typeModel;

signals:
    void noteListChanged();
    void deletemodeChanged();
    void typeModelChanged();
};

#endif // NOTESMANAGER_H
