SSID: Webasto_XXXXXXX (10 min.)
PASS: martinhol221

ESP-12E OR ESP-12F
ADDR: 0x00000

На устройствах на плате 7.0 распиновка реле:
1-Wire - GPIO0
KEY- GPIO2
IN1- GPIO13  
IN2- GPIO12 
K1-  GPIO14  
K2-  GPIO5  
K3-  GPIO4  
K4-  GPIO15  
K5-  GPIO16  

На устройствах на плате 7.1 и выше распиновка реле:

1-Wire - GPIO0
KEY- GPIO2
IN1- GPIO13  
IN2- GPIO12  
K1 - GPIO14  
K2 - GPIO16  
K3 - GPIO5  
K4 - GPIO4  
K5 - GPIO15  

На всех прошивках с 2019 г стокрость модема 57600 бод, переключается командой AT+IPR=57600;&W

2018.12.27.bin - устарела работала на скорости 9600, для перехода на нее нужно использовать команду AT+IPR=9600;&W

2019.03.19 - добавлена охранная функция


