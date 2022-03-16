#include "module_stl.h"
#include "data_for_modules.h"
#ifdef with_stl
    #include <map>
template<typename s, typename f>
using map_container = std::map<s, f>;
template<typename s, typename f>
using map_pair = std::pair<s, f>;
#else
#include "my_map.h"
#include "my_pair.h"
template<typename s, typename f>
using map_container = my_map<s, f>;
template<typename s, typename f>
using map_pair = my_pair<s, f>;
#endif

bool data_for_modules::control_same;
int data_for_modules::count_column_for_out;
int data_for_modules::quantity_of_value;
double data_for_modules::array_value_out[data_for_modules::max_quantity_of_pair][data_for_modules::result_number];
double data_for_modules::tmp_array_mediana[data_for_modules::max_quantity_of_symbol];

map_container<std::string, double*> mp_out;
map_container<std::string, double*> ::iterator it_out;

void general_same(std::string key_name, int key_value) {
    double* tmp_pointer;
    tmp_pointer = it_out->second;
    if (it_out->first == key_name) {
        ++data_for_modules::quantity_of_value;
        data_for_modules::tmp_array_mediana[data_for_modules::quantity_of_value - 1] = key_value;
#ifndef with_stl
        data_for_modules::array_value_out[data_for_modules::count_column_for_out][0] += key_value;
#endif
        tmp_pointer[0] += key_value;
        data_for_modules::control_same = true;
    }
    else {
        if (data_for_modules::control_same) {
            tmp_pointer[1] = (data_for_modules::array_value_out[data_for_modules::count_column_for_out][0] / data_for_modules::quantity_of_value);
            general_sort(&data_for_modules::tmp_array_mediana[0]);
            if (data_for_modules::quantity_of_value % 2 == 0) {
                int tmp;
                tmp = data_for_modules::quantity_of_value / 2;
                tmp_pointer[2] = (data_for_modules::tmp_array_mediana[tmp] + data_for_modules::tmp_array_mediana[tmp - 1]) / 2;
            }
            else {
                data_for_modules::quantity_of_value = (int)floor(data_for_modules::quantity_of_value / 2);
                tmp_pointer[2] = data_for_modules::tmp_array_mediana[data_for_modules::quantity_of_value];
            }
            data_for_modules::control_same = false;
        }
        ++data_for_modules::count_column_for_out;
        for (int i = 0; i < data_for_modules::result_number; i++) {
            data_for_modules::array_value_out[data_for_modules::count_column_for_out][i] = key_value;
        }
        mp_out.insert(map_pair<std::string, double*>(key_name, data_for_modules::array_value_out[data_for_modules::count_column_for_out]));
        ++it_out;
        data_for_modules::quantity_of_value = 1;
        data_for_modules::tmp_array_mediana[data_for_modules::quantity_of_value - 1] = key_value;
    }
}

void general_sort(double* array_sort) {
    for (int i = 0; i < data_for_modules::quantity_of_value; i++) {
        for (int j = 0; j < data_for_modules::quantity_of_value; j++) {
            if (array_sort[j] < array_sort[i]) {
                double tmp = array_sort[j];
                array_sort[j] = array_sort[i];
                array_sort[i] = tmp;
            }
        }
    }
}

void output(std::string key, double* first) {
    if (key != " ") {
        std::cout << "Ключ " << key << ": сумма - " << first[0] << ", среднее - " << first[1] << ", медиана - " << first[2] << std::endl;
    }
}

void output_start(std::string key, int first) {
    if (key != " ") {
        std::cout << "Ключ " << key << ": значение - " << first << std::endl;
    }
}

void create_map(void) {
    double arr_tmp[3] = { 0,0,0 };
    mp_out.insert(map_pair<std::string, double*>(" ", arr_tmp));
    it_out = mp_out.begin();
}

void cout_map(void) {
    for_each(mp_out.begin(), mp_out.end(), output);
}
