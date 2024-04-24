#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include "esp_http_client.h"
#include "esp_log.h"

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    bool post(const std::string& url, const std::string& payload);

private:
    
};

#endif // HTTP_CLIENT_H