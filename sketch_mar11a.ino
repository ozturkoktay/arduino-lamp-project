int ses_sensor = 4;
int role = 5;
int alkis = 0;
long algilama_baslangic = 0;
long algilama_araligi = 0;
boolean isik_durumu = false;
 
void setup() {

  pinMode(ses_sensor, INPUT);
  pinMode(role, OUTPUT);
}
 
void loop() {
 
  int sensor_durumu = digitalRead(ses_sensor);
 
  if (sensor_durumu == 0) {

    if (alkis == 0){
      algilama_baslangic = algilama_araligi = millis();
      alkis++;
    }

    else if (alkis > 0 && millis()-algilama_araligi >= 50) {
      algilama_araligi = millis();
      alkis++;
    }
  }
 
  if (millis()-algilama_baslangic >= 400) {
  
    if (alkis == 2) {    
      if (!isik_durumu) {
          isik_durumu = true;
          digitalWrite(role, HIGH);
        }
        else if (isik_durumu) {
          isik_durumu = false;
          digitalWrite(role, LOW);
        }
    }
    alkis = 0;
  }
}
