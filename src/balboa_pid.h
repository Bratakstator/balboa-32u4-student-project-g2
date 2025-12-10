
//you can find the documentation for these values in the doc 
int8_t kP = 20;
int8_t kI = 1;
int8_t kD = 3;
int32_t angleOffset = -4000; //degrees of ofsett for balance

//calculation variables
int16_t eInt = 0;
int16_t ePrev = 0;
//int16_t tNow = 0;
int16_t e = 0;
int16_t eDot =0;
int16_t u =0;
int16_t dt = 0.01;

extern int32_t angle;

int32_t pid_controll() {
	//pid controller
	//tNow  = tNow + dt;
	e     = angle - angleOffset;
	eDot  = (e - ePrev) / dt;
	eInt  = eInt + e * dt;
	u     = kP * e + kI * eInt + kD * eDot;
	ePrev = e;

	return u; // her må vi legge til funksjon
}