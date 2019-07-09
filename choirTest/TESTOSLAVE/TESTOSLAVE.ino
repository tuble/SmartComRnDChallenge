// SLAVE

#define SLAVE_RECEIVE 3
#define CLOCK_IN 2
#define AUDIO_OUT 0

#define MESSAGE_LENGTH 4
#define NOTE_LENGTH 250

//int received_info = 0;
int i = 0;
int sing = 0;

void setup() {
  pinMode(SLAVE_RECEIVE, INPUT);
  pinMode(CLOCK_IN, INPUT);
  pinMode(AUDIO_OUT, OUTPUT);
}

void loop() {

  while (digitalRead(CLOCK_IN)) {
    sing = receive_info();
  }

  while (sing) {
    if (digitalRead(CLOCK_IN)) {
      break;
    }

    play_note(1.5 * 2); // oshte po dobrata
  }
}

int receive_info() { // void receive_info(int bit_position)
  //  sing = digitalRead(SLAVE_RECEIVE);
  return digitalRead(SLAVE_RECEIVE);

}

void play_note(float half_period) {
  digitalWrite(AUDIO_OUT, HIGH);
  delay(half_period);
  digitalWrite(AUDIO_OUT, LOW);
  delay(half_period);
}

//void bin_to_dec(int info_stream[], int len) {
//  for(int i = 0; i < len; i++) {
//
//  }
//
//}
