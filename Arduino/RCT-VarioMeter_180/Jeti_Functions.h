//
// For any extra functions needed before loop()
//

// Vario
static long Averaging_Filter(long input);
static long Averaging_Filter(long input) // moving average filter function
{
  long sum = 0;
  for (int i = 0; i < sample_count; i++) {
    k[i] = k[i + 1];
  }
  k[sample_count - 1] = input;
  for (int i = 0; i < sample_count; i++) {
    sum += k[i];
  }
  return ( sum / sample_count ) ;
}

// Reset sensor via Jetibox
void(* resetFunc) (void) = 0;
