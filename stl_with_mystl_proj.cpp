// stl_with_mystl_proj.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "general_set_up.h"
#include"data_for_modules.h"
#include "module_stl.h"

#ifdef with_stl
    #include <map>
    template<typename s, typename p>
    using multimap_container = std::multimap <s, p>;
    template<typename s, typename p>
    using map_container = std::map<s, p>;
    template<typename s, typename p>
    using map_pair = std::pair<s, p>;
#else
    #include "my_multimap.h"
    #include "my_map.h"
    #include "my_pair.h"
    template<typename s, typename p>
    using multimap_container = my_multimap<s, p>;
    template<typename s, typename p>
    using map_container = my_map<s, p>;
    template<typename s, typename p>
    using map_pair = my_pair<s, p>;
#endif

int main() {
    setlocale(0, "");
#ifdef with_stl
    std::cout << " Реализация c STL " << std::endl;
#else
    std::cout << " Реализация без STL " << std::endl;
#endif
    multimap_container<std::string,int*> mp_in;
#ifdef const_pair
    int* tmp_for_value = new int[25];
    for(int i = 0; i<25; i++){
        tmp_for_value[i]=i-5;
    }
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[0]));
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[1]));
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[2]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[3]));
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[4]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[5]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[6]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[7]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[8]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[9]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[10]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[11]));
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[12]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[13]));
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[14]));
    mp_in.insert(map_pair<std::string, int*>("key0", &tmp_for_value[15]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[16]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[17]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[18]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[19]));
    mp_in.insert(map_pair<std::string, int*>("key2", &tmp_for_value[20]));
    mp_in.insert(map_pair<std::string, int*>("key3", &tmp_for_value[21]));
    mp_in.insert(map_pair<std::string, int*>("key1", &tmp_for_value[22]));
    mp_in.insert(map_pair<std::string, int*>("key3", &tmp_for_value[23]));
    mp_in.insert(map_pair<std::string, int*>("key3", &tmp_for_value[24]));
#else
    std::cout << "Введите количество элементов: "; int n; n = data_for_modules::my_getline();
    int* tmp_for_value = new int[n];
    for (int i = 0; i < n; i++) {
        char array_for_input_key[data_for_modules::max_quantity_of_symbol];
        std::cout << "Введите ключ: ";std::cin.getline(array_for_input_key, data_for_modules::max_quantity_of_symbol);
        std::cout << "Введите значение ключа " << array_for_input_key << ": ";
        tmp_for_value[i] = data_for_modules::my_getline();
        mp_in.insert(map_pair<std::string, int*>(array_for_input_key, &tmp_for_value[i]));
    }
#endif
    multimap_container<std::string, int*> ::iterator it_in = mp_in.begin();
    cout_results
    create_map();
    for_each(mp_in.begin(), mp_in.end(), general_same);
    cout_map();
    system("pause");
    return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
