/*********************************************************
VIZIC TECHNOLOGIES. COPYRIGHT 2013.
THE DATASHEETS, SOFTWARE AND LIBRARIES ARE PROVIDED "AS IS." 
VIZIC EXPRESSLY DISCLAIM ANY WARRANTY OF ANY KIND, WHETHER 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
OR NONINFRINGEMENT. IN NO EVENT SHALL VIZIC BE LIABLE FOR 
ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF 
PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, 
ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO 
ANY DEFENCE THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION,
OR OTHER SIMILAR COSTS.
*********************************************************/

/********************************************************
 IMPORTANT : This Example is created for the Arduino 1.0 Software IDE
********************************************************/

//THIS SKETCH NEEDS THE SMARTGPU Arduino library V4

/********************************************************
 This simple sketch does the next:
 1.- try open the "testfile.txt" file in the microSD root path in write only mode 
 2.- if doesn't exist, create the file - if exist overwritte the file
 3.- open again the "testfile.txt" file in the microSD root path in write only mode 
 4.- write "Data Written by the SmartGPU" to the .txt file
 5.- save contents and close file
 6.- open again the file in read only mode
 7.- read from file to a buffer
 8.- verify data read to be equal to message
 9.- end
 
- remove microSD card and search for the file on a PC with the written contents
********************************************************/

#include <SMARTGPU.h>     //include the SMARTGPU library!

SMARTGPU lcd;             //create our object called lcd

unsigned char res = OK;      //create the variable that will store all SMARTGPU commands responses

char message[29]="Data Written by the SMARTGPU";
unsigned int row=5;

//function that loops forever on error
void die(unsigned char response){ //if the response is different than OK, print and loop forever
  if(response!=OK){
    lcd.string(10,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-Error... forever loop @");
    while(1);  
  }
}

/**************************************************/
/**************************************************/
//Initial setup
void setup() { //initial setup
  //Those two functions must always be called for SMARTGPU support
  lcd.init();  //configure the serial and pinout of arduino board for SMARTGPU support
  lcd.start(); //initialize the SMARTGPU processor
}

/**************************************************/
/****************** MAIN LOOP *********************/
/**************************************************/
/**************************************************/
void loop() { //main loop
    char buffer[50]={0};
    unsigned int writtenBytes=0, readbytes=0, i=0;        
    
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT4, UNFILL, "FAT file read,write demo!"); row+=25;
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL, "-Open File <testfile.txt>."); row+=15;
    
    //try to open the file
    res=lcd.SDFopenFile(WRITEONLY, "testfile.txt");  //Try to open a file called "testFile.txt" in write only mode
    if(res!=OK){                       //If the file doesn't Open is because it doesn't exist      
      lcd.string(0,row,WIDTH-1,HEIGHT-1, GREEN, FONT2, UNFILL, "-File does not exist, creating file..."); row+=15;    
      res=lcd.SDFopenFile(CREATENEW, "testfile.txt");  //Try to create the file 
      res|=lcd.SDFopenFile(WRITEONLY, "testfile.txt");  //Try to open the created file      
      die(res);                        //If any error loop forever
    }
    
    //Up to here the file exist and is open    
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL, "-File Open in WRITEONLY mode."); row+=15;    
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL, "-Writting to File... "); row+=15;    
    res=lcd.SDFwriteFile(sizeof(message), message, &writtenBytes); //write to the open file size of message in bytes and store the successfully written Bytes on writtenBytes variable
    die(res);                         //If any error loop forever    
    lcd.SDFsaveFile();                //Save changes in the file contained
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-Close File."); row+=15;    
    lcd.SDFcloseFile();               //Close the file --------------------
    
    //Now lets verify contents
    //open again the file in read only mode
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-Open File <testfile.txt>."); row+=15;    
    res=lcd.SDFopenFile(READONLY, "testfile.txt");  //Try to open again the file read only mode
    die(res);                         //If any error loop forever
    //read the file  
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-File Open in READONLY mode."); row+=15;    
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-Read bytes from File to buffer..."); row+=15;    
    res=lcd.SDFreadFile(sizeof(message), buffer, &readbytes); //read size of message in bytes from the open file and store the successfully read Bytes on readbytes variable
    die(res);                         //If any error loop forever        
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-Close File."); row+=15;        
    lcd.SDFcloseFile();               //Close the file --------------------
    
    //check contents
    lcd.string(0,row,WIDTH-1,HEIGHT-1, GREEN, FONT2, UNFILL,"-Verify/Compare contents..."); row+=15;            
    for(i=0;i<sizeof(message);i++){      
      if(message[i]!=buffer[i]){ //if contents are different
        lcd.string(0,row,WIDTH-1,HEIGHT-1, GREEN, FONT2, UNFILL,"-Contents differ!"); row+=15;                  
        while(1);
      }
    }
    lcd.string(0,row,WIDTH-1,HEIGHT-1,GREEN, FONT2, UNFILL,"-Contents are equal!!! ...END");                     
    while(1);
}
