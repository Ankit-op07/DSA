/*
Breadth first traversal
we traverse levelwise in bfs
level order traversal

How to implement

 * we will use queue data structure to implement bfs
 * Visited array
 *
 */
 /* NORMAL BFS CODE----

 #include<bits/stdc++.h>
 using namespace std;

 const int N = 1e5+10;

 vector<int>g[N];
 //visited array
 int vis[N];
 int level[N]
 //source = from where our bfs will start
 void bfs(int source){
  //created a queue because of fifo
 queue<int>q;
 //pushed the node
 q.push(source);
 //mark it visited
 vis[source]=1;
 //traversing the full level and inserting their childs in the queue
 while(!q.empty()){
    int cur_v = q.front();
    q.pop();
    for(auto child : g[cur_v]){
    if(!vis[chile]){
        q.push(child);
        vis[child]=1;
        level[child]= level[cur_v]+1;
    }
    }
 }



 }
 int main(){

     int tc;cin>>tc;
     while(tc--){
         string s1,s2;
     cin>>s1>>s2;


     }
     int n;cin>>n;

     for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
          g[y].push_back(x);

     }
 }
 */
 // prbolem SPOJ NAKANJ
 //Matrix problem solved using bfs
  #include<bits/stdc++.h>
 using namespace std;
 const int N = 1e5+10;
 const int INF = 1e9+10;
 vector<int>g[N];

 //visited array
 int vis[8][8];
 int lev[8][8];
 //source = from where our bfs will start

 //for co-ordinates
 int getX(string s){
 return s[0]-'a';
 }
  int getY(string s){
 return s[1]-'1';
 }
 //for co-ordinates


 bool isValid(int x,int y){
     return x>=0 && y>=0 && x<8 && y <8;
 }
 //For movements

 vector<pair<int,int>> movements = {
 {-1,2}, {1,2},
  {-1,-2}, {1,-2},
   {2,-1}, {2,1},
   {-2,-1}, {-2,1}

 };
 //For movements


 int  bfs(string source ,string dest){
 int sourceX=getX(source);
 int sourceY=getY(source);
 int destX=getX(dest);
 int destY=getY(dest);

 // in matrix type questions we will create queue of pairs
 queue<pair<int,int>>q;
 q.push({sourceX,sourceY});
 vis[sourceX][sourceY]=1;
 lev[sourceX][sourceY]=0;

 while(!q.empty()){
    pair<int,int> v = q.front();
    int x= v.first, y= v.second; //parent
    q.pop();

   for(auto movement :movements){ // CHilds
        int X= movement.first+x;
        int Y = movement.second+y;


    if(isValid(X,Y)){
        if(!vis[X][Y]){
                pair<int,int> p={X,Y};
                q.push(p);
                lev[X][Y]=lev[x][y]+1;
                vis[X][Y]=1;
        }
    }
   }
    if(lev[destX][destY] != INF){
    break;
 }

 }



return lev[destX][destY];
 }

 void reset(){

 for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        lev[i][j]=INF;
        vis[i][j]=0;
    }
 }

 }

  int main(){

     int tc;cin>>tc;
     while(tc--){

         string s1,s2;
     cin>>s1>>s2;
      reset();
     cout<<bfs(s1,s2)<<endl;

     }


 }
