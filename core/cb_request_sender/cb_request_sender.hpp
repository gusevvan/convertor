#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>

class CbRequestSender: public QObject {
Q_OBJECT
private:
    QNetworkAccessManager manager;
    QString cbUrl;

public:
    CbRequestSender(QObject* parent = nullptr);

    void setCbUrl(const QString& url);

public slots:
    void sendRequest();
    void handleReply(QNetworkReply* reply);

signals:
    void replyHandled(const QString& answer);
};
