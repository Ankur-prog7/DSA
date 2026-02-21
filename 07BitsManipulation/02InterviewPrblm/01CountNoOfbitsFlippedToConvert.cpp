// Count number of bits to be flipped to convert A to B

int minBitsFlip(int start,int goal){
  int num = start^goal;
  int count  =0 ;
  for (int i = 0; i < 32; i++)
  {
    //  Update count if the rightmost bit is set 
    count += (num & 1); 
    num = num >> 1;
  }
  return count;
}