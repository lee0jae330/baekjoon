#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[13];

int main(void){
    fastio();
    for(int i=0;i<7;i++){
        int month ,day;
        cin >>month >> day;
        switch(month){
            case 1:
                if(day>=1&&day<=19){
                    arr[12]=1;
                }
                else{
                    arr[1]=1;
                }
            break;
            
            case 2:
                if(day>=1&&day<=18){
                    arr[1]=1;
                }
                else{
                    arr[2]=1;
                }
            break;
            
            case 3:
                if(day>=1&&day<=20){
                    arr[2]=1;
                }
                else{
                    arr[3]=1;
                }
            break;
            
            case 4:
                if(day>=1&&day<=19){
                    arr[3]=1;
                }
                else{
                    arr[4]=1;
                }
            break;
            
            case 5:
                if(day>=1&&day<=20){
                        arr[4]=1;
                    }
                  else{
                        arr[5]=1;
                    }
            break;
            
            case 6:
                if(day>=1&&day<=21){
                        arr[5]=1;
                    }
                  else{
                        arr[6]=1;
                }
            break;
            
            case 7:
                if(day>=1&&day<=22){
                        arr[6]=1;
                    }
                  else{
                        arr[7]=1;
                }
            break;
            
            case 8:
                if(day>=1&&day<=22){
                        arr[7]=1;
                    }
                  else{
                        arr[8]=1;
                }
            break;
            
            case 9:
                if(day>=1&&day<=22){
                        arr[8]=1;
                    }
                  else{
                        arr[9]=1;
                }
            break;
            
            case 10:
                if(day>=1&&day<=22){
                        arr[9]=1;
                    }
                  else{
                        arr[10]=1;
                }
            break;
            
            case 11:
                if(day>=1&&day<=22){
                        arr[10]=1;
                    }
                  else{
                        arr[11]=1;
                }
            break;
            
            default:
                if(day>=1&&day<=21){
                        arr[11]=1;
                    }
                  else{
                        arr[12]=1;
                }
        }
    }
    int N;
    vector<pair<int,int>>v;
    cin >>N;
    while(N--){
        int month , day;
        cin >> month>> day;
        switch(month){
        case 1:
                if(day>=1&&day<=19){
                    if(!arr[12])
                        v.push_back({month,day});
                }
                else{
                    if(!arr[1])
                        v.push_back({month,day});
                }
            break;
            
            case 2:
                if(day>=1&&day<=18){
                    if(!arr[1])
                        v.push_back({month,day});
                }
                else{
                    if(!arr[2])
                        v.push_back({month,day});
                }
            break;
            
            case 3:
                if(day>=1&&day<=20){
                    if(!arr[2])
                        v.push_back({month,day});
                }
                else{
                    if(!arr[3])
                        v.push_back({month,day});
                }
            break;
            
            case 4:
                if(day>=1&&day<=19){
                    if(!arr[3])
                        v.push_back({month,day});
                }
                else{
                    if(!arr[4])
                        v.push_back({month,day});
                }
            break;
            
            case 5:
                if(day>=1&&day<=20){
                        if(!arr[4])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[5])
                        v.push_back({month,day});
                    }
            break;
            
            case 6:
                if(day>=1&&day<=21){
                        if(!arr[5])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[6])
                        v.push_back({month,day});
                }
            break;
            
            case 7:
                if(day>=1&&day<=22){
                        if(!arr[6])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[7])
                        v.push_back({month,day});
                }
            break;
            
            case 8:
                if(day>=1&&day<=22){
                        if(!arr[7])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[8])
                        v.push_back({month,day});
                }
            break;
            
            case 9:
                if(day>=1&&day<=22){
                        if(!arr[8])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[9])
                        v.push_back({month,day});
                }
            break;
            
            case 10:
                if(day>=1&&day<=22){
                        if(!arr[9])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[10])
                        v.push_back({month,day});
                }
            break;
            
            case 11:
                if(day>=1&&day<=22){
                        if(!arr[10])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[11])
                        v.push_back({month,day});
                }
            break;
            
            default:
                if(day>=1&&day<=21){
                        if(!arr[11])
                        v.push_back({month,day});
                    }
                  else{
                        if(!arr[12])
                        v.push_back({month,day});
                }
        }
    }
    if(!v.size()){
        cout<< "ALL FAILED"<<'\n';   
    }
    else{
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout<< v[i].first<<' '<<v[i].second<<'\n';
    }
    return 0;
}