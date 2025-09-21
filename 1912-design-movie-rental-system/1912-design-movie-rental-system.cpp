struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 20) ^ p.second;
    }
};

class MovieRentingSystem {
public:
    struct Entry {
        int price, shop, movie;
        bool operator<(const Entry& other) const {
            if (price != other.price) return price < other.price;
            if (shop != other.shop) return shop < other.shop;
            return movie < other.movie;
        }
    };

    unordered_map<pair<int,int>, int, PairHash> priceMap;
    unordered_map<int, set<Entry>> availableByMovie;
    set<Entry> available;
    set<Entry> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[{shop, movie}] = price;
            Entry entry = {price, shop, movie};
            available.insert(entry);
            availableByMovie[movie].insert(entry);
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto& e : availableByMovie[movie]) {
            res.push_back(e.shop);
            if (res.size() == 5) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        Entry e = {price, shop, movie};
        available.erase(e);
        availableByMovie[movie].erase(e);
        rented.insert(e);
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        Entry e = {price, shop, movie};
        rented.erase(e);
        available.insert(e);
        availableByMovie[movie].insert(e);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto& e : rented) {
            res.push_back({e.shop, e.movie});
            if (res.size() == 5) break;
        }
        return res;
    }
};
