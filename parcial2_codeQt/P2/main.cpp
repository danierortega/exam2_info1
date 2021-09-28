#include <iostream>
#include <QImage>
#include <fstream>

using namespace std;

int main()
{
    //LECTURA DE IMAGEN
    string filename="../P2/images/mexico.jpg";
    QImage im(filename.c_str());

    //IMPRIME TAMAÑO DE IMAGEN
    cout<<im.width()<<"x"<<im.height()<<" pixels"<<endl;

    //ESCRITURA EN TXT
    ofstream archivo;
    archivo.open("datos.txt", ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir archivo";
        system("pause");
        system("reset");
    }


    //CICLO PARA REDUCIR
    string matrizLed[8][8];
    long double longiX=im.width();
    long double longiY=im.height();

    long double pasoX=0.0;
    long double pasoY=0.0;

        for(unsigned int y=0; y < 8; y++){
            //cout<<endl;
                for (unsigned int x=0; x < 8; x++){
                    matrizLed[x][y]=to_string(im.pixelColor(pasoX,pasoY).red())+","+
                            to_string(im.pixelColor(pasoX,pasoY).green())+","+
                            to_string(im.pixelColor(pasoX,pasoY).blue())+",";
                    //cout<<matrizLed[x][y]<<",";
                    pasoX=pasoX+(longiX/8);

                }
                pasoY=pasoY+(longiY/8);
                pasoX=0;
        }

   //ESCRIBIR EN datos.txt
     for(unsigned int y=0; y < 8; y++){
         cout<<endl;
             for (unsigned int x=0; x < 8; x++){
                 cout<<matrizLed[x][y];//muestra datos en terminal
                 archivo<<(matrizLed[x][y]);
             }
             archivo<<"\n";
     }

     archivo.close();
    return 0;
}
