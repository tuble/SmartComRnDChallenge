// SLAVE

#define SLAVE_RECEIVE 3
#define CLOCK_IN 2
#define AUDIO_OUT 0

#define MESSAGE_LENGTH 4
#define NOTE_LENGTH 250

//int received_info = 0;

bool sing;
int i;

void setup() {
  pinMode(SLAVE_RECEIVE, INPUT);
  pinMode(CLOCK_IN, INPUT);
  pinMode(AUDIO_OUT, OUTPUT);
  pinMode(1, INPUT);
  sing = false;
  i = 0;
}

void loop() {

  // get info from master, while CLOCK_IN = HIGH
  while (digitalRead(CLOCK_IN) == HIGH) {
    //    i = receive_info();
    if (receive_info() == HIGH) { // b o z a
      sing = true;
    } else {
      sing = false;
    }
  }

  if (sing == true) {
    play_note(1.6, 64); //////////
    delay(200);

    play_note(0.6, 128);
    delay(50);
  }
}

int receive_info() { // void receive_info(int bit_position)
  return digitalRead(SLAVE_RECEIVE);
}

void play_note(float half_period, int repetitions) {
  // repetitions = number of periods
  for (int i = 0; i < repetitions; i++) {
    digitalWrite(AUDIO_OUT, HIGH);
    delay(half_period * 2); // * 2
    digitalWrite(AUDIO_OUT, LOW);
    delay(half_period * 2);
  }

}
