bool A[2];
bool B[2];
int count;
int final_Loop;
#define A_P 12
#define B_P 11
void setup() {
  // initialize digital pin 13 to drive LED
  pinMode(A_P, INPUT);
  pinMode(B_P, INPUT);
  Serial.begin(9600);
  A[0] = digitalRead(A_P);
  B[0] = digitalRead(B_P);
  A[1] = digitalRead(A_P);
  B[1] = digitalRead(B_P);
  count = 0;
}

// infinite loop for real-time operation
void loop() {
  A[0] = A[1];
  B[0] = B[1];
  A[1] = digitalRead(A_P);
  B[1] = digitalRead(B_P);
  if((!A[0]&&!A[1]&&!B[0]&& B[1])||
     (!A[0]&& A[1]&& B[0]&& B[1])||
     ( A[0]&& A[1]&& B[0]&&!B[1])||
       A[0]&&!A[1]&&!B[0]&&!B[1]){
    count+=1;
    if(count>=4) {
      count = 0;
      final_Loop+=1;
      if(final_Loop>=100) {
        final_Loop = 0;
      }
      Serial.println(final_Loop);
    }
    
  } else if(A[0]==A[1]&&B[0]==B[1]) {
    
  } else {
    count-=1;
    if(count <= -4) {
      count = 0;
      final_Loop-=1;
      if(final_Loop<0) {
        final_Loop = 99;
      }
      Serial.println(final_Loop);
    }
  }
  
}
