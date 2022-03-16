#pragma once
#include "general_set_up.h"
#include <iostream>

class data_for_modules
{
public:
	static const int max_quantity_of_pair = 256;
	static const int result_number = 3;
	static const int max_quantity_of_symbol = 256;
	static double array_value_out[max_quantity_of_pair][result_number];
	static double tmp_array_mediana[max_quantity_of_pair];
	static bool control_same;
	static int quantity_of_value;
	static int count_column_for_out;
	data_for_modules(void);
	static int my_getline(void);
};

