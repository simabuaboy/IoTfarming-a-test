#ifndef NTP_H
#define NTP_H

#include <esp_log.h>
#include <esp_sntp.h>
#include <string>

class NtpClient {
public:
    NtpClient();
    ~NtpClient();
    std::string getTime();

private:
    static const char* TAG;
    void initializeSntp();
    void deinitializeSntp();
};


#endif 