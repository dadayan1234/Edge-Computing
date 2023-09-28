int sw = 6;
int bt = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int pressed = 0;
int alert_state = 0;

void press() {
  alert_state += 1;
  if (alert_state > 1){
    alert_state = 0;
  }
  if (alert_state == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      pressed = 0;
  }
  else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
  }
}

void setup() {
  pinMode(sw, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(bt), press, RISING);
}

void loop() {
  
  if (digitalRead(sw) == HIGH) {
    pressed+=1;
    Serial.println(pressed);
    if (pressed > 3) {
      pressed = 0;
    }

    if (pressed == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW); 
    }
    else if (pressed == 2){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW); 
    }
    else if (pressed == 3){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH); 
    }
    else if (pressed == 0){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW); 
    }
    delay(1000);
  }
}
