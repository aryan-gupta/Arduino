enum HEX_D {
  H0 = 0x3F,
  H1 = 0x06, 
  H2 = 0x5B,
  H3 = 0x4F, 
  H4 = 0x66, 
  H5 = 0x6D, 
  H6 = 0x7D, 
  H7 = 0x07, 
  H8 = 0x7F, 
  H9 = 0x6F, 
  HA = 0x77, 
  HB = 0x7C, 
  HC = 0x39, 
  HD = 0x5E, 
  HE = 0x79, 
  HF = 0x71
};

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void write_hex(HEX_D hex_enum) {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

  int hex_num = int(hex_enum);
  
  digitalWrite(2, (hex_num & 0x1)? HIGH : LOW); // SEG A
  digitalWrite(3, (hex_num & 0x2)? HIGH : LOW); // SEG B
  digitalWrite(4, (hex_num & 0x4)? HIGH : LOW); // SEG C
  digitalWrite(5, (hex_num & 0x20)? HIGH : LOW); // SEG F
  digitalWrite(6, (hex_num & 0x40)? HIGH : LOW); // SEG G
  digitalWrite(7, (hex_num & 0x10)? HIGH : LOW); // SEG E
  digitalWrite(8, (hex_num & 0x8)? HIGH : LOW); // SEG D
}

void write_all() {
  write_hex(H0);
    delay(1000);
    
    write_hex(H1);
    delay(1000);
    
    write_hex(H2);
    delay(1000);
    
    write_hex(H3);
    delay(1000);
    
    write_hex(H4);
    delay(1000);
    
    write_hex(H5);
    delay(1000);
    
    write_hex(H6);
    delay(1000);
    
    write_hex(H7);
    delay(1000);
    
    write_hex(H8);
    delay(1000);
    
    write_hex(H9);
    delay(1000);
    
    write_hex(HA);
    delay(1000);
    
    write_hex(HB);
    delay(1000);
    
    write_hex(HC);
    delay(1000);
    
    write_hex(HD);
    delay(1000);
    
    write_hex(HE);
    delay(1000);
    
    write_hex(HF);
    delay(1000);

}

void loop() {
    write_all();
}
