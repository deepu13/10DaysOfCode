
#include <bits/stdc++.h>

using namespace std;

struct Vec2i
{
    int x, y;
    Vec2i(int _x, int _y) : x(_x), y(_y) {}
    Vec2i() { x = y = 0; }
    
    Vec2i& operator+=(const Vec2i& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    double length()
    {
        return sqrt(x*x + y*y);
    }

};

inline Vec2i operator+(const Vec2i& l, const Vec2i& r)
{
    return { l.x + r.x, l.y + r.y };
}

inline Vec2i operator-(const Vec2i& l, const Vec2i& r)
{
    return { l.x + r.x, l.y + r.y };
}

inline bool operator==(const Vec2i& l, const Vec2i& r)
{
    return l.x == r.x && l.y == r.y;
}

struct State
{
    Vec2i pos;
    int moves;
};

inline bool operator==(const State& a, const State& b)
{
    return a.pos == b.pos;
}

int pathfind(int n, int a, int b)
{
    int d = sqrt(a*a + b*b);
    
    vector<Vec2i> dirs = {
        { a, b },
        { -a, b },
        { -a, -b },
        { a, -b },
        { b, a },
        { -b, a },
        { -b, -a },
        { b, -a }
    };
    
    auto compare = [n,d](const State& a, const State& b)
    {
        double l0 = a.moves * d + (Vec2i(n, n) - a.pos).length();
        double l1 = b.moves * d + (Vec2i(n, n) - b.pos).length();
        return l0 < l1;
    };

    vector<State> active, visited;
    
    active.push_back({ { 0, 0 }, 0 });
    
    while(active.size() > 0)
    {
        sort(active.begin(), active.end(), compare);
        auto current = active[0];
        active.erase(active.begin());
        visited.push_back(current);
        
        if(current.pos.x == n - 1 && current.pos.y == n - 1)
        {
            return current.moves;
        }
        
        for(Vec2i d : dirs)
        {
            Vec2i p = current.pos + d;
            
            if(p.x < 0 || p.y < 0 || p.x >= n || p.y >= n)
            {
                continue;
            }
            
            State newState = { p, current.moves + 1};
            
            if(find(visited.begin(), visited.end(), newState) == visited.end())
            {
                auto v = find(active.begin(), active.end(), newState);
                
                if(v != active.end())
                {
                    if(compare(newState, *v)) 
                    {
                        swap(*v, newState);
                    }
                }
                else
                {
                    active.push_back(newState);
                }
                
            }
            
        }
        
    }
    
    return -1;
}

vector<vector<int>> knightlOnAChessboard(int n) 
{
    vector<vector<int>> result(n-1);

    for(auto &v : result)
    {
        v=vector<int>(n-1);
    }

    for(int a=1;a<n;a++)
    {
        for(int b=1;b<n;b++)
        {
            result[a-1][b-1]=pathfind(n,a,b);
        }
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) 
    {
        for (int j = 0; j < result[i].size(); j++) 
        {
            fout << result[i][j];

            if (j != result[i].size() - 1) 
            {
                fout << " ";
            }
        }

        if (i != result.size() - 1) 
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}