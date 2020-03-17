import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    function jsFunc(val)
    {
        print("C++ called this func with param " + val);
        return "this msg is the return msg from jsFunc";
    }

    Column{
        Text{
            id:textId
            text : messageClass.message
        }
        Button{
            text: "Change Text"
            onClicked: messageClass.doMessageChange()

        }

        Button{
            text: "Talk to C++"
            onClicked: {
                var res;
                 res = messageClass.sendMessageFromCpp("this is msg from qml")
                print (res);
            }

        }
    }

}
