byte myByte=0b10010111;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(myByte,BIN);
  //myByte = myByte*2; // left shift (destructive)
  //myByte = myByte/2; // right shift (destructive)
  //myByte = myByte * 128 + myByte / 2; // circular left shift  
  //myByte = myByte / 128 + myByte * 2; // circular left shift
  //myByte = 0xFF - myByte; // bit flip
  myByte = bitreverse(myByte);
  delay(500);
}

byte bitreverse(byte start) {
  byte result=0;
  for (byte i=0;i<8;i++) {
    result = result <<1; //push bits already in there over by one
    result |= ((start>>i) & 0x01); //shift start x bits to the right, bitwise and with 1. |= is bitwise-or-equals, same idea as += and the like. 
    //Serial.println(result,BIN);
  }
  return result;
}

byte bitreverse2(byte start) {
  byte result = ((start&0x01)<<7)|((start&0x02)<<5)|((start&0x04)<<3)|((start&0x08)<<1)|((start&0x10)>>1)|((start&0x20)>>3)|((start&0x40)>>5)|((start&0x80)>>7);
  return result;
}
