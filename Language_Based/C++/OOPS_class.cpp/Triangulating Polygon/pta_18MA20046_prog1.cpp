/*
Name : Swapnanil Halder
Roll No. : 18MA20046

The code written is based on modified earclipping method.
The algorithm consists of finding such an ear/triangle, removing it from the polygon
which results in a new polygon that still meets the conditions and repeating until there is only one triangle left.
The running time complexity of the code is O(n*n).
In this code we go through each vertex of the polygon and check if we can cutoff the ear/triangle from the polygon.
We cut an ear from a polygon only when the angle between two edges is less than 180 (i.e that part of the polygon is convex)
and there doesnot lie any point inside the ear/triangle so that when we draw diagonal it does not cut any edge or diagonal.
The checking condition of each vertex take O(n) time, so for n vertices of a polygon the time complexity becomes O(n*n).

Some arbitrary inputs of this function are provided below..
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Coordinates
{
  float x, y;
};

vector<Coordinates> global;

class Polygon
{
    private:
        vector<Coordinates> poly;

        // Function to check if a vertex is a ear (i.e. it holds angle < 180 degree)
        int isVertexEar(int n, const vector<Coordinates> &p)
        {
            if (isVertexInsideNewPoly(n, p) && !isEdgeIntersect(n, p)) {
                // cout << "Is Vertex Ear : " << p[n].x << ", " << p[n].y << endl;
                return true;
            }
            return false;
        }

        int isEdgeIntersect(int n, const vector<Coordinates> &p)
        {
            Coordinates v = p[n];
            vector<Coordinates> a;

            for (size_t i = 0; i < p.size(); i++)
                if (i != n)
                    a.push_back(p[i]);

            int c = 0, cnt = a.size(), prev = (cnt + (n - 1)) % cnt, next = n % cnt;

            Coordinates v1 = a[prev], v2 = a[next];

            for (size_t i = 0, j = cnt - 1; i < cnt; j = i++)
            {
                if (prev == i || prev == j || next == i || next == j)
                    continue;

                Coordinates v4 = a[j], v3 = a[i];

                float denominator = ((v4.y - v3.y) * (v2.x - v1.x)) - ((v4.x - v3.x) * (v2.y - v1.y));

                if (!denominator)
                    continue;

                float ua = (((v4.x - v3.x) * (v1.y - v3.y)) - ((v4.y - v3.y) * (v1.x - v3.x))) / denominator;
                float ub = (((v2.x - v1.x) * (v1.y - v3.y)) - ((v2.y - v1.y) * (v1.x - v3.x))) / denominator;

                //float x = v1.x + (ua * (v2.x - v1.x)), y = v1.y + (ua * (v2.y - v1.y));

                if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1) {
                    c = 1;
                    break;
                }
            }
            // if(!c) cout << "IsEdgeIntersect : " << p[n].x << ", " << p[n].y  << endl;
            return c;
        }

        int isVertexInsideNewPoly(int n, const vector<Coordinates> &p)
        {
            Coordinates v = p[n];
            vector<Coordinates> a;

            for (size_t i = 0; i < p.size(); i++)
                if (i != n)
                    a.push_back(p[i]);

            int c = 1;

            for (size_t i = 0, j = a.size() - 1; i < a.size(); j = i++) {
                if ((((a[i].y <= v.y) && (v.y < a[j].y)) || ((a[j].y <= v.y) && (v.y < a[i].y))) && (v.x > (a[j].x - a[i].x) * (v.y - a[i].y) / (a[j].y - a[i].y) + a[i].x))
                    c = !c;
            }
            // if(c) cout << "Is vertex Inside New Poly: " << p[n].x << ", " << p[n].y << endl;
            return c;
        }

        float dist(Coordinates a, Coordinates b)
        {
            return sqrt(  ((a.x - b.x) * (a.x - b.x)) + (((a.y - b.y) * (a.y - b.y)))  );
        }

    public:
        void push(const Coordinates &p)
        {
            poly.push_back(p);
        }

        void pop()
        {
            if (poly.size() > 0)
                poly.pop_back();
        }

        void clear()
        {
            poly.clear();
        }

        Coordinates v(int index) {
            return poly[index];
        }

        size_t size() {
            return poly.size();
        }

        void triangulate() 
        {
            vector<Coordinates> a;

            for (size_t i = 0; i < poly.size(); i++) {
                a.push_back(poly[i]);
            }

            poly.clear();

            for (size_t t = a.size() - 1, i = 0, j = 1; i < a.size(); t = i++, j = (i + 1) % a.size()) {
                if (a.size() == 3) {
                    poly.push_back(a[0]);
                    poly.push_back(a[1]);
                    poly.push_back(a[2]);

                    break;
                }

                if (isVertexEar(i, a)) {
                    poly.push_back(a[t]);
                    poly.push_back(a[i]);
                    poly.push_back(a[j]);
                    // cout <<endl<<"[1] : "<<a[t].x << " "<<a[t].y <<"   "<< "[2] : "<<a[j].x << " "<<a[j].y;
                    

                    // Printing out the outputs
                    for(int i = 0; i<global.size(); i++) {
                        
                        if(global[i].x == a[t].x && global[i].y == a[t].y) {
                            cout << "   ("<<i+1<<",";
                            break;
                        }
                    }
                    for(int i = 0; i<global.size(); i++) {
                        if(global[i].x == a[j].x && global[i].y == a[j].y) {
                            cout <<i+1<<") ;";
                            break;
                        }
                    }

                    a.erase(a.begin() + i, a.begin() + i + 1);

                    t = a.size() - 1;
                    i = 0;
                    j = 1;
                }
            }
        }
};

int main() {
    Polygon poly;
    vector<Coordinates> tempv;
    
    int t;
    cout << "Enter the no. of points : ";  cin >> t; cout << "Enter the points of the polygon in clockwise in each line : (both coordinates with a space separation)\n";
    for (int i = 0; i < t; i++) {
        float n1, n2;
        cin >> n1 >> n2;
        Coordinates temp = {n1, n2};
        tempv.push_back(temp);
        global.push_back(temp);
    }
    reverse(tempv.begin(), tempv.end());
    for(int i = 0; i<t; i++) {
        poly.push(tempv[i]);
    }
    cout <<endl;
    cout << "The polygon can be triangulated by joining these vertices :\n";
    poly.triangulate();
    cout <<endl;
    // for (int i = 0; i < poly.size(); i++)
    // {
    //     Coordinates temp = poly.v(i);
    //     // cout << temp.x << " , " << temp.y <<"   ;   ";   if(i%3 == 2) cout << endl;
    // }
    // cout << "Size : " << poly.size() <<endl;
}

/*

Inputs : (Copy and Paste)

8
0 10
7 12
9 1
15 7
20 0
15 -3
1 0
5 5

13
10 0
0 0
5 10
0 20
10 10
20 20
30 10
40 20
50 10
50 0
40 10
30 0
20 10

24
0 2
1 3
0 4
1.6 4.6
0.8 3.5
4 3
3 5
5 5
5 3
4 4
5 2
4 1
3 2
3 3
2 2
3 1
2 -1
2.5 -1.5
2 -2
0.8 1
1 2
-2 0
-2 -1
-3 1
*/