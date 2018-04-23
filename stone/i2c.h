//    Main I2C functions :
//   'i2c_start' -    Issues a start condition and sends address
//         and transfer direction.
//   'i2c_rep_start' -  Issues a repeated start condition and sends
//         address and transfer direction.
//   'i2c_stop' -    Terminates the data transfer by issue a
//         stop condition.
//   'i2c_write' -   Writes data (one byte) to the I2C bus
//         
//   'i2c_get_ack' - Get slave acknowledge response.
//    
//   'i2c_put_ack' -  Put acknowledge.
//       
//   'PCF8503_write_byte' - Writes data (one byte) to the PCF8583.
//         
//   'PCF8503_read_byte' - Reads data (one byte) from the PCF8583.
// 
//  USAGE
//   (An example is shown in the 'main' code).  
// 
//  NOTES
//   The I2C routines can be called either from non-interrupt or
//   interrupt routines, not both.
// 


// **** Global I2C Constants ****

#define I2C_PORT      DDRD        // I2C port direction
#define I2C_PORT_IN   PIND        // I2C port in 
#define I2C_PORT_OUT  PORTD       // I2C port out 

#define SCL         0             // SCL Pin
#define SDA         1             // SDA Pin 


// ******* RTC Address****
#define PCF8583         0xa0      // PCF8583 address 

  

// ***************************************************************************
// *
// * FUNCTION
// *  i2c_hp_delay
// *  i2c_qp_delay
// *
// * n_hp = (5 * fosc in Mhz) for normal mode  (1.3 * fosc) for fast mode
// * n_qp = (2.5 * fosc im MHz) for normal mode  (0.6 * fosc) for fast mode
// *
// * Use n_hp and n_qp to chose one of the following methods for both delays.
// * n_xx < 1    remove all calls to rhe delay routine
// * 1 < n <2    replace all calls to rhe delay routine with one _nop() instrucion
// * 2 < n <3    replace all calls to the delay routine with two _nop() instrucions
// * 2 < n <7    the delay routine should consist ';' only 
// * n_xx > 7    routine is used in the program code
// *
// ***************************************************************************

#define n_hp       40        //  fosc = 8Mhz       
#define n_qp       20                                     


void delay_hp(void)                    //hp - half i2c clock period delay normal: 5.0us
{
unsigned char time= 1+ (n_hp-7)/3;
while(time--);
}

void delay_qp(void)                    //qp - quarter i2c clock period delay normal: 2.5us
{
unsigned char time= 1+ (n_qp-7)/3;
while(time--);
}


// ***************************************************************************
// *
// * FUNCTION
// *  i2c_init
// *
// * DESCRIPTION
// *  Initialization of the I2C bus interface.
// *
// * USAGE
// *  Call this function once to initialize the I2C bus. 
// *
// * COMMENT
// *  This function can be combined with any  PORT initializations.
// *
// ***************************************************************************

void i2c_init(void)
  {
  I2C_PORT_OUT&= ~(1<<SCL | 1<<SDA);      //set I2C pins to open colector
  I2C_PORT&= ~(1<<SCL | 1<<SDA);
  }




// ***************************************************************************
// *
// * FUNCTION
// *  i2c_rep_start
// *
// * DESCRIPTION
// *  Assert repeated start condition 
// *
// * RETURN
// *  none.
// *
// * NOTE
// *  IMPORTANT! : This funtion must be directly followed by i2c_start.
// *
// ***************************************************************************

void i2c_rep_start(void)
{
  I2C_PORT|= 1<<SCL;                 // force SCL low
  I2C_PORT&=~(1<<SDA);                // release SDA
  delay_hp();                        // half period delay
  I2C_PORT&=~(1<<SCL);               // release SCL
  delay_qp();                        // quarter period delay
}

// ***************************************************************************
// *
// * FUNCTION
// *  i2c_start
// *
// * DESCRIPTION
// *  Generates start condition 
// *
// * RETURN
// *  none.
// *
// * NOTE
// *  IMPORTANT! : This funtion must be directly followed by i2c_write.
// *
// ***************************************************************************

void i2c_start(void)
{        
  I2C_PORT|=1<<SDA;           // force SDA low
  delay_qp();                 // quarter period delay
}

// ***************************************************************************
// *
// * FUNCTION
// *  i2c_write
// *
// * DESCRIPTION
// *  Writes data (one byte) to the I2C bus. Also used for sending
// *  the address.
// *
// * USAGE
// *  send - Contains data to be transmitted.
// *
// * NOTE
// *  IMPORTANT! : This funtion must be directly followed by i2c_get_ack.
// *
// ***************************************************************************
   
void i2c_write(unsigned char send)
{
  unsigned char i=0x80;
  do{
  
     I2C_PORT|=1<<SCL;                        // force SCL low
      if (send & i) I2C_PORT&=~(1<<SDA);
         else I2C_PORT|=1<<SDA;
        delay_hp();
       I2C_PORT&=~(1<<SCL);
       delay_hp();
      i=i>>1;
    }
   while(i);
}


