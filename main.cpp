#include <iostream>
#include <cstdlib>
using namespace std;

int** createArray(int rows, int cols){
  int** arr = new int*[rows];
  for(int i = 0; i< rows; i++){
    arr[i] = new int[cols];
  }
  return arr;
}

void initArray(int **arr, int rows, int cols){
  int counter = 1;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j< cols; j++){ 
      if(j == 0){
        arr[i][j] = counter;
        counter++;
      }else{
         arr[i][j] = 0;
      }
    }
  }

}

void printArray(int **arr, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j< cols; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout <<"-----" << endl;
}





void deleteArray(int** arr, int rows){
  for (int i = 0; i < rows; i++){
    delete[] arr[i];
    arr[i] = NULL;
  }
delete [] arr;
arr = NULL;
}
void moveDisk(int locA, int locB, int** arr, int arrHeight){
  //loop throguh column to see where the top disk is.
  int stop = 0;
  int temp;

  // if the disk is on the first column move it and stop
  for(int i = 0; i < arrHeight;i++){
    if(arr[locA][i] > 0 && stop < 1){
      stop++;
      temp = arr[locA][i];
      arr[locA][i] = 0;
    }
  }
  stop = 0;
  for(int i = arrHeight-1; i >= 0; i--){
    if(arr[locB][i] == 0 && stop < 1){
      stop++;
      arr[locB][i] = temp;
    }
  }
}



void towers(int numberOfDisks, int** arr, int fromCol, int toCol, int spare){
  int temp = numberOfDisks;
  if(numberOfDisks >= 1){
    //cout << numberOfDisks << endl;
    towers(numberOfDisks-1,arr,fromCol,spare,toCol);
    moveDisk(fromCol,toCol,arr,numberOfDisks);
    //cout << numberOfDisks << endl;
    towers(numberOfDisks-1, arr, spare,  toCol,  fromCol);
  }else{
    printArray(arr,temp,3);
    
  }
  
}



int main(int argc, char *argv[]) {
  //cout << argv[1];
  int a = atoi(argv[1]);// # of disks
  int b = 3;//atoi(argv[2]);

  cout << a << endl;


 int** arr = createArray(a,b);
 initArray(arr, a, b);
  printArray(arr, a, b);
  
  //towers(a,arr,0,1,2);
  //printArray(arr, a, b);
  
  moveDisk(0, 2, arr, a);

  printArray(arr, a, b);

  moveDisk(0, 1, arr, a);

  printArray(arr, a, b);
  deleteArray(arr, a);
  return 0;
}