## Informationen:

Diese CAN-Library dient zum Programmieren von CAN-Bus Controllern für Ladegeräte von TCCharger oder auch andere. Der dafür notwendige Code findet sich im Repository "TCCharger voltage & current control".

## Benötigte Hardware:

Statt eines Arduino Nano kann auch ein beliebiger anderer Arduino mit SPI-Schnittstelle verwendet werden, z.B. Pro Mini, Uno oder Mega2560. Bestellung am besten bei Amazon oder Banggood, dort gibt es auch gute Starterkits und Zubehör. 

Die CAN-Bus Interfaces solltet ihr besser nicht woanders bestellen, ich habe oft fehlerhafte bekommen. Mit dem Lieferanten auf Amazon habe ich ausschließlich gute Erfahrungen gemacht. Es schadet auch nicht einen in Reserve zu haben falls ihr mal einen zerschießt.

Arduino Nano:
https://www.amazon.de/Elegoo-Entwicklerboard-Arduino-Atmega328P-CH340/dp/B0713ZRJLC/

oder:
https://www.banggood.com/3Pcs-ATmega328P-Nano-V3-Controller-Board-Compatible-Arduino-Improved-Version-p-983486.html

CAN-Bus Interfaces:
https://www.amazon.de/gp/product/B01IV3ZSKO

Zusätzlich wird folgendes benötigt:
-Lötkolben
-dünne Kabel

## Installation:

Die gesamte Library im .zip Format herunterladen und in die Arduino IDE importieren.

## Verwendung:

Am besten in die Beispiele schauen. Die Datei "Einstiegsbeispiel" enthält alle wichtigen Funktionen mit Beschreibungen.

## Nützliche Tutorials:

https://www.youtube.com/watch?v=cKf3MwjL2fc
https://www.youtube.com/watch?v=ZHaxv-cGZFI

## English description from Seeed-Studio

### 1. Set the BaudRate

This function is used to initialize the baudrate of the CAN Bus system.

The available baudrates are listed as follows:

	#define CAN_5KBPS    1
	#define CAN_10KBPS   2
	#define CAN_20KBPS   3
	#define CAN_25KBPS   4 
	#define CAN_31K25BPS 5
	#define CAN_33KBPS   6
	#define CAN_40KBPS   7
	#define CAN_50KBPS   8
	#define CAN_80KBPS   9
	#define CAN_83K3BPS  10
	#define CAN_95KBPS   11
	#define CAN_100KBPS  12
	#define CAN_125KBPS  13
	#define CAN_200KBPS  14
	#define CAN_250KBPS  15
	#define CAN_500KBPS  16
	#define CAN_666kbps  17
	#define CAN_1000KBPS 18


### 2. Set Receive Mask and Filter

There are 2 receive mask registers and 5 filter registers on the controller chip that guarantee you get data from the target device. They are useful especially in a large network consisting of numerous nodes.

We provide two functions for you to utilize these mask and filter registers. They are:

    init_Mask(unsigned char num, unsigned char ext, unsigned char ulData);
    init_Filt(unsigned char num, unsigned char ext, unsigned char ulData);

**num** represents which register to use. You can fill 0 or 1 for mask and 0 to 5 for filter.

**ext** represents the status of the frame. 0 means it's a mask or filter for a standard frame. 1 means it's for a extended frame.

**ulData** represents the content of the mask of filter.



### 3. Check Receive
The MCP2515 can operate in either a polled mode, where the software checks for a received frame, or using additional pins to signal that a frame has been received or transmit completed.  Use the following function to poll for received frames.

    INT8U MCP_CAN::checkReceive(void);

The function will return 1 if a frame arrives, and 0 if nothing arrives.



### 4. Get CAN ID

When some data arrives, you can use the following function to get the CAN ID of the "send" node.

    INT32U MCP_CAN::getCanId(void);



### 5. Send Data

    CAN.sendMsgBuf(INT32U id, INT8U ext, INT8U len, INT8U *buf);

This is a function to send data onto the bus. In which:

**id** represents where the data come from.

**ext** represents the status of the frame. '0' means standard frame. '1' means extended frame.

**len** represents the length of this frame.

**buf** is the content of this message.

For example, In the 'send' example, we have:

```
unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

CAN.sendMsgBuf(0x00, 0, 8, stmp); //send out the message 'stmp' to the bus and tell other devices this is a standard frame from 0x00.
```



### 6. Receive Data

The following function is used to receive data on the 'receive' node:

    CAN.readMsgBuf(INT8U *len, INT8U *buf);

Under the condition that masks and filters have been set, this function will only get frames that meet the requirements of those masks and filters.

**len** represents the data length.

**buf** is where you store the data.


### 7. Check additional flags

When frame is received you may check whether it was remote request and whether it was an extended (29bit) frame.

    CAN.isRemoteRequest();
    CAN.isExtendedFrame();

**return value** is '0' for a negative response and '1' for a positive


<br>

For more information, please refer to [wiki page](http://www.seeedstudio.com/wiki/CAN-BUS_Shield).

    
----

This software is written by loovee ([luweicong@seeed.cc](luweicong@seeed.cc "luweicong@seeed.cc")) for seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>


[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/CAN_BUS_Shield)](https://github.com/igrigorik/ga-beacon)

