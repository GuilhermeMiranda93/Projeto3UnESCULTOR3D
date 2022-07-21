#include <iostream>
#include <vector>
#include "Figurageometrica.h"
#include "Sculptor.h"
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"
#include "Leitorarquivos.h"

using namespace std;

int main (){
    //ponteiro da classe sculptor para se adequar as dimens�es da matriz deseja
    Sculptor *t1;
    //objeto da classe arquivo que fara a interpreta��o do arquivo de entrada
    leitorarquivos dg;

    vector <FiguraGeometrica*> figs;
    //arquivo a ser lido
    figs = dg.parse("entrada.txt");
    //aloca��o din�mica do objeto t1 da classe sculptor de arcordo com os dados retornados da classe leitorarquivos
    t1= new Sculptor(dg.getDx(),dg.getDy(),dg.getDz());
    //caminho sobre o vetor figs e desenho dos objetos contidos nele
    for(size_t i=0; i<figs.size();i++){
        cout <<"desenhando..."<<endl;
        figs[i]->draw(*t1);//realiza��o do desenho
    }
    //arquivo de saida
    t1->writeOFF((char*)"Desenho.off");
    //desaloca��o da memoria do vetor figs
    for(size_t i=0;i<figs.size(); i++){
        delete figs[i];
    }
    //libera��o de memoria para o objeto da classe sculptor
    delete t1;

    return 0;


}
