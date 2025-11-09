import QtQuick
import com.yourapp.notes 1.0

Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("Notes")

    Flickable{ //Прокручивающаяся сетка заметок
        id: notesFlickable
        anchors.fill: parent
        contentHeight: parent.height
        contentWidth: parent.width

        Grid{
            id: notesGrid
            width: parent.width
            columns: 2
            spacing: 40

            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
                topMargin: 50

                leftMargin: 20
            }

            Repeater{
                model: notesManager.noteList

                Rectangle{
                    height: 190
                    width: 120
                    color: "lightblue"
                    border.color: "gray"
                    radius: 8

                    Text{
                        id: textOfText
                        text: modelData.Text
                        font.pointSize: 8
                        anchors{
                            top: parent.top
                            left: parent.left
                            right: parent.right
                            bottom: textOfName.top
                            topMargin: 5
                            leftMargin: 8
                            rightMargin: 8
                        }
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        elide: Text.ElideRight

                    }

                    Text{
                        id: textOfName
                        anchors{

                            left: parent.left
                            right: parent.right
                            bottom: parent.bottom
                            bottomMargin: 15
                            leftMargin: 7
                            rightMargin: 7
                        }
                        horizontalAlignment: Text.AlignHCenter
                        text: modelData.NameOfNote
                        font.pointSize: 8
                        wrapMode: Text.WordWrap // Разрешаем перенос слов
                        maximumLineCount: 2
                        elide: Text.ElideRight

                        height: 15
                    }
                    MouseArea{
                        id: noteInfo

                        anchors.fill: parent
                        onClicked: {
                            editorScreen.changeNote(modelData);
                            editorScreen.dialogController.open();

                        }
                    }
                }
            }
        }


    }

    Rectangle{ //Кнопка добавления заметки
        id: addNotesButton

        width: 50
        height: 50
        color: "green"

        anchors{
            right: parent.right
            bottom: parent.bottom
            rightMargin: 40
            bottomMargin: 90
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                editorScreen.currentNote = null;
                editorScreen.dialogController.open();
            }
        }

    }
    EditorScreen{ //Окно добавления заметки
        id: editorScreen
    }

}
