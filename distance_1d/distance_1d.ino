const int TRIGX = 4;
const int ECHOX = 3;

void setup (){
Serial.begin(9600);
pinMode(TRIGX, OUTPUT);
pinMode(ECHOX, INPUT);
}

void loop (){ 

long durationX, inchesX, cmX;
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
Serial.print("X ");
Serial.print( cmX );
Serial.print("cm");
//Serial.print(','); 

Serial.println();
delay(20);

}

long microsecondsToInches(long microseconds)
{return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}
