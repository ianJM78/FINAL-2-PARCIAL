
#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include "rainAnalyzer2.h"
using namespace std;


int main()
{
    string path = "C:/UNI/PROGRAMING/FINAL 2nd parcial/texto.txt";
    string path_2 = "C:/UNI/PROGRAMING/FINAL 2nd parcial/Small_Large.txt";
    string path_3 = "C:/UNI/PROGRAMING/FINAL 2nd parcial/Large_Smalll.txt";

    rainAnalyzer2 RAIN;

    //* COPY file onto vector
    RAIN.copy_textFile_onto_vector(path);

    //* Display file_vector

    vector<file> FILE_VECTOR = RAIN.get_File_vector();

    for (file& element : FILE_VECTOR)
    {
        cout << element.regionNumber << " | " << element.rainAmount << " | " << element.past_rainAmount << endl;
    }
    
    // update precipitation vector with info from file vector

    RAIN.update_Precipitation_vector();

    // display update precipitation vector

    vector<precipitation> PRECIPITATION_VECTOR = RAIN.get_Precipitation_vector();

    for (precipitation& element : PRECIPITATION_VECTOR)
    {
        cout << "Region: " << element.region << endl;
        cout << "Times it rained: " << element.times_it_rained << endl;
        cout << "Total rain: " << element.totalRain << endl;
        cout << "Total past rain: " << element.totalPastRain << "\n" << endl;
    }

    // SORT from smallest to largest rainfall in the PRECIPITAION VECTOR
    RAIN.sort_Smallest_to_Largest();

    // COPY onto file
    RAIN.create_file_with_update_Precipitation_vector(path_2);
    
    // Sort from largest to smallest in the PRECIPITATION VECTOR
    RAIN.sort_Largest_to_Smallest();

    //COPY onto file
    RAIN.create_file_with_update_Precipitation_vector(path_3);
}