// SLAVE

#define SLAVE_RECEIVE 3
#define CLOCK_IN 2
#define AUDIO_OUT 0

#define MESSAGE_LENGTH 4
#define NOTE_LENGTH 250

//int received_info = 0;

bool sing = false;

void setup() {
  pinMode(SLAVE_RECEIVE, INPUT);
  pinMode(CLOCK_IN, INPUT);
  pinMode(AUDIO_OUT, OUTPUT);
  pinMode(1, INPUT);
  //  digitalWrite(1, LOW);
}

void loop() {

  // get info from master, while CLOCK_IN = HIGH
  while (digitalRead(CLOCK_IN) == HIGH) {
    int i = receive_info();
    if (i == 1) {
      sing = true;
    } else {
      sing = false;
    }

  }

  // if CLOCK_IN = LOW, slave is not receiveing => play note

  while (sing == true) { // sing, if "told" by master to sing
    if (digitalRead(CLOCK_IN) == HIGH) { // exit if clock is HIGH
      break;
    }
    play_note(1.5 * 2);
    play_note(3.3 * 2);
    play_note(1.5 * 2);
    play_note(3.3 * 2);
   
    //    digitalWrite(AUDIO_OUT, HIGH);
    //    delay(50);
    //    digitalWrite(AUDIO_OUT, LOW);
    //    delay(50);
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
