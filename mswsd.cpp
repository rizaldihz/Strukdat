#include<bits/stdc++.h>
using namespace std;

//belum buka

pair< vector<vector<int> >, vector<vector<bool> > > init(int besar)
{
    vector<vector<int> > layerBack;
    vector<vector<bool> > layerFront;

    for(int i=0;i<besar;i++){
        vector<int> BackTemp;
        vector<bool> FrontTemp;
        for(int j=0;j<besar;j++){
            BackTemp.push_back(0);
            FrontTemp.push_back(true);
        }
        layerBack.push_back(BackTemp);
        layerFront.push_back(FrontTemp);

        BackTemp.clear();
        FrontTemp.clear();
    }

    return make_pair(layerBack,layerFront);
}

void Display(vector<vector<int> > temp,vector<vector<bool> > depan)
{
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            if(depan[i][j]==true)
                cout<<"X ";
            else{
                if(temp[i][j]==-1)
                    cout<<"B ";
                else if(temp[i][j]==0)
                    cout<<"  ";
                else cout << temp[i][j] << " ";
            }
        }
        cout<<endl;
    }
}

void makebomb(int nbomb, vector<vector<int> > &layer)
{
    srand(time(NULL));
    int besar=layer.size();

    for(int i=0;i<nbomb;i++){
        int x=rand() % besar;
        int y=rand() % besar;

        if(layer[x][y]!=-1) layer[x][y]=-1;
        else i--;
    }
}

void makenum(vector<vector<int> > &layer)
{
    for(int i=0;i<layer.size();i++){
        for(int j=0;j<layer[i].size();j++){
            if(layer[i][j]==-1){
                if(i-1>=0){
                    if(j-1>=0&&layer[i-1][j-1]>-1)
                        layer[i-1][j-1]++;
                    if(layer[i-1][j]>-1)
                        layer[i-1][j]++;
                    if(j+1<layer[i].size()&&layer[i-1][j+1]>-1)
                        layer[i-1][j+1]++;
                }
                if(j-1>=0&&layer[i][j-1]>-1)
                    layer[i][j-1]++;
                if(j+1<layer[i].size()&&layer[i][j+1]>-1)
                    layer[i][j+1]++;
                if(i+1<layer.size()){
                    if(j-1>=0&&layer[i+1][j-1]>-1)
                        layer[i+1][j-1]++;
                    if(layer[i+1][j]>-1)
                        layer[i+1][j]++;
                    if(j+1<layer[i].size()&&layer[i+1][j+1]>-1)
                        layer[i+1][j+1]++;
                }
            }
        }
    }
}

int main()
{
    int besar=16;

    pair< vector<vector<int> >, vector<vector<bool> > > res=init(besar);

    vector<vector<int> > layerBack=res.first;
    vector<vector<bool> > layerFront=res.second;

    makebomb(27,layerBack);
    makenum(layerBack);
    Display(layerBack,layerFront);
}
