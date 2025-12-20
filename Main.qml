import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import com.yourapp.notes 1.0
import QtQuick.Effects
Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("Notes")
    property bool isDeleteMode: false
    property bool isAddMode: false
    color: "#F4F6F9"

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
                            gradient: Gradient{
                                GradientStop{
                                    position: 0.0
                                    color: modelData.color
                                }
                                GradientStop{
                                    position: 1.0
                                    color: Qt.darker(modelData.color, 1.4)
                                }
                            }
                            layer.enabled: true
                            layer.effect: MultiEffect{
                                shadowEnabled: true
                                shadowColor: "#90000000"
                                shadowBlur: 1.0
                                shadowVerticalOffset: 4
                                shadowHorizontalOffset: 0
                            }
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

    Rectangle{ //Верхняя область для кнопок
        id: topBar
        height: 95
        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
        }
        color: "white"

        layer.enabled: true
        layer.effect: MultiEffect{
            shadowEnabled: true
            shadowColor: "#20000000"
            shadowBlur: 1.0
            shadowVerticalOffset: 4
            shadowHorizontalOffset: 0
        }
    }

    Rectangle{ //Нижняя область для кнопок
        id: bottomBar
        height: 60
        width: parent.width
        anchors{
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        color: "white"

        layer.enabled: true
        layer.effect: MultiEffect{
            shadowEnabled: true
            shadowColor: "#90000000"
            shadowBlur: 1.0
            shadowVerticalOffset: 4
            shadowHorizontalOffset: 0
        }
    }

    FancyButton{ //Кнопка отмены режима выделения
        id: cancelDeleteModeButton
        visible: isDeleteMode
        height: 25
        width: 25
        radius: 8
        anchors{
            left: topBar.left
            top: topBar.top
            leftMargin: 8
            topMargin: 10
        }
        startColor: "#FFB75E"
        endColor: "#ED8F03"
        onClicked: {
            isDeleteMode = !isDeleteMode
            notesManager.removeAllSelectedNote();
            console.log("Режим удаления выключен")
        }
    }

    FancyButton { //Кнопка добавления заметки в избранное
        id: favouritesButtons
        visible: isDeleteMode
        width: 25
        height: 25
        radius: 8
        anchors {
            right: bottomBar.right
            top: bottomBar.top
            rightMargin: 10
            topMargin: 10
        }
        text: ""
        startColor: "#FF416C"
        endColor: "#FF4B2B"

        onClicked: {
            notesManager.toggleSelectedFavorites();
            isDeleteMode = !isDeleteMode
            notesManager.removeAllSelectedNote()
        }
    }

    FancyButton{ //Кнопка удаления заметки
        id: deleteButtom
        visible: isDeleteMode
        height: 25
        width: 25
        radius: 8
        anchors{
            left: bottomBar.left
            top: bottomBar.top
            leftMargin: 8
            topMargin: 10
        }
        startColor: "#485563"
        endColor: "#29323c"
        text: ""
        onClicked:{
            notesManager.deleteSelectedNotes()
            isDeleteMode = !isDeleteMode
        }
    }

    FancyButton{ //Кнопка добавления заметки
        id: addNotesButton
        width: 55
        height: 55
        radius: 180
        anchors{
            right: parent.right
            bottom: parent.bottom
            rightMargin: 40
            bottomMargin: 90
        }
        startColor: "#667eea"
        endColor: "#764ba2"
        onClicked: {
            editorScreen.currentNote = null;
            if(isDeleteMode){
                isDeleteMode = !isDeleteMode
            }
            editorScreen.dialogController.open();
        }
    }

    FancyButton{ //Кнопка поиска
        id: seacrhButton
        width: 25
        height: 25
        radius: 8
        anchors{
            right: menuButton.left
            top: topBar.top
            rightMargin: 15
            topMargin: 15
        }
        startColor: "#FF9966"
        endColor: "#FF5E62"
        onClicked: searchEditor.searchDialog.open()
    }

    FancyButton{ //Кнопка изменения типов
        id: changeTypeButton
        anchors{
            right: topBar.right
            bottom: topBar.bottom
            rightMargin: 10
            bottomMargin: 13
        }
        width: 87
        height: 30
        startColor: "#E0E0E0"
        endColor: "#E0E0E0"
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
            text: "Изменить"
            font.pixelSize: 12
            color: "black"
        }
        onClicked:{
            editorType.dialogController.open();
        }
    }

    FancyButton{ //Кнопка меню
        id: menuButton
        width: 25
        height: 25
        text: "..."
        radius: 8

        anchors{
            right: topBar.right
            top: topBar.top
            rightMargin: 10
            topMargin: 15
        }

        startColor: "#E0E0E0"
        endColor: "#E0E0E0"

        onClicked: {
            optionMenu.open()
        }
        Menu {
            id: optionMenu
            parent: menuButton

            width: 160

            x: parent.width - width
            y: parent.height + 5

            topPadding: 12
            bottomPadding: 12

            background: Rectangle {
                implicitWidth: 150
                implicitHeight: 40
                color: "white"
                radius: 8
            }

            MenuItem {
                text: "Сортировка"
                height: 30
                anchors{
                    left: parent.left
                    right: parent.right
                    margins: 10
                }
                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 13
                    color: "black"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
                background: Rectangle{
                    color: parent.highlighted ? "#F0F0F0" : "transparent"
                    radius: 8
                }
                onTriggered: sortNotes.sortNotesDialog.open()
            }

            MenuItem {
                text: notesGrid.isGridView ? "Вид: Список" : "Вид: Сетка"
                height: 30
                anchors{
                    left: parent.left
                    right: parent.right
                    margins: 10
                }
                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 13
                    color: "black"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
                background: Rectangle{
                    color: parent.highlighted ? "#F0F0F0" : "transparent"
                    radius: 8
                }
                onTriggered: {
                    notesGrid.timeFlipped = !notesGrid.timeFlipped
                    notesGrid.isGridView = !notesGrid.isGridView
                }
            }

            MenuSeparator {
                contentItem: Rectangle {
                    implicitWidth: parent.width
                    implicitHeight: 1
                    color: "#E0E0E0"
                }
            }

            MenuItem {
                text: isDeleteMode ? "Готово" : "Выбрать"
                height: 30
                anchors{
                    left: parent.left
                    right: parent.right
                    margins: 10
                }
                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 13
                    color: "black"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
                background: Rectangle{
                    color: parent.highlighted ? "#F0F0F0" : "transparent"
                    radius: 8
                }
                onTriggered: {
                    isDeleteMode = !isDeleteMode
                    if(!isDeleteMode) notesManager.removeAllSelectedNote();
                }
            }
        }
    }

    Flickable{ //Список типов заметки
        anchors{
            left: topBar.left
            right: changeTypeButton.left
            bottom: topBar.bottom
            bottomMargin: 13
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

                    gradient: Gradient{
                        orientation: Gradient.Horizontal

                        GradientStop{
                            position: 0.45
                            color: modelData.nameOfColor
                        }
                        GradientStop{
                            position: 1.0
                            color: Qt.darker(modelData.nameOfColor)
                        }
                    }

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
                        font.pixelSize: 12
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
