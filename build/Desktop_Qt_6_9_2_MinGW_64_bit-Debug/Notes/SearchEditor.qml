import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
Item {
    id: root
    width: parent.width
    property alias searchDialog: searchDialog
    Dialog{
        id: searchDialog
        width: 360
        height: 640

        anchors.centerIn: parent
        modal: true

        onOpened: {
            searchInput.text = ""
            notesManager.searchNotes("")
        }

        background: Rectangle {
            color: "white"
        }

        onClosed: {
            searchInput.text = ""
            notesManager.searchNotes("")
        }

        ColumnLayout{
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            RowLayout{
                Layout.fillWidth: true
                spacing: 10

                Rectangle{
                    id: backButton
                    width: 55
                    height: 30
                    anchors{
                        left: searchDialog.left
                        top: searchDialog.top
                        leftMargin: 15
                        topMargin: 15
                    }
                    color: "green"
                    MouseArea{
                        id: buttonToClose
                        anchors.fill: parent
                        onClicked:{
                            searchDialog.close();
                        }
                    }
                }
                TextField{
                    id: searchInput
                    Layout.fillWidth: true
                    placeholderText: "Поиск "
                    onTextChanged: {
                        notesManager.searchNotes(text)
                    }
                }
            }

            ListView{
                id: searchListView
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true
                spacing: 10

                model: notesManager.noteList

                delegate: Rectangle{
                    id: noteCard
                    width: searchListView.width
                    height: 80
                    radius: 10

                    color: modelData.color
                    border.color: "gray"
                    border.width: 1

                    RowLayout{
                        anchors.fill: parent
                        anchors.margins: 6
                        spacing: 15

                        ColumnLayout{
                            Layout.fillWidth: true

                            Text{
                                id: textOfName
                                text: modelData.NameOfNote
                                elide: Text.ElideRight
                                font.pixelSize: 15
                                Layout.fillWidth: true
                            }
                            Text{
                                id: textOfTime
                                text: Qt.formatTime(modelData.LastDateOfRedact, "hh:mm")
                                color: "#555"
                                font.pixelSize: 12
                            }
                        }
                        Text{
                            id: textOfText
                            text: modelData.Text

                            Layout.preferredWidth: 100
                            Layout.fillHeight: true
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            elide: Text.ElideRight
                            color: "#333"
                            font.pixelSize: 12
                            verticalAlignment: Text.AlignLeft
                        }
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            searchDialog.close();
                            editorScreen.changeNote(modelData);
                            editorScreen.dialogController.open();
                        }
                    }
                }

            }
        }




    }
    EditorScreen{ //Окно добавления заметки
        id: editorScreen
    }
}
