/*lang: SR
 * 
 *  UPALI/UGASI LED preko BLUETOOTHA.
 * 
 * Na ploci LED je obicno digitalni pin 13, ali se moze koristiti i ovaj
 * LED_BUILTIN koji ce pronaci pravi LED pin nezavisno od modela ploce.
 * HC-05 Bluetooth Modul spojen sa GND, 5V, RX, TX (RX, TX ukrsteni)
 * 
 * **********************************************************************
 * 
 *  TURN ON/OFF LED with BLUETOOTH.
 * 
 * On-board LED is by default digital pin 13, but you can use this trick,
 * LED_BUILTIN is the correct LED pin independent of which board is used.
 * HC-05 Bluetooth Module connected with GND, 5V, RX, TX (RX, TX croosed)
 * 
 *                                                           dxdev.co.nf
*/

char serData; // Primljeno preko BT // Received BT data 

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600); //Set the data rate in bits per second (baud) for serial data transmission
}

void loop() {
  
  if(Serial.available() > 0) {
    serData = Serial.read();  // Read the incoming data and store it into serData
    Serial.print("Recived: ");  // Print in Serial monitor (Send feedback)
    Serial.print(serData);
    Serial.print("\n");
    if(serData == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");
    }else if(serData == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
    }
  }
  
}
