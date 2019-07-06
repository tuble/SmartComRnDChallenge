// MASTER

// I2S !!!!!!!!! LIB

#define MOSI 0
#define CLOCK_OUT 2

// MOSI -> TP4 (0 TO 3) bqla jica
// CLK -> CLK (2 TO 2) cherna jica
// COMMON GND & VCC

int i = 0;

int info[] = {1, 0, 1, 0};

void setup() {

  pinMode(MOSI, OUTPUT);
  pinMode(CLOCK_OUT, OUTPUT);
  digitalWrite(CLOCK_OUT, HIGH);

}

void loop() {

  // def a signal send window

  while (digitalRead(CLOCK_OUT)) {
    send_4_bits();
    digitalWrite(CLOCK_OUT, LOW);
  }


}

void send_4_bits() {

  for (int i = 0; i < 4; i++) {
    digitalWrite(MOSI, info[i]);
    delay(250);
  }

}
