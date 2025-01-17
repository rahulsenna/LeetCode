#define debug(...) cerr << __LINE__ << ": "; _setupvar(#__VA_ARGS__); _debug(__VA_ARGS__);
void _print(s64 t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(r64 t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(u64 t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _debug() {cerr << '\n';}
vector<string> VARS;int VAR_IDX = 0;
// void _setupvar(string v) {VARS = std::views::split(v, ',') | ranges::to<vector<string>>();VAR_IDX = 0;}
void _setupvar(const std::string& v) {
    std::vector<std::string> tokens;
    std::istringstream stream(v);
    std::string token;
    
    while (std::getline(stream, token, ','))
    {
        // Trim whitespace
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        tokens.push_back(token);
    }
    
    VARS = std::move(tokens);
    VAR_IDX = 0;
}
template<typename T, typename... Args>
void _debug(const T& first, const Args&... args) { cerr << VARS[VAR_IDX++] << ": "; _print(first); cerr << ", "; _debug(args...);}