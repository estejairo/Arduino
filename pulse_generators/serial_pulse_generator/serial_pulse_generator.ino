// Serial negative pulse generator to test ASD board, sending serial
// commands.
//
// Author: Jairo Gonzalez

//Serial
long BaudRate = 9600;

// Pin
int o_pulse_pin = 13; // pulse output pin

//Aux
int pulse_duration_ms = 100;
int delay_time_ms = 100; //inter pulse delay
String in_string;
int pulses_number = 0;
int i = 1; //loop index
void setup() {
    //Serial communication
    Serial.begin(BaudRate);

    //I/O
    pinMode(o_pulse_pin, OUTPUT);
    digitalWrite(o_pulse_pin, HIGH);
}

void loop() {
    //Detects Serial Command
    if(Serial.available()>0){
        //Extracts number
        in_string=Serial.readString();
        pulses_number = in_string.toInt();
        Serial.print("Sending ");
        Serial.print(pulses_number);
        Serial.println(" pulses.");
        
        //Sending Pulses
        for (i = 1; i<pulses_number+1; i++){
            Serial.print("\tPulse number ");
            Serial.println(i);
            
            digitalWrite(o_pulse_pin, LOW);
            delay(pulse_duration_ms);
            digitalWrite(o_pulse_pin, HIGH);
            delay(delay_time_ms);
        }
        i = 1;
        
        Serial.println("Done.");
    }
}
