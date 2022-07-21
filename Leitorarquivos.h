#ifndef LEITORARQUIVOS_H_INCLUDED
#define LEITORARQUIVOS_H_INCLUDED
#include <vector>
#include "Figurageometrica.h"
#include <string>
using namespace std;
///Classe repons�vel pela leitura e interpreta��o do arquivo entrada.
class leitorarquivos{
    //Dimens�es para a matriz
    int dimX, dimY, dimZ;
    //Cores
    float r,g,b,a;

public:
    //Construtor
    leitorarquivos();
    ~leitorarquivos(){};
    //Gera uma lista das figuras que se quer desenha
    vector<FiguraGeometrica*> parse(string filename);
    int getDx();
    int getDy();
    int getDz();

};


#endif // LEITORARQUIVOS_H_INCLUDED
