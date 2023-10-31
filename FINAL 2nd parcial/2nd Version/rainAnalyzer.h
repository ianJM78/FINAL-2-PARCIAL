#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

const int REGION_COUNT = 6;


struct file
{
    int  regionNumber;
    int rainAmount;
    int past_rainAmount;
};

struct precipitation
{
    int region;
    int times_it_rained;
    int totalRain;
    int totalPastRain;
};

class rainAnalyzer
{
private:
    file FILE_ARRAY[100];
    precipitation PRECIPITACION_ARRAY[REGION_COUNT];
public:
    rainAnalyzer();
    void set_fileVector(ifstream& value,int* FILE_array_size);
    void update_PRECIPITATION_array(int* FILE_array_size);
    file* get_FILE_array();
    precipitation* get_PRECIPITATION_array();
};

rainAnalyzer::rainAnalyzer()
{
    for (int i = 0; i < REGION_COUNT; i++)
    {
        PRECIPITACION_ARRAY[i].region = (i+1);   //! From 1 to REGION_COUNT.
        PRECIPITACION_ARRAY[i].times_it_rained = 0;
        PRECIPITACION_ARRAY[i].totalRain = 0;
        PRECIPITACION_ARRAY[i].totalPastRain = 0;
    }
}

void rainAnalyzer ::set_fileVector(ifstream& value,int* FILE_array_size)
{
    value >> FILE_ARRAY[*FILE_array_size].regionNumber >> FILE_ARRAY[*FILE_array_size].rainAmount >> FILE_ARRAY[*FILE_array_size].past_rainAmount;
}

void rainAnalyzer ::update_PRECIPITATION_array(int* FILE_array_size) 
{
    // for all elmenents is FILE array
    for (int i = 0; i < *FILE_array_size; i++)
    {
        // We get the value of the region at the "i" iteration
        int auxiliary = FILE_ARRAY[i].regionNumber;

        //* if its 1, we access the PRECIPITATION vector at the index equivalent to the region we are on currently itterating on the FILE array (region number - 1) and modify values to the required values in said vector
        PRECIPITACION_ARRAY[auxiliary - 1].totalRain += FILE_ARRAY[i].rainAmount;
        PRECIPITACION_ARRAY[auxiliary - 1].totalPastRain += FILE_ARRAY[i].past_rainAmount;
        PRECIPITACION_ARRAY[auxiliary - 1].times_it_rained++;
    }     
}


precipitation *rainAnalyzer::get_PRECIPITATION_array()
{
    return PRECIPITACION_ARRAY;
}

file *rainAnalyzer::get_FILE_array()
{
    return FILE_ARRAY;
}


