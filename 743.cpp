#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

std::unordered_map<int, std::unordered_map<int,int>> edges;
std::vector<int> flags;
void traverse(int point,int time){
	printf("%d ==> %d\n",point,time);
	flags[point] = 1;
	auto iter  = edges.find(point);
	if(iter != edges.end()){
		for(auto &kv: iter->second){
			if(!flags[kv.first]){
				traverse(kv.first,kv.second + time);		
			}

		}
	}


}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	flags = std::vector<int>(n+1,0);
	for(int i = 0;i < times.size();i++){
		auto &edge = times[i];
		edges[edge[0]][edge[1]] = edge[2];
	}
	traverse(k,0);
	return -1;
}

int main(){
	std::vector<std::vector<int>> v= {
		{1,2,3},
		{2,3,2},
		{1,3,4},
		{3,4,1},
		{2,5,1}
	};
	networkDelayTime(v,5,1);

					
}

