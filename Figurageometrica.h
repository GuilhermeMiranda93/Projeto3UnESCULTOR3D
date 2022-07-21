#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED

#include "Sculptor.h"
//Classe abstrata respons�vel por interligar outras classes para realizar o desenho
///Classe abstrata FiguraGeometrica respons�vel por interligar outras classes para representar objetos primitivos gen�ricos
class FiguraGeometrica{
protected:
    //cores e transpar�ncias
    float r,g,b,a;
public:
    //Construtor da classe
    FiguraGeometrica();
    //Destrutor Virtual
    virtual ~FiguraGeometrica(){};
    //recebe como par�metro um objeto da classe sculptor
    //respons�vel pelos mais diversos desenhos
    //Ser� implementado nas classes herdeiras de acordo com as caracteristicas
    //apropriadas do desenho
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H_INCLUDED
