//Code by Lennart O.

//Bibliotheken einbinden

#include <mcp_can.h> 
#include <SPI.h>

//Konstanten und Variablen deklarieren

#define SPI_CS_PIN 10 //CS Pin

unsigned long int sendId = 0x1806E5F4;
unsigned char data[8] = {highByte(outputvoltage), lowByte(outputvoltage), highByte(outputcurrent), lowByte(outputcurrent), 0x00,0x00,0x00,0x00};

unsigned char len = 0; //Länge emfpangener CAN Nachricht
unsigned char buf[8]; //Buffer für Daten aus CAN Nachricht
unsigned long int receiveId; //ID des Senders

//Objekt deklarieren

MCP_CAN CAN(SPI_CS_PIN); //CS Pin für SPI setzen

//Funktionen

void setup() {

  Serial.begin(115200); //Serielle Schnittstelle zur Diagnose starten

  while(CAN_OK != CAN.begin(CAN_250KBPS, MCP_8MHz)){ //CAN Bus initialisieren, Bitrate und Schwingfrequenz der Quarzes auf dem CAN-Interface angeben

    Serial.println("CAN Initialisierung fehlgeschlagen, Neustart");
    delay(200);

  }

  Serial.println("CAN Initialisierung erfolgreich");
  
}



void loop() {

//Daten lesen

if(CAN_MSGAVAIL == CAN.checkReceive()){ //auf Nachrichten prüfen

    CAN.readMsgBuf(&len, buf); //Daten lesen, len: Datenlänge, buf: Daten

    receiveId = CAN.getCanId(); // CAN-ID lesen
    
      Serial.print("CAN ID: ");
      Serial.print(receiveId, HEX); //ID ausgeben

      Serial.print(" / CAN Daten: ");
      for(int i = 0; i<len; i++){ //Daten ausgeben

        if( buf[i] < 0x10){ // führende Null wenn nur eine Ziffer
          Serial.print("0");
        }

        Serial.print(buf[i],HEX);
        Serial.print(" ");          // Leerzeichen

      }

      Serial.println(); //Absatz

      }
      
   
  
  //Daten senden

  byte sndStat = CAN.sendMsgBuf(sendId, 1, 8, data); //Nachricht senden (ID, Extended Frame, Datenlänge, Daten)

    if(sndStat == CAN_OK) //Statusbyte für Übertragung
     Serial.println("CAN Nachricht erfolgreich gesendet");
    else
     Serial.println("Fehler bei Nachrichtenübertragung");
     
  delay(500); //kurze Pause

}
