const int TRIGX = 4;
const int ECHOX = 3;

const int TRIGY = 7;
const int ECHOY = 6;

const int TRIGZ = 9;
const int ECHOZ = 8;


void setup (){

Serial.begin(9600);

pinMode(TRIGX, OUTPUT);

pinMode(ECHOX, INPUT);

pinMode(TRIGY, OUTPUT);

pinMode(ECHOY, INPUT);

pinMode(TRIGZ, OUTPUT);

pinMode(ECHOZ, INPUT);

}

void loop (){ 

//Serial.print("New loop"); 
  
long durationX, inchesX, cmX,durationY, inchesY, cmY,durationZ, inchesZ, cmZ;
pinMode(TRIGX, OUTPUT); 
digitalWrite(TRIGX, LOW); 
delayMicroseconds(2); 
digitalWrite(TRIGX, HIGH); 
delayMicroseconds(10); 
digitalWrite(TRIGX, LOW);
pinMode(ECHOX, INPUT); 
durationX = pulseIn(ECHOX, HIGH);
inchesX = microsecondsToInches(durationX); 
cmX = microsecondsToCentimeters(durationX);
Serial.flush();
//Serial.print("X ");
Serial.print( cmX );
//Serial.print("  |");
Serial.print(','); 

pinMode(TRIGY, OUTPUT); 
digitalWrite(TRIGY, LOW); 
delayMicroseconds(2); 
digitalWrite(TRIGY, HIGH); 
delayMicroseconds(10); 
digitalWrite(TRIGY, LOW);
pinMode(ECHOY, INPUT); 
durationY = pulseIn(ECHOY, HIGH);
inchesY = microsecondsToInches(durationY); 
cmY = microsecondsToCentimeters(durationY);
//Serial.print("  Y ");
Serial.print( cmY );
//Serial.print("  |");
Serial.print(','); 

pinMode(TRIGZ, OUTPUT); 
digitalWrite(TRIGZ, LOW); 
delayMicroseconds(2); 
digitalWrite(TRIGZ, HIGH); 
delayMicroseconds(10); 
digitalWrite(TRIGZ, LOW);
pinMode(ECHOZ, INPUT); 
durationZ = pulseIn(ECHOZ, HIGH);
inchesZ = microsecondsToInches(durationZ); 
cmZ = microsecondsToCentimeters(durationZ);
//Serial.print("  Z "); 
Serial.print( cmZ );
//Serial.print("  |");

Serial.println();

delay(20);

}

long microsecondsToInches(long microseconds)
{return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}
