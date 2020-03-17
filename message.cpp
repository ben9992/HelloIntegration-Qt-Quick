#include "message.h"
#include <QDebug>

Message::Message(QObject *parent) :
    QObject(parent), m_counter(0), m_message("init")
{
}

int Message::sendMessageFromCpp(const QString val)
{
    qDebug() << "This is cpp Test " << val;
    return m_counter;
}

void Message::doMessageChange()
{
    setMessage("Hello %1");
}

void Message::setMessage(QString val)
{
    m_message = val.arg(++m_counter);
    emit messageChanged();
}
