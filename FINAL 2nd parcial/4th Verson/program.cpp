
#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include "rainAnalyzer3.h"
using namespace std;






void create_file_with_update_Precipitation_vector(vector<precipitation> PRECIPITATION_VECTOR, string path)
{
    ofstream values(path);

    for (precipitation& element : PRECIPITATION_VECTOR)
    {
        values << element.region << " | " << element.totalRain << " | " << (element.totalRain / element.times_it_rained)
        << " | " << abs((element.totalRain / element.times_it_rained) - (element.totalPastRain / element.times_it_rained))
        << endl;
    }
}

void largest_to_smallest(vector<precipitation> PRECIPITATION_VECTOR, string path)
{
    for (size_t i = 1; i < PRECIPITATION_VECTOR.size(); i++)
    {
        precipitation key = PRECIPITATION_VECTOR[i];
        int j = i - 1;

        while (j >= 0 && PRECIPITATION_VECTOR[j].totalRain < key.totalRain)
        {
            PRECIPITATION_VECTOR[j + 1] = PRECIPITATION_VECTOR[j];
            j--;
        }
        PRECIPITATION_VECTOR[j + 1] = key;
    }

    create_file_with_update_Precipitation_vector(PRECIPITATION_VECTOR,path);
}

void smallest_to_largets(vector<precipitation> PRECIPITATION_VECTOR, string path)
{
    for (size_t i = 1; i < PRECIPITATION_VECTOR.size(); i++)
    {
        precipitation key = PRECIPITATION_VECTOR[i];
        int j = i - 1;

        while (j >= 0 && PRECIPITATION_VECTOR[j].totalRain > key.totalRain)
        {
            PRECIPITATION_VECTOR[j + 1] = PRECIPITATION_VECTOR[j];
            j--;
        }
        PRECIPITATION_VECTOR[j + 1] = key;
    }

    create_file_with_update_Precipitation_vector(PRECIPITATION_VECTOR,path);
}



int main()
{
    string path = "C:/UNI/PROGRAMING/FINAL 2nd parcial/texto.txt";
    string path_2 = "C:/UNI/PROGRAMING/FINAL 2nd parcial/Small_Large.txt";
    string path_3 = "C:/UNI/PROGRAMING/FINAL 2nd parcial/Large_Smalll.txt";

    rainAnalyzer3 RAIN;


    //? COPY file onto vector
    RAIN.copy_textFile_onto_vector(path);


    //? Display file_vector
    vector<file> FILE_VECTOR = RAIN.get_File_vector();
    for (file& element : FILE_VECTOR)
    {
        cout << element.regionNumber << " | " << element.rainAmount << " | " << element.past_rainAmount << endl;
    }
    
    //? update precipitation vector with info from file vector
    RAIN.update_Precipitation_vector();


    vector<precipitation> PRECIPITATION_VECTOR = RAIN.get_Precipitation_vector();
    

    //? display update precipitation vector
    for (precipitation& element : PRECIPITATION_VECTOR)
    {
        cout << "Region: " << element.region << endl;
        cout << "Times it rained: " << element.times_it_rained << endl;
        cout << "Total rain: " << element.totalRain << endl;
        cout << "Total past rain: " << element.totalPastRain << "\n" << endl;
    }

    //? SORT and CREATE file with Precipitation vector
    smallest_to_largets(PRECIPITATION_VECTOR,path_2);

    largest_to_smallest(PRECIPITATION_VECTOR,path_3);
    
}