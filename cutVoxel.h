#ifndef CUTVOXEL_H_INCLUDED
#define CUTVOXEL_H_INCLUDED

#include "Figurageometrica.h"
///Classe cutVoxel derivada da classe FiguraGeometrica.
///
///Um voxel deverá ser especificado para remoção conforme sua posição no espaços.
class cutVoxel:public FiguraGeometrica{
    int x; int y; int z;
public:
    cutVoxel(int x, int y, int z);
    ~cutVoxel(){};
    void draw(Sculptor &t);
};


#endif // CUTVOXEL_H_INCLUDED
