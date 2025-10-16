#include <WiFi.h>
#include <esp_wifi.h>

void readMacAddress() {
    uint8_t baseMac[6];
    if (esp_wifi_get_mac(WIFI_IF_STA, baseMac) == ESP_OK) {
        Serial.printf("ESP32 MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            baseMac[0], baseMac[1], baseMac[2],
            baseMac[3], baseMac[4], baseMac[5]);
    } else {
        Serial.println("Failed to read MAC address");
    }
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);  // Hanya perlu mode STA
    readMacAddress();
}

void loop() {
    
}

