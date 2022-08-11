#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>


/* 'CheckRoF' function has 4 attribute. New inpıt, old input, number of how many channel wanted to look, channel numbers and rise or fall*/
void CheckRoF(uint16_t NewInput, uint16_t OldInput,int NumberofChannel, int ChannelNumbers[], _Bool RoF){
    /*New input and old input are used as tempNew - tempOld for repeatedly reset situations.*/
    uint16_t tempNew = NewInput;
    uint16_t tempOld = OldInput;
    /*for loop executes NumberofChannel time as the user wanted.*/
    for(;NumberofChannel>0;NumberofChannel-=1){
        /*tempNew and tempOld shift right as one minus selected channel number from index 4 to 0 of ChannelNumbers
          This substraction is nececery since the code need to use AND operation with '1'*/
        tempNew>>=ChannelNumbers[NumberofChannel-1]-1;
        tempOld>>=ChannelNumbers[NumberofChannel-1]-1;
        /*By using XOR gate, the code filters the same channels.(ex: 1-1, 0-0)*/
        if((tempNew&1 ^ tempOld&1)){
            /*Check tempNew's selected channel is 1 or 0 and user requested rise edge or fall edge.*/
            // Rise Edge
            if(tempNew&1 && RoF == true){
                printf("\nRise Edge at channel %d",ChannelNumbers[NumberofChannel-1]);
                break;
            // Fall Edge
            }else if(!(tempNew&1) && RoF == false){
                printf("\nFall Edge at channel %d ",ChannelNumbers[NumberofChannel-1]);
                break;
            }
        }
        // Reset shifted temps and continue.
        tempNew = NewInput;
        tempOld = OldInput;
    }
    
    
}

//Converts decimal to binary and prints. int type input.
void decimalToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
   
   // Stores binary representation of number.
   int binaryNum[16]; // Assuming 16 bit integer.
   int i=0;
   
   for ( ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   
   // Printing array in reverse order.
   for (int j = i-1; j >= 0; j--){
     
      printf("%d", binaryNum[j]);
   }
}

int hammingWeight(uint32_t n) {
    int values[16];
    int count=0;
    int BitPoint = 0;
    while(n>0)
    {   
        BitPoint++;
        if(n&1)
        {
            count++;
            values[count] = BitPoint;
        }
        n>>=1;
    }
    for(int i = 1;i<BitPoint+1;i++){
        printf("%d ",values[i]);
    }
    return count;
}

//Delay function. Input in seconds.
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int main(int argc, char const *argv[])
{   
    //For automated test cases I created datasets random.
    int n = 0;
    uint16_t old;
    uint16_t new;
    int NumberofChannel,i;
  /*  int NumberofChannel = rand() % 16 + 1; 
    int ChannelNumbers[],i; 
    for(i=0;i<NumberofChannel;i++)
        ChannelNumbers[i]=rand()% 16 + 1;   
    */
    //CheckRoF(0b000010001010111,0b000001000001001,NumberofChannel,ChannelNumbers,1);


    while(n<10){
        //Every loop new, old, Number of channel and channel numbers values changes randomly
        new = rand() % 65536;
        old = rand() % 65536;
        NumberofChannel = rand() % 16 + 1; // Random number of channel wanted to be activate between 1-16 
        int ChannelNumbers[NumberofChannel];
        ChannelNumbers[NumberofChannel]; // ChannelNumbers's size determined randomly by NumberofChannel

        for(i=0;i<NumberofChannel;i++)
            ChannelNumbers[i]=rand()% 16 + 1;  //Generate number between 1-16 as much as active channel.

        printf("\nTest Case : %d\n",n+1);
        printf("\nOld Bin : ");decimalToBinary(old);
        printf("\nNew Bin : ");decimalToBinary(new);
        printf("\nNew Dec : %d \nOld Dec : %d \n",new,old);
        CheckRoF(new,old,NumberofChannel,ChannelNumbers,1);

        CheckRoF(new,old,NumberofChannel,ChannelNumbers,0);
                printf("\n");
        printf("\nNumber of channel : %d \nChannel Numbers : ",NumberofChannel);

        for(int i = 0; i<NumberofChannel;i++){
            printf("%d ",ChannelNumbers[i]);
        }
        // new and old values reset
        new = 0;
        old = 0;
        printf("\n");
        n++;
        // delay 2.5 seconds
        delay(2.5);
    }
    return 0;
}
