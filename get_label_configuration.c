#include<stdio.h>

void get_label_configuration(
  int label_int,
  int ensemble_size_int,
  int configuration_ary_ptr[ ensemble_size_int ]
){

  int index_int = 0 ;
  int aux_label_int = label_int ;

  for (
    index_int = 0 ;
    index_int < ensemble_size_int ;
    index_int++
  ){
    configuration_ary_ptr[ index_int ] = aux_label_int%2 ;
    aux_label_int = aux_label_int/2 ;
  }

}