#include "NtpClient.h"

const char *NtpClient::TAG = "NtpClient";

NtpClient::NtpClient()
{
    initializeSntp();
}

NtpClient::~NtpClient()
{
    deinitializeSntp();
}

std::string NtpClient::getTime()
{
    ESP_LOGI(TAG, "Setting timezone to Jakarta (WIB)");
    setenv("TZ", "WIB-7", 1);
    tzset();

    time_t now = 0;
    struct tm timeinfo = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int retry = 0;
    const int retry_count = 10;
    while (timeinfo.tm_year < (2016 - 1900) && ++retry < retry_count)
    {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        time(&now);
        localtime_r(&now, &timeinfo);
    }

    if (retry < retry_count)
    {
        ESP_LOGI(TAG, "Time obtained: %s", asctime(&timeinfo));
    }
    else
    {
        ESP_LOGE(TAG, "Failed to obtain time!");
    }

    std::string timeString = asctime(&timeinfo);
    return timeString;

}

void NtpClient::initializeSntp()
{
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
}

void NtpClient::deinitializeSntp()
{
    ESP_LOGI(TAG, "Deinitializing SNTP");
    sntp_stop();
}
