
//you can find the documentation for these values in the doc 
float kP = 20;
float kI = 1;
float kD = 3;
float angleOffset = -4; //degrees of ofsett for balance

//calculation variables
float eInt = 0;
float ePrev = 0;
//float tNow = 0;
float e = 0;
float eDot =0;
float u =0;
float dt = 0.01;


float pid_controll(float angle) {
	//pid controller
	//tNow  = tNow + dt;
	e     = angle - angleOffset;
	eDot  = (e - ePrev) / dt;
	eInt  = eInt + e * dt;
	u     = kP * e + kI * eInt + kD * eDot;
	ePrev = e;

	return u; // her må vi legge til funksjon
}