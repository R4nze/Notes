#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "NotesManager.h"
#include "NoteItem.h"

int main(int argc, char *argv[])
{
   QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<NoteItem>("com.yourapp.notes", 1, 0, "NoteItem");

    NotesManager* notesManager = new NotesManager();
    engine.rootContext()->setContextProperty("notesManager", notesManager);

   QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                    &app, []() { QCoreApplication::exit(-1); },
   Qt::QueuedConnection);
   engine.loadFromModule("Notes", "Main");

   return app.exec();
}
