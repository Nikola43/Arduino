
#include <Arduino.h>

//Matrix dimensions
#define ROWMAX 8
#define COLMAX 8

//shifts pins
#define ROW_DATA 8
#define ROW_CLK 10
#define ROW_LAT 12

#define COL_DATA 9
#define COL_CLK 11
#define COL_LAT 13

//Open and close latch shortcuts
#define openRowLat digitalWrite(ROW_LAT, LOW)
#define openColLat digitalWrite(COL_LAT, LOW)
#define closeRowLat digitalWrite(ROW_LAT, HIGH)
#define closeColLat digitalWrite(COL_LAT, HIGH)

int matrix[8][17];
	
int b[8][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}};
	
int auxmatrix[8][8] =
{{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 0, 0, 1, 1, 0},
{1, 1, 1, 0, 0, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1},
{0, 1, 1, 0, 1, 1, 1, 0},
{0, 0, 1, 1, 1, 1, 0, 0},
{0, 0, 0, 1, 1, 0, 0, 0}};

int a[8][8] ={ 
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0}};



int c[8][8] =
{{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 1, 0, 0, 0},
{0, 0, 1, 0, 1, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0},
{0, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 0, 0, 1, 0},
{0, 0, 1, 0, 1, 0, 0, 0},
{0, 0, 1, 0, 1, 0, 0, 0}};

//matrix
//uint8_t matrixLED[ROW_SIZE][COL_SIZE + 9];
int counter = 0;
int movement = 0;

void setup();
void loop();
void matrizWrite(byte rowByte, byte colByte);
void matrixAssign(int outMatrix[ROWMAX][COLMAX], int inMatrix[ROWMAX][COLMAX]);
void matrixReset();
void matrixPrint();
void matrixTurnOn();
void matrixSlide(int data[ROWMAX][COLMAX]);

void setup()
{
	Serial.begin(9600);
	Serial.println("Inicio");
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

	matrixSlide(a);

	

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

void matrixAssign(int outMatrix[ROWMAX][COLMAX], int inMatrix[ROWMAX][COLMAX])
{
	int currentRow = 0, currentCol = 0;
	
	for (currentRow = 0; currentRow < ROWMAX; currentRow++)
		for (currentCol = 0; currentCol < COLMAX; currentCol++)
			matrix[currentRow][currentCol] = inMatrix[currentRow][currentCol];
}

void matrixReset()
{
	int currentRow = 0, currentCol = 0;
	
	for (currentRow = 0; currentRow < ROWMAX; currentRow++)
		for (currentCol = 0; currentCol < COLMAX; currentCol++)
			matrix[currentRow][currentCol] = 0;
}

void matrixTurnOn()
{
	int currentRow, currentCol;
	byte rowByte, colByte;
	
	for(currentRow=0; currentRow<ROWMAX; currentRow++)
	{
		rowByte += currentRow;
		for(currentCol=0; currentCol<COLMAX; currentCol++)
		{
			if(matrix[currentCol][currentCol] == 1)
				bitWrite(colByte, currentCol, 1);
			else
				bitWrite(colByte, currentCol, 0);
		}
		matrizWrite(rowByte, colByte);
		delay(1);
	}
}

void matrixSlide(int data[ROWMAX][COLMAX])
{
	
	if(movement == 0)
	{
		uint8_t row, col;
		for(row=0; row<ROWMAX; row++)
		{
			for(col=0; col<COLMAX; col++)
			{
				matrix[row][col+8] = data[row][col];
			}
		}
	}
	
	if(counter % 25 == 0)
	{
		uint8_t row, col;
		for(row=0; row<ROWMAX; row++)
		for(col=0; col<COLMAX + 8; col++)
		matrix[row][col] = matrix[row][col+1];
		
		movement++;
	}
	
	if(movement >= 16)
	{
		counter = 0;
		movement = 0;
	}
	matrixTurnOn();
	counter++;
}


/*
	void rotateMatrix()
	{		
				
		matrixAssign(auxmatrix, matrix);
		
	int currentRow = 0, currentCol = 0;

	int rowByte[ROWMAX] = {0b011111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011, 0b11111101, 0b111111110};
		
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
