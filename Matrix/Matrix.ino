//size from matrix
#define ROW_SIZE 8
#define COL_SIZE 8

uint8_t sp[ROW_SIZE][COL_SIZE] = {0};

uint8_t A[ROW_SIZE][COL_SIZE] = {
{0,1,1,1,0,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,1,1,1,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0},
{1,0,0,0,1,0,0,0}};

uint8_t B[ROW_SIZE][COL_SIZE] = {
{0, 0, 0, 0, 1, 1, 1, 1}, 
{0, 0, 0, 1, 0, 0, 0, 1}, 
{0, 0, 0, 1, 0, 0, 0, 1}, 
{0, 0, 0, 0, 1, 1, 1, 1}, 
{0, 0, 0, 1, 0, 0, 0, 1}, 
{0, 0, 0, 1, 0, 0, 0, 1}, 
{0, 0, 0, 1, 0, 0, 0, 1},
{0, 0, 0, 0, 1, 1, 1, 1}}; 
		
//Open and close latch shortcuts
#define open_row_lat digitalWrite(ROW_LAT, LOW)
#define open_col_lat digitalWrite(COL_LAT, LOW)
#define close_row_lat digitalWrite(ROW_LAT, HIGH)
#define close_col_lat digitalWrite(COL_LAT, HIGH)

//shifts pins
#define ROW_DATA 8
#define ROW_CLK 10
#define ROW_LAT 12
#define COL_DATA 9
#define COL_CLK 11
#define COL_LAT 13

//function prototypes
void matrix_slide(uint8_t data[ROW_SIZE][COL_SIZE]);
void matrix_light();
void matrix_reset(uint8_t matrix[ROW_SIZE][COL_SIZE]);

//matrix
uint8_t matrixLED[ROW_SIZE][COL_SIZE + 9];
int counter = 0;
int movement = 0;

//setup function
void setup()
{
    pinMode(ROW_DATA, OUTPUT);
    pinMode(ROW_CLK, OUTPUT);
    pinMode(ROW_LAT, OUTPUT);
    pinMode(COL_DATA, OUTPUT);
    pinMode(COL_CLK, OUTPUT);
    pinMode(COL_LAT, OUTPUT);

    Serial.begin(9600);
    Serial.println("init");  
}

//loop function
void loop()
{
  char val;
  
    while(true)
    {    
		if (Serial.available() > 0)
			val = Serial.read();

        if(val == 'a')
            matrix_slide(A);
    }
}

void matrix_slide(uint8_t data[ROW_SIZE][COL_SIZE])
{
    
    if(movement == 0)
    {
        uint8_t row, col;
        for(row=0; row<ROW_SIZE; row++)
        {
            for(col=0; col<COL_SIZE; col++)
            {
                matrixLED[row][col+8] = data[row][col];
            }
        }
    } 
  
    if(counter % 25 == 0) 
    {
        uint8_t row, col;
        for(row=0; row<ROW_SIZE; row++)
            for(col=0; col<COL_SIZE + 8; col++)
                matrixLED[row][col] = matrixLED[row][col+1];  
    
        movement++;
    }
  
    if(movement >= 16)
    {
        counter = 0;
        movement = 0;
    }
    matrix_light();
    counter++;
}

void matrix_light()
{
    uint8_t row_pos[ROW_SIZE] = {0b01111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011, 0b111111101, 0b11111110};
    uint8_t row, col;
    uint8_t row_byte, col_byte;
    for(row=0; row<ROW_SIZE; row++)
    {
        row_byte = row_pos[row];
        for(col=0; col<COL_SIZE; col++)
	{
	    if(matrixLED[row][col] == 1)
	        bitWrite(col_byte, col, 1);
	    else
	        bitWrite(col_byte, col, 0);
	}
	
        //Write data to shifts
        open_row_lat; open_col_lat;
	    shiftOut(ROW_DATA, ROW_CLK, LSBFIRST, row_byte);
            shiftOut(COL_DATA, COL_CLK, LSBFIRST, col_byte);
	close_row_lat; close_col_lat;
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
