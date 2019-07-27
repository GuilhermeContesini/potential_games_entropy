void set_ensemble_probability(
	int size_int_,
	int strategy_int_ary_[ size_int_ ],
	int ensemble_size_int,
	int probability_profile_size_int,
	float ensemble_probability_profile_ary_ptr[ probability_profile_size_int ]
	){

	int ary_index_int, ensemble_index_int ;
	int micro_state_label_int ;

	double sum_float = 0.0 ;
	
  double ensemble_count_profile_double_ary_ptr[ probability_profile_size_int ] ;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Array-Pointer Cleaner 
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for (
		ary_index_int = 0 ;
		ary_index_int <= probability_profile_size_int;
		ary_index_int++
	){

		ensemble_count_profile_double_ary_ptr[ ary_index_int ] = 0.0 ;
		ensemble_probability_profile_ary_ptr[ ary_index_int ] = 0.0 ;
		// printf("%d:%f\n",ary_index_int,ensemble_count_profile_double_ary_ptr[ary_index_int] );
	}
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	for (
		ary_index_int = 0 ;
		ary_index_int <= size_int_- ensemble_size_int ;
		ary_index_int++
	){
		
		micro_state_label_int = 0 ;

		for (
			ensemble_index_int = ensemble_size_int - 1 ;
			ensemble_index_int >= 0  ;
			ensemble_index_int--
		){
			
			micro_state_label_int =	\
				micro_state_label_int + (
					strategy_int_ary_[ ary_index_int+ensemble_index_int ]*\
					pow( 2, ensemble_index_int ) 
				) ;
				// printf("%d,",strategy_int_ary_[ary_index_int+ensemble_index_int] );
				
		}
		// printf("%d\n",micro_state_label_int);
		ensemble_count_profile_double_ary_ptr[ micro_state_label_int ] = \
		ensemble_count_profile_double_ary_ptr[ micro_state_label_int ] + 1 ;
		// printf("%d:%.2lf\n", micro_state_label_int,ensemble_count_profile_double_ary_ptr[micro_state_label_int] ); 
	}

	for (
		ary_index_int = 0 ;
		ary_index_int <= probability_profile_size_int ;
		ary_index_int++
	){

		sum_float = sum_float + ensemble_count_profile_double_ary_ptr[ary_index_int] ;
		// printf("%d,%lf\n",ary_index_int, sum_float );
	}

	for (
		ary_index_int = 0 ;
		ary_index_int < probability_profile_size_int ;
		ary_index_int++
	){

		ensemble_probability_profile_ary_ptr[ ary_index_int ] = \
			ensemble_count_profile_double_ary_ptr[ ary_index_int ]\
			/ sum_float ; 
		// printf("%d\t%f\n", ary_index_int, ensemble_probability_profile_ary_ptr[ary_index_int] );
	}

}

// ainda falta a condição de contorno !