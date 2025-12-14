#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include <QObject>
#include<QList>
#include"NoteItem.h"
#include"Type.h"
#include "DatabaseHandler.h"

class NotesManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> noteList READ noteList  NOTIFY noteListChanged FINAL)
    Q_PROPERTY(bool deletemode READ deletemode WRITE setDeletemode NOTIFY deletemodeChanged FINAL)
    Q_PROPERTY(QList<Type*> typeModel READ typeModel NOTIFY typeModelChanged FINAL)

public:
    explicit NotesManager(QObject *parent = nullptr);

    QList<QObject *> noteList() const {return m_displayList;}

    bool deletemode() const {return m_deletemode;};
    void setDeletemode(bool newDeletemode);

    QList<Type *> typeModel() const {return m_typeModel;};
    Q_INVOKABLE QColor getTypeColor(NoteItem *item) ;
    Q_INVOKABLE QColor getColor(int id);
    Q_INVOKABLE QColor getDarkerColor(const QColor &color, int factor);
    Q_INVOKABLE QString getTypeNameForColor(const QString& colorCode);

public slots:
    void addNote(const QString &name, const QString &description, const QString &text, const int& id);
    void changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text, const QString &nameOfColor, const QColor &color);
    void changeType(const int &id, const QString &name);
    void deleteSelectedNotes();
    void addSelectedNote(NoteItem* item);
    void removeSelectedNote(NoteItem* item);
    void removeAllSelectedNote();
    void sortByType(int idOfType);
    void sortByChoice(int idOfType);
    void searchNotes(const QString &query);
    void toggleFavorites(int noteId);
    void toggleSelectedFavorites();
    int getOrCreateTypeId(const QString& name, const QColor &color);

private:
    void checkToRemoveType(int idOfType);
    void updateDisplayList();
    void loadNotesFromDatabase();

    QList<QObject*> m_displayList;
    QList<NoteItem*> m_allNotes;
    QList<NoteItem *> m_selectedNotes;
    QList<Type *> m_typeModel;
    bool m_deletemode;
    int m_nextTypeId = 0;
    int m_currentFilterId = -1;
    DatabaseHandler m_database;

signals:
    void noteListChanged();
    void deletemodeChanged();
    void typeModelChanged();
};

#endif // NOTESMANAGER_H
