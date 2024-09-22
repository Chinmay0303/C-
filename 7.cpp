#include<iostream>
using namespace std;

int main()
{

int traits=2;
int n=traits*2;

bool gene[n]={1,0,1,0};

for(int i=0;i<n;i++){
    cout<<gene[i];
    if((i+1)%2==0)
    cout<<" ";
}
cout<<endl;

int allcomb=1<<traits;
int m=traits*allcomb;

bool comb[m]={0,};
int count=0;
for(int i=0;i<allcomb;i++){
    for(int j=0; j<traits;j++){
        bool alllele= i & (1<<j);
        comb[count++]=gene[(2*j)+alllele];
    }
}

bool p1[m];
bool p2[m];

for(int i=0;i<m;i++){
    cout<<comb[i];
    p1[i]=comb[i];
    p2[i]=comb[i];
    if((i+1)%traits==0)
    cout<<" ";
}
cout<<endl;
int k=1;
for(int i=0;i<allcomb;i++){
    for(int j=0;j<allcomb;j++){
        bool off[n]={0,};
        for(int t=0;t<traits;t++){
                off[2*t]=p1[traits*i+t];
                off[2*t+1]=p2[traits*j+t];
        }
        cout<<"Offspring"<<k++<<": ";
        for(int t=0;t<n;t++){
            cout<<off[t];
            if((t+1)%2==0){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

char traitsarr[6][20]={"Wrinkled","Round","Green","Yellow","Dwarf","Tall"};

for(int i=0;i<6;i++){
    cout<<traitsarr[i]<<" ";
}

return 0;

}