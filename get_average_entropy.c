#include<stdio.h>
#include<math.h>

float get_average_entropy(
    int ensemble_probability_size_int,
    float strategies_profile_float_ary_ptr[ ensemble_probability_size_int ]
  ){
  
  int index_int = 0 ;

  float ensemble_entropy_float = 0.0 ;

  for (
    index_int = 0 ;
    index_int < ensemble_probability_size_int ;
    index_int++
  ){
    ensemble_entropy_float = ensemble_entropy_float-\
    (
      strategies_profile_float_ary_ptr[index_int]*log(1.e-6+strategies_profile_float_ary_ptr[index_int])
    ) ;
  }

  return ensemble_entropy_float ;
}