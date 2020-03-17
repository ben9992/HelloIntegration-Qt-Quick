#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaObject>
#include <QDebug>
#include "message.h"

void TestInvoke(QObject* rootObj){
    QVariant return_val;
    QVariant msg = " %%c++ param%% ";
    QMetaObject::invokeMethod(rootObj, "jsFunc", Q_RETURN_ARG(QVariant, return_val), Q_ARG(QVariant, msg));
    qDebug() << "QML res " << return_val;
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Message my_msg;
    auto root_context = engine.rootContext();
    root_context->setContextProperty("messageClass", &my_msg);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    auto root_obj = engine.rootObjects().first();
    TestInvoke(root_obj);

    return app.exec();
}
