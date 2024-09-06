import java.util.Arrays;

class Outlier{

    static int find(int[] integers){
      int parity = integers[0] % 2 + integers[1] % 2 + integers[2] % 2;
      if(parity < 2){
        for (int i : integers){
          if(i % 2 != 0){
            return i;
          }
        }
      }
      else{
        for (int i : integers){
          if(i % 2 == 0){
            return i;
          }
        }
      }
      return 0;
    }
}