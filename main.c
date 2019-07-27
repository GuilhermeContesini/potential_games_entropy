#include<stdio.h>
#include<stdlib.h>

#include"init_strategy.c"
#include"set_ensemble_probability.c"
#include"get_global_average_strategy.c"
#include"get_average_entropy.c"
#include"get_average_energy.c"
#include"get_strategy_evolution.c"

int main(
	int argc,
	char *argv[]
){

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//                                                                     PROFILE
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	argv:
		N_size_int_ = 128
		seed_int_   = 32767
		ensemble_size_int = 10
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	int seed_int = 32767 ;
	int ensemble_size_int = 10 ;
	int time_int = 0 ;
	int index_int = 0 ; 
	
	long int n_size_int = 128 ;
	long int ensemble_probability_size_int = 0 ;

	float global_average_strategy_float = 0.0 ;

	float ensemble_average_entropy_float = 0.0 ;
	float ensemble_average_energy_float = 0.0 ;

	int *strategies_int_ary_ptr = NULL ; 
	
	float *strategies_profile_float_ary_ptr = NULL ;

	FILE * data_file_ptr ;

  data_file_ptr = fopen ( "Data/data_file.txt","w" ) ;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//                                                                        ARGV
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	if(argc>1){
		n_size_int = atoi(argv[1]) ;
	}

	if(argc>2){
		ensemble_size_int = atoi(argv[2]) ;
	}

	if(argc>3){
		seed_int = atoi(argv[3]) ;
	}


	// n_size_int = 64 ;
	// while(n_size_int<4096){
		
	// ensemble_size_int = 1 ;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ loop in time

	ensemble_probability_size_int = pow( 2, ensemble_size_int ) ;

	strategies_int_ary_ptr = malloc( n_size_int * sizeof(int) ) ;
	
	strategies_profile_float_ary_ptr = malloc(
		ensemble_probability_size_int*sizeof(float)
	);
	
	init_strategy(
		n_size_int,
		strategies_int_ary_ptr,
		seed_int
	) ;
		
	for (
		time_int = 0;
		time_int < 10e8;
		time_int++
	){

		global_average_strategy_float = get_global_average_strategy(
			n_size_int,
			strategies_int_ary_ptr
		) ;

		set_ensemble_probability(
			n_size_int,
			strategies_int_ary_ptr,
			ensemble_size_int,
			ensemble_probability_size_int,
			strategies_profile_float_ary_ptr
		);

		ensemble_average_energy_float = get_average_energy(
			ensemble_size_int,
			ensemble_probability_size_int,
			strategies_profile_float_ary_ptr
		) ;

		ensemble_average_entropy_float = get_average_entropy(
			ensemble_probability_size_int,
			strategies_profile_float_ary_ptr
		) ;

		fprintf(
			data_file_ptr,
			"%d\t%f\t%f\t%.4f\n",
			ensemble_size_int,
			ensemble_average_entropy_float,
			ensemble_average_energy_float,
			(-1)*ensemble_average_energy_float/ensemble_average_entropy_float
		);

		// ensemble_size_int = ensemble_size_int + 1 ;

		get_strategy_evolution( n_size_int, strategies_int_ary_ptr );

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ loop in time
}

		// printf("\n");
		// n_size_int = n_size_int*2 ;
	// }

  free( strategies_int_ary_ptr ) ;
  free( strategies_profile_float_ary_ptr ) ; 
  fclose ( data_file_ptr ) ;
  return 0;
}

