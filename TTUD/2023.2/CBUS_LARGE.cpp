#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int N;
int cap;
int A[2*MAX+1][2*MAX+1];
int x[2*MAX+1];
bool visited[2*MAX+1];
int load;
int f;
int f_best;
int x_best[2*MAX+1];
int cmin = 1e9;

bool check(int v, int k){
    if(visited[v]) return false;
    if(v > N){
        if(!visited[v-N]) return false;
    }else{
        if(load + 1 > cap) return false;
    }
    return true;
}

void solution(){
    if(f + A[x[2*N]][0] <= f_best){
        f_best = f + A[x[2*N]][0];
        for (int i = 1; i <= 2*N; i++){
            x_best[i] = x[i];
        }
    }
}

void TRY(int k){
    for(int v = 1; v <= 2 * N; v++){
        if(check(v,k)){
            x[k] = v;
            f += A[x[k-1]][x[k]];
            if(v <= N) load += 1; else load += -1;
            visited[v] = true;
            if(k == 2*N) solution();
            else if(f + (2*N+1-k)*cmin < f_best) TRY(k+1);
            if(v <= N) load -= 1; else load -= -1;
            visited[v] = 0;
            f -= A[x[k-1]][x[k]];
        }
    }
}

int main(){
    scanf("%d%d",&N,&cap);
    for(int i = 0; i <= 2*N;  i++){
        for(int j= 0; j <= 2*N; j++){
            scanf("%d",&A[i][j]);
            if(i != j && cmin > A[i][j]) cmin = A[i][j];
        }
    }

    load = 0;
    f = 0;
    f_best = 1000000;
    for(int i = 1; i <= 2*N; i++) visited[i] = false;
    x[0] = 0; x_best[0] = 0;
    TRY(1);
    printf("%d\n",N);
    for (int i = 1; i <= 2*N; i++){
        printf("%d ", x_best[i]);
    }
    return 0;
}
