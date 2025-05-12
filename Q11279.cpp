//maximum heap
//Q11279
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class heap{

    public:
        vector<int> date;
        
        heap(){
            date.push_back(-1);
        }
        void add(int addNumber){

            if(addNumber == 0){
                remove();
                return;
            }

            date.push_back(addNumber);
            int index = date.size() - 1;
            int me = index;
            while(index != 0){
                index /= 2; 

                if(index == 0) break;

                if(date[index] < date[me]){
                    int temp = date[me];
                    date[me] = date[index];
                    date[index] = temp;
                    me = index;
                }
            }

        }
        void remove(){

            if(date.size() == 1){
                print(0);
                return ;
            }

            else{
                print(date[1]);
                int temp = date[1];
                date[1] = date[date.size()-1];
                date[date.size()-1] = temp;
                date.pop_back();

            }

            int index = 1;
            int me = index;
            while(true){
                index = index * 2;

                if(index > date.size()-1){
                    break;
                }

                if(index+1 > date.size()-1){
                    if(date[index] > date[me]){
                        int temp = date[me];
                        date[me] = date[index];
                        date[index] = temp;
                        me = index;
                    }
                }
                else if(date[index] > date[me] || date[index+1] > date[me]){

                    index = date[index] > date[index+1] ? index : index+1;

                    int temp = date[me];
                    date[me] = date[index];
                    date[index] = temp;
                    me = index;
                }
            }
        }
        void print(int num){

            cout<<num<<'\n';
        }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    heap h;
    int n, x;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        h.add(x);
    }
}

