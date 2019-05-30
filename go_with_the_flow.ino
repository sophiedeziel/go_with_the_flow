#include <TM1637Display.h>

#define METER_PIN 2
#define DIO_PIN 5
#define CLK_PIN 4

volatile int pulses = 0;

TM1637Display display_liters(CLK_PIN, DIO_PIN);

void setup() {
  pinMode(METER_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(METER_PIN), countPulses, RISING);
  Serial.begin(115200);
  display_liters.setBrightness(0x0a);
}

void loop() {
  double centiliters = pulses / 4.5;
  display_liters.showNumberDecEx(centiliters, 0b01000000);
}

void countPulses() {
  pulses++;
}
