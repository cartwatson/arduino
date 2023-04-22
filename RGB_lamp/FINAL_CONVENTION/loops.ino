//loopRed
void loopRed() {
  //read rotary encoder
  state = digitalRead(outputA);
  if (state != lastState) {
    if (digitalRead(outputB) != state) {
      counterRed--;
    } else {
      counterRed++;
    }
    //write data to pin
    if (counterRed < 0) {
      analogWrite(RED, 0);
    } else if (counterRed > 255) {
      analogWrite(RED, 255);
    } else {
      analogWrite(RED, counterRed);
    }
    //write change to serial monitor
    Serial.print("PositionRED: ");
    Serial.println(counterRed);
    //update lastStateRed
    lastState = state;
  }

  //check for button press
  if (digitalRead(switchEncoder) == LOW) {
    //change state
    red = false;
    blue = false;
    green = true;
    //display change on serial monitor
    Serial.println("STATE CHANGE: GRN");
    //delay to prevent one button press registering as many
    delay(500); //500ms
  }

  //write filler space if needed
  lcd.setCursor(4,0);
  if (counterRed <100){
    lcd.print("0");
    if (counterRed < 10){
      lcd.print("0");
    }
  }

  //write to lcd
  if (counterRed > 0) {
    lcd.print(counterRed);
  } else {
    lcd.print(0);
  }
}


//loop green
void loopGreen() {
  //read rotary encoder
  state = digitalRead(outputA);
  if (state != lastState) {
    if (digitalRead(outputB) != state) {
      counterGreen--;
    } else {
      counterGreen++;
    }
    //write data to pin
    if (counterGreen < 0) {
      analogWrite(GREEN, 0);
    } else if (counterGreen > 255) {
      analogWrite(GREEN, 255);
    } else {
      analogWrite(GREEN, counterGreen);
    }
    //write change to serial monitor
    Serial.print("PositionGRN: ");
    Serial.println(counterGreen);
    //update lastState
    lastState = state;
  }

  //check for button press
  if (digitalRead(switchEncoder) == LOW) {
    //change state
    red = false;
    blue = true;
    green = false;
    //display change on serial monitor
    Serial.println("STATE CHANGE: BLU");
    //delay to prevent one button press registering as many
    delay(500); //500ms
  }

  //write filler space if needed
  lcd.setCursor(12,0);
  if (counterGreen <100){
    lcd.print("0");
    if (counterGreen < 10){
      lcd.print("0");
    }
  }

  //print to lcd
  if (counterGreen > 0) {
    lcd.print(counterGreen);
  } else {
    lcd.print(0);
  }
}

//loop blue
void loopBlue() {
  //read rotary encoder
  state = digitalRead(outputA);
  if (state != lastState) {
    if (digitalRead(outputB) != state) {
      counterBlue--;
    } else {
      counterBlue++;
    }
    //write change to pin
    if (counterBlue < 0) {
      analogWrite(BLUE, 0);
    } else if (counterBlue > 255) {
      analogWrite(BLUE, 255);
    } else {
      analogWrite(BLUE, counterBlue);
    }
    //write change to serial monitor
    Serial.print("PositionBLU: ");
    Serial.println(counterBlue);
    //update lastState
    lastState = state;
  }

  //check for button press
  if (digitalRead(switchEncoder) == LOW) {
    //change state
    red = true;
    blue = false;
    green = false;
    //display change on serial monitor
    Serial.println("STATE CHANGE: RED");
    //delay to prevent one button press registering as many
    delay(500); //500ms
  }

  //write filler space if needed
  lcd.setCursor(4,1);
  if (counterBlue < 100){
    lcd.print("0");
    if (counterBlue < 10){
      lcd.print("0");
    }
  }

  //print to lcd
  if (counterBlue > 0) {
    lcd.print(counterBlue);
  } else {
    lcd.print(0);
  }
}
