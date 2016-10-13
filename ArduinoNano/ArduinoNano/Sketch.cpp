//Include arduino libraries
#include <Arduino.h>

//Matrix dimensions
#define ROWMAX 8
#define COLMAX 8

//shifts pins
#define ROW_DATA 2
#define ROW_CLK 3
#define ROW_LAT 4

#define COL_DATA 5
#define COL_CLK 6
#define COL_LAT 7

//Open and close latch shortcuts
#define openRowLat digitalWrite(ROW_LAT, LOW)
#define openColLat digitalWrite(COL_LAT, LOW)
#define closeRowLat digitalWrite(ROW_LAT, HIGH)
#define closeColLat digitalWrite(COL_LAT, HIGH)


	
byte b[8][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}};
	
byte auxmatrix[8][8] = {
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0}};

byte a[ROWMAX][8] = {
	{0,1,1,1,0,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,1,1,1,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,0,0}};



byte c[8][8] =
{{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 1, 0, 0, 0},
{0, 0, 1, 0, 1, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0},
{0, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 0, 0, 1, 0},
{0, 0, 1, 0, 1, 0, 0, 0},
{0, 0, 1, 0, 1, 0, 0, 0}};

byte matrix[ROWMAX][COLMAX + 9];
byte counter = 0;
byte movement = 0;

void setup();
void loop();

void matrixTurnOn();
void matrixSlide(byte data[ROWMAX][COLMAX]);
void matrizWrite(byte rowByte, byte colByte);
void matrixAssign(byte outMatrix[ROWMAX][COLMAX], byte inMatrix[ROWMAX][COLMAX]);
void matrixReset();

void setup()
{
	Serial.begin(9600);
	Serial.print("Inicio");
	pinMode(13, OUTPUT);
	pinMode(ROW_DATA, OUTPUT);
	pinMode(ROW_CLK, OUTPUT);
	pinMode(ROW_LAT, OUTPUT);
	pinMode(COL_DATA, OUTPUT);
	pinMode(COL_CLK, OUTPUT);
	pinMode(COL_LAT, OUTPUT);
}

//Infinite loop
void loop()
{

    matrixTurnOn();


}





void matrixTurnOn()
{
	byte rowPos[ROWMAX] = {0b01111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011, 0b111111101, 0b11111110};
	byte currentRow, currentCol;
	byte rowByte, colByte;
	
	for(currentRow=0; currentRow<ROWMAX; currentRow++)
	{
		rowByte = rowPos[currentRow];
		for(currentCol=0; currentCol<COLMAX; currentCol++)
		{
			if(a[currentRow][currentCol] == 1)
				bitWrite(colByte, currentCol, 1);
			else
				bitWrite(colByte, currentCol, 0);
		}
		matrizWrite(rowByte, colByte);
		delay(1);
	}
}

void matrixSlide(byte data[ROWMAX][COLMAX])
{
	
	if(movement == 0)
	{
		byte row, col;
		for(row=0; row<ROWMAX; row++)
		{
			for(col=0; col<COLMAX; col++)
			{
				matrix[row][col+8] = data[row][col];
			}
		}
	}
	
	if(movement == 8)
	{
		byte row, col;
		for(row=0; row<ROWMAX; row++)
		{
			for(col=0; col<COLMAX; col++)
			{
				matrix[row][col+8] = b[row][col];
			}
		}
	}
	
	if(counter % 25 == 0)
	{
		byte row, col;
		for(row=0; row<ROWMAX; row++)
			for(col=0; col<COLMAX + 8; col++)
				matrix[row][col] = matrix[row][col+1];
		
		movement++;
	}
	
	if(movement >= 24)
	{
		counter = 0;
		movement = 0;
	}
	matrixTurnOn();
	counter++;
}

void matrizWrite(byte rowByte, byte colByte)
{
	openRowLat;
	openColLat;
		shiftOut(ROW_DATA, ROW_CLK, MSBFIRST, rowByte);
		shiftOut(COL_DATA, COL_CLK, MSBFIRST, colByte);
	closeRowLat;
	closeColLat;
}

void matrixAssign(byte outMatrix[ROWMAX][COLMAX], byte inMatrix[ROWMAX][COLMAX])
{
	byte currentRow = 0, currentCol = 0;
	
	for (currentRow = 0; currentRow < ROWMAX; currentRow++)
	for (currentCol = 0; currentCol < COLMAX + 9; currentCol++)
	outMatrix[currentRow][currentCol] = inMatrix[currentRow][currentCol - 9];
}

void matrixReset()
{
	byte currentRow = 0, currentCol = 0;
	
	for (currentRow = 0; currentRow < ROWMAX; currentRow++)
		for (currentCol = 0; currentCol < COLMAX; currentCol++)
			matrix[currentRow][currentCol] = 0;
}

/*
	void rotateMatrix()
	{		
				
		matrixAssign(auxmatrix, matrix);
		
	byte currentRow = 0, currentCol = 0;

	byte rowByte[ROWMAX] = {0b011111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011, 0b11111101, 0b111111110};
		
	byte colByte=0;
	
	for (currentRow = 0; currentRow < ROWMAX; currentRow++)
	{
		for (currentCol = 0; currentCol < COLMAX; currentCol++)
		{
			if(matrix[currentRow][currentCol] == 1)
			bitWrite(colByte, currentCol, 1);
			else
			bitWrite(colByte, currentCol, 0);
			//colByte<<1;
		}
		matrizWrite(rowByte[currentRow], colByte);
	}
	
	
	}
	*/
