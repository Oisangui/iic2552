#include <bits/stdc++.h>

using namespace std;

void mod_matriz(int iy,int ix,int matriz[][8],int mode){
    for (int x=0;x<8;x++){//columnas
        for (int y=0;y<8;y++){//filas
            if((y==iy+(x-ix))||(y==iy-x+ix)||(x==ix)||(y==iy)){
                if (mode==1)matriz[y][x]+=1;else matriz[y][x]-=1;
            }
        }
    }
}
void fun(vector<int>& solucion, int matriz[][8],int icol,int irow,int plus,int& index){
    if (solucion.size()==icol){
        solucion.push_back(irow);
        /* for (int i=0;i<solucion.size();i++){
            cout<<solucion[i]+1;
        }
        cout<<'\n'; */
        plus=1;
    }
    int x=9;
    int y=9;
    for (int i=0; i<8;i++){//por cada fila posible
        bool pasa=true;
        if (i==irow){
            continue;}
        for (int j=0; j<solucion.size(); j++){//nos aseguramos de que la fila no 
            if (i==solucion[j]) {pasa=false;}//este seleccionada
        }
        if ((pasa==true)&&(matriz[i][solucion.size()]==0)){
            solucion.push_back(i);
            int x=solucion.size()-1;
            int y=i;
            mod_matriz(y,x,matriz,1);
            /* for (int i=0;i<solucion.size();i++){
                cout<<solucion[i]+1;
            }
            cout<<'\n'; */
            fun(solucion,matriz,icol,irow,0,index);
            if(solucion.size()==8){
                if (index > 9) cout << index << "      ";
                else cout << " " << index << "      ";
                index+=1;
                for (int j=0; j<8; j++){
                cout<<solucion[j]+1;
                if (j!=7) {cout<<' ';}
                }
            cout<<'\n';   
            }
            for(int i=0;i<solucion.size();i++){
                if (solucion[i]==irow)plus=1;
                else plus=0;
            }
            //cout<<plus<<8888<<i<<'\n';
            if((plus==1)){//&&(i==7)){
                //cout<<"eliminando uno, queda en "<<solucion.size()-1<<" ";
                solucion.pop_back();
            }
            solucion.pop_back();
            mod_matriz(y,x,matriz,0);
        }
    }           
}
int main(){
ios::sync_with_stdio(false); 
cin.tie(0);   
vector<int> solucion(0,0);
int matriz[8][8]={};
int T;
cin>>T;
int irow=0;
int icol=0;
int index=1;
for (int i=0; i<T;i++){
    index=1;
    int matriz[8][8]={};
    vector<int> solucion(0,0);
    cin>>irow;
    cin>>icol;
    irow-=1;
    icol-=1;
    mod_matriz(irow,icol,matriz,1);
    if (i>0){
        cout<<'\n';
    }
    cout<<"SOLN       COLUMN\n"<<" #      1 2 3 4 5 6 7 8\n\n";
    fun(solucion, matriz, icol,irow,0,index);
}
return 0;
}

