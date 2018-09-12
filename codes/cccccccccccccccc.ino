const int frontLeft1 = 2;
const int frontLeft2 = 3;

const int frontRight1 = 4;
const int frontRight2 = 5;

const int backLeft1 = 6;
const int backLeft2 = 7;

const int backRight1 = 8;
const int backRight2 = 9;


// Lifter

const int leftSide1 = 10;
const int leftSide2 = 11;

const int rightSide1 = 12;
const int rightSide2 = 13;


char command;

void setup()
{
	Serial.begin(9600);
	pinMode( frontLeft1, OUTPUT);
	pinMode( frontLeft2, OUTPUT);
	pinMode( frontRight1, OUTPUT);
	pinMode( frontRight2, OUTPUT);
	pinMode( backLeft1, OUTPUT);
	pinMode( backLeft2, OUTPUT);
	pinMode( backRight1, OUTPUT);
	pinMode( backRight2, OUTPUT);
	pinMode( leftSide1, OUTPUT);
	pinMode( leftSide2, OUTPUT);
	pinMode( rightSide1, OUTPUT);
	pinMode( rightSide2, OUTPUT);
	
}

void goForward()
{
	digitalWrite(frontLeft1, HIGH);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, HIGH);
	digitalWrite(frontRight2, LOW);
	digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, HIGH);
	digitalWrite(backRight2, LOW);
}

void goBackward()
{
	digitalWrite(frontLeft1, LOW);
	digitalWrite(frontLeft2, HIGH);
	digitalWrite(frontRight1, LOW);
	digitalWrite(frontRight2, HIGH);
	digitalWrite(backLeft1, LOW);
	digitalWrite(backLeft2, HIGH);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, HIGH);
}

void goLeft()
{
	digitalWrite(frontLeft1, LOW);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, HIGH);
	digitalWrite(frontRight2, LOW);
	digitalWrite(backLeft1, LOW);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, HIGH);
	digitalWrite(backRight2, LOW);
}

void goRight()
{
	digitalWrite(frontLeft1, HIGH);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, LOW);
	digitalWrite(frontRight2, LOW);
	digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, LOW);


}

void turn360()
{
	digitalWrite(frontLeft1, HIGH);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, LOW);
	digitalWrite(frontRight2, HIGH);
	digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, HIGH);

}

void stopall()
{

	digitalWrite(frontLeft1, LOW);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, LOW);
	digitalWrite(frontRight2, LOW);
	digitalWrite(backLeft1, LOW);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, LOW);


}


//Write lifter motor codes here



void loop()
{
	if (Serial.available()>0){
		command = Serial.read();
		
		switch (command){
			case 'w':
				goForward();
				break;
			case 's':
				goBackward();
				break;
			case 'a':
				goLeft();
				break;
			case 'd':
				goRight();
				break;
				
			case 'e':
				turn360();
				break;
				
			default:
				stopall();
				break;
		
		
		}
	
	
	}


}
