import QtQuick
import QtQuick.Effects
Item {
    id: root
    width: 40
    height: 40

    property string text: ""
    property color startColor: "#00F260"
    property color endColor: "#0575E6"
    property real radius: 8
    property string iconSource: "" // Путь к иконке (по умолчанию пусто)
    property int iconSize: 20      // Размер иконки
     property color iconColor: "white"
    property alias textColor: buttonText.color
    property alias shadowColor: shadowInfo.shadowColor
    signal clicked();

    MultiEffect{
        id: shadowInfo
        source: rectSource
        anchors.fill: rectSource
        shadowEnabled: true
        shadowColor: "#60000000"
        shadowBlur: 0.8
        shadowVerticalOffset: 4
        autoPaddingEnabled: true
    }

    Rectangle{
        id: rectSource
        anchors.fill: parent
        radius: root.radius

        gradient: Gradient{
            GradientStop{position: 0.0; color: mouseArea.pressed ? Qt.darker(root.startColor, 1.1) : root.startColor}
            GradientStop{position: 1.0; color: mouseArea.pressed ? Qt.darker(root.endColor, 1.1) : root.endColor}
        }

        Item{
            anchors.fill: parent
            visible: root.iconSource !== ""

            Image {
                id: iconSrc
                source: root.iconSource
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                visible: root.iconSource !== ""
                mipmap: true
            }

            MultiEffect{
                visible: true
                source: iconSrc
                anchors.fill: parent
                brightness: 1.0
                colorization: 1.0
                colorizationColor: root.iconColor
            }
        }

        Text{
            id: buttonText
            anchors.centerIn: parent
            text: root.text
            color: "black"
            font.bold: true
            font.pixelSize: 12
            visible: root.text !== ""
        }
        scale: MouseArea.pressed ? 0.95 : 1.0
        Behavior on scale{
            NumberAnimation {duration: 100; easing.type: Easing.InOutQuad}
        }
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: root.clicked()
        cursorShape: Qt.PointingHandCursor
    }

}
