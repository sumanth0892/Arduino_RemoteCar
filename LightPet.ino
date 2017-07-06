//The light pet - A color changing mood lighting
//Randomly selects and fades through colors of three LEDs

//Set pins for colors
const int red = 9;
const int green = 10;
const int blue = 11;

//Assign variables for LEDs to mix colors at various levels between 0 and 255.
int redValue = 0;
int newRedValue = 0;

int blueValue = 0;
int newBlueValue = 0;

int greenValue = 0;
int newGreenValue = 0;

//Utility variables and random number, with the fading speed
int randomValue = 0;
int fadeSpeed = 50;

//Setup the three LED pins for OUTPUT

void setup() {
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
}

void loop() {
int mood = random(20);
if (mood>2)
{blendColors();}
}

void blendColors(){
newRedValue = random(255); //Pick a random value for red LED
if (redValue<newRedValue){
  for (int x=redValue;x<newRedValue;x++){
    analogWrite(red,x);
    delay(fadeSpeed);  
  }
}
else {
  for (int x=redValue;x>newRedValue;x--){
    analogWrite(red,x);
    delay(fadeSpeed);
  }
}

redValue=newRedValue;

newGreenValue = random(255); //Pick a random value for Green LED
if (greenValue<newGreenValue){
  for (int x=greenValue;x<newGreenValue;x++){
    analogWrite(green,x);
    delay(fadeSpeed);  
  }
}
else {
  for (int x=greenValue;x>newGreenValue;x--){
    analogWrite(green,x);
    delay(fadeSpeed);
  }
}

greenValue=newGreenValue;

newBlueValue = random(255); //Pick a random value for Blue LED
if (blueValue<newBlueValue){
  for (int x=blueValue;x<newBlueValue;x++){
    analogWrite(blue,x);
    delay(fadeSpeed);  
  }
}
else {
  for (int x=blueValue;x>newBlueValue;x--){
    analogWrite(blue,x);
    delay(fadeSpeed);
  }
}

blueValue=newBlueValue;


}

