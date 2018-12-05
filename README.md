# Анатомия автозапуска 7.0
Anatomy of autorun 7.0

MQTT broker
https://www.cloudmqtt.com

http://flyhub.org

******

MQTT apps on Android

[MQTT Dash Google Play](https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=ru) recommend

[IoT MQTT Panel](https://play.google.com/store/apps/details?id=snr.lab.iotmqttpanel.prod)

[IoT MQTT Dashboard](https://play.google.com/store/apps/details?id=com.thn.iotmqttdashboard)

[Linear MQTT Dashboard](https://play.google.com/store/apps/details?id=com.ravendmaster.linearmqttdashboard)


***
Cloudmqtt.com > Log in> + Create Nwe Intance > 

**Name:** any name

**Plan:** Cute Cat(Free)

**Tags:** any name

**Data center:** EU-West-1 (Ireland) > Confirm > Create Nwe Intance

Details - Instance info - Copy: Server, User, Password and Port

********

Mqtt dash > Seting - Insert server settings: Server, User, Password and Port

Mqtt dash > Импорт/экспорт метрик: > ПОДПИСАТЬСЯ и ЖДАТЬ МЕТРИКИ.

*****

***Daschbord*** 

Cloudmqtt.com > Log in> WEBSOCKET UI > Websocket -Send message 

**Topic** metrics/exchange

**Message** >  https://raw.githubusercontent.com/martinhol221/SIIM800C_ESP8266/master/daschbord.txt
