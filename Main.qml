import QtQuick
import com.yourapp.notes 1.0
Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("Notes")
    property bool isDeleteMode: false
    property bool isAddMode: false

    Flickable{ //Прокручивающаяся сетка заметок
        id: notesFlickable
        anchors{
            fill: parent
            bottom: bottomBar.top
            top: topBar.bottom
            topMargin: 35
            bottomMargin: 30
        }

        contentHeight: notesGrid.implicitHeight + 100
        contentWidth: parent.width
        Grid{
            id: notesGrid
            property bool isGridView: true
            property bool timeFlipped: false
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

            Repeater{
                model: notesManager.noteList

                Flipable{
                    id: noteCard
                    height: notesGrid.columns === 1 ? 100 : 190
                    width: notesGrid.columns === 1 ? notesGrid.width : 120
                    property bool flipped: false
                    property bool isSelectedItem: false
                    Text{
                        id: frontTime
                        visible: !notesGrid.timeFlipped
                        anchors{
                            top: noteCard.bottom
                            left: noteCard.left
                            right: noteCard.right
                        }
                        transform : Rotation{
                            origin.x: frontTime.width / 2
                            origin.y: frontTime.height / 2
                            angle: -rotation.angle

                            axis.x: 0; axis.y: 1; axis.z: 0;
                        }

                        horizontalAlignment: Text.AlignHCenter
                        text: Qt.formatTime(modelData.LastDateOfRedact, "hh:mm")
                    }
                    front:
                        Rectangle{
                        id: frontRectangle
                        anchors.fill: parent
                        color: "lightblue"
                        border.color: isSelectedItem && isDeleteMode ? "black" : "gray"
                        radius: 8
                        border.width: isSelectedItem && isDeleteMode ? 3 : 1

                        Text{
                            id: timeInRectangle
                            visible: notesGrid.timeFlipped
                            anchors{
                                right: frontRectangle.right
                                bottom: frontRectangle.bottom
                                rightMargin: 5
                                bottomMargin: 5
                            }
                            text: Qt.formatTime(modelData.LastDateOfRedact, "hh:mm")
                        }

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
                                bottomMargin: 8
                                leftMargin: 7
                                rightMargin: 7
                            }
                            horizontalAlignment: notesGrid.timeFlipped ? Text.AlignLeft : Text.AlignHCenter
                            text: modelData.NameOfNote
                            font.pointSize: 8
                            wrapMode: Text.WordWrap // Разрешаем перенос слов
                            elide: Text.ElideRight

                            height: 15
                        }
                    }
                    back:
                        Rectangle{
                        id: backRectangle
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
                        Text{
                            id: backTimeInfo
                            visible: notesGrid.timeFlipped
                            anchors{
                                bottom: backRectangle.bottom
                                right: backRectangle.right
                                bottomMargin: 5
                                rightMargin: 5
                            }
                            text: Qt.formatTime(modelData.LastDateOfRedact, "hh:mm")
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
                        id: selectDeleteNote
                        anchors.fill: frontRectangle
                        enabled: isDeleteMode

                        onClicked: {
                            console.log("Произошло нажатие")
                            noteCard.isSelectedItem = !noteCard.isSelectedItem
                            if(noteCard.isSelectedItem){
                                notesManager.addSelectedNote(modelData);
                            }
                            else{
                                notesManager.removeSelectedNote(modelData);
                            }
                        }
                    }

                    MouseArea{
                        id: noteMouseArea
                        anchors.fill: parent
                        enabled: !isDeleteMode
                        property point pressPos: Qt.point(0,0)
                        property bool isSwipe: false


                        Timer{
                            id: longPressTimer

                            interval: 650
                            repeat: false

                            onTriggered: {
                                isDeleteMode = true
                                noteCard.isSelectedItem = true
                                notesManager.addSelectedNote(modelData);
                                console.log("Включён режим удаления")
                            }
                        }

                        onPressed:function(mouse){
                            pressPos = Qt.point(mouse.x, mouse.y);;
                            isSwipe = false;
                            longPressTimer.start();
                        }

                        onPositionChanged: function(mouse){
                            if(Math.abs(mouse.x - pressPos.x) > 10 || Math.abs(mouse.y - pressPos.y) > 10){
                                isSwipe = true;
                            }
                        }

                        onReleased: function(mouse){
                            var dx = mouse.x - pressPos.x

                            longPressTimer.stop()
                            if(isDeleteMode) return;
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

    Rectangle{
        id: topBar
        height: 70
        width: parent.width
        anchors.top: parent.top
        color: "blue"

        Rectangle{
            id: cancelDeleteModeButton
            visible: isDeleteMode
            color: "yellow"
            height: 25
            width: 25
            anchors{
                left: parent.left
                bottom: parent.bottom
                leftMargin: 10
                bottomMargin: 10
            }
            MouseArea{
                id: cancelButton
                anchors.fill: parent
                onClicked: {
                    isDeleteMode = !isDeleteMode
                    console.log("Режим удаления выключен")
                }
            }

        }

    }

    Rectangle{
        id: bottomBar
        height: 60
        width: parent.width
        anchors.bottom: parent.bottom
        color: "lightgreen"

        Rectangle{
            id: deleteButtom
            visible: isDeleteMode
            color: "grey"
            height: 25
            width: 25
            anchors{
                left: bottomBar.left
                top: bottomBar.top
                leftMargin: 10
                topMargin: 10
            }
            MouseArea{
                anchors.fill: parent
                onClicked:{
                    notesManager.deleteSelectedNotes()
                    isDeleteMode = !isDeleteMode
                }

            }
        }
    }

    Rectangle{ //Кнопка добавления заметки
        id: addNotesButton
        width: 55
        height: 55
        color: "green"
        radius: 180
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
                if(isDeleteMode){
                    isDeleteMode = !isDeleteMode
                }

                editorScreen.dialogController.open();

            }
        }
    }

    Rectangle{
        id: addSwapButton //Кнопка изменения вида кнопок
        property bool colorChange: true
        width: 25
        height: 25
        color: colorChange ? "grey" : "lightblue"
        anchors{
            right: topBar.right
            bottom: topBar.bottom
            rightMargin: 20
            bottomMargin: 20
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                notesGrid.timeFlipped = !notesGrid.timeFlipped
                addSwapButton.colorChange = !addSwapButton.colorChange
                notesGrid.isGridView = !notesGrid.isGridView
            }
        }
    }

    EditorScreen{ //Окно добавления заметки
        id: editorScreen
    }

}
