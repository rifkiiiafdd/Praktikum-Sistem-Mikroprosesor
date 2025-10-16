const int pin_relay = 26;
const int pin_input = 25;
const int period = 1000;

static unsigned long last_toggle = 0;
static bool relay_state = false;
static int last_input = HIGH;

void setup() {
    Serial.begin(115200);
    pinMode(pin_relay, OUTPUT);
    pinMode(pin_input, INPUT_PULLUP);
}

void loop() {
    
    unsigned long now = millis();

    // Bangkitkan sinyal kotak
    if (now - last_toggle >= period) {
        relay_state = !relay_state;
        digitalWrite(pin_relay, relay_state);                  // catat waktu kontrol
        last_toggle = now;
    }

    // Baca output relay dan hitung selisih
    int input_level = digitalRead(pin_input);
    if (input_level != last_input) {
        unsigned long t_response = millis();
        Serial.printf("Feedback: %d | Delay = %lu ms\n",
                      input_level, t_response - last_toggle);
        last_input = input_level;
    }
}
