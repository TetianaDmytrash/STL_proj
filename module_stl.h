#pragma once
#include <math.h>
#include "general_set_up.h"
#include <iostream>

void general_same(std::string key_name, int key_value);
void output(std::string key, double* first);
void general_sort(double* array_sort);
void output_start(std::string key, int first);
void create_map(void);
void cout_map(void);

template<class iterator>
void for_each(iterator start_map, iterator finish_map, void f(std::string, double*)) {
    ++start_map;
    for (; start_map != finish_map; ++start_map) {
        f(start_map->first, start_map->second);
    }
}

template<class iterator>
void for_each(iterator start_multimap, iterator finish_multimap, void f(std::string, int)) {
    iterator tmp_iter;
    for (; start_multimap != finish_multimap; ++start_multimap) {
        f(start_multimap->first, *(start_multimap->second));
        tmp_iter = start_multimap;
    }
    if (start_multimap == finish_multimap) {
        start_multimap = tmp_iter;
        f(" ", 0);
    }
}