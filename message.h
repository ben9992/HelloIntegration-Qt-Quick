#pragma once
#include <QObject>
#include <QString>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    explicit Message(QObject *parent=nullptr);
    QString message() const {return m_message;}
    QString msg() const {return m_message;}
    void setMessage(QString val);
    Q_INVOKABLE int sendMessageFromCpp(const QString val);

public slots:
    void doMessageChange();
signals:
    void messageChanged();

private:

    int m_counter;
    QString m_message;

    explicit Message(const Message& rhs) = delete;
    Message& operator= (const Message& rhs) = delete;
};


