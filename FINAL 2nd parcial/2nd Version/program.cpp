#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include "rainAnalyzer.h"
using namespace std;

//!    IMPORTANT

//!    GETTING THE DIRECCION OF THE ARRAYS FROM THE CLASS IS POINTLESS
//!    IT DEFEATS THE POINT OF THEM ONLY BEING ACCESIBLE BY METHODS


void create_file_with_Precipitation_array(struct precipitation PRECIPITATION_ARRAY[],string path)
{
    ofstream values(path);
    for (int i = 0; i < REGION_COUNT; i++)
    {
        values << PRECIPITATION_ARRAY[i].region << " | " << PRECIPITATION_ARRAY[i].totalRain << " | " << (PRECIPITATION_ARRAY[i].totalRain / PRECIPITATION_ARRAY[i].times_it_rained)
        << " | " << abs((PRECIPITATION_ARRAY[i].totalRain / PRECIPITATION_ARRAY[i].times_it_rained) - (PRECIPITATION_ARRAY[i].totalPastRain / PRECIPITATION_ARRAY[i].times_it_rained))
        << endl;
    }
    
}


void Smallest_to_largest(struct precipitation PRECIPITATION_ARRAY[],string path)
{
    for (int i = 1; i < REGION_COUNT; i++)
    {

        precipitation key = PRECIPITATION_ARRAY[i];

        int j = i - 1;

        while (j >= 0 && PRECIPITATION_ARRAY[j].totalRain > key.totalRain)
        {
            PRECIPITATION_ARRAY[j+1] = PRECIPITATION_ARRAY[j];
            j--;
        }
        

        PRECIPITATION_ARRAY[j+1] = key;
    }
    create_file_with_Precipitation_array(PRECIPITATION_ARRAY, path);

}
void largest_to_smallest(struct precipitation PRECIPITATION_ARRAY[],string path)
{
    for (int i = 1; i < REGION_COUNT; i++)
    {

        precipitation key = PRECIPITATION_ARRAY[i];

        int j = i - 1;

        while (j >= 0 && PRECIPITATION_ARRAY[j].totalRain < key.totalRain)
        {
            PRECIPITATION_ARRAY[j+1] = PRECIPITATION_ARRAY[j];
            j--;
        }
        

        PRECIPITATION_ARRAY[j+1] = key;
    }
    create_file_with_Precipitation_array(PRECIPITATION_ARRAY, path);
}

int main()
{
    int FILE_array_size = 0;
    string path = "C:/UNI/PROGRAMING/FINAL 2nd parcial/texto.txt";
    string path_2 = "C:/UNI/PROGRAMING/FINAL 2nd parcial/Small_Large.txt";
    string path_3 = "C:/UNI/PROGRAMING/FINAL 2nd parcial/Large_Smalll.txt";;

    rainAnalyzer RAIN;
    ifstream values(path);
    
    while (!values.eof())
    {
        RAIN.set_fileVector(values,&FILE_array_size);
        FILE_array_size++;
    }

    //? UPDATE Preceipitation array
    RAIN.update_PRECIPITATION_array(&FILE_array_size);

    //? GET File array and PRINT it

    file* FILE_ARRAY = RAIN.get_FILE_array();

    for (int i = 0; i < FILE_array_size; i++)
    {
        cout << FILE_ARRAY[i].regionNumber << " | " 
        << FILE_ARRAY[i].rainAmount << " | " 
        << FILE_ARRAY[i].past_rainAmount << endl;

    }
    

    //? GET Precipitation Array, SORT it and CREATE file
    precipitation* PRECIPITATION_ARRAY = RAIN.get_PRECIPITATION_array();

    Smallest_to_largest(PRECIPITATION_ARRAY,path_2);
    largest_to_smallest(PRECIPITATION_ARRAY,path_3);


    
    
}