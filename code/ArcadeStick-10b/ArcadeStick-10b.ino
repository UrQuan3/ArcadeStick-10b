// 10 button arcade stick
// Brian Harrison
//
// Adapted from ArcadeStick-8b-V1  This program is for reading the inputs from a 10 button 
// arcade stick and transmitting the commands to a Windows or Linux computer via USB.
// Supports a single digital stick and 10 buttons (8P + start(P9) and coin(P10)).

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);   //up
  pinMode(1, INPUT_PULLUP);   //right
  pinMode(2, INPUT_PULLUP);   //down
  pinMode(3, INPUT_PULLUP);   //left
  pinMode(4, INPUT_PULLUP);   //button 1
  pinMode(5, INPUT_PULLUP);   //button 2
  pinMode(6, INPUT_PULLUP);   //button 3
  pinMode(7, INPUT_PULLUP);   //button 4
  pinMode(8, INPUT_PULLUP);   //button 5
  pinMode(9, INPUT_PULLUP);   //button 6
  pinMode(10, INPUT_PULLUP);  //button 7
  pinMode(11, INPUT_PULLUP);  //button 8
  pinMode(13, OUTPUT);
  pinMode(14, INPUT_PULLUP);  //button 9  (start)
  pinMode(15, INPUT_PULLUP);  //button 10 (select/insert coin)
  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int joystat;
  bool pinstat00, pinstat01, pinstat02, pinstat03/*, pinstat04, pinstat05,
       pinstat06, pinstat07, pinstat08, pinstat09, pinstat10, pinstat11*/;
  
  joystat = 0;
  pinstat00 = digitalRead(0);   //up
  pinstat01 = digitalRead(1);   //right
  pinstat02 = digitalRead(2);   //down
  pinstat03 = digitalRead(3);   //left
  /*pinstat04 = digitalRead(4);
  pinstat05 = digitalRead(5);
  pinstat06 = digitalRead(6);
  pinstat07 = digitalRead(7);
  pinstat08 = digitalRead(8);
  pinstat09 = digitalRead(9);
  pinstat10 = digitalRead(10);
  pinstat11 = digitalRead(11);*/

  //Joystick Read
  joystat = !pinstat03;
  joystat = joystat << 1;
  joystat = joystat + !pinstat02;
  joystat = joystat << 1;
  joystat = joystat + !pinstat01;
  joystat = joystat << 1;
  joystat = joystat + !pinstat00;
  //digitalWrite(13, HIGH);		//Uncomment for debugging hand-wired joysticks
  switch (joystat) {
    case 0x0:
      Joystick.hat(-1);
      break;
    case 0x1:
      Joystick.hat(0);
      break;
    case 0x2:
      Joystick.hat(90);
      break;
    case 0x3:
      Joystick.hat(45);
      break;
    case 0x4:
      Joystick.hat(180);
      break;
    case 0x5:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    case 0x6:
      Joystick.hat(135);
      break;
    case 0x7:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    case 0x8:
      Joystick.hat(270);
      break;
    case 0x9:
      Joystick.hat(315);
      break;
    case 0xA:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    case 0xB:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    case 0xC:
      Joystick.hat(225);
      break;
    case 0xD:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    case 0xE:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    case 0xF:
      Joystick.hat(-1);   //INVALID
      digitalWrite(13, LOW);
      break;
    default:
      break;
  }

  //Button Read
  //All buttons are active low, so invert readings
  if(digitalRead(4)) {
    Joystick.button(1, 0);
  }else{
    Joystick.button(1, 1);
  }
  if(digitalRead(5)) {
    Joystick.button(2, 0);
  }else{
    Joystick.button(2, 1);
  }
  if(digitalRead(6)) {
    Joystick.button(3, 0);
  }else{
    Joystick.button(3, 1);
  }
  if(digitalRead(7)) {
    Joystick.button(4, 0);
  }else{
    Joystick.button(4, 1);
  }
  if(digitalRead(8)) {
    Joystick.button(5, 0);
  }else{
    Joystick.button(5, 1);
  }
  if(digitalRead(9)) {
    Joystick.button(6, 0);
  }else{
    Joystick.button(6, 1);
  }
  if(digitalRead(10)) {
    Joystick.button(7, 0);
  }else{
    Joystick.button(7, 1);
  }
  if(digitalRead(11)) {
    Joystick.button(8, 0);
  }else{
    Joystick.button(8, 1);
  }
                             //skip 13, put start and coin together
  if(digitalRead(14)) {      //start
    Joystick.button(9, 0);
  }else{
    Joystick.button(9, 1);
  }
  if(digitalRead(15)) {      //coin
    Joystick.button(10, 0);
  }else{
    Joystick.button(10, 1);
  }
  delay(50);
}
