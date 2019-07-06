// SLAVE

#define SLAVE_RECEIVE 3
#define CLOCK_IN 2
#define LED4 0

int received_info = 0; // to arr 
// then arr to value


void setup() {

  pinMode(SLAVE_RECEIVE, INPUT);
  //  pinMode(CLOCK_IN, INPUT);

}

void loop() {

  while (digitalRead(CLOCK_IN)) {
    receive_info();
  }



}

void receive_info() {
  received_info = digitalRead(SLAVE_RECEIVE);
  digitalWrite(LED4, received_info);
}
