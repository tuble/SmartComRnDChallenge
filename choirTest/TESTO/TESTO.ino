// MASTER

#define MOSI 0
#define CLOCK_OUT 2
#define AUDIO_OUT 3

#define MESSAGE_LENGTH 2
#define NOTE_LENGTH 125

bool start_msg_sent;
bool stop_msg_sent;

void setup() {
  pinMode(MOSI, OUTPUT);
  pinMode(CLOCK_OUT, OUTPUT);
  pinMode(AUDIO_OUT, OUTPUT);
  //  digitalWrite(CLOCK_OUT, HIGH);
  digitalWrite(CLOCK_OUT, LOW);
  start_msg_sent = false;
  stop_msg_sent = false;
  pinMode(1, INPUT);
}

void loop() {
  // send start message
  //  send_start_msg();

  // play note seq
  if (stop_msg_sent == false) {

    play_note(1.6, 64); //////////
    delay(200);

    play_note(0.6, 128);
    delay(50);
    play_note(1.1, 64);
    delay(50);
    play_note(0.6, 128);
    delay(50);
    play_note(1.1, 64);
    delay(50);
    play_note(0.6, 128);
    delay(50);
    play_note(1.1, 64);
    delay(50);


    play_note(1.6, 64); //////////
    delay(100);

    play_note(0.6, 128);
    delay(50);
    play_note(1.1, 64);
    delay(50);
    play_note(0.6, 128);
    play_note(0.6, 128);
    delay(50);
    play_note(1.1, 64);
    delay(200);

    play_note(2.0, 32); //////////
    delay(50);

    play_note(1.2, 64); //////////
    delay(50);
    play_note(1.8, 46); //////////
    delay(50);
    play_note(1.2, 64); //////////
    delay(50);
    play_note(1.8, 46); //////////
    delay(50);
    play_note(1.2, 64); //////////
    delay(50);
    play_note(1.8, 46); //////////
    delay(50);
    play_note(1.2, 64); //////////
    delay(100);
    
    play_note(1.8, 46); //////////
    delay(50);
    play_note(1.1, 64);
    delay(50);
    play_note(1.6, 64); //////////
    delay(50);
    play_note(1.6, 64); //////////
    delay(50);

    play_note(1.8, 46); //////////
    delay(50);
    play_note(2.0, 64); //////////
    delay(50);

    //play_note(0.52, 64); //////////
    //delay(500);

    //    digitalWrite(CLOCK_OUT, HIGH); // prep for stop_msg transmission
  }

  // send stop message
  //  send_stop_msg();
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

void play_note(float half_period, int repetitions) {
  // repetitions = number of periods
  for (int i = 0; i < repetitions; i++) { // AAAAAAa
    digitalWrite(AUDIO_OUT, HIGH);
    delay(half_period * 2); // * 2
    digitalWrite(AUDIO_OUT, LOW);
    delay(half_period * 2);
  }

}
