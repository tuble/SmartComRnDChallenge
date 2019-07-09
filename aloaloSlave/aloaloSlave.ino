// SLAVE

#define SLAVE_RECEIVE 3
#define CLOCK_IN 2
#define LED4 0
#define MESSAGE_LENGTH 4


int received_info[MESSAGE_LENGTH] = {};
int i = 0;

bool receiveing = 0;

void setup() {

  pinMode(SLAVE_RECEIVE, INPUT);
  //  pinMode(CLOCK_IN, INPUT);

}

void loop() {

  // handling message reception
  // LSB first
  ]
  if (digitalRead(CLOCK_IN)) {
    receiveing = 1;
  } else {
    receiveing = 0;
    i = 0;
  }

  while (receiveing == 1) {
    receive_info(); // pass in msg bit position
  }

  // * test 

  // play note sequence

  
}

void receive_info() { // void receive_info(int bit_position)

  received_info[i] = digitalRead(SLAVE_RECEIVE);
  digitalWrite(LED4, received_info[i]);
  i += 1;

}
