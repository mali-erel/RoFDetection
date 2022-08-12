#include <stdio.h>
#include <stdint.h>

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

//TheCompare method compares previous and current inputs' channels whether riseing or falling.
int TheCompare(int a, int b){
    int BitPoint = 0;
    int count=0;
    while(b>=0)
    {   
        BitPoint++;
        if((a&1 ^ b&1)){
            if(b&1){
                printf("\nRise Edge : %d",BitPoint);
                printf("\nChannel %d is active",BitPoint);
            }else{
                printf("\nFall Edge : %d",BitPoint);
                printf("\nChannel %d is deactive",BitPoint);
            }          
        }else{
            count++;
        }
        a>>=1;
        b>>=1;
    }
    
}


//The void method takes 3 variables. int arr[] contains channel numbers, int NumofChannels, the user specifies previously how many channels they want to check. 
//uint16_t NewInput is a decimal number the user wants to check on..
void isActive(int arr[], int NumofChannel, uint16_t NewInput){
    int i;
    uint16_t temp = NewInput;
    for(i = 0; i<NumofChannel;i++)
    {
        temp>>=arr[i]-1;
        if(temp&1 RoF == 1){
            printf("\nChannel %d is rise",arr[i]);
        }else{
            printf("\nChannel %d is deactive",arr[i]);
        }
        temp = NewInput;
    }

    
}

int main(int argc, char const *argv[])
{
    uint16_t a = 824;
    uint16_t b = 12345;
    uint16_t c = 55826;
    int arr[16]; 
    int channelNumbers;
    printf("\n");
    printf("Binary of %d : ",a);decimalToBinary(a);
    printf("\nBinary of %d : ",b);decimalToBinary(b);
    printf("\nBinary of %d : ",c);decimalToBinary(b);
    printf("\n");
    //Compare
    TheCompare(a,b);

    //Channel active check
    printf("\nEnter how many channel you want to look : ");
   // scanf("%d",&channelNumbers);
   // for(int i = 0; i<channelNumbers;i++){
   //     scanf("%ld",&arr[i]);
   // }

    // Void method that check one or multiple channels if they are active or not.
   // isActive(arr,channelNumbers,c);
  //   printf("\n");
  //  int x = hammingWeight(b);
  //  printf("\n%d",x);
    return 0;
}
