
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


class rainAnalyzer3
{
private:
    vector<file> FILE_VECTOR;
    vector <precipitation> PRECIPITATION_VECTOR;
public:
    rainAnalyzer3();

    vector<file> get_File_vector();
    vector<precipitation> get_Precipitation_vector();

    void copy_textFile_onto_vector(string path);
    void update_Precipitation_vector();
   
};

rainAnalyzer3::rainAnalyzer3()
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

vector<file> rainAnalyzer3 ::get_File_vector()
{
    return FILE_VECTOR;
}

vector<precipitation> rainAnalyzer3 :: get_Precipitation_vector()
{
    return PRECIPITATION_VECTOR;
}

void rainAnalyzer3 ::copy_textFile_onto_vector(string path)
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

void rainAnalyzer3 ::update_Precipitation_vector()
{
    for (file& element : FILE_VECTOR)
    {
        int auxiliary = element.regionNumber;
        PRECIPITATION_VECTOR[auxiliary -1].totalRain += element.rainAmount;
        PRECIPITATION_VECTOR[auxiliary -1].totalPastRain += element.past_rainAmount;
        PRECIPITATION_VECTOR[auxiliary -1].times_it_rained++;
        
    }
    
}