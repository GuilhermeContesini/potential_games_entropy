#include<stdlib.h>

#include"ranlux.c"

void init_strategy(
	int size_int_,
	int strategy_int_ary_[size_int_],
	int seed_int
	){

	int index_int ;
	float *random_float_ary_ptr ;

	random_float_ary_ptr = malloc(size_int_ * sizeof(float));

	get_randlux(size_int_,random_float_ary_ptr,seed_int);

	for( index_int=0; index_int<size_int_; index_int++ ){
		
		strategy_int_ary_[index_int]=0;

		if(
			random_float_ary_ptr[index_int]<0.5
		){

			strategy_int_ary_[index_int]=1;
		
		}	

	}
	free( random_float_ary_ptr );
}