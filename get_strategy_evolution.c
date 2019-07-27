#include<stdlib.h>

//Win-Stay Lose-Shift

void get_strategy_evolution(
  int size_int_,
  int strategy_int_ary_[ size_int_ ]
  ){

  int index_int ;

  for( index_int=0; index_int<size_int_; index_int++ ){
    
    strategy_int_ary_[ index_int ] = \
      strategy_int_ary_[ index_int ] == strategy_int_ary_[ index_int+1 ] ;

  }

}