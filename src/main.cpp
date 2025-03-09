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

    // Send SMS
    // sim7080g.println("AT+CMGF=1"); // Set SMS to text mode
    // delay(1000);
    // sim7080g.println(
    //     "AT+CMGS=\"+1234567890\""); // Replace with recipient's number
    // delay(1000);
    // sim7080g.print("Hello from SIM7080G");
    // sim7080g.write(26); // CTRL+Z to send SMS
    // delay(5000);
}

void loop() {
    // Handle incoming data or other functionalities
    // Test AT command
    sim7080g.println("AT");
    Serial.println("sent AT command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
    sim7080g.println("AT");
    Serial.println("sent AT command to sim7080g");
    delay(1000);
    while (sim7080g.available()) {
        Serial.write(sim7080g.read());
    }
}