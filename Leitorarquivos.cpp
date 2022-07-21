#include "Leitorarquivos.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>//lidar com arquivos
#include <sstream>//para fluxo de dados
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"

using namespace std;

//Construtor padrão
leitorarquivos::leitorarquivos(){
}
//Método recebe um arquivo de entrada
vector<FiguraGeometrica*> leitorarquivos::parse(string filename){
    //vetor figs que vai listar as estruturas desejadas
    vector <FiguraGeometrica*> figs;
    //arquivo de entrada
    ifstream entrada;
    //fluxo
    stringstream ss;
    //fluxos auxiliares
    string s, token;

    //abertura do arquivo de entrada
    entrada.open(filename.c_str());

    //Para Erro na abertura do arquivo
    //cout <<"Abrindo o arquivo"<<filename<<"..."<<endl;
    if(!entrada.is_open()){
        cout<<"Erro na abertura do arquivo!\n";
        exit(0);
    }

    while(getline(entrada,s)){
        //leitura de linha a linha do arquivo de entrada
            ss.clear();//limpeza do fluxo
            ss.str(s);//inicialização do fluxo de entrada
            ss>>token;
            cout<<token<<" ";

            if(token.compare("dim")==0){
                ss>>dimX>>dimY>>dimZ;
            }

            else if(token.compare("putvoxel")==0){
                int x,y,z;
                ss>>x>>y>>z>>r>>g>>b>>a;
                figs.push_back(new putVoxel(x,y,z,r,g,b,a));
            }

            else if(token.compare("cutvoxel")==0){
                int x,y,z;
                ss>>x>>y>>z;
                figs.push_back(new cutVoxel(x,y,z));
            }

            else if(token.compare("putbox")==0){
                int x0,x1,y0,y1,z0,z1;
                ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
                figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
            }

             else if(token.compare("cutbox")==0){
                int x0,x1,y0,y1,z0,z1;
                ss>>x0>>x1>>y0>>y1>>z0>>z1;
                figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
            }

            else if(token.compare("putsphere")==0){
                int xc,yc,zc,rad;
                ss>>xc>>yc>>zc>>rad>>r>>g>>b>>a;
                figs.push_back(new putSphere(xc,yc,zc,rad,r,g,b,a));
            }

            else if(token.compare("cutsphere")==0){
                int xc,yc,zc,rad;
                ss>>xc>>yc>>zc>>rad;
                figs.push_back(new cutSphere(xc,yc,zc,rad));
            }

             else if(token.compare("putellipsoid")==0){
                int xc,yc,zc,rx,ry,rz;
                ss>>xc>>yc>>zc>>rx>>ry>>rz>>r>>g>>b>>a;
                figs.push_back(new putEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
            }

            else if(token.compare("cutEllipsoid")==0){
                int xc,yc,zc,rx,ry,rz;
                ss>>xc>>yc>>zc>>rx>>ry>>rz;
                figs.push_back(new cutEllipsoid(xc,yc,zc,rx,ry,rz));
            }
    }

    entrada.close();//fechando arquivo
    return (figs);
}
//Métodos para retornar a dimensão da matriz
int leitorarquivos::getDx(){
    return dimX;
}

int leitorarquivos::getDy(){
    return dimY;
}

int leitorarquivos::getDz(){
    return dimZ;
}
