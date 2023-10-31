
#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>
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


class rainAnalyzer2
{
private:
    vector<file> FILE_VECTOR;
    vector <precipitation> PRECIPITATION_VECTOR;
public:
    rainAnalyzer2();
    void copy_textFile_onto_vector(string path);
    vector<file> get_File_vector();
    vector<precipitation> get_Precipitation_vector();
    void update_Precipitation_vector();
    void create_file_with_update_Precipitation_vector(string path);
    void sort_Smallest_to_Largest();
    void sort_Largest_to_Smallest();
};

rainAnalyzer2::rainAnalyzer2()
{
    for (int i = 0; i < REGION_COUNT; i++)
    {
        precipitation auxiliary;
        auxiliary.region = (i+1);
        auxiliary.times_it_rained = 0;
        auxiliary.totalPastRain = 0;
        auxiliary.totalRain = 0;
        PRECIPITATION_VECTOR.push_back(auxiliary);
    }
}

vector<file> rainAnalyzer2 ::get_File_vector()
{
    return FILE_VECTOR;
}

vector<precipitation> rainAnalyzer2 :: get_Precipitation_vector()
{
    return PRECIPITATION_VECTOR;
}

void rainAnalyzer2 ::copy_textFile_onto_vector(string path)
{
    ifstream values(path);

    if (!values.is_open()) {
        cerr << "Error opening file: " << path << endl;
        exit(EXIT_FAILURE); // Exit the program with an error code
    }

    while (!values.eof())
    {
        file auxiliary;
        values >> auxiliary.regionNumber >> auxiliary.rainAmount >> auxiliary.past_rainAmount;
        FILE_VECTOR.push_back(auxiliary);
    }
    
}

void rainAnalyzer2 ::update_Precipitation_vector()
{
    for (file& element : FILE_VECTOR)
    {
        int auxiliary = element.regionNumber;
        PRECIPITATION_VECTOR[auxiliary -1].totalRain += element.rainAmount;
        PRECIPITATION_VECTOR[auxiliary -1].totalPastRain += element.past_rainAmount;
        PRECIPITATION_VECTOR[auxiliary -1].times_it_rained++;
        
    }
    
}

void rainAnalyzer2 ::create_file_with_update_Precipitation_vector(string path)
{
    ofstream values(path);

    for (precipitation& element : PRECIPITATION_VECTOR)
    {
        values << element.region << " | " << element.totalRain << " | " << (element.totalRain / element.times_it_rained)
        << " | " << abs((element.totalRain / element.times_it_rained) - (element.totalPastRain / element.times_it_rained))
        << endl;
    }
    
}

void rainAnalyzer2 ::sort_Smallest_to_Largest()
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
}

void rainAnalyzer2 ::sort_Largest_to_Smallest()
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
}

