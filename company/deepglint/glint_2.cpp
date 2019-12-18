#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>
#include <omp.h>
using namespace std;

typedef std::array<int, 4> BBox;

inline float BBox_IOU(BBox& a, BBox& b) {
    int w = std::min(a[2], b[2]) - std::max(a[0], b[0]);
    if(w <= 0) return 0.0f;
    int h = std::min(a[3], b[3]) - std::max(a[1], b[1]);
    if(h <= 0) return 0.0f;
    return 1.0f;
}

inline bool exist_cross(BBox& bbox, std::vector<BBox>& target_bbox) {
    for(int i = 0; i < target_bbox.size(); i++) {
        // if(target_bbox[i][0] > bbox[2] && target_bbox[i][1] > bbox[3]) break;
        if(BBox_IOU(bbox, target_bbox[i]) > 0.0f) {
            return true;
        }
    }
    return false;
}

// #define DEEP_TEST 1

int main() {
    int w = 0, h = 0, s = 0, t = 0;
    int k = 0;
    int P = 0;
    int Q = 0;
#ifdef DEEP_TEST
    std::ifstream cin("glint_2.txt");
    cin >> w >> h >> s >> t >> k >> P >> Q;
#else
    scanf("%d %d %d %d %d %d %d\n", &w, &h, &s, &t, &k, &P, &Q);
#endif
    std::vector<BBox> target_bbox;
    int min_x = P, min_y = Q;
    int max_x = 0, max_y = 0;
    for(int i = 0; i < k; i++) {
        int X, Y, W, H;
#ifdef DEEP_TEST
        cin >> X >> Y >> W  >> H;
#else
        scanf("%d %d %d %d\n", &X, &Y, &W, &H);
#endif
        int rx = X+W;
        int ry = Y+H;
        if((rx < 0 && ry < 0) || (X >= P && Y >= Q) || rx < X || ry < Y) continue;
        min_x = std::min(min_x, X);
        min_y = std::min(min_y, Y);
        max_x = std::max(max_x, rx);
        max_y = std::max(max_y, ry);
        target_bbox.push_back(BBox{X, Y, rx, ry});
    }
    int c = 0;
    int i_start = floor(max(0, min_x - w) / s);
    int j_start = floor(max(0, min_y - h) / t);
    int i_end = ceil(min(max_x, P - w) / s);
    int j_end = ceil(min(max_y, Q - h) / t);

    for(int i = i_end; i >= i_start; i--) {
        int start_i = s*i;
        int start_j = t*j_start;
        for(int j = j_start; j <= j_end; j++, start_j+=t) {
            BBox bbox = {start_i, start_j, start_i+w, start_j+h};
            if(exist_cross(bbox, target_bbox)) {
                c++;
            }
        }
    }
    std::cout << c << std::endl;
    return 0;
}

