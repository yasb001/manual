#ifndef SIGNALITEMBEAN_H
#define SIGNALITEMBEAN_H

#include <QObject>

class SignalItemBean : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ord READ ord WRITE setOrd NOTIFY ordChanged)
    Q_PROPERTY(QString deviceName READ deviceName WRITE setDeviceName NOTIFY deviceNameChanged)
    Q_PROPERTY(QString signalName READ signalName WRITE setSignalName NOTIFY signalNameChanged)
    Q_PROPERTY(QString signalMeanning READ signalMeanning WRITE setSignalMeanning NOTIFY signalMeanningChanged)
    Q_PROPERTY(QString signalFrom READ signalFrom WRITE setSignalFrom NOTIFY signalFromChanged)
    Q_PROPERTY(QString signalType READ signalType WRITE setSignalType NOTIFY signalTypeChanged)
    Q_PROPERTY(QString signalConnected READ signalConnected WRITE setSignalConnected NOTIFY signalConnectedChanged)
    Q_PROPERTY(QString signalReason READ signalReason WRITE setSignalReason NOTIFY signalReasonChanged)
    Q_PROPERTY(QString signalHandler READ signalHandler WRITE setSignalHandler NOTIFY signalHandlerChanged)



    QString m_ord;

    QString m_signalHandler;

    QString m_deviceName;

    QString m_signalName;

    QString m_signalMeanning;

    QString m_signalFrom;

    QString m_signalType;

    QString m_signalConnected;

    QString m_signalReason;

public:
    explicit SignalItemBean(QObject *parent = 0);

QString ord() const
{
    return m_ord;
}

QString signalHandler() const
{
    return m_signalHandler;
}

QString deviceName() const
{
    return m_deviceName;
}

QString signalName() const
{
    return m_signalName;
}

QString signalMeanning() const
{
    return m_signalMeanning;
}

QString signalFrom() const
{
    return m_signalFrom;
}

QString signalType() const
{
    return m_signalType;
}

QString signalConnected() const
{
    return m_signalConnected;
}

QString signalReason() const
{
    return m_signalReason;
}

signals:

void ordChanged(QString ord);

void signalHandlerChanged(QString signalHandler);

void deviceNameChanged(QString deviceName);

void signalNameChanged(QString signalName);

void signalMeanningChanged(QString signalMeanning);

void signalFromChanged(QString signalFrom);

void signalTypeChanged(QString signalType);

void signalConnectedChanged(QString signalConnected);

void signalReasonChanged(QString signalReason);

public slots:
void setOrd(QString ord)
{
    if (m_ord == ord)
        return;

    m_ord = ord;
    emit ordChanged(ord);
}
void setSignalHandler(QString signalHandler)
{
    if (m_signalHandler == signalHandler)
        return;

    m_signalHandler = signalHandler;
    emit signalHandlerChanged(signalHandler);
}
void setDeviceName(QString deviceName)
{
    if (m_deviceName == deviceName)
        return;

    m_deviceName = deviceName;
    emit deviceNameChanged(deviceName);
}
void setSignalName(QString signalName)
{
    if (m_signalName == signalName)
        return;

    m_signalName = signalName;
    emit signalNameChanged(signalName);
}
void setSignalMeanning(QString signalMeanning)
{
    if (m_signalMeanning == signalMeanning)
        return;

    m_signalMeanning = signalMeanning;
    emit signalMeanningChanged(signalMeanning);
}
void setSignalFrom(QString signalFrom)
{
    if (m_signalFrom == signalFrom)
        return;

    m_signalFrom = signalFrom;
    emit signalFromChanged(signalFrom);
}
void setSignalType(QString signalType)
{
    if (m_signalType == signalType)
        return;

    m_signalType = signalType;
    emit signalTypeChanged(signalType);
}
void setSignalConnected(QString signalConnected)
{
    if (m_signalConnected == signalConnected)
        return;

    m_signalConnected = signalConnected;
    emit signalConnectedChanged(signalConnected);
}
void setSignalReason(QString signalReason)
{
    if (m_signalReason == signalReason)
        return;

    m_signalReason = signalReason;
    emit signalReasonChanged(signalReason);
}
};

#endif // SIGNALITEMBEAN_H
