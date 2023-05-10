#include "WiFiProv.h"
#include "WiFi.h"
#include "nvs_flash.h"
#include "nvs.h"

/**
 * =============================================
 * Deploy the Fleet BLE Provisioning Example App
 * =============================================
 * 
 * This is a bare bones example of how to use the BLE Provisioning flow to provision
 * Wi-Fi credentials to an ESP32 device. Simply modify the loop() function below as
 * you normally would for your application.
*/

bool is_provisioned = false;
void SysProvEvent(arduino_event_t *sys_event)
{
    switch (sys_event->event_id)
    {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
        Serial.print("\nConnected IP address : ");
        Serial.println(IPAddress(sys_event->event_info.got_ip.ip_info.ip.addr));
        is_provisioned = true;
        break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
        Serial.println("\nDisconnected. Connecting to the AP again... ");
        break;
    case ARDUINO_EVENT_PROV_START:
        Serial.println("\nProvisioning started\nGive Credentials of your access point using the Espressif BLE Provisioning App");
        break;
    case ARDUINO_EVENT_PROV_CRED_RECV:
    {
        Serial.println("\nReceived Wi-Fi credentials");
        Serial.print("\tSSID : ");
        Serial.println((const char *)sys_event->event_info.prov_cred_recv.ssid);
        Serial.print("\tPassword : ");
        Serial.println((char const *)sys_event->event_info.prov_cred_recv.password);
        break;
    }
    case ARDUINO_EVENT_PROV_CRED_FAIL:
    {
        Serial.println("\nProvisioning failed!\nPlease reset to factory and retry provisioning\n");
        if (sys_event->event_info.prov_fail_reason == WIFI_PROV_STA_AUTH_ERROR)
            Serial.println("\nWi-Fi AP password incorrect");
        else
            Serial.println("\nWi-Fi AP not found....Add API \" nvs_flash_erase() \" before beginProvision()");
        break;
    }
    case ARDUINO_EVENT_PROV_CRED_SUCCESS:
        Serial.println("\nProvisioning Successful");
        break;
    case ARDUINO_EVENT_PROV_END:
        Serial.println("\nProvisioning Ends");
        break;
    default:
        break;
    }
}

void setup()
{
    Serial.begin(115200);
    WiFi.onEvent(SysProvEvent);
    // TODO: change the PIN and device prefix here to suite your needs. The last two parameters are
    // used in the provisioning app.
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM, WIFI_PROV_SECURITY_1, "abcd1234", "PROV_DTF");
}

void loop()
{
    if(is_provisioned)
    {
        // REPLACE THIS WITH YOUR CODE
        // This code will run every time through the loop() function when provisioned. This is
        // where you would put your normal Arduino loop() logic.
        Serial.println("Connected to Wi-Fi and ready to run main application");
        delay(5000);
    }
    else
    {
        // REPLACE THIS WITH YOUR CODE
        // This code will run every time through the loop() function while waiting for credentials
        // It could be left off or used as shown to print a message to the serial monitor.
        Serial.println("Waiting for Wi-Fi credentials. Open app to get started.");
        delay(5000);
    }
}