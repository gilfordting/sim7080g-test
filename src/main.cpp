#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial sim7080g(1);
#define PWRKEY 4
#define RX_PIN 6
#define TX_PIN 7

void power_on_sim7080g() {
    pinMode(PWRKEY, OUTPUT);
    digitalWrite(PWRKEY, LOW);
    delay(1000); // Hold PWRKEY low for 1 second
    digitalWrite(PWRKEY, HIGH);
    delay(5000); // Wait for initialization
}

void setup() {
    Serial.begin(115200);
    sim7080g.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN); // RX, TX
    power_on_sim7080g();

    // Test AT command
    sim7080g.println("AT");
    Serial.println("sent AT command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+CEREG?");
    Serial.println("sent AT+CEREG? command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+CPIN?");
    Serial.println("sent AT+CPIN? command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
    sim7080g.println("AT+CSQ?");
    Serial.println("sent AT+CSQ? command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
    sim7080g.println("AT+CNACT?");
    Serial.println("sent AT+CNACT? command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
    sim7080g.println("AT+CNACT=0,1");
    Serial.println("sent AT+CNACT command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+SHDISC");
    Serial.println("sent AT+SHDISC command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+SHSTATE?");
    Serial.println("sent AT+SHSTATE? command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+SHCONF=\"URL\",\"http://efpi-10.mit.edu\"");
    Serial.println("sent AT+SHCONF command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
    sim7080g.println("AT+SHCONF=\"BODYLEN\", 1024");
    Serial.println("sent AT+SHCONF BODYLEN command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+SHCONF=\"HEADERLEN\", 350");
    Serial.println("sent AT+SHCONF HEADERLEN command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    sim7080g.println("AT+SHCONN");
    Serial.println("sent AT+SHCONN command to sim7080g");
    delay(5000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
}

void loop() {
    // Handle incoming data or other functionalities
    // Test AT command

    // sim7080g.println("AT+SHREQ=\"example.com\", 1");
    // Serial.println("sent AT+SHREQ command to sim7080g");
    // delay(1000);
    // while (sim7080g.available()) {
    //     Serial.write(sim7080g.read());
    // }

    // AT+SHREQ="/request?deviceId=UCFLVA28",3

    sim7080g.println("AT+SHREQ=\"/tunnel_gting/lte_test?num=1\", 2");
    Serial.println("sent AT+SHREQ command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }

    // sim7080g.println("AT+SHREAD=0, 615");
    // Serial.println("sent AT+SHREAD command to sim7080g");
    // delay(1000);
    // while (sim7080g.available()) {
    //     Serial.write(sim7080g.read());
    // }

    // sim7080g.println("AT+SHDISC");
    // Serial.println("sent AT+SHDISC command to sim7080g");
    // delay(1000);
    // while (sim7080g.available()) {
    //     Serial.write(sim7080g.read());
    // }
}