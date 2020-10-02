// g++ astar.cpp -o astar && ./astar
#include <bits/stdc++.h>
using namespace std;


map<int, string> city; // assigning a no to every city

vector<int> st_dis(25); // straight distance

void make_graph(){
    
    city.insert(pair<int, string>(1,"Arad"));
    city.insert(pair<int, string>(2,"Bucharest"));
    city.insert(pair<int, string>(3,"Craiova"));
    city.insert(pair<int, string>(4,"Dobreta"));
    city.insert(pair<int, string>(5,"Eforie"));
    city.insert(pair<int, string>(6,"Fagaras"));
    city.insert(pair<int, string>(7,"Giurgiu"));
    city.insert(pair<int, string>(8,"Hirsova"));
    city.insert(pair<int, string>(9,"Iasi"));
    city.insert(pair<int, string>(10,"Lugoj"));
    city.insert(pair<int, string>(11,"Mehadia"));
    city.insert(pair<int, string>(12,"Neamt"));
    city.insert(pair<int, string>(13,"Oradea"));
    city.insert(pair<int, string>(14,"Pitesti"));
    city.insert(pair<int, string>(15,"Rimnicu Vilcea"));
    city.insert(pair<int, string>(16,"Sibiu"));
    city.insert(pair<int, string>(17,"Timisoara"));
    city.insert(pair<int, string>(18,"Urziceni"));
    city.insert(pair<int, string>(19,"Vaslui"));
    city.insert(pair<int, string>(20,"Zerind"));


    st_dis[1] = 366;
    st_dis[2] = 0;
    st_dis[3] = 160;
    st_dis[4] = 242;
    st_dis[5] = 161;
    st_dis[6] = 178;
    st_dis[7] = 77;
    st_dis[8] = 151;
    st_dis[9] = 226;
    st_dis[10] = 244;
    st_dis[11] = 241;
    st_dis[12] = 234;
    st_dis[13] = 380;
    st_dis[14] = 98;
    st_dis[15] = 193;
    st_dis[16] = 253;
    st_dis[17] = 329;
    st_dis[18] = 80;
    st_dis[19] = 199;
    st_dis[20] = 374;
}

// heap
vector<pair<int, int>> heap(30);
int hp_last = 1;

void insert(pair<int, int> temp){
    
    heap[hp_last].first = temp.first;
    heap[hp_last].second = temp.second;

    int last = hp_last++;

    while(last > 1){
        if()
    }


}

int main(){

    
    make_graph();
    for(int i = 1; i < 21; i++) cout << city[i] << " " << st_dis[i] << endl;

}