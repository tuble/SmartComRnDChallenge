// MASTER

#define MOSI 0
#define CLOCK_OUT 2
#define AUDIO_OUT 3

#define MESSAGE_LENGTH 2
#define NOTE_LENGTH 500

bool start_msg_sent;
bool stop_msg_sent;

void setup() {
  pinMode(MOSI, OUTPUT);
  pinMode(CLOCK_OUT, OUTPUT);
  pinMode(AUDIO_OUT, OUTPUT);
  digitalWrite(CLOCK_OUT, HIGH);
  start_msg_sent = false;
  stop_msg_sent = false;
  pinMode(1, INPUT);
}

void loop() {
  // send start message
  send_start_msg();

  // play note
  if (stop_msg_sent == false) {
    for (int i = 0; i < NOTE_LENGTH; i++ ) {
      play_note(1.5);
      //      digitalWrite(AUDIO_OUT, HIGH);
      //      delay(50);
      //      digitalWrite(AUDIO_OUT, LOW);
      //      delay(50);
    }
    digitalWrite(CLOCK_OUT, HIGH); // prep for stop_msg transmission
  }

  // send stop message
  send_stop_msg();
}

void send_start_msg() {
  while (digitalRead(CLOCK_OUT) == HIGH && start_msg_sent == false) {
    send_info(1);
    delay(125);
    digitalWrite(CLOCK_OUT, LOW); // stop msg transmission
    start_msg_sent = true;
  }
}

void send_stop_msg() {
  while (digitalRead(CLOCK_OUT) == HIGH && stop_msg_sent == false) {
    send_info(0);
    delay(125);
    digitalWrite(CLOCK_OUT, LOW); // stop msg transmission
    stop_msg_sent = true;
  }
}

void send_info(int info) {
  digitalWrite(MOSI, info);
}

void play_note(float half_period) {
  digitalWrite(AUDIO_OUT, HIGH);
  delay(half_period); // * 2
  digitalWrite(AUDIO_OUT, LOW);
  delay(half_period);
}
