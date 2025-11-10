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
        contentHeight: notesGrid.implicitHeight + 100
        contentWidth: parent.width
        Grid{
            id: notesGrid
            property bool isGridView: true
            width: notesFlickable.width
            columns: isGridView ? 2 : 1
            spacing: 40

            anchors{

                top: parent.top

                left: parent.left
                right: parent.right
                topMargin: 50
                rightMargin: 20
                leftMargin: 20
            }
            // width: 120
            //height: 190

            Repeater{
                model: notesManager.noteList

                Flipable{
                    id: noteCard
                    height: notesGrid.columns === 1 ? 100 : 190
                    width: notesGrid.columns === 1 ? notesGrid.width : 120
                    property bool flipped: false
                    front: Rectangle{

                        anchors.fill: parent
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
                    }
                    back: Rectangle{
                        anchors.fill: parent
                        color: "red"
                        border.color: "gray"
                        radius: 8

                        Text{
                            id: textOfDescription
                            anchors{
                                margins: 20
                                fill: parent
                            }

                            text: modelData.Description
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            font.pointSize: 8
                        }
                    }
                    transform: Rotation {
                            id: rotation
                            property bool isRotation: false
                            origin.x: noteCard.width/2
                            origin.y: noteCard.height/2
                            axis.x: 0; axis.y: isRotation? -1 : 1; axis.z: 0     // set axis.y to 1 to rotate around y-axis
                    }
                    states: State {
                        name: "back"
                        PropertyChanges { target: rotation; angle: 180 }
                         when: noteCard.flipped
                    }

                    transitions: Transition {
                        NumberAnimation { target: rotation; property: "angle"; duration: 800 }
                    }


                    MouseArea{
                        anchors.fill: parent

                        property point pressPos: Qt.point(0,0)
                        property bool isSwipe: false

                        onPressed:function(mouse){
                            pressPos = Qt.point(mouse.x, mouse.y);;
                            isSwipe = false;
                        }
                        onPositionChanged: function(mouse){
                            if(Math.abs(mouse.x - pressPos.x) > 10 || Math.abs(mouse.y - pressPos.y) > 10){
                                isSwipe = true;
                            }
                        }

                        onReleased: function(mouse){
                            var dx = mouse.x - pressPos.x
                            if(Math.abs(dx) > 30){
                                rotation.isRotation = !rotation.isRotation;
                                noteCard.flipped = !noteCard.flipped;
                            }

                            else if(Math.abs(dx) <= 30 && !isSwipe){
                                editorScreen.changeNote(modelData);
                                editorScreen.dialogController.open();
                            }
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

    Rectangle{
        id: addSwapButton
        property bool colorChange: true
        width: 25
        height: 25
        color: colorChange ? "grey" : "lightblue"
        anchors{
            right: parent.right
            top: parent.top
            rightMargin: 20
            topMargin: 20
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                addSwapButton.colorChange = !addSwapButton.colorChange
                notesGrid.isGridView = !notesGrid.isGridView
            }
        }
    }

    EditorScreen{ //Окно добавления заметки
        id: editorScreen
    }

}
