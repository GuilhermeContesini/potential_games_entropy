float get_global_average_strategy(
	int size_int_,
	int strategy_int_ary_[size_int_]
	){

	int index_int ;
	float sum_float ;

	sum_float = 0.0 ;

	for (
		index_int = 0 ;
		index_int < size_int_ ;
		index_int++
	){
		sum_float = sum_float + strategy_int_ary_[index_int] ;
	}

	return sum_float/size_int_ ;
}