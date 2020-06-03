#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DallasTemperature.h> 
WiFiClient client;
ADC_MODE(ADC_VCC);
#define ONE_WIRE_BUS 0             // GPIO2 (ESP8266) > DATA (DS18B20)
#define PIN_POWER_DS 5             // GPIO5 (ESP8266) > VCC  (DS18B20)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int count, inDS = 5;               // Количество датчиков на шине
int sleep = 300;                   // Время сна секндах
const char *ssid = "Gateway";      // SSID шлюза (платы анатомия автозапуска 7.3)
const char *pass = "martinhol221"; // Пароль шлюза 
String host = "192.168.4.1";

void setup() {
bool pin4 = digitalRead(4);
pinMode(PIN_POWER_DS, OUTPUT); digitalWrite(PIN_POWER_DS, HIGH); 
Serial.begin(115200), Serial.println(), Serial.println();
Serial.print("https://github.com/martinhol221/ESP-8266 | esp"), Serial.println(ESP.getChipId());
Serial.print("Conecting to: SSID:"), Serial.print(ssid); Serial.print(" | PASS:"), Serial.println(pass);
WiFi.mode(WIFI_STA); WiFi.begin(ssid, pass);



while (WiFi.status() != WL_CONNECTED) {count++, delay(500),  Serial.print("#");
                                       if (count > 40) Serial.println("DeepSleep 10 min"), delay(1000), ESP.deepSleep(10*60*1000000);}
Serial.print(" - > IP:"), Serial.println(WiFi.localIP());

if (pin4 != 0) ds18b20_get();
//SMS_get("375291234567", "Privet.%20Srabotal%20datchik!"); // отправка SMS на латинице c заменой пробела на %20
//Call_get("375291234567");                                 // звонок на номер
if (pin4 == 0) program_get(6);                              // запуск программы №

Serial.println("Uptime: "+String(millis())+" millisec.");
Serial.println("DeepSleep "+String(sleep)+" sec."); delay(100), ESP.deepSleep(sleep*1000000);
}


void ds18b20_get() {
String buf = String(ESP.getChipId())+"&rssi="+String(WiFi.RSSI())+"&adc="+String(ESP.getVcc());
sensors.begin(); delay(1000); 
sensors.requestTemperatures();
for (int x=0; x < inDS; x++) buf +="&temp"+String(x)+"=" + String(sensors.getTempCByIndex(x));
get_reqest("GET /esp?id="+buf);}

void program_get(int program)              {get_reqest("GET /set?PROG="+String(program));}  
void Call_get(String phone)                {get_reqest("GET /set?AT_CMD=ATD%2B"+phone+"%3B");}
void SMS_get(String phone, String smsText) {get_reqest("GET /sms?sms_phone=%2B"+phone+"&sms_text="+smsText);}

void get_reqest(String url)     { 
    if (client.connect(host, 80)) {
                                  String buf = url+" HTTP/1.1\r\nHost: "+host+"\r\nConnection: close\r\n\r\n";
                                  client.println(buf); Serial.println(buf);
                                  } else Serial.println("Хост: "+host+" недоступен"); 
                                }


void loop() {
            }
