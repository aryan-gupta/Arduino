const int CAM_PIN = 2;
const int LED1_PIN = 0;
//const int LED2_PIN = 1;

bool gRecording = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(CAM_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  //pinMode(LED2_PIN, OUTPUT);
  
  digitalWrite(CAM_PIN, LOW);
  digitalWrite(LED1_PIN, LOW);

  delay(10000);
  digitalWrite(LED1_PIN, HIGH);
}

void toggle_camera() {
  static const int HIGH_TIME = 200;

  gRecording = !gRecording;

  digitalWrite(CAM_PIN, HIGH);
  delay(HIGH_TIME);
  digitalWrite(CAM_PIN, LOW);
}

void take_picture() {
  
  static const int HIGH_TIME = 200;
  static const int LOW_TIME = 50;
    
  digitalWrite(CAM_PIN, HIGH);
  delay(HIGH_TIME);
  digitalWrite(CAM_PIN, LOW);
  
  delay(LOW_TIME);
  
  digitalWrite(CAM_PIN, HIGH);
  delay(HIGH_TIME);
  digitalWrite(CAM_PIN, LOW);
}

void loop() {
  take_picture();
  delay(1000);
  take_picture();

  delay(1000);
  
  toggle_camera();
  delay(5000);
  toggle_camera();
  
  digitalWrite(LED1_PIN, LOW);
  delay(10000);
}
