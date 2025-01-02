#include "cb_request_sender.hpp"

CbRequestSender::CbRequestSender(QObject* parent): QObject(parent) {
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleReply(QNetworkReply*)));
}

void CbRequestSender::sendRequest() {
    manager.get(QNetworkRequest(QUrl(cbUrl)));
}

void CbRequestSender::handleReply(QNetworkReply* reply) {
    QString answer;
    if (!reply->error()) {
        answer = reply->readAll();
    }
    emit replyHandled(answer);
}

void CbRequestSender::setCbUrl(const QString& url) {
    cbUrl = url;
}
