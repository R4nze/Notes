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

                FancyButton{
                    id: backButton
                    width: 55
                    height: 35
                    anchors{
                        left: searchDialog.left
                        top: searchDialog.top
                        leftMargin: 15
                        topMargin: 15
                    }

                    Layout.bottomMargin: 15
                    startColor: "#11998e"
                    endColor: "#38ef7d"
                    iconSource: "icons/LeftArrow.png"
                    onClicked:{
                        searchDialog.close();
                    }

                }

                TextField{
                    id: searchInput
                    Layout.fillWidth: true
                    Layout.preferredHeight: 35
                    Layout.bottomMargin: 15
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
                spacing: 15

                model: notesManager.noteList

                delegate: FancyButton{
                    id: noteCard
                    width: searchListView.width
                    height: 80
                    radius: 10

                    startColor: modelData.color
                    endColor: Qt.darker(modelData.color, 1.4)
                    RowLayout{
                        anchors.fill: parent
                        anchors.margins: 6
                        spacing: 15

                        ColumnLayout{
                            Layout.fillWidth: true

                            Text{
                                id: textOfName
                                //anchors.top: parent.top
                                text: modelData.NameOfNote
                                elide: Text.ElideRight
                                font.pixelSize: 15
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                            }
                            Text{
                                id: textOfTime
                                text: Qt.formatTime(modelData.LastDateOfRedact, "hh:mm")
                                font.pixelSize: 12
                            }
                        }
                        Text{
                            id: textOfText
                            text: modelData.Text

                            Layout.preferredWidth: 180
                            Layout.fillHeight: true
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            elide: Text.ElideRight
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
