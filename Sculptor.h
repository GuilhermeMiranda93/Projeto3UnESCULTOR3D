#ifndef SCULPTOR_H_INCLUDED
#define SCULPTOR_H_INCLUDED

#include "Voxel.h"
///Class Sculptor cont�m os m�todos necess�rios por outras classes para desenho do um objeto.
class Sculptor{

protected:
    Voxel ***v;
    int nx,ny,nz;
    float r,g,b,a;

public:
    //M�todo construtor
    Sculptor(int _nx, int _ny, int _nz);
    //M�todo destrutor
    ~Sculptor();
    //M�todo para definir a cor
    void setColor (float r, float g, float b, float alpha);
    //M�todo para adicionar um voxel
    void putVoxel (int x, int y, int z);
    //M�todo para retirar um voxel
    void cutVoxel (int x, int y, int z);
    //M�todo de escrita e gera��o do arquivo OFF
    int getx();
    int gety();
    int getz();
    void writeOFF(char *filename);

};


#endif // SCULPTOR_H_INCLUDED
