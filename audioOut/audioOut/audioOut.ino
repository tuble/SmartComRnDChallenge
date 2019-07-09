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

// val for silence 
// 00
// 0.1
// 0.2

// 11|11 - >  3|3 max; 0|0min
//            6.6max; 0.0min


void playNote(float half_period) {

  digitalWrite(audioOut, HIGH);

  delay(half_period * 2); // time in milliseconds

  digitalWrite(audioOut, LOW);

  delay(half_period * 2);

}

//float dec(float playNote){
//
//  float adivel[] = {987.77, 923.33, 880.00, };
//}
