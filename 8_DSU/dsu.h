class dsu{
    int size;

    public:
        int *parent;
        int *rank;

        dsu(int size){
            this->size = size;
            parent = new int[size];
            rank = new int[size];
            for(int i = 0; i < size; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x){
            if(parent[x] == x){
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void union_set(int x, int y){
            x = find(x);
            y = find(y);
            if(x != y){
                if(rank[x] < rank[y]){
                    swap(x, y);
                }
                parent[y] = x;
                if(rank[x] == rank[y]){
                    rank[x]++;
                }
            }
        }

        bool same(int x, int y){
            return find(x) == find(y);
        }

        ~dsu(){
            delete[] parent;
            delete[] rank;
        }

        void swap(int &x, int &y){
            int temp = x;
            x = y;
            y = temp;
        }
};