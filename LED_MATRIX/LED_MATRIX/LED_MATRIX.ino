/*
 * LED_MATRIX.ino
 *
 * Created: 11/30/2014 9:56:06 PM
 * Author: paulo
 */ 

//size from matrix
#define ROW_SIZE 8
#define COL_SIZE 8

uint8_t A[ROW_SIZE][8] = {
	{0,1,1,1,0,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,1,1,1,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,1,0,1,0,0,0},
	{1,0,0,0,1,0,0,0}};
//Open and close latch shortcuts
#define open_row_lat digitalWrite(ROW_LAT, LOW);
#define open_col_lat digitalWrite(COL_LAT, LOW);
#define close_row_lat digitalWrite(ROW_LAT, HIGH);
#define close_col_lat digitalWrite(COL_LAT, HIGH);

//shifts pins
#define ROW_DATA 8
#define ROW_CLK 10
#define ROW_LAT 12
#define COL_DATA 9
#define COL_CLK 11
#define COL_LAT 13

//function prototypes

void matrix_light(uint8_t matrix[ROW_SIZE][COL_SIZE]);
void matrix_assig(uint8_t matrix[ROW_SIZE][COL_SIZE], uint8_t data[ROW_SIZE][COL_SIZE]);
void matrix_reset(uint8_t matrix[ROW_SIZE][COL_SIZE]);

//matrix
uint8_t matrix[ROW_SIZE][COL_SIZE];

//setup function
void setup()
{
	Serial.begin(9600);
        while(!Serial);
	Serial.println("ON");
	pinMode(ROW_DATA, OUTPUT);
	pinMode(ROW_CLK, OUTPUT);
	pinMode(ROW_LAT, OUTPUT);
	pinMode(COL_DATA, OUTPUT);
	pinMode(COL_CLK, OUTPUT);
	pinMode(COL_LAT, OUTPUT);
}

//loop function
void loop()
{
	matrix_light(A);	
}

void matrix_light(uint8_t matrix[ROW_SIZE][COL_SIZE])
{
	uint8_t row, col;
	uint8_t row_byte, col_byte;
	for(row=0; row<ROW_SIZE; row++)
	{
		row_byte += row;
		for(col=0; col<COL_SIZE; col++)
		{
			if(matrix[row][col] == 1)
				bitWrite(col_byte, col, 1);
			else
				bitWrite(col_byte, col, 0);
		}
					
		shiftOut(ROW_DATA, ROW_CLK, LSBFIRST, row_byte);
		shiftOut(COL_DATA, COL_CLK, LSBFIRST, col_byte);
		delay(20);
	}
}

void matrix_assig(uint8_t matrix[ROW_SIZE][COL_SIZE], uint8_t data[ROW_SIZE][COL_SIZE])
{
	uint8_t row, col;
	for(row=0; row<ROW_SIZE; row++)
		for(col=0; col<COL_SIZE; col++)
			matrix[row][col] = data[row][col];
}

//turn off matrix
void matrix_reset(uint8_t matrix[ROW_SIZE][COL_SIZE])
{
	uint8_t row, col;
	for(row=0; row<ROW_SIZE; row++)
		for(col=0; col<COL_SIZE; col++)
			matrix[row][col] = 0;
}
