#include "data_for_modules.h"

data_for_modules::data_for_modules(void) {
#ifdef with_stl
	count_column_for_out = -1;
#else
    count_column_for_out = 0;
#endif
    quantity_of_value = 1;
    control_same = false;
}

int data_for_modules::my_getline(void) {
    char k1[max_quantity_of_symbol];
    int k;
    std::cin.getline(k1, max_quantity_of_symbol);
    k = (int)atof(k1);
    return k;
}
