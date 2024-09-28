#define BLYNK_TEMPLATE_ID "TMPL66K84Tsa1"
#define BLYNK_TEMPLATE_NAME "switch"
#define BLYNK_AUTH_TOKEN "vFoE-oqxzViv2IR94SuZBUnNJGNUAbfJ"
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

#define Relay1 D1 // Define the pin for Relay1

char auth[] = "vFoE-oqxzViv2IR94SuZBUnNJGNUAbfJ";
char ssid[] = "3BB-DECHA_2.4GHz";
char pass[] = "146395DE";

WidgetLED Relay1Blynk(V10);

int lastSwitchState = 1;
int currentSwitchState = 0;

// Use ICACHE_FLASH_ATTR to move this function to Flash memory
ICACHE_FLASH_ATTR void setup() {
  // Debug console
  Serial.begin(9600);
  
  // Configure OUTPUT pin for relay
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH); // Ensure relay is initially OFF

  // Synchronize Blynk state when the device starts
  Blynk.syncVirtual(V1); // Sync the state of the virtual pin V1 (the switch in the Blynk app)

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  // Read the momentary switch state
  currentSwitchState = digitalRead(D3); // Assuming momentary switch is connected to pin D2

  // Check for a rising edge (button press)
  if (currentSwitchState == HIGH && lastSwitchState == LOW) {
    // Toggle the relay state
    toggleRelay();
  }

  lastSwitchState = currentSwitchState;
}

// Use ICACHE_FLASH_ATTR to move this function to Flash memory
ICACHE_FLASH_ATTR void toggleRelay() {
  // Toggle the state of the relay
  if (digitalRead(Relay1) == HIGH) {
    digitalWrite(Relay1, LOW);
    Blynk.virtualWrite(V1, 255);
    Relay1Blynk.on();
  } else {
    digitalWrite(Relay1, HIGH);
    Blynk.virtualWrite(V1, 0);
    Relay1Blynk.off();
  }
}

// This function handles the Blynk app switch
BLYNK_WRITE(V1) {
  // Handle the Blynk app switch
  int relayState = param.asInt();
  if (relayState) {
    digitalWrite(Relay1, LOW);
    Relay1Blynk.on();
  } else {
    digitalWrite(Relay1, HIGH);
    Relay1Blynk.off();
  }
}
