#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED

#include "Sculptor.h"
//Classe abstrata responsável por interligar outras classes para realizar o desenho
///Classe abstrata FiguraGeometrica responsável por interligar outras classes para representar objetos primitivos genéricos
class FiguraGeometrica{
protected:
    //cores e transparências
    float r,g,b,a;
public:
    //Construtor da classe
    FiguraGeometrica();
    //Destrutor Virtual
    virtual ~FiguraGeometrica(){};
    //recebe como parâmetro um objeto da classe sculptor
    //responsável pelos mais diversos desenhos
    //Será implementado nas classes herdeiras de acordo com as caracteristicas
    //apropriadas do desenho
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H_INCLUDED
