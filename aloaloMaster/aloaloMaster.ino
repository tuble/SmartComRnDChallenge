// MASTER

// I2S !!!!!!!!! LIB

#define MOSI 0
#define CLOCK_OUT 2
#define AUDIO_OUT 3

#define MESSAGE_LENGTH 2
#define NOTE_LENGTH 250

// MOSI -> TP4 (0 TO 3) bqla jica
// CLK -> CLK (2 TO 2) cherna jica
// COMMON GND & VCC ... only common GND is needed?

bool msg_sent;

int info[MESSAGE_LENGTH] = {1, 0, 1, 0};

void setup() {
  pinMode(MOSI, OUTPUT);
  pinMode(CLOCK_OUT, OUTPUT);
  pinMode(AUDIO_OUT, OUTPUT);
  digitalWrite(CLOCK_OUT, HIGH);
  msg_sent = false;
}

void loop() {
  // send message
  while (digitalRead(CLOCK_OUT) == 1 && msg_sent == false) {
    send_bits();
    digitalWrite(CLOCK_OUT, LOW); // stop msg transmission
    msg_sent = true;
  }

  // play note sequence
  play_note(1);
  delay(NOTE_LENGTH);
//  play_note(1);
//  delay(NOTE_LENGTH);
}

void send_bits() {
  for (int i = 0; i < MESSAGE_LENGTH; i++) {
    digitalWrite(MOSI, info[i]);
    delay(250);
  }
}

void play_note(float half_period) {
  digitalWrite(AUDIO_OUT, HIGH);
  delay(half_period * 2);
  digitalWrite(AUDIO_OUT, LOW);
  delay(half_period * 2);
}
