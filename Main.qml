import QtQuick
import QtQuick.Layouts
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
            left:parent.left
            right:parent.right
            bottom: bottomBar.top
            top: topBar.bottom
        }
        contentHeight: notesGrid.implicitHeight + 65
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
                topMargin: 25
                rightMargin: 20
                leftMargin: 28
            }

            Repeater{
                model: notesManager.noteList

                Flipable{
                    id: noteCard
                    height: notesGrid.columns === 1 ? 100 : 190
                    width: notesGrid.columns === 1 ? notesGrid.width : 120
                    property bool flipped: false
                    property bool isSelectedItem: false
                    Item {
                        id: bottomInfoContainer
                        anchors {
                            top: noteCard.bottom
                            left: noteCard.left
                            right: noteCard.right
                        }
                        height: 20
                        visible: !notesGrid.timeFlipped

                        transform: Rotation {
                            origin.x: bottomInfoContainer.width / 2
                            origin.y: bottomInfoContainer.height / 2
                            angle: -rotation.angle
                            axis.x: 0; axis.y: 1; axis.z: 0;
                        }

                        Text {
                            id: frontTime
                            text: Qt.formatTime(modelData.LastDateOfRedact, "hh:mm")
                            font.pixelSize: 12
                            color: "black"
                            anchors.centerIn: parent
                        }

                        Text {
                            id: favouriteStar
                            text: "★"
                            color: "#FFD700"
                            font.pixelSize: 14

                            visible: modelData.isFavorite

                            anchors {
                                right: frontTime.left
                                verticalCenter: frontTime.verticalCenter
                                rightMargin: 4
                            }
                        }
                    }
                    front:
                        Rectangle{
                        id: frontRectangle
                        anchors.fill: parent
                        color: modelData.color
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
                        color: notesManager.getDarkerColor(modelData.color, 140);
                        border.color: isSelectedItem && isDeleteMode ? "black" : "gray"
                        border.width: isSelectedItem && isDeleteMode ? 3 : 1
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

                            interval: 1000
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
                                longPressTimer.stop();
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
        height: 95
        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
        }
        color: "blue"
    }
    Rectangle{ //кнопка отмены DeleteMode
        id: cancelDeleteModeButton
        visible: isDeleteMode
        color: "yellow"
        height: 25
        width: 25
        anchors{
            left: topBar.left
            top: topBar.top
            leftMargin: 22
            topMargin: 10
        }
        MouseArea{
            id: cancelButton
            anchors.fill: parent
            onClicked: {
                isDeleteMode = !isDeleteMode
                notesManager.removeAllSelectedNote();
                console.log("Режим удаления выключен")
            }
        }
    }

    Rectangle{
        id: bottomBar
        height: 60
        width: parent.width
        anchors{
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        color: "lightgreen"
    }
    Rectangle{
        id: favouritesButtons
        visible: isDeleteMode
        color: "red"
        height: 25
        width: 25
        anchors{
            right: bottomBar.right
            top: bottomBar.top
            rightMargin: 10
            topMargin: 10
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                notesManager.toggleSelectedFavorites();
                isDeleteMode = !isDeleteMode
            }
        }
    }
    Rectangle{ //кнопка удаления заметки
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
        width: 22
        height: 22
        color: colorChange ? "grey" : "lightblue"
        anchors{
            right: topBar.right
            top: topBar.top
            rightMargin: 10
            topMargin: 15
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
    Rectangle{
        id: sortNotesBy
        width: 22
        height: 22
        anchors{
            right: addSwapButton.left
            top: topBar.top
            rightMargin: 15
            topMargin: 15
        }
        color: "purple"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                sortNotes.sortNotesDialog.open();
            }
        }
    }
    Rectangle{
        id: seacrhButton
        width: 22
        height: 22
        anchors{
            right: sortNotesBy.left
            top: topBar.top
            rightMargin: 15
            topMargin: 15
        }
        color: "pink"
        MouseArea{
            anchors.fill: parent
            onClicked:{
                searchEditor.searchDialog.open();
            }
        }
    }

    Rectangle{
        id: changeTypeButton //Кнопка изменения типов
        anchors{
            right: topBar.right
            bottom: topBar.bottom
            rightMargin: 10
            bottomMargin: 18
        }
        width: 87
        height: 30
        color: "orange"

        MouseArea{
            anchors.fill: parent
            onClicked:{
                editorType.dialogController.open();
            }
        }
    }

    Flickable{
        anchors{
            left: topBar.left
            right: changeTypeButton.left
            bottom: topBar.bottom
            bottomMargin: 18
            leftMargin: 8
        }
        contentWidth: topBar.width + changeTypeButton.width
        flickableDirection: Flickable.HorizontalFlick
        height: 30
        clip: true
        RowLayout{
            id: rowOfTypes
            anchors.verticalCenter: parent.verticalCenter
            spacing: 10
            Repeater{
                model: notesManager.typeModel

                Rectangle{
                    id: rowRectangle
                    color: modelData.nameOfColor

                    Layout.preferredWidth: 75
                    Layout.preferredHeight: 30
                    radius: 8

                    Text{
                        anchors{
                            left: parent.left
                            right: parent.right
                            top: parent.top
                            bottom: parent.bottom
                            leftMargin: 10
                        }
                        verticalAlignment: Text.AlignVCenter
                        text: modelData.nameOfType
                        elide: Text.ElideRight
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            notesManager.sortByType(modelData.id);
                        }
                    }
                }
            }
        }
    }
    EditorScreen{ //Окно добавления заметки
        id: editorScreen
    }
    EditorType{ //Окно изменения названия заметки
        id: editorType
    }
    SortNotes{
        id: sortNotes
    }
    SearchEditor{
        id: searchEditor
    }
}
