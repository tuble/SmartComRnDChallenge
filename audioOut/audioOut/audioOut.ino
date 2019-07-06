// one pin audio out
// the rest -> led indication

#define audioOut 2
#define noteLength 250
void setup() {

  pinMode(audioOut, OUTPUT);

}

void loop() {

  for (int i = 0; i < noteLength; i++) {

    playNote(1.9); // C

  }

}

void playNote(float time_state) {

  digitalWrite(audioOut, HIGH);

  delay(time_state); // time in milliseconds

  digitalWrite(audioOut, LOW);

  delay(time_state);

}
