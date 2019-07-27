#include<stdlib.h>

#include"get_label_configuration.c"

#define coupling_A -1
#define coupling_B -1

float get_average_energy(
  	int ensemble_size_int,
  	int ensemble_probability_size_int,
  	float strategies_profile_float_ary_ptr[ ensemble_probability_size_int ]
	){

	int energy_index_int = 0 ;
  int label_index_int = 0 ;
  int number_configurations_int = pow(2, ensemble_size_int) ;
  float configuration_energy_float = 0.0 ;
  float average_energy_float = 0.0 ;

  for (
    label_index_int = 0 ;
    label_index_int < number_configurations_int ;
    label_index_int++
  ){
    /* code */
    // average_energy_float = 0.0 ;
    configuration_energy_float = 0.0 ;
    int *configuration_int_ary = NULL ;

    configuration_int_ary = malloc( ensemble_size_int * sizeof(int) ) ;

    get_label_configuration( label_index_int, ensemble_size_int, configuration_int_ary ) ;

    for (
      energy_index_int = 0 ;
      energy_index_int < ensemble_size_int-1 ;
      energy_index_int++
    ){

    	configuration_energy_float = configuration_energy_float +\
      coupling_A*( configuration_int_ary[ energy_index_int ]*configuration_int_ary[ energy_index_int+1 ] )+\
      coupling_B*( configuration_int_ary[ energy_index_int ] ) ;

    }

    average_energy_float = average_energy_float + \
    ( configuration_energy_float*strategies_profile_float_ary_ptr[ label_index_int ] ) ;
    free( configuration_int_ary ) ;
  }

  
  return average_energy_float/ensemble_size_int ;

}