// ***************************************************************************
// *
// * FUNCTION
// *  i2c_get_ack
// *
// * DESCRIPTION
// *  Get slave acknowledge response.
// *
// * RETURN
// *  0 - if a slave responds to a request.
// *  1 - if a slave not responds to a request.
// *
// ***************************************************************************

unsigned char i2c_get_ack(void)
 {
  I2C_PORT|=1<<SCL;               //force SCL low
  I2C_PORT&= ~(1<<SDA);           //release SDA
  delay_hp();                     // half period delay
  I2C_PORT&= ~(1<<SCL);           //release SCL

  while (!(I2C_PORT_IN & (1<<SCL)));  // wait SCL high 
     
  if (I2C_PORT_IN & 1<<SDA)       // ACK not present
         {
           delay_hp();
           return (1);
         }
    else                          // ACK present 
      {
      delay_hp();                 // half period delay
      return(0);
       }
}


// ***************************************************************************
// *
// * FUNCTION
// *  i2c_read
// *
// * DESCRIPTION
// *  Reads data (one byte) from the I2C bus.
// *
// * RETURN
// *  Contains received data.
// *
// * NOTE
// *  IMPORTANT! : This funtion must be directly followed by i2c_put_ack.
// *
// ***************************************************************************

unsigned char i2c_read(void)
{
  unsigned char przesuw=0x80;
  unsigned char rx=0;
  
  do{
    I2C_PORT|=1<<SCL;        // force SCL low
    delay_hp();            
    I2C_PORT&=~(1<<SCL);          //release SCL
    delay_hp();
    if (I2C_PORT_IN & (1<<SDA)) rx=rx+przesuw;
    przesuw=przesuw>>1;
  } while(przesuw);
  return rx;
}


// ***************************************************************************
// *
// * FUNCTION
// *  i2c_put_ack
// *
// * DESCRIPTION
// *  Put acknowledge.
// *
// * USAGE
// *    status -   If set no acknowledge is given to the slave
// *               indicating last read operation before a STOP.
// *               If cleared acknowledge is given to the slave
// *               indicating more data.
// *
// * RETURN
// *  none
// *
// ***************************************************************************

void i2c_put_ack(unsigned char status)
 {
  I2C_PORT|=1<<SCL;                     // force SCL low
  if (status) I2C_PORT&=~(1<<SDA); 
   else
        I2C_PORT|=1<<SDA;                  // set ACK (low level)
   
  delay_hp();                           // half period delay
  I2C_PORT&=~(1<<SCL);                  // release SCL

  while(!(I2C_PORT_IN & (1<<SCL)));           // wait SCL high
  delay_hp();                        // half period delay
}


// ***************************************************************************
// *
// * FUNCTION
// *  i2c_stop
// *
// * DESCRIPTION
// *  Assert stop condition.
// *
// * USAGE
// *  No parameters.
// *
// * RETURN
// *  None.
// *
// ***************************************************************************

void i2c_stop(void)
  {
  I2C_PORT|=1<<SCL;           //  force SCL low
  I2C_PORT|=1<<SDA;           //  force SDA low
  delay_hp();                 //  half period delay
  I2C_PORT&=~(1<<SCL);        //  release SCL
  delay_qp();                 //  quarter period delay
  I2C_PORT&=~(1<<SDA);        //  release SDA
  delay_hp();                   //  half period delay
  }




// ***************************************************************************
// *
// * FUNCTION
// *  PCF8583_write_byte
// *
// * DESCRIPTION
// *  Writes data (one byte) to the  PCF8583
// *  
// *
// * USAGE
// *  address - PCF8583 internal memory address.
// *  data - Contains data to be transmitted.
// *
// *
// ***************************************************************************



unsigned char PCF8583_write_byte(unsigned char address, unsigned char data)
{ 
 i2c_start();
 i2c_write(PCF8583);
 if (i2c_get_ack()) 
    {
     i2c_stop(); 
     return(1);
    }

 i2c_write(address);
 if (i2c_get_ack()) 
    {
     i2c_stop(); 
     return(1);
    }

i2c_write(data);
 if (i2c_get_ack()) 
    {
     i2c_stop(); 
     return(1);
    }
i2c_stop();    
return(0);
}


// ***************************************************************************
// *
// * FUNCTION
// *  PCF8503_read_byte
// *
// * DESCRIPTION
// *  Reads data (one byte) from the PCF8583.
// *
// * USAGE
// *  Address - PCF8583 internal memory address
// *    
// * RETURN
// *  Contains received data.
// *
// ***************************************************************************


unsigned char PCF8583_read_byte(unsigned char address)
{
 unsigned char data;
 i2c_start();
 i2c_write(PCF8583);
 if (i2c_get_ack()) 
    {
     i2c_stop(); 
     return(1);
    }

 i2c_write(address);
 if (i2c_get_ack()) 
    {
     i2c_stop(); 
     return(1);
    }

i2c_rep_start();
i2c_start();
i2c_write(PCF8583 | 0x01);
 if (i2c_get_ack()) 
    {
     i2c_stop(); 
     return(1);
    }

data =i2c_read();
i2c_put_ack(1);
i2c_stop();
return data;
}